# ROUND 2 PREPARATION PLAN (6 HOURS)

## HOUR 1 — MCU + BOOT + PERIPHERALS
Focus: Core microcontroller fundamentals.

1. MCU Architecture Refresh (25 min)
- Boot sequence: Reset → Vector Table → SystemInit → main
   🟡 reset -> vector table (reset ptr, stack ptr, NMI, **hard fault handler**. 
- Clock tree and peripheral clock gating
- 
  '''bash
    🟡 - How do I choose a clock?
    Pick HSI for low power, HSE for accuracy, and PLL when you need maximum CPU performance.
    - What clock does a Cortex-M3 use?
    Cortex-M3 MCUs typically run the CPU from a PLL-derived system clock (commonly up to 72 MHz).
    - What happens if I overclock? Safe and max?
    Overclocking can work briefly but breaks timing margins and risks crashes—only vendor-rated max frequency is safe.
    - Are all cores synced, and what if overclocked?
     Most M3 chips are single-core; if multi-core, they share the same clock source but become unstable together when overclocked.

- Memory map: Flash, SRAM, peripherals
  🟡 - 
- IOMUX / GPIO configuration flow
- NVIC and interrupt priority grouping

2. Peripheral Fundamentals (25 min)
Prepare short 20-second explanations for:
- I2C
- SPI
- UART
- CAN basics
- LIN basics
- DMA high-level workflow

3. Rapid Quiz (10 min)
- How do you debug an I2C NACK?
- What causes SPI misalignment?
- Why CAN uses dominant bits.

## HOUR 2 — FREERTOS + DRIVER DEVELOPMENT
Focus: RTOS concepts and driver patterns.

1. FreeRTOS (20 min)
- Mutex vs binary semaphore vs counting semaphore
- Task notifications
- ISR safe APIs (FromISR)
- Priority inheritance
- Timer tasks
- Scheduling and jitter

2. Driver Bring-Up Pattern (20 min)
Standard flow:
Enable clock
Configure pins
Configure peripheral registers
Enable interrupts
Test basic transaction or loopback
Add DMA if needed

3. Interrupt Handling Flow (20 min)
- NVIC enable
- Peripheral IRQ enable
- ISR entry → service → clear flag
- Causes for "interrupt not firing"

----------------------------------------

## HOUR 3 — DEBUGGING MASTERCLASS
Focus: Showing your debugging strength.

1. Debugging Framework (20 min)
Symptom
Reproduce
Measure (scope, logic analyzer, registers, logs)
Isolate HW vs SW
Fix
Verify
Document for customer

2. Your 3 Debug Stories (20 min)
A. SJA1124 interrupt/status register issue
B. NCJ37x SPI/T=1 framing issue
C. FreeRTOS jitter / priority issue

3. Common Debugging Questions (20 min)
- I2C stuck low
- SPI fails at high speed
- Interrupt not firing
- Boot failure
- Noisy ADC readings

## HOUR 4 — FAE COMMUNICATION + INTRODUCTION
Focus: Clear, simple, customer-facing answers.

1. Build Your 60 Second Intro (20 min)
Include:
Embedded + driver experience
Hardware debugging
SJA1124 depth
FreeRTOS multitasking
Register-level comfort
Bench familiarity
FAE motivation

2. Customer Style Answers (20 min)
Format:
Explain simply
Add technical details
Describe how you help the customer

Example: UART framing error → voltage, baud mismatch, oversampling, noise, grounding.

3. Behavioral Questions (20 min)
Handling multiple customers
Working with incomplete information
Admitting unknowns
Long debugging cycles


## HOUR 5 — TOP TECHNICAL QUESTIONS (FAST RECALL)
Focus: Crisp senior-level answers.

1. MCU Fundamentals (20 min)
Boot sequence
Flash vs SRAM
NVIC flow
Endianness
Memory alignment
Cache basics

2. Peripheral Questions (20 min)
SPI vs I2C speed
I2C arbitration loss
CAN dominant bits
DMA workflow

3. RTOS + Driver Questions (20 min)
Mutex vs semaphore
ISR design
Priority inversion
Deadlock examples

## HOUR 6 — FINAL WRAP-UP
Focus: Polishing stories and confidence.

1. Polish Debug Stories (20 min)
Each 35–45 seconds, STAR format.

2. Prepare Questions For Them (20 min)
- What issues do customers face most with NXP MCUs?
- Which MCU families will I support first?
- What does success in 30/60 days look like?

3. Quick Recap (20 min)
Review:
Boot process
Driver bring-up
I2C/SPI/CAN/LIN
Interrupts
Debugging framework
Your intro
Your 3 stories
========================================

