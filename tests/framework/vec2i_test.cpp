

#include <gtest/gtest.h>

#include <framework/vec2i.hpp>

#include <iostream>

TEST(Vec2iTest, lt_operator_evaluates_the_less_than_comparison_as_expected)
{
   std::vector<vec2i> vec2is = {
      { 9, -4 },
      { 3,  5 },
      { -3, 2 },
      { 5,  2 },
      { 3,  4 },
      { 5, -2 },
      { 1,  3 },
      { 5,  4 },
      { 0,  5 },
      { 5,  2 },
   };

   std::vector<vec2i> expected_sorted_vec2is = {
      { -3, 2 },
      { 0,  5 },
      { 1,  3 },
      { 3,  4 },
      { 3,  5 },
      { 5, -2 },
      { 5,  2 },
      { 5,  2 },
      { 5,  4 },
      { 9, -4 },
   };

   std::sort(vec2is.begin(), vec2is.end());

   std::stringstream error_message;
   error_message << "The resulting error sortings are (expected, actual): { ";
   for (unsigned i=0; i<vec2is.size(); i++) std::cout << " { " << expected_sorted_vec2is[i].print() << " - " << vec2is[i].print() << " }, ";
   error_message << " }.";

   ASSERT_EQ(expected_sorted_vec2is, vec2is) << error_message.str();
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


