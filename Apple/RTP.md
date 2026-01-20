# RTP — Last-Minute Interview Refresh (AVConference)

## What RTP Is

* **RTP (Real-time Transport Protocol)** carries real-time audio/video.
* Runs at the **application layer**, usually over **UDP** for low latency.
* Provides **timing, sequencing, and stream identification** — not reliability.

---

## What RTP Does

* Packetizes encoded media
* Adds:

  * **Sequence number** → loss + reordering detection
  * **Timestamp** → playout timing + sync
  * **Payload Type (PT)** → codec identification
  * **SSRC** → stream identity
* Minimal overhead, low latency

---

## What RTP Does *NOT* Do

* No retransmission
* No congestion control
* No bitrate adaptation
* No jitter buffering
* No encryption

---

## RTP Fixed Header (12 bytes — key fields)

* **Version (V)**
* **Payload Type (PT)**
* **Sequence Number (16 bits)**
* **Timestamp (32 bits)**
* **SSRC (32 bits)**
* Optional: **CSRC list** (mixers)

---

## Key Field Meanings

* **Sequence Number**

  * Increments per packet
  * Detects loss + out-of-order

* **Timestamp**

  * Sampling time of first payload byte
  * Same for all packets of a video frame
  * Codec-clock based (not wall-clock)
  * Typical video clock: **90 kHz**

* **SSRC**

  * 32-bit stream identifier
  * Supports mixers + multiple streams per port

* **CSRC**

  * IDs of contributing sources (audio mixing)

---

## Timing, Jitter, Sync

* Sender generates timestamps
* Network jitter affects **arrival time**, not RTP timestamps
* Receiver smooths timing using a **jitter buffer**
* Playout scheduled from RTP timestamps

---

## RTCP (Runs Alongside RTP)

Used for:

* Packet loss reports
* Jitter + RTT
* Quality feedback
* A/V sync

**RTCP Sender Report (SR)**

* Maps **RTP timestamp ↔ NTP wall-clock time**

**RTCP Receiver Report (RR)**

* Loss %, jitter, RTT

**Lip-sync:**

* Receiver aligns audio + video using RTP↔NTP mapping from RTCP SRs.

---

## Loss Handling

* RTP itself: **no retransmission**
* Application may use:

  * **NACK** (selective retransmit)
  * **FEC** (Forward Error Correction)
  * Packet concealment

---

## FEC (Forward Error Correction)

* Adds redundancy to recover lost packets
* Example: XOR parity or Reed-Solomon
* Used instead of retransmission for low latency

---

## Security

* **SRTP = Secure RTP**

  * Adds encryption, authentication, replay protection

---

## Session Setup

* RTP does **not** establish sessions
* A signaling protocol negotiates:

  * IPs, ports
  * Codecs
  * Payload types
  * Clock rates
  * SRTP keys
* Examples: **SDP (via SIP / WebRTC / RTSP / custom)**

---

## RTP vs Application Layer

* RTP: transport + timing metadata
* Application / media stack:

  * Jitter buffer
  * ABR / encoder control
  * FEC / NACK
  * Congestion control
  * Lip-sync logic

---

## WebRTC Relation

* WebRTC **implements RTP internally**
* Adds:

  * SRTP
  * RTCP feedback
  * Congestion control (GCC)
  * ABR via encoder control

---

## Libraries

* JRTPLIB
* Live555
* GStreamer RTP
* libwebrtc (full stack, not just RTP)

---

## Apple-Style 20-Second Summary

RTP carries real-time audio and video over UDP. It adds sequence numbers for loss detection, timestamps for playout timing and synchronization, payload type for codec identification, and SSRC for stream identity. RTP doesn’t do retransmission, congestion control, or bitrate adaptation. RTCP runs alongside RTP to provide feedback, quality metrics, and lip-sync using RTP-to-NTP timestamp mapping.

---

## Lightning Facts

* RTP uses **UDP** → low latency
* Video clock rate → **90 kHz**
* Same frame → same RTP timestamp
* RTP ≠ reliability
* RTCP = feedback + sync
* SRTP = encrypted RTP
* RTP carries media; **app adapts quality**

---

**One-liner to memorize:**

> RTP transports real-time media and provides timing and sequencing; the application handles reliability, adaptation, and synchronization using RTCP feedback.
