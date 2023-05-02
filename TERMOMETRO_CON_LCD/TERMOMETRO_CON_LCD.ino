/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Carlos Alexander Quim Chapaz
Carné: 2019172 
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define LEDR 5 
#define LEDB 4 
#define LEDA 3 

LiquidCrystal_I2C lcd_quim(0x27,16,2);
OneWire ourWire(2);
DallasTemperature sensor(&ourWire);

int sensortF();
int sensortC();
void medicion();

int TempF, TempC;

byte termometro[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

byte caliente[] = {
  B00000,
  B00100,
  B00110,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110
};

byte frio[] = {
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000
};

byte templado[] = {
  B11011,
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000
};

byte grados[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  Serial.begin(9600);   //Inicio la comunicacion serial
  lcd_quim.init();  
  lcd_quim.backlight();
  sensor.begin();   //Se inicia el sensor
  lcd_quim.createChar(0, termometro);
  lcd_quim.createChar(1, caliente);
  lcd_quim.createChar(2, frio); 
  lcd_quim.createChar(3, templado);
  lcd_quim.createChar(4, grados); 
  lcd_quim.home();
  pinMode(LEDR,OUTPUT);
  pinMode(LEDA,OUTPUT);
  pinMode(LEDB,OUTPUT);
}

void loop() {
  medicion();
}

int sensortC(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  int temp= sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}

int sensortF(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  int temp1 = sensor.getTempFByIndex(0); //Se obtiene la temperatura en ºF
  return temp1;
}

void medicion(){
  TempF = sensortF();
  TempC = sensortC();
  
  
  lcd_quim.setCursor(0,0);
  lcd_quim.print("  TERMOMETRO ");
  lcd_quim.write(byte(0));
  //Temperatura en Celsius
  lcd_quim.setCursor(2,1);
  lcd_quim.print(TempC);
  lcd_quim.write(byte(4));
  lcd_quim.print("C");
  //Temperatura en Fahrenheit
  lcd_quim.setCursor(8,1);
  lcd_quim.print(TempF);
  lcd_quim.write(byte(4));
  lcd_quim.print("F "); 


  if(TempC >= 15 && TempC <= 30){
    lcd_quim.setCursor(13,1);
    lcd_quim.write(byte(3));
    delay(800);
    lcd_quim.setCursor(13,1);
    lcd_quim.print(" ");
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDA,HIGH);
  }

  if(TempC > 30){
    lcd_quim.setCursor(13,1);
    lcd_quim.write(byte(1));
    delay(800);
    lcd_quim.setCursor(13,1);
    lcd_quim.print(" ");
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
  }

  if(TempC < 15){
    lcd_quim.setCursor(13,1);
    lcd_quim.write(byte(2));
    delay(800);
    lcd_quim.setCursor(13,1);
    lcd_quim.print(" ");
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
  }

}
