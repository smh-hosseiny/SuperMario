#include "rsdl.hpp"
#include <map>
#include <algorithm>
#include <memory>
#include "Mario.h"
#include "Gomba.h"
#include "Block.h"
#include "Game.h"
#include "Screen.h"

using namespace std;
Game* game = Game :: get_instance();


Game* Game :: get_instance()
	{
		if(the_instance == 0)
			the_instance = new Game();
		return the_instance;
	}


Game :: Game()
{
	this->offset = 0.0;
}

void Game :: check_if_loses()
{
	if(mario -> get_virtual_position().get_bottom_left()[1] > 400)
	{
		Screen :: get_instance() -> display_lose_game();
		exit(1);
	}
}


void Game :: check_if_wins()
{
	if(mario -> get_virtual_position().get_bottom_right()[0] > 
				flag-> get_borders().get_bottom_left()[0])
	{
		Screen :: get_instance() -> display_win_game();
		exit(1);
	}
}

float Game :: get_offset()
{
	return this -> offset;	
}

bool Game :: move_mario_to_right(Window &win)
{
	this->offset += mario -> move_right(Screen :: win);
	return true;
}

bool Game :: move_mario_to_left(Window &win)
{
	this->offset += mario -> move_left(Screen :: win);
	return true;
}


bool Game :: jump()
{	
	mario->draw(Screen::win, get_map_size(), apply_force(make_shared<ObjectsBorders>(ObjectsBorders(mario -> get_virtual_position()))), 1);
	return true;
}


void Game :: move_goomba()
{
	for(auto &elem : goomba)
		elem -> move();
}


void Game :: move_koopa_troopa()
{
	for(auto &elem : koopa_troopa)
		elem -> move();
}


void Game :: draw_mario()
{
	mario->draw(Screen::win, get_map_size(), apply_force(make_shared<ObjectsBorders>(ObjectsBorders(mario -> get_virtual_position()))));
}

