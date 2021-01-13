/*
 * Deber #9
 * Autor: Ramirez Paul
 * Objetivo: Realice un programa que mediante un conversor análogo-digital se configure el tiempo 
 * de reinicio del perro guardián (tiempos seleccionados por el usuario). Envíe mensajes por 
 * comunicación serial validando todo el proceso.
 */
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <MsTimer2.h>

int on;
int tiempo=0;
int cont=0;
int dato;
int i=0;

void setup() {
  Serial.begin(9600);//inicializa comunicacion serial
  MsTimer2::set(1000,reloj);//inicializa timer a 1seg
  attachInterrupt(0,activacion,LOW);//interrupcion0
}

void loop() {
  if(on==1){
    dato=analogRead(0);
    tiempo=map(dato,0,1023,0,60);//cambio de escala
    Serial.println(String("El sistema se reinicia en: ")+String(tiempo)+String(" seg"));
    delay(1000);
  }

}

void activacion(){
  switch(on){
    case 0:
    Serial.println("Inicio del Sistema");
    Serial.println("Configure el tiempo de reinicio: ");
    on++;
    break;
    case 1:
    Serial.println(String("Sistema se reinicia en: ")+String(tiempo)+String(" seg"));
    MsTimer2::start();
    on++;
    break;
    case2:
    Serial.println("Fin del Sistema");
    on=0;
    tiempo=0;
    wdt_disable();
    cont=0;
    break;
  }
}

void reloj(){
  cont++;
  Serial.println(cont);
  if(tiempo==cont){
    Serial.println("Reinicio del sistema");
    wdt_disable();//deshabilida perro guardian
    wdt_enable(WDTO_2S);//habilita perro guardian
  }
}
