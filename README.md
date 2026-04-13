# 🏠 Smart Home Automation on ATmega32 (LCD + LDR + LM35 + Flame + PWM Fan)
<img width="1897" height="917" alt="image" src="https://github.com/user-attachments/assets/9c1c7262-b115-417c-944f-f06bbb5f204b" />

A smart home controller built on **ATmega32 @ 16 MHz**. It automates **lighting**, **fan speed**, and **fire alerts** using:
- **LDR** (light intensity) → drives **RGB LEDs** by thresholds
- **LM35** (temperature) → drives **DC fan** via **PWM (Timer0/OC0)** and H-bridge
- **Flame sensor** → triggers **buzzer** + LCD critical alert
- **16×2 LCD (8-bit)** → shows **FAN ON/OFF**, **Temp**, and **LDR %**

The firmware follows a **layered architecture** (application → drivers: LCD, LED, buzzer, motor, flame, LM35, LDR → MCAL: GPIO, PWM, ADC).

---

## ✨ Features

### Lighting (LDR → LEDs)
- **< 15 %**: **Red + Green + Blue ON**
- **16–50 %**: **Red + Green ON**
- **51–70 %**: **Red ON**
- **> 70 %**: **All OFF**

### Fan (LM35 → PWM speed)
- **≥ 40 °C**: **100 %**
- **35–<40 °C**: **75 %**
- **30–<35 °C**: **50 %**
- **25–<30 °C**: **25 %**
- **< 25 °C**: **OFF**

### Fire detection (Flame sensor)
- Show **“Critical alert!”** on LCD, **buzzer ON**, and remain in alert mode until cleared.

### LCD content
- **Row 1:** `FAN is ON` or `FAN is OFF`  
- **Row 2:** `Temp= xxC  LDR= xxx%`

---

## 🔌 Hardware & Pin Map

- **MCU:** ATmega32 @ **16 MHz**
- **Sensors:**  
  - **LDR:** **PA0 / ADC0**  
  - **LM35:** **PA1 / ADC1**
- **LCD 16×2 (8-bit mode):**  
  - **RS:** **PD0**  
  - **E:** **PD1**  
  - **R/W:** **GND** (write-only)  
  - **D0..D7:** **PORTC**
- **Fan / H-bridge:**  
  - **IN1:** **PB0**  
  - **IN2:** **PB1**  
  - **Enable1 (PWM):** **PB3 / OC0**
- **LEDs:**  
  - **Red:** **PB5**  
  - **Green:** **PB6**  
  - **Blue:** **PB7**
- **Flame sensor:** **PD2**  
- **Buzzer:** **PD3**

---

## 🧱 Software Architecture

Application Layer
├─ Light control (LDR → LED bands)
├─ Fan control (LM35 → PWM duty)
├─ Fire monitor (Flame → buzzer + LCD alert)
└─ LCD view (fan state, Temp, LDR%)

Drivers (HAL)
├─ LCD (8-bit)
├─ LED (RGB, positive/negative logic)
├─ Buzzer
├─ DC Motor (H-bridge control)
├─ Flame sensor (polling)
├─ LM35 (temperature)
└─ LDR (percentage)

MCAL / Low-level
├─ GPIO
├─ ADC (Vref=2.56 V, prescaler=F_CPU/128)
└─ PWM (Timer0, OC0, non-inverting, prescaler=F_CPU/1024)

---

## 🔧 Driver Contracts (APIs)

- **ADC**
  - `void ADC_init(void)` — Vref=**2.56 V**, prescaler=**F_CPU/128**
  - `uint16 ADC_readChannel(uint8 channel_num)` — read ADCx
- **PWM (Timer0)**
  - `void PWM_Timer0_Start(uint8 duty_cycle)` — non-inverting on **OC0**, prescaler **F_CPU/1024**
- **LCD (8-bit)** — print strings, move cursor; pins as above
- **LDR**
  - `uint16 LDR_getLightIntensity(void)` — return **0–100 %**
- **LEDs**
  - `void LEDS_init(void)` — configure pins, all OFF
  - `void LED_on(LED_ID id)`, `void LED_off(LED_ID id)` — positive/negative logic supported
- **DC Motor**
  - `void DcMotor_Init(void)` — set directions, stop initially
  - `void DcMotor_Rotate(DcMotor_State state, uint8 speed)` — **CW/CCW/Stop**, speed % (0–100)
- **Flame**
  - `void FlameSensor_init(void)` — set input
  - `uint8 FlameSensor_getValue(void)` — read (polling)
- **Buzzer**
  - `void Buzzer_init(void)`, `void Buzzer_on(void)`, `void Buzzer_off(void)`

---

## 🕹️ Operation

1. **Lighting:** LDR percentage maps to LED bands (see thresholds).  
2. **Fan:** LM35 temperature maps to PWM duty; LCD shows **FAN ON/OFF**.  
3. **Fire:** flame → LCD shows **“Critical alert!”**, buzzer ON until flame clears.  
4. **LCD:** live `Temp=…C` and `LDR=…%` on row 2.    


