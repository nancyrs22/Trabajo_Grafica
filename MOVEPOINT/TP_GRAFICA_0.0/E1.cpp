#include <iostream>
#include <glut.h>
#include <time.h>
using namespace std;

/*GLfloat p1;
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
*/

struct Points
{
	float x, y;
	Points() { x = 0.0; y = 0.0; }

	Points(float _x, float _y) : x(_x), y(_y){}
};

class Punto
{
public:
	Points pts[1];
	Punto();

	void draw(Punto *sqr);
	Points mouse(int x, int y);
	Punto* drag(Punto *sqr, Points* mouse);
};

Punto::Punto()
{
	pts[0] = Points(0.5, 0.5);
};

void Punto::draw(Punto * sqr)
{
	int i;
	glPointSize(6.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for ( i = 0; i < 1; i++)
	{
		glVertex2f(sqr->pts[i].x, sqr->pts[i].y);
	}
	glEnd();
}

Points Punto::mouse(int x, int y)
{
	int windowWidth = 700, windowHeight = 700;
	return Points(float(x) / windowWidth, 1.0 - float(y) / windowHeight);
}

Punto* Punto::drag(Punto *sqr, Points *mouse)
{
	sqr->pts[0].x = mouse->x - 0.01;
	sqr->pts[0].y = mouse->y - 0.01;

	sqr->pts[0].x = mouse->x + 0.01;
	sqr->pts[0].y = mouse->y - 0.01;

	sqr->pts[0].x = mouse->x + 0.01;
	sqr->pts[0].y = mouse->y + 0.01;

	sqr->pts[0].x = mouse->x - 0.01;
	sqr->pts[0].y = mouse->y + 0.01;

	return sqr;
}

Punto* sqr = new Punto;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	sqr->draw(sqr);
	glFlush();
}

void drag(int x, int y)
{
	Points mousePT = sqr->mouse(x, y);
	Points* mouse = &mousePT;

	if (mouse -> x >= sqr->pts[0].x-0.05 || mouse->x <= sqr->pts[0].x+0.05 && mouse->y >= sqr->pts[0].y-0.05 || mouse->x <= sqr->pts[0].y + 0.05)
	{
		sqr->drag(sqr, mouse);
		glutPostRedisplay();
	}
}

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv)
{
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Move Box");

	glutMotionFunc(drag);

	Initialize();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}