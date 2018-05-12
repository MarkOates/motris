#pragma once


#include <framework/sprite_sheet.hpp>
#include <framework/vec2i.hpp>
#include <vector>


class Figure
{
public:
   enum figure_t
   {
      FIGURE_SHAPE_I = 0,
      FIGURE_SHAPE_Z,
      FIGURE_SHAPE_S,
      FIGURE_SHAPE_T,
      FIGURE_SHAPE_L,
      FIGURE_SHAPE_J,
      FIGURE_SHAPE_O,
      FIGURE_SHAPE_OTHER,
   };

private:
   figure_t type;

public:
   std::vector<vec2i> points;
   int color;

   Figure(std::vector<vec2i> points, int color, Figure::figure_t type);

   figure_t get_type();

   bool is_type(Figure::figure_t type);

   void move_x(int delta);
   void move_y(int delta);
   void rotate();

   void draw(SpriteSheet &sprite_sheet, int tile_size, bool hide_above_y_0=false);
};


