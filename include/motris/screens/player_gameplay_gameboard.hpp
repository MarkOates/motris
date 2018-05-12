#pragma once


#include <motris/factories/figure_factory.hpp>
#include <motris/models/field.hpp>
#include <motris/models/figure.hpp>
#include <motris/models/timer.hpp>
#include <motris/strategies/scoring_strategy.hpp>
#include <motris/ui_components/gameplay_hud.hpp>
#include <allegro5/allegro.h>
#include <framework/screen.hpp>
#include <framework/sprite_sheet.hpp>


class PlayerGameplayGameboard : public Screen
{
private:
   enum state_t
   {
      STATE_UNDEF = 0,
      STATE_GAMEPLAY,
      STATE_LOST,
   };

   GameplayHUD gameplay_hud;
   SpriteSheet piece_tiles_sprite_sheet;
   FigureFactory figure_factory;
   Field field;
   Figure current_player_figure;
   Figure next_figure;
   float drop_rate_per_second;
   float drop_rate_counter;
   ScoringStrategy scoring_strategy;

   Timer timer;
   int level;
   int score;
   int lines_cleared;
   int pieces_since_last_longbar;

   state_t state;

public:
   PlayerGameplayGameboard();

   void update_scene();
   void render_scene();
   void process_button_up_input(int gamer_input_screen_button_type);
   void process_button_down_input(int gamer_input_screen_button_type);

   void try_figure_movement_and_placement(ALLEGRO_EVENT &event);
   void place_and_respond_to_figure();
   void process_event(ALLEGRO_EVENT &event) override;
};


