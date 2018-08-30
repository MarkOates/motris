#pragma once


#include <string>
#include <vector>
#include <framework/screen.hpp>
#include <motris/main_menu_screen/models/menu_item.hpp>


namespace MainMenu
{
   class MainMenuScreen : public Screen
   {
   private:
      int cursor_pos;
      std::vector<MenuItem> menu_items;

   public:
      MainMenuScreen();
      ~MainMenuScreen();

      void process_event(ALLEGRO_EVENT &event) override;
   };
} // MainMenu


