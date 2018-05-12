#pragma once


class ScoringStrategy
{
public:
   ScoringStrategy();
   ~ScoringStrategy();

   int get_points_awarded(int level, int num_lines_removed);
};


