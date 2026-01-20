# VIZIO Interview – Final Basics Practice Plan (Project-Anchored, 1-Hour Interview Ready)

**Role:** Sr. Embedded C++ Developer (Media Domain)  
**Interview:** Wed Jan 14, 10:00 AM PST  
**Current Time Reference:** Mon Jan 12, 11:00 PM  
**Primary Goal:** Be able to write **simple, correct, minimal C++ code** in a **1-hour interview**, while clearly explaining intent.  
**Strategy:** Practice **fundamentals first**, anchored in real project experience. Coding problems are *additional*, not the core proof.

---

## Core Guiding Principles
- Prefer **clarity over cleverness**
- Use **minimal constructs** (C++11/17)
- Stop once the solution is correct
- Be able to explain *why this is sufficient*

---

## TONIGHT (11:00 – 11:30 PM) — Light Mental Setup Only
**No coding. No editor. No deep dives.**

### 11:00 – 11:30 PM
- Mentally index the *simplest correct approach* for:
  - stack usage
  - mutex + condition_variable
  - unique_ptr vs shared_ptr
  - extern "C"
  - thread creation + join
  - vector vs unordered_map
- Ask yourself for each:  
  *What is the one mistake I must avoid?*
- Stop and sleep.

---

## TUESDAY – PRIMARY PRACTICE DAY

### 1️⃣ C++ Language & Memory Basics (Morning Block)
**Objective:** Write safe, minimal C++ without hesitation.

Practice focus:
- Value vs reference vs pointer
- Stack vs heap lifetime
- RAII concept (constructor/destructor responsibility)
- unique_ptr usage patterns
- shared_ptr pitfalls (cycles, hidden ownership)
- const correctness (parameters, methods)

Constraints:
- Each snippet should fit in **½ screen**
- No templates unless required
- No over-engineering

---

### 2️⃣ STL Core (Morning Block)
**Objective:** Immediate recall of containers and common operations.

Practice focus:
- std::vector
- std::stack
- std::unordered_map
- std::string

Emphasis:
- Why choose one container over another
- Insert / find / erase patterns
- Iteration safety
- Avoiding iterator invalidation

Mental check:
> “If `using namespace std` is removed, can I still write calmly?”

---

### 3️⃣ Multithreading & Synchronization (Late Morning)
**Objective:** Correct synchronization, not performance tricks.

Practice focus:
- std::thread lifecycle
- std::mutex
- std::lock_guard vs std::unique_lock
- std::condition_variable
- Clean thread shutdown

Must be comfortable with:
- Sharing a variable safely
- Coordinating turn-taking
- Explaining why sleep-based sync is wrong

Do NOT practice:
- Lock-free algorithms
- Heavy atomics
- Thread pools

---

### 4️⃣ IPC & OS Fundamentals (Early Afternoon)
**Objective:** Clear explanation + minimal implementation readiness.

Practice focus:
- process vs thread
- socket vs message queue
- blocking vs non-blocking I/O
- user space vs kernel space (high level)
- file descriptor concept

Constraint:
- Be able to explain each in **30 seconds**
- No kernel internals

---

### 5️⃣ C and C++ Interoperability (Mid Afternoon)
**Objective:** Zero hesitation on C/C++ boundaries.

Practice focus:
- Name mangling
- extern "C"
- Header boundary discipline
- ABI awareness

This is a confidence topic—keep it simple.

---

### 6️⃣ OOPS & Casting (Mid Afternoon)
**Objective:** Demonstrate maturity, not cleverness.

Practice focus:
- Inheritance vs composition
- virtual destructors
- Safe casting choices
- Why reinterpret_cast is dangerous

Golden rule:
> Explain *why* before *how*.

---

### 7️⃣ Design Patterns – Interview Scale (Late Afternoon)
**Objective:** Apply patterns only where they help.

Practice focus:
- Singleton → one instance, clear ownership
- Factory → simple creation logic returning base type
- Builder → incremental parameter setup

Rules:
- No full frameworks
- No pattern stacking
- Patterns support clarity, not complexity

---

### 8️⃣ Project Anchoring (Evening)
**Objective:** Tie fundamentals back to real systems.

For each topic above, ask:
- Where did I use this in Project 1 (ground tracking)?
- Where did I use this in Project 2 (encoding pipeline)?
- How would I simplify it to interview scale?

Practice speaking:
- Project 1 summary in 2 minutes
- Project 2 summary in 2 minutes

---

## WEDNESDAY – INTERVIEW DAY

### Morning (7:30 – 8:30 AM)
- Light review only
- Re-read this plan
- Recall mental checklists
- No new learning

---

## Success Criteria (Final Self-Check)
You are ready if you can:
- Write small, correct C++ snippets calmly
- Explain ownership and lifetime clearly
- Synchronize threads safely
- Choose the right STL container instinctively
- Explain OS/IPC concepts without jargon
- Stop early and explain rather than over-coding

---

## Final Reminder
Your projects prove depth.  
This plan ensures **execution under interview constraints**.

**Clarity + correctness + confidence > complexity.**

End of final practice plan.
