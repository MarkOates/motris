#pragma once


#include <string>
#include <vector>
#include <motris/main_menu_screen/models/menu_item.hpp>


namespace MainMenu
{
   class Menu
   {
   private:
      int cursor_pos;
      std::vector<MenuItem> menu_items;

   public:
      Menu(std::vector<MenuItem> menu_items);
      ~Menu();

      int get_cursor_pos();
      std::vector<MenuItem> get_menu_items();

      void move_cursor_up();
      void move_cursor_down();
   };
} // MainMenu


