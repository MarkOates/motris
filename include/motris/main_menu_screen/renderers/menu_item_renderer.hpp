#pragma once


#include <framework/placement2d.hpp>
#include <allegro5/allegro_font.h>
#include <motris/main_menu_screen/models/menu_item.hpp>


namespace MainMenu
{
   class MenuItemRenderer
   {
   public:
      enum state_t
      {
         NONE = 0,
         NORMAL,
         SELECTED,
      };

   private:
      MenuItem *menu_item;
      placement2d place;
      ALLEGRO_FONT *font;
      state_t state;

   public:
      MenuItemRenderer(MenuItem *menu_item, ALLEGRO_FONT *font, float x, float y, state_t state);
      ~MenuItemRenderer();

      void render();
   };
}


