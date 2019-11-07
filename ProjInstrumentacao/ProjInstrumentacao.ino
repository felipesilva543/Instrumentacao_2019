//#include <idDHT11.h>
#include <LiquidCrystal.h>
#include <TimerOne.h>
#include <Servo.h>
#include "DHT.h"

//VARIÁVEIS SENSOR DE PRESENÇA
volatile bool auxSenPre = false; // Ativa o bloco de comandos quando encontra identifica uma presença

// VARIÁVEIS SERVO MOTOR
int pos;        // Posição Servo

// Variáveis sensor DHT11
int lero = 0; // Teste
float h = 0;  // Umidade
float t = 0;  // Temperatura

/*######## DEFINES ########*/
#define pinSenPre    3        // Porta Digital onde o Sinal do Sensor de presença esta conectado
#define SERVO        9        // Porta Digital onde o Sinal do servo esta conectado
#define DHTPIN       A1       // PORTA ANALÓGICA QUE CONECTA O SENSOR DHT11
#define DHTTYPE      DHT11    // DHT 11
                                         // Intanciação do Objeto Servo Motor
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);                        // Define os pinos que serão utilizados para ligação ao display
DHT dht(DHTPIN, DHTTYPE);
Servo servo;                                                  // Intanciação do Objeto Servo Motor

void msgDisplay (){
  Serial.println("Interruption ON!");
    lcd.clear();
    //Posiciona o cursor na coluna, linha;
    lcd.setCursor(0, 0);
    //Envia o texto entre aspas para o LCD
    lcd.print("Temp: " + String(t) + " *C");
    //Posiciona o cursor na coluna, linha;
    lcd.setCursor(0, 1);
    //Envia o texto entre aspas para o LCD
    lcd.print("Umid: " + String(h) + " " + String(lero));
}

/*################################# INTERRUPÇÃO SENSOR PRESENÇA #################################*/
void interruptionPresSensor(){
    auxSenPre = true;     // MUDA A FLAG PARA ATIVAR A SEQUENCIA DEPOIS DE IDETIFICAR A PRESENÇA
    lero++;
    Serial.println("Interrupão Pres: " + String(lero));
}

void ligarVentoinha(int indoVindo){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
  if(indoVindo = 0){
    servo.write(pos-5);  
  }else if(indoVindo = 1){
    servo.write(pos+5);
  }
  
  auxSenPre = false;
}


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Init LCD
  dht.begin();      // Init DHT11
  servo.attach(SERVO); // Init Servo
  pinMode(LED_BUILTIN, OUTPUT);

  //Timer1.initialize(10000000);   //TIMER IRA EXECUTAR A CADA 1 SEGUNDO (PARAMETRO EM MICROSEGUNDOS)
  //Timer1.attachInterrupt(msgDisplay);


// INTERRUPÇÃO SENSOR DE PRESENÇA
  pinMode(pinSenPre, INPUT_PULLUP);  
  attachInterrupt(digitalPinToInterrupt(pinSenPre), interruptionPresSensor, RISING);

  
} // End Setup

void loop() {
/*Leitura sensor Temperatura e Umidade.*/
//  float auxH = dht.readHumidity();
//  float auxT = dht.readTemperature();
//  if (isnan(auxT) || isnan(auxH)){
//    Serial.println("Failed");
//  } else{  
//    Serial.println("T: " + String(auxT));
//    Serial.println("U: " + String(auxH));
//    t = auxT;
//    h = auxH;
//  }
/*End Leitura sensor Temperatura e Umidade.*/

/*Controle Servo Motor.*/

//for(pos = 0; pos < 180; pos+=5){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
//  servo.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
//  delay(15); //INTERVALO DE 15 MILISSEGUNDOS
//  if(auxSenPre){
//    ligarVentoinha(0);
//  }
//}
//delay(1000); //INTERVALO DE 1 SEGUNDO
//for(pos = 180; pos >= 0; pos-=5){ //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
//  servo.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
//  delay(15); //INTERVALO DE 15 MILISSEGUNDOS
//  if(auxSenPre){
//    ligarVentoinha(1);
//  }
//}

servo.write(90);

//for(pos = 0; pos < 180; pos++){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
//  servo.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
//  delay(15); //INTERVALO DE 15 MILISSEGUNDOS
//}
//delay(1000); //INTERVALO DE 1 SEGUNDO
//for(pos = 180; pos >= 0; pos--){ //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
//  servo.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
//  delay(15); //INTERVALO DE 15 MILISSEGUNDOS
//}
  

  
/*End Controle Servo Motor.*/
  
}
