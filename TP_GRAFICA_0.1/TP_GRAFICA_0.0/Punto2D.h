#pragma once
#ifndef PUNTO2D_H_INCLUDED
#define PUNTO2D_H_INCLUDED
class Punto2D {
public:
	float x, y, z;
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
};
#endif