void Game :: draw_goomba()
{
	for(auto &elem : goomba)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game :: draw_koopa_troopa()
{
	for(auto &elem : koopa_troopa)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_blocks()
{
	for(auto &elem : blocks)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_pipes()
{
	for(auto &elem : pipe)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_flags()
{
	flag -> draw(Screen :: win, this->offset, get_map_size());
}


void Game ::  draw_simple_blocks()
{
	for(auto &elem : simple_blocks)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_simple_bricks()
{
	for(auto &elem : simple_bricks)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_coin_container()
{
	for(auto &elem : coin_container)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_red_mushroom_container()
{
	for(auto &elem : red_mushroom_container)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

void Game ::  draw_health_mushroom_container()
{
	for(auto &elem : health_mushroom_container)
		elem -> draw(Screen :: win, this->offset, get_map_size());
}

///////////////////////////////////////////////////////////////////////////////////

vector<shared_ptr<ObjectsBorders> > Game ::  get_block_positions()
{
	vector<shared_ptr<ObjectsBorders> > block_borders;
	for(auto &elem : blocks)
	{
		block_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return block_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_red_mushroom_positions()
{
	vector<shared_ptr<ObjectsBorders> > red_mushroom_container_borders;
	for(auto &elem : red_mushroom_container)
	{
		red_mushroom_container_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return red_mushroom_container_borders;
}



vector<shared_ptr<ObjectsBorders> > Game ::  get_pipe_positions()
{
	vector<shared_ptr<ObjectsBorders> > pipe_borders;
	for(auto &elem : pipe)
	{
		pipe_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return pipe_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_simple_block_positions()
{
	vector<shared_ptr<ObjectsBorders> > simple_block_borders;
	for(auto &elem : simple_blocks)
	{
		simple_block_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return simple_block_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_brick_positions()
{
	vector<shared_ptr<ObjectsBorders> > brick_borders;
	for(auto &elem : simple_bricks)
	{
		brick_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return brick_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_health_mushroom_positions()
{
	vector<shared_ptr<ObjectsBorders> > health_mushroom_container_borders;
	for(auto &elem : health_mushroom_container)
	{
		health_mushroom_container_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return health_mushroom_container_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_coin_container_positions()
{
	vector<shared_ptr<ObjectsBorders> > coin_container_borders;
	for(auto &elem : coin_container)
	{
		coin_container_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return coin_container_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_flag_positions()
{
	vector<shared_ptr<ObjectsBorders> > flag_borders;
	flag_borders.push_back(make_shared<ObjectsBorders>(flag -> get_borders()));
	return flag_borders;
}

vector<shared_ptr<ObjectsBorders> > Game ::  get_goomba_positions()
{
	vector<shared_ptr<ObjectsBorders> > goomba_borders;
	for(auto &elem : goomba)
	{
		goomba_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
	return goomba_borders;
}


vector<shared_ptr<ObjectsBorders> > Game ::  get_troopa_positions()
{
	vector<shared_ptr<ObjectsBorders> > troopa_borders;
	for(auto &elem : koopa_troopa)
	{
		troopa_borders.push_back(make_shared<ObjectsBorders>(elem -> get_borders()));
	}
		
	return troopa_borders;
}




void Game :: initialize(int size_of_map)
{
	set_pipes();
	set_flags();
	this -> map_size = size_of_map;
	objects_borders.push_back(get_block_positions());
	objects_borders.push_back(get_red_mushroom_positions());
	objects_borders.push_back(get_pipe_positions());
	objects_borders.push_back(get_simple_block_positions());
	objects_borders.push_back(get_brick_positions());
	objects_borders.push_back(get_health_mushroom_positions());
	objects_borders.push_back(get_coin_container_positions());
	objects_borders.push_back(get_flag_positions());
	objects_borders.push_back(get_goomba_positions());
	objects_borders.push_back(get_troopa_positions()); 
}


vector<shared_ptr<ObjectsBorders> > Game :: update_goomba()
{
	objects_borders[8] = get_goomba_positions();
	return get_goomba_positions();	
}


vector<shared_ptr<ObjectsBorders> > Game :: update_troopa()
{
	objects_borders[9] = get_troopa_positions();	
	return get_troopa_positions();
}

void Game :: update_initialization()
{
	update_goomba();
	update_troopa();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Game :: update_map()
{
	update_initialization();
	draw_blocks();
	draw_simple_blocks();
	draw_simple_bricks();
	draw_coin_container();
	draw_red_mushroom_container();
	draw_health_mushroom_container();
	move_goomba();
	draw_goomba();
	draw_koopa_troopa();
	draw_pipes();
	draw_flags();
	draw_mario();
	apply_gravity();
	check_horizontal_collision(make_shared<ObjectsBorders>(ObjectsBorders(mario -> get_virtual_position())));
	check_if_loses();
	check_if_wins();
}


shared_ptr<Mario> Game :: get_mario()
{
	return mario;
}

void Game :: set_mario(int x, int y)
{
	mario = make_shared<Mario>(Mario(x,y));
}

void Game :: set_blocks(int x, int y)
{
	blocks.push_back(make_shared<Block>(Block(x,y)));
}

void Game :: set_simple_blocks(int x, int y)
{
	simple_blocks.push_back(make_shared<SimpleBlock>(SimpleBlock(x,y)));
}

void Game :: set_simple_bricks(int x, int y)
{
	simple_bricks.push_back(make_shared<SimpleBrick>(SimpleBrick(x,y)));
}

void Game :: set_coin_container(int x, int y)
{
	coin_container.push_back(make_shared<CoinContainer>(CoinContainer(x,y)));
}

void Game :: set_red_mushroom_container(int x, int y)
{
	red_mushroom_container.push_back(make_shared<RedMushroomContainer>(RedMushroomContainer(x,y)));
}

void Game :: set_health_mushroom_container(int x, int y)
{
	health_mushroom_container.push_back(make_shared<HealthMushroomContainer>(HealthMushroomContainer(x,y)));
}

void Game :: set_goomba(int x, int y)
{
	goomba.push_back(make_shared<Gomba>(Gomba(x,y)));
}

void Game :: set_koopa_troopa(int x, int y)
{
	koopa_troopa.push_back(make_shared<KoopaTroopa>(KoopaTroopa(x,y)));
}

void Game :: store_pipes(int x, int y)
{
	pipe_positions.push_back(Point(x, y));
}


void Game :: store_flags(int x, int y)
{
	flag_positions.push_back(Point(x, y));
}



void Game :: set_pipes()
{
	map<int, vector<int>> positions;

	for (int i=0; i<pipe_positions.size(); i++)
	{
		positions[pipe_positions[i].x].push_back(pipe_positions[i].y);
	}

	for(auto it = positions.begin(); it != positions.end(); it++, it++)
	{
		pipe.push_back(make_shared<Pipe>(Pipe(it->first, it->second)));
	}
}


void Game :: set_flags()
{
	flag = make_shared<Flag>(Flag(flag_positions));
}


bool Game :: check_horizontal_distance(shared_ptr<ObjectsBorders> object_1, shared_ptr<ObjectsBorders> object_2)
{
	return (((object_1 -> get_bottom_right()[0] <= object_2 -> get_top_right()[0]) && 
		(object_1 -> get_bottom_right()[0] > object_2 -> get_top_left()[0])) ||
		((object_1 -> get_bottom_left()[0] < object_2 -> get_top_right()[0]) && 
			(object_1 -> get_bottom_left()[0] >=  object_2 -> get_top_left()[0])));
}


bool Game :: check_vertical_positions(shared_ptr<ObjectsBorders> object_1, shared_ptr<ObjectsBorders> object_2)
{
	return (abs(object_1->get_bottom_left()[1] - object_2-> get_top_left()[1]) < 5 && 
			object_1->get_bottom_left()[1] - object_2-> get_top_left()[1] <=0) ;
}


bool Game :: is_on_object(shared_ptr<ObjectsBorders> mario_borders, shared_ptr<ObjectsBorders> objects)
{
	if(check_horizontal_distance(mario_borders, objects)) 
	{
		if(check_vertical_positions(mario_borders, objects))
			return true;
	}
	return false;
}


bool Game :: apply_force(shared_ptr<ObjectsBorders> object)
{
	for(auto &elements : objects_borders)
	{
		for(auto &elem : elements)
		{
			if(is_on_object(object, elem))
			{
				return true;
			}
		}
	}
	return false;
}



void Game :: apply_gravity()
{
	if(!apply_force(make_shared<ObjectsBorders>(ObjectsBorders(mario -> get_virtual_position()))))
	{
		mario -> fall_down();
	}

	for(int i=0; i<update_goomba().size(); i++)
	{
		if(!apply_force(update_goomba()[i]))
			goomba[i] -> fall_down();
	}

	for(int i=0; i<update_troopa().size(); i++)
	{
		if(!apply_force(update_troopa()[i]))
			koopa_troopa[i] -> fall_down();
	}

}



int Game :: get_map_size()
{
	return map_size;
}


bool Game :: check_vertical_distance(shared_ptr<ObjectsBorders> object_1, shared_ptr<ObjectsBorders> object_2)
{
	return((object_1 -> get_top_right()[1] >=  object_2->get_top_left()[1]  &&
			 object_1 -> get_top_right()[1] <= object_2->get_bottom_left()[1]) ||
			(abs(object_1 -> get_top_right()[1] -  object_2->get_top_left()[1]) < 5  &&
			 abs(object_1 -> get_bottom_right()[1] == object_2->get_bottom_left()[1])<5));
}

bool Game :: is_horizontal_collision(shared_ptr<ObjectsBorders> object_1, shared_ptr<ObjectsBorders> object_2)
{
	if(check_horizontal_distance(object_1, object_2))
	{
		if(check_vertical_distance(object_1, object_2))
			return true;
	}
	return false;
}


bool Game :: is_collision(shared_ptr<ObjectsBorders> mario_borders)
{
	for(auto &elements : objects_borders)
	{
		for(auto &elem : elements) 
		{
			if(is_horizontal_collision(mario_borders, elem))
				return true;
		}
	}
	return false;
}


void Game :: check_horizontal_collision(shared_ptr<ObjectsBorders> object)
{
	if(is_collision(object))
	{
		if(move_mario_to_right(Screen :: win))
			mario -> cant_move_right();

		if(move_mario_to_left(Screen :: win))
			mario -> cant_move_left();
	}	
}