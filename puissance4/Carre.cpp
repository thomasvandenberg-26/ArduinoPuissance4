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

/* Méthodes Get/Setter des paramétres  carré */
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
