#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include "rsdl.hpp"
#include "Gomba.h"
#include "Block.h"
#include "SimpleBlock.h"
#include "SimpleBrick.h"
#include "CoinContainer.h"
#include "RedMushroomContainer.h"
#include "HealthMushroomContainer.h"
#include "KoopaTroopa.h"
#include "Pipe.h"
#include "Flag.h"
#include "Mario.h"
#include "Screen.h"
#include "ObjectsBorders.h"


using namespace std;

class Game
{
public:
	static Game* get_instance();
	void initialize(int size_of_map);

	void check_if_loses();
	void check_if_wins();
	void update_map();
	void update_initialization();
	vector<shared_ptr<ObjectsBorders> > update_goomba();
	vector<shared_ptr<ObjectsBorders> > update_troopa();
	void draw_mario();
	void draw_goomba();
	void draw_blocks();
	void draw_simple_blocks();
	void draw_simple_bricks();
	void draw_coin_container();
	void draw_red_mushroom_container();
	void draw_health_mushroom_container();
	void draw_koopa_troopa();
	void draw_pipes();
	void draw_flags();

	bool move_mario_to_right(Window &win);
	bool move_mario_to_left(Window &win);
	void move_goomba();
	void move_koopa_troopa();

	bool jump();
	void store_flags(int x, int y);
	void store_pipes(int x, int y);

	float get_offset();
	shared_ptr<Mario> get_mario();

	void apply_gravity();
	bool apply_force(shared_ptr<ObjectsBorders> object);
	bool is_on_object(shared_ptr<ObjectsBorders> mario_borders,
							shared_ptr<ObjectsBorders> objects);

	bool check_horizontal_distance(shared_ptr<ObjectsBorders> object_1,
							shared_ptr<ObjectsBorders> object_2);
	bool check_vertical_positions(shared_ptr<ObjectsBorders> object_1,
							 shared_ptr<ObjectsBorders> object_2);
	void check_horizontal_collision(shared_ptr<ObjectsBorders> object);

	bool is_horizontal_collision(shared_ptr<ObjectsBorders> object_1,
										 shared_ptr<ObjectsBorders> object_2);

	bool is_collision(shared_ptr<ObjectsBorders> mario_borders);

    bool check_vertical_distance(shared_ptr<ObjectsBorders> object_1, 
    							shared_ptr<ObjectsBorders> object_2);

	void set_mario(int x, int y);
	void set_blocks(int x, int y);
	void set_simple_blocks(int x, int y);
	void set_simple_bricks(int x, int y);
	void set_coin_container(int x, int y);
	void set_red_mushroom_container(int x, int y);
	void set_health_mushroom_container(int x, int y);
	void set_goomba(int x, int y);
	void set_koopa_troopa(int x, int y);
	void set_pipes();
	void set_flags();
	int get_map_size();

	vector<shared_ptr<ObjectsBorders> > get_block_positions();
	vector<shared_ptr<ObjectsBorders> > get_red_mushroom_positions();
	vector<shared_ptr<ObjectsBorders> > get_simple_block_positions();
	vector<shared_ptr<ObjectsBorders> > get_brick_positions();
	vector<shared_ptr<ObjectsBorders> > get_coin_container_positions();
	vector<shared_ptr<ObjectsBorders> > get_health_mushroom_positions();
	vector<shared_ptr<ObjectsBorders> > get_pipe_positions();
	vector<shared_ptr<ObjectsBorders> > get_flag_positions();
	vector<shared_ptr<ObjectsBorders> > get_goomba_positions();
	vector<shared_ptr<ObjectsBorders> > get_troopa_positions();

private:
	static Game* the_instance;
	Game();
	vector<Point> pipe_positions;
	vector<Point> flag_positions;

	float offset;
	int map_size;

	shared_ptr<Mario> mario;
	vector<shared_ptr<Gomba> > goomba;
	vector<shared_ptr<Block> > blocks;
	vector<shared_ptr<SimpleBlock> > simple_blocks;
	vector<shared_ptr<SimpleBrick> > simple_bricks;
	vector<shared_ptr<CoinContainer> > coin_container;
	vector<shared_ptr<RedMushroomContainer> > red_mushroom_container;
	vector<shared_ptr<HealthMushroomContainer> > health_mushroom_container;
	vector<shared_ptr<KoopaTroopa> > koopa_troopa;
	vector<shared_ptr<Pipe> > pipe;
	shared_ptr<Flag> flag;
	vector<vector<shared_ptr<ObjectsBorders> > > objects_borders;

} ;


#endif
