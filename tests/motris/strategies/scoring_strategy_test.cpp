

#include <gtest/gtest.h>

#include <motris/strategies/scoring_strategy.hpp>


TEST(ScoringStrategyTest, get_points_awarded__returns_the_expected_awarded_points)
{
   ScoringStrategy scoring_strategy;

   ASSERT_EQ(0, scoring_strategy.get_points_awarded(1, 0));
   ASSERT_EQ(40, scoring_strategy.get_points_awarded(1, 1));
   ASSERT_EQ(100, scoring_strategy.get_points_awarded(1, 2));
   ASSERT_EQ(300, scoring_strategy.get_points_awarded(1, 3));
   ASSERT_EQ(1200, scoring_strategy.get_points_awarded(1, 4));

   ASSERT_EQ(80, scoring_strategy.get_points_awarded(2, 1));
   ASSERT_EQ(200, scoring_strategy.get_points_awarded(2, 2));
   ASSERT_EQ(600, scoring_strategy.get_points_awarded(2, 3));
   ASSERT_EQ(2400, scoring_strategy.get_points_awarded(2, 4));
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}



