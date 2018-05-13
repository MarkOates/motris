#pragma once


#include <map>


enum button_t
{
   GAMER_BUTTON_UNDEF = 0,
   GAMER_BUTTON_UP,
   GAMER_BUTTON_DOWN,
   GAMER_BUTTON_LEFT,
   GAMER_BUTTON_RIGHT,
   GAMER_BUTTON_START,
   GAMER_BUTTON_BACK,
   GAMER_BUTTON_A,
   GAMER_BUTTON_B,
   GAMER_BUTTON_C,
   GAMER_BUTTON_SIZE_MAX,
};


class PlayerInputConfiguration
{
private:
   int joystick_num;
   std::map<button_t, int> joystick_mappings;
   std::map<button_t, int> keyboard_mappings;

public:
   PlayerInputConfiguration();
   ~PlayerInputConfiguration();

   void set_joystick_num(int joystick_num);
   void add_joystic_mapping(button_t button, int joy_button_num);
   void add_keyboard_mapping(button_t button, int allegro_keycode);

   void setup_default_keyboard_mapping_for_ARROW_KEYS();
   void setup_default_joystick_mapping_for_XBOX_360_CONTROLLER();
   void setup_default_joystick_mapping_for_LOGITECH_RUMBLEPAD_2();
};


