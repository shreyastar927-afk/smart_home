ESP32-Based Smart Monitoring and Automated Control System
Project Report

Project Title:
ESP32-Based Smart Monitoring and Automated Control System

Developed By: Shreya
Platform: ESP32 DevKit V4 (Wokwi Simulation)
Programming Language: Arduino (Embedded C)
Simulation Software: Wokwi

1. Abstract

The ESP32-Based Smart Monitoring and Automated Control System is an IoT-based embedded system designed to automate home monitoring and improve safety using multiple environmental sensors and actuators. The system continuously acquires real-time data from eight sensors, processes the information using the ESP32 microcontroller, and performs automatic actions based on predefined thresholds.

The project integrates temperature monitoring, gas leakage detection, flame detection, motion sensing, rain sensing, light monitoring, visitor detection using an ultrasonic sensor, and an automatic door system. An OLED display provides live system status, while an RGB LED and buzzer provide visual and audible alerts. The project demonstrates real-time decision-making, sensor interfacing, actuator control, and embedded IoT concepts using the ESP32.

2. Objective

The objectives of this project are:

Design an embedded automation system using ESP32.
Interface multiple analog and digital sensors.
Implement threshold-based automation.
Control actuators automatically based on sensor data.
Display real-time system information.
Demonstrate communication protocols used in IoT.
Develop a scalable smart home prototype.
3. Components Used
Component	Quantity	Purpose
ESP32 DevKit V4	1	Main Controller
OLED SSD1306	1	Display
DHT22 Sensor	1	Temperature & Humidity
MQ2 Gas Sensor	1	Gas Detection
PIR Sensor	1	Motion Detection
Ultrasonic HC-SR04	1	Visitor Detection
LDR Sensor	1	Light Intensity
Flame Sensor (Potentiometer in simulation)	1	Fire Detection
Rain Sensor (Potentiometer in simulation)	1	Rain Detection
RGB LED	1	Status Indicator
Active Buzzer	1	Alarm
Push Button	1	Mode Selection
Stepper Motor	1	Automatic Door
A4988 Driver	1	Stepper Driver
4. Software Used
Arduino IDE (Embedded C)
Wokwi Simulator
GitHub
ESP32 Arduino Framework
5. System Architecture
                    Sensors
      -------------------------------
      DHT22
      MQ2
      PIR
      Flame
      Rain
      LDR
      Ultrasonic
      Push Button
              │
              ▼
        ESP32 Controller
              │
   --------------------------
   OLED Display
   RGB LED
   Buzzer
   Stepper Motor
              │
              ▼
     Smart Home Automation
6. Pin Configuration
Component	ESP32 Pin
DHT22	GPIO 4
MQ2 Gas Sensor	GPIO 35
PIR Sensor	GPIO 18
LDR	GPIO 34
Flame Sensor	GPIO 13
Rain Sensor	GPIO 15
Ultrasonic Trigger	GPIO 17
Ultrasonic Echo	GPIO 5
RGB Red	GPIO 16
RGB Green	GPIO 33
RGB Blue	GPIO 32
Buzzer	GPIO 23
OLED SDA	GPIO 21
OLED SCL	GPIO 22
Stepper STEP	GPIO 26
Stepper DIR	GPIO 27
Stepper ENABLE	GPIO 25
Push Button	GPIO 14
7. Working Principle

The ESP32 continuously reads data from all connected sensors inside the loop() function.

The controller compares sensor readings with predefined threshold values and automatically performs suitable actions.

Examples:

Temperature > 25°C → Fan Status becomes ON.
Gas concentration > Threshold → Red LED and buzzer activate.
Flame detected → Fire alarm activates.
Visitor within 20 cm → Door opens automatically.
Rain detected → Blue LED turns ON.
Motion detected → Yellow LED and alarm activate.
Push button toggles between Home and Away modes.
OLED displays live system status.
Serial Monitor continuously prints all sensor values.

The loop repeats every 500 ms, providing continuous real-time monitoring.

