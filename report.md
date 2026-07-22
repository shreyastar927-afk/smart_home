# ESP32-Based Smart Monitoring and Automated Control System

## Project Report

**Project Title:** ESP32-Based Smart Monitoring and Automated Control System

**Developed By:** Shreya

**Platform:** ESP32 DevKit V4 (Wokwi Simulation)

**Programming Language:** Arduino (Embedded C)

**Simulation Software:** Wokwi

---

# 1. Abstract

The ESP32-Based Smart Monitoring and Automated Control System is an IoT-based embedded system that automates home monitoring and improves safety using multiple environmental sensors and actuators. The ESP32 continuously collects data from eight different sensors and automatically performs actions based on predefined threshold values. The project integrates temperature monitoring, humidity sensing, gas leakage detection, flame detection, motion detection, rain sensing, light monitoring, and visitor detection. An OLED display provides live system status while an RGB LED and buzzer provide visual and audible alerts. The project demonstrates real-time sensor interfacing, embedded decision making, actuator control, and IoT automation using the ESP32.

---

# 2. Objectives

- Design an embedded smart home automation system using ESP32.
- Interface multiple analog and digital sensors.
- Perform automatic decision making based on sensor values.
- Control actuators such as LEDs, buzzer and stepper motor.
- Display live system information on an OLED display.
- Demonstrate communication protocols used in embedded IoT systems.
- Develop a scalable smart home prototype.

---

# 3. Components Used

| Component | Purpose |
|-----------|---------|
| ESP32 DevKit V4 | Main Controller |
| DHT22 Sensor | Temperature and Humidity |
| MQ2 Gas Sensor | Gas Leakage Detection |
| PIR Motion Sensor | Motion Detection |
| Flame Sensor (Simulated) | Fire Detection |
| Rain Sensor (Potentiometer) | Rain Detection |
| LDR Sensor | Light Intensity Detection |
| HC-SR04 Ultrasonic Sensor | Visitor Detection |
| RGB LED | System Status Indicator |
| Active Buzzer | Alarm |
| SSD1306 OLED Display | Live Dashboard |
| Push Button | Home/Away Mode Selection |
| Stepper Motor | Automatic Door |
| A4988 Driver | Stepper Motor Driver |

---

# 4. Software Used

- Arduino IDE
- Wokwi Simulator
- GitHub
- ESP32 Arduino Framework

---

# 5. System Architecture

Sensors:
- DHT22
- MQ2 Gas Sensor
- PIR Motion Sensor
- Flame Sensor
- Rain Sensor
- LDR
- Ultrasonic Sensor
- Push Button

↓

ESP32 Controller

↓

Outputs:
- OLED Display
- RGB LED
- Buzzer
- Stepper Motor

↓

Smart Home Automation

---

# 6. Pin Configuration

| Component | ESP32 Pin |
|------------|-----------|
| DHT22 | GPIO 4 |
| MQ2 Gas Sensor | GPIO 35 |
| PIR Sensor | GPIO 18 |
| LDR | GPIO 34 |
| Flame Sensor | GPIO 13 |
| Rain Sensor | GPIO 15 |
| Ultrasonic Trigger | GPIO 17 |
| Ultrasonic Echo | GPIO 5 |
| RGB Red | GPIO 16 |
| RGB Green | GPIO 33 |
| RGB Blue | GPIO 32 |
| Buzzer | GPIO 23 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| Stepper STEP | GPIO 26 |
| Stepper DIR | GPIO 27 |
| Stepper ENABLE | GPIO 25 |
| Push Button | GPIO 14 |

---

# 7. Working Principle

The ESP32 continuously reads data from all connected sensors inside the loop() function. Sensor readings are compared against predefined threshold values. Based on these values, the ESP32 automatically controls various actuators.

Examples:

- Temperature greater than 25°C → Fan status becomes ON.
- Gas value greater than threshold → Red LED and buzzer activate.
- Flame detected → Fire alarm activates.
- Visitor within 20 cm → Door opens automatically.
- Rain detected → Blue LED turns ON.
- Motion detected → Yellow LED and buzzer activate.
- Push button switches between Home Mode and Away Mode.
- OLED continuously displays live system information.
- Serial Monitor prints all sensor readings and system status.

The loop repeats every 500 milliseconds, enabling continuous monitoring.

---

# 8. Features Implemented

## Smart Climate Monitoring

- Temperature monitoring using DHT22
- Humidity monitoring
- Automatic fan status based on temperature

## Gas Leakage Detection

