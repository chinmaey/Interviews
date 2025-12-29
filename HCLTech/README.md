# Interview Preparation Plan (Python + C++ | Test Equipment & Automation)

## Context / Target
- Interview: HCL round (2 people) + CoderPad (2 coding questions)
- Must answer **crisp + aligned to JD** with **time/space complexity**
- Focus areas called out by Sayantan: **Regex**, **DLL/Shared Libraries**, **C++**, **Python**, plus crisp experience alignment

---

## 1) Rapid Alignment to Job Description (30–45 min)
### 1.1 Build a “JD → My Proof” map (1–2 bullets each)
- Test equipment automation (DVM, PSU, loads, scopes, analyzers, DAQ): examples of HW/SW integration + validation
- Serial protocols: Ethernet / I2C / USB / UART / single-wire: what you built + how you debugged
- Data acquisition + analysis + visualization: Python/SQL/log processing examples
- Revision control + documentation + validation: Git/GitLab/Jira/CI + test evidence
- Bonus: embedded firmware + battery testing: map to ECU/FreeRTOS/driver/automation

### 1.2 60-second intro (script)
- Role fit: C/C++ + Python + embedded test automation + HW/SW integration
- 1–2 strongest projects relevant to lab/test tooling

---

## 2) CoderPad Readiness (2 coding questions) (60–90 min)
### 2.1 What to practice (interview patterns)
- Arrays/strings, hash map, set, stack/queue, two pointers, sliding window
- File/log parsing problems (strings + regex + grouping counts)
- Implement clean solution, then state:
  - Complexity: **O(n)** / **O(n log n)**, space **O(1)/O(n)**
  - Edge cases + tests

### 2.2 CoderPad execution checklist
- Restate problem + assumptions
- Write minimal working version fast
- Add edge cases and small tests
- Optimize only if needed
- Narrate complexity clearly at end

---

## 3) Python (Gap-Focused to Match JD) (90–120 min)
### 3.1 Remaining items from README.md
- `06_bitwise_binary_struct.ipynb`: masking, shifting, `struct.pack/unpack`, endianness (protocol payload/log decoding)
- `07_regex.ipynb`: **Regex fundamentals + practical log parsing**
- `08_testing_pytest.ipynb`: pytest, fixtures, parameterization (automation credibility)

### 3.2 Regex in Python (must-cover)
- Core constructs: `. * + ? | () [] {m,n} ^ $ \b`
- Groups + named groups: `(...)`, `(?P<name>...)`
- Greedy vs non-greedy: `.*` vs `.*?`
- Flags: `re.I, re.M, re.S`
- Common tasks: extract fields, validate lines, redact, split, replace

### 3.3 DLL / Shared Library integration in Python (must-cover)
- Concepts: shared libraries (.so/.dylib/.dll), symbols, ABI, calling conventions
- How Python calls native:
  - `ctypes` basics: `CDLL`, argtypes/restype, strings/buffers
  - Memory ownership: who allocates/frees
  - Error handling: errno / return codes
- Alternative integration: `subprocess` to run C++ test binaries and parse output
- Practical interview framing: “Python orchestrates; C++ does timing-critical IO; Python parses + reports”

---

## 4) C++ (Embedded + Test Tooling) (90–120 min)
### 4.1 C++ essentials for interview
- RAII, Rule of 0/3/5, smart pointers
- References vs pointers, const correctness
- STL: vector/map/unordered_map, string, algorithms
- Error handling: return codes vs exceptions (embedded context)

### 4.2 Regex in C++ (explicit must-cover)
- `<regex>`: `std::regex`, `std::smatch`, `regex_search`, `regex_match`, `regex_replace`
- Pitfalls: performance/complexity, prefer simpler parsing when possible
- Interview-ready examples: extract timestamp/level/message, validate format

### 4.3 C++ shared libraries (DLL) (explicit must-cover)
- Terminology: static lib vs shared lib
- Linux: `.so`, `ldd`, `LD_LIBRARY_PATH`, rpath
- Symbol export basics, headers vs implementation
- Dynamic loading concepts: `dlopen/dlsym/dlclose` (high level)
- Using DLL/shared libs from apps/tools (why: modular drivers/instrument SDKs)

---

## 5) Systems / Test Automation Design Discussion (45–60 min)
- Design a test automation toolchain:
  - Python orchestrator (CLI, configs)
  - C++ measurement/control layer (instrument control, timing-critical tasks)
  - Data pipeline: collect → validate → analyze → report
  - Logging, traceability, reproducibility
- Handling real lab constraints:
  - flaky connections, retries, timeouts
  - calibration/versioning, test evidence, documentation

---

## 6) Experience Answers (Crisp, JD-Aligned) (45–60 min)
Prepare 6–8 “ready stories” (2 minutes each):
- HW/SW integration + debugging (scope/sniffer/log correlation)
- Test automation pipeline (Python + CI + reports)
- Embedded driver/protocol bring-up (I2C/UART/Ethernet)
- A failure you owned + fixed (root cause + prevention)
For each story: **Problem → Action → Result (metric if possible)**

---

## 7) Final 30-Min Runbook (Tonight + Morning)
### Tonight (30 min)
- One CoderPad timed problem (45 min max)
- Review regex cheatsheet (Python + C++)
- Review DLL/shared library bullets (Python ctypes + C++ shared lib basics)

### Morning of interview (30 min)
- 60-second intro rehearse (3 times)
- 3 JD-aligned stories rehearse
- Complexity statement practice (say it out loud)

---

## Output Targets
- Confident CoderPad performance with complexity + edge cases
- Crisp, role-aligned answers (Python automation + C++ embedded + instrumentation mindset)
- Clear understanding of **Regex** and **DLL/shared libraries** in both Python and C++ contexts
