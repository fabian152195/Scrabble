#include <LiquidCrystal.h>
//Definimos los pines que vamos a usar  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int motor = 6;
int aceptar = 7;
char incomingByte = 0;   // for incoming serial data
int led = 13;
int boton1 = 16;
int boton2 = 15;
int bright;
bool algo;
String palabra;
void setup()
{
  Serial.begin(9600); 
  // opens serial port, sets data rate to 9600 bps
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  lcd.begin(16, 2);  //Inicializamos la pantalla
  lcd.setCursor(0, 0);  //Situamos el cursor
}

void loop()
{
    String estado;
   int indicador1 = analogRead(boton1);
    int indicador2 = analogRead(boton2);
    //Serial.println(indicador1);
    //Serial.println(indicador2);
    if(indicador1 > 500){
      Serial.println('1');
      Serial.println('.');
    }
    if(indicador2 > 500){
      Serial.println('2');
      Serial.println('.');
    }
    
  while(Serial.available() > 0){
  // send data only when you receive data:
  //if (Serial.available() > 0)
    //{
      // read the incoming byte:
       incomingByte = Serial.read();
       if(incomingByte != '.'){
        palabra += incomingByte;
        show(palabra);
       digitalWrite(led, algo);
       }else{
        show(palabra);
        palabra = "";
       }
    }
    
    //delay(150);
  }

  int show(String cont){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Verificando:");
  lcd.setCursor(0,1);
  lcd.print(cont);
  return 0;
  }
  int estado(String cont, bool validez){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(cont+":");
    lcd.setCursor(0,1);
    if(validez){
      lcd.print("ESTADO: ACEPTADA");
    }else{
      lcd.print("ESTADO: DENENGADA");;
    }
    return 0;
  }
  



    
    
