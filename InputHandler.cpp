#include<vector>
#include <iostream>
#include<memory>


#include "Game.h"
#include "rsdl.hpp"
#include "InputHandler.h"



using namespace std;

InputHandler* InputHandler :: the_instance=0;

InputHandler* InputHandler :: get_instance()
{
	if(the_instance == 0)
		the_instance = new InputHandler();
	return the_instance;
}

void InputHandler :: initialize_map(char *argv[])
{
	map = input -> read_input(argv);
	static int map_size = designer -> handle_input(map, Game :: get_instance());
	Game :: get_instance()-> initialize(map_size);
	play_music();
}


void InputHandler :: play_music()
{
	Screen :: get_instance() -> play_sound();
}

InputHandler :: InputHandler()
{}
	
