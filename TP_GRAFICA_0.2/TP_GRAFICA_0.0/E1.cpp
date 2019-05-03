#include <iostream>
#include <glut.h>
#include <time.h>
#include <vector>

using namespace std;

//GLfloat x;
//GLfloat y;

struct Puntos
{
	float x;
	float y;
	float z;
}posPunto[4];


void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void DibujaPunto()
{
	srand((unsigned)time(NULL));

	int cantPuntos[2] = { 3,4 };
	int l = rand() % (2);

	glPointSize(6.0);
	glColor3f(1.0f, 0.0f, 0.0f);


	for (int i = 0; i < cantPuntos[l]; i++)
	{

		posPunto[i].x = (float)(rand() % 101) / 100;
		posPunto[i].y = (float)(rand() % 101) / 100;
		glBegin(GL_POINTS);
		glVertex3f(posPunto[i].x, posPunto[i].y, 0.0f);
		glEnd();
		//cout <<" " << posPunto[i].x<< " " << posPunto[i].y <<endl;
		//cout << i;
		glBegin(GL_LINES);
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glEnd();
		glFlush();
	}
/*
	for (int i = 0; i < cantPuntos[i] - 1; i++)
	{
		glBegin(GL_LINES);
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glEnd();
		glFlush();
	}
*/
	glutSwapBuffers();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DibujaPunto();
}

void DibujaLinea()
{

}
int Factorial(int x)
{
	int fac = 1;
	for (int i = 2; i <= x; i++) fac *= i;
	return fac;
}

int CoeficienteBinomial(int n, int i)
{
	int a = Factorial(n);
	int b = Factorial(i);
	int c = Factorial(n - i);
	int cb = a / (b*c);
	return cb;
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
	glutReshapeFunc(resize);
	
	initGL();
	glutMainLoop();
	return 0;
}