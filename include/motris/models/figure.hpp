#pragma once


#include <framework/bitmap.hpp>
#include <framework/vec2i.hpp>
#include <vector>


class Figure
{
public:
   std::vector<vec2i> points;

   Figure(std::vector<vec2i> points);

   void draw(Bitmap &block_bitmap, int tile_size);
   void move_x(int delta);
   void move_y(int delta);
   void rotate();
};


