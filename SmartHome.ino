#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
 //#include "BluetoothSerial.h"


// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// Bluetooth
//BluetoothSerial SerialBT;


// RGB
#define RED_PIN 16
#define GREEN_PIN 33
#define BLUE_PIN 32


// Buzzer
#define BUZZER_PIN 23


// Stepper
#define STEP_PIN 26
#define DIR_PIN 27
#define EN_PIN 25


// Sensors

#define DHT_PIN 4
#define DHTTYPE DHT22

DHT dht(DHT_PIN,DHTTYPE);


#define MQ2_PIN 35
#define LDR_PIN 34
#define PIR_PIN 18
#define FLAME_PIN 13
#define RAIN_PIN 15


// Ultrasonic
#define TRIG_PIN 17
#define ECHO_PIN 5


// Button
#define BUTTON_PIN 14



bool homeMode = true;


// DHT object



void stepMotor(int steps)
{
  for(int i=0;i<steps;i++)
  {
    digitalWrite(STEP_PIN,HIGH);
    delayMicroseconds(700);

    digitalWrite(STEP_PIN,LOW);
    delayMicroseconds(700);
  }
}



void setRGB(bool r,bool g,bool b)
{
  digitalWrite(RED_PIN,r);
  digitalWrite(GREEN_PIN,g);
  digitalWrite(BLUE_PIN,b);
}



long getDistance()
{

digitalWrite(TRIG_PIN,LOW);
delayMicroseconds(2);

digitalWrite(TRIG_PIN,HIGH);
delayMicroseconds(10);

digitalWrite(TRIG_PIN,LOW);


long duration=pulseIn(ECHO_PIN,HIGH);

return duration*0.034/2;

}



void oledPrint(String line1,String line2)
{

display.clearDisplay();

display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);

display.setCursor(0,0);
display.println(line1);

display.println(line2);

display.display();

}



void setup()
{

Serial.begin(115200);


// Bluetooth name
//SerialBT.begin("ESP32_SmartHome");



pinMode(RED_PIN,OUTPUT);
pinMode(GREEN_PIN,OUTPUT);
pinMode(BLUE_PIN,OUTPUT);


pinMode(BUZZER_PIN,OUTPUT);


pinMode(STEP_PIN,OUTPUT);
pinMode(DIR_PIN,OUTPUT);
pinMode(EN_PIN,OUTPUT);


digitalWrite(EN_PIN,LOW);



pinMode(PIR_PIN,INPUT);
pinMode(FLAME_PIN,INPUT);

pinMode(TRIG_PIN,OUTPUT);
pinMode(ECHO_PIN,INPUT);


pinMode(BUTTON_PIN,INPUT_PULLUP);



Wire.begin(21,22);


display.begin(SSD1306_SWITCHCAPVCC,0x3C);


dht.begin();



oledPrint("SMART HOME","Bluetooth Ready");


delay(2000);

}



void loop()
{


// Bluetooth commands

//if(SerialBT.available())
//{

//char command=SerialBT.read();


//if(command=='O')
//{
//oledPrint("Manual","Door Opening");

//digitalWrite(DIR_PIN,HIGH);
//stepMotor(200);
//}


//if(command=='C')
//{
//oledPrint("Manual","Door Closing");

//digitalWrite(DIR_PIN,LOW);
//stepMotor(200);
//}


//if(command=='A')
//{
//homeMode=false;
//}


//if(command=='H')
//{
//homeMode=true;
//}


//}




// Read sensors


float temperature=dht.readTemperature();
float humidity=dht.readHumidity();


int light=analogRead(LDR_PIN);

int gas=analogRead(MQ2_PIN);

int rain=analogRead(RAIN_PIN);


int motion=digitalRead(PIR_PIN);

int flame = analogRead(FLAME_PIN);



long distance=getDistance();
// =================== SERIAL MONITOR ===================

Serial.println("--------------------------------------");

Serial.print("Mode: ");
Serial.println(homeMode ? "HOME" : "AWAY");

Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" C");

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");

Serial.print("Gas Value: ");
Serial.println(gas);

Serial.print("Light Value: ");
Serial.println(light);

Serial.print("Rain Value: ");
Serial.println(rain);

Serial.print("Flame Value: ");
Serial.println(flame);

Serial.print("Motion: ");
Serial.println(motion ? "DETECTED" : "NONE");

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

Serial.print("Door: ");
if(distance < 20 && homeMode)
  Serial.println("OPEN");
else
  Serial.println("CLOSED");

Serial.print("Fan: ");
if(temperature > 25)
  Serial.println("ON");
else
  Serial.println("OFF");

Serial.print("Gas Alert: ");
if(gas > 2000)
  Serial.println("YES");
else
  Serial.println("NO");

Serial.print("Fire Alert: ");
if(flame > 2000)
  Serial.println("YES");
else
  Serial.println("NO");

Serial.println("--------------------------------------");

// =======================================================



// Button mode change

if(digitalRead(BUTTON_PIN)==LOW)
{
homeMode=!homeMode;

delay(500);
}



// OLED status


display.clearDisplay();

display.setCursor(0,0);

display.setTextSize(1);


display.println("SMART HOME");

display.print("Mode:");
if(homeMode)
display.println("HOME");
else
display.println("AWAY");


display.print("Temp:");
display.print(temperature);
display.println(" C");


display.print("Hum:");
display.print(humidity);
display.println("%");


display.print("Light:");
display.println(light);



display.print("Dist:");
display.print(distance);
display.println("cm");





display.display();



// Security logic


if(flame>2000)
{

setRGB(HIGH,LOW,LOW);

tone(BUZZER_PIN,2000);

//SerialBT.println("WARNING FIRE");

}



else if(gas>2000)
{

setRGB(HIGH,LOW,LOW);

tone(BUZZER_PIN,1500);

//SerialBT.println("GAS ALERT");

}



else if(motion)
{

setRGB(HIGH,HIGH,LOW);

tone(BUZZER_PIN,1000);

//SerialBT.println("Motion detected");

}



else if(rain>2000)
{

setRGB(LOW,LOW,HIGH);

}



else
{

setRGB(LOW,HIGH,LOW);

noTone(BUZZER_PIN);

}




// Automatic door

if(distance<20 && homeMode)
{

oledPrint("Object Near","Opening Door");


digitalWrite(DIR_PIN,HIGH);

stepMotor(200);


delay(3000);


digitalWrite(DIR_PIN,LOW);

stepMotor(200);

}



delay(500);

}
