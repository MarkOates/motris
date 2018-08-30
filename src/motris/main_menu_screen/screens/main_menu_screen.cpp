

#include <motris/main_menu_screen/screens/main_menu_screen.hpp>


namespace MainMenu
{


MainMenuScreen::MainMenuScreen()
   : Screen()
   , cursor_pos(0)
   , menu_items()
{
}


MainMenuScreen::~MainMenuScreen()
{
}


void MainMenuScreen::process_event(ALLEGRO_EVENT &event)
{
}


} // namespace


