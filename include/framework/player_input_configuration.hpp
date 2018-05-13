#pragma once


#include <framework/player_input_commands.hpp>
#include <map>


class PlayerInputConfiguration
{
private:
   int joystick_num;
   bool use_joystick_axes_for_arrow_commands;
   std::map<int, player_input_command_t> joystick_mappings;
   std::map<int, player_input_command_t> keyboard_mappings;

public:
   PlayerInputConfiguration();
   ~PlayerInputConfiguration();

   void set_joystick_num(int joystick_num);
   //void add_keyboard_mapping(player_input_command_t button, int al_keycode);
   //void add_joystic_mapping(player_input_command_t button, int joystick_button_num);
   void set_use_joystick_axes_for_arrow_commands(bool use=true);

   bool is_usiing_joystick_axes_for_arrow_commands();

   bool is_joystick_num(int joystick_num);
   player_input_command_t get_keyboard_mapping(int al_keycode);
   player_input_command_t get_joystick_mapping(int joystick_button_num);

   void setup_default_keyboard_mapping_for_ARROW_KEYS();
   void setup_default_joystick_mapping_for_XBOX_360_CONTROLLER();
};


