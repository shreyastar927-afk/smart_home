# 🏠 ESP32-Based IoT Multi-Sensor Smart Home Automation and Safety System

## Project Overview

This project is an ESP32-based IoT Smart Home Automation and Safety System that integrates multiple environmental and security sensors to automate household operations and improve safety. The system continuously monitors temperature, humidity, gas leakage, motion, light intensity, fire, rainfall, and visitor presence, and automatically controls various actuators based on predefined conditions.

The project demonstrates real-time sensor monitoring, embedded decision-making, actuator control, Bluetooth communication, and IoT system design using the ESP32.

---

# Objectives

- Develop a smart home automation system using the ESP32.
- Interface multiple sensors and actuators with a single microcontroller.
- Implement automatic decision-making based on sensor data.
- Display real-time system status on an OLED display and Serial Monitor.
- Demonstrate embedded systems concepts including communication protocols, sensor interfacing, and IoT integration.

---

# Features

### 🌡️ Smart Climate Control
- Monitors temperature and humidity using a DHT22 sensor.
- Automatically turns the fan ON when the temperature exceeds 25°C.
- Displays temperature, humidity, and fan status.

### 🛢️ Gas Leakage Detection
- Continuously monitors gas concentration using an MQ-2 sensor.
- Activates an alarm and LED when gas exceeds the safety threshold.

### 🚪 Automatic Smart Door
- Detects approaching objects using an IR obstacle sensor.
- Opens the door using a stepper motor.
- Automatically closes the door after a short delay.

### 💡 Intelligent Lighting Control
- Uses an LDR and PIR sensor.
- Turns lights ON only when motion is detected in low-light conditions.

### 🔒 Home Security
- Detects unauthorized movement using a PIR sensor.
- Activates alarms in Away Mode.

### 🔥 Fire Detection
- Detects flames using a flame sensor.
- Activates the buzzer and opens ventilation.

### 🌧️ Rain Detection
- Detects rainfall.
- Automatically closes the window to prevent water from entering.

### 🚶 Visitor Detection
- Uses an ultrasonic sensor to detect visitors.
- Displays a welcome message and turns on the entrance light.

### ⚡ Smart Energy Saving
- Automatically switches OFF appliances after prolonged inactivity.
- Helps reduce unnecessary power consumption.

### 📶 Bluetooth Connectivity
- Supports Bluetooth Serial communication for future wireless monitoring and control.

### 🖥️ OLED Dashboard
Displays:
- Temperature
- Humidity
- Gas Status
- Fan Status
- Door Status
- System Mode
- Alerts

---

# Hardware Components

| Component | Purpose |
|-----------|---------|
| ESP32 | Main Controller |
| DHT22 | Temperature & Humidity |
| MQ-2 Sensor | Gas Detection |
| PIR Sensor | Motion Detection |
| LDR | Light Detection |
| IR Obstacle Sensor | Automatic Door |
| Ultrasonic Sensor | Visitor Detection |
| Flame Sensor | Fire Detection |
| Rain Sensor | Rain Detection |
| Stepper Motor + A4988 | Door Automation |
| RGB LED | Status Indication |
| Buzzer | Alarm |
| OLED Display | Real-Time Display |

---

# System Workflow

1. ESP32 continuously reads data from all connected sensors.
2. Sensor values are compared against predefined thresholds.
3. Appropriate actions are automatically executed.
4. Current sensor readings and actuator status are displayed on the OLED display and Serial Monitor.
5. Bluetooth communication enables future wireless monitoring and control.

---

# Communication Protocols Used

- **I²C** – OLED Display Communication
- **Bluetooth Serial** – Wireless Communication
- **MQTT (Future Scope)** – Cloud-based IoT Monitoring

---

# Concepts Applied from SMP Sessions

### Sensor Interfacing

The project interfaces multiple environmental and safety sensors with the ESP32 to collect real-time data.

Sensors used:

- DHT22
- MQ-2
- PIR
- IR Obstacle Sensor
- LDR
- Flame Sensor
- Rain Sensor
- Ultrasonic Sensor

---

### Analog and Digital Inputs

**Analog Sensors**
- MQ-2 Gas Sensor
- LDR

**Digital Sensors**
- PIR
- IR Sensor
- Flame Sensor
- Rain Sensor
- Ultrasonic Sensor
- DHT22

---

### Embedded Decision Making

The ESP32 performs automatic decision-making based on sensor inputs.

Examples include:

- Temperature > 25°C → Fan ON
- Gas Detected → Alarm ON
- Motion + Darkness → Lights ON
- Object Detected → Door Opens
- Flame Detected → Alarm + Ventilation
- Rain Detected → Window Closes

---

### Actuator Control

The ESP32 controls:

- Stepper Motor
- RGB LED
- Buzzer
- Fan

---

### Real-Time Monitoring

The OLED display and Serial Monitor continuously display:

- Temperature
- Humidity
- Gas Value
- Door Status
- Fan Status
- Security Alerts
- System Mode

---

# Skills Demonstrated

- ESP32 Programming
- Embedded C / Arduino Framework
- Sensor Interfacing
- Actuator Control
- I²C Communication
- Bluetooth Communication
- Real-Time Data Acquisition
- Embedded Decision Making
- Smart Home Automation
- IoT System Design

---

# Future Enhancements

- MQTT Cloud Dashboard
- Mobile Application Integration
- Wi-Fi Remote Monitoring
- Push Notifications
- Voice Assistant Integration
- Data Logging and Analytics
- AI-Based Energy Optimization

---

## Developed Using

- ESP32
- Arduino Framework
- Wokwi Simulator
- Embedded C/C++

  ## Circuit diagram
  <img width="1086" height="750" alt="image" src="https://github.com/user-attachments/assets/fba29822-fff5-487f-8271-c89af9496311" />

  ## OLED Readings
  <img width="480" height="395" alt="image" src="https://github.com/user-attachments/assets/b901e477-0c9f-44e1-a978-e29a9380ce16" />


