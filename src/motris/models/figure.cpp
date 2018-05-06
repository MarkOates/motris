

#include <motris/models/figure.hpp>


Figure::Figure(std::set<vec2i> points)
   : points(points)
{};


void Figure::draw(Bitmap &block_bitmap, int tile_size)
{
   block_bitmap.clear();

   for (auto &point : points)
   {
      block_bitmap.position = vec2d(point.x * tile_size, point.y * tile_size);
      block_bitmap.draw();
   }
}


