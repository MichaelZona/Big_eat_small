#include "bits/stdc++.h"
#include "shark.h"
using namespace std;
// Shark(int _x,int _y,int _dx,int _dy,int wid,int hei,ACL_Image *_img,rect _r);
// Shark();
// ~Shark();
// void movement();
// bool crush(rect r);
Shark::Shark(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r):
Basic(_x,_y,_dx,_dy,_wid,_hei,_img,_r){}
Shark::Shark(){}
Shark::~Shark(){}
void Shark::movement(){
    int i,j;
    if (x+dx<0 || x+dx+wid>r.width) dx=-dx;
    if (y+dy<0 || y+dy+hei>r.y+r.height) dy=-dy;
    x+=dx,y+=dy;
}
bool Shark::crush(rect rr){
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
