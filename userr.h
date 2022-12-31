#ifndef Userr_h
#define Userr_h
#include "basicplayer.h"
class Userr: public Basic{
    int sco;
    public:
        Userr(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r);
        Userr(Userr &zt);
        Userr();
        virtual ~Userr();
        // void movement(rect zt);
        void movement(int set);
        bool crush(rect rr);
        int get_sco();
        void set_sco(int zt);
        void add_sco(int zt);
};
#endif