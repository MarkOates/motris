#pragma once


#include <motris/ui_components/gameplay_hud_interface.hpp>
#include <motris/ui_components/labeled_timer.hpp>
#include <motris/ui_components/labeled_text.hpp>
#include <motris/models/field.hpp>
#include <allegro5/allegro_font.h>


class GameplayHUD : public GameplayHUDInterface
{
private:
   friend class PlayerGameplayGameboard;

   ALLEGRO_FONT *label_font;
   ALLEGRO_FONT *value_font;
   ALLEGRO_FONT *small_value_font;
   ALLEGRO_FONT *large_font;

   SpriteSheet sprite_sheet;
   Field next_figure_field;

   LabeledText level;
   LabeledText score;
   LabeledText lines_cleared;
   LabeledText next;
   LabeledText since_last_longbar;
   LabeledTimer time;

   Text notification;

public:
   GameplayHUD();
   ~GameplayHUD();

   void set_next_figure(Figure::figure_t type);

   void update_scene() override;
   void render_scene() override;
   void process_event(ALLEGRO_EVENT &event) override;
};


