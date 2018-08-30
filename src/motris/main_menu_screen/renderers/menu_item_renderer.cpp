

#include <motris/main_menu_screen/renderers/menu_item_renderer.hpp>

#include <allegro5/allegro_color.h>


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
}


MenuItemRenderer::~MenuItemRenderer()
{
}


void MenuItemRenderer::render()
{
   place.start_transform();
   al_draw_text(font, al_color_name("white"), 0, 0, ALLEGRO_ALIGN_CENTER, menu_item->get_text().c_str());
   place.restore_transform();
}


} // namespace


