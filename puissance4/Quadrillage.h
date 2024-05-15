class Quadrillage{
  private:
    Carre *plateau[6][7];
     void iniQuadrillage(int x,int y);
  public:
    Quadrillage(int x,int y);
    void drawQuadrillage();
    void findCarre(Carre *carre,Color color);
    bool findCarre(int i,int j);
    bool checkGagneVertical();
    bool checkGagneHorizon();
    void removeQuadrillage(int x,int y);
    bool checkGagneDiagoLeft();
    //bool checkGagne();
    
};
