

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
   for (auto &point : figure.points) set_tile(point.x, point.y, figure.color);
}


static int get_tile_type_sprite_index(int tile_type)
{
   switch (tile_type)
   {
   case 0: return 8; break;
   default: return tile_type;
   }
}


void Field::draw(SpriteSheet &sprite_sheet, int tile_size) const
{
   Bitmap tile(sprite_sheet.get_sprite(0));

   for (unsigned y=0; y<height; y++)
      for (unsigned x=0; x<width; x++)
      {
         tile.placement.position = vec2d(x * tile_size, y * tile_size);
         int sprite_sheet_tile_index = get_tile_type_sprite_index(get_tile(x, y));
         tile.set_bitmap(sprite_sheet.get_sprite(sprite_sheet_tile_index));
         tile.draw();
      }
}


int Field::remove_complete_lines()
{
   int num_lines_removed = 0;

   int k = height-1;
   for (unsigned y=height-1; y>0; y--)
   {
      int count = 0;
      for (unsigned x=0; x<width; x++)
      {
         if (get_tile(x, y) != 0) count++;
         set_tile(x, k, get_tile(x, y));
      }
      if (count < width)
      {
         k--;
      }
      else
      {
         num_lines_removed++;
      }
   }

   return num_lines_removed;
}


