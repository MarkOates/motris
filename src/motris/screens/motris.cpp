

#include <motris/screens/motris.hpp>

#include <framework/screens/gamer_input_screen.hpp>
#include <framework/color.hpp>
#include <framework/placement2d.hpp>


Motris::Motris()
   : piece_tiles_sprite_sheet(al_load_bitmap("data/bitmaps/piece_tiles.png"), 16, 16)
   , figure_factory()
   , field(10, 20)
   , current_player_figure(figure_factory.make_random_shape())
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
   al_orthographic_transform(&trans, 0, 0, -1.0, al_get_bitmap_width(backbuffer_bitmap)/2.5, al_get_bitmap_height(backbuffer_bitmap)/2.5, 1.0);
   al_set_target_bitmap(backbuffer_bitmap);
   al_use_projection_transform(&trans);
   al_clear_to_color(color::hex("4b3c37"));

   placement2d place;
   place.position = vec2d(200, 30);
   place.start_transform();

   field.draw(piece_tiles_sprite_sheet, 16);
   current_player_figure.draw(piece_tiles_sprite_sheet, 16);

   place.restore_transform();

   al_flip_display();
}


void Motris::process_button_down_input(int gamer_input_screen_button_type)
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
      emit_event(GAME_EVENT_ACCELERATE_DROP);
      break;
   case GAMER_BUTTON_START:
   case GAMER_BUTTON_BACK:
   case GAMER_BUTTON_A:
   case GAMER_BUTTON_B:
   case GAMER_BUTTON_C:
      break;
   };
}


void Motris::process_button_up_input(int gamer_input_screen_button_type)
{
   switch(gamer_input_screen_button_type)
   {
   case GAMER_BUTTON_DOWN:
      emit_event(GAME_EVENT_NORMALIZE_DROP_SPEED);
      break;
   }
}


void Motris::try_figure_movement_and_placement(ALLEGRO_EVENT &event)
{
   Figure temp_figure = current_player_figure;
   bool drop_event = false;

   switch(event.type)
   {
   case GAME_EVENT_FIGURE_DROP:
      temp_figure.move_y(1);
      drop_event = true;
      break;
   case GAME_EVENT_ROTATE_FIGURE:
      temp_figure.rotate();
      break;
   case GAME_EVENT_MOVE_FIGURE_LEFT:
      temp_figure.move_x(-1);
      break;
   case GAME_EVENT_MOVE_FIGURE_RIGHT:
      temp_figure.move_x(1);
      break;
   default:
      break;
   }

   if (field.can_place_figure(temp_figure))
      current_player_figure = temp_figure;
   else if (drop_event)
      emit_event(GAME_EVENT_PLACE_FIGURE);

}


void Motris::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case GAME_EVENT_FIGURE_DROP:
   case GAME_EVENT_ROTATE_FIGURE:
   case GAME_EVENT_MOVE_FIGURE_LEFT:
   case GAME_EVENT_MOVE_FIGURE_RIGHT:
      try_figure_movement_and_placement(event);
      break;
   case GAME_EVENT_PLACE_FIGURE:
      {
         field.place_figure(current_player_figure);
         int new_x = rand() % field.get_width();
         FigureFactory figure_factory;
         current_player_figure = figure_factory.make_random_shape();
         break;
      }
   case GAME_EVENT_NORMALIZE_DROP_SPEED:
      drop_rate_per_second = 1.0;
      break;
   case GAME_EVENT_ACCELERATE_DROP:
      drop_rate_per_second = 1.0/10;
      drop_rate_counter = drop_rate_per_second;
      break;
   case ALLEGRO_EVENT_TIMER:
      update_scene();
      render_scene();
      break;
   case ALLEGRO_EVENT_DISPLAY_CLOSE:
      emit_event(EVENT_ABORT_PROGRAM);
      break;
   case GAMER_BUTTON_DOWN_EVENT:
      process_button_down_input(event.user.data1);
      break;
   case GAMER_BUTTON_UP_EVENT:
      process_button_up_input(event.user.data1);
      break;
   default:
      std::cout << "Unrecognized Event << " << std::endl;
      break;
   }
}


