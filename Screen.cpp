#include "Screen.h"
#include "rsdl.hpp"
#include "Mario.h"
#include "Game.h"

#include <memory>

#define START_POINT 0
#define END_POINT 800

using namespace std;


Window Screen::win = Window(800, 640);

Screen* Screen :: the_instance=0;

Screen* Screen :: get_instance()
{
	if(the_instance == 0)
		the_instance = new Screen();
	return the_instance;
}


float Screen :: set_camera_start(const int &offset)
{
	float starting_point = START_POINT;
	starting_point += 0.15 * abs(offset);
	return starting_point;
}

void Screen :: play_sound()
{
	win.play_music("assets/sounds/Super Mario Bros. theme music.mp3");
}


float Screen :: set_camera_end(const int &offset)
{
	float end_point = END_POINT;
	end_point += 0.15 * abs(offset); 
	return end_point;
}

void Screen :: set_map(Game* game)
{
	float offset = game -> get_offset();

	win.draw_img("assets/background_image.png", Rectangle(0, 0, 800, 640),
		 Rectangle(set_camera_start(offset), 200, set_camera_end(offset), 840));

	win.show_text("Lives : 1   Coins : 0", Point(300, 25), RED, "OpenSans.ttf", 25);
	game -> update_map();
}


void Screen :: clear_screen()
{
	win.clear();
}

void Screen :: handle_events(Game* game)
{
	while(win.has_pending_event()) 
	{
	    Event event = win.poll_for_event();
	    switch(event.get_type()) 
	    {
	    	case Event::QUIT :
				exit(0);

		    case Event::KEY_PRESS :
				if(event.get_pressed_key() == 'd')
				{
					game -> move_mario_to_right(Screen :: win);
				};	

				if(event.get_pressed_key() == 'a')
				{
					game -> move_mario_to_left(Screen :: win);
				};	

				if(event.get_pressed_key() == 'w')
				{
					game -> jump();
				};	
				
	    	break;


		    case Event::KEY_RELEASE :
					win.poll_for_event();
	    	break;
	    }
	}
}


void Screen :: display_lose_game()
{
	win.show_text("You Lose", Point(300, 100), RED, "OpenSans.ttf", 50);
	win.stop_music();
	win.play_music("assets/sounds/sound_effects/mario-death.wav");
	win.update_screen();
	delay(3000);
}


void Screen :: display_win_game()
{
	win.show_text("You Win", Point(300, 100), RED, "OpenSans.ttf", 50);
	win.stop_music();
	win.play_music("assets/sounds/sound_effects/level-clear.wav");
	win.update_screen();
	delay(5000);
}

Screen :: Screen()	 
{}


void Screen :: get_map()
{
    win.update_screen();
    delay(40);	
}


