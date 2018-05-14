

#include <motris/factories/figure_factory.hpp>


FigureFactory::FigureFactory()
   : random_number_generator()
{
}


FigureFactory::~FigureFactory()
{
}


Figure FigureFactory::construct_figure(std::vector<int> positions, int color, Figure::figure_t type)
{
   std::vector<vec2i> points;

   for (auto &position : positions)
      points.push_back(vec2i(position % 2, position / 2));

   return Figure(points, color, type);
}


Figure FigureFactory::make_I_shape()
{
   return construct_figure({1, 3, 5, 7}, 1, Figure::FIGURE_SHAPE_I);
}


Figure FigureFactory::make_Z_shape()
{
   return construct_figure({2, 4, 5, 7}, 2, Figure::FIGURE_SHAPE_Z);
}


Figure FigureFactory::make_S_shape()
{
   return construct_figure({3, 4, 5, 6}, 3, Figure::FIGURE_SHAPE_S);
}


Figure FigureFactory::make_T_shape()
{
   return construct_figure({3, 5, 4, 7}, 4, Figure::FIGURE_SHAPE_T);
}


Figure FigureFactory::make_L_shape()
{
   return construct_figure({2, 3, 5, 7}, 5, Figure::FIGURE_SHAPE_L);
}


Figure FigureFactory::make_J_shape()
{
   return construct_figure({3, 5, 7, 6}, 6, Figure::FIGURE_SHAPE_J);
}


Figure FigureFactory::make_O_shape()
{
   return construct_figure({2, 3, 4, 5}, 7, Figure::FIGURE_SHAPE_O);
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

   return possible_figures[random_number_generator.get_random_int(0, possible_figures.size()-1)];
}


Figure FigureFactory::make_figure(Figure::figure_t type)
{
   switch (type)
   {
      case Figure::FIGURE_SHAPE_I: return make_I_shape(); break;
      case Figure::FIGURE_SHAPE_Z: return make_Z_shape(); break;
      case Figure::FIGURE_SHAPE_S: return make_S_shape(); break;
      case Figure::FIGURE_SHAPE_T: return make_T_shape(); break;
      case Figure::FIGURE_SHAPE_L: return make_L_shape(); break;
      case Figure::FIGURE_SHAPE_J: return make_J_shape(); break;
      case Figure::FIGURE_SHAPE_O: return make_O_shape(); break;
      case Figure::FIGURE_SHAPE_OTHER:
      default:
         throw std::runtime_error("unrecognized Figure::figure_t");
         break;
   }
}


