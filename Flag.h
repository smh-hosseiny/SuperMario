#ifndef FLAG_H
#define FLAG_H

#include<vector>
#include "rsdl.hpp"
#include "Screen.h"
#include "ObjectsBorders.h"



class Flag 
{
public:
	Flag(vector<Point> flag_position);
	void draw(Window &win, int offset, int map_size);
	void draw_head(Window &win, int offset, int map_size);
	void draw_body(Window &win, int offset, int map_size);
	void draw(string part_name, Window &win, int offset, int x, int y, int map_size);
	ObjectsBorders get_borders();
	
private:
	float x_position;;
	std :: vector<int> heights;
	const string head = "assets/sprites/objects/flag/head.png";
	const string body = "assets/sprites/objects/flag/body.png";
} ;


#endif
