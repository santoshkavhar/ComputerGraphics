#include<iostream>
#include<graphics.h>
#include<stdlib.h>
 long int random(void);
       void srandom(unsigned int seed);
       char *initstate(unsigned int seed, char *state, size_t n);
       char *setstate(char *state);
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
//int r= getwindowwidth();
//cout << r;
int gd=DETECT, gm;
int a,b,c,d,e,rand,f,g,t;
initgraph(&gd,&gm,NULL);
int ans=100000;
/*
while(ans!=0)
{


/*
		a=320;
		b=240;
		c=random()%640;
		d=random()%480;
		e=random()%16;
		f=random()%640;
		g=random()%480;
	*/
		/*{
		
			//putpixel(random()%640,random()%480,random()%16);
			
			
		setcolor(e);
			line(a,b,c,d);
			
			delay(10);
			
			setcolor(random()%16);
			line(c,d,f,g);
			
			delay(10);
			//}
		//else if(ans%2==1)
			//{
			
		
		setcolor(BLACK);
		 line(a,b,c,d);
		 ans--;
		 delay(10);
		 }
		 
		 }*/
		 a=120;
		 b=240;
		 f=1;
		 while(1)
		 {
		 e=0;
		 while(e!=500)
		 {
		 
			c=random()%160;
			d=random()%240;
			do
			{
			g=random()%16;
			}while(g==CYAN||g==WHITE||g==BLACK||g==YELLOW);
			setcolor(g);
			
			line(a,b,420+random()%320,160+random()%200);
			//arc(a, b, 0, 135, 50);
			//circle(320,240,e);
			//delay(5);
			//a=c;b=d;
			e+=5;
			
		 }
		 cleardevice();
		 }
}
