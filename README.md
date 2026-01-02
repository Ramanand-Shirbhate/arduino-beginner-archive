# 🤖 Arduino Robotics Archive

![Status](https://img.shields.io/badge/Status-Active-success)
![Platform](https://img.shields.io/badge/Platform-Arduino-blue)
![Hardware](https://img.shields.io/badge/Hardware-Robotics-red)

## 📖 Overview

Welcome to the **Arduino Beginner Archive**. This repository documents my journey into embedded systems and robotics. It focuses on the construction and programming of autonomous and manually controlled mobile robots.

Each project explores a different method of interacting with the physical world—from wireless control (Bluetooth/IR) to autonomous decision-making (Obstacle Avoidance/Line Following).

## 🛠️ Hardware Stack

These projects primarily utilize the **Arduino Uno** platform along with standard robotics components:

* **Microcontroller:** Arduino Uno (R3)
* **Motor Driver:** L298N H-Bridge or L293D Motor Shield
* **Communication:** HC-05/HC-06 Bluetooth Module, IR Receiver (TSOP)
* **Sensors:** * Ultrasonic Sensor (HC-SR04)
    * IR Proximity/Line Sensors
    * Servo Motors (SG90)
* **Power:** 18650 Li-ion Batteries or 9V/12V DC source

## 📂 Project Directory

Below is a detailed list of the robotic modules included in this archive:

| Project Name | Type | Description | Key Modules |
| :--- | :--- | :--- | :--- |
| **BT-Car** | Wireless Control | A remote-controlled car operated via a Smartphone App using Bluetooth serial communication. | HC-05 Bluetooth Module, Android App |
| **IR-Car** | Wireless Control | A vehicle controlled using a standard infrared TV/DVD remote. Decodes hex signals to drive motors. | IR Receiver (TSOP), IR Remote |
| **Line Following Robot** | Autonomous | A robot that autonomously detects and follows a black line on a white surface (or vice versa) using PID or logic control. | IR Sensor Array |
| **Obstacle Avoiding Robot** | Autonomous | A robot that navigates freely, detecting walls or objects in its path and turning automatically to avoid collisions. | Ultrasonic Sensor (HC-SR04), Servo |
| **Object Following Robot** | Autonomous | A robot designed to detect a specific object (like a hand) and maintain a set distance to "follow" it. | Ultrasonic/IR Sensors |

## 🚀 Getting Started

To test these robots on your own hardware:

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/Ramanand-Shirbhate/arduino-beginner-archive.git](https://github.com/Ramanand-Shirbhate/arduino-beginner-archive.git)
    ```
2.  **Select a Project:** Open the desired folder (e.g., `Line Following Robot`).
3.  **Check Pinout:** Open the `.ino` file and check the `#define` or variable section at the top to match the pins with your wiring.
4.  **Install Libraries:** Ensure you have necessary libraries installed (e.g., `AFMotor.h` or `NewPing.h`) via the Arduino Library Manager.
5.  **Upload:** Connect your Arduino and upload the code.

## 🤝 Contributing

Suggestions for code optimization (especially improving the turning logic or implementing PID for the line follower) are welcome!

1.  Fork the Project
2.  Create your Feature Branch 
3.  Commit your Changes
4.  Push to the Branch
5.  Open a Pull Request

## 📄 License

This project is open-source and available for educational purposes.

---
*Maintained by [Ramanand Shirbhate](https://github.com/Ramanand-Shirbhate)*
