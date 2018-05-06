

#include <motris/models/field.hpp>


Field::Field(int width, int height)
   : width(width)
   , height(height)
   , tiles(width * height, 0)
{}


void Field::set_tile(int x, int y, int tile)
{
   tiles[x + y * width] = tile;
}


int Field::get_tile(int x, int y) const
{
   return tiles[x + y * width];
}


int Field::get_width() const
{
   return width;
}


bool Field::can_place_figure(const Figure &figure) const
{
   for (auto &point : figure.points)
   {
      if (point.x < 0) return false;
      if (point.x >= width) return false;
      if (point.y >= height) return false;

      if (get_tile(point.x, point.y) != EMPTY_TILE) return false;
   }

   return true;
}


void Field::place_figure(const Figure &figure)
{
   for (auto &point : figure.points) set_tile(point.x, point.y, 1);
}


