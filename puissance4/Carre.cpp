#include <Gamebuino-Meta.h>
#include "Carre.h"
Carre::Carre(int x,int y,int heigh,int widthe){
        this->color = gb.createColor(255,255,255);
        this->x = x;
        this->y = y;
        this->heigh = heigh;
        this->widthe = widthe;
        this->y = y;
        this->heigh = heigh;
        this->widthe = widthe;
        this->positions = false;
}
 int Carre::getHeigh(){
  return this->heigh;
 }
 int Carre::getWidthe(){
  return this->widthe;
 }

bool Carre::getPositions(){
      return this->positions;
    }
void Carre::setPositions(bool pos){
      this->positions = pos;
    }
Color Carre::getColors(){
  return this->color;
}
void Carre::setColors(Color color){
  this->color = color;
}
int Carre::getX(){
  return this->x;
}


void left(){
  
}

void Carre::setX(int x){
  this->x = x;
}

int Carre::getY(){
  return this->y;
}

void Carre::setY(int y){
  this->y = y;
}

void Carre::draw(){
  
  gb.display.setColor(this->color);
  gb.display.drawRect(this->x, this->y, this->heigh, this->widthe);
}
