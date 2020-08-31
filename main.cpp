#include <vector>
#include <memory>
#include "rsdl.hpp"
#include "Input.h" 
#include "Screen.h"
#include "Game.h"
#include "MapDesigner.h"
#include "InputHandler.h"

  
using namespace std;


Game* Game :: the_instance=0;
 

int main(int argc, char *argv[])
{
	InputHandler :: get_instance() -> initialize_map(argv);  
	
	while(true)
	{
		Screen :: get_instance() -> clear_screen();
		Screen :: get_instance() -> set_map(Game :: get_instance());
		Screen :: get_instance() -> handle_events(Game :: get_instance());
		Screen :: get_instance() -> get_map();
	}

}	
