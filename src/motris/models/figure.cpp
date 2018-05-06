

#include <motris/models/figure.hpp>


Figure::Figure(std::vector<vec2i> points)
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



void Figure::move_x(int delta)
{
   std::vector<vec2i> moved_points = {};

   for (auto &point : points)
      moved_points.push_back(vec2i{ point.x + delta, point.y });

   points = moved_points;
}


void Figure::rotate()
{
   if (points.size() <= 1) throw std::runtime_error("cannot rotate figure that is <= 1 coordinate points");

   vec2i point_of_rotation = points[1];
   std::vector<vec2i> rotated_points;

   for (auto &point : points)
   {
      vec2i temp(point.y - point_of_rotation.y, point.x - point_of_rotation.x);
      rotated_points.push_back({ point_of_rotation.x - temp.x, point_of_rotation.y + temp.y });
   }

   points = rotated_points;
}


