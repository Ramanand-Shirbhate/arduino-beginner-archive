# Arduino Object Follower Robot

This project is an autonomous robot capable of detecting and following an object (like a hand or another robot) while maintaining a specific distance. It uses a combination of Infrared (IR) sensors for direction control and an Ultrasonic sensor for distance measurement.

## 🚀 Features
* **Object Tracking:** Turns left or right to keep the target object in front using IR sensors.
* **Distance Maintenance:** Moves forward only when the object is within a specific range (10cm - 30cm).
* **Automatic Stop:** Stops moving if the object is too close (<10cm), too far (>30cm), or not detected by the IR sensors.
* **Speed Control:** Uses PWM to adjust motor speed for smoother turns.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible board)
* **Motor Driver:** L298N Module
* **Sensors:**
    * 1x HC-SR04 Ultrasonic Sensor
    * 2x IR Proximity Sensors (Digital)
* **Actuators:** 4x DC Gear Motors (paired as Left and Right) + Wheels
* **Power:** 12V Battery / Power Supply
* **Chassis:** Robot chassis kit
* **Wiring:** Jumper wires, Breadboard (optional)

## 🔌 Circuit Diagram
*(Ensure you upload your 'Object Follower Circuit Diagram.jpg' to your repo and link it here if you wish to display the image directly)*

### Pin Connections
| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **Right Motor** | Enable A (Speed) | 5 |
| | Input 1 | 7 |
| | Input 2 | 8 |
| **Left Motor** | Enable B (Speed) | 6 |
| | Input 3 | 9 |
| | Input 4 | 10 |
| **Ultrasonic Sensor** | Trig | 11 |
| | Echo | 12 |
| **IR Sensors** | Right IR Output | 2 |
| | Left IR Output | 3 |

**Note:** The 12V power supply is connected to the L298N module, which then powers the Arduino via the VIN pin (or separate power if preferred). Ensure common ground between the battery, L298N, and Arduino.

## 💻 Software & Libraries
* **Arduino IDE**
* **NewPing Library:** This project requires the `NewPing` library for the ultrasonic sensor.
    * *To install:* Go to **Sketch** -> **Include Library** -> **Manage Libraries**, search for "NewPing", and install it.

## ⚙️ How It Works
The robot uses a simple logic loop to decide its movement:

1.  **Sensors Read Data:** The code continuously reads the distance from the Ultrasonic sensor and the state (HIGH/LOW) of the Left and Right IR sensors.
2.  **Turning Logic:**
    * If the **Right IR** detects an object (LOW) and the Left does not: The robot turns **Right**.
    * If the **Left IR** detects an object (LOW) and the Right does not: The robot turns **Left**.
3.  **Forward Logic:**
    * If both IR sensors are balanced (or the object is centered) and the distance is between `10cm` and `30cm`, the robot moves **Forward**.
4.  **Stop Logic:**
    * If none of the above conditions are met (object out of range or lost), the robot **Stops**.

## 🔧 Setup Instructions
1.  Assemble the robot chassis and mount the motors.
2.  Connect the circuit according to the Pin Connections table.
3.  Open the `ObjectFollower.ino` file in Arduino IDE.
4.  Install the **NewPing** library.
5.  Connect your Arduino to your PC and upload the code.
6.  Place an object in front of the sensors and watch it follow!

## 📝 Customization
You can tweak the following macros at the top of the code to adjust the robot's behavior:
* `max_fwd_speed`: Adjusts the base speed (0-255).
* `max_turn_speed`: Adjusts how aggressively the robot turns.
* `min_dist` & `max_dist`: Sets the "sweet spot" distance for following.

## 📄 License
This project is open-source and available for anyone to use and modify.