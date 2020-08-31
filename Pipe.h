#ifndef PIPE_H
#define PIPE_H

#include<vector>
#include "rsdl.hpp"
#include "Screen.h"
#include "ObjectsBorders.h"

class Pipe 
{
public:
	Pipe(int x_1, std :: vector<int> y_1);
	void draw(Window &win, int offset, int map_size);
	void draw_head(Window &win, int offset, int map_size);
	void draw_body(Window &win, int offset, int map_size);
	void draw(string part_name, Window &win, int offset, int x, int y, int map_size);
	void draw_left_body(Window &win, int offset, int i, int map_size);
	void draw_right_body(Window &win, int offset, int i, int map_size);
	void draw_right_head(Window &win, int offset, int map_size);
	void draw_left_head(Window &win, int offset, int map_size);
	ObjectsBorders get_borders();
	std :: vector<int> get_pipe_height();

private:
	int left_x;
	std :: vector<int> left_heights;
	const string left = "assets/sprites/objects/pipe/left.png";
	const string right = "assets/sprites/objects/pipe/right.png";
	const string head_left = "assets/sprites/objects/pipe/head-left.png";
	const string head_right = "assets/sprites/objects/pipe/head-right.png";
} ;


#endif
