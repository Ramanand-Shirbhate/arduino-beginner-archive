# Arduino Obstacle Avoiding Robot

This project is an autonomous robot that navigates its environment by detecting and avoiding obstacles. It uses an ultrasonic sensor mounted on a servo motor to "look" left and right when an obstacle is detected, deciding the best path to take.

## 🚀 Features
* **Autonomous Navigation:** Moves forward continuously until an obstacle is detected within 40cm.
* **Smart Obstacle Avoidance:**
    * Stops and scans the surroundings (Left and Right) using a servo-mounted ultrasonic sensor.
    * Compares distances and turns toward the direction with more space.
* **Reverse Maneuver:** Briefly moves backward before turning to ensure clearance.
* **Speed Control:** Uses PWM (Pulse Width Modulation) to control motor speed via the L298N driver.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible board)
* **Motor Driver:** L298N Module
* **Sensors:** 1x HC-SR04 Ultrasonic Sensor
* **Actuators:**
    * 4x DC Gear Motors (Yellow) + Wheels
    * 1x SG90 Servo Motor (for scanning)
* **Power:** 12V Battery / Power Supply
* **Chassis:** Robot chassis kit (4WD)
* **Wiring:** Jumper wires

## 🔌 Circuit Diagram
*(Ensure you upload your 'Obstacle Avoider Circuit diagram.jpg' to your repo and link it here)*

### Pin Connections
| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **Right Motor** | Enable A (Speed) | 5 |
| | Input 1 (Forward) | 9 |
| | Input 2 (Backward) | 8 |
| **Left Motor** | Enable B (Speed) | 6 |
| | Input 3 (Forward) | 10 |
| | Input 4 (Backward) | 11 |
| **Ultrasonic Sensor** | Trig | A5 |
| | Echo | A4 |
| **Servo Motor** | Signal (Orange/Yellow) | 3 |

**Note:** The servo motor power (VCC/GND) and Ultrasonic sensor power should be connected to the Arduino's 5V and GND rails. The L298N takes the main 12V supply.

## 💻 Software & Libraries
* **Arduino IDE**
* **NewPing Library:** Required for stable ultrasonic sensor readings.
* **Servo Library:** Standard Arduino library (usually pre-installed).

**Installation Steps:**
1.  Open Arduino IDE.
2.  Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
3.  Search for `NewPing` and install the latest version.

## ⚙️ How It Works
The robot operates on a continuous loop:
1.  **Forward Motion:** It moves forward by default at a set speed.
2.  **Detection:** The ultrasonic sensor continuously measures distance.
3.  **Obstacle Encountered:** If distance < 40cm:
    * The robot stops and reverses slightly.
    * The servo rotates the sensor to look **Right** (50°) and then **Left** (170°).
    * It compares the distance readings.
    * It turns toward the clearer path and resumes forward motion.

## 🔧 Setup Instructions
1.  Assemble the chassis and mount the motors.
2.  Mount the servo motor at the front and attach the ultrasonic sensor to the servo horn.
3.  Wire the components according to the pin table and circuit diagram.
4.  Upload the code (`ObstacleAvoider.ino`) to the Arduino.
5.  Power on the 12V supply and place the robot on the floor.

## 📝 Customization
You can tweak these values in the code:
* `maximum_distance`: Maximum ping distance (currently 200cm).
* `speed`: Motor speed (0-255). Currently set to 150 for forward and turning, 180 for backward.
* `distance`: The threshold for detecting an obstacle (currently checked against 40 in the loop).

## 📄 License
This project is open-source and available for anyone to use and modify.