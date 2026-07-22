# System Flowchart

```
START
   │
Initialize ESP32
   │
Initialize Sensors
   │
Read All Sensor Values
   │
Temperature > 25°C ?
   │
 ├── Yes → Fan ON
 └── No → Fan OFF
   │
Gas Detected?
   │
 ├── Yes → Alarm
 └── No
   │
Object Detected?
   │
 ├── Yes → Open Door
 └── No
   │
Motion + Dark?
   │
 ├── Yes → Lights ON
 └── No
   │
Fire?
   │
 ├── Yes → Alarm
 └── No
   │
Rain?
   │
 ├── Yes → Close Window
 └── No
   │
Visitor?
   │
 ├── Yes → Welcome Message
 └── No
   │
Update OLED
   │
Send Bluetooth Data
   │
Repeat Forever
```
