# Arduino Line Follower Robot

A simple and efficient Line Follower Robot built using an Arduino Uno, L298N Motor Driver, and IR sensors. This robot detects a black line on a white surface and navigates autonomously by adjusting the motor directions based on sensor input.

## 📸 Circuit Diagram
![Line Follower Circuit](Line%20Follower%20Circuit%20Diagram.png)
*(Ensure the image file name matches the one in your repository)*

## 🚀 Features
* **Autonomous Navigation:** Follows a black line on a white background.
* **Differential Steering:** Controls left and right motors independently for smooth turning.
* **Speed Control:** Uses PWM (Pulse Width Modulation) on Enable pins to manage motor speed.
* **Stop Mechanism:** Automatically stops when both sensors detect a black line (intersection or finish line).

## 🛠️ Components Required
* **Microcontroller:** Arduino Uno
* **Motor Driver:** L298N Module
* **Sensors:** 2x IR (Infrared) Proximity Sensors
* **Motors:** 2x DC Gear Motors
* **Power:** 9V Battery or Li-ion Battery Pack (6V - 12V)
* **Chassis:** Robot chassis kit with wheels
* **Connection:** Jumper wires and Breadboard (optional)

## 🔌 Pin Connections

### Motors (L298N to Arduino)
| L298N Pin | Arduino Pin | Description |
| :--- | :--- | :--- |
| **ENA** | 10 | Enable Left Motor (PWM Speed) |
| **IN1** | 9 | Left Motor Logic 1 |
| **IN2** | 8 | Left Motor Logic 2 |
| **IN3** | 7 | Right Motor Logic 1 |
| **IN4** | 6 | Right Motor Logic 2 |
| **ENB** | 5 | Enable Right Motor (PWM Speed) |

### Sensors
| Sensor | Arduino Pin |
| :--- | :--- |
| **Left IR Sensor** | 4 |
| **Right IR Sensor** | 3 |

*Note: Power the L298N with the battery. Connect the Arduino 5V to the L298N 5V output (if the driver supports it) or power the Arduino separately via the Vin pin.*

## 🧠 Logic & Algorithm

The robot uses a differential drive system based on the feedback from the two IR sensors. The logic assumes **Active Low** sensors (Low signal when reflecting off white, High signal on black line).

| Left Sensor | Right Sensor | Action | Behavior |
| :--- | :--- | :--- | :--- |
| **White** (LOW) | **White** (LOW) | `Forward` | Robot moves straight |
| **White** (LOW) | **Black** (HIGH) | `Right` | Robot turns Right to correct |
| **Black** (HIGH) | **White** (LOW) | `Left` | Robot turns Left to correct |
| **Black** (HIGH) | **Black** (HIGH) | `Stop` | Robot stops (Finish/Crossroad) |

## 💻 Code Overview

The code is written in C++ for the Arduino IDE.

1.  **Setup:** Defines pin modes and sets the initial motor speed (`analogWrite` to ENA/ENB).
2.  **Loop:** Continuously reads the state of `LS` (Left Sensor) and `RS` (Right Sensor).
3.  **Conditions:**
    * If both see white (Logic `!0 && !0`), both motors turn forward.
    * If the robot deviates left (Right sensor hits line), the Left motor moves and Right stops/reverses to turn Right.
    * If the robot deviates right (Left sensor hits line), the Right motor moves and Left stops/reverses to turn Left.

## ⚙️ How to Run
1.  Assemble the circuit according to the diagram.
2.  Calibrate the IR sensors using the built-in potentiometer so they correctly distinguish between the black line and the white floor.
3.  Open the `.ino` file in the Arduino IDE.
4.  Connect your Arduino to the PC.
5.  Select the correct Board and Port from the `Tools` menu.
6.  Upload the code.
7.  Place the robot on the track and connect the battery!

## 🤝 Contributing
Feel free to fork this repository and submit pull requests. You can improve the project by adding PID control for smoother tracking or adding obstacle avoidance features.

## 📜 License
This project is open-source.