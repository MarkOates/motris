

#include <motris/models/figure.hpp>


Figure::Figure(std::set<vec2i> points)
   : points(points)
{};


void Figure::draw(Bitmap &block_bitmap, int tile_size)
{
   block_bitmap.placement.clear();

   for (auto &point : points)
   {
      block_bitmap.placement.position = vec2d(point.x * tile_size, point.y * tile_size);
      block_bitmap.draw();
   }
}


#include <iostream>
#include <sstream>


void Figure::move_x(int delta)
{
   std::set<vec2i> moved_points = {};

   for (auto &point : points)
      moved_points.insert(vec2i{ point.x + delta, point.y });

   points = moved_points;
}


void Figure::rotate()
{
   if (points.size() <= 1) throw std::runtime_error("cannot rotate figure that is <= 1 coordinate points");

   vec2i point_of_rotation = *std::next(points.begin(), 1);
   std::set<vec2i> rotated_points;

   for (auto &point : points)
   {
      vec2i temp(point.y - point_of_rotation.y, point.x - point_of_rotation.x);
      rotated_points.insert({ point_of_rotation.x - point.x, point_of_rotation.y + point.y });
   }

   points = rotated_points;
}


