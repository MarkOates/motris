#pragma once


#include <framework/placement2d.hpp>
#include <framework/text.hpp>


class LabeledText
{
private:
   placement2d placement;
   Text label;
   Text value;

public:
   LabeledText(ALLEGRO_FONT *label_font, ALLEGRO_FONT *value_font, std::string label_text, std::string value_text, float x, float y, float align_x);
   ~LabeledText();

   Text &get_label();
   Text &get_value();

   void set_value(int value);

   void draw();
};


