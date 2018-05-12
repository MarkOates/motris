

#include <gtest/gtest.h>

#include <motris/models/field.hpp>


TEST(FieldTest, remove_complete_lines__returns_the_number_of_removed_lines)
{
   const int height = 6;
   const int width = 3;

   Field field(width, height);

   int tiles[height][width] = {
      { 0, 0, 0 },
      { 1, 0, 1 },
      { 1, 1, 0 },
      { 1, 1, 1 },
      { 1, 0, 1 },
      { 1, 1, 1 },
   };

   for (int y=0; y<height; y++)
      for (int x=0; x<width; x++)
         field.set_tile(x, y, tiles[y][x]);

   ASSERT_EQ(2, field.remove_complete_lines());
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


