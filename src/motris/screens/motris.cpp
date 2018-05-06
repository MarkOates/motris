

#include <motris/screens/motris.hpp>
#include <framework/color.hpp>

#include <allegro5/allegro.h>


Motris::Motris()
   : piece_tiles_sprite_sheet(al_load_bitmap("data/bitmaps/piece_tiles.png"), 16, 16)
   , bitmap(piece_tiles_sprite_sheet.get_sprite(0), 40, 20)
{
}


void Motris::update_scene()
{
}


void Motris::render_scene()
{
   ALLEGRO_BITMAP *backbuffer_bitmap = al_get_backbuffer(al_get_current_display());
   ALLEGRO_TRANSFORM trans;
   al_identity_transform(&trans);
   al_orthographic_transform(&trans, 0, 0, -1.0, al_get_bitmap_width(backbuffer_bitmap)/4, al_get_bitmap_height(backbuffer_bitmap)/4, 1.0);
   al_set_target_bitmap(backbuffer_bitmap);
   al_use_projection_transform(&trans);
   al_clear_to_color(color::hex("4b3c37"));

   bitmap.draw();

   al_flip_display();
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


