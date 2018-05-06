

#include <framework/vec2i.hpp>

#include <sstream>


vec2i::vec2i(int x, int y)
   : x(x)
   , y(y)
{
}


vec2i::~vec2i()
{
}


std::string vec2i::print()
{
   std::stringstream ss;
   ss << "(" << x << ", " << y << ")";
   return ss.str();
}


bool vec2i::operator==(const vec2i &other) const
{
   return x == other.x && y == other.y;
}


bool vec2i::operator!=(const vec2i &other) const
{
   return !(*this == other);
}


bool vec2i::operator<(const vec2i &other) const
{
   if (x < other.x) return true;
   else if (x == other.x && y < other.y) return true;
   return false;
}


