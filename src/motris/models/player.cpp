

#include <motris/models/player.hpp>


int Player::last_player_id = 0;


Player::Player(std::string name, int player_num)
   : player_num(player_num)
   , player_id(last_player_id++)
   , name(name)
{
}


Player::~Player()
{
}


int Player::get_player_num()
{
   return player_num;
}


std::string Player::get_name()
{
   return name;
}


int Player::get_id()
{
   return player_id;
}


