

#include <motris/ui_components/gameplay_hud.hpp>

#include <motris/factories/figure_factory.hpp>
#include <framework/color.hpp>
#include <motris/events.hpp>


static int const SCREEN_W = 1792;
static int const SCREEN_H = 1008;
static int const GAMEPLAY_X = 0;
static int const GAMEPLAY_Y = (SCREEN_H/2);
static int const LEFT_COLUMN_X = (-250);
static int const RIGHT_COLUMN_X = (250);


GameplayHUD::GameplayHUD()
   : label_font(al_load_font("data/fonts/LeagueGothic-Regular.otf", 36, 0))
   , value_font(al_load_font("data/fonts/Questrial-Regular.ttf", 70, 0))
   , small_value_font(al_load_font("data/fonts/Questrial-Regular.ttf", 50, 0))
   , large_font(al_load_font("data/fonts/Questrial-Regular.ttf", 140, 0))
   , sprite_sheet(al_load_bitmap("data/bitmaps/piece_tiles.png"), 16, 16)
   , next_figure_field(4, 5)
   , level(label_font, large_font, "LEVEL", "13", LEFT_COLUMN_X, 200 - GAMEPLAY_Y, 1.0)
   , score(label_font, value_font, "SCORE", "6273459", LEFT_COLUMN_X, 500 - GAMEPLAY_Y, 1.0)
   , lines_cleared(label_font, value_font, "LINES CLEARED", "129", LEFT_COLUMN_X, 650 - GAMEPLAY_Y, 1.0)
   , next(label_font, value_font, "NEXT", "", RIGHT_COLUMN_X, 200 - GAMEPLAY_Y, 0.0)
   , since_last_longbar(label_font, value_font, "SINCE LAST LONGBAR", "29", RIGHT_COLUMN_X, 500 - GAMEPLAY_Y, 0.0)
   , time(label_font, value_font, small_value_font, "TIME", "-", RIGHT_COLUMN_X, 650 - GAMEPLAY_Y, 0.0)
   , notification(value_font, "", 880 - GAMEPLAY_X, 500 - GAMEPLAY_Y, color::white)
{
   if (!label_font) throw std::runtime_error("label_font not loaded");
   if (!value_font) throw std::runtime_error("value_font not loaded");
   if (!small_value_font) throw std::runtime_error("small_value_font not loaded");
}


GameplayHUD::~GameplayHUD()
{
   al_destroy_font(label_font);
   al_destroy_font(value_font);
   al_destroy_font(small_value_font);
}


void GameplayHUD::update_scene()
{
}


void GameplayHUD::render_scene()
{
   level.draw();
   lines_cleared.draw();
   score.draw();
   next.draw();
   placement2d next_figure_placement(RIGHT_COLUMN_X, 250 - GAMEPLAY_Y, 0, 0);
   next_figure_placement.scale = vec2d(3, 3);
   next_figure_placement.start_transform();
   next_figure_field.draw(sprite_sheet, 12);
   next_figure_placement.restore_transform();
   since_last_longbar.draw();
   time.draw();

   notification.draw();
}


void GameplayHUD::set_next_figure(Figure::figure_t type)
{
   FigureFactory figure_factory;
   Figure constructed_figure = figure_factory.make_figure(type);
   constructed_figure.move_x(1);
   next_figure_field.clear();
   next_figure_field.place_figure(constructed_figure);
}


void GameplayHUD::process_event(ALLEGRO_EVENT &event)
{
   switch (event.type)
   {
   case GAME_EVENT_HUD_UPDATE_SCORE:
      score.set_value(event.user.data1);
      break;
   case GAME_EVENT_HUD_UPDATE_LEVEL:
      level.set_value(event.user.data1);
      break;
   case GAME_EVENT_HUD_UPDATE_LINES_CLEARED:
      lines_cleared.set_value(event.user.data1);
      break;
   case GAME_EVENT_HUD_UPDATE_TIME:
      time.set_value(event.user.data1);
      break;
   case GAME_EVENT_HUD_UPDATE_PIECES_SINCE_LAST_LONGBAR:
      since_last_longbar.set_value(event.user.data1);
      break;
   case GAME_EVENT_HUD_UPDATE_NEXT_FIGURE:
      set_next_figure(static_cast<Figure::figure_t>(event.user.data1));
      break;
   case GAME_EVENT_HUD_UPDATE_NOTIFICATION_GAME_OVER:
      notification.set_text("Game Over").set_placement_size_to_text();
      break;
   case GAME_EVENT_HUD_CLEAR_NOTIFICATION:
      notification.set_text("");
      break;
   default:
      break;
   }
}


