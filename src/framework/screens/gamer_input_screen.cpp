

#include <framework/screens/gamer_input_screen.hpp>


GamerInputScreen::GamerInputScreen()
   : Screen()
{
   al_init_user_event_source(&input_event_source);
   al_register_event_source(master_event_queue, &input_event_source);
}


GamerInputScreen::~GamerInputScreen()
{
   // uninit user event source?
   //al_init_user_event_source(&my_event_source);
   al_unregister_event_source(master_event_queue, &input_event_source);
}


void GamerInputScreen::emit_gamer_command_up(int player_num, player_input_command_t button)
{
   ALLEGRO_EVENT my_event;
   my_event.user.type = GAMER_BUTTON_UP_EVENT;
   my_event.user.data1 = player_num;
   my_event.user.data2 = button;
   //pressed[button] = false;
   al_emit_user_event(&input_event_source, &my_event, NULL);
}


void GamerInputScreen::emit_gamer_command_down(int player_num, player_input_command_t button)
{
   ALLEGRO_EVENT my_event;
   my_event.user.type = GAMER_BUTTON_DOWN_EVENT;
   my_event.user.data1 = player_num;
   my_event.user.data2 = button;
   //pressed[button] = true;
   al_emit_user_event(&input_event_source, &my_event, NULL);
}


void GamerInputScreen::key_down_func(ALLEGRO_EVENT &event)
{
   for (auto &player_input_configuration : player_input_configurations)
   {
      player_input_command_t command = player_input_configuration.second.get_keyboard_mapping(event.keyboard.keycode);
      if (command != PLAYER_INPUT_COMMAND_UNDEF) emit_gamer_command_down(player_input_configuration.first, command);
   }
}


void GamerInputScreen::key_up_func(ALLEGRO_EVENT &event)
{
   for (auto &player_input_configuration : player_input_configurations)
   {
      player_input_command_t command = player_input_configuration.second.get_keyboard_mapping(event.keyboard.keycode);
      if (command != PLAYER_INPUT_COMMAND_UNDEF) emit_gamer_command_up(player_input_configuration.first, command);
   }
}


void GamerInputScreen::joy_axis_func(ALLEGRO_EVENT &event)
{
}


void GamerInputScreen::joy_button_down_func(ALLEGRO_EVENT &event)
{
   for (auto &player_input_configuration : player_input_configurations)
   {
      player_input_command_t command = player_input_configuration.second.get_joystick_mapping(event.joystick.button);
      if (command != PLAYER_INPUT_COMMAND_UNDEF) emit_gamer_command_down(player_input_configuration.first, command);
   }
}


void GamerInputScreen::joy_button_up_func(ALLEGRO_EVENT &event)
{
   for (auto &player_input_configuration : player_input_configurations)
   {
      player_input_command_t command = player_input_configuration.second.get_joystick_mapping(event.joystick.button);
      if (command != PLAYER_INPUT_COMMAND_UNDEF) emit_gamer_command_up(player_input_configuration.first, command);
   }
}


void GamerInputScreen::joy_config_func(ALLEGRO_EVENT &event)
{
}


void GamerInputScreen::process_event(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case ALLEGRO_EVENT_KEY_DOWN:
      key_down_func(event);
      break;
   case ALLEGRO_EVENT_KEY_UP:
      key_up_func(event);
      break;
   case ALLEGRO_EVENT_JOYSTICK_AXIS:
      joy_axis_func(event);
      break;
   case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
      joy_button_down_func(event);
      break;
   case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
      joy_button_up_func(event);
      break;
   case ALLEGRO_EVENT_JOYSTICK_CONFIGURATION:
      joy_config_func(event);
      break;
   }
}


