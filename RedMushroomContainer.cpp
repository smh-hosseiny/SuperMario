#include<vector>
#include <iostream>
#include<memory>
#include<fstream>


#include "RedMushroomContainer.h"
#include "rsdl.hpp"

#define g 10

using namespace std;
 
RedMushroomContainer :: RedMushroomContainer(int input_x, int input_y)
{
	x = 20 * input_x;
	y = 20 * input_y;
	file_name = "assets/sprites/objects/bricks_blocks/question-2.png";
}

Point RedMushroomContainer :: get_position()
{
    return Point(x, y);
}

string RedMushroomContainer :: get_file_name()
{
    return file_name;
}

void RedMushroomContainer :: draw(Window &win, int offset, int map_size)
{
    //cout << 32*get_position().x << " " << win.get_height()/3+ 32*get_position().y << endl;
    win.draw_img(get_file_name(), Rectangle(x-20 + offset, win.get_height()-(20*map_size-y), 20, 20));
}

ObjectsBorders RedMushroomContainer :: get_borders()
{
	return ObjectsBorders(x-40, y, x-20, y,x-20, y-20, x-40, y-20);
}