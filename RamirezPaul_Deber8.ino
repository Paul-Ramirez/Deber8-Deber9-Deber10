/*
 * Deber #8
 * Autor: Ramirez Paul
 * Objetivo: Realizar un código que el sistema se reinicia cada minuto, active el conversor 
 *           análogo-digital realice una lectura y vuelve el sistema a un modo sleep.
 */

#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <MsTimer2.h>

int on;//variable para interrupcion
int tiempo=0;//tiempo de funcionamiento
int cont=0;//contador de reloj


void setup() {
  Serial.begin(9600);//inicializa la comunicacion serial
  MsTimer2::set(1000,reloj);//inicializa el timer a 1 seg
  attachInterrupt(0,activacion,LOW);//interrupcion para modos

}

void loop() {
  Serial.println(analogRead(0));
  delay(1000);
  

}

void activacion(){
  switch(on){
    case 0://inicio del sistema mediante interrupcion
    Serial.println("Inicio del Sistema");
    power_adc_disable();//deshabilita los ADC
    tiempo=60;//tiempo de reinicio del sistema 1min
    on++;//incremento de variable de interrupcion
    break;
    case 1://segundo caso de la interrupcion, sistema a funcinoar
    Serial.println(String("Sistema Funciona en: ")+String(tiempo)+String(" seg"));
    MsTimer2::start();//se inicia el timer a contar el tiempo 
    on++;
    break;
    case 2://fin del sistema 
    Serial.println("Fin del Sistema");
    //reinicio de variables
    tiempo=0;
    on=0;
    MsTimer2::stop();//parar el timer
    power_adc_disable();//deshabilita el ADC
    break;
  }

}

void reloj(){
  cont++;
  Serial.println(String("Lectura en:")+String(tiempo-cont));
  if(tiempo==cont){//compara el tiempo de reinicio
    power_adc_enable();//activa el conversor
    delay(10);
    Serial.println(analogRead(0));//realiza lectura del ADC
    cont=0;
  }
}
