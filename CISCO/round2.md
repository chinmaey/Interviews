# Interview Round Summary — Laxman (Switching / Networking / Coding)

## 1. L2 Protocols Used
**Question:** What Layer-2 protocols have you used?

**Answer (clarified):**
- Ethernet (IEEE 802.3)
- VLAN tagging (IEEE 802.1Q)
- MAC learning / Forwarding Database (FDB)
- Spanning Tree (STP/RSTP) – conceptual
- ARP (L2/L3 boundary)

**Key takeaway:** L2 focus should stay on Ethernet, VLANs, MAC learning, and STP; routing protocols come later at L3.

---

## 2. TCP/IP – Session Establishment
**Question:** How does TCP/IP work? How is a session established?

**Answer:**
1. Client resolves server IP using DNS (if only URL is known).
2. TCP connection setup uses a **3-way handshake**:
   - Client sends **SYN** with a random Initial Sequence Number (ISN₁).
   - Server responds with **SYN-ACK**, its own random ISN₂, and ACK = ISN₁ + 1.
   - Client sends **ACK** = ISN₂ + 1.
3. Connection is established.

**Session identification:**
- TCP does **not** have an explicit “session ID” field.
- A TCP connection is uniquely identified by the **5-tuple**:
