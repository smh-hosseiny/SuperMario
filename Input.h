#ifndef INPUT_H
#define INPUT_H

#include<vector>

class Input
{
public:
	Input();
	std :: vector<std :: string> read_input(char *argv[]);
	void handle_input(const std :: vector<std :: string> &input);
	void show_line(const std :: string& input);
	void show_icon(char input, int number);

} ;


#endif
