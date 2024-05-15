class Quadrillage{
  private:
    carre *plateau[6][7];
  public:
    quadrillage(int x,int y);
    void drawQuadrillage();
    void findCarre(carre *Carre,Color color);
    bool findCarre(int i,int j);
    bool checkGagne();
    
};