- Continuous gas monitoring
- Gas alert generation
- Audible alarm

## Fire Detection

- Flame detection
- High-priority safety alert

## Motion Detection

- PIR sensor detects human movement
- Security alert generation

## Visitor Detection

- Ultrasonic sensor detects approaching visitors
- Automatic door opening
- Automatic door closing after 3 seconds

## Rain Detection

- Rain monitoring
- Blue status indicator

## Light Monitoring

- Ambient light monitoring using LDR

## OLED Dashboard

Displays:
- Home Mode
- Temperature
- Humidity
- Light Level
- Distance

## RGB Status Indicator

Green → Normal Operation

Yellow → Motion Detected

Blue → Rain Detected

Red → Fire or Gas Alert

## Alarm System

Different buzzer frequencies indicate:
- Motion Detection
- Gas Leakage
- Fire Detection

## Home/Away Mode

Selected using a push button.

Home Mode enables automatic door operation.

Away Mode disables automatic door opening.

---

# 9. Communication Protocols Used

## I2C Communication

Used between the ESP32 and OLED Display.

Pins:
- SDA → GPIO21
- SCL → GPIO22

Advantages:
- Only two communication wires.
- Supports multiple I2C devices.
- High-speed communication.

## Analog Communication

Used for:
- MQ2
- LDR
- Flame Sensor
- Rain Sensor

The ESP32 ADC converts analog voltages into digital values.

## Digital Communication

Used for:
- PIR Sensor
- Push Button
- RGB LED
- Buzzer
- Stepper Driver

## Pulse-Based Communication

Used by the HC-SR04 Ultrasonic Sensor.

The ESP32 sends a trigger pulse and measures the echo pulse duration to calculate distance using the Time-of-Flight principle.

## Step Pulse Control

The ESP32 generates STEP pulses for the A4988 driver to rotate the stepper motor.

## Bluetooth Communication

Bluetooth functionality has been prepared in the code and can be enabled for future wireless control of the smart home system.

---

# 10. Concepts Applied from SMP Sessions

The following concepts learned during the SMP sessions were implemented:

- ESP32 Programming
- GPIO Configuration
- Analog Sensor Interfacing
- Digital Sensor Interfacing
- ADC Conversion
- I2C Communication
- Embedded C Programming
- Multi-Sensor Integration
- Threshold-Based Automation
- Real-Time Data Acquisition
- Stepper Motor Control
- Pulse Generation
- Embedded Decision Making
- Bluetooth Communication (Future Ready)

---

# 11. Results

The system successfully performs:

- Temperature Monitoring
- Humidity Monitoring
- Gas Leakage Detection
- Fire Detection
- Motion Detection
- Rain Detection
- Light Monitoring
- Visitor Detection
- Automatic Door Control
- OLED Live Dashboard
- RGB Status Indication
- Audible Alarm Generation
- Home/Away Mode Switching
- Continuous Serial Monitoring

---

# 12. Applications

- Smart Homes
- Home Security Systems
- Industrial Safety
- Gas Leakage Monitoring
- Fire Detection Systems
- Smart Buildings
- IoT Automation
- Educational Embedded System Projects

---

# 13. Advantages

- Low Cost
- Modular Design
- Real-Time Monitoring
- Easy Expansion
- Multiple Sensors in One System
- Automatic Safety Response
- Low Power Consumption
- Scalable IoT Architecture

---

# 14. Limitations

- Developed in simulation using Wokwi.
- Rain and Flame sensors are simulated using potentiometers.
- Bluetooth code is currently commented.
- Fan operation is represented logically rather than using a physical DC motor.
- Cloud connectivity has not yet been implemented.

---

# 15. Future Scope

Future improvements include:

- MQTT Cloud Integration
- Mobile Application
- Firebase Database
- Wi-Fi Dashboard
- Voice Assistant Integration
- AI-Based Anomaly Detection
- Push Notifications
- Smart Energy Analytics
- Remote Bluetooth and Wi-Fi Control

---

# 16. Conclusion

The ESP32-Based Smart Monitoring and Automated Control System successfully integrates multiple sensors and actuators into a single embedded IoT platform. The system continuously monitors environmental conditions, performs real-time decision making, and automatically responds to abnormal situations such as gas leakage, fire, motion detection, and visitor arrival. The project demonstrates practical implementation of embedded systems concepts, communication protocols, sensor interfacing, and automation techniques learned during the SMP sessions. The modular architecture allows future expansion into a complete cloud-enabled smart home solution.
