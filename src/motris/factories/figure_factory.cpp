

#include <motris/factories/figure_factory.hpp>


FigureFactory::FigureFactory()
{
}


FigureFactory::~FigureFactory()
{
}


Figure FigureFactory::construct_figure(std::set<int> positions)
{
   std::set<vec2i> points;

   //for (auto &position : positions)
      //points.insert(vec2i(position % 2, position / 2));

   return Figure(points);
   //return Figure({});
}


Figure FigureFactory::make_I_shape()
{
   return construct_figure({1, 3, 5, 7});
}


Figure FigureFactory::make_Z_shape()
{
   return construct_figure({2, 4, 5, 7});
}


Figure FigureFactory::make_S_shape()
{
   return construct_figure({3, 4, 5, 6});
}


Figure FigureFactory::make_T_shape()
{
   return construct_figure({3, 5, 4, 7});
}


Figure FigureFactory::make_L_shape()
{
   return construct_figure({2, 3, 5, 7});
}


Figure FigureFactory::make_J_shape()
{
   return construct_figure({3, 5, 7, 6});
}


Figure FigureFactory::make_O_shape()
{
   return construct_figure({2, 3, 4, 5});
}


