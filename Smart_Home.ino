#include <SoftwareSerial.h> //Librarey for serial connection with ESP

SoftwareSerial ESP(3,4); //ESP is connected to 3 and 4 pin of Arduino

String sendData = "https://api.thingspeak.com/update?api_key=TAGTKD3FITWTN6V4&field1=0";
String output = ""; //Initialize a null string variable
#define Relay1 6

void setup()
{
  pinMode(Relay1, OUTPUT);
  delay(2000);

  Serial.begin (9600);
  delay(100);
}

void loop() {

  String cmd = "AT+CIPSTART=\"TCP\",\"";   // Establishing TCP connection// AT+CIPSTART=4,"TCP","google.com",80
  cmd += "184.106.153.149";   //  api.thingspeak.com
  cmd += "\",80";   // port 80

  char incoming_value = output[126];
  Serial.print("incoming_value is : ");
  Serial.println(incoming_value);
  if (incoming_value == '1') //light should be off
  {

    digitalWrite(Relay1, LOW);
  }
  if (incoming_value == '0') //light should be on
  {

    digitalWrite(Relay1, HIGH);
  }
}
