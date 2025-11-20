# AeroMACS Secure Communication & TPM Prototype Integration — Detailed Technical Story

## 1. Overview  
I worked on the initial development of the **AeroMACS (Aviation WiMAX)** radio interface for the Communication Management Unit (CMU).  
AeroMACS provides a **secure, dedicated aviation band** communication link and is positioned between:
- **Wi-Fi** (cheap, flexible, but not secure enough for safety services)  
- **SATCOM / HF / VHF** (robust but expensive and high-maintenance)

AeroMACS offers the right balance for **safety-related, high-priority data**, providing:
- Dedicated spectrum (not shared with commercial users)  
- Superior access control and authentication  
- Lower cost and maintenance than SATCOM  
- Higher security and scalability than Wi-Fi  

---

## 2. Security Architecture: EAP-TLS & AAA Integration  
AeroMACS implements **EAP-TLS** for strong Layer-2 authentication.

### Base Station (BS)
- Acts as the **EAP-TLS server**
- Terminates TLS handshake with clients

### AAA Server
- Hosts the **Certificate Authority (CA)**
- Maintains the **X.509 trust hierarchy**
- Provides:
  - Authentication
  - Authorization
  - Policy enforcement

### End System (ES)
- "ES" is the correct term for the **mobile/user device**
- Presents a **client certificate** for identity

### Security Guarantees
- **Mutual authentication** using X.509 certificates  
- **Integrity & confidentiality** using AES session keys derived during TLS handshake  
- **Authorization** through AAA policy  
- **Non-repudiation** via certificate-based identity

---

## 3. Network Segmentation: VLAN Design  
I designed VLANs to isolate and prioritize different classes of traffic:

1. **High-priority secure data**  
   - Location reports  
   - PM-CPDLC messages  

2. **Low-priority secure data**  
   - ACARS, operational maintenance data  

3. **High-priority cabin data**  
   - Crew applications  
   - Real-time cabin connectivity  

4. **Low-priority cabin data**  
   - Passenger data  
   - Non-critical services  

This segmentation ensured:
- Deterministic performance  
- QoS enforcement  
- Isolation of safety-critical communication  

---

## 4. ATN Integration: Control & Data Paths  
AeroMACS ES must interface with the **ATN/OSI stack** used for aviation datalink (CPDLC, ADS-C, etc.).

### Control Plane: SNSME via SNMPv3  
- Used the **Subnetwork Service Management Entity (SNSME)**  
- Managed ES registration, addressing, and subnetwork association  
- Implemented using **SNMPv3**, providing:
  - Authentication  
  - Integrity  
  - Privacy  

I implemented the SNMPv3 control interface to:
- Enable/disable ES  
- Configure the radio parameters  
- Manage handoff and administrative functions  

### Data Plane: IP-SNDCF over IPsec  
For transporting PLP/CLNP ATN traffic, I used:
- **IP-SNDCF** (IP-based Subnetwork Dependent Convergence Function)  
- Secured using an **IPsec tunnel**

Benefits:
- End-to-end **confidentiality**, **integrity**, and **anti-replay**  
- Compatibility with existing ATN applications  
- Separation of control (SNMPv3) and data (IPsec) planes  

---

## 5. TPM 1.2 Integration on MPC8270 Platform  
Our hardware supported **TPM 1.2**, and the embedded board used a **Tundra PCI↔PCIe bridge**.

### Hardware Integration
- Connected a **PCIe-based TPM 1.2 module** through the Tundra bridge  
- From the MPC8270 perspective, the TPM appeared as a **standard PCI device**

### Software Integration
- Integrated vendor-supplied **TPM 1.2 PCI driver**  
- Exposed `/dev/tpm0` interface to the embedded Linux/firmware

### Security Features Implemented
- **Measured Boot**  
  - Extended boot measurements into PCRs  
  - Boot stages: Bootloader → Kernel → RootFS → Application

- **Secure Key Storage**  
  - Generated keys inside the TPM  
  - Stored certificate private keys sealed to PCR states  

- **Attestation**  
  - Generated TPM quotes  
  - Remote verifier checked PCRs + signatures  
  - Ensured only trusted firmware operated on the ES  

This provided a hardware-rooted trust chain before allowing AeroMACS association.

---

## 6. Threat Modeling Approach  
I used OWASP/STRIDE-inspired threat analysis:

### Assets
- AeroMACS radio interface  
- Secure VLANs  
- Certificates and private keys  
- TPM-protected measurements  
- PLP/CLNP traffic via IP-SNDCF  
- Control-plane SNMPv3 configuration paths  

### Threats
- Spoofing (fake ES connecting)  
- Tampering (modifying control commands)  
- Replay of registration messages  
- Misconfiguration via insecure SNMP  
- Rogue BS or Man-in-the-Middle  
- Compromise of certificates  

### Controls
- EAP-TLS mutual authentication  
- TPM-based device identity  
- VLAN isolation  
- SNMPv3 authentication/privacy  
- IPsec protection for data path  
- TPM-sealed keys and PCR-based trust  
- Attestation before granting network access  

---

## 7. Outcome  
The system achieved:
- **Confidentiality:** IPsec + AES session keys  
- **Integrity:** EAP-TLS, TPM PCRs, SNMPv3  
- **Authentication:** Certificate-based mutual auth  
- **Authorization:** AAA server policies + role separation  
- **Non-repudiation:** X.509 identity + TPM-backed keys

It established a secure, layered, standards-compliant AeroMACS interface aligned with ATN/OSI datalink requirements.

---

## 8. Relevance to LiDAR Security (Optional Interview Link)  
This work directly translates to LiDAR security by demonstrating:
- Firmware trust (measured boot + attestation)  
- Hardware root of trust (TPM)  
- Secure device identity  
- Secure control/data path separation  
- VLAN/QoS-like segmentation of safety-critical vs non-critical data  
- Use of X.509, mutual authentication, IPsec, and SNMPv3 patterns  

