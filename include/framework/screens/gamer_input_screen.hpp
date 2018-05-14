#pragma once


#include <framework/framework.hpp>
#include <framework/player_input_commands.hpp>
#include <framework/player_input_configuration.hpp>
#include <map>

#define GAMER_BUTTON_UP_EVENT ALLEGRO_GET_EVENT_TYPE('N','P','T','U')
#define GAMER_BUTTON_DOWN_EVENT ALLEGRO_GET_EVENT_TYPE('N','P','T','D')


class GamerInputScreen : public Screen
{
private:
   ALLEGRO_EVENT_SOURCE input_event_source;

   void key_down_func(ALLEGRO_EVENT &event);
   void key_up_func(ALLEGRO_EVENT &event);
   void joy_axis_func(ALLEGRO_EVENT &event);
   void joy_button_down_func(ALLEGRO_EVENT &event);
   void joy_button_up_func(ALLEGRO_EVENT &event);
   void joy_config_func(ALLEGRO_EVENT &event);

public:
   std::map<int, PlayerInputConfiguration> player_input_configurations;

   GamerInputScreen();
   ~GamerInputScreen();

   void process_event(ALLEGRO_EVENT &event) override;

   void emit_gamer_command_up(int player_num, player_input_command_t button);
   void emit_gamer_command_down(int player_num, player_input_command_t button);
};


