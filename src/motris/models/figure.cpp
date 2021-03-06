

#include <motris/models/figure.hpp>

#include <framework/bitmap.hpp>


Figure::Figure(std::vector<vec2i> points, int color, Figure::figure_t type)
   : points(points)
   , color(color)
   , type(type)
{};


Figure::figure_t Figure::get_type()
{
   return type;
}


bool Figure::is_type(Figure::figure_t type)
{
   return this->type == type;
}


void Figure::move_x(int delta)
{
   for (auto &point : points) point.x += delta;
}


void Figure::move_y(int delta)
{
   for (auto &point : points) point.y += delta;
}


void Figure::rotate()
{
   if (points.size() <= 1) throw std::runtime_error("cannot rotate figure that is <= 1 coordinate points");

   vec2i point_of_rotation = points[1];
   std::vector<vec2i> rotated_points;

   for (auto &point : points)
   {
      vec2i temp(point.y - point_of_rotation.y, point.x - point_of_rotation.x);
      rotated_points.push_back(vec2i{ point_of_rotation.x - temp.x, point_of_rotation.y + temp.y });
   }

   points = rotated_points;
}


void Figure::draw(SpriteSheet &sprite_sheet, int tile_size, bool hide_above_y_0)
{
   Bitmap tile(sprite_sheet.get_sprite(color));
   tile.placement.clear();

   for (auto &point : points)
   {
      if (hide_above_y_0 && point.y < 0) continue;
      tile.placement.position = vec2d(point.x * tile_size, point.y * tile_size);
      tile.draw();
   }
}


