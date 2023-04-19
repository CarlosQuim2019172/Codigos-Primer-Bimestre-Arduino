#include <Keypad.h>

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

char tecla;
int i , dtime = 2000;
int coso = 0;
void setup() {
  Serial.begin(9600);
  for(i=10;i<=17;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  tecla = teclado.getKey();
  
  if(tecla == 0){
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(14,HIGH);
    digitalWrite(15,HIGH);
    digitalWrite(16,HIGH);
    digitalWrite(17,LOW);
  }
   
  if(tecla){
      Serial.println(tecla);    
  switch(tecla){
    
    case('0'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,LOW);
      delay(dtime);
      break;
      
    case('1'):
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,LOW);
      digitalWrite(15,LOW);
      digitalWrite(16,LOW);
      digitalWrite(17,LOW);
      delay(dtime);
      break;
      
    case('2'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,LOW);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('3'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,LOW);
      digitalWrite(16,LOW);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('4'):
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,LOW);
      digitalWrite(15,LOW);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('5'):
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,LOW);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('6'):
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('7'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,LOW);
      digitalWrite(15,LOW);
      digitalWrite(16,LOW);
      digitalWrite(17,LOW);
      delay(dtime);
      break;
      
    case('8'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;

    case('9'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,LOW);
      digitalWrite(15,LOW);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('A'):
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,LOW);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('B'):
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
      
    case('C'):
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,LOW);
      delay(dtime);
      break;
      
    case('D'):
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,LOW);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;

    case('#'):
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(14,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;

    case('*'):
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(14,LOW);
      digitalWrite(15,HIGH);
      digitalWrite(16,HIGH);
      digitalWrite(17,HIGH);
      delay(dtime);
      break;
  }   
  }
}
