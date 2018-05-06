#pragma once


#include <allegro5/allegro.h>
#include <framework/bitmap.hpp>
#include <framework/screen.hpp>
#include <framework/sprite_sheet.hpp>


class Motris : public Screen
{
private:
   SpriteSheet piece_tiles_sprite_sheet;
   Bitmap bitmap;

public:
   Motris();

   void update_scene();
   void render_scene();
   void process_event(ALLEGRO_EVENT &event) override;
};


