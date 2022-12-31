#ifndef basicplayer_h
#define basicplayer_h
#include "acllib.h"
class Basic{
    protected:
        int x,y,dx,dy; // 当前位置，以及前进的动量
        int wid,hei; // 图片的长度和宽度
        ACL_Image *img; // 当前图片
        rect r;
    public:
        Basic(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r);
        Basic(Basic &zt);
        Basic();
        virtual ~Basic();
        rect get_rect();
        // virtual void movement(rect zt)=0;
        void drawplayer(int wid,int hei);
        void drawplayer();
};
#endif
