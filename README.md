# 🤖 Voice Controlled Robot Car with Obstacle Avoidance

A Bluetooth-controlled robot car that accepts voice commands from an Android app and autonomously avoids obstacles using an ultrasonic sensor — built on the Arduino platform.

---

## 📌 Overview

This project combines voice recognition, wireless communication, and real-time obstacle avoidance into a single autonomous robot car. The user speaks commands into an Android app, which sends them via Bluetooth to the Arduino. The robot also continuously scans its surroundings with an ultrasonic sensor mounted on a servo — automatically stopping and reversing when an obstacle is detected.

---

## 🧰 Components Used

| Component | Model | Purpose |
|-----------|-------|---------|
| Microcontroller | Arduino Uno (ATmega328P) | Brain of the system |
| Motor Driver | L298N | Controls DC motor speed & direction |
| Bluetooth Module | HC-05 | Wireless communication with Android app |
| Ultrasonic Sensor | HC-SR04 | Obstacle detection |
| Servo Motor | SG90 | Rotates sensor for 180° scanning |
| DC Gear Motors + Wheels | — | Robot movement |
| Battery | 9V | Power supply |

---

## 🔁 How It Works

1. User opens the Android app (built in Android Studio) and pairs with the **HC-05** Bluetooth module (default PIN: `1234` or `0000`)
2. User taps the **mic icon** and speaks a command (e.g., "forward", "left", "stop")
3. The app converts speech to text and sends it via Bluetooth
4. **Arduino Uno** receives the string, matches it to a command, and drives the **L298N** motor driver accordingly
5. Simultaneously, the **servo** sweeps the ultrasonic sensor across 180° — if an obstacle is detected within 20 cm, the robot auto-stops and reverses

---

## 🗂️ Block Diagram

```
[Android App] → [HC-05 BT Module] → [Arduino Uno] → [L298N Motor Driver] → [DC Motors]
                                          ↑
                               [Ultrasonic Sensor + Servo]
```

---

## 🎮 Voice Commands

| Command | Action |
|---------|--------|
| `F` | Move Forward |
| `B` | Move Backward |
| `R` | Turn Right |
| `L` | Turn Left |
| `S` | Stop |
| `X` | Move Back (short distance) |

---

## ⚙️ Arduino Pin Connections

| Arduino Pin | Connected To |
|-------------|-------------|
| Pin 2, 3 | L298N IN1, IN2 (Motor A) |
| Pin 4, 5 | L298N IN3, IN4 (Motor B) |
| Pin 6 | Ultrasonic TRIG |
| Pin 7 | Ultrasonic ECHO |
| Pin 9 | Servo Signal |
| RX/TX (0,1) | HC-05 TX/RX |

---

## 💻 Software

- **Arduino IDE** — Firmware development
- **Android Studio** — Android control app
- **Libraries used:** `Servo.h`

---

## ✅ Results

- Reliable voice command recognition and execution via Bluetooth
- Effective real-time obstacle detection and auto-avoidance
- Wireless range: ~50m (indoors), ~100m (open area)
- Successfully tested in cluttered indoor environments

---

## ⚡ Advantages

- Hands-free operation via voice
- Autonomous obstacle avoidance — no manual intervention needed
- Accessible for differently-abled users
- Low cost, built with locally available components

---

## 📚 Tech Stack

`Arduino` `Embedded C` `HC-05 Bluetooth` `L298N` `HC-SR04` `Android Studio` `Servo PWM`

---

## 📄 License

This project is open for educational and personal use.
