#include <iostream>
#include <GL/glut.h>
using namespace std;

int xa, ya, xb, yb;
int flag = 0;

void BresLine(int xa, int ya, int xb, int yb)
{
 
 //if (abs(dx) > abs(dy))
 
 int dx = xb - xa;
 int dy = yb - ya;

 int d = (2*abs(dy)) - abs(dx);
 
 int c, r, f;
 if (dx > 0)
 {
  c = xa;
  r = ya;
  f = xb;
 }
 
 else
 {
  c = xb;
  r = yb;
  f = xa;
 }
 
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POINTS);
 
 while (f >= c)
 {
  if (d < 0)
  {
   c = c + 1;
   d = d + (2* abs(dy));
   }
   
  else
  {
   c = c + 1;
   if ( (dx > 0 && dy > 0) || (dx < 0 && dy < 0))
   {
    r = r + 1;
    }
   
   else
   {
    r = r - 1;
    }
    d = d + (2*abs(dy)) - (2*abs(dx));
    }
    if (flag == 0)
    {
    glVertex2d(c , r);
    }
    else
    {
    glVertex2d(r , c);
    }
   }
   glEnd();
   glFlush();
  }
  
void Draw()
{
 if (abs(xb - xa) > abs(yb - ya))
 {
  BresLine(xa, ya, xb, yb);
  }
 else
 { 
  flag = 1;
  BresLine(ya, xa, yb, xb);
  }
 }
 
 
 
 int main(int argc, char** argV)
{
 cout << "\nEnter first co-ordinates: ";
 cin >> xa >> ya;
 cout << "\nEnter second co-ordinates";
 cin >> xb >> yb;
 
 glutInit(&argc , argV);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 
 glutInitWindowPosition(0,0);
 glutInitWindowSize(640,480);
 
 glutCreateWindow("Plot");
 glClearColor(1.0,1.0,1.0,0); //sel clear colour to black
   
 glColor3f(0.0,0.0,0.0); //fill colour to black
   
 gluOrtho2D(0,640,0,480); 
   
 glutDisplayFunc(Draw); //call the displaying function
   
 glutMainLoop(); //keep displaying until the program is closed
 return 0;
   
}
