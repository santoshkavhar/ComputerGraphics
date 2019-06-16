#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Pend
{
	float a, i;	///iterations and angle
	
	float rx1, ry1, ry2, rx2;	///rectangle
	
	float xc, yc;	///centre and radius
	
	float x1,y1,x2,y2,nx1,nx2,ny1,ny2;
	
	float sx1, sy1, sx2, sy2, snx, sny;
	float mx1, my1, mx2, my2, mnx, mny;
	float hx1, hy1, hx2, hy2, hnx, hny;
	
	float ox, oy;
	
	int k, kh, km;

public:
	Pend();
	
	void draw(int,int,int);
	void casing();
	
	void pendulum();
	void longer();
	
	void sec_hand();
	void min_hand();
	void hour_hand();


};

Pend::Pend()
{
	xc= getmaxx()/2;
	yc= getmaxy()/2-80;
	
	rx1= xc -150;
	ry1= yc - 150;
	rx2= xc + 150;
	ry2= yc + 300;

	ox= xc;
	oy= yc;
	
	x1= xc;
	y1= yc + 126;
	x2= xc;
	y2= yc + 250;
	
	
	sx1= xc;
	sy1= yc;
	sx2= xc;
	sy2= yc - 100;
	snx= xc;
	sny= yc - 100;
	
	mx1= xc;
	my1= yc;
	mx2= xc;
	my2= yc - 80;
	mnx= xc;
	mny= yc - 80;
	
	hx1= xc;
	hy1= yc;
	hx2= xc;
	hy2= yc - 60;
	hnx= xc;
	hny= yc - 60;
	
	k=km=kh=0;
	
}


void Pend::draw(int h, int m, int s)
{
k= s;
km= m;
kh = h;
	casing();
	while(1)
	{
	pendulum();
	}

}

void Pend::casing()
{	
	setcolor(10);
	
	ellipse(ox, oy ,180, 360,150 , 150);
	ellipse(ox, oy ,180, 360,151 , 151);
	ellipse(ox, oy ,180, 360,152 , 152);
	ellipse(ox, oy ,180, 360,153 , 153);
	ellipse(ox, oy ,180, 360,154 , 154);
	ellipse(ox, oy ,0, 180,150 , 300);
	ellipse(ox, oy ,0, 180,151 , 301);
	ellipse(ox, oy ,0, 180,152 , 302);
	ellipse(ox, oy ,0, 180,153 , 303);
	ellipse(ox, oy ,0, 180,154 , 304);
	
	
	setcolor(6);
	circle(xc,yc,120);
	circle(xc,yc,121);
	circle(xc,yc,122);
	circle(xc,yc,123);
	circle(xc,yc,124);
	
	//setfontstyle(1);
	
	outtextxy(xc-115, yc-3, "9");
	outtextxy(xc-5, yc-117, "12");
	outtextxy(xc+112, yc-3, "3");
	outtextxy(xc-3, yc+110, "6");
	
	outtextxy(xc-50, yc+ 265, "SMART CLOCK");


}

void Pend::pendulum()
{
	for(i=-12; i<=12; i++)
	{
		longer();
		if(i==12)
		{
			k++;
			sec_hand();
			
			if(k%60==0)
				km++;
				
			min_hand();
				
			if(k%3600==0)
				kh++;
				
			hour_hand();
		
		}
	}
	
	for(i=12; i>=-12; i--)
	{
		longer();
		if(i==-12)
		{
			k++;
			sec_hand();
			
			if(k%60==0)
				km++;
			min_hand();	
			if(k%3600==0)
				kh++;
			hour_hand();
		
		}
	}
	


}

void Pend::longer()
{
	a= i*3.14/180;
		
	nx1= ox + (x1- ox)*cos(a) + (y1-oy)*sin(a);		
	ny1= oy - (x1- ox)*sin(a) + (y1-oy)*cos(a);
	nx2= ox + (x2- ox)*cos(a) + (y2-oy)*sin(a);
	ny2= oy - (x2- ox)*sin(a) + (y2-oy)*cos(a);	
	
	setcolor(WHITE);
	line(nx1,ny1,nx2,ny2);
	setcolor(GREEN);
	bar(nx2-10,ny2-10,nx2+10,ny2+10);
	
	delay(39);
		
	setcolor(BLACK);
	line(nx1,ny1,nx2,ny2);
	bar(nx2-10,ny2-10,nx2+10,ny2+10);

}


void Pend::sec_hand()
{
	a= -6* (k*3.14/180);
	
	setcolor(BLACK);
	line(xc,yc,snx,sny);
	circle(snx,sny,2);
	
	snx= ox + (sx2- ox)*cos(a) + (sy2-oy)*sin(a);		
	sny= oy - (sx2- ox)*sin(a) + (sy2-oy)*cos(a);
	
	setcolor(3);
	line(xc,yc,snx,sny);
	circle(snx,sny,2);
	
}

void Pend::min_hand()
{
	a= -6* (km*3.14/180);
	
	setcolor(BLACK);
	line(xc,yc,mnx,mny);
	circle(mnx,mny,2);
	
	mnx= ox + (mx2- ox)*cos(a) + (my2-oy)*sin(a);		
	mny= oy - (mx2- ox)*sin(a) + (my2-oy)*cos(a);
	
	setcolor(11);
	line(xc,yc,mnx,mny);
	circle(mnx,mny,2);
	
}

void Pend::hour_hand()
{
	a= -30* (kh*3.14/180);
	
	setcolor(BLACK);
	line(xc,yc,hnx,hny);
	circle(hnx,hny,2);
	
	hnx= ox + (hx2- ox)*cos(a) + (hy2-oy)*sin(a);		
	hny= oy - (hx2- ox)*sin(a) + (hy2-oy)*cos(a);
	
	setcolor(9);
	line(xc,yc,hnx,hny);
	circle(hnx,hny,2);
	
}



int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	Pend obj;
	
	while(1)
	{
		obj.draw(11,18,50);
	}
	
	closegraph();
}



