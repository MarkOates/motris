

#include <motris/main_menu_screen/renderers/menu_item_renderer.hpp>

#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace MainMenu
{


MenuItemRenderer::MenuItemRenderer(MenuItem *menu_item, ALLEGRO_FONT *font, float x, float y, state_t state)
   : menu_item(menu_item)
   , font(font)
   , place(x, y, 200, 100)
   , state(state)
{
   // validate menu_item
   // validate font

   if (!menu_item) throw std::runtime_error("Invalid menu_item in MenuItemRenderer");
   if (!font) throw std::runtime_error("Invalid font in MenuItemRenderer");
}


MenuItemRenderer::~MenuItemRenderer()
{
}


void MenuItemRenderer::render()
{
   place.start_transform();
   ALLEGRO_COLOR color;

   switch(state)
   {
   case NONE:
      color = al_color_name("gray");
      break;
   case NORMAL:
      color = al_color_name("white");
      break;
   case SELECTED:
      color = al_color_name("yellow");
      break;
   default:
      break;
   }

   al_draw_filled_rectangle(0, 0, 800, 800, al_color_name("green"));

   al_draw_text(font, color, 0, 0, ALLEGRO_ALIGN_CENTER, menu_item->get_text().c_str());
   place.restore_transform();
}


} // namespace


