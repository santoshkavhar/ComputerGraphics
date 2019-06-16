#include<iostream>
#include<stdlib.h>
#include<graphics.h>

#define max 70

using namespace std;

int main()
{
    int gd=DETECT, gm;
    int r[max][max] ; // r for position of 1 or 0.

    int cnt=0, x, y;    //cnt will help for randomly filling the first cycle of whole screen

    initgraph(&gd, &gm, NULL);
do{
        for(int i=0; i<64; i++)
        {
            for(int j=0; j<48; j+=2)    //extra space needed to look neat, so j is double incremented
                        {
                                x= i*10 ;       //as the window is divided into 64*48, we multiply by 10 for position
                                y= j*10 ;
                    if(cnt<(64*24))             //only first cycle is random cycle
                            {
                                r[i][j]= rand() % 5;    // r[i][j] can get values 0,1,2,3,4
                                cnt ++;
                               // delay(10);
                                
                            }
                    else
                        {
                        /// This is for making that position blank and ready for next entry
                        setcolor(0);    // make it disapper
                                            
                            if(r[i][j]==0)
                                    {   line(x + 4, y + 6, x + 5, y + 5);//1's head
                                        line (x + 5, y + 5, x + 5, y + 15);// 1's spine
                                        line(x + 4, y + 15, x + 6, y + 15);// 1's base
                                       }
                            else if(r[i][j]==1)
                                     ellipse(x + 5, y + 10, 0, 360, 2 , 5); //draw 0
                                

                            if(j<46)
                                r[i][j] = r[i][j+2];    
                               
                            else
                                r[i][j]= rand() % 5;    // last row needs to get random values, which are copied up
                                          
                        }
 //delay(10);
                        setcolor(2);
                               
                                if(r[i][j]==0)
                                    {   
                                        line(x + 4, y + 6, x + 5, y + 5);
                                        line (x + 5, y + 5, x + 5, y + 15);
                                        line(x + 4, y + 15, x + 6, y + 15);
                                    }
                                else if(r[i][j]==1)
                                     ellipse(x + 5, y + 10, 0, 360, 2 , 5);
                    }
                }
            }while(1);		//for infinite loop
            delay(9999);
    closegraph();
}
