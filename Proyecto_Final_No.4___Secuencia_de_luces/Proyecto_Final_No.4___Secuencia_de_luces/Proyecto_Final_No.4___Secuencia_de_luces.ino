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
#include <Keypad.h>
#define NUMPIXELS 15 // definimos la cantidad da leds del NEOPIXEL
#define NEO 14
#define BUZ 10

const byte FILAS = 4;
const byte COLUMNAS = 4;

char keys[FILAS][COLUMNAS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {9,8,7,6};
byte pinesColumnas[COLUMNAS] = {5,4,3,2};

Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,FILAS,COLUMNAS);
LiquidCrystal_I2C lcd_proyecto(0x27,16,2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO, NEO_GRB + NEO_KHZ800);

void secuenciasluces();
void nuestrasecuencia();
int colorespixels();
int i; //colores a utilizar
char tecla;


void setup() {
  Serial.begin(9600);
  pixels.clear(); // Apaga todos los NeoPixels
  lcd_proyecto.init();  
  lcd_proyecto.backlight();
  pinMode(NEO, OUTPUT);
  pinMode(BUZ,OUTPUT);
}

void loop() {
  tecla = teclado.getKey();
  secuenciasluces();
  colorespixels();
}

void secuenciasluces(){
  if(tecla == 'A'){
    nuestrasecuencia();
  }
}
  

void nuestrasecuencia(){ // funcionde la quinta secuencia 
  int color = colorespixels();
  Serial.println(tecla);
    for(i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i,color);
      pixels.show();
    }  
    delay(500);
    for(i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i,0,0,0);
      pixels.show();  
    }
    delay(500);    
    for(i = NUMPIXELS; i > 0; i++){
      pixels.setPixelColor(i,color);
      pixels.show();
    }
  
}
