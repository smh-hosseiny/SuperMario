#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>
#include <memory>
#include "rsdl.hpp"
#include "Input.h"
#include "Game.h"
#include "MapDesigner.h"
#include "Screen.h"

using namespace std;



class InputHandler
{

public:	
	void initialize_map(char *argv[]);
	static InputHandler* get_instance();
	void play_music();


private:
	shared_ptr<Input> input = make_shared<Input>(Input());
	vector<string> map;
	shared_ptr<MapDesigner> designer = make_shared<MapDesigner>(MapDesigner());
	static InputHandler* the_instance;
	InputHandler();


		
} ;


#endif