8. Features Implemented
Smart Climate Monitoring
Temperature monitoring using DHT22.
Humidity monitoring.
Automatic fan status based on temperature.
Gas Leakage Detection
Continuous gas monitoring.
Gas alert generation.
Visual and audible warning.
Fire Detection
Flame sensor monitoring.
Immediate fire alert.
Highest priority safety event.
Motion Detection
PIR sensor detects human movement.
Security alert generation.
Visitor Detection
Ultrasonic sensor detects approaching visitors.
Automatic door opening.
Automatic door closing after 3 seconds.
Rain Detection
Rain intensity monitoring.
Blue status indicator.
Light Monitoring
LDR continuously measures ambient light intensity.
OLED Dashboard

Displays:

Mode
Temperature
Humidity
Light Level
Distance
RGB Status Indicator

Green

Normal operation

Yellow

Motion detected

Blue

Rain detected

Red

Gas leakage
Fire detection
Alarm System

The buzzer generates different alarm frequencies for:

Motion detection
Gas leakage
Fire detection
Home/Away Mode

Controlled using a push button.

Home Mode

Door automation enabled.

Away Mode

Automatic door disabled.
9. Communication Protocols Used
I2C Communication

Used between:

ESP32 ↔ OLED Display

Pins:

SDA → GPIO21
SCL → GPIO22

Benefits:

Only two wires required.
Supports multiple I2C devices.
Faster communication.
Digital GPIO Communication

Used for:

PIR Sensor
RGB LED
Push Button
Buzzer
Stepper Driver
Analog Input

Used for:

MQ2
LDR
Flame Sensor
Rain Sensor

ESP32 ADC converts analog voltages into digital values.

Pulse-Based Communication

Used for:

Ultrasonic Sensor

Trigger pulse
Echo pulse

Distance calculated using Time-of-Flight principle.

Step Pulse Control

Used for the A4988 Stepper Driver.

The ESP32 generates STEP pulses to rotate the motor.

Bluetooth (Future Ready)

Bluetooth commands have already been implemented in the code structure (currently commented). This allows future expansion for wireless control of the door and home modes using a smartphone.

10. Concepts Applied from SMP Sessions

The following concepts learned during the SMP sessions were implemented:

ESP32 GPIO Programming
Sensor Interfacing
Digital Sensors
Analog Sensors
ADC Reading
I2C Communication
Pulse Generation
Embedded Decision Making
Threshold-Based Automation
Multi-Sensor Integration
Stepper Motor Control
Real-Time Monitoring
Embedded C Programming
Bluetooth Communication (framework included)
11. Results

The system successfully performs:

✔ Temperature monitoring

✔ Humidity monitoring

✔ Gas leakage detection

✔ Fire detection

✔ Motion detection

✔ Rain monitoring

✔ Visitor detection

✔ Automatic door control

✔ OLED live dashboard

✔ RGB status indication

✔ Audible alarm generation

✔ Home/Away mode switching

✔ Real-time Serial Monitor updates

12. Applications
Smart Homes
Home Security Systems
Industrial Safety
Gas Leakage Monitoring
Fire Detection Systems
Smart Buildings
IoT Automation
Laboratory Demonstrations
Embedded Systems Education
13. Advantages
Low cost
Real-time monitoring
Easy to expand
Modular design
Low power consumption
Multiple sensors integrated
Automatic safety response
Scalable IoT architecture
14. Limitations
Prototype developed in simulation.
No cloud dashboard currently implemented.
Bluetooth section is prepared but commented out.
Rain and flame sensors are simulated using potentiometers in Wokwi.
Fan is represented logically instead of using a physical DC motor.
15. Future Scope

Future improvements include:

MQTT cloud integration
Mobile application
Firebase database
Wi-Fi dashboard
Voice assistant integration
Camera-based security
AI-based anomaly detection
Push notifications
Smart energy analytics
Remote Bluetooth and Wi-Fi control
16. Conclusion

The ESP32-Based Smart Monitoring and Automated Control System successfully demonstrates the integration of multiple sensors and actuators into a single embedded IoT platform. The project performs continuous environmental monitoring, real-time decision-making, and automated responses for safety and convenience. It effectively applies concepts of sensor interfacing, communication protocols, embedded programming, and automation learned during the SMP sessions. The modular design allows easy future expansion with cloud connectivity, mobile applications, and advanced IoT features, making it a strong foundation for real-world smart home systems.
