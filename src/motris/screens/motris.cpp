

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
      {
         float x=1792/2; float y=1008/2; float scale=0.8;
         float spacing = 419;
         framework.add_screen(new PlayerGameplayGameboard(x-spacing*1.5, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(x-spacing*0.5, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(x+spacing*0.5, y, scale));
         framework.add_screen(new PlayerGameplayGameboard(x+spacing*1.5, y, scale));
      }
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   }
}


