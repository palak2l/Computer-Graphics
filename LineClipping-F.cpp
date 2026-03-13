#include<iostream>
#include<GL/glut.h>
using namespace std;

int outa[4]={0,0,0,0};
int outb[4]={0,0,0,0};	
int xa,ya,xb,yb;
int xmin,ymin,xmax,ymax;

int xi1,yi1,xi2,yi2; // intersection points

void outcode(int x, int y, int out[])
{
	if(x<xmin)
		out[3]=1;

	if(x>xmax)
		out[2]=1;

	if(y<ymin)
		out[1]=1;

	if(y>ymax)
		out[0]=1;
}

void intersection(int x1, int y1, int out[], float m)
{
    int x = x1;
    int y = y1;
    
    if(out[3]==1)
    {
        x = xmin;
        y = y1 + m * (xmin - x1);
    }
    else if(out[2]==1)
    {
        x = xmax;
        y = y1 + m * (xmax - x1);
    }
    
    if(out[1]==1)
    {
        y = ymin;
        x = x1 + (ymin - y1) / m;
    }
    else if(out[0]==1)
    {
        y = ymax;
        x = x1 + (ymax - y1) / m;
    }

    cout<<"----point after cliping ----\n";
    cout<<"("<<x<<","<<y<<")\n";

    // store for drawing
    if(x1==xa && y1==ya)
    {
        xi1=x;
        yi1=y;
    }
    else
    {
        xi2=x;
        yi2=y;
    }
}

void linecliping()
{
	int flag1 = 0;
	int reject = 0;
	
	cout<<"enter xmin : ";
	cin>>xmin;
	cout<<"enter ymin : ";
	cin>>ymin;
	cout<<"enter xmax : ";
	cin>>xmax;
	cout<<"enter ymax : ";
	cin>>ymax;
	
	cout<<"enter xa : ";
	cin>>xa;
	cout<<"enter ya : ";
	cin>>ya;
	cout<<"enter xb : ";
	cin>>xb;
	cout<<"enter yb : ";
	cin>>yb;
	
	outcode(xa,ya,outa);
	outcode(xb,yb,outb);

	cout<<"\n -------Outcodes------- \n";
	cout<<"outcode a : ";
	for(int i=0; i<4; i++)
		cout<<outa[i];

	cout<<"\n";

	cout<<"outcode b : ";
	for(int i=0; i<4; i++)
		cout<<outb[i];

	cout<<"\n\n";
	
	for(int i=0; i<4; i++)
	{
		if(outa[i]==1 || outb[i]==1)
		{
			flag1=1;
			break;
		}
	}
	
	if(flag1==0)
	{
		cout<<"the line is accepted \n";
	}
	else
	{
		for(int i =0; i<4; i++)
		{
			if(outa[i] == 1  && outb[i] == 1)
			{
				reject=1;
				break;
			}
		}

		if(reject==0)
		{
			cout<<"the line is partially accepted \n";	
			float m = (float) (yb-ya)/(xb-xa);

			intersection(xa,ya,outa,m);
			intersection(xb,yb,outb,m);
		}
		else
		{
			cout<<"the line is rejected \n";
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// draw clipping window
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmax,ymin);
	glVertex2f(xmax,ymax);
	glVertex2f(xmin,ymax);
	glEnd();

	// original line
	glColor3f(1,0,0);
	glBegin(GL_LINES);
	glVertex2f(xa,ya);
	glVertex2f(xb,yb);
	glEnd();

	// clipped line
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(xi1,yi1);
	glVertex2f(xi2,yi2);
	glEnd();

	glFlush();
}

int main(int argc,char** argv)
{
	linecliping();

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Line Clipping");

	glClearColor(1,1,1,1);
	gluOrtho2D(0,640,0,480);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}