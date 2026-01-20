# 🧠 TCP — Last-Day Interview Pill (Ultra-Compact)

## What TCP Is  
- Reliable, connection-oriented, byte-stream protocol  
- Guarantees: in-order + lossless delivery  
- Uses: sequence numbers, ACKs, retransmissions  
- Great for files/web, bad for real-time media

---

## 3-Way Handshake  
1) SYN (seq = X)  
2) SYN-ACK (seq = Y, ack = X+1)  
3) ACK (ack = Y+1)

Why 3 steps?  
- Confirms both sides alive  
- Syncs sequence numbers  
- Prevents old duplicate SYNs

---

## Sequence Numbers & ACKs  
- Byte-oriented sequence numbers  
- ACK = next byte expected  
- ACK confirms all bytes ≤ ACK−1

---

## Flow vs Congestion Control  

Flow Control (rwnd):  
- Receiver capacity limit  
- Advertised by receiver  

Congestion Control (cwnd):  
- Network capacity limit  
- Maintained by sender  

Send window = min(rwnd, cwnd)

---

## Congestion Control Phases  

Slow Start:  
- cwnd starts small (~10 MSS)  
- Exponential growth per RTT  

Congestion Avoidance:  
- Linear growth  
- AIMD (Additive Increase, Multiplicative Decrease)

Linux default CC: CUBIC  
(others: Reno, BBR, Vegas)

---

## Loss Detection & Recovery  

Timeout:  
- RTO expires → retransmit  

Fast Retransmit:  
- 3 duplicate ACKs → retransmit missing segment  

SACK:  
- Receiver reports received blocks  
- Retransmit only missing data

---

## Nagle’s Algorithm  
- Batches small writes into MSS  
- Reduces tiny packets  
- Disable for low-latency traffic (real-time media, gaming)

---

## MTU vs MSS  
- MTU: Max IP packet size  
- MSS: Max TCP payload = MTU − IP − TCP headers  

Why it matters:  
- Wrong MSS → fragmentation → poor performance

---

## ECN (Explicit Congestion Notification)  
- Routers mark packets instead of dropping  
- Sender slows down on marks  
- Avoids loss + retransmission latency

---

## Offloads (Linux)  
- TSO: NIC splits large TCP buffers  
- GRO: NIC/stack merges received packets

---

## Why TCP Is Bad for Real-Time Media  
- Retransmissions add latency  
- Head-of-line blocking delays new data  
- Congestion control causes bitrate oscillation  
- Jitter breaks A/V sync

---

## Lightning Facts (Memorize)

- ACK = next byte expected  
- Slow start = exponential growth  
- Congestion avoidance = linear growth  
- Fast retransmit = 3 duplicate ACKs  
- Default Linux CC = CUBIC  
- rwnd = receiver limit  
- cwnd = network limit  
- MSS = MTU − headers  
- ECN = mark instead of drop  
- TCP ≠ real-time friendly

---

## 15-Second Killer Summary  

TCP is a reliable, connection-oriented byte-stream protocol using sequence numbers, ACKs, and retransmissions. It controls rate using slow start and congestion avoidance and limits traffic using both rwnd and cwnd. While great for bulk transfer, retransmissions and head-of-line blocking make it unsuitable for real-time media.

---

## One-Liner to Memorize  

TCP guarantees reliable, ordered delivery using ACKs and retransmissions, but its latency and head-of-line blocking make it unsuitable for real-time media.
