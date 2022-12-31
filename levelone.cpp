#include "bits/stdc++.h"
#include "levelone.h"
using namespace std;
// Levelone(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r,int _sco);
// Levelone(Levelone &zt);
// ~Levelone();
// void movement(rect r);
// int get_sco();
Levelone::Levelone(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r,int _sco):
Basic(_x,_y,_dx,_dy,_wid,_hei,_img,_r){
    sco=_sco;
}
Levelone::Levelone(Levelone &zt):Basic(zt){
    sco=zt.sco;
}
Levelone::Levelone(){
    sco=0;
}
Levelone::~Levelone(){}
void Levelone::movement(){
    int i,j;
    if (x+dx<0 || x+dx+wid>r.width) dx=-dx;
    if (y+dy<0 || y+dy+hei>r.y+r.height) dy=-dy;
    x+=dx,y+=dy;
}
int Levelone::get_sco(){
    return sco;
}
