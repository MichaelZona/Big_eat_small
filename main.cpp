#include "bits/stdc++.h"
#include "acllib.h"
#include "userr.h"
#include "levelone.h"
#include "leveltwo.h"
#include "shark.h"
using namespace std;
const int MAX=105;
const int N=800;
const int M=600;
ACL_Image img,imgUsr,imgHeart,bg,grass,longgrass,sharkk;
rect winRect;
Levelone monst1[MAX];
Leveltwo monst2[MAX];
Shark srk;
Userr user;
int userwid,userhei,monwid,monhei;
int cnt1,cnt2;
bool flag;
bool ck1[MAX],ck2[MAX],cku,ckend,ckwin;
int clk;
int eat1,eat2;
void init(){
    int i,j;
    memset(ck1,true,sizeof(ck1));
    memset(ck2,true,sizeof(ck2));
    eat1=eat2=cnt1=cnt2=clk=0;flag=true;ckend=cku=false;
    ckwin=false;
    userwid=userhei=monwid=monhei=100;
    winRect.x=winRect.y=DEFAULT;
	winRect.width=N;winRect.height=M;
    loadImage("xia.bmp",&img);
	loadImage("fish.bmp",&imgUsr);
	loadImage("wuzei.bmp",&imgHeart);
    loadImage("ocean.bmp",&bg);
    loadImage("grass.bmp",&grass);
    loadImage("longgrass.bmp",&longgrass);
    loadImage("shark.bmp",&sharkk);
}
void creatdata1(){
    int i,j;
    int x,y,dx,dy;
    x=rand()%N*rand()%N*rand()%N+1-monwid;
    x=x<0?x+monwid:x;
    y=rand()%M*rand()%M*rand()%M+1-monhei;
    y=y<0?y+monhei:y;
    dx=dy=1;
    monst1[++cnt1]=Levelone(x,y,dx,dy,monwid,monhei,&img,winRect,3);
}
void creatdata3(){
    int i,j;
    int x,y,dx,dy;
    x=rand()%N*rand()%N*rand()%N+1-monwid;
    x=x<0?x+monwid:x;
    y=rand()%M*rand()%M*rand()%M+1-monhei;
    y=y<0?y+monhei:y;
    dx=dy=3;
    monst2[++cnt2]=Leveltwo(x,y,dx,dy,monwid,monhei,&imgHeart,winRect,5);
}
void creatdata2(){
    int i,j;
    int x,y,dx,dy;
    x=rand()%N*rand()%N*rand()%N+1-userwid;
    x=x<0?x+userwid:x;
    y=rand()%M*rand()%M*rand()%M+1-userhei;
    y=y<0?y+userhei:y;
    dx=dy=5;
    user=Userr(x,y,dx,dy,userwid,userhei,&imgUsr,winRect);
    cku=true;
}
void creatshark(){
    int i,j;
    int x,y,dx,dy;
    x=rand()%N*rand()%N*rand()%N+1-userwid;
    x=x<0?x+userwid:x;
    y=rand()%M*rand()%M*rand()%M+1-userhei;
    y=y<0?y+userhei:y;
    dx=dy=5;
    srk=Shark(x,y,dx,dy,userwid,userhei,&sharkk,winRect);
}
void paint(){
    int i,j;
	char score[10],happy_new_year1[100]="Have fun 2023!",happy_new_year2[100]="Best wishes!";
    beginPaint();
    clearDevice();
    // putImageScale(&bg,0,0,N,M);
    putImageScale(&grass,0,450,150,170);
    putImageScale(&longgrass,650,300,150,300);
    // putImageScale(&sharkk,0,0,100,100);
    srk.drawplayer();
        for (i=1;i<=cnt1;i++)
            if (ck1[i])
                monst1[i].drawplayer();
        for (i=1;i<=cnt2;i++)
            if (ck2[i])
                monst2[i].drawplayer();
    if (cku)
        user.drawplayer();
	sprintf(score, "%d", user.get_sco());
	setTextSize(20);
    char zt[100]="Scores:";
	paintText(10,10,zt);
    paintText(100,10,score);
    setTextSize(25);
    paintText(300,15,happy_new_year1);
    paintText(316,40,happy_new_year2);
    if (ckend){
        char los[MAX]="Try again!";
        setTextSize(40);
        paintText(300,200,los);
    }
    if (ckwin){
        char win[MAX]="Congratulations!";
        setTextSize(40);
        paintText(270,200,win);
    }
    endPaint();
}
void keyEvent(int key, int event){
    int i,j;
	if (event != KEY_DOWN)return;
    if (ckend || ckwin) goto away;
	if(cku)user.movement(key);
    for (i=1;i<=cnt1;i++)
        if (ck1[i])
            if (user.crush(monst1[i].get_rect())){
                int s = monst1[i].get_sco();
                if (cku)user.add_sco(s);
                ck1[i]=false;
                eat1++;
            }
    for (i=1;i<=cnt2;i++)
        if (ck2[i])
            if (user.crush(monst2[i].get_rect())){
                int s = monst2[i].get_sco();
                if (cku)user.add_sco(s);
                ck2[i]=false;
                eat2++;
            }
    if (srk.crush(user.get_rect())){
        cku=false;
        ckend=true;
    }
	away:paint();
}
void timerEvent(int id){
	int i,j;
    clk++;
    if (clk%2==0 || ckend || ckwin) return;
	switch (id){
        case 0:
            for (i=1;i<=cnt1;i++)
                if (ck1[i])
                    monst1[i].movement();
            for (i=1;i<=cnt2;i++)
                if (ck2[i]){
                    rect zt=user.get_rect();
                    monst2[i].movement(zt); 
                }
            break;
        case 1:
            if (cnt2<25 && clk%5==0)
                creatdata3();
            if (cnt1<25)
                creatdata1();
            break;
	}
    if (cnt2>=25 && cnt2>=25 && eat1==cnt1 && eat2==cnt2) ckwin=true;
    srk.movement();
	paint();
}
int Setup(){
    init();
	initWindow("Goodbye 2022 !", DEFAULT, DEFAULT, N, M);
	srand((unsigned)time(NULL));
	creatdata2();
    creatshark();
	registerTimerEvent(timerEvent);
	registerKeyboardEvent(keyEvent);
	startTimer(0,40);
	startTimer(1,1000);
	return 0;
}