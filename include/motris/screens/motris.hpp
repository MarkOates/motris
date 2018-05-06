#pragma once


#include <allegro5/allegro.h>
#include <framework/bitmap.hpp>
#include <framework/screen.hpp>
#include <framework/sprite_sheet.hpp>


#define GAME_EVENT_ROTATE_FIGURE     ALLEGRO_GET_EVENT_TYPE('R','t','F','g')
#define GAME_EVENT_MOVE_FIGURE_LEFT  ALLEGRO_GET_EVENT_TYPE('M','v','F','R')
#define GAME_EVENT_MOVE_FIGURE_RIGHT ALLEGRO_GET_EVENT_TYPE('M','v','F','L')


class Motris : public Screen
{
private:
   SpriteSheet piece_tiles_sprite_sheet;
   Bitmap bitmap;

public:
   Motris();

   void update_scene();
   void render_scene();
   void process_input(int gamer_input_screen_button_type);
   void process_event(ALLEGRO_EVENT &event) override;
};


