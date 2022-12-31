#ifndef Shark_h
#define Shark_h
#include "basicplayer.h"

class Shark: public Basic{
    public:
        Shark(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r);
        Shark();
        ~Shark();
        void movement();
        bool crush(rect r);
};
#endif