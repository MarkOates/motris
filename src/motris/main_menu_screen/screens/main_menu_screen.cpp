

#include <motris/main_menu_screen/screens/main_menu_screen.hpp>

#include <motris/main_menu_screen/renderers/menu_renderer.hpp>
#include <motris/events.hpp>
#include <framework/framework.hpp>


namespace MainMenu
{


MainMenuScreen::MainMenuScreen()
   : Screen()
   , menu({
      { "Start One Player Game", SYSTEM_EVENT_GOTO_SINGLE_PLAYER_GAMEPLAY_SCREEN },
      { "Start Four Player Game", SYSTEM_EVENT_GOTO_MULTIPLAYER_GAMEPLAY_SCREEN },
      { "Quit", EVENT_ABORT_PROGRAM },
   })
{
}


MainMenuScreen::~MainMenuScreen()
{
}


void MainMenuScreen::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case MAIN_MENU_EVENT_MOVE_CURSOR_UP:
      menu.move_cursor_up();
      break;
   case MAIN_MENU_EVENT_MOVE_CURSOR_DOWN:
      menu.move_cursor_down();
      break;
   case MAIN_MENU_EVENT_SELECT_MENU_ITEM:
      {
         MenuItem *menu_item = menu.get_current_menu_item();
         if (menu_item) emit_event(menu_item->get_event());
      }
      break;
   case ALLEGRO_EVENT_TIMER:
      update_scene();
      render_scene();
      std::cout << "event" << std::endl;
      break;
   case MAIN_MENU_EVENT_NONE:
   //deafult:
      //throw std::runtime_error("MainMenUScreen::process_event unexpected ALLEGRO_EVENT_TYPE");
      break;
   }
}


void MainMenuScreen::update_scene()
{
}


#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


void MainMenuScreen::render_scene()
{
   al_draw_filled_rectangle(0, 0, 200, 200, al_color_name("orange"));
   MenuRenderer menu_renderer(&menu, 600, 300);
   menu_renderer.render();
}


} // namespace


