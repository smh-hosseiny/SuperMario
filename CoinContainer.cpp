#include<vector>
#include <iostream>
#include<memory>
#include<fstream>


#include "CoinContainer.h"
#include "rsdl.hpp"

#define g 10

using namespace std;
 
CoinContainer :: CoinContainer(int input_x, int input_y)
{
	x = 20 * input_x;
	y = 20 * input_y;
	file_name = "assets/sprites/objects/bricks_blocks/question-1.png";
}

Point CoinContainer :: get_position()
{
    return Point(x, y);
}

string CoinContainer :: get_file_name()
{
    return file_name;
}

void CoinContainer :: draw(Window &win, int offset, int map_size)
{
    win.draw_img(get_file_name(), Rectangle(x-20 + offset, win.get_height()-(20*map_size-y), 20, 20));
}

ObjectsBorders CoinContainer :: get_borders()
{
	return ObjectsBorders(x-40, y, x-20, y,x-20, y-20, x-40, y-20);
}
