#include <Gamebuino-Meta.h>
#include "Carre.h"
#include "Quadrillage.h"
Quadrillage::Quadrillage(int x,int y){
 this->iniQuadrillage(x,y);
}
void Quadrillage::iniQuadrillage(int x,int y){
  const int tailleCase = 7 ;
   // Calculer la position X du coin supérieur gauche du plateau pour le centrer horizontalement
  int plateauX = x;
  // Calculer la position Y du coin supérieur gauche du plateau pour le positionner vers le bas de l'écran
  int plateauY = y;// Mettons une marge de 10 pixels en bas
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      int caseX = plateauX  + j * tailleCase; // Position X de la case sur l'écran
      int caseY = plateauY  + i * tailleCase; // Position Y de la case sur l'écran
      plateau[i][j] = new Carre(caseX, caseY, tailleCase, tailleCase);
    }
  }
   plateau[0][0]->setColors(gb.createColor(0,255,0));
}
void Quadrillage::removeQuadrillage(int x,int y){
  this->iniQuadrillage(x,y);
}

bool Quadrillage::checkGagneHorizon(){
  bool bol = false;
  for(int i=0;i<6;i++){
    for(int j=0;j<4;j++){
      if(plateau[i][j]->getColors()==plateau[i][j+1]->getColors()&& plateau[i][j]->getColors()==plateau[i][j+2]->getColors() &&   plateau[i][j]->getColors()==plateau[i][j+3]->getColors()
      && plateau[i][j]->getPositions()==true && plateau[i][j+1]->getPositions()==true && plateau[i][j+2]->getPositions()==true && plateau[i][j+3]->getPositions()==true
      ){
        bol = true;
      }
    }
  }
  return bol;
}

bool Quadrillage::checkGagneDiago(){
 bool bol = false;
  for(int i=5;i>=4;i--){
    for(int j=6;j>=4;j--){
      gb.display.println((String)plateau[i][j]->getColors());
      gb.display.println((String)plateau[i-1][j-1]->getColors());
      gb.display.println((String)plateau[i-2][j-2]->getColors());
      gb.display.println((String)plateau[i-3][j-3]->getColors());
      if(plateau[i][j]->getColors()==plateau[i-1][j-1]->getColors()&& plateau[i][j]->getColors()==plateau[i-2][j-2]->getColors() &&   plateau[i][j]->getColors()==plateau[i-3][j-3]->getColors()
      && plateau[i][j]->getPositions()==true && plateau[i-1][j-1]->getPositions()==true && plateau[i-2][j-2]->getPositions()==true && plateau[i-3][j-3]->getPositions()==true
      ){
        bol = true;
      }
    }
  }
  return bol;
}
bool Quadrillage::checkGagneVertical(){
  bool bol = false;
  for(int i=0;i<4;i++){
    for(int j=0;j<3;j++){
      if(plateau[j][i]->getColors()==plateau[j+1][i]->getColors()&& plateau[j][i]->getColors()==plateau[j+2][i]->getColors() &&   plateau[j][i]->getColors()==plateau[j+3][i]->getColors()
      && plateau[j][i]->getPositions()==true && plateau[j+1][i]->getPositions()==true && plateau[j+2][i]->getPositions()==true && plateau[j+3][i]->getPositions()==true
      ){
        bol = true;
      }
    }
  }
  return bol;
}

bool Quadrillage::findCarre(int i,int j){
 bool bol = false;
 if(plateau[i][j]->getPositions()==true){
  bol = true;
 }
 return bol;
}

void Quadrillage::findCarre(Carre *carre,Color color){
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      if(gb.collide.rectRect(carre->getX(),carre->getY(),carre->getHeigh(),carre->getWidthe(),plateau[i][j]->getX(),plateau[i][j]->getY(),plateau[i][j]->getHeigh(),plateau[i][j]->getWidthe())){
        plateau[i][j]->setPositions(true);
        plateau[i][j]->setColors(color);
      }
    }
  }
}
void Quadrillage::drawQuadrillage(){
   for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++){
      this->plateau[i][j]->draw();
    }
   }
}
