#include<vector>
#include <iostream>
#include<memory>
#include<fstream>


#include "Block.h"
#include "rsdl.hpp"
#include "ObjectsBorders.h"

using namespace std;
 
Block :: Block(int input_x, int input_y)
{
	x = 20 * input_x;
	y = 20 * input_y;
   file_name = "assets/sprites/objects/bricks_blocks/clay.png";
}

Point Block :: get_position()
{
    return Point(x, y);
}


ObjectsBorders Block :: get_borders()
{
	return ObjectsBorders(x-40, y, x-20, y,x-20, y-20, x-40, y-20);
}


string Block :: get_file_name()
{
    return file_name;
}

void Block :: draw(Window &win, int offset, int map_size)
{
	win.draw_img(get_file_name(), Rectangle((x+offset-20 ), win.get_height()-(20*map_size-y), 20, 20));
}