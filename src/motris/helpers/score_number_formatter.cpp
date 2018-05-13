

#include <motris/helpers/score_number_formatter.hpp>

#include <string>
#include <iomanip>


ScoreNumberFormatter::ScoreNumberFormatter(int score)
   : score(score)
{
}


ScoreNumberFormatter::~ScoreNumberFormatter()
{
}


std::string ScoreNumberFormatter::get_formatted_score()
{
   std::stringstream formatted_score;
   formatted_score << std::setw(6) << std::setfill('0') << score;
   return formatted_score.str();
}


