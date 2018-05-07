#pragma once


#include <framework/sprite_sheet.hpp>
#include <framework/vec2i.hpp>
#include <vector>


class Figure
{
public:
   std::vector<vec2i> points;

   Figure(std::vector<vec2i> points);

   void move_x(int delta);
   void move_y(int delta);
   void rotate();

   void draw(SpriteSheet &sprite_sheet, int tile_size);
};


