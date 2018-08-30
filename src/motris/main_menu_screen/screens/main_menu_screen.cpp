

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
   case MAIN_MENU_MOVE_CURSOR_UP:
      break;
   case MAIN_MENU_MOVE_CURSOR_DOWN:
      break;
   case MAIN_MENU_MOVE_SELECT_MENU_ITEM:
      break;
   case ALLEGRO_EVENT_TIMER:
      update_scene();
      render_scene();
      break;
   }
}


void MainMenuScreen::update_scene()
{
}


void MainMenuScreen::render_scene()
{
   MenuRenderer menu_renderer(&menu, 600, 300);
   menu_renderer.render();
}


} // namespace


