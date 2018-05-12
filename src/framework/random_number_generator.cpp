

#include <framework/random_number_generator.hpp>


RandomNumberGenerator::RandomNumberGenerator(unsigned int seed)
   : seed(seed)
{
   set_seed(seed);
}


void RandomNumberGenerator::set_seed(unsigned int new_seed)
{
   seed = new_seed;
   random_number_generator.seed(seed);
}


unsigned int RandomNumberGenerator::get_seed()
{
   return seed;
}


int RandomNumberGenerator::get_random_int(int min, int max)
{
   std::uniform_int_distribution<int> dist(min, max);
   return dist(random_number_generator);
}


float RandomNumberGenerator::get_random_float(float min, float max)
{
   std::uniform_real_distribution<float> dist(min, max);
   return dist(random_number_generator);
}


double RandomNumberGenerator::get_random_double(double min, double max)
{
   std::uniform_real_distribution<double> dist(min, max);
   return dist(random_number_generator);
}


bool RandomNumberGenerator::get_one_in_chance(int chance)
{
   if (chance <= 0) return false;

   if (get_random_int(0, chance - 1) == 0)
      return true;
   return false;
}


