

#include <motris/screens/player_gameplay_gameboard.hpp>

#include <motris/ui_components/gameplay_hud.hpp>
#include <framework/screens/gamer_input_screen.hpp>
#include <framework/color.hpp>
#include <framework/placement2d.hpp>
#include <motris/events.hpp>


PlayerGameplayGameboard::PlayerGameplayGameboard(float x, float y, float scale)
   : Screen()
   , placement(x, y, 0, 0, 0, scale, scale, 0.5, 0.5, 0, 0)
   , gameplay_hud(new GameplayHUD)
   , piece_tiles_sprite_sheet(al_load_bitmap("data/bitmaps/piece_tiles.png"), 16, 16)
   , figure_factory()
   , field(10, 20)
   , current_player_figure(figure_factory.make_random_shape())
   , next_figure(figure_factory.make_random_shape())
   , drop_rate_per_second(1.0)
   , drop_rate_counter(0)
   , scoring_strategy()
   , timer()
   , level(1)
   , score(0)
   , lines_cleared(0)
   , pieces_since_last_longbar(0)
   , state(STATE_UNDEF)
{
   emit_event(GAME_EVENT_START_GAMEPLAY);
}


void PlayerGameplayGameboard::set_position(float x, float y, float scale)
{
   placement.position = vec2d(x, y);
   placement.scale = vec2d(scale, scale);
}


void PlayerGameplayGameboard::update_scene()
{
   if (state == PlayerGameplayGameboard::STATE_GAMEPLAY)
   {
      drop_rate_counter += 1.0 / 60.0;
      while (drop_rate_counter >= drop_rate_per_second)
      {
         drop_rate_counter -= drop_rate_per_second;
         emit_event(GAME_EVENT_FIGURE_DROP);
      }

      emit_event(GAME_EVENT_HUD_UPDATE_TIME, timer.get_elappsed_time_msec());
   }

   gameplay_hud->update_scene();
}


void PlayerGameplayGameboard::render_scene()
{
   placement.start_transform();

      placement2d field_placement;
         field_placement.size = vec2d(16*10, 16*20);
         field_placement.align = vec2d(0.5, 0.5);
         field_placement.scale = vec2d(2.65, 2.65);
         field_placement.start_transform();

         field.draw(piece_tiles_sprite_sheet, 16);
         current_player_figure.draw(piece_tiles_sprite_sheet, 16, true);

      field_placement.restore_transform();

      gameplay_hud->render_scene();
   placement.restore_transform();

   placement.draw_origin();
}

void PlayerGameplayGameboard::process_button_down_input(int gamer_input_screen_button_type)
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


void PlayerGameplayGameboard::process_button_up_input(int gamer_input_screen_button_type)
{
   switch(gamer_input_screen_button_type)
   {
   case GAMER_BUTTON_DOWN:
      emit_event(GAME_EVENT_NORMALIZE_DROP_SPEED);
      break;
   }
}


void PlayerGameplayGameboard::try_figure_movement_and_placement(ALLEGRO_EVENT &event)
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


void PlayerGameplayGameboard::place_and_respond_to_figure()
{
   if (field.will_place_above_the_top(current_player_figure))
   {
      emit_event(GAME_EVENT_PLAYER_LOST);
      return;
   }

   field.place_figure(current_player_figure);
   int num_lines_removed = field.remove_complete_lines();
   int lines_cleared_before = lines_cleared;
   int points_awarded = scoring_strategy.get_points_awarded(level, num_lines_removed);

   lines_cleared += num_lines_removed;
   score += points_awarded;

   if ((lines_cleared_before + num_lines_removed) / 10 > (lines_cleared_before / 10))
   {
      level++;
      emit_event(GAME_EVENT_HUD_UPDATE_LEVEL, level);
   }

   emit_event(GAME_EVENT_HUD_UPDATE_LINES_CLEARED, lines_cleared);
   emit_event(GAME_EVENT_HUD_UPDATE_SCORE, score);
   emit_event(GAME_EVENT_SPAWN_NEW_FIGURE);
}


void PlayerGameplayGameboard::process_event(ALLEGRO_EVENT &event)
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
      place_and_respond_to_figure();
      break;
   case GAME_EVENT_SPAWN_NEW_FIGURE:
      current_player_figure = next_figure;
      next_figure = figure_factory.make_random_shape();
      current_player_figure.move_x(4);
      current_player_figure.move_y(-2);
      if (current_player_figure.is_type(Figure::FIGURE_SHAPE_I)) pieces_since_last_longbar=0;
      else pieces_since_last_longbar++;
      emit_event(GAME_EVENT_HUD_UPDATE_PIECES_SINCE_LAST_LONGBAR, pieces_since_last_longbar);
      emit_event(GAME_EVENT_HUD_UPDATE_NEXT_FIGURE, next_figure.get_type());
      break;
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
   case GAMER_BUTTON_DOWN_EVENT:
      process_button_down_input(event.user.data1);
      break;
   case GAMER_BUTTON_UP_EVENT:
      process_button_up_input(event.user.data1);
      break;
   case GAME_EVENT_START_GAMEPLAY:
      state = PlayerGameplayGameboard::STATE_GAMEPLAY;
      timer = Timer();
      timer.start();
      level = 0;
      score = 0;
      lines_cleared = 0;
      pieces_since_last_longbar = 0;

      emit_event(GAME_EVENT_HUD_UPDATE_LEVEL, level);
      emit_event(GAME_EVENT_HUD_UPDATE_SCORE, score);
      emit_event(GAME_EVENT_HUD_UPDATE_LINES_CLEARED, lines_cleared);
      emit_event(GAME_EVENT_HUD_UPDATE_TIME, timer.get_elappsed_time_msec());
      emit_event(GAME_EVENT_HUD_UPDATE_PIECES_SINCE_LAST_LONGBAR, pieces_since_last_longbar);
      emit_event(GAME_EVENT_HUD_UPDATE_NEXT_FIGURE, next_figure.get_type());
      emit_event(GAME_EVENT_HUD_CLEAR_NOTIFICATION);

      emit_event(GAME_EVENT_SPAWN_NEW_FIGURE);
      break;
   case GAME_EVENT_PLAYER_LOST:
      state = PlayerGameplayGameboard::STATE_LOST;
      emit_event(GAME_EVENT_HUD_UPDATE_NOTIFICATION_GAME_OVER);
      timer.stop();
      break;
   default:
      gameplay_hud->process_event(event);
      //std::cout << "Unrecognized Event << " << std::endl;
      break;
   }
}


