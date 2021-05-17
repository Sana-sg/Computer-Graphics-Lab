#include <stdio.h>
#include <GL/glut.h>


void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000, 1000, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);

}
void body() {
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(100, 300);
	glVertex2f(400, 300);
	glVertex2f(400, 100);
	glEnd();
}
void roof() {
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(100, 300);
	glVertex2f(240, 400);
	glVertex2f(400, 300);
	glEnd();

}
void door() {
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(200, 100);
	glVertex2f(200, 200);
	glVertex2f(300, 200);
	glVertex2f(300, 100);
	glEnd();
}
void wind1() {
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(120, 220);
	glVertex2f(120, 260);
	glVertex2f(160, 260);
	glVertex2f(160, 220);
	glEnd();
}
void wind2() {
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(340, 220);
	glVertex2f(340, 260);
	glVertex2f(380, 260);
	glVertex2f(380, 220);
	glEnd();
}
void house() {
	body();
	roof();
	door();
	wind1();
	wind2();
}
float th = 0,th1=0,th2=0,th3=0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	th += 0.01;
	th1 += 0.02;
	th2 += 0.03;
	th3 += 0.04;
	glLoadIdentity();


	glPushMatrix();
	glRotatef(th, 0, 0, 1);
	house();
	glPopMatrix();

	glPushMatrix();
	glRotatef(th1, 0, 0, 1);
	glTranslatef(300, 300, 0);
	house();
	glPopMatrix();

	glPushMatrix();
	glRotatef(th2, 0, 0, 1);
	glTranslatef(500, 0, 0);
	house();
	glPopMatrix();

	glPushMatrix();
	glRotatef(th3, 0, 0, 1);
	glTranslatef(0, 500, 0);
	house();
	glPopMatrix();

	
	glutSwapBuffers();
	glutPostRedisplay();

}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("My First Program");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}