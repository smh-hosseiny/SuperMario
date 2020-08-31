#include<vector>
#include <iostream>
#include<memory>
#include<fstream>


#include "Pipe.h"
#include "rsdl.hpp"



using namespace std;

Pipe :: Pipe(int x_1, vector<int> y_1)
{
	left_x = 20* x_1;
	for(auto &elem : y_1)
		left_heights.push_back(20*elem);
}


void Pipe :: draw(string part_name, Window &win, int offset, int x, int y, int map_size)
{
	win.draw_img(part_name, Rectangle((x+offset-20), 
				win.get_height()-(20*map_size-left_heights[y]), 20, 20));
}


void Pipe :: draw_left_body(Window &win, int offset, int i, int map_size)
{
	draw(left, Screen :: win, offset, left_x, i, map_size);
}


void Pipe :: draw_right_body(Window &win, int offset, int i, int map_size)
{
	draw(right, Screen :: win, offset, left_x+20, i, map_size);
}


void Pipe :: draw_body(Window &win, int offset, int map_size)
{
	for(int i=0; i<left_heights.size()-1; i++)
		{
			draw_left_body(Screen :: win, offset, i, map_size);
			draw_right_body(Screen :: win, offset, i, map_size);
		}
}


void Pipe :: draw_right_head(Window &win, int offset, int map_size)
{
	draw(head_right, Screen :: win, offset, left_x+20, left_heights.size()-1, map_size);
}


void Pipe :: draw_left_head(Window &win, int offset, int map_size)
{
	draw(head_left, Screen :: win, offset, left_x, left_heights.size()-1, map_size);
}


void Pipe :: draw_head(Window &win, int offset, int map_size)
{
	draw_right_head(Screen :: win, offset, map_size);
	draw_left_head(Screen :: win, offset, map_size);
}


void Pipe :: draw(Window &win, int offset, int map_size)
{
	draw_body(Screen :: win, offset, map_size);
	draw_head(Screen :: win, offset, map_size);
}

ObjectsBorders Pipe :: get_borders()
{
	return ObjectsBorders(left_x-40, left_heights[left_heights.size()-1], left_x, left_heights[left_heights.size()-1], 
		left_x, left_heights[0], left_x-40, left_heights[0]);	
}

vector<int> Pipe :: get_pipe_height()
{
	return left_heights;
}