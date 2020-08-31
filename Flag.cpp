#include<vector>
#include <iostream>
#include<memory>
#include<fstream>


#include "Flag.h"
#include "rsdl.hpp"



using namespace std;

Flag :: Flag(vector<Point> flag_position)
{
	x_position = 20*flag_position[0].x;
	heights = vector<int> (flag_position.size());
	for(int i=0; i<flag_position.size(); i++)
		heights[i] = 20*flag_position[i].y;
}


void Flag :: draw(string part_name, Window &win, int offset, int x, int y, int map_size)
{
	win.draw_img(part_name, Rectangle((x + offset-20), win.get_height()-(20*map_size-y), 20, 20));
}



void Flag :: draw_body(Window &win, int offset, int map_size)
{
	for(int i=0; i<heights.size()-1; i++)
		{
			draw(body, Screen :: win, offset, x_position, heights[i], map_size);
		}
}


void Flag :: draw_head(Window &win, int offset, int map_size)
{
	draw(head , Screen :: win, offset, x_position, heights[heights.size()-1], map_size);
}


void Flag :: draw(Window &win, int offset,int map_size)
{
	draw_body(Screen :: win, offset, map_size);
	draw_head(Screen :: win, offset, map_size);
}

ObjectsBorders Flag :: get_borders()
{
	return ObjectsBorders(x_position-40, heights[heights.size()-1], x_position-40,
	heights[heights.size()-1], x_position-40, heights[0]-20, x_position-40, heights[0]-20);
}
