#pragma once
#include <glut.h>
#ifndef PUNTO2D_H_INCLUDED
#define PUNTO2D_H_INCLUDED
class Punto2D {
public:
	float x, y, z;

	bool selectPoint;

	static float size;

	Punto2D()
	{
	}


	Punto2D(float _x, float _y)
	{
		x = _x;
		y = _y;
		z = 0.0f;
	}

	void init() {
		x = 0;
		y = 0;
		z = 0;
	}

	void setxy(float x2, float y2) {
		x = x2;
		y = y2;
		z = 0;
	}

	const Punto2D & operator=(const Punto2D &rPunto2D) {
		x = rPunto2D.x;
		y = rPunto2D.y;
		z = rPunto2D.z;
		return *this;
	}

	void SelectPoint()
	{
		selectPoint = true;
	}

	void UnselectPoint()
	{
		selectPoint = false;
	}

	void drawPoint(void)
	{
		glPointSize(size);
		glBegin(GL_POINTS);
		glVertex3f(x, y, 0.0);
		glEnd();
	}
};
#endif
