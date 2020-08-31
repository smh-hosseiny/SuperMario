#include "rsdl.hpp"
#include "Mario.h"
#include "Game.h"
#include "MapDesigner.h"

#include <memory>

using namespace std;

MapDesigner :: MapDesigner()
{}

void MapDesigner :: set_icon(char input, int number_of_char_inline, int number_of_line, Game* game)
{ 	
	switch(input)	
	{
		case '#' :
			game->set_blocks(number_of_char_inline, number_of_line);
		break;		


		case '@' :
			game->set_simple_blocks(number_of_char_inline, number_of_line);
		break;		


		case 'b' :
			game->set_simple_bricks(number_of_char_inline, number_of_line);
		break;		


		case '?' :
			game->set_coin_container(number_of_char_inline, number_of_line);
		break;		


		case 'm' :
			game->set_red_mushroom_container(number_of_char_inline, number_of_line);
		break;		


		case 'h' :
			game->set_health_mushroom_container(number_of_char_inline, number_of_line);
		break;		


		case 'M' :
			game->set_mario(number_of_char_inline, number_of_line);
		break;		


		case 'l' :
			game->set_goomba(number_of_char_inline, number_of_line);
		break;		


		case 'k' :
			game->set_koopa_troopa(number_of_char_inline, number_of_line);
		break;		


		case '|' :
			game->store_pipes(number_of_char_inline, number_of_line);
		break;		


		case 'f' :
			game->store_flags(number_of_char_inline, number_of_line);
		break;		
	}
}

void MapDesigner :: handle_input_inline(const string& input, int number_of_line, Game* game)
{
	for(int i=0; i<input.length(); i++)
		set_icon(input[i], i+1, number_of_line, game);
}


int MapDesigner :: handle_input(const vector<string> &input, Game* game)
{
    for(int i=input.size()-1; i>=0; i--)
    {
    	handle_input_inline(input[i], i, game);
    }

    return input.size();
}
