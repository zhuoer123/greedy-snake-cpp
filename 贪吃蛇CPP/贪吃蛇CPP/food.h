#ifndef _FOOD_HEAD
#define _FOOD_HEAD
#include<iostream>
#include "wall.h"
using namespace std;

class Food
{
public:
	Food(Wall& tmpwall);
	~Food();
	void setFood();

private:
	int foodX;
	int foodY;
	Wall& wall;
};
#endif




