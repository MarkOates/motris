#pragma once


#include <framework/placement2d.hpp>
#include <framework/text.hpp>


class LabeledTextNarrow
{
private:
   placement2d placement;
   Text label;
   Text value;

public:
   LabeledTextNarrow(ALLEGRO_FONT *label_font, ALLEGRO_FONT *value_font, std::string label_text, std::string value_text, float x, float y);
   ~LabeledTextNarrow();

   void set_value(int value);

   void draw();
};


