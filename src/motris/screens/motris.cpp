

#include <motris/screens/motris.hpp>

#include <framework/screens/gamer_input_screen.hpp>
#include <framework/color.hpp>


Motris::Motris()
   : piece_tiles_sprite_sheet(al_load_bitmap("data/bitmaps/piece_tiles.png"), 16, 16)
   , bitmap(piece_tiles_sprite_sheet.get_sprite(0), 40, 20)
   , drop_rate_per_second(1.0)
   , drop_rate_counter(0)
{
}


void Motris::update_scene()
{
   drop_rate_counter += 1.0 / 60.0;
   while (drop_rate_counter >= drop_rate_per_second)
   {
      drop_rate_counter -= drop_rate_per_second;
      emit_event(GAME_EVENT_FIGURE_DROP);
   }
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


void Motris::process_input(int gamer_input_screen_button_type)
{
   switch(gamer_input_screen_button_type)
   {
   case GAMER_BUTTON_UP:
      emit_event(GAME_EVENT_ROTATE_FIGURE);
      break;
   case GAMER_BUTTON_LEFT:
      emit_event(GAME_EVENT_MOVE_FIGURE_LEFT);
      break;
   case GAMER_BUTTON_RIGHT:
      emit_event(GAME_EVENT_MOVE_FIGURE_RIGHT);
      break;
   case GAMER_BUTTON_DOWN:
   case GAMER_BUTTON_START:
   case GAMER_BUTTON_BACK:
   case GAMER_BUTTON_A:
   case GAMER_BUTTON_B:
   case GAMER_BUTTON_C:
      break;
   };
}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case GAME_EVENT_FIGURE_DROP:
      current_player_figure.move_y(1);
      break;
   case GAME_EVENT_ROTATE_FIGURE:
      current_player_figure.rotate();
      break;
   case GAME_EVENT_MOVE_FIGURE_LEFT:
      current_player_figure.move_x(-1);
      break;
   case GAME_EVENT_MOVE_FIGURE_RIGHT:
      current_player_figure.move_x(1);
      break;
   case ALLEGRO_EVENT_TIMER:
      update_scene();
      render_scene();
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   case GAMER_BUTTON_DOWN_EVENT:
      process_input(event.user.data1);
      break;
   default:
      std::cout << "Unrecognized Event << " << std::endl;
      break;
   }
}


