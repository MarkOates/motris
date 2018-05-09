

#include <motris/screens/motris.hpp>

#include <motris/events.hpp>


Motris::Motris(Framework &framework)
   : framework(framework)
{}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   }
}


