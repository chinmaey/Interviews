# 🧠 QUIC — Last-Day Interview Pill (Ultra-Compact)

## What QUIC Is  
- **QUIC (Quick UDP Internet Connections)** is a modern transport protocol built on **UDP**  
- Provides:
  - Reliability  
  - Congestion control  
  - Stream multiplexing  
  - Built-in encryption (TLS 1.3)

- Implemented in **user space**  
- Used by **HTTP/3**

---

## Why QUIC Was Created  

To fix TCP problems:

- Head-of-line blocking  
- Slow handshakes  
- Kernel-space inflexibility  
- Poor mobility (IP change breaks TCP)  
- TCP + TLS handshake overhead

---

## Core QUIC Features  

- Runs over UDP  
- Built-in TLS 1.3 encryption  
- Reliable delivery  
- Congestion control (similar to TCP)  
- Multiple independent streams  
- No head-of-line blocking across streams  
- Fast connection setup (0–1 RTT)  
- Connection migration (survives IP change)

---

## QUIC vs TCP (Interview-Gold Table)

| Feature | TCP | QUIC |
|--------|-----|------|
| Transport | Kernel | User space |
| Underlying | IP | UDP |
| Reliability | Yes | Yes |
| Congestion Control | Yes (CUBIC, BBR) | Yes |
| Encryption | Optional (TLS) | Built-in (TLS 1.3) |
| Multiplexing | At app layer (HTTP/2) | Native streams |
| Head-of-Line Blocking | Yes | No (per stream) |
| Handshake | 1–2 RTT | 0–1 RTT |
| Mobility | Breaks on IP change | Survives IP change |
| Deployment | OS upgrade | App update |

---

## Why QUIC Is Better for Modern / Real-Time Apps  

- No head-of-line blocking  
- Faster connection setup  
- Built-in security  
- Better performance on lossy networks  
- Survives Wi-Fi ↔ LTE ↔ 5G changes

---

## Where QUIC Is Used  

- HTTP/3  
- YouTube, Google services  
- Modern browsers  
- Mobile apps  
- CDN transport

---

## QUIC vs UDP (1 Line)

- UDP = raw datagrams  
- QUIC = reliable, encrypted, congestion-controlled transport over UDP

---

## Why QUIC Is Better Than TCP for Real-Time Media  

- Avoids head-of-line blocking  
- No TCP retransmission stalls across streams  
- Faster recovery from loss  
- Better behavior on mobile networks  
- Lower latency under loss

---

## Lightning Facts (Memorize)

- QUIC runs over UDP  
- QUIC includes TLS 1.3  
- QUIC has native streams  
- QUIC avoids HOL blocking  
- QUIC supports 0-RTT  
- QUIC supports connection migration  
- QUIC is in user space  
- QUIC is used by HTTP/3

---

## 15-Second Killer Summary  

QUIC is a UDP-based transport protocol that provides TCP-like reliability, built-in TLS encryption, congestion control, and native stream multiplexing. It avoids head-of-line blocking, supports fast handshakes, and survives IP changes, making it better than TCP for modern and mobile applications.

---

## One-Liner to Memorize  

> QUIC is a UDP-based transport that provides TCP-like reliability with built-in encryption and stream multiplexing, while avoiding head-of-line blocking and supporting fast handshakes and connection migration.
