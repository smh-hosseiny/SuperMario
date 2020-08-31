#include<vector>
#include <iostream>
#include<memory>
#include<fstream>


#include "KoopaTroopa.h"
#include "rsdl.hpp"



using namespace std;
 
KoopaTroopa :: KoopaTroopa(int input_x, int input_y)
{
    x = 20 *input_x;
    y = 20 *input_y;
}

Point KoopaTroopa :: get_position()
{
    return Point(x, y);
}
    
string KoopaTroopa :: get_file_name()
{
	return file_name;
}

Point KoopaTroopa :: move()
{
    number_of_move_picture < 1 ? number_of_move_picture++ : number_of_move_picture=0;
    file_name = walking[number_of_move_picture];
    x -= v_x;
    return Point(x, y);
}    


void KoopaTroopa :: turn()
{
    v_x = -v_x;
}

void KoopaTroopa :: draw(Window &win, int offset, int map_size)
{
    move();
	win.draw_img(get_file_name(), Rectangle(x-20 + offset, win.get_height()-(20*map_size-y), 20, 20));
}

ObjectsBorders KoopaTroopa :: get_borders()
{
    return ObjectsBorders(x-40, y, x-20, y,x-20, y-20, x-40, y-20);
}

void KoopaTroopa :: fall_down()
{
    y += v_y;
}
