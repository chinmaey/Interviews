# ROUND 2 PREPARATION PLAN (6 HOURS)

## HOUR 1 — MCU + BOOT + PERIPHERALS
Focus: Core microcontroller fundamentals.

1. MCU Architecture Refresh (25 min)
- Boot sequence: Reset → Vector Table → SystemInit → main
   🟡 reset -> vector table (reset ptr, stack ptr, NMI, **hard fault handler**. 
- Clock tree and peripheral clock gating
  
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
     0x0000_0000 – Code region (Flash, Boot ROM, Aliased memory)
      0x0000_0000 to around 0x0800_0000 is usually on-chip Flash depending on MCU.
      
      0x2000_0000 – SRAM region
      This covers on-chip SRAM blocks and tightly-coupled memory (if present).
      All RAM on M4 is mapped starting at 0x2000_0000.
      
      0x4000_0000 – Peripheral region
      APB and AHB peripheral registers (timers, GPIO, USART, SPI, I2C, etc.).
      
      0x6000_0000 – External memory region
      External QSPI/NOR/SRAM/PSRAM (if MCU supports external memory interface).
      
      0x8000_0000 – Private peripheral bus
      System control space (NVIC, SysTick, SCB, MPU) at 0xE000_0000.
      
      0xE000_0000 – System control region
      NVIC registers, SysTick, debug, trace units, core peripherals.

      Tyeps of RAM
         SRAM = fast, no refresh, small and expensive
         DRAM = slow, needs refresh, high density
         SDRAM = DRAM clock-synchronized for higher performance
- IOMUX / GPIO configuration flow
    🟡 -
     Enable the **clock** for the GPIO port in the RCC (or equivalent clock control).

     Use the IOMUX/AF (alternate function) register to **select the pin function** (GPIO, UART TX, SPI SCK, etc.).
      
      Configure the **pin mode** (input, output, alternate function, analog).
      
      Configure output type (**push-pull** or **open-drain**).
      
      Configure pull-up or pull-down resistors.
      
      Configure output speed (low/medium/high) if applicable.
      
      Write or read the pin using the GPIO data registers.
  
      Yes, M4 supports internal pull-up/pull-down via registers, and no external resistor is required unless you need a stronger or protocol-specific pull.
  
- NVIC and interrupt priority grouping
  🟡 -
     NVIC manages interrupts and nesting.

     Priority grouping controls how priority bits are split between pre-emption and subpriority.

     NVIC supports up to 240 external interrupts plus 16 system exceptions; actual count depends on the MCU.

     NVIC manages external and software-triggered interrupts, while core exceptions like Reset, NMI, and HardFault are handled by the core but still use the vector table.

2. Peripheral Fundamentals (25 min)
Prepare short 20-second explanations for:
- I2C
  🟡 -
     I2C is a two-wire communication protocol using SDA and SCL lines that supports multiple masters and slaves on the same bus.
      It uses open-drain signaling, pull-up resistors, and transfers data in address-based frames with start, stop, and acknowledge bits.
      
      Two-wire open-drain bus with start/stop, ACK, and multi-master support; works at common logic levels 1.8–5 V and standard speeds 100 kHz, 400 kHz, 1 MHz, and up to 3.4 MHz (HS mode).

     

- SPI
  
  🟡 -
  SPI is a high-speed, full-duplex serial bus with separate lines for clock, MOSI, MISO, and chip select.
  
   It’s simple, fast, and efficient, supporting one master and multiple slaves with configurable clock polarity, phase, and data order.
   
   Full-duplex clocked interface using SCK/MOSI/MISO/CS; works at logic levels 1.8–5 V and supports baud rates typically from a few MHz up to 20–50+ MHz depending on the MCU.

- UART
- 
  🟡 -
   Asynchronous serial interface using TX/RX with start/stop bits and no shared clock; works at logic levels 1.8–5 V.

  Typical baud rates are 9600, 19200, 115200, up to 1–2 Mbps depending on the MCU.

- CAN basics
  🟡 -

  Robust multi-master differential bus using CANH/CANL with built-in arbitration where the node sending a recessive bit while seeing a dominant bit loses; works at transceiver voltage levels typically 3.3 V logic with 5 V bus signaling.

Common baud rates are 125 kbps, 250 kbps, 500 kbps, and 1 Mbps (CAN FD supports up to 8 Mbps data phase).

lower CAN ID wins arbitration because dominant bits override recessive ones during the ID field.

- LIN basics
  🟡 -
  
- DMA high-level workflow
  🟡 -
  On an ARM Cortex-M4, the DMA workflow is: first, enable the DMA clock in the RCC. Then choose a DMA channel/stream linked to your peripheral (like SPI, UART, ADC) and configure the basic parameters: source and destination addresses, transfer direction (peripheral-to-memory or memory-to-peripheral), data size, number of items, increment modes, and optionally circular or burst mode. Next, configure the DMA trigger/request from the peripheral and set priority and FIFO options if available. Then enable DMA interrupts in both the DMA controller and NVIC if you want half-transfer/complete/error callbacks. After that, enable the DMA stream and start the peripheral (or software trigger). The DMA then moves data autonomously; when it’s done, you handle the interrupt or poll the status flags, clear them, and optionally re-arm for the next transfer.

3. Rapid Quiz (10 min)
- How do you debug an I2C NACK?

  🟡 -
  “To debug an I²C NACK, I start by checking the fundamentals: Is the slave powered, wired correctly, and using the correct 7-bit address? Then I verify pull-up resistors on SDA and SCL and check signal integrity on a scope or logic analyzer to make sure the lines are actually reaching valid logic levels. I’ll also confirm the bus speed matches what the device supports. If the device requires initialization time or specific register sequences, I make sure those are correct. Finally, I probe the bus during the transaction to see whether the NACK happens on the address byte or data byte, which usually tells me whether it’s addressing, timing, or configuration related.”

- What causes SPI misalignment?
  🟡 -
  SPI misalignment happens when the master and slave don’t sample or shift data on the same clock edge or phase, causing bits to be read in the wrong order. It usually comes from wrong CPOL/CPHA settings, clock skew, or timing violations, and results in shifted or corrupted data bytes.
  
- Why CAN uses dominant bits.
  
CAN uses dominant bits (logical 0) because they can override recessive bits (logical 1) on the bus.
This allows non-destructive arbitration—multiple nodes can transmit at once, and the node with the highest priority (more dominant bits) wins without corrupting the frame.
It also improves reliability on a noisy, multi-driver bus.

- How do youfix the i2c
  In I²C, the 9th pulse is the ACK/NACK bit.
Each data byte is sent with 8 clock pulses for the data bits, and the 9th clock pulse is used by the receiver to pull SDA low for ACK or leave it high for NACK.
So every I²C byte transfer always has 9 SCL pulses total.
## HOUR 2 — FREERTOS + DRIVER DEVELOPMENT
Focus: RTOS concepts and driver patterns.

1. FreeRTOS (20 min)
- Mutex vs binary semaphore vs counting semaphore
- Task notifications

     Task notifications (in RTOSes like FreeRTOS) are a lightweight signaling mechanism used for task-to-task or ISR-to-task communication.
   They let one task or ISR wake up another task, send a small value (like a counter or flags), and are faster and cheaper than queues or semaphores because they don’t need heavy kernel objects.

- ISR safe APIs (FromISR)

   ISR-safe APIs (the …FromISR versions) are RTOS functions designed to be safe to call inside interrupts.
They avoid blocking, use special interrupt-safe critical sections, and often return a flag telling you whether a context switch is needed.
Regular APIs can’t be used in ISRs because they may block or manipulate scheduler state unsafely.
 
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

     I²C gets stuck low when a slave holds SDA or SCL low, often due to a missed STOP, clock stretching, or a reset during transfer. Fix by toggling SCL manually to release the slave, checking pull-ups, bus capacitance, and ensuring slaves aren’t brown-out resetting.
     
- SPI fails at high speed

     SPI fails at high speed due to signal integrity issues—skew, long traces, bad grounding, or poor rise times. Fix by slowing the clock, shortening traces, matching impedance, enabling stronger drive, and verifying CPOL/CPHA settings.
     
- Interrupt not firing

     Interrupts don’t fire when the interrupt isn’t enabled, priority is wrong, ISR not linked, pending flag not cleared, or the source signal doesn’t meet trigger conditions. Check NVIC enable, GPIO mode, edge selection, and ensure global interrupts are on.
  
- Boot failure

  Boot failure usually comes from wrong boot mode pins, corrupted firmware, missing clocks, or bad power/reset sequence. Check power rails, clock sources, flash programming, and ensure the bootloader or vector table is correctly placed.
  
- Noisy ADC readings
  Noisy ADC comes from poor grounding, long/high-impedance signal paths, noisy supply, or wrong sampling time. Fix by adding filtering, using short traces, enabling oversampling, improving power decoupling, and setting a longer ADC sampling window.

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

