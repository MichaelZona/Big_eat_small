#include "basicplayer.h"
#include "bits/stdc++.h"
using namespace std;
// Basic(int _x,int _y,int _tx,int _ty,int _wid,int _hei,ACL_Image *_img,rect _r);
// Basic(Basic &zt);
// virtual ~Basic();
// rect get_rect();
// virtual void movement(rect zt)=0;
// void drawplayer(int wid,int hei);
// void drawplayer();
Basic::Basic(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r){
    x=_x; y=_y; dx=_dx; dy=_dy; wid=_wid; hei=_hei;
    img=_img;
    r=_r;
}
Basic::Basic(Basic &zt){
    x=zt.x; y=zt.y; dx=zt.dx; dy=zt.dy; wid=zt.wid; hei=zt.hei;
    img=zt.img;
    r=zt.r;
}
Basic::Basic(){}
Basic::~Basic(){}
rect Basic::get_rect(){
    return (rect){x,y,wid,hei};
}
void Basic::drawplayer(int xx,int yy){
    putImageScale(img,xx,yy,wid,hei);
}
void Basic::drawplayer(){
    putImageScale(img,x,y,wid,hei);
}
