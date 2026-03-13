#include<iostream>
#include<GL/glut.h>
using namespace std;

int xa,ya,xb,yb;
int Round(float a)
{
return (int)(a+0.5);
}
void DDALine(int xa ,int ya, int xb, int yb){
int dx , dy, steps;

dx = xb-xa;
dy = yb-ya;

if(abs(dx)>abs(dy))
{
steps = abs(dx);
}
else
{
steps= abs(dy);
}
float xinc,yinc;
xinc = (float)(dx)/steps;
yinc = (float)(dy)/steps;
float x = xa;
float y = ya;

glBegin(GL_POINTS);

glVertex2d(xa,ya);
for (int i = 0 ; i<steps;i++)
{
x =x+xinc;
y =y+yinc;
glVertex2d(Round(x),Round(y));
}
glEnd();
glFlush();
}

void Draw()
{
/*glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glVertex2d(100,100);
glVertex2d(300,300);
glEnd();
glFlush();*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.44,0.0,3.0);
DDALine(xa,ya,xb,ya);
DDALine(xb,ya,xb,yb);
DDALine(xb,yb,xa,yb);
DDALine(xa,yb,xa,ya);
glColor3f(0.0,0.0,0.0);
DDALine(xa,(ya+yb)/2,(xa+xb)/2,ya);
DDALine((xa+xb)/2,ya,xb,(ya+yb)/2);
DDALine(xb,(ya+yb)/2,(xa+xb)/2,yb);
DDALine((xa+xb)/2,yb,xa,(yb+ya)/2);
}


int main(int argc , char **argv)
{
cout<<"\n enter first point";
cin>>xa>>ya;
cout<<"\n enter second point";
cin>>xb>>yb;
glutInit(&argc,argv); // initialise GLUT(Graphics Library Utility Tools) library

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // Set the initial display mode

glutInitWindowPosition(0,0); //Set the initial position and size
glutInitWindowSize(640,480);

glutCreateWindow("plot"); // Create the window with title plot 

glClearColor(1.0,1.0,1.0,0);  // set clear color to white

//glColor3f(1.44,0.0,3.0); // set fill color to black

gluOrtho2D(0,640,0,480); 

glutDisplayFunc(Draw); // call the display function

glutMainLoop(); // keep displaying until the program is closed
}
