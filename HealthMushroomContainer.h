#ifndef HEALTHMUSHROOMCONTAINER_H
#define HEALTHMUSHROOMCONTAINER_H

#include "rsdl.hpp"
#include "ObjectsBorders.h"


class HealthMushroomContainer
{
public:
	HealthMushroomContainer(int input_x, int input_y);
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
