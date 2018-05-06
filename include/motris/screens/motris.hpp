#pragma once


#include <allegro5/allegro.h>
#include <framework/screen.hpp>
#include <framework/sprite_sheet.hpp>


enum game_events
{
   GAME_EVENT_FIGURE_DROP = ALLEGRO_GET_EVENT_TYPE('M','t','r','s'),
   GAME_EVENT_ROTATE_FIGURE,
   GAME_EVENT_MOVE_FIGURE_LEFT,
   GAME_EVENT_MOVE_FIGURE_RIGHT
};


class Motris : public Screen
{
private:
   SpriteSheet piece_tiles_sprite_sheet;
   float drop_rate_per_second;
   float drop_rate_counter;

public:
   Motris();

   void update_scene();
   void render_scene();
   void process_input(int gamer_input_screen_button_type);
   void process_event(ALLEGRO_EVENT &event) override;
};


