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


void display_callback();
void init(){
glClearColor(1.0,1.0,1.0,1.0);

}


int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Snake Game");
 //glClearColor(1.0,1.0,1.0,0);

 glutDisplayFunc(display_callback);
 init();
 glutMainLoop();
 return 0;
}

void display_callback(){
glClear(GL_COLOR_BUFFER_BIT);
glutSwapBuffers();
}
