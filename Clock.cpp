#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Pend
{
	float i, a;	///angle
	
	float rx1,ry1,ry2,rx2;
	
	float	x1,y1,x2,y2;
	float 	xc,yc, r;
	float 	nx1, nx2,ny1,ny2;
	
	float nsx, nsy, sx, sy;
	float nmx, nmy, mx, my;
	float nhx, nhy, hx, hy;
	
	int k, kh, km;
	
public:
	Pend();
	void draw(int,int,int);
	void casing();
	
	void pendulum();
	void longer();
	void second_h();
	void minute_h();
	void hour_h();
	


};

Pend::Pend()
{
	xc= getmaxx()/2;
	yc= getmaxy()/2-80;
	
	rx1= xc -150;
	ry1= yc -150;
	rx2= xc +150;
	ry2= yc +300;
	
	r= 120;
	
	x1= xc;
	y1= yc + 122;
	x2= xc;
	y2= yc + 250;
	
	nsx = xc;
	nsy = yc ;
	sx = xc;
	sy = yc - 100;
	
	
	nmx = xc;
	nmy = yc -80;
	mx = xc;
	my = yc  - 80;
	
	nhx = xc;
	nhy = yc -60 ;
	hx = xc;
	hy = yc - 60;
	
	k=0;
	km=0;
	kh=0;




}

void Pend::casing()
{
	rectangle(rx1,ry1,rx2,ry2);
	
	circle(xc,yc,r);
	outtextxy(xc-115, yc-5,"9");
	outtextxy(xc-5, yc-112,"12");
	outtextxy(xc+110, yc-5,"3");
	outtextxy(xc-3, yc+108,"6");


}

void Pend::pendulum()
{
	for(i=-12; i<=12; i++)
	{
		longer();
		
		if(i==12)
		{
			second_h();
			minute_h();
			hour_h();
			if(k%60==0)
				{km++;
				//delay(10000);
				}
					
					if(km%60==0)
						kh++;
				
		}
	}

	for(i=12; i>=-12; i--)
	{
		longer();
		
		if(i==-12)
		{
			second_h();
			minute_h();
			hour_h();
			if(k%60==0)
				km++;
				
					if(km%60==0)
						kh++;
				
		}
	}


}

void Pend::longer()
{
	a= i*3.14/180;
		
		nx1= xc + (x1- xc)*cos(a) + (y1- yc)*sin(a);
		ny1= yc - (x1-xc)*sin(a) + (y1-yc)*cos(a);
	
		nx2= xc + (x2- xc)*cos(a) + (y2- yc)*sin(a);
		ny2= yc - (x2-xc)*sin(a) + (y2-yc)*cos(a);
		
		setcolor(RED);
		line(nx1,ny1,nx2,ny2);
		setcolor(GREEN);
		circle(nx2,ny2,12);
		
		//delay(39);
		
		setcolor(BLACK);
		line(nx1,ny1,nx2,ny2);
		circle(nx2,ny2,12);



}

void Pend::second_h()
{
		setcolor(BLACK);
		line(xc,yc,nsx,nsy);
		circle(nsx,nsy,2);
		
		
		a= -6*(k*3.14/180);
		
		nsx= xc + (sx- xc)*cos(a) + (sy- yc)*sin(a);
		nsy= yc - (sx- xc)*sin(a) + (sy- yc)*cos(a);
	
		
		setcolor(CYAN);
		line(xc,yc,nsx,nsy);
		circle(nsx,nsy,2);
		
		k++;
}

void Pend::minute_h()
{
		setcolor(BLACK);
		line(xc,yc,nmx,nmy);
		circle(nmx,nmy,2);
		
		
		a= -6*(km*3.14/180);
		
		nmx= xc + (mx- xc)*cos(a) + (my- yc)*sin(a);
		nmy= yc - (mx- xc)*sin(a) + (my- yc)*cos(a);
	
		
		setcolor(5);
		line(xc,yc,nmx,nmy);
		circle(nmx,nmy,2);
		//delay(10000);
		

}

void Pend::hour_h()
{
		setcolor(11);
		line(xc,yc,nhx,nhy);
		circle(nhx,nhy,2);
		
		
		a= -30*(kh*3.14/180);
		
		nmx= xc + (hx- xc)*cos(a) + (hy- yc)*sin(a);
		nmy= yc - (hx- xc)*sin(a) + (hy-yc)*cos(a);
	
		
		setcolor(6);
		line(xc,yc,nhx,nhy);
		circle(nhx,nhy,2);


}


void Pend::draw(int h,int m, int s)
{
k=s;
km=m;
kh=h;
	casing();
while(1)
{	
	pendulum();
}

}


int main()
{
	int gd=0,gm;
	initgraph(&gd,&gm,NULL);
	
	Pend obj;
	
	while(1)
	{
		obj.draw(1,58,58);
	}
	
	
	closegraph();

}
