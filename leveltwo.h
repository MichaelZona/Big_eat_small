#ifndef leveltwo_h
#define leveltwo_h
#include "basicplayer.h"
class Leveltwo:public Basic{
    int sco;
    public:
        Leveltwo(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r,int _sco);
        Leveltwo(Leveltwo &zt);
        Leveltwo();
        ~Leveltwo();
        void movement(rect rr);
        bool whecrush(rect rr);
        int get_sco();
};
#endif