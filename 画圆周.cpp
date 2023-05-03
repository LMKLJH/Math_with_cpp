#include <graphics.h>
#include <conio.h>
using namespace std; 
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   circle(300, 200, 250);
   circle(300,200,110);
   circle(300,200,120);
    circle(300,200,300);
   getch();
   closegraph();
   return 0;
}

