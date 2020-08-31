#ifndef SIMPLEBLOCK_H
#define SIMPLEBLOCK_H

#include "rsdl.hpp"
#include "ObjectsBorders.h"

class SimpleBlock
{
public:
	SimpleBlock(int input_x, int input_y);
	Point get_position();
	std :: string get_file_name();
	void draw(Window &win, int offset, int map_size);
	ObjectsBorders get_borders();

private:
	float x;
	float y;
	std :: string file_name;
} ;


#endif
