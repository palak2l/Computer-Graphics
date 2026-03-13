
// C++ source code implements Bresenham's circle and DDA line drawing algorithms using GLUT functions.

#include <iostream>
#include <GL/glut.h>
using namespace std;

int xa, xb, ya, yb;

int Round(float a)
 {
   return(int)(a+0.5);
 }
void Draw()
 {
  /* glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_LINES);
   glVertex2d(100,100);
   glVertex2d(300,300);
   glEnd();
   glFlush(); */
   
   int dx, dy, steps;
   
   dx =  xb-xa;
   dy = yb-ya;
   
   if(abs(dx)>abs(dy))
   steps = abs(dx);
   else
   steps = abs(dy);
   
   float xinc, yinc;
   
   xinc = (float)(dx) / steps;
   yinc = (float)(dy) / steps;
   
   float x=xa, y=ya;
   
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POINTS);
   
   glVertex2d(xa,ya);
   for(int i=0; i<steps; i++)
   {
       x += xinc;
       y += yinc;
       glVertex2d(Round(x),Round(y));
   }
   glEnd();
   glFlush();
 }
int main( int argc, char** argV)
{
   cout<<"\nEnter First Co-ordinate:" ;
   cin>>xa>>ya;
   cout<<"\nEnter Second Co-ordinate:" ;
   cin>>xb>>yb;
   glutInit(&argc , argV); //initialize GLUT library (graphics library utility tool)
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//set the initial display mode
   
   glutInitWindowPosition(0,0);
   glutInitWindowSize(640,480);
   //set initial window position and size
   
   glutCreateWindow("Plot");
   glClearColor(1.0,1.0,1.0,0); //sel clear colour to black
   
   glColor3f(0.0,0.0,0.0); //fill colour to black
   
   gluOrtho2D(0,640,0,480); 
   
   glutDisplayFunc(Draw); //call the displaying function
   
   glutMainLoop(); //keep displaying until the program is closed
   return 0;
   
   
}