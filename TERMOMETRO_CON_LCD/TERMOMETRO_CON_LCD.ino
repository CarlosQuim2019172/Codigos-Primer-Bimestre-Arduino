#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define LEDR 5 
#define LEDB 4 
#define LEDA 3 

LiquidCrystal_I2C lcd_quim(0x27,16,2);
OneWire ourWire(2);
DallasTemperature sensor(&ourWire);

float sensortF();
float sensortC();
void medicion();

float TempF, TempC;

void setup() {
  Serial.begin(9600);   //Inicio la comunicacion serial
  lcd_quim.init();  
  lcd_quim.backlight();
  sensor.begin();   //Se inicia el sensor
  pinMode(LEDR,OUTPUT);
  pinMode(LEDA,OUTPUT);
  pinMode(LEDB,OUTPUT);
}

void loop() {
  medicion();
}

float sensortC(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}

float sensortF(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp1 = sensor.getTempFByIndex(0); //Se obtiene la temperatura en ºF
  return temp1;
}

void medicion(){
  TempF = sensortF();
  TempC = sensortC();

  if(TempC > 15 && TempC < 30){
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDA,HIGH);
  }
  
  //Temperatura en Celsius
  lcd_quim.setCursor(0,0);
  lcd_quim.print("Temp = ");
  lcd_quim.setCursor(7,0);
  lcd_quim.print(TempC);
  lcd_quim.setCursor(13,0);
  lcd_quim.print((char)223);
  lcd_quim.setCursor(14,0);
  lcd_quim.print("C");

  //Temperatura en Fahrenheit
  lcd_quim.setCursor(0,1);
  lcd_quim.print("Temp = ");
  lcd_quim.setCursor(7,1);
  lcd_quim.print(TempF);
  lcd_quim.setCursor(13,1);
  lcd_quim.print((char)223);
  lcd_quim.setCursor(14,1);
  lcd_quim.print("F");  

  if(TempC > 30){
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
  }

  if(TempC < 15){
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
  }

}
