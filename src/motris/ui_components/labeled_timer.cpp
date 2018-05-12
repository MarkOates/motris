

#include <motris/ui_components/labeled_timer.hpp>

#include <framework/color.hpp>
#include <sstream>
#include <iomanip>


LabeledTimer::LabeledTimer(ALLEGRO_FONT *label_font, ALLEGRO_FONT *value_font, ALLEGRO_FONT *value_milliseconds_font, std::string label_text, std::string value_text, float x, float y, float align_x)
   : placement(x, y, 0, 0)
   , label(label_font, label_text, 0, 0, color::hex("9c7d72"))
   , value(value_font, value_text, 0, 40)
   , value_milliseconds(value_milliseconds_font, value_text, 217, 83)
{
   label.placement.align = vec2d(align_x, 0);
   value.placement.align = vec2d(align_x, 0);
}


LabeledTimer::~LabeledTimer()
{
}


void LabeledTimer::set_value(int value)
{
   std::stringstream ss;
   std::stringstream ss_milli;
   int hours = value / 3600000;
   int minutes = (value / 60000) % 60;
   int seconds = (value / 1000) % 60;
   int milliseconds = value % 1000;

   if (hours > 0) ss << std::setw(2) << std::setfill('0') << hours << ":";

   ss << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds;
   ss_milli << '.' << std::setfill('0') << std::setw(3) << milliseconds;

   this->value.set_text(ss.str());
   this->value.set_placement_size_to_text();

   this->value_milliseconds.set_text(ss_milli.str());
   this->value_milliseconds.set_placement_size_to_text();
}


void LabeledTimer::draw()
{
   placement.start_transform();
   label.draw();
   value.draw();
   value_milliseconds.draw();
   placement.restore_transform();
}


