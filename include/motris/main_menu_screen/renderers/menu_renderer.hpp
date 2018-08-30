#pragma once


#include <motris/main_menu_screen/models/menu.hpp>
#include <framework/placement2d.hpp>


namespace MainMenu
{
   class MenuRenderer
   {
   private:
      placement2d place;
      Menu *menu;

   public:
      MenuRenderer(Menu *menu, float x, float y);
      ~MenuRenderer();

      void render();
   };
} // namespace MainMenu


