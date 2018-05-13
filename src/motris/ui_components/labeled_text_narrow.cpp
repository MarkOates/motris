

#include <motris/ui_components/labeled_text_narrow.hpp>

#include <framework/color.hpp>
#include <sstream>


LabeledTextNarrow::LabeledTextNarrow(ALLEGRO_FONT *label_font, ALLEGRO_FONT *value_font, std::string label_text, std::string value_text, float x, float y)
   : placement(x, y, 0, 0)
   , label(label_font, label_text, 0, 0, color::hex("9c7d72"))
   , value(value_font, value_text, 26, 4)
{
   label.placement.align = vec2d(1.0, 0);
   value.placement.align = vec2d(0.0, 0);
}


LabeledTextNarrow::~LabeledTextNarrow()
{
}


void LabeledTextNarrow::set_value(int value)
{
   std::stringstream ss;
   ss << value;
   this->value.set_text(ss.str());
   this->value.set_placement_size_to_text();
}


void LabeledTextNarrow::draw()
{
   placement.start_transform();
   label.draw();
   value.draw();
   placement.restore_transform();
}


