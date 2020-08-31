#ifndef MAPDESIGNER_H
#define MAPDESIGNER_H

#include <vector>
#include <memory>
#include "rsdl.hpp"
#include "Game.h"

using namespace std;

class MapDesigner
{

public:	
		
	void set_icon(char input, int number_of_char_inline, int number_of_line, Game* game);

	void  handle_input_inline(const string& input, int number_of_line, Game* game);

	int handle_input(const vector<string> &input, Game* game);

	MapDesigner();
	

private:
		
} ;


#endif
