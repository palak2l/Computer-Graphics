#include<iostream>
#include<GL/glut.h>
using namespace std;

int xc, yc, r;

void MidPointCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);

    int x = 0;
    int y = r;

    int p = 1 - r;

    do
    {
        
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        
        if (p < 0)
        {
            x = x + 1;
            p = p + 2*x + 3; 
        }      
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2*x - 2*y + 5;   
        }

    } while (x <= y);   

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter center (xc , yc): ";
    cin >> xc >> yc;

    cout << "Enter radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Mid-Point Circle Drawing");

    glClearColor(1.0, 1.0, 1.0, 0);  // White background
    glColor3f(0.0, 0.0, 0.0);        // Black points

    gluOrtho2D(0, 640, 0, 480);

    glutDisplayFunc(MidPointCircle);

    glutMainLoop();

    return 0;
}