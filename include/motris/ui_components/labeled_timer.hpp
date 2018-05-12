#pragma once


#include <framework/placement2d.hpp>
#include <framework/text.hpp>


class LabeledTimer
{
private:
   placement2d placement;
   Text label;
   Text value;
   Text value_milliseconds;

public:
   LabeledTimer(ALLEGRO_FONT *label_font, ALLEGRO_FONT *value_font, ALLEGRO_FONT *milliseconds_value_font, std::string label_text, std::string value_text, float x, float y, float align_x);
   ~LabeledTimer();

   void set_value(int value);

   void draw();
};


