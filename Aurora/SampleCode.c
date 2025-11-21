/*
 * tpm_ipsec_key_demo.c
 *
 * DEMO FLOW (TPM 1.2 + OpenSSL):
 *  1. Connect to TPM via TrouSerS (libtspi).
 *  2. Load SRK and create an RSA keypair in TPM.
 *  3. Export public key (PEM) for making an X.509 cert later.
 *  4. Use OpenSSL ENGINE "tpm" to access the TPM-backed private key
 *     as an EVP_PKEY (for IKE/IPsec authentication).
 *
 *  NOTE:
 *   - This is a skeleton, not production-ready.
 *   - Error handling is simplified.
 *   - Assumes TrouSerS (TPM 1.2) and an OpenSSL TPM ENGINE are installed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <tss/tss_error.h>
#include <tss/tspi.h>

#include <openssl/engine.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

#define TPM_WELL_KNOWN_SECRET_LEN 20

static void check_tss(TSS_RESULT result, const char *msg) {
    if (result != TSS_SUCCESS) {
        fprintf(stderr, "%s failed: 0x%08X\n", msg, result);
        exit(1);
    }
}

int main(void) {
    TSS_HCONTEXT hContext = 0;
    TSS_HTPM hTPM = 0;
    TSS_HKEY hSRK = 0;
    TSS_HPOLICY hSrkPolicy = 0;
    TSS_HKEY hKey = 0;
    TSS_RESULT result;
    BYTE wellKnownSecret[TPM_WELL_KNOWN_SECRET_LEN] = {0}; // 20 bytes of 0x00
    UINT32 pubKeyLen = 0;
    BYTE *pubKey = NULL;

    /* 1. TPM context setup */
    result = Tspi_Context_Create(&hContext);
    check_tss(result, "Tspi_Context_Create");

    result = Tspi_Context_Connect(hContext, NULL);
    check_tss(result, "Tspi_Context_Connect");

    result = Tspi_Context_GetTpmObject(hContext, &hTPM);
    check_tss(result, "Tspi_Context_GetTpmObject");

    /* 2. Load SRK (Storage Root Key) */
    result = Tspi_Context_LoadKeyByUUID(
        hContext,
        TSS_PS_TYPE_SYSTEM,
        TSS_UUID_SRK,
        &hSRK
    );
    check_tss(result, "Tspi_Context_LoadKeyByUUID(SRK)");

    /* 3. Set SRK policy (well-known secret = all zeros for demo) */
    result = Tspi_GetPolicyObject(hSRK, TSS_POLICY_USAGE, &hSrkPolicy);
    check_tss(result, "Tspi_GetPolicyObject(SRK)");

    result = Tspi_Policy_SetSecret(
        hSrkPolicy,
        TSS_SECRET_MODE_SHA1,
        TPM_WELL_KNOWN_SECRET_LEN,
        wellKnownSecret
    );
    check_tss(result, "Tspi_Policy_SetSecret(SRK)");

    /* 4. Create a new RSA key pair in TPM under SRK */
    result = Tspi_Context_CreateObject(
        hContext,
        TSS_OBJECT_TYPE_RSAKEY,
        TSS_KEY_TYPE_SIGNING | TSS_KEY_SIZE_2048 | TSS_KEY_VOLATILE,
        &hKey
    );
    check_tss(result, "Tspi_Context_CreateObject(KEY)");

    result = Tspi_Key_CreateKey(hKey, hSRK, 0);
    check_tss(result, "Tspi_Key_CreateKey");

    /* 5. Get the public part of the key (to create cert later) */
    result = Tspi_Key_GetPubKey(hKey, &pubKeyLen, &pubKey);
    check_tss(result, "Tspi_Key_GetPubKey");

    /* 6. Convert public key (TPM format) to OpenSSL RSA/EVP_PKEY */
    /* NOTE:
       In real code, you must parse the TPM pubkey blob (TPM_PUBKEY struct)
       and extract the modulus and exponent to build an RSA* structure.
       Here we just show the outline.
    */

    // Pseudo-code for converting pubKey -> RSA:
    // const BYTE *p = pubKey;
    // TPM_PUBKEY tpm_pub;
    // parse_tpm_pubkey(&tpm_pub, &p, pubKeyLen);
    // BIGNUM *n = BN_bin2bn(tpm_pub.modulus, len_modulus, NULL);
    // BIGNUM *e = BN_new(); BN_set_word(e, 65537);
    // RSA *rsa = RSA_new();
    // RSA_set0_key(rsa, n, e, NULL);
    // EVP_PKEY *evp_pub = EVP_PKEY_new();
    // EVP_PKEY_assign_RSA(evp_pub, rsa);

    /* For demo, we’ll just print that we got the pubkey length: */
    printf("TPM public key length = %u bytes\n", pubKeyLen);

    /* 7. Write public key to PEM file (TODO: convert first) */
    /* In real code, after building `evp_pub`, do something like:
     *
     * FILE *f = fopen("ipsec_tpm_pubkey.pem", "w");
     * if (!f) { perror("fopen"); exit(1); }
     * PEM_write_PUBKEY(f, evp_pub);
     * fclose(f);
     */

    /* 8. Use OpenSSL ENGINE "tpm" to access TPM-backed private key */

    ENGINE_load_builtin_engines();
    ENGINE *e = ENGINE_by_id("tpm");   // Needs an installed TPM engine
    if (!e) {
        fprintf(stderr, "TPM ENGINE not found. Make sure it's installed.\n");
        // Not exiting so code path is visible
    } else {
        if (!ENGINE_init(e)) {
            fprintf(stderr, "ENGINE_init(tpm) failed.\n");
        } else {
            /* Load private key from TPM using a label or key handle.
               The exact string depends on the TPM engine implementation.
               Many use something like "0x00000001" or a UUID.
             */
            const char *key_id = "0x00000001"; // example handle/ID
            EVP_PKEY *tpm_priv = ENGINE_load_private_key(e, key_id, NULL, NULL);
            if (!tpm_priv) {
                fprintf(stderr, "ENGINE_load_private_key failed.\n");
            } else {
                printf("Loaded TPM-backed private key via ENGINE.\n");

                /* 9. Use tpm_priv in OpenSSL as normal:
                 *    - Sign IKE authentication payloads
                 *    - Create a certificate signing request (CSR)
                 *    - Or integrate with your IKE/IPsec stack
                 */

                // Example: sign some data
                const unsigned char data[] = "test data";
                unsigned char sig[256];
                size_t siglen = sizeof(sig);

                EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
                EVP_PKEY_CTX *pctx = NULL;

                if (EVP_DigestSignInit(mdctx, &pctx, EVP_sha256(), NULL, tpm_priv) == 1 &&
                    EVP_DigestSignUpdate(mdctx, data, sizeof(data)-1) == 1 &&
                    EVP_DigestSignFinal(mdctx, sig, &siglen) == 1) {
                    printf("Successfully signed data with TPM-backed key (len=%zu)\n", siglen);
                } else {
                    fprintf(stderr, "TPM-backed signing failed.\n");
                }

                EVP_MD_CTX_free(mdctx);
                EVP_PKEY_free(tpm_priv);
            }
            ENGINE_finish(e);
        }
        ENGINE_free(e);
    }

    /* 10. Cleanup TPM resources */
    if (pubKey) {
        Tspi_Context_FreeMemory(hContext, pubKey);
    }

    Tspi_Context_CloseObject(hContext, hKey);
    Tspi_Context_CloseObject(hContext, hSRK);
    Tspi_Context_Close(hContext);

    return 0;
}
