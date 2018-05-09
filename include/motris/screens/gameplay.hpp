#pragma once


#include <motris/factories/figure_factory.hpp>
#include <motris/models/field.hpp>
#include <motris/models/figure.hpp>
#include <allegro5/allegro.h>
#include <framework/screen.hpp>
#include <framework/sprite_sheet.hpp>


enum game_events
{
   GAME_EVENT_FIGURE_DROP = ALLEGRO_GET_EVENT_TYPE('M','t','r','s'),
   GAME_EVENT_ROTATE_FIGURE,
   GAME_EVENT_MOVE_FIGURE_LEFT,
   GAME_EVENT_MOVE_FIGURE_RIGHT,
   GAME_EVENT_PLACE_FIGURE,
   GAME_EVENT_ACCELERATE_DROP,
   GAME_EVENT_NORMALIZE_DROP_SPEED,
   GAME_EVENT_SPAWN_NEW_FIGURE,
};


class Gameplay : public Screen
{
private:
   SpriteSheet piece_tiles_sprite_sheet;
   FigureFactory figure_factory;
   Field field;
   Figure current_player_figure;
   float drop_rate_per_second;
   float drop_rate_counter;

public:
   Gameplay();

   void update_scene();
   void render_scene();
   void process_button_up_input(int gamer_input_screen_button_type);
   void process_button_down_input(int gamer_input_screen_button_type);

   void try_figure_movement_and_placement(ALLEGRO_EVENT &event);
   void process_event(ALLEGRO_EVENT &event) override;
};


