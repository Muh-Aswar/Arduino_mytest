#include <SoftwareSerial.h>// impor library softwareserial

SoftwareSerial BlueSer(10, 11); // RX, TX
int led=13; 
int BluetoothData;

void setup() {
BlueSer.begin(9600);
BlueSer.println("Bluetooth ready, tekan 1 or 0 utk on/off LED");
pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.println("\nde bluetooth Connected tuaip ....");
}

void loop() {
  
if (BlueSer.available()){
  BluetoothData=BlueSer.read();
  
  if(BluetoothData=='1'){ 
    digitalWrite(led,HIGH);
    BlueSer.println("LED onnnn");
    Serial.print("\n ON");
    Serial.println(BluetoothData);
  }
  if (BluetoothData=='0'){
    digitalWrite(led,LOW);
    BlueSer.println("LED off");
    Serial.print("\n OFF");
    Serial.println(BluetoothData);
  }
}

delay(100);
}