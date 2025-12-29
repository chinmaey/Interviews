# Interview Summary — Round 3 (Performance / Systems Focus)

**Interviewer:** Srijith  
**Role Focus:** Linux drivers, application & system performance optimization, switching/control paths  
**Format:** Discussion + live coding (notepad-style)

---

## 1. Interviewer Introduction & Team Context
- Srijith works primarily on:
  - Linux drivers
  - Application-level performance optimization
  - Switching and control paths
- Emphasis is **system-level performance**, not single-packet latency.
- Typical issues include:
  - Long connection establishment times
  - Route add / switching delays
  - Control-path inefficiencies
- Performance process:
  - Initial development achieves ~50% performance
  - Progressive integration and testing (IXIA, UNITY, etc.)
  - Issues discovered at each integration layer
  - Final validation against RFC-level performance
- Long-lived codebase (~20 years) → complexity due to multiple versions.

---

## 2. My Experience Discussion
I explained my background aligned with performance and systems work:

- **Honeywell (RTOS):**
  - Driver-level and system-level performance improvements
  - Real-time constraints and optimization levers at low level

- **Comcast (Linux STB):**
  - Node.js application performance tuning
  - Linux-based set-top box environment
  - Application profiling and optimization

- **Linux Bandwidth Measurement:**
  - Linux setup to measure bandwidth
  - Traffic control (TC) used to enforce bandwidth profiles

- **Android Application:**
  - Measuring bandwidth on Android
  - Collecting device/context information
  - Context-aware streaming support

- **Rivian (Automotive):**
  - Device driver performance improvements
  - Embedded/Linux systems context

---

## 3. Preference Question
**Question:** Device drivers vs application & performance monitoring?

**My Answer:**
- Primary focus has always been **performance improvement**
- Device drivers provide **more leverage points** to exploit performance
- Lower-level access enables higher impact optimizations

**Response:** Interviewer agreed this was a good alignment.

---

## 4. Coding Question

### Problem
> Given a string `S`, remove all adjacent duplicate characters **recursively** until no more duplicates remain.

**Example:**
Input: "abccbccba"
Output: ""
Explanation:
ab(cc)b(cc)ba → abbba → a(bbb)a → aa → ""


---

### My Approach & Discussion
- Clarified understanding using the example
- Asked whether recursion was mandatory (it was not)
- Initially considered recursive split-based approach (did not work)
- Considered two-pointer approach (`l` and `r`)
- Realized `r` was unnecessary; interviewer asked what role `r` played
- Shifted to single-pointer iteration
- Identified that **one pass is insufficient** due to cascading removals
- Recognized need for:
  - Iterative repetition **or**
  - Recursive call on the reduced string
- Began implementing a loop that:
  - Detects adjacent duplicates
  - Builds a reduced string
  - Recursively processes the result
- Time ended (~40 minutes) before completing a clean final version

**Key realization (near end):**
- The problem inherently requires **multiple passes / stack-like behavior**
- Recursive return on the reduced string is valid

---

## 5. Post-Coding Discussion
- Asked interviewer about real performance optimization work
- Learned that:
  - Most issues are **system/control-path level**, not per-packet delays
  - Debugging involves placing markers across stages to isolate latency
  - Data path is mostly hardware; control path causes more software issues
- Interviewer mentioned **VFS (Linux Virtual File System)** in passing (assumed familiarity)

---

## 6. Overall Takeaways
- This role is **not heavily DSA-focused**
- Strong emphasis on:
  - Linux systems
  - Control-path performance
  - Long-lived, complex codebases
  - Tool-driven, multi-stage performance analysis
- Coding evaluation focused more on:
  - Reasoning
  - Adaptability
  - Understanding problem behavior
  - Less on finishing perfectly under time

---

## 7. Self-Assessment
- Good alignment with role and interviewer’s work
- Strong systems and performance discussion
- Coding problem reached correct mental model, but not fully implemented due to time and notepad constraints
- Identified need to keep **whiteboard / notepad coding reflexes warm** for future interviews

---

**Status:** Round 3 completed  
**Confidence:** Reasoning and domain alignment strong; coding polish can be improved with targeted practice
