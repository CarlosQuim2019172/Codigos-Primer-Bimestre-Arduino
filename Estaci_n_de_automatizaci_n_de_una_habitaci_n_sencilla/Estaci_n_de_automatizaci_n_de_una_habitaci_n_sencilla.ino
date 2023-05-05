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
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define NUMPIXELS 7 // definimos la cantidad da leds del NEOPIXEL
#define RADAR 14
#define PUSH3 13
#define PUSH2 12
#define PUSH1 11
#define BUZ 9
#define LEDR 7 
#define LEDB 5
#define LEDG 6 
#define NEO 4
#define RELE2 3
#define RELE1 2

Servo myservo;
LiquidCrystal_I2C lcd_quim(0x27,16,2);
OneWire ourWire(8);
DallasTemperature sensor(&ourWire);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO, NEO_GRB + NEO_KHZ800);

void pines();
int sensortC();
void temperatura();
void radar();
void puerta();
void luminarias();
void pantallainicial();

int TempC, value = 0, value1 = 0, value2 = 0;

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

byte abajo[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B10001
};

byte arriba[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};

byte apagado[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110,
  B00000
};

byte encendido[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B00000
};

void setup() {
  Serial.begin(9600);
  lcd_quim.init();  
  lcd_quim.backlight();
  sensor.begin();   //Se inicia el sensor
  pixels.begin();
  myservo.attach(10);
  lcd_quim.createChar(0, caliente);
  lcd_quim.createChar(1, frio); 
  lcd_quim.createChar(2, templado);
  lcd_quim.createChar(3, abajo);
  lcd_quim.createChar(4, arriba);
  lcd_quim.createChar(5, apagado);
  lcd_quim.createChar(6, encendido);
  lcd_quim.home();
  myservo.write(0);
  pines();
  pantallainicial();
}

void loop() {
  temperatura();
  radar();
  puerta();
  luminarias();
}

void pines(){
  pinMode(LEDR,OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(LEDB,OUTPUT);
  pinMode(RELE1,OUTPUT);
  pinMode(RELE2,OUTPUT);
  pinMode(BUZ,OUTPUT);
  pinMode(RADAR,INPUT);
  pinMode(PUSH1,INPUT);
  pinMode(PUSH2,INPUT);
  pinMode(PUSH3,INPUT);
  digitalWrite(RELE1,HIGH);
  digitalWrite(RELE2,HIGH);
}

int sensortC(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  int temp= sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}


void temperatura(){
  TempC = sensortC();
  Serial.println(TempC);
 
  if(TempC >= 21 && TempC <= 25){
    digitalWrite(LEDR,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDB,LOW);    
    lcd_quim.setCursor(5,0);
    lcd_quim.write(byte(2));
  }

  if(TempC >= 15 && TempC <= 20){
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDB,HIGH);    
    lcd_quim.setCursor(5,0);
    lcd_quim.write(byte(1));
  }

  if(TempC >= 26 && TempC <= 45){
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDB,LOW);
    lcd_quim.setCursor(5,0);
    lcd_quim.write(byte(0));
  }
}

void radar(){
  int estado = digitalRead(RADAR);
 
   // personas con brazos abajo
   lcd_quim.setCursor(6,1);
   lcd_quim.write(byte(3));
   for(int i =0; i<8; i++){
      pixels.setPixelColor(i,pixels.Color(0,0,255));
      pixels.show();  
   }
 
  if(estado == HIGH){
    // personas con brazos abajo
    lcd_quim.setCursor(6,1);
    lcd_quim.write(byte(3));
    for(int i =0; i<8; i++){
      pixels.setPixelColor(i,pixels.Color(0,0,255));
      pixels.show();  
    }
    delay(300);
    // personas con brazos arriba
    lcd_quim.setCursor(6,1);
    lcd_quim.write(byte(4));
    for(int i =0; i<8; i++){
      pixels.setPixelColor(i,pixels.Color(255,0,0));
      pixels.show();  
    }
    delay(300);
    tone(BUZ,200);
    delay(100);
    noTone(BUZ);
  }
}

void puerta(){

  if(digitalRead(PUSH3) && value == 0){
    lcd_quim.setCursor(10,1);
    lcd_quim.print("OPEN ");
    myservo.write(90); 
    delay(500);
    value = 1; 
  }
  
  if(digitalRead(PUSH3) && value == 1){
    lcd_quim.setCursor(10,1);
    lcd_quim.print("CLOSE");
    myservo.write(0); 
    delay(500); 
    value = 0;                                                       
  }
}

void luminarias(){  
  if(digitalRead(PUSH1) && value1 == 0){
    digitalWrite(RELE1,LOW);
    lcd_quim.setCursor(10,0);
    lcd_quim.write(byte(6));
    delay(500); 
    value1 = 1;
  }
  
  if(digitalRead(PUSH1) && value1 == 1){
    digitalWrite(RELE1,HIGH);
    lcd_quim.setCursor(10,0);
    lcd_quim.write(byte(5));
    delay(500); 
    value1 = 0;
  }

  if(digitalRead(PUSH2) && value2 == 0){
    digitalWrite(RELE2,LOW);
    lcd_quim.setCursor(15,0);
    lcd_quim.write(byte(6));
    delay(500); 
    value2 = 1;
  }
  
  if(digitalRead(PUSH2) && value2 == 1){
    digitalWrite(RELE2,HIGH);
    lcd_quim.setCursor(15,0);
    lcd_quim.write(byte(5));
    delay(500); 
    value2 = 0;
  }                                
}

void pantallainicial(){
  // Temperatura
  lcd_quim.setCursor(0,0);
  lcd_quim.print("TEMP: ");

  // Luminarias
  lcd_quim.setCursor(7,0);
  lcd_quim.print("L1:");
  lcd_quim.setCursor(10,0);
  lcd_quim.write(byte(5));
  lcd_quim.setCursor(12,0);
  lcd_quim.print("L2:");
  lcd_quim.setCursor(15,0);
  lcd_quim.write(byte(5));
  
  // Radar
  lcd_quim.setCursor(0,1);
  lcd_quim.print("RADAR: ");
    
  // Puerta 
  lcd_quim.setCursor(8,1);
  lcd_quim.print("P:");
  lcd_quim.setCursor(10,1);
  lcd_quim.print("CLOSE");
}
