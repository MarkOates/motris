

#include <motris/models/field.hpp>
#include <framework/bitmap.hpp>


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


void Field::draw(SpriteSheet &sprite_sheet, int tile_size) const
{
   Bitmap tile(sprite_sheet.get_sprite(0));

   for (unsigned y=0; y<height; y++)
      for (unsigned x=0; x<width; x++)
      {
      switch (get_tile(x, y))
      {
      case EMPTY_TILE:
         break;
      default:
         tile.placement.position = vec2d(x * tile_size, y * tile_size);
         tile.draw();
         break;
      }
      }
}


std::vector<vec2i> Field::remove_complete_lines()
{
   std::vector<vec2i> results;

   int k = height-1;
   for (unsigned y=height-1; y>0; y--)
   {
      int count = 0;
      for (unsigned x=0; x<width; x++)
      {
         if (get_tile(x, y) != 0) count++;
         set_tile(x, k, get_tile(x, y));
      }
      if (count < width) k--;
   }

   return results;
}


