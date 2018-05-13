#pragma once


#include <motris/ui_components/gameplay_hud_interface.hpp>
#include <motris/ui_components/labeled_text_narrow.hpp>
#include <motris/models/field.hpp>
#include <allegro5/allegro_font.h>


class GameplayHUDNarrow : public GameplayHUDInterface
{
private:
   friend class PlayerGameplayGameboard;

   ALLEGRO_FONT *player_name_font;
   ALLEGRO_FONT *label_font;
   ALLEGRO_FONT *value_font;
   ALLEGRO_FONT *notification_font;

   SpriteSheet sprite_sheet;
   Field next_figure_field;

   Text player_name;
   LabeledTextNarrow level;
   LabeledTextNarrow score;
   LabeledTextNarrow lines;

   Text notification;

public:
   GameplayHUDNarrow();
   ~GameplayHUDNarrow();

   void set_next_figure(Figure::figure_t type);

   void update_scene() override;
   void render_scene() override;
   void process_event(ALLEGRO_EVENT &event) override;
};


