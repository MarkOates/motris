#pragma once


#include <framework/screens/gamer_input_screen.hpp>
#include <framework/framework.hpp>
#include <framework/screen.hpp>
#include <motris/models/player.hpp>


class Motris : public Screen
{
private:
   Framework &framework;
   GamerInputScreen gamer_input_screen;
   Player player_1;
   Player player_2;
   Player player_3;
   Player player_4;

public:
   Motris(Framework &framework);

   void process_event(ALLEGRO_EVENT &event) override;
};


