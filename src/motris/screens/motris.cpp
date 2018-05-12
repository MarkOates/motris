

#include <motris/screens/motris.hpp>

#include <motris/screens/player_gameplay_gameboard.hpp>
#include <motris/events.hpp>


Motris::Motris(Framework &framework)
   : framework(framework)
   , gamer_input_screen()
{
   framework.add_screen(&gamer_input_screen);
   emit_event(GAME_EVENT_GOTO_SINGLE_PLAYER_GAMEPLAY_SCREEN);
}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case GAME_EVENT_GOTO_SINGLE_PLAYER_GAMEPLAY_SCREEN:
      framework.add_screen(new PlayerGameplayGameboard);
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   }
}


