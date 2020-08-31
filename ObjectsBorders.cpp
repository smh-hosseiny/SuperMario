#include "ObjectsBorders.h"
#include "rsdl.hpp"

using namespace std;
 
vector<int> ObjectsBorders :: get_top_right()
{
	return top_right;
}

vector<int> ObjectsBorders :: get_bottom_right()
{
	return bottom_right;
}

vector<int> ObjectsBorders :: get_top_left()
{
	return top_left;
}

vector<int> ObjectsBorders :: get_bottom_left()
{
	return bottom_left;
}

void ObjectsBorders :: set_bottom_left(int x, int y)
{
	bottom_left.push_back(x);
	bottom_left.push_back(y);	
}

void ObjectsBorders :: set_bottom_right(int x, int y)
{
	bottom_right.push_back(x);
	bottom_right.push_back(y);	
}

void ObjectsBorders :: set_top_right(int x, int y)
{
	top_right.push_back(x);
	top_right.push_back(y);	
}

void ObjectsBorders :: set_top_left(int x, int y)
{
	top_left.push_back(x);
	top_left.push_back(y);	
}


ObjectsBorders ::  ObjectsBorders(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4) 
{
	set_top_left(x_1, y_1);
	set_top_right(x_2, y_2);
	set_bottom_right(x_3, y_3);
	set_bottom_left(x_4, y_4);
}

int ObjectsBorders :: get_size()
{
	return top_left.size();
}