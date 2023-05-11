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
#include <LiquidCrystal_I2C.h>
#define NUMPIXELS 14 // definimos la cantidad da leds del NEOPIXEL
#define NEO 2
#define BUZ 3

LiquidCrystal_I2C lcd_proyecto(0x27,16,2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO, NEO_GRB + NEO_KHZ800);

void nuestrasecuencia();
int pinespixels();
int cantidad;

void setup() {
  Serial.begin(9600);
  lcd_proyecto.init();  
  lcd_proyecto.backlight();
  pinMode(NEO, OUTPUT);
  pinMode(BUZ,OUTPUT);
}

void loop() {
  nuestrasecuencia();

}

void nuestrasecuencia(){
  cantidad = pinespixels();

  Serial.println(cantidad);
    
}

int pinespixels(){
  int npixel;
  
     for(int i =0; i<15; i++){ 
      npixel = i; 
   }

  return npixel;
}
