#pragma once


#include <string>


class Player
{
private:
   static int last_player_id;
   int player_id;
   std::string name;

public:
   Player(std::string name);
   ~Player();

   std::string get_name();
   int get_id();
};


