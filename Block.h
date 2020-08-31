#ifndef BLOCK_H
#define BLOCK_H

#include "rsdl.hpp"
#include "ObjectsBorders.h"

class Block
{
public:
	Block(int input_x, int input_y);
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
