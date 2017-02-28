#include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);

	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("OGL");
	glutDisplayFunc(display);
	glutMainLoop();
}
