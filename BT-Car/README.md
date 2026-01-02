# Smartphone Controlled Bluetooth Robot Car

This project is a 4-wheel drive robot car controlled wirelessly via a Smartphone (Android) using Bluetooth. It supports variable speed control, diagonal movements, and features functional headlights, taillights, and a horn.

## 🚀 Features
* **Wireless Control:** Communicates via HC-05/HC-06 Bluetooth module.
* **Full Maneuverability:** Forward, Backward, Left, Right, and **Diagonal** movements.
* **Speed Control:** Adjust motor speed directly from the app (0% - 100%).
* **Accessories:**
    * **Headlights & Taillights:** Toggleable front and rear LEDs.
    * **Horn:** Piezo buzzer for signaling.
* **Braking:** Electronic braking system logic included.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno (or Mega/Nano)
* **Motor Driver:** L298N Dual H-Bridge Module
* **Communication:** HC-05 or HC-06 Bluetooth Module
* **Motors:** 4x DC Gear Motors + Wheels
* **Power:** 2x 18650 Li-ion Batteries (or 12V DC equivalent)
* **Lights/Sound:**
    * 4x LEDs (2 Front, 2 Back)
    * 1x Buzzer
    * Resistors (220Ω or 330Ω for LEDs)
* **Chassis:** Robot Car Chassis Kit

## 🔌 Circuit Diagram
*(Upload your 'BT Car Circuit Diagram.jpg' to your repository and link it here)*

### Pin Configuration
| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **L298N Driver** | IN1 (Right Fwd) | 5 |
| | IN2 (Right Bwd) | 6 |
| | IN3 (Left Fwd) | 10 |
| | IN4 (Left Bwd) | 11 |
| **Bluetooth (HC-05)** | TX | 0 (RX) |
| | RX | 1 (TX) |
| **Accessories** | Front Right LED | A0 (Pin 14) |
| | Front Left LED | A1 (Pin 15) |
| | Back Right LED | A2 (Pin 16) |
| | Back Left LED | A3 (Pin 17) |
| | Buzzer | A4 (Pin 18) |

**⚠️ Important Wiring Note:** The Bluetooth Module's **TX** pin goes to Arduino's **RX** pin, and the Module's **RX** pin goes to Arduino's **TX** pin.

## 📚 Software & Libraries
Great news! **No external library installation is required.**

This code runs entirely on the standard Arduino core libraries. You do not need to download or install anything extra from the Library Manager.

* `Serial`: Used for Bluetooth communication (Standard).
* `analogWrite`: Used for Motor PWM speed control (Standard).

## 📱 App Command Protocol
To control this robot, you need an Android Bluetooth Controller app that sends specific characters. Configure your app buttons to send the following:

**Movement:**
* `F`: Forward
* `B`: Backward
* `L`: Left
* `R`: Right
* `G`: Forward Left
* `I`: Forward Right
* `H`: Back Left
* `J`: Back Right
* `S`: Stop

**Accessories:**
* `W`: Front Lights ON | `w`: Front Lights OFF
* `U`: Back Lights ON | `u`: Back Lights OFF
* `V`: Horn ON | `v`: Horn OFF

**Speed Control:**
* `0` - `9`: Sets speed from slow to fast.
* `q`: Max Speed (100%).

## 🔧 Installation Steps
1.  **Assembly:** Build your robot chassis and mount the motors.
2.  **Wiring:** Connect all components according to the circuit diagram and Pin Configuration table.
3.  **Code Upload:**
    * Open the `.ino` file in Arduino IDE.
    * **CRITICAL STEP:** Disconnect the Bluetooth Module's **RX** and **TX** wires (Pins 0 and 1) before uploading. The code upload will fail if these are connected.
    * Select your board (Arduino Uno) and Port.
    * Click **Upload**.
4.  **Finalize:** Reconnect the RX/TX wires after the upload says "Done uploading".
5.  **Connect:** Open your Bluetooth App, pair with the HC-05 (default password often `1234` or `0000`), and start driving!

## 📄 License
This project is open-source. Feel free to modify and share!