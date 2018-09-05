#pragma once


#include <allegro5/allegro.h>
#include <framework/player_input_commands.hpp>
#include <map>


class PlayerInputConfiguration
{
private:
   ALLEGRO_JOYSTICK *joystick;
   bool use_joystick_axes_for_arrow_commands;
   std::map<int, player_input_command_t> joystick_mappings;
   std::map<int, player_input_command_t> keyboard_mappings;

public:
   float direction_values[4] = {0.0f};
   PlayerInputConfiguration();
   ~PlayerInputConfiguration();

   void set_joystick(ALLEGRO_JOYSTICK *joystick);
   void set_use_joystick_axes_for_arrow_commands(bool use=true);

   ALLEGRO_JOYSTICK *get_joystick();
   player_input_command_t get_keyboard_mapping(int al_keycode);
   player_input_command_t get_joystick_mapping(int joystick_button_num);

   bool is_joystick(ALLEGRO_JOYSTICK *joystick);
   bool is_usiing_joystick_axes_for_arrow_commands();

   void setup_default_keyboard_mapping_for_ARROW_KEYS();
   void setup_default_joystick_mapping_for_XBOX_360_WIRELESS_CONTROLLER();
};


