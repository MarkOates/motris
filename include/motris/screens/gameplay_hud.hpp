#pragma once


#include <motris/ui_components/labeled_text.hpp>
#include <allegro5/allegro_font.h>
#include <framework/screen.hpp>


class GameplayHUD : public Screen
{
private:
   ALLEGRO_FONT *label_font;
   ALLEGRO_FONT *value_font;
   ALLEGRO_FONT *large_font;

   LabeledText level;
   LabeledText score;
   LabeledText lines_cleared;
   LabeledText next;
   LabeledText since_last_longbar;
   LabeledText time;

public:
   GameplayHUD();
   ~GameplayHUD();

   void update_scene();
   void render_scene();

   void process_event(ALLEGRO_EVENT &event) override;
};


