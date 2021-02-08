#ifndef _FOOD_HEAD
#define _FOOD_HEAD
#include<iostream>
#include "wall.h"
#include<conio.h>
#include<Windows.h>
using namespace std;

class Food
{
public:
	Food(Wall& tmpwall);
	~Food();
	
	void setFood();

	int getFoodX();
	int getFoodY();

private:
	int foodX;
	int foodY;
	Wall& wall;
};
#endif




