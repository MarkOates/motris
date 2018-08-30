

#include <motris/main_menu_screen/models/menu.hpp>


static void __move_cursor(int &cursor, int delta, int num_elements)
{
   if (delta == 0) return;

   cursor += delta;
   while (cursor < 0) { cursor += num_elements; }
   cursor = cursor % num_elements;
}


namespace MainMenu
{


Menu::Menu(std::vector<MenuItem> menu_items)
   : cursor_pos(0)
   , menu_items(menu_items)
{
}


Menu::~Menu()
{
}


int Menu::get_cursor_pos()
{
   return cursor_pos;
}


std::vector<MenuItem> Menu::get_menu_items()
{
   return menu_items;
}


void Menu::move_cursor_up()
{
   __move_cursor(cursor_pos, -1, menu_items.size());
}


void Menu::move_cursor_down()
{
   __move_cursor(cursor_pos, 1, menu_items.size());
}


} // namespace


