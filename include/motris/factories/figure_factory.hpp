#pragma once


#include <motris/models/figure.hpp>


class FigureFactory
{
private:
   Figure construct_figure(std::vector<int> positions);

public:
   FigureFactory();
   ~FigureFactory();

   Figure make_I_shape();
   Figure make_Z_shape();
   Figure make_S_shape();
   Figure make_T_shape();
   Figure make_L_shape();
   Figure make_J_shape();
   Figure make_O_shape();
};


