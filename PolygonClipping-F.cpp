#include <GL/glut.h>
#include <iostream>
using namespace std;

int xmin, ymin, xmax, ymax;
int v, i;
int original_v;
int k;
int input [2][10];
int temp [2][10];
float output [2][10];
int result[2][10];


void leftclip(int xa, int ya, int xb, int yb)
{
 float m = float (yb - ya) / (xb - xa);
 if (xa > xmin && xb > xmin) //in-in
 {
  output[0][k] = xb;
  output[1][k] = yb;
  k = k + 1;
  }
 if (xa > xmin && xb < xmin) //in-out
 {
  output[0][k] = xmin;
  output[1][k] = ya + m * (xmin - xa);
  k = k + 1;
  }
 if (xa < xmin && xb > xmin) //out-in
 {
  output[0][k] = xmin;
  output[1][k] = ya + m * (xmin - xa);
  output[0][k+1] = xb;
  output[1][k+1] = yb;
  k = k + 2;
  }
}

void rightclip(int xa, int ya, int xb, int yb)
{
 float m = float (yb - ya) / (xb - xa);
 if (xa < xmax && xb < xmax) //in-in
 {
  output[0][k] = xb;
  output[1][k] = yb;
  k = k + 1;
  }
 if (xa < xmax && xb > xmax) //in-out
 {
  output[0][k] = xmax;
  output[1][k] = ya + m * (xmax - xa);
  k = k + 1;
  }
 if (xa > xmax && xb < xmax) //out-in
 {
  output[0][k] = xmax;
  output[1][k] = ya + m * (xmax - xa);
  output[0][k+1] = xb;
  output[1][k+1] = yb;
  k = k + 2;
  }
}

void bottomclip(int xa, int ya, int xb, int yb)
{
 float m = float (yb - ya) / (xb - xa);
 if (ya > ymin && yb > ymin) //in-in
 {
  output[0][k] = xb;
  output[1][k] = yb;
  k = k + 1;
  }
 if (ya > ymin && yb < ymin) //in-out
 {
  output[0][k] = xa + (ymin - ya)/ m;
  output[1][k] = ymin;
  k = k + 1;
  }
 if (ya < ymin && yb > ymin) //out-in
 {
  output[0][k] = xa + (ymin - ya)/ m;
  output[1][k] = ymin;
  output[0][k+1] = xb;
  output[1][k+1] = yb;
  k = k + 2;
  }
}

void topclip(int xa, int ya, int xb, int yb)
{
 float m = float (yb - ya) / (xb - xa);
 if (ya < ymax && yb < ymax) //in-in
 {
  output[0][k] = xb;
  output[1][k] = yb;
  k = k + 1;
  }
 if (ya < ymax && yb > ymax) //in-out
 {
  output[0][k] = xa + (ymax - ya)/ m;
  output[1][k] = ymax;
  k = k + 1;
  }
 if (ya > ymax && yb < ymax) //out-in
 {
  output[0][k] = xa + (ymax - ya)/ m;
  output[1][k] = ymax;
  output[0][k+1] = xb;
  output[1][k+1] = yb;
  k = k + 2;
  }
}

void clipping()
{
 for (int i = 0;i < v; i++ )
 {
  temp[0][i] = input[0][i];
  temp[1][i] = input[1][i];
  }
 k = 0; 
 for (int i = 0;i < v; i++ )
 {
  leftclip(temp[0][i], temp[1][i], temp[0][(i+1) % v], temp[1][(i+1) % v]);
  }
  
  v = k;
  for (int i = 0;i < v; i++ )
 {
  temp[0][i] = output[0][i];
  temp[1][i] = output[1][i];
  }
  
  k = 0; 
 for (int i = 0;i < v; i++ )
 {
  rightclip(temp[0][i], temp[1][i], temp[0][(i+1) % v], temp[1][(i+1) % v]);
  }
  
  v = k;
  for (int i = 0;i < v; i++ )
 {
  temp[0][i] = output[0][i];
  temp[1][i] = output[1][i];
  }
  
  k = 0; 
 for (int i = 0;i < v; i++ )
 {
  bottomclip(temp[0][i], temp[1][i], temp[0][(i+1) % v], temp[1][(i+1) % v]);
  }
  
  v = k;
  for (int i = 0;i < v; i++ )
 {
  temp[0][i] = output[0][i];
  temp[1][i] = output[1][i];
  }
  
  k = 0; 
 for (int i = 0;i < v; i++ )
 {
  topclip(temp[0][i], temp[1][i], temp[0][(i+1) % v], temp[1][(i+1) % v]);
  }
  
  v = k;
  for (int i = 0;i < v; i++ )
 {
  temp[0][i] = output[0][i];
  temp[1][i] = output[1][i];
  }
  
  for (int i = 0;i < v; i++ )
 {
  result[0][i] = output[0][i];
  result[1][i] = output[1][i];
  }
   
 for (int i = 0;i < v; i++ )
 {
  cout<<"\n"<<result[0][i]<<"\t"<<result[1][i]<<"\n";
 }
 
} 
 
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 
 //Clipping Window
 glColor3f(1,1,1);
 glBegin(GL_LINE_LOOP);
 glVertex2i(xmin,ymin);
 glVertex2i(xmax,ymin);
 glVertex2i(xmax,ymax);
 glVertex2i(xmin,ymax);
 glEnd();

 // Original polygon
 glColor3f(1,0,0);
 glBegin(GL_LINE_LOOP);
 for(int i=0;i<original_v;i++)
 	glVertex2f(input[0][i],input[1][i]);
 glEnd();

 // Clipped polygon
 glColor3f(0,1,0);
 glBegin(GL_LINE_LOOP);
 for(int i=0;i<k;i++)
 	glVertex2f(result[0][i],result[1][i]);
 glEnd();

 glFlush();
} 

void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(0,500,0,500);
} 

int main(int argc,char** argv)
{
 cout<<"\nVertices: ";
 cin>> v;
 original_v = v;
 for (int i = 0;i < v;i++ )
 {
  cout<<"X-coordinate: ";
  cin>>input[0][i];
  cout<<"Y-coordinate: ";
  cin>>input[1][i];
  }
  
 cout<<"\nxmin: ";
 cin>>xmin;
 cout<<"\nymin: ";
 cin>>ymin;
 cout<<"\nxmax: ";
 cin>>xmax;
 cout<<"\nymax: ";
 cin>>ymax;
 
 clipping ();
 
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutCreateWindow("Polygon Clipping");

  init();
  glutDisplayFunc(display);
  glutMainLoop();
}