#pragma once


#include <string>


class vec2i
{
public:
   int x, y;

   vec2i(int x=0, int y=0);
   ~vec2i();

   std::string print() const;

   bool operator==(const vec2i &other) const;
   bool operator!=(const vec2i &other) const;
   bool operator<(const vec2i &other) const;
};


