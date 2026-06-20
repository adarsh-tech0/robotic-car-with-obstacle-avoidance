# 🧾 Bill of Materials (BOM)

Complete components list for the **Voice Controlled Robot Car with Obstacle Avoidance** project.

---

## Components List

| # | Component | Model | Quantity |
|---|-----------|-------|----------|
| 1 | Microcontroller Board | Arduino Uno (ATmega328P) | 1 |
| 2 | Motor Driver Module | L298N | 1 |
| 3 | Bluetooth Module | HC-05 | 1 |
| 4 | Ultrasonic Sensor | HC-SR04 | 1 |
| 5 | Servo Motor | SG90 (or equivalent) | 1 |
| 6 | DC Gear Motors with Wheels | TT Gear Motor | 2 |
| 7 | Battery | 9V | 1 |
| 8 | Switch | Rocker/Push Switch | 1 |
| 9 | Connecting Wires | Jumper Wires (M-M, M-F, F-F) | As required |
| 10 | USB Cable | USB 2.0 Type A/B | 1 |

---

## Component Specifications

### 1. Arduino Uno (ATmega328P)

| Parameter | Value |
|-----------|-------|
| Microcontroller | ATmega328P — 8-bit AVR |
| Operating Voltage | 5V |
| Recommended Input Voltage | 7–12V |
| Input Voltage Limits | 6–20V |
| Digital I/O Pins | 14 (6 with PWM output) |
| Analog Input Pins | 6 (A0–A5) |
| DC Current per I/O Pin | 40mA |
| DC Current on 3.3V Pin | 50mA |
| Flash Memory | 32 KB (0.5 KB used by bootloader) |
| SRAM | 2 KB |
| EEPROM | 1 KB |
| Clock Speed | 16 MHz |

---

### 2. Motor Driver Module (L298N)

| Parameter | Value |
|-----------|-------|
| Driver Model | L298N 2A |
| Driver Chip | Double H-Bridge L298N |
| Motor Supply Voltage (max) | 46V |
| Motor Supply Current (max) | 2A |
| Logic Voltage | 5V |
| Driver Voltage | 5–35V |
| Driver Current | 2A |
| Logical Current | 0–36mA |
| Maximum Power | 25W |
| Features | Heatsink, Power-On LED, Current Sense |

**Pin Map:**

| Pin | Function |
|-----|----------|
| IN1 & IN2 | Motor A direction control |
| IN3 & IN4 | Motor B direction control |
| ENA | PWM enable for Motor A |
| ENB | PWM enable for Motor B |
| OUT1 & OUT2 | Motor A output |
| OUT3 & OUT4 | Motor B output |
| 12V | DC power input |
| 5V | Logic power supply |
| GND | Ground |

---

### 3. Bluetooth Module (HC-05)

| Parameter | Value |
|-----------|-------|
| Bluetooth Version | 2.0 + EDR |
| Default Baud Rate | 9600 |
| Default PIN | 1234 or 0000 |
| Operating Voltage | 3.3V – 5V |
| Range | ~10m (class 2) |
| Interface | UART (TX, RX) |
| Mode | Master / Slave |

---

### 4. Ultrasonic Sensor (HC-SR04)

| Parameter | Value |
|-----------|-------|
| Operating Voltage | 5V DC |
| Working Current | 15mA |
| Working Frequency | 40 KHz |
| Max Range | 4m |
| Min Range | 2cm |
| Measuring Angle | 15° |
| Trigger Input Signal | 10µs TTL pulse |
| Echo Output Signal | TTL level signal |

---

### 5. Servo Motor (SG90)

| Parameter | Value |
|-----------|-------|
| Operating Voltage | 4.8V – 6V |
| Torque | 1.8 kg/cm (at 4.8V) |
| Speed | 0.1 sec/60° (at 4.8V) |
| Rotation Range | 0° – 180° |
| Control Signal | PWM (1–2ms pulse width) |
| Dead Band Width | 10µs |

---

### 6. DC Gear Motors + Wheels

| Parameter | Value |
|-----------|-------|
| Type | TT DC Gear Motor |
| Operating Voltage | 3–6V |
| No Load Speed | ~200 RPM (at 6V) |
| Shaft Diameter | 4mm |
| Wheel Diameter | ~65mm (rubber tyre) |

---

### 7. Battery (9V)

| Parameter | Value |
|-----------|-------|
| Voltage | 9V |
| Type | Alkaline / Li-ion |
| Cells | 6 small cylindrical cells in series |
| Usage | Powers Arduino + motor driver |

---

## Arduino Pin Connections

| Arduino Pin | Connected To | Purpose |
|-------------|-------------|---------|
| Pin 0 (RX) | HC-05 TX | Bluetooth receive |
| Pin 1 (TX) | HC-05 RX | Bluetooth transmit |
| Pin 2 | L298N IN1 | Motor A control |
| Pin 3 | L298N IN2 | Motor A control |
| Pin 4 | L298N IN3 | Motor B control |
| Pin 5 | L298N IN4 | Motor B control |
| Pin 6 | HC-SR04 TRIG | Ultrasonic trigger |
| Pin 7 | HC-SR04 ECHO | Ultrasonic echo |
| Pin 9 | SG90 Signal | Servo PWM |
| 5V | HC-SR04 VCC, HC-05 VCC | Power |
| GND | All GND pins | Common ground |
| VIN | 9V Battery (+) | Power input |

---

## Software

| Tool | Version | Purpose |
|------|---------|---------|
| Arduino IDE | 1.8+ | Firmware upload |
| Android Studio | Any | Android app development |
| Library: Servo.h | Built-in | Servo motor control |

---

## Obstacle Avoidance Logic

| Parameter | Value |
|-----------|-------|
| Detection threshold | 20 cm |
| Servo scan range | 0° to 180° |
| Scan step | 10° per step |
| Backward move distance | 50 cm |
| Serial baud rate | 9600 |

---

*Refer to `README.md` for full wiring instructions and setup guide.*
