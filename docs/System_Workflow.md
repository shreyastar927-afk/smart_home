# System Workflow

1. ESP32 initializes all sensors and communication peripherals.

2. Temperature and humidity are read using the DHT22 sensor.

3. Gas concentration is monitored using the MQ2 sensor.

4. Motion, light intensity, fire, rainfall, and visitor presence are continuously monitored.

5. Sensor values are compared with predefined thresholds.

6. Based on the decision logic:
   - Fan is switched ON/OFF.
   - Door opens automatically.
   - RGB LED indicates system status.
   - Alarm buzzer is activated during emergencies.

7. The OLED display is updated with the latest sensor readings.

8. Bluetooth transmits system information for future mobile monitoring.

9. The process repeats continuously in real time.
