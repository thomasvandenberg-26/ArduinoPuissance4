#ifndef CARRE_H
#define CARRE_H


#include <Gamebuino-Meta.h> 
class carre{
  private:
    int x;
    int y;
    int heigh;
    int widthe;
    bool positions;
    Color color;
  public:
    carre(int x,int y,int heigh,int widthe);
    void setColors(Color color);
    bool getPositions();

    void setPositions(bool pos);
    
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void draw();
    int getHeigh();
    int getWidthe();
    Color getColors();
    
};
