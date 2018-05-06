

#include <gtest/gtest.h>

#include <motris/models/figure.hpp>


TEST(FigureTest, make_I_shape__makes_the_expected_shape)
{
   Figure figure({{0, 1}, {1, 1}, {2, 1}, {3, 1}});

   std::set<vec2i> expected_points{ {1, 1}, {2, 1}, {3, 1}, {4, 1} };

   figure.move_x(1);

   ASSERT_EQ(expected_points, figure.points);
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


