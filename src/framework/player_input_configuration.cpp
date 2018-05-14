

#include <framework/player_input_configuration.hpp>

#include <allegro5/allegro.h>


PlayerInputConfiguration::PlayerInputConfiguration()
   : joystick(nullptr)
   , joystick_mappings()
   , keyboard_mappings()
{
}


PlayerInputConfiguration::~PlayerInputConfiguration()
{
}


void PlayerInputConfiguration::set_joystick(ALLEGRO_JOYSTICK *joystick)
{
   this->joystick = joystick;
}


void PlayerInputConfiguration::set_use_joystick_axes_for_arrow_commands(bool use)
{
   use_joystick_axes_for_arrow_commands = use;
}


bool PlayerInputConfiguration::is_usiing_joystick_axes_for_arrow_commands()
{
   return use_joystick_axes_for_arrow_commands;
}


ALLEGRO_JOYSTICK *PlayerInputConfiguration::get_joystick()
{
   return joystick;
}


bool PlayerInputConfiguration::is_joystick(ALLEGRO_JOYSTICK *joystick)
{
   return this->joystick == joystick;
}


player_input_command_t PlayerInputConfiguration::get_keyboard_mapping(int al_keycode)
{
   std::map<int, player_input_command_t>::iterator it = keyboard_mappings.find(al_keycode);
   if (it == keyboard_mappings.end()) return PLAYER_INPUT_COMMAND_UNDEF;
   return it->second;
}


player_input_command_t PlayerInputConfiguration::get_joystick_mapping(int joystick_button_num)
{
   std::map<int, player_input_command_t>::iterator it = joystick_mappings.find(joystick_button_num);
   if (it == joystick_mappings.end()) return PLAYER_INPUT_COMMAND_UNDEF;
   return it->second;
}


void PlayerInputConfiguration::setup_default_keyboard_mapping_for_ARROW_KEYS()
{
   keyboard_mappings.clear();

   keyboard_mappings[ALLEGRO_KEY_UP] = PLAYER_INPUT_COMMAND_UP;
   keyboard_mappings[ALLEGRO_KEY_DOWN] = PLAYER_INPUT_COMMAND_DOWN;
   keyboard_mappings[ALLEGRO_KEY_LEFT] = PLAYER_INPUT_COMMAND_LEFT;
   keyboard_mappings[ALLEGRO_KEY_RIGHT] = PLAYER_INPUT_COMMAND_RIGHT;

   keyboard_mappings[ALLEGRO_KEY_ENTER] = PLAYER_INPUT_COMMAND_START;
   keyboard_mappings[ALLEGRO_KEY_BACKSPACE] = PLAYER_INPUT_COMMAND_BACK;
   keyboard_mappings[ALLEGRO_KEY_Z] = PLAYER_INPUT_COMMAND_A;
   keyboard_mappings[ALLEGRO_KEY_SPACE] = PLAYER_INPUT_COMMAND_B;
   keyboard_mappings[ALLEGRO_KEY_X] = PLAYER_INPUT_COMMAND_C;
}


void PlayerInputConfiguration::setup_default_joystick_mapping_for_XBOX_360_CONTROLLER()
{
   joystick_mappings.clear();

   // see http://html5gamepad.com/ to test mappings (however the numberings are not consistent)

   joystick_mappings[0] = PLAYER_INPUT_COMMAND_DOWN;
   joystick_mappings[1] = PLAYER_INPUT_COMMAND_RIGHT;
   joystick_mappings[3] = PLAYER_INPUT_COMMAND_LEFT;
   joystick_mappings[4] = PLAYER_INPUT_COMMAND_UP;
}


