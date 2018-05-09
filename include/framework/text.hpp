#pragma once


#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <framework/placement2d.hpp>
#include <string>


class Text
{
private:
   std::string text;
   ALLEGRO_COLOR color;
   ALLEGRO_FONT *font;

public:
   placement2d placement;

   Text(ALLEGRO_FONT *font, std::string text="", float x=0, float y=0, ALLEGRO_COLOR color=al_map_rgba_f(1,1,1,1));
   ~Text();

   Text &set_text(std::string text);
   Text &set_font(ALLEGRO_FONT *font);
   Text &set_color(ALLEGRO_COLOR color);

   Text &set_placement_size_to_text();
   Text &clean();
   Text &draw();
};


