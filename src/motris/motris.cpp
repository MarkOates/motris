

#include <motris/screens/motris.hpp>

#include <allegro5/allegro.h>


Motris::Motris()
{
}


void Motris::update_scene()
{
}


void Motris::render_scene()
{
}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case ALLEGRO_EVENT_TIMER:
      update_scene();
      render_scene();
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   default:
      std::cout << "Unrecognized Event << " << std::endl;
      break;
   }
}


