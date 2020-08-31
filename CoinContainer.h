#ifndef COINCONTAINER_H
#define COINCONTAINER_H

#include "rsdl.hpp"
#include "ObjectsBorders.h"


class CoinContainer
{
public:
	CoinContainer(int input_x, int input_y);
	Point get_position();
	std :: string get_file_name();
	void draw(Window &win, int offset, int map_size);
	ObjectsBorders get_borders();

private:
	std :: string file_name;
	float x;
	float y;
} ;


#endif
