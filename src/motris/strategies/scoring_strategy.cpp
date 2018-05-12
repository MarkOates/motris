

#include <motris/strategies/scoring_strategy.hpp>

#include <stdexcept>


ScoringStrategy::ScoringStrategy()
{
}


ScoringStrategy::~ScoringStrategy()
{
}


int ScoringStrategy::get_points_awarded(int level, int num_lines_removed)
{
   int base_points_awarded = 0;

   switch (num_lines_removed)
   {
   case 0: base_points_awarded = 0; break;
   case 1: base_points_awarded = 40; break;
   case 2: base_points_awarded = 100; break;
   case 3: base_points_awarded = 300; break;
   case 4: base_points_awarded = 1200; break;
   default:
      throw std::runtime_error("unaccounted for num_lines_removed");
      break;
   }

   return base_points_awarded * (level + 1);
}


