#include <iostream>
#include <GL/glut.h>
using namespace std;

int xc, yc, r;

void BresCircle()
 {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
 int x, y, d;
 x = 0;
 y = r;
 d = 3 - (2*r);
 
 do
 { 
  glVertex2d (xc + x, yc + y);
  glVertex2d (xc + y, yc + x);
  glVertex2d (xc + y, yc - x);
  glVertex2d (xc + x, yc - y);
  glVertex2d (xc - x, yc - y);
  glVertex2d (xc - y, yc - x);
  glVertex2d (xc - y, yc + x);
  glVertex2d (xc - x, yc + y);
  
  if (d < 0)
  {
   x = x + 1;
   d = d + (4*x) + 6;
   }
   
  else
  {
   x = x + 1;
   y = y - 1;
   d = d + (4*x) - (4*y) + 10;
   }
  } while ( x <= y);
   glEnd();
   glFlush();
 }
 
int main(int argc, char** argV)
{
 cout << "\nEnter circle's co-ordinates: ";
 cin >> xc >> yc;
 cout << "\nEnter radius: ";
 cin >> r;
 
 glutInit(&argc , argV);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 
 glutInitWindowPosition(0,0);
 glutInitWindowSize(640,480);
 
 glutCreateWindow("Plot");
 glClearColor(1.0,1.0,1.0,0); //sel clear colour to black
   
 glColor3f(0.0,0.0,0.0); //fill colour to black
   
 gluOrtho2D(0,640,0,480); 
   
 glutDisplayFunc(BresCircle); //call the displaying function
   
 glutMainLoop(); //keep displaying until the program is closed
 return 0;
   
}
   
 
 

