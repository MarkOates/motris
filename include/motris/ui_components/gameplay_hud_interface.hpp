#pragma once


#include <allegro5/allegro.h>


class GameplayHUDInterface
{
public:
   friend class PlayerGameplayGameboard;

   virtual void update_scene() = 0;
   virtual void render_scene() = 0;
   virtual void process_event(ALLEGRO_EVENT &event) = 0;
};


