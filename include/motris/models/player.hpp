#pragma once


#include <string>


class Player
{
private:
   static int last_player_id;
   int player_num;
   int player_id;
   std::string name;

public:
   Player(std::string name, int player_num);
   ~Player();

   int get_player_num();
   std::string get_name();
   int get_id();
};


