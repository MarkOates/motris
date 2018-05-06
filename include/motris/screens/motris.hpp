#pragma once


#include <allegro5/allegro.h>
#include <framework/screen.hpp>


class Motris : public Screen
{
public:
   Motris();

   void update_scene();
   void render_scene();
   void process_event(ALLEGRO_EVENT &event) override;
};


