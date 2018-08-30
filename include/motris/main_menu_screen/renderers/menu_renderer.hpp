#pragma once


#include <motris/main_menu_screen/models/menu.hpp>
#include <allegro5/allegro_font.h>
#include <framework/placement2d.hpp>


namespace MainMenu
{
   class MenuRenderer
   {
   private:
      Menu *menu;
      placement2d place;
      ALLEGRO_FONT *font;

   public:
      MenuRenderer(Menu *menu, float x, float y);
      ~MenuRenderer();

      void render();
   };
} // namespace MainMenu


