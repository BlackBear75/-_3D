#pragma once

#include"gl/glut.h"
#include <cmath>

class Move
{
public:
	void Move_Camera(float& zAlfa, float& xAlfa);
	void MoveHero(float& zAlfa, float& xAlfa, FLOAT& x, FLOAT& y);
};

