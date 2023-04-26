#include <GL/glut.h>
#include <cstdlib>
#include <math.h>
#include <iostream>

const double PI = 3.141592654;

void primitivaQ() {
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(10.0, 20.0, 0.0);
		glVertex3f(20.0, 20.0, 0.0);
		glVertex3f(20.0, 10.0, 0.0);
		glVertex3f(10.0, 10.0, 0.0);
	glEnd();

	glFlush();
}

void primitivaT() {
	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f(10.0, 20.0, 0.0);
		glVertex3f(15.0, 30.0, 0.0);
		glVertex3f(20.0, 20.0, 0.0);
	glEnd();
	glFlush();
}

void primitivaC(double rad){
	int d;
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	for(d = 0; d<=32;d++){
		double angle = (2*PI/32) * d;
		glVertex2d(rad*cos(angle),rad*sin(angle));
	}
	glEnd();
}

// Drawing routine.
void drawScene(void) {
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(50,50,0);
	primitivaT();
	glPopMatrix();

	glutSwapBuffers();
}

// Initialization routine.
void Init(void) {
	glClearColor(0.75, 0.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Main routine.
int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("trabalho1");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);

	Init();

	glutMainLoop();
}





