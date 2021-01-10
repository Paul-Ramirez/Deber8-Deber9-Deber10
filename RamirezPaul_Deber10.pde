/*
*Deber #10
*Autor: Paul Ramirez
*Objetivo: Realizar una interfaz que permita mover una esfera por toda la pantalla mediante teclas.
*/
int y1=650/2;//posicion y de la esfera
int x1=450;//posicion x de la esfera

void setup(){
  size(900,700);
  background(#8E8181);
}

void draw(){
  background(#8E8181);//fondo
  stroke(0,0,0);//contorno
  strokeWeight(5);//grosor contorno
  fill(255, 233, 0);//fondo esfera
  ellipse(x1,y1,100,100);//esfera, posicion, tamañp
  if(keyPressed){//evento del teclado 
  //Movimiento hacia arriba
    if(keyCode==UP || key=='w'){
      if(y1>0){
        y1=y1-5;
      }
    }
    //Movimiento hacia abajo
    if(keyCode==DOWN || key=='s'){
      if(y1<700){
        y1+=5; 
      }
    }
    //Movimiento hacia la izquierda
    if(keyCode==LEFT || key=='a'){
      if(x1>0){
        x1=x1-5;
      }
    }
    //Movimiento hacia la derecha
    if(keyCode==RIGHT || key=='d'){
      if(x1<900){
        x1+=5;
      }
    }
  }  
}
