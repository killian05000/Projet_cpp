// MyWindow.hpp

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "Formes.hpp"

class MyWindow : public EZWindow {
    Formes formes;
    Forme  *pforme;
    bool souris;
    bool quadriActive;
    string imagePath;
    //bool colorChanging=false;
    int numColor=0;
    //bool flashActive=false;
    int dx, dy;

  public:
    MyWindow(int w, int h,const char *name);
    ~MyWindow();
    void timerNotify();
    void expose();
    void keyPress(EZKeySym keysym);
    void buttonPress(int mouse_x,int mouse_y,int button);
    void motionNotify(int mouse_x,int mouse_y,int button);
    void buttonRelease(int mouse_x,int mouse_y,int button);
    void quadrillage()const;
    void funcSouris(int mouse_x, int mouse_y, int button);
};

#endif
