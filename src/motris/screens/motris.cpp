

#include <motris/screens/motris.hpp>

#include <motris/screens/gameplay.hpp>
#include <motris/events.hpp>


Motris::Motris(Framework &framework)
   : framework(framework)
{
   emit_event(GAME_EVENT_START_GAMEPLAY);
}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case GAME_EVENT_START_GAMEPLAY:
      framework.add_screen(new Gameplay);
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   }
}


