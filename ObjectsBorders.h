#ifndef OBJECTSBORDERS_H
#define OBJECTSBORDERS_H
#include "rsdl.hpp"
#include <vector>


class ObjectsBorders
{
public:
	ObjectsBorders(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4);
	std :: vector<int> get_top_right();
	std :: vector<int> get_bottom_right();
	std :: vector<int> get_top_left();
	std :: vector<int> get_bottom_left();

	void set_bottom_left(int x, int y);
	void set_top_right(int x, int y);
	void set_bottom_right(int x, int y);
	void set_top_left(int x, int y);

	int get_size();
	
private:
	std :: vector<int> top_right;
	std :: vector<int> bottom_right;
	std :: vector<int> top_left;
	std :: vector<int> bottom_left;
} ;


#endif
