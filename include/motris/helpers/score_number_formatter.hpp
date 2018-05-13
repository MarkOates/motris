#pragma once


#include <sstream>


class ScoreNumberFormatter
{
private:
   int score;

public:
   ScoreNumberFormatter(int score);
   ~ScoreNumberFormatter();

   std::string get_formatted_score();
};


