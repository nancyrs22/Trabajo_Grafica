#include <iostream>
#include <glut.h>
#include <time.h>
using namespace std;

GLfloat p1;
GLfloat p2;

void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	srand((unsigned)time(NULL));

	int max = (rand() % 5);

	int num[2] = { 3,4 };
	int l = rand() % (2);

	glPointSize(6.0);
	glColor3f(1.0f, 0.0f, 0.0f);


	for (int i = 0; i < num[l]; i++)
	{
	
		p1 = (float)(rand() % 101) / 100;
		p2 = (float)(rand() % 101) / 100;
		glBegin(GL_POINTS);
		glVertex3f(p1, p2, 0.0f);
		glEnd();
		cout <<" " <<p1 << " " << p2<<endl;
		cout << i;
	}
	
	glutSwapBuffers();
}

void resize(GLsizei width, GLsizei height)
{
	cout << "width=> " << width << " height=> " << height << endl;

	if (height == 0) height = 1;                
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height) {
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else {

		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("trabajo grafica");

	glutDisplayFunc(display);
	//glutReshapeFunc(resize);
	
	initGL();
	glutMainLoop();
	return 0;
}