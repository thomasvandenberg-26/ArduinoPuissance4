Quadrillage::Quadrillage(int x,int y){
  const int tailleCase = 7 ;
   // Calculer la position X du coin supérieur gauche du plateau pour le centrer horizontalement
  int plateauX = x;
  // Calculer la position Y du coin supérieur gauche du plateau pour le positionner vers le bas de l'écran
  int plateauY = y;// Mettons une marge de 10 pixels en bas
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      int caseX = plateauX  + j * tailleCase; // Position X de la case sur l'écran
      int caseY = plateauY  + i * tailleCase; // Position Y de la case sur l'écran
      plateau[i][j] = new carre(caseX, caseY, tailleCase, tailleCase);
    }
  }
}

bool Quadrillage::checkGagne(){
  bool bol = false;
  for(int i=0;i<6;i++){
    for(int j=0;j<4;j++){
      if(plateau[i][j]->getColors()==plateau[i][j+1]->getColors() && plateau[i][j]->getColors()==plateau[i][j+2]->getColors() && plateau[i][j]->getColors()==plateau[i][j+3]->getColors()){
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

void Quadrillage::findCarre(carre *Carre,Color color){
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      if(gb.collide.rectRect(Carre->getX(),Carre->getY(),Carre->getHeigh(),Carre->getWidthe(),plateau[i][j]->getX(),plateau[i][j]->getY(),plateau[i][j]->getHeigh(),plateau[i][j]->getWidthe())){
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
