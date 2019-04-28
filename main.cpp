/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>


int Xc, Yc, R; // circle center and radius


//circle functions
void myInit(void)
{
 glClearColor(1.0,1.0,1.0,0);
 glColor3f(1.0, 0.0, 0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

//Draws the 8 symmetric points
void Circle8Points(int x, int y)
{
glVertex2i(Xc + x, Yc + y);
glVertex2i(Xc - x, Yc + y);
glVertex2i(Xc + x, Yc - y);
glVertex2i(Xc - x, Yc - y);
glVertex2i(Xc + y, Yc + x);
glVertex2i(Xc - y, Yc + x);
glVertex2i(Xc + y, Yc - x);
glVertex2i(Xc - y, Yc - x);
}

//Implement the Midpoint algorithm
void CircleMidpoint(void)
{
int x=0;
int y=R;
int p=1-R; //initial value of the decision parameter
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex2i(Xc,Yc); //Draw circle center for illustration
Circle8Points(x,y);/* Plot the First point */
while(x<y)
{
x++;
if(p<0)
p +=2 * x + 1;
else
{
y--; // ??? ??? ??? ??????? ????? ???? ?????? ???? ?????
p += 2 * (x -y) + 1;
}
Circle8Points(x,y);
}
glEnd();
glFlush();
}




//try yellow eyes
void Circleyel(void)
{

glClearColor(1.0,1.0,1.0,0);
 glColor3f(1.0, 1.0, 0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
int x=0;
int y=R;
int p=1-R; //initial value of the decision parameter
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex2i(Xc,Yc); //Draw circle center for illustration
Circle8Points(x,y);/* Plot the First point */
while(x<y)
{
x++;
if(p<0)
p +=2 * x + 1;
else
{
y--; // ??? ??? ??? ??????? ????? ???? ?????? ???? ?????
p += 2 * (x -y) + 1;
}
Circle8Points(x,y);
}
glEnd();
glFlush();
}






//2ndtry

void display()
{
 int i; float x,y;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
 for(i=0;i<=360;i++)
 {
 glBegin(GL_POINTS);
 x=(cos((2*i*3.14)/360)) * .6;
 y=(sin((2*i*3.14)/360)) * .6;
 glVertex2f(x,y);
 glEnd();
 }

glColor3f(0.0f, 1.0f, 0.0f);
 for(i=240;i<300;i++)
 {
 glBegin(GL_POINTS);
 x=cos((2*i*3.14)/360) * .3;
 y=sin((2*i*3.14)/360) * .3;
 glVertex2f(x,y);
 glEnd();
 }
 glColor3f(1.0f, 0.99f, 0.0f);
 glPointSize(15.5);
 glBegin(GL_POINTS);
 glVertex2f(-.25,.2);
 glVertex2f(.25,.2);
 glEnd();

 glFlush();
}



void multirngleDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
glPointSize(5);
glBegin(GL_TRIANGLES);
glVertex2i(50,50);
glColor3f(1,1,0);
glVertex2i(200,200);
glColor3f(0,1,0);
glVertex2i(300,50);
glEnd();
glFlush();

}

void tirngleDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,1);
glPointSize(10);
glBegin(GL_TRIANGLES);
glVertex2i(100,100);
glVertex2i(300,300);
glVertex2i(600,50);
glEnd();
glFlush();
}

void rectangelDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,1);
glPointSize(10);
glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
glEnd();

glFlush();
}

void rectdisplay(){

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.255f, 1.255f, 1.255f);
   glRectf(-0.50f, 0.50f, 0.50f, -0.50f);
   glFlush();
   glutSwapBuffers();
}



void display_callback();


int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Snake Game");
 //glClearColor(1.0,1.0,1.0,0);

 glutDisplayFunc(display_callback);
 glutMainLoop();
 return 0;
}

void display_callback(){
glutSwapBuffers();
}
