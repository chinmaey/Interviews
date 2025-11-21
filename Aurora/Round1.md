# Interview Summary — Aurora | Lidar Security Engineer  
**Candidate:** Chinmaey Shende  
**Interviewer:** Kyle Oliver, Principal TLM (Lidar Software)  
**Date:** Thu, Nov 20, 2025  
**Time:** 1:30 PM – 2:00 PM PST  
**Format:** Virtual (Google Meet)  
**Duration:** 30 minutes  

---

## 1. Interview Structure Overview

The discussion followed a clear structure:

1. **Introductions**  
2. **Motivation for applying & transition from Rivian**  
3. **Technical background overview (embedded + security)**  
4. **Security architecture question (core evaluation)**  
5. **Programming language usage**  
6. **Closing & next steps**  

Kyle conducted this as a first-round **technical screening** to assess domain fit, relevance of background, and alignment with Aurora’s LiDAR security work.

---

## 2. Introduction & Role Context (Kyle)

Kyle introduced himself as the **Principal Technical Lead Manager (TLM)** for LiDAR software at Aurora.  
He described the team’s focus:

- Building and securing **Aurora’s LiDAR sensors** used in autonomous trucks  
- Security features in firmware  
- Ensuring integrity & trust across the LiDAR pipeline  
- Collaborating across hardware, firmware, and security components  

---

## 3. “Why Aurora?” / “Why This Role?”

**Response Summary:**

- Strong interest in **embedded networking**, **performance improvement**, and **secure firmware**.  
- Experience in **safety-critical systems** and **secure embedded software** aligns well with Aurora’s work.  
- Motivated by applying system-level security knowledge (TPM, secure boot, networking) to cutting-edge LiDAR technologies.

**Assessment:**  
This answer made a positive impression — clearly aligned with the role’s focus on embedded + security.

---

## 4. “Why leave Rivian?”

**Response Summary:**

- Contract at Rivian ending the following week.  
- Actively looking for a long-term opportunity aligned with embedded security and systems.

**Assessment:**  
Clear and professional. No red flags.

---

## 5. Technical Background Discussion

### 5.1 Embedded & Firmware Experience

You highlighted:

- Device drivers: **SMBus, Ethernet, Serial, I2C**
- RTOS experience: **FreeRTOS, Honeywell RTOS**
- Certification processes: **safety requirements, DER interactions**
- System & integration-level testing in avionics
- AeroMACS program (WiMAX subset for aviation)

Kyle showed interest because this maps directly to:

- LiDAR firmware  
- Trusted execution  
- Safety-critical communication between perception modules  

---

### 5.2 AeroMACS & Networking Security

You described:

- Secure WiMAX-based AeroMACS integration for aviation  
- **AAA / EAP-TLS** setup using Cisco router, Siemens Base Station & End Station  
- VLAN configuration, QoS, secure separation  
- TPM usage for key integrity  
- Demonstration of the system at the airport  
- Focus on secure interface design, firewalling, and reducing attack surface  

**Assessment:**  
This was a major strength.  
Your AeroMACS experience directly aligns with:

- Secure communication  
- Key management  
- Hardware-assisted security  
- Multi-interface embedded system design  

Kyle likely noted this as **unique and rare experience**.

---

### 5.3 Comcast & Node.js

You briefly described:

- Performance testing  
- Triaging in SAFe environment  
- Low-level debugging of the app pipeline  

Kept short — appropriate for this role.

---

### 5.4 Research Work

You explained:

- Video streaming research  
- Android app for sensory data  
- Secure data collection using **SSL/TLS and OAuth**  
- Data analysis pipelines  

This highlighted your fluency with secure communication and client–server authentication.

---

## 6. Core Technical Question (Security System Design)

### **Kyle’s Question:**
**“How do you approach the security design of a secure system?”**

### **Your Response (Structured as CIA + Hardware Root of Trust):**

- **Confidentiality:**  
  - Use appropriate encryption  
  - Select bandwidth-efficient protocols (AeroMACS example)

- **Integrity:**  
  - Secure boot  
  - Signed firmware  
  - TPM to protect private keys and integrity measurements

- **Authentication:**  
  - EAP-TLS (example from AeroMACS)  
  - Certificate-based device identity  
  - Avoid manual configuration by relying on automated trust chain

- **Authorization:**  
  - VLAN access control  
  - Certificate-based policy enforcement  
  - Limiting device-to-device communication paths

- **Secure coding practices:**  
  - Buffer validation  
  - Input sanitization  
  - Attack surface reduction by removing unused features

### **Assessment:**
This answer was well-received.  
It checked every box:

- Secure boot  
- TPM  
- Interface security  
- Access control  
- Software hardening  

This is *exactly* what a LiDAR security role demands.

---

## 7. Language Skills Question

**Kyle’s Question:**  
“What languages do you use? C++, C, Python?”

**Your Response:**  
- **C/C++** for embedded development  
- **Python** for research and system-level packet processing (Scapy, async pipelines)  

**Assessment:**  
Good — concise and consistent with your resume.

---

## 8. Closing & Next Steps

Kyle ended with:

> “Thanks for joining. You have a profile suitable for multiple roles.  
> We can schedule more details of your project.  
> I’ll get back to HR and let you know the next steps.”

This indicates:

- You passed the initial screening  
- They see you as a strong technical match  
- They may consider you for **multiple embedded/security positions**  
- Next step likely involves a deeper technical interview  

---

# Overall Evaluation

### **Strengths**
- Outstanding fit for embedded security  
- Relevant experience: TPM, secure boot, WiMAX/AeroMACS  
- Strong communication and clarity  
- Demonstrated system-level thinking  
- Good balance of theory + practical experience  

### **Potential Next-Round Focus**
- C/C++ embedded coding  
- Secure boot architecture  
- Hardware security modules (TPM/HSM/SE)  
- LiDAR threat modeling  
- Multi-interface embedded communication  

### **Overall Impression**  
**Very strong candidate; likely to progress to next round.**

---

# Next Steps (Suggested)
For the technical deep dive, prepare:

- A 5-minute walkthrough of AeroMACS security design  
- A clear explanation of secure boot (ROM → bootloader → kernel → app)  
- TPM key hierarchy and attestation  
- Embedded C coding sample (circular buffer, state machine)  
- LiDAR system threat analysis  

---

# End of Document
