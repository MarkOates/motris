

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
   emit_event(GAME_EVENT_GOTO_MULTIPLAYER_GAMEPLAY_SCREEN);

   // player 1 is on keyboard
   gamer_input_screen.player_input_configurations[player_1.get_player_num()].setup_default_keyboard_mapping_for_ARROW_KEYS();

   // player 2 is on joystick
   gamer_input_screen.player_input_configurations[player_2.get_player_num()].setup_default_joystick_mapping_for_XBOX_360_WIRELESS_CONTROLLER();
}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case SYSTEM_EVENT_GOTO_SINGLE_PLAYER_GAMEPLAY_SCREEN:
      {
         float x=1792/2; float y=1008/2; float scale=1.0;
         framework.add_screen(new PlayerGameplayGameboard(player_1, x, y, scale));
      }
      break;
   case SYSTEM_EVENT_GOTO_MULTIPLAYER_GAMEPLAY_SCREEN:
      {
         float x=1792/2; float y=1008/2; float scale=0.8;
         framework.add_screen(new PlayerGameplayGameboard(player_1, x-600, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(player_2, x-200, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(player_3, x+200, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(player_4, x+600, y, scale));
      }
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   }
}


