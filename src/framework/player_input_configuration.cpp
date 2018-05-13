

#include <framework/player_input_configuration.hpp>


PlayerInputConfiguration::PlayerInputConfiguration()
   : joystick_num(0)
   , joystick_mappings()
   , keyboard_mappings()
{
}


PlayerInputConfiguration::~PlayerInputConfiguration()
{
}


void PlayerInputConfiguration::setup_default_keyboard_mapping_for_ARROW_KEYS()
{
   keyboard_mappings.clear();
   //button_up_keyboard_keymap = ALLEGRO_KEY_UP;
   //button_down_keyboard_keymap = ALLEGRO_KEY_DOWN;
   //button_left_keyboard_keymap = ALLEGRO_KEY_LEFT;
   //button_right_keyboard_keymap = ALLEGRO_KEY_RIGHT;
   //button_start_keyboard_keymap = ALLEGRO_KEY_ENTER;
   //button_back_keyboard_keymap = ALLEGRO_KEY_BACKSPACE;
   //button_a_keyboard_keymap = ALLEGRO_KEY_Z;
   //button_b_keyboard_keymap = ALLEGRO_KEY_SPACE;
   //button_c_keyboard_keymap = ALLEGRO_KEY_X;
}


void PlayerInputConfiguration::setup_default_joystick_mapping_for_LOGITECH_RUMBLEPAD_2()
{
   //button_up_joystick_buttonmap = 999;
   //button_down_joystick_buttonmap = 999;
   //button_left_joystick_buttonmap = 999;
   //button_right_joystick_buttonmap = 999;
   //button_start_joystick_buttonmap = 9;
   //button_back_joystick_buttonmap = 8;
   //button_a_joystick_buttonmap = 0;
   //button_b_joystick_buttonmap = 1;
   //button_c_joystick_buttonmap = 2;
}


void PlayerInputConfiguration::setup_default_joystick_mapping_for_XBOX_360_CONTROLLER()
{
   //button_up_joystick_buttonmap = 999;
   //button_down_joystick_buttonmap = 999;
   //button_left_joystick_buttonmap = 999;
   //button_right_joystick_buttonmap = 999;
   //button_start_joystick_buttonmap = 11;
   //button_back_joystick_buttonmap = 6;
   //button_a_joystick_buttonmap = 3;
   //button_b_joystick_buttonmap = 0;
   //button_c_joystick_buttonmap = 1;
}


