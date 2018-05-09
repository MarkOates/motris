#pragma once


#include <framework/screens/gamer_input_screen.hpp>
#include <framework/framework.hpp>
#include <framework/screen.hpp>


class Motris : public Screen
{
private:
   Framework &framework;
   GamerInputScreen gamer_input_screen;

public:
   Motris(Framework &framework);

   void process_event(ALLEGRO_EVENT &event) override;
};


