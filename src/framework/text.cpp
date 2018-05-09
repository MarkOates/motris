

#include <framework/text.hpp>


Text::Text(ALLEGRO_FONT *font, std::string text, float x, float y, ALLEGRO_COLOR color)
   : text(text)
   , color(color)
   , font(font)
   , placement(x, y, 0, 0)
{
   set_text(text);
   set_placement_size_to_text();
}


Text::~Text()
{
}


Text &Text::set_text(std::string text)
{
   this->text = text;
   return *this;
}


Text &Text::set_font(ALLEGRO_FONT *font)
{
   this->font = font;
   return *this;
}


Text &Text::set_color(ALLEGRO_COLOR color)
{
   this->color = color;
   return *this;
}


Text &Text::set_placement_size_to_text()
{
   if (font)
   {
      placement.size.x = al_get_text_width(font, text.c_str());
      placement.size.y = al_get_font_line_height(font);
   }
   else
   {
      placement.size = vec2d(0, 0);
   }
   return *this;
}


Text &Text::clean()
{
   placement.clear();
   text = "";
   font = NULL;
   return *this;
}


Text &Text::draw()
{
   if (!font) std::runtime_error("Cannot render text, font is nullptr");

   placement.start_transform();
   al_draw_text(font, color, 0, 0, 0, text.c_str());
   placement.restore_transform();

   return *this;
}


