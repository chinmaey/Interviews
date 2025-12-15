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
(Source IP, Destination IP, Source Port, Destination Port, Protocol)

- Each session also has its own **sequence number space**, starting from randomly chosen ISNs.

**Clarification during interview:**
- “Session number” was used conversationally to describe ISNs + connection tuple.
- This was conceptually correct and accepted after hints.

---

## 3. L2 vs L3 Forwarding Decisions
**Question:** How are L2 and L3 forwarding decisions taken?

**Answer:**
- **L2 forwarding:**
- Based on **destination MAC address**
- Uses **Forwarding Database (FDB / CAM table)**
- Unknown MAC → flood within VLAN
- **L3 forwarding:**
- Based on **destination IP address**
- Uses **FIB (Forwarding Information Base)**
- ARP resolves next-hop MAC

**Important clarification:**
- **ACLs do not decide forwarding**; they only permit/deny/mark traffic.
- Forwarding happens first (L2/L3 logic), ACLs are applied as policy.

---

## 4. VLAN Tagging
**Question:** Why do we use VLAN tagging?

**Answer:**
- Logical separation of traffic at Layer 2
- Reduces broadcast domains
- Allows multiple VLANs to share the same physical trunk
- Supports QoS via PCP bits in the 802.1Q tag

---

## 5. L2 / L3 Protocols Worked On
**Answer:**
- Avionics protocols: CLNP, IDRP
- Routing protocols: eBGP (external), IS-IS, OSPF

---

## 6. Career Motivation (PhD / Domain Expansion)
**Question:** Why PhD / why this domain?

**Answer:**
- Strong background in avionics networking and performance
- Motivation to **expand into networking and advanced technologies**
- Goal: broader impact and better opportunities, not abandoning prior expertise

**Interpretation:** Expansion of domain, not exit from avionics — acceptable and professional.

---

## 7. Coding Question — Two Threads, Odd/Even Printing (One Pass)
**Question:**
- Given an array of numbers
- Two threads:
- Thread 1 prints odd numbers
- Thread 2 prints even numbers
- Must process the array **in one go (single pass)**

### Initial Approach (Issue)
- Proposed semaphores and turn-based coordination
- This over-serialized execution and added unnecessary complexity

### Correct / Expected Approach
- Use a **shared index** protected by a **mutex (or binary semaphore)**
- Each thread:
1. Locks
2. Reads and increments index
3. Unlocks
4. Prints number if parity matches

**Key insight:**
- One-pass requirement ⇒ shared index must be protected
- No ordering requirement ⇒ no need for alternation or condition variables

**Clean pattern (pseudocode):**


```c
while true:
lock
if idx == n: unlock; break
x = arr[idx++]
unlock
if parity matches: print
```


**Why this is preferred:**
- Minimal synchronization
- No deadlocks
- Clear intent
- Senior-level simplicity

---

## 8. Overall Assessment of the Round
- **Strengths:**
  - Strong systems and networking background
  - Correct conceptual understanding
  - Adapted well with hints
- **Weaknesses:**
  - Over-complication in coding under pressure
  - Slight terminology drift (session ID vs 5-tuple, ACL vs forwarding)
- **Net result:**
  - Mixed but acceptable performance
  - Not a rejection-level interview
  - Additional rounds scheduled to validate coding clarity and domain fit

---



