#pragma once


#include <framework/framework.hpp>
#include <framework/player_input_commands.hpp>
#include <framework/player_input_configuration.hpp>
#include <map>

#define NEW_PLAYER_CREATED      ALLEGRO_GET_EVENT_TYPE('N','u','P','l')
#define GAMER_BUTTON_UP_EVENT   ALLEGRO_GET_EVENT_TYPE('N','P','T','U')
#define GAMER_BUTTON_DOWN_EVENT ALLEGRO_GET_EVENT_TYPE('N','P','T','D')


class GamerInputScreen : public Screen
{
private:
   bool keyboard_detected;
   std::vector<ALLEGRO_JOYSTICK *> joysticks_detected;
   std::vector<PlayerInputConfiguration> players;

   ALLEGRO_EVENT_SOURCE input_event_source;

   void key_down_func(ALLEGRO_EVENT &event);
   void key_up_func(ALLEGRO_EVENT &event);
   void joy_axis_func(ALLEGRO_EVENT &event);
   void joy_button_down_func(ALLEGRO_EVENT &event);
   void joy_button_up_func(ALLEGRO_EVENT &event);
   void joy_config_func(ALLEGRO_EVENT &event);

   void test_for_new_player_input_mappings(ALLEGRO_EVENT &event);
   void emit_gamer_command_up(int player_num, player_input_command_t button);
   void emit_gamer_command_down(int player_num, player_input_command_t button);

public:
   std::map<int, PlayerInputConfiguration> player_input_configurations;

   GamerInputScreen();
   ~GamerInputScreen();

   void process_event(ALLEGRO_EVENT &event) override;
};


