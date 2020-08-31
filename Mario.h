#ifndef MARIO_H
#define MARIO_H

#include <vector>
#include "rsdl.hpp"
#include "ObjectsBorders.h"

class Screen;



class Mario
{
public:
	Mario(int input_x, int input_y);
	void draw(Window &win, int map_size, bool on_a_object, bool jump = 0);
	void update(bool on_a_object, bool jump =0);
	float move_right(Window &win);
	float move_left(Window &win);
	Point get_position();
	void jump(bool on_a_object);
	std :: string get_file_name();
	ObjectsBorders get_virtual_position();
	int get_initial_height();
	bool check_gravity(int max_height_of_block, int mario_height);

	void fall_down();
	bool moving_right();
	void cant_move_left();
	void cant_move_right();

	bool is_in_range(int input, int border, char comparator_sign);
	bool is_greater_than(int input, int border);
	bool is_less_than(int input, int border);
 
private:
	int initial_height;
	std :: string file_name;
	double v_x=0;
	double v_y;
	int a_y = 5;
	float x;
	float y;
	int virtual_x;
	bool right_permission = true;
	bool left_permission = true;

	const std :: string standing = "assets/sprites/mario/normal/standing-right.png";

	const std :: vector<std :: string> walking_right = {"assets/sprites/mario/normal/walking-right-1.png", 
			"assets/sprites/mario/normal/walking-right-2.png", "assets/sprites/mario/normal/walking-right-3.png"};

	const std :: vector<std :: string> walking_left = {"assets/sprites/mario/normal/walking-left-1.png", 
			"assets/sprites/mario/normal/walking-left-2.png", "assets/sprites/mario/normal/walking-left-3.png"};

	const std :: string jumping_right = "assets/sprites/mario/normal/jumping-right.png";
} ;

#endif
