#pragma once


#include <allegro5/allegro.h>
#include <framework/placement2d.hpp>


class Bitmap
{
public:
   placement2d placement;
   ALLEGRO_BITMAP *al_bitmap;
   ALLEGRO_COLOR color;
   float opacity;
   int flags;

public:
   Bitmap(ALLEGRO_BITMAP *al_bitmap, float x=0, float y=0);
   ~Bitmap();

   Bitmap &set_bitmap(ALLEGRO_BITMAP *bitmap);
   Bitmap &set_flags(int flags);
   Bitmap &set_opacity(float opacity);

   ALLEGRO_BITMAP *get_bitmap();

   Bitmap &reset();
   Bitmap &draw_raw();
   Bitmap &draw();
};


