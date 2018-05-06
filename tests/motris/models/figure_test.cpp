

#include <gtest/gtest.h>

#include <motris/models/figure.hpp>


TEST(FigureTest, move_x__moves_the_figure_in_the_x_direction)
{
   Figure figure({{0, 1}, {1, 1}, {2, 1}, {3, 1}});

   std::vector<vec2i> expected_points{ {1, 1}, {2, 1}, {3, 1}, {4, 1} };

   figure.move_x(1);

   ASSERT_EQ(expected_points, figure.points);
}


TEST(FigureTest, move_y__moves_the_figure_in_the_y_direction)
{
   Figure figure({{0, 1}, {1, 1}, {2, 1}, {3, 1}});

   std::vector<vec2i> expected_points{ {0, 2}, {1, 2}, {2, 2}, {3, 2} };

   figure.move_y(1);

   ASSERT_EQ(expected_points, figure.points);
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


