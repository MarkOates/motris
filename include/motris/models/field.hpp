#pragma once


#include <motris/models/figure.hpp>
#include <vector>


class Field
{
private:
   const int EMPTY_TILE = 0;
   int width;
   int height;
   std::vector<int> tiles;

public:
   Field(int width=10, int height=20);

   void set_tile(int x, int y, int tile);

   int get_tile(int x, int y) const;

   bool can_place_figure(const Figure &figure) const;
};


