// Aba reservada para definição de Servos, Ultrassônicos, Leds, Botões e Buzzer
#ifndef Basico
#define Basico

#include <Arduino.h>
#include <Servo.h>    

class Led {   
  private:
    byte pinLed1 = 0;  
    byte pinLed2 = 0;  
    byte pinLed3 = 0;  

  public:

    void ligarLeds(byte s1, byte s2, byte s3) {
      pinLed1 = s1;
      pinLed2 = s2;
      pinLed3 = s3;


      pinMode(pinLed1, OUTPUT); 
      pinMode(pinLed2, OUTPUT); 
      pinMode(pinLed3, OUTPUT); 
      
    }
    void ligarLed1() {
      digitalWrite(pinLed1, HIGH); 
    }
    void desligarLed1() {
      digitalWrite(pinLed1, LOW);
    }

    void piscarLed1(int intervalo) {
      digitalWrite(pinLed1, HIGH);
      delay(intervalo);
      digitalWrite(pinLed1, LOW);
      delay(intervalo);
    }

    void ligarLed2() {
      digitalWrite(pinLed2, HIGH); 
    }
    void desligarLed2() {
      digitalWrite(pinLed2, LOW);
    }
    void piscarLed2(int intervalo){
      digitalWrite(pinLed2, HIGH);
      delay(intervalo);
      digitalWrite(pinLed2,LOW);
      delay(intervalo);
    }
    void ligarLed3() {
      digitalWrite(pinLed3, HIGH); 
    }
    void desligarLed3(){
      digitalWrite(pinLed3,LOW);
    }
    void piscarLed3(int intervalo){
      digitalWrite(pinLed3,HIGH);
      delay(intervalo);
      digitalWrite(pinLed3,LOW);
      delay(intervalo);
    }

};

class Ultrassonico { 
  private:

    byte pinoTrigger = 0; 
    byte pinoEcho = 0; 

  public:

    void ligarUltrassonico(byte trig, byte echo) { 
      pinoTrigger = trig;
      pinoEcho = echo;

      pinMode(pinoTrigger, OUTPUT); 
      pinMode(pinoEcho, INPUT); 
    }

    long calculoUltrassonico() { 
      long duration, distance;
      digitalWrite(pinoTrigger, LOW);  
      delayMicroseconds(2);            
      digitalWrite(pinoTrigger, HIGH); 
      delayMicroseconds(10);           
      digitalWrite(pinoTrigger, LOW);  
      duration = pulseIn(pinoEcho, HIGH);
      distance = duration * 340 / (2 * 10000); 
      return distance;
    }

    void leituraUltrassonico() {        
      int US1 = calculoUltrassonico();
      Serial.print(" U 1: \t");         
      Serial.println(US1, DEC);         
    }
};

class Servos {  
  private:
    Servo Servo1;  
    Servo Servo2;
    int pos = 0;   
  public:
    void ligarServos(byte pinServo1, byte pinServo2) {  
      Servo1.attach(pinServo1);  
      Servo1.write(90);          
      Servo2.attach(pinServo2);  
      Servo2.write(90);          
    }

    void movimentarServo(int pos) {
      Servo1.write(0);              
      delay(150);                    
      Servo1.write(pos);             
    }
    void movimentarServo2(int pos) {
      Servo1.write(0);               
      delay(150);                   
      Servo2.write(pos);            
    }

};

class Botoes {  
  private:
    byte pinBotao1 = 0;   
    byte pinBotao2 = 0;   
  public:
    void ligarBotoes(byte s1, byte s2) {  
      pinBotao1 = s1;
      pinBotao2 = s2;
      pinMode(pinBotao1, INPUT);  
      pinMode(pinBotao2, INPUT);
    }
    void botaoApertado1 (int porta) {  

      bool leituraBotao1 = digitalRead(pinBotao1);   

      if (leituraBotao1 == true) {   
        digitalWrite(porta, HIGH);   
        delay(100);                  
        leituraBotao1 = !leituraBotao1;  
      }
      if (leituraBotao1 == false) {  
        digitalWrite(porta, LOW);  
        delay(100);                
        leituraBotao1 = !leituraBotao1;  
      }
    }
    void botaoApertado2 (int porta) {  
      bool leituraBotao2 = digitalRead(pinBotao2);   

      if (leituraBotao2 == true) {   
        digitalWrite(porta, HIGH);   
        delay(100);                  
        leituraBotao2 = !leituraBotao2;    
      }
      if (leituraBotao2 == false) {  
        digitalWrite(porta, LOW);  
        delay(100);                
        leituraBotao2 = !leituraBotao2;  
      }
    }
};
class Buzzer {  
  private:
    byte pinBuzzer1 = 0;  
    byte pinBuzzer2 = 0;  
    int tomBuzzer1 = 0;   
    int tomBuzzer2 = 0;   
  public:
    void ligarBuzzer(byte s1, byte s2) { 
      pinBuzzer1 = s1;
      pinBuzzer2 = s2;

      pinMode(pinBuzzer1, OUTPUT);  
      pinMode(pinBuzzer2, OUTPUT);

    }

    void tocarBuzzer(int tom1, int intervalo) { 
      tone(pinBuzzer1, tom1); 
      digitalWrite(pinBuzzer1, HIGH); 
      delay(intervalo);  
      digitalWrite(pinBuzzer1, LOW);  
      delay(intervalo); 
    }
    void tocarBuzzer2(int tom2, int intervalo) { 
      tone(pinBuzzer2, tom2); 
      digitalWrite(pinBuzzer2, HIGH); 
      delay(intervalo);       
      digitalWrite(pinBuzzer2, LOW);  
      delay(intervalo);       
    }
};
#endif // Basico
