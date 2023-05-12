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
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#define NUMPIXELS 14 // definimos la cantidad da leds del NEOPIXEL
#define NEO 14
#define BUZ 10

enum NeoColor { // Definir los colores posibles
  RED = 0xFF0000,
  GREEN = 0x00FF00,
  BLUE = 0x0000FF,
  YELLOW = 0xFFFF00,
  MAGENTA = 0xFF00FF,
  CYAN = 0x00FFFF,
  LIM = 0xFFF33
};

// Declaración de patrones
void ascendente();
void descendente();
void auto_fantastico();
void alternancia();
void grupal();

// Declaración de funciones
void colorespixel();

// Inicialización de objeto
Adafruit_NeoPixel pixels(NUMPIXELS, NEO, NEO_GRB + NEO_KHZ800);

// Inicialización de objeto
LiquidCrystal_I2C lcd_proyecto(0x27,16,2);

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
// Inicialización de objeto
Keypad keypad = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,FILAS,COLUMNAS);

// Variable global de color
uint32_t color = RED;

int a = 0;

void setup() {
  pixels.begin(); // Inicializa el Neopixel
  pixels.setBrightness(50); //Le establecemos intesidad al LED
  pixels.show(); // Inicializa todos los píxeles en apagado

}

void loop() {  
  char key = keypad.getKey();
  switch(key) {
      case '1':
        color =  RED;
        break;
      case '2':
        color = GREEN;
        break;
      case '3':
        color = BLUE;
        break;
      case '4':
        color = YELLOW;
        break;
      case '5':
        color = MAGENTA;
        break;
      case '6':
        color = CYAN;
        break;
      case '7':
        color = LIM;
        break;
      case 'A':
        ascendente();
        break;
      case 'B': 
        descendente();
        break;
      case 'C':
        alternancia();
        break;
  }
}


//Secuencias
void ascendente(){ 
    for(int i = 0; i<14; i++){
      pixels.setPixelColor(i,color);
      pixels.show();  //muestro el color en el led
      delay(200);
    } 
    for(int i = 0; i<14; i++){
      pixels.setPixelColor(i,pixels.Color(0,0,0));
      pixels.show();  //muestro el color en el led
    }
      delay(200);
}

void descendente(){
    for(int i = 14; i>=0; i--){
      pixels.setPixelColor(i,color);
      pixels.show();  //muestro el color en el led
      delay(200);
    } 
    
    for(int i = 14; i>=0; i--){
      pixels.setPixelColor(i,pixels.Color(0,0,0));
      pixels.show();  //muestro el color en el led
    } 
    delay(200);      
}

void alternancia(){
  //leds pares
  for(int i = 0; i<14; i=i+2){
    pixels.setPixelColor(i,color);
    pixels.show();  //muestro el color en el led
  } 
  delay(200);
  for(int i = 0; i<14; i++){
    pixels.setPixelColor(i,pixels.Color(0,0,0));
    pixels.show();  //muestro el color en el led
  }
  delay(200);
  
  //leds inpares
  for(int i = 1; i<14; i=i+2){
    pixels.setPixelColor(i,color);
    pixels.show();  //muestro el color en el led
  } 
  delay(200);
  for(int i = 0; i<14; i++){
    pixels.setPixelColor(i,pixels.Color(0,0,0));
    pixels.show();  //muestro el color en el led
  }
  delay(200); 
}
