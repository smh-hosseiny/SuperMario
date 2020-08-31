#ifndef GOMBA_H
#define GOMBA_H

#include<vector>
#include "rsdl.hpp"
#include "ObjectsBorders.h"

class Gomba
{
public:
	Gomba(int input_x, int input_y);
	Point get_position();
	Point move();
	std :: string get_file_name();
	void draw(Window &win, int offset, int map_size);
	void turn();
	ObjectsBorders get_borders();
	void fall_down();

private:
	std :: vector<std :: string > walking = {"assets/sprites/enemies/little_goomba/walking-1.png",
											"assets/sprites/enemies/little_goomba/walking-2.png"};
	std :: string file_name;
	double v_x = 1;
	double v_y = 1;
	float x;
	float y;
	int number_of_move_picture =0;
} ;


#endif
