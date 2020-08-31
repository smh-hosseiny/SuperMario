#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include<vector>
#include "rsdl.hpp"
#include "ObjectsBorders.h"

class KoopaTroopa
{
public:
	KoopaTroopa(int input_x, int input_y);
	Point get_position();
	Point move();
	void fall_down();
	std :: string get_file_name();
	void draw(Window &win, int offset, int map_size);
	void turn();
	ObjectsBorders get_borders();

private:
	std :: vector<std :: string > walking = {"assets/sprites/enemies/koopa_troopa/walking-left-1.png",
											"assets/sprites/enemies/koopa_troopa/walking-left-2.png"};
	std :: string file_name;
	double v_x=1;
	double v_y = 5;
	int number_of_move_picture =0;
	float x;
	float y;
} ;


#endif
