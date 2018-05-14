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
   PlayerInputConfiguration();
   ~PlayerInputConfiguration();

   void set_joystick(ALLEGRO_JOYSTICK *joystick);
   void set_use_joystick_axes_for_arrow_commands(bool use=true);

   bool is_usiing_joystick_axes_for_arrow_commands();
   ALLEGRO_JOYSTICK *get_joystick();
   bool is_joystick(ALLEGRO_JOYSTICK *joystick);

   player_input_command_t get_keyboard_mapping(int al_keycode);
   player_input_command_t get_joystick_mapping(int joystick_button_num);

   void setup_default_keyboard_mapping_for_ARROW_KEYS();
   void setup_default_joystick_mapping_for_XBOX_360_CONTROLLER();
};


