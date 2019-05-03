#include <iostream>
#include <glut.h>
#include <time.h>
#include <math.h>

#include <vector>
#include "Punto2D.h"

using namespace std;

int NUMPOINTS = 0;
vector<Punto2D> puntosControl;

////////////////////
/*double oldX, oldY, currentX, currentY;
static GLsizei width_, height_;
//
//float Punto2D::size = 3.0f;
//
Punto2D puntoActual;
//
// Mouse callback routine.
void mouseControl(int button, int state, int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Store the clicked point in the currentPoint variable when left button is pressed.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		puntoActual = puntosControl[NUMPOINTS-1];

		//ModifyMyStuff(puntoActual);
	}

	// Store the currentPoint in the points vector when left button is released.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		puntosControl.push_back(puntoActual);

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) exit(0);

	//glFlush();
	glutPostRedisplay();
}

// Mouse motion callback routine.
void mouseMotion(int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Update the location of the current point as the mouse moves with button pressed.
	puntoActual.setxy(x, height_ - y);

	glColor3f(1.0, 1.0, 1.0);
	//DibujaLinea(puntosControl[NUMPOINTS-1], puntoActual);


	//Punto2D POld = puntoActual;
	//for (double t = 0.0; t <= 1.0; t += 0.005)
	//{
	//	Punto2D P = DibujaBezier(t);
	//	DibujaLinea(POld, P);
	//	POld = P;
	//}

	//glFlush();

	glutPostRedisplay();
}

*/

void myInit()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

Punto2D DibujaBezier(double t)
{
	Punto2D P;
	P.init();
	int n = NUMPOINTS - 1;
	for (int i = 0; i < NUMPOINTS; i++)
	{
		P.x += CoeficienteBinomial(n, i)*(puntosControl[i].x)*(pow((1 - t), n - i))*(pow(t, i));
		P.y += CoeficienteBinomial(n, i)*(puntosControl[i].y)*(pow((1 - t), n - i))*(pow(t, i));
	}
	return P;
}

void DibujaLinea(Punto2D p1, Punto2D p2)
{
	glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glEnd();
	glFlush();
}

/*void DeCasteljau()
{
	//DeCasteljau
	Punto2D P;
	P.init();
	double t;
	Punto2D punto1, punto2;
	punto1.init();
	punto2.init();
	punto1.setxy((float)oldX, 720 - oldY);
	punto2.setxy((float)currentX, 720 - currentY);
	//int i = 0;
	for (t = 0; t <= 1.0; t = t + 0.001)
	{
		currentX = (1 - t)*((1 - t)*((1 - t)*puntosControl[0].x + t * puntosControl[1].x) + t * ((1 - t)*puntosControl[1].x + t * puntosControl[2].x)) + t * ((1 - t)*((1 - t)*puntosControl[1].x + t * puntosControl[2].x) + t * ((1 - t)*puntosControl[2].x + t * puntosControl[3].x));
		currentY = (1 - t)*((1 - t)*((1 - t)*puntosControl[0].y + t * puntosControl[1].y) + t * ((1 - t)*puntosControl[1].y + t * puntosControl[2].y)) + t * ((1 - t)*((1 - t)*puntosControl[1].y + t * puntosControl[2].y) + t * ((1 - t)*puntosControl[2].y + t * puntosControl[3].y));

		punto1.setxy((float)oldX, 720 - oldY);
		punto2.setxy((float)currentX, 720 - currentY);
		glColor3f(1.0, 0.0, 0.0);

		DibujaLinea(punto1, punto2);
		cout << t << endl;
		oldX = currentX;
		oldY = currentY;
		//if (t==0 || t == .250 || t == .500 || t == .750)
		//{
		//	i++;
		//}
	}
}
*/
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat x, y;
	srand((unsigned)time(NULL));

	int num[2] = { 3,4 };
	int l = rand() % (2);

	glPointSize(6.0);
	glColor3f(1.0f, 0.0f, 0.0f);

	for (int i = 0; i < num[l]; i++)
	{
		x = (float)(rand() % 101) / 100;
		y = (float)(rand() % 101) / 100;
		//Dibuja puntos
		glBegin(GL_POINTS);
		glVertex3f(x, y, 0.0f);
		glEnd();
		//Imprime posición de los puntos
		cout <<" " <<x << " " << y<<endl;
		//cout << i;
		//Setea las posiciones del punto
		Punto2D aux;
		aux.setxy((float)x, (float)y);
		puntosControl.push_back(aux);
		NUMPOINTS++;
	}

	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < NUMPOINTS - 1; i++)
	{
		DibujaLinea(puntosControl[i], puntosControl[i + 1]);
	}

	glColor3f(0.0, 1.0, 0.0);
	Punto2D POld = puntosControl[0];
	for (double t = 0.0; t <= 1.0; t += 0.005)
	{
		Punto2D P = DibujaBezier(t);
		DibujaLinea(POld, P);
		POld = P;
	}
	/*for (int i = 0; i < NUMPOINTS; i++)
	{
		Punto2D aux;
		aux.setxy(oldX, oldY);
	}
	DeCasteljau();
	*/
	glFlush();
}



void resize(GLsizei width, GLsizei height)
{
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


int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Curva de Bezier: ");
	
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(resize);

	myInit();

	//// Register the mouse callback function.
	//glutMouseFunc(mouseControl);

	//// Register the mouse motion callback function.
	//glutMotionFunc(mouseMotion);

	glutMainLoop();
	return 0;
}