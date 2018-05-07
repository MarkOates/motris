#pragma once


#include <motris/models/figure.hpp>
#include <framework/sprite_sheet.hpp>
#include <vector>


#define EMPTY_TILE 0


class Field
{
private:
   int width;
   int height;
   std::vector<int> tiles;

public:
   Field(int width=10, int height=20);

   void set_tile(int x, int y, int tile);

   int get_tile(int x, int y) const;
   int get_width() const;

   bool can_place_figure(const Figure &figure) const;
   void place_figure(const Figure &figure);
   void draw(SpriteSheet &sprite_sheet, int tile_size) const;
   std::vector<vec2i> remove_complete_lines();
};


