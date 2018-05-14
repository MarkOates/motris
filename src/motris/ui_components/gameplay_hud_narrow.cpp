

#include <motris/ui_components/gameplay_hud_narrow.hpp>

#include <motris/factories/figure_factory.hpp>
#include <motris/helpers/score_number_formatter.hpp>
#include <framework/color.hpp>
#include <motris/events.hpp>


static int const SCREEN_W = 1792;
static int const SCREEN_H = 1008;
static int const GAMEPLAY_X = 0;
static int const GAMEPLAY_Y = (SCREEN_H/2);
static int const LEFT_COLUMN_X = (-250);
static int const RIGHT_COLUMN_X = (250);


GameplayHUDNarrow::GameplayHUDNarrow(std::string player_name_str)
   : player_name_font(al_load_font("data/fonts/Questrial-Regular.ttf", 45, 0))
   , label_font(al_load_font("data/fonts/LeagueGothic-Regular.otf", 42, 0))
   , value_font(al_load_font("data/fonts/Questrial-Regular.ttf", 42, 0))
   , notification_font(al_load_font("data/fonts/Questrial-Regular.ttf", 70, 0))
   , sprite_sheet(al_load_bitmap("data/bitmaps/piece_tiles.png"), 16, 16)
   , next_figure_field(4, 5)
   , player_name(player_name_font, player_name_str, -210, -475, color::white)
   , level(label_font, value_font, "LEVEL", "12", -146, 472)
   , score(label_font, value_font, "SCORE", ScoreNumberFormatter(0).get_formatted_score(), 46, 472)
   , lines(label_font, value_font, "LINES", "14", 46, 520)
   , notification(notification_font, "", 0, 500 - GAMEPLAY_Y, color::white)
{
   player_name.placement.align.x = 0.0;

   if (!player_name_font) throw std::runtime_error("small_value_font not loaded");
   if (!label_font) throw std::runtime_error("label_font not loaded");
   if (!value_font) throw std::runtime_error("value_font not loaded");
}


GameplayHUDNarrow::~GameplayHUDNarrow()
{
   al_destroy_font(player_name_font);
   al_destroy_font(label_font);
   al_destroy_font(value_font);
   al_destroy_font(notification_font);
}


void GameplayHUDNarrow::update_scene()
{
}


void GameplayHUDNarrow::render_scene()
{
   player_name.draw();
   player_name.placement.draw_origin();

   placement2d next_figure_placement(215, -585, 0, 0);
   next_figure_placement.scale = vec2d(2.5, 2.5);
   next_figure_placement.rotation = ALLEGRO_PI * 2 * 0.25;
   next_figure_placement.start_transform();
   next_figure_field.draw(sprite_sheet, 12);
   next_figure_placement.restore_transform();

   level.draw();
   score.draw();
   lines.draw();

   notification.draw();
}


void GameplayHUDNarrow::set_next_figure(Figure::figure_t type)
{
   FigureFactory figure_factory;
   Figure constructed_figure = figure_factory.make_figure(type);
   constructed_figure.move_x(1);
   next_figure_field.clear();
   next_figure_field.place_figure(constructed_figure);
}


void GameplayHUDNarrow::process_event(ALLEGRO_EVENT &event)
{
   switch (event.type)
   {
   case GAME_EVENT_HUD_UPDATE_SCORE:
      score.set_value(ScoreNumberFormatter(event.user.data2).get_formatted_score());
      break;
   case GAME_EVENT_HUD_UPDATE_LEVEL:
      level.set_value(event.user.data2);
      break;
   case GAME_EVENT_HUD_UPDATE_LINES_CLEARED:
      lines.set_value(event.user.data2);
      break;
   case GAME_EVENT_HUD_UPDATE_NEXT_FIGURE:
      set_next_figure(static_cast<Figure::figure_t>(event.user.data2));
      break;
   case GAME_EVENT_HUD_UPDATE_NOTIFICATION_GAME_OVER:
      notification.set_text("GAME OVER").set_placement_size_to_text();
      break;
   case GAME_EVENT_HUD_CLEAR_NOTIFICATION:
      notification.set_text("").set_placement_size_to_text();
      break;
   case GAME_EVENT_HUD_UPDATE_TIME:
   case GAME_EVENT_HUD_UPDATE_PIECES_SINCE_LAST_LONGBAR:
   default:
      break;
   }
}



