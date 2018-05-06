#pragma once


#include <framework/bitmap.hpp>
#include <framework/vec2i.hpp>
#include <set>


class Figure
{
public:
   const std::set<vec2i> points;

   Figure(std::set<vec2i> points);

   void draw(Bitmap &block_bitmap, int tile_size);
};


