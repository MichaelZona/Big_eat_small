#ifndef levelone_h
#define levelone_h
#include "basicplayer.h"
class Levelone: public Basic{
    int sco;
    public:
    Levelone(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r,int _sco);
    Levelone(Levelone &zt);
    Levelone();
    ~Levelone();
    void movement();
    int get_sco();
};
#endif