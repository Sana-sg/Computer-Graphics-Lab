#include <stdio.h>
#include <GL/glut.h>
float x, y, inc = 0.2, r = 1, g =0 , b = 1;
int flag = 0;

void init() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);

}
void traingle() {
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(250, 400);
	glVertex2f(400, 100);
	glEnd();
}
void point(float a,float b) {
	glBegin(GL_POINTS);
	glVertex2f(a, b);
	glEnd();
}
float th;
float xtemp, ytemp;
void display() {
	th += inc;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if (flag == 1) {
		xtemp = 0;
		ytemp = 0;
	}
	else if (flag == 0) {
		xtemp = x;
		ytemp = y;
	}
	else if (flag == 2) {
		th = 0;
	}
	glColor3f(1, 0.6, 0);
	glPointSize(6);
	point(xtemp, ytemp);

	glColor3f(r, g, b);
	glTranslatef(xtemp, ytemp, 0);
	glRotatef(th, 0, 0, 1);
	glTranslatef(-xtemp, -ytemp, 0);
	traingle();

	glutSwapBuffers();
	glutPostRedisplay();
}
void rotateMenu(int option) {
	if (option == 1) {
		flag = 1;
	}
	else if (option == 2) {
		flag = 0;
	}
	else if (option == 3) {
		flag = 2;
	}
	else if (option == 4) {
		inc += 0.05;
	}
	else if (option == 5) {
		inc -= 0.05;
	}
	else if (option == 6) {
		r = 1;
		g = 0;
		b = 0;
	}
}

int main(int argc, char* argv[]) {
	printf("Enter the fixed points: ");
	scanf_s("%f%f", &x, &y);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Triangle Rotation");
	init();
	glutDisplayFunc(display);
	glutCreateMenu(rotateMenu);
	glutAddMenuEntry("Rotate around Origin", 1);
	glutAddMenuEntry("Rotate around Fixed point", 2);
	glutAddMenuEntry("Stop Rotation", 3);
	glutAddMenuEntry("Speed Up", 4);
	glutAddMenuEntry("Speed Down", 5);
	glutAddMenuEntry("Color:Red", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}