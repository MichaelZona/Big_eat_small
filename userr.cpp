#include "userr.h"
#include "bits/stdc++.h"
using namespace std;
// Userr(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r);
// Userr(Userr &zt);
// virtual ~Userr();
// void movement(rect zt);
// void movement(int set);
// bool crush(rect rr);
// int get_sco();
// void setsco(int s);
// void add_sco(int s);

Userr::Userr(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r):Basic(_x,_y,_dx,_dy,_wid,_hei,_img,_r){
    // x=_x; y=_y; dx=_dx; dy=_dy; wid=_wid; hei=_hei;
    // img=_img;
    // r=_r;
    sco=0;
}
Userr::Userr(Userr &zt):Basic(zt){
    // x=zt.x; y=zt.y; tx=zt.tx; ty=zt.ty; wid=zt.wid; hei=zt.hei;
    // img=zt.img;
    // r=zt.r;
}
Userr::Userr(){}
Userr::~Userr(){}
void Userr::movement(int set){ // 按上下位置移动
    int i,j;
    if (set==VK_DOWN){
        y+=dy;
        if (y+hei>r.height) y=r.height-hei;
    }
    if (set==VK_UP){
        y-=dy;
        if (y<0) y=0;
    }
    if (set==VK_LEFT){
        x-=dx;
        if (x<0) x=0;
    }
    if (set==VK_RIGHT){
        x+=dx;
        if (x+wid>r.width) x=r.width-wid;
    }
}
bool Userr::crush(rect rr){
    int i,j,tx,ty;
    tx=x,ty=y;
    if (tx>=rr.x && ty>=rr.y && tx<=rr.x+rr.width && ty<=rr.y+rr.height) return true;
    tx=x+wid,ty=y;
    if (tx>=rr.x && ty>=rr.y && tx<=rr.x+rr.width && ty<=rr.y+rr.height) return true;
    tx=x,ty=y+hei;
    if (tx>=rr.x && ty>=rr.y && tx<=rr.x+rr.width && ty<=rr.y+rr.height) return true;
    tx=x+wid,ty=y+hei;
    if (tx>=rr.x && ty>=rr.y && tx<=rr.x+rr.width && ty<=rr.y+rr.height) return true;
    return false;
}
int Userr::get_sco(){
    return sco;
}
void Userr::set_sco(int zt){
    sco=zt;
}
void Userr::add_sco(int zt){
    sco+=zt;
}