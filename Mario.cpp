#include<vector>
#include <iostream>
#include<memory>
#include<fstream>
#include <algorithm>


#include "Mario.h"
#include "rsdl.hpp"


using namespace std;
 
int number_of_move_right_picture=0, number_of_move_left_picture=0;

 Mario :: Mario(int input_x, int input_y)
{
	x = 20*input_x;
	virtual_x = 20 * input_x;
	y = 20*input_y;
	this -> file_name = standing;
}

void Mario :: cant_move_right()
{
	right_permission = false;
}

void Mario :: cant_move_left()
{
	left_permission = false;
}

string Mario :: get_file_name()
{
	return file_name;
}

Point Mario :: get_position()
{
    return Point(x, y);
}
    

void Mario :: update(bool on_a_object, bool jump)
{
	right_permission = true;
	left_permission = true;
	if(on_a_object && !jump)
	{
		v_y = a_y = 0;
	}

	else if ( on_a_object && jump )
	{
		file_name = jumping_right;
		v_y = -100;
		y += v_y;
		v_y += 5;
		virtual_x += v_x;
	}
}


void Mario :: draw(Window &win, int map_size, bool on_a_object, bool jump)
{	
	update(on_a_object, jump);
	win.draw_img(get_file_name(), Rectangle(x, win.get_height()-(20*map_size)+y, 20, 20));
}


bool Mario :: is_less_than(int input, int border)
{
	return input <= border;
}


bool Mario :: is_greater_than(int input, int border)
{
	return input > border;
}


bool Mario :: is_in_range(int input, int border, char comparator_sign)
{
	switch(comparator_sign)
	{
		case '<':
			return is_less_than(input, border);

		case '>':
			return is_greater_than(input, border);
	}
}


float Mario :: move_right(Window &win)
{
	number_of_move_right_picture < 2 ? number_of_move_right_picture++ : number_of_move_right_picture=0;

	file_name = walking_right[number_of_move_right_picture];
	if(is_in_range(x,  win.get_width()*0.5, '<'))
	{
		if(right_permission)
		{
			x += 5;
			virtual_x += 5;
		}
		return 0;
	}

	else
	{
		if(right_permission)
		{
			virtual_x += 5;
			return -5;
		}
	}
	
}

ObjectsBorders Mario :: get_virtual_position()
{
	return ObjectsBorders(virtual_x-20, y, virtual_x, y,virtual_x, y+20, virtual_x-20, y+20);
}


float Mario :: move_left(Window &win)
{
	file_name = walking_left[number_of_move_left_picture];
	number_of_move_left_picture < 2 ? number_of_move_left_picture++ : number_of_move_left_picture=0;

	if(is_in_range(x,  win.get_width()*0.01, '>'))
	{
		if(left_permission)
		{
			x -= 5;
			virtual_x -= 5;
		}
		return 0;
	}

	if(is_in_range(x,  win.get_width()*0.01, '<'))
		return 0;	
}

void Mario :: fall_down()
{
	v_y = 0;
	v_y += 5;
	y += v_y;
}

bool Mario :: moving_right()
{
	return (find(walking_right.begin(), walking_right.end(), this -> file_name) != walking_right.end());
}

