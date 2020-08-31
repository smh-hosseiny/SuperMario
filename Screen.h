#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <memory>
#include "rsdl.hpp"

class Game;

using namespace std;


class Screen
{

public:

	void handle_event(Game* game, char action);

   float set_camera_start(const int &offset);

   void display_lose_game();

   void display_win_game();

   float set_camera_end(const int &offset);
	
   void handle_events(Game* game);
   
   void clear_screen();

   void play_sound();
   
   static Screen* get_instance();

   static Window win;

   void get_map();

   void set_map(Game* game);

private:
	Event lastEvent;
	Screen();
	static Screen* the_instance;
} ;


#endif
