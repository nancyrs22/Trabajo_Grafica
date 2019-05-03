#include <iostream>
#include <glut.h>
#include <time.h>
using namespace std;

//GLfloat p1;
//GLfloat p2;

struct Point
{
	float x, y;
	Point() { x = 0.0; y = 0.0; }
	Point(float _x, float _y) : x(_x) , y(_y) {}
};

class Punto
{
public:
	Point pts[1];
	Punto();	
	void draw(Punto* sqr);
	Point mouse(int x, int y);
	Point* drag(Punto *sqr, Point *mouse);
};


Punto::Punto()
{
	pts[0] = Point(0.5, 0.5);	
}

void Punto::draw(Punto*sqr)
{
	int i;
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for ( i = 0; i < 1; i++)
	{
		glVertex2f(sqr->pts[i].x, sqr->pts[i].y);
	}
	glEnd();	
}

void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
/*
	srand((unsigned)time(NULL));

	int max = (rand() % 5);

	int num[2] = { 3,4 };
	int l = rand() % (2);
*/
	glPointSize(6.0);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POINTS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();

	/*for (int i = 0; i < num[l]; i++)
	{
	
		p1 = (float)(rand() % 101) / 100;
		p2 = (float)(rand() % 101) / 100;
		glBegin(GL_POINTS);
		glVertex3f(p1, p2, 0.0f);
		glEnd();
		cout <<" " <<p1 << " " << p2<<endl;
		cout << i;
	}*/
	
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
	glutReshapeFunc(resize);
	
	//glutMotionFunc(drag);

	initGL();
	glutMainLoop();
	return 0;
}