

#include <motris/screens/gameplay_hud.hpp>


#define LEFT_COLUMN_X 550
#define RIGHT_COLUMN_X 1200


GameplayHUD::GameplayHUD()
   : label_font(al_load_font("data/fonts/LeagueGothic-Regular.otf", 36, 0))
   , value_font(al_load_font("data/fonts/Questrial-Regular.ttf", 70, 0))
   , large_font(al_load_font("data/fonts/Questrial-Regular.ttf", 140, 0))
   , level(label_font, large_font, "LEVEL", "13", LEFT_COLUMN_X, 200, 1.0)
   , score(label_font, value_font, "SCORE", "6273459", LEFT_COLUMN_X, 500, 1.0)
   , lines_cleared(label_font, value_font, "LINES CLEARED", "129", LEFT_COLUMN_X, 650, 1.0)
   , next(label_font, value_font, "NEXT", "", RIGHT_COLUMN_X, 200, 0.0)
   , since_last_longbar(label_font, value_font, "SINCE LAST LONGBAR", "29", RIGHT_COLUMN_X, 500, 0.0)
   , time(label_font, value_font, "TIME", "0:32", RIGHT_COLUMN_X, 650, 0.0)
{
   if (!label_font) throw std::runtime_error("label_font not loaded");
   if (!value_font) throw std::runtime_error("value_font not loaded");
}


GameplayHUD::~GameplayHUD()
{
   al_destroy_font(label_font);
   al_destroy_font(value_font);
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
   since_last_longbar.draw();
   time.draw();
}


void GameplayHUD::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case ALLEGRO_EVENT_TIMER:
      update_scene();
      render_scene();
      break;
   default:
      std::cout << "GameplayHUD Unrecognized Event << " << std::endl;
      break;
   }
}


