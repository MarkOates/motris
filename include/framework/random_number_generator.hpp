#pragma once


#include <random>
#include <ctime>


class RandomNumberGenerator
{
private:
   std::mt19937 random_number_generator;
   unsigned int seed;

public:
   RandomNumberGenerator(unsigned int seed=(unsigned int)time(0));

   void set_seed(unsigned int new_seed);

   unsigned int get_seed();

   int get_random_int(int min, int max);
   float get_random_float(float min, float max);
   double get_random_double(double min, double max);
   bool get_one_in_chance(int chance);
};


