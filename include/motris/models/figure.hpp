#pragma once


#include <framework/bitmap.hpp>
#include <framework/vec2i.hpp>
#include <set>


class Figure
{
public:
   std::set<vec2i> points;

   Figure(std::set<vec2i> points);

   void draw(Bitmap &block_bitmap, int tile_size);
   void move_x(int delta);
   void rotate();
};


