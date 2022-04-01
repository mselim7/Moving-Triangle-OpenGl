#include <windows.h>
#include <iostream>
using namespace std;
#include <gl/gl.h>
#include <gl/glut.h>
#include<math.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
double tx = 0.0;
boolean wasl = false;

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char* argv[]);
/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations();

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay();

int main(int argc, char* argv[]) {
	InitGraphics(argc, argv);
	
	return 0;
}

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL Lab");
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	//	glutIdleFunc(OnDisplay);
	//SetTransformations();
	// to keep the window open 
	glutMainLoop();
}

/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations() {
	//set up the logical coordinate system of the window: [-100, 100] x [-100, 100]
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200, -200, 200);
}

//  cx: center x
//  cy: center y
//  r: radius
// num_segments: no of segments to draw the circle  note: high number of segments ---> high accuracy 

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay() {
	//set the background color to white
	glClearColor(1, 1, 1, 5);
	//fill the whole color buffer with the clear color
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();



	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	// X-axis
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);
	glColor3f(1, 0, 0);
	//Y-axis
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);
	glEnd();


	glPointSize(5);
	glTranslatef(tx, 0, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2d(0, 0);
	glColor3f(0, 1, 0);
	glVertex2d(25, 40);
	glColor3f(0, 0, 1);
	glVertex2d(50, 0);
	glEnd();

	glLineWidth(5);
	glFlush();
	glutSwapBuffers();
	

		if (tx <= 150 && !wasl) {
			tx += 1;
			cout << tx << endl;
			cout << wasl << endl;
			if (tx == 150) { wasl = true; }
		}

		if (tx >= -200 && wasl)
		{
			tx -= 1;
			cout << tx << endl;
			cout << wasl << endl;
		}

	glutPostRedisplay();
	
}

