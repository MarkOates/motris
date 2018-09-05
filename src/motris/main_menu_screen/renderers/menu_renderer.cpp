

#include <motris/main_menu_screen/renderers/menu_item_renderer.hpp>
#include <motris/main_menu_screen/renderers/menu_renderer.hpp>

#include <allegro5/allegro_color.h>


namespace MainMenu
{


MenuRenderer::MenuRenderer(Menu *menu, float x, float y)
   : menu(menu)
   , place(x, y, 0, 0)
   , font(al_load_font("data/fonts/LeagueGothic-Regular.otf", 32, 0))
{
}


MenuRenderer::~MenuRenderer()
{
   al_destroy_font(font);
}


void MenuRenderer::render()
{
   place.start_transform();

   int cursor_y = 0;
   int cursor_distance_y = 140;

   int menu_item_index = 0;
   for (auto &menu_item : menu->get_menu_items())
   {
      bool is_focused = (menu_item_index == menu->get_cursor_pos());
      MenuItemRenderer(&menu_item, font, 600, cursor_y, is_focused ? MenuItemRenderer::SELECTED : MenuItemRenderer::NORMAL).render();
      cursor_y += cursor_distance_y;
      menu_item_index++;
   }

   place.restore_transform();
}


};


