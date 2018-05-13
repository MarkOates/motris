

#include <motris/screens/motris.hpp>

#include <motris/screens/player_gameplay_gameboard.hpp>
#include <motris/events.hpp>


Motris::Motris(Framework &framework)
   : framework(framework)
   , gamer_input_screen()
   , player_1("Player 1", 1)
   , player_2("Player 2", 2)
   , player_3("Player 3", 3)
   , player_4("Player 4", 4)
{
   framework.add_screen(&gamer_input_screen);
   emit_event(GAME_EVENT_GOTO_SINGLE_PLAYER_GAMEPLAY_SCREEN);

   gamer_input_screen.player_input_configurations[2].setup_default_keyboard_mapping_for_ARROW_KEYS();
   gamer_input_screen.player_input_configurations[2].setup_default_joystick_mapping_for_XBOX_360_CONTROLLER();
}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case GAME_EVENT_GOTO_SINGLE_PLAYER_GAMEPLAY_SCREEN:
      {
         float x=1792/2; float y=1008/2; float scale=0.8;
         framework.add_screen(new PlayerGameplayGameboard(player_1, x-400, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(player_2, x+400, y, scale));
      }
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   }
}


