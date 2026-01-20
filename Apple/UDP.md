# 🧠 UDP — Last-Day Interview Pill (Ultra-Compact)

## What UDP Is  
- **UDP (User Datagram Protocol)** is a connectionless, message-oriented transport protocol  
- No handshake, no connection state  
- Best-effort delivery — no guarantees

---

## UDP Header (8 bytes — very small)

- Source Port  
- Destination Port  
- Length  
- Checksum  

(No sequence numbers, no ACKs, no window, no retransmission)

---

## What UDP Does  
- Sends independent datagrams  
- Preserves message boundaries  
- Very low overhead  
- Very low latency

---

## What UDP Does *NOT* Do  
- No retransmission  
- No congestion control  
- No flow control  
- No in-order delivery  
- No reliability guarantees

---

## Why UDP Is Used  
- Time-sensitive data  
- Loss-tolerant applications  
- Applications that implement their own reliability

Examples:  
- RTP (audio/video)  
- WebRTC  
- DNS  
- VoIP  
- Online gaming  
- QUIC (built on UDP)

---

## UDP vs TCP (1-Line Contrast)

- TCP: reliable, ordered, congestion-controlled  
- UDP: fast, unordered, unreliable

---

## Error Detection  
- UDP checksum detects corruption  
- Corrupt packets are dropped  
- No recovery at UDP layer

---

## Reliability Over UDP  
- Implemented at application layer  
Examples:  
- RTP + RTCP  
- QUIC  
- Custom protocols

---

## Why UDP Is Good for Real-Time Media  
- No retra
