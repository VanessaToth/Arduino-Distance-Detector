Arduino Distance Detector with Servo & Alert System

An embedded C++ application built on Arduino UNO that continuously scans the surrounding environment using an ultrasonic sensor, controls a servo motor for area sweeping, and triggers dynamic visual and audio telemetry alerts.

---
 Key Features

- **Ultrasonic Distance Measurement:** Accurately measures object distances using the HC-SR04 ultrasonic sensor.
- **Dynamic Servo Scanning:** Sweeps the servo motor between $0^\circ$ and $180^\circ$ when the area is clear.
- **Non-blocking Timing Alerts:** Utilizes `millis()` non-blocking timers to flash a Red LED and pulse a buzzer at a 300ms interval upon obstacle detection ($<40\text{ cm}$).
- **LCD Telemetry Display:** Real-time system state (`AREA IS CLEAR` / `AREA NOT CLEAR`) and telemetry metrics (distance in cm) displayed via I2C LCD interface.
- **Position Isolation:** Automatically detaches the servo during alert states to lock on the target obstacle position.

---
 Hardware Components

- **Microcontroller:** Arduino UNO
- **Sensor:** HC-SR04 Ultrasonic Distance Sensor
- **Actuator:** Servo Motor
- **Display:** 16x2 LCD with I2C Module (`0x27`)
- **Indicators & Output:** Red LED, Blue LED, Piezo Buzzer

---
 Circuit Pinout Configuration

| Component | Arduino Pin | Description |
|---|---|---|
| Ultrasonic Trig | Pin 9 | Pulse trigger output |
| Ultrasonic Echo | Pin 8 | Echo pulse duration input |
| Piezo Buzzer | Pin 7 | Audio alert output |
| Red LED | Pin 6 | Alert state indicator |
| Blue LED | Pin 5 | Clear state indicator | 
| Servo Motor | Pin 10 | PWM position control |
| LCD I2C | SDA / SCL | I2C communication pins |

---
 How to Run

1. Connect the hardware components according to the pinout configuration table above.
2. Open the project in **Arduino IDE** or **PlatformIO**.
3. Install required libraries:
   - `LiquidCrystal_I2C`
   - `Servo`
4. Compile and upload `src/main.cpp` to your Arduino UNO board.
