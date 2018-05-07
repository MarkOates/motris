

#include <motris/factories/figure_factory.hpp>


FigureFactory::FigureFactory()
{
}


FigureFactory::~FigureFactory()
{
}


Figure FigureFactory::construct_figure(std::vector<int> positions, int color)
{
   std::vector<vec2i> points;

   for (auto &position : positions)
      points.push_back(vec2i(position % 2, position / 2));

   return Figure(points, color);
}


Figure FigureFactory::make_I_shape()
{
   return construct_figure({1, 3, 5, 7}, 1);
}


Figure FigureFactory::make_Z_shape()
{
   return construct_figure({2, 4, 5, 7}, 2);
}


Figure FigureFactory::make_S_shape()
{
   return construct_figure({3, 4, 5, 6}, 3);
}


Figure FigureFactory::make_T_shape()
{
   return construct_figure({3, 5, 4, 7}, 4);
}


Figure FigureFactory::make_L_shape()
{
   return construct_figure({2, 3, 5, 7}, 5);
}


Figure FigureFactory::make_J_shape()
{
   return construct_figure({3, 5, 7, 6}, 6);
}


Figure FigureFactory::make_O_shape()
{
   return construct_figure({2, 3, 4, 5}, 7);
}


Figure FigureFactory::make_random_shape()
{
   static const std::vector<Figure> possible_figures = {
      make_I_shape(),
      make_Z_shape(),
      make_S_shape(),
      make_T_shape(),
      make_L_shape(),
      make_J_shape(),
      make_O_shape()
   };

   return possible_figures[rand() % possible_figures.size()];
}


