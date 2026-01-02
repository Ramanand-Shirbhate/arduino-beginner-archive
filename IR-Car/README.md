# Arduino IR Remote Controlled Car

This project is a wireless robot car controlled using a standard Infrared (IR) remote. It utilizes an Arduino Uno, an L298N motor driver, and an IR receiver module to interpret commands for moving forward, backward, turning left, turning right, and stopping.

## 🚀 Features
* **Wireless Control:** Navigate the robot using any standard IR remote control (TV, DVD, or generic remote).
* **Calibration Tool Included:** Includes a decoder sketch to read signal codes from your specific remote.
* **Full Directional Control:** Forward, Backward, Left, Right, and Stop.
* **Simple Logic:** Uses `switch` case statements to map IR codes to motor actions.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno
* [cite_start]**Motor Driver:** L298N Dual H-Bridge Module [cite: 3]
* **Motors:** 4x DC Gear Motors (or 2x depending on chassis)
* [cite_start]**Communication:** IR Receiver Module (3-pin) [cite: 1]
* **Power:** 9V Battery or 12V Battery Pack (recommended for better performance)
* **Remote:** Any generic IR Remote Control
* **Wiring:** Jumper wires

## 🔌 Circuit Diagram
*(Ensure you upload your 'IR Car Circuit Diagram.jpg' to your repo and link it here)*

### Pin Connections
| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **IR Receiver** | Signal (Output) | [cite_start]7 [cite: 1, 3] |
| | VCC | 5V |
| | GND | GND |
| **L298N Driver** | Input 1 | [cite_start]8 [cite: 12] |
| | Input 2 | [cite_start]9 [cite: 12] |
| | Input 3 | [cite_start]10 [cite: 12] |
| | Input 4 | [cite_start]11 [cite: 12] |
| **Power** | Battery (+) | L298N 12V In |
| | Battery (-) | L298N GND & Arduino GND |

[cite_start]**Note:** The motors are controlled via pins 8, 9, 10, and 11. Pins 8 & 9 control one side (Right), and pins 10 & 11 control the other side (Left)[cite: 12, 13].

## 📚 Software & Library Installation
This project requires the **IRremote** library to function.

1.  Open the Arduino IDE.
2.  Go to **Sketch** -> **Include Library** -> **Manage Libraries...**
3.  In the search bar, type `IRremote`.
4.  Look for **"IRremote by Armin Joachimsmeyer"** (or similar standard library) and click **Install**.
    * *Note: If you are using a very new version of the library (v3.0+), some older code syntax might need updating. The provided code is compatible with standard implementations.*

## ⚙️ Setup & Calibration (Crucial Step)
Every remote control sends different unique codes. You must find out what codes **your** remote sends before the car will work.

### Step 1: Decode Your Remote
1.  Open the file `IR Decoder.ino` from this repository.
2.  Upload it to your Arduino.
3.  [cite_start]Open the **Serial Monitor** (Tools -> Serial Monitor) and set baud rate to `9600`[cite: 1].
4.  Point your remote at the IR receiver and press the buttons you want to use (e.g., Up, Down, Left, Right, OK/Stop).
5.  [cite_start]Write down the numeric codes that appear in the Serial Monitor for each button[cite: 2].

### Step 2: Configure the Car Code
1.  Open the file `IR Car Code.ino`.
2.  [cite_start]Locate the `switch (results.value)` block inside the `loop` function[cite: 5].
3.  Replace the numeric values in the `case` lines with the codes you wrote down in Step 1:
    * [cite_start]**Forward:** Replace `551504055` [cite: 5]
    * [cite_start]**Left:** Replace `551495895` [cite: 6]
    * [cite_start]**Stop:** Replace `551528535` [cite: 7]
    * [cite_start]**Right:** Replace `551512215` [cite: 8]
    * [cite_start]**Back:** Replace `553009523` [cite: 9]
4.  Upload the modified `IR Car Code.ino` to your Arduino.

## 🎮 How to Use
1.  Power on the car using the battery switch.
2.  Point your remote at the IR receiver.
3.  Press the buttons you mapped.
4.  [cite_start]The car will move continuously in that direction until you press your mapped **Stop** button (or another direction)[cite: 7].

## ❓ Troubleshooting

### 1. Compilation Error: "decode_results has no member named value"
If you see an error message mentioning that `value` is not found, you are likely using the newest version (4.0+) of the **IRremote** library, which has changed its command syntax. 

**The Fix:**
* In Arduino IDE, go to **Sketch** -> **Include Library** -> **Manage Libraries**.
* Search for **IRremote**.
* In the dropdown menu for version selection, choose **Version 2.8.0** (or any 2.x version) and click **Install**. 
* This code was written for the 2.x syntax and works perfectly with that version.

### 2. Car Doesn't Move / Motors Just Hum
The L298N motor driver drops about 2V from your power supply. If you are using a 9V battery, it might not have enough current to drive 4 motors once the voltage drops.
* **Solution:** Ensure your batteries are fresh. For best performance, use two Li-ion (18650) batteries or a dedicated 12V battery pack.

### 3. Remote Not Working in Sunlight
Infrared signals are easily washed out by strong sunlight.
* **Solution:** Test your robot indoors or in the shade. Direct sunlight can blind the receiver.

### 4. Serial Monitor Shows "FFFFFFFF"
If you press and hold a button, some remotes send `FFFFFFFF` (Hex) to indicate a "repeat" signal.
* **Solution:** Press the button just once quickly to get the actual command code during calibration.

## 📄 License
This project is open-source. Feel free to modify and share!