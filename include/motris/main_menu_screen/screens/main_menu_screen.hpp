#pragma once


#include <string>
#include <vector>
#include <framework/screen.hpp>
#include <motris/main_menu_screen/models/menu.hpp>


namespace MainMenu
{
   class MainMenuScreen : public Screen
   {
   private:
      int cursor_pos;
      Menu menu;

   public:
      MainMenuScreen();
      ~MainMenuScreen();

      void process_event(ALLEGRO_EVENT &event) override;
      void update_scene();
      void render_scene();
   };
} // MainMenu


