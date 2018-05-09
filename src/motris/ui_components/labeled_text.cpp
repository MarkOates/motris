

#include <motris/ui_components/labeled_text.hpp>

#include <framework/color.hpp>


LabeledText::LabeledText(ALLEGRO_FONT *label_font, ALLEGRO_FONT *value_font, std::string label_text, std::string value_text, float x, float y, float align_x)
   : placement(x, y, 0, 0)
   , label(label_font, label_text, 0, 0, color::hex("9c7d72"))
   , value(value_font, value_text, 0, 40)
{
   label.placement.align = vec2d(align_x, 0);
   value.placement.align = vec2d(align_x, 0);
}


LabeledText::~LabeledText()
{
}


Text &LabeledText::get_label()
{
   return label;
}


Text &LabeledText::get_value()
{
   return value;
}


void LabeledText::draw()
{
   placement.start_transform();
   label.draw();
   value.draw();
   placement.restore_transform();
}


