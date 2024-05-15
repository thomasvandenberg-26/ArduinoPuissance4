#include <Gamebuino-Meta.h>

const int lignes = 6;
const int colonnes = 7;
int plateau[lignes][colonnes]; 
int colonneSelectionnee = 0;
const int tailleCase = 7 ;

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
carre::carre(int x,int y,int heigh,int widthe){
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
 int carre::getHeigh(){
  return this->heigh;
 }
 int carre::getWidthe(){
  return this->widthe;
 }

bool carre::getPositions(){
      return this->positions;
    }
void carre::setPositions(bool pos){
      this->positions = pos;
    }
Color carre::getColors(){
  return this->color;
}
void carre::setColors(Color color){
  this->color = color;
}
int carre::getX(){
  return this->x;
}


void left(){
  
}

void carre::setX(int x){
  this->x = x;
}

int carre::getY(){
  return this->y;
}

void carre::setY(int y){
  this->y = y;
}

void carre::draw(){
  
  gb.display.setColor(this->color);
  gb.display.drawRect(this->x, this->y, this->heigh, this->widthe);
}

class cadriage{
  private:
    carre *plateau[6][7];
  public:
    cadriage(int x,int y);
    void drawCadriage();
    void findCarre(carre *Carre,Color color);
    bool findCarre(int i,int j);
    bool checkGagne();
    
};

cadriage::cadriage(int x,int y){
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

bool cadriage::checkGagne(){
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

bool cadriage::findCarre(int i,int j){
 bool bol = false;
 if(plateau[i][j]->getPositions()==true){
  bol = true;
 }
 return bol;
}

void cadriage::findCarre(carre *Carre,Color color){
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      if(gb.collide.rectRect(Carre->getX(),Carre->getY(),Carre->getHeigh(),Carre->getWidthe(),plateau[i][j]->getX(),plateau[i][j]->getY(),plateau[i][j]->getHeigh(),plateau[i][j]->getWidthe())){
        plateau[i][j]->setPositions(true);
        plateau[i][j]->setColors(color);
      }
    }
  }
}
void cadriage::drawCadriage(){
   for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++){
      this->plateau[i][j]->draw();
    }
   }
}

carre *Carre;
cadriage *cadri;
int plateauX;
int plateauY;
Color color = gb.createColor(255,0,0);
void setup() {
  gb.begin();
  plateauX = (gb.display.width() - (colonnes * tailleCase)) / 2;
  plateauY = gb.display.height() - (lignes * tailleCase) - 10; 
  Carre = new carre(0,0,2,2);
  cadri = new cadriage(plateauX,plateauY);
}

void loop() {
  // Attendre la prochaine mise à jour du Gamebuino
  while(!gb.update());
  gb.display.clear();
  Carre->setColors(color);
  cadri->drawCadriage();
   int carreX = plateauX + colonneSelectionnee * 7 + 7 / 2;
    int carreY = plateauY - 10;
   Carre->setX(carreX);
   Carre->setY(carreY);
   Carre->draw();
   // Gérer la navigation entre les colonnes
  if (gb.buttons.released(BUTTON_LEFT)) {
    colonneSelectionnee = max(colonneSelectionnee - 1, 0); // Ne pas dépasser la première colonne
  }
  if (gb.buttons.released(BUTTON_RIGHT)) {
    colonneSelectionnee = min(colonneSelectionnee + 1, colonnes - 1); // Ne pas dépasser la dernière colonne
  }
  if(gb.buttons.released(BUTTON_A)){
    for(int i=0;i<6;i++){
      if(cadri->findCarre(i,colonneSelectionnee)!=true){
        Carre->setY(Carre->getY()  + 8);
        Carre->draw();
      }
      else{
        //Carre->setY(Carre->getY()  - 8);
        Carre->draw();
        break;
      }
    }
    cadri->findCarre(Carre,color);
    if(color==gb.createColor(0,255,0)){
      color= gb.createColor(255,0,0);
    }else{
      color=gb.createColor(0,255,0);
    }
    if(cadri->checkGagne()==true){
      gb.display.clear();
    }
  }
   
}

