

#include <gtest/gtest.h>

#include <motris/factories/figure_factory.hpp>


TEST(FigureFactoryTest, make_I_shape__makes_the_expected_shape)
{
   FigureFactory figure_factory;

   std::vector<vec2i> points = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
   Figure figure = figure_factory.make_I_shape();

   ASSERT_EQ(points, figure.points);
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


