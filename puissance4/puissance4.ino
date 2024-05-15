#include <Gamebuino-Meta.h>
#include "Carre.h"
#include "Quadrillage.h"

const int lignes = 6;
const int colonnes = 7;
int plateau[lignes][colonnes]; 
int colonneSelectionnee = 0;
const int tailleCase = 7 ;



Carre *carre;
Quadrillage *quadri;
int plateauX;
int plateauY;
int GameOver = false;
Color color = gb.createColor(255,0,0);
void setup() {
  gb.begin();
  plateauX = (gb.display.width() - (colonnes * tailleCase)) / 2;
  plateauY = gb.display.height() - (lignes * tailleCase) - 10; 
  carre = new Carre(0,0,2,2);
  quadri = new Quadrillage(plateauX,plateauY);
}

void loop() {
  // Attendre la prochaine mise à jour du Gamebuino
  while(!gb.update());
  gb.display.clear();
  if(GameOver!=true){
    carre->setColors(color);
    quadri->drawQuadrillage();
     int carreX = plateauX + colonneSelectionnee * 7 + 7 / 2;
      int carreY = plateauY - 10;
     carre->setX(carreX);
     carre->setY(carreY);
     carre->draw();
     // Gérer la navigation entre les colonnes
    if (gb.buttons.released(BUTTON_LEFT)) {
      colonneSelectionnee = max(colonneSelectionnee - 1, 0); // Ne pas dépasser la première colonne
    }
    if (gb.buttons.released(BUTTON_RIGHT)) {
      colonneSelectionnee = min(colonneSelectionnee + 1, colonnes - 1); // Ne pas dépasser la dernière colonne
    }
    if(gb.buttons.released(BUTTON_A)){
      for(int i=0;i<6;i++){
        if(quadri->findCarre(i,colonneSelectionnee)!=true){
          carre->setY(carre->getY()  + 8);
          carre->draw();
        }
        else{
          //Carre->setY(Carre->getY()  - 8);
          carre->draw();
          break;
        }
      }
      quadri->findCarre(carre,color);
      if(color==gb.createColor(0,255,0)){
        color= gb.createColor(255,0,0);
      }else{
        color=gb.createColor(0,255,0);
      }
      if(quadri->checkGagneHorizon()==true){
        GameOver = true;
      }
      if(quadri->checkGagneVertical()==true){
        GameOver = true;
      }
    }
  }
  else{
    gb.display.print("GAME OVER");
    if(gb.buttons.released(BUTTON_B)){
      quadri->removeQuadrillage(plateauX,plateauY);
       GameOver = false;
    }
  }
}
