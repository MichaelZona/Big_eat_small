#include "bits/stdc++.h"
#include "leveltwo.h"
using namespace std;
// Leveltwo(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r,int _sco);
// Leveltwo(Leveltwo &zt);
// ~Leveltwo();
// void movement();
// bool whecrush(rect rr);
// int get_sco();
Leveltwo::Leveltwo(int _x,int _y,int _dx,int _dy,int _wid,int _hei,ACL_Image *_img,rect _r,int _sco):
Basic(_x,_y,_dx,_dy,_wid,_hei,_img,_r){
    sco=_sco;
}
Leveltwo::Leveltwo(Leveltwo &zt):Basic(zt){
    sco=zt.sco;
}
Leveltwo::Leveltwo(){}
Leveltwo::~Leveltwo(){}
void Leveltwo::movement(rect rr){
    int i,j;
    if (!whecrush(rr)){
        if (x+dx<0 || x+dx+wid>r.width) dx=-dx;
        if (y+dy<0 || y+dy+hei>r.height) dy=-dy;
        x+=dx,y+=dy;
    }
    else{
        dx=x<rr.x?-abs(dx):abs(dx); dy=y<rr.y?-abs(dy):abs(dy);
        if (x+dx<0 || x+dx+wid>r.width) dx=-dx;
        if (y+dy<0 || y+dy+hei>r.height) dy=-dy;
        x+=dx*2,y+=dy*2;
    }
}
bool Leveltwo::whecrush(rect rr){
    int i,j;
    // int tx,ty,tdx,tdy,ztx,zty;
    // ztx=x,zty=y,tdx=dx,tdy=dy;
    // for (i=1;i<=5;i++){
    //     if (ztx+tdx<0 || tx+tdx+wid>r.width)  tdx=-tdx;
    //     if (zty+tdy<0 || ty+tdy+hei>r.height) tdy=-tdy;
    //     ztx+=tdx,zty+=tdy;
    //     tx=ztx,ty=zty;
    //     if (tx>rr.x && ty>rr.y && tx<rr.x+rr.width && ty<rr.x+rr.height) return true;
    //     tx=ztx+wid,ty=zty;
    //     if (tx>rr.x && ty>rr.y && tx<rr.x+rr.width && ty<rr.x+rr.height) return true;
    //     tx=ztx,ty=zty+hei;
    //     if (tx>rr.x && ty>rr.y && tx<rr.x+rr.width && ty<rr.x+rr.height) return true;
    //     tx=ztx+wid,ty=zty+hei;
    //     if (tx>rr.x && ty>rr.y && tx<rr.x+rr.width && ty<rr.x+rr.height) return true;
    // }
    // return false;
    double dist=sqrt((double)(x-rr.x)*(double)(x-rr.x)+(double)(y-rr.y)*(double)(y-rr.y));
    if (dist<200) return true;
    else return false;
}
int Leveltwo::get_sco(){
    return sco;
}
