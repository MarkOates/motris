

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
   std::cout << "==== JOY AXIS" << std::endl;

   int stick = event.joystick.stick;
   int axis = event.joystick.axis;
   float pos = event.joystick.pos;

   std::cout << "stick: " << stick << "    axis: " << axis << "   pos: " << pos << std::endl;

   for (auto &player_input_configuration : player_input_configurations)
   {
      PlayerInputConfiguration &configuration = player_input_configuration.second;
      //if (!configuration.uses_joystick(event.joystick.id)) continue;
      //if (!configuration.is_usiing_joystick_axes_for_arrow_commands()) continue;

      switch (event.joystick.stick)
      {
      //case 0:
         //if (axis == 0) state->left_stick_x = pos;
         //else if (axis == 1) state->left_stick_y = pos;
         //break;
      //case 1:
         //if (axis == 0) state->left_trigger = (pos + 1.0) / 2.0;
         //else if (axis == 1) state->right_stick_x = pos;
         //break;
      ////case 2:
       ////  if (axis == 0) state->right_stick_y = pos;
        //// else if (axis == 1) state->right_trigger = (pos + 1.0) / 2.0;
         ////break;
      //case 3:
         //if (axis == 0) state->dpad_x = pos;
         //else if (axis == 1) state->dpad_y = pos;
         //break;
      //default:
         //break;
      }
   }
}


void GamerInputScreen::joy_button_down_func(ALLEGRO_EVENT &event)
{
   std::cout << "==== JOY DOWN" << std::endl;
   for (auto &player_input_configuration : player_input_configurations)
   {
      if (!player_input_configuration.second.uses_joystick(event.joystick.id)) continue;
      player_input_command_t command = player_input_configuration.second.get_joystick_mapping(event.joystick.button);
      if (command != PLAYER_INPUT_COMMAND_UNDEF) emit_gamer_command_down(player_input_configuration.first, command);
   }
}


void GamerInputScreen::joy_button_up_func(ALLEGRO_EVENT &event)
{
   std::cout << "==== JOY UP" << std::endl;
   for (auto &player_input_configuration : player_input_configurations)
   {
      if (!player_input_configuration.second.uses_joystick(event.joystick.id)) continue;
      player_input_command_t command = player_input_configuration.second.get_joystick_mapping(event.joystick.button);
      if (command != PLAYER_INPUT_COMMAND_UNDEF) emit_gamer_command_up(player_input_configuration.first, command);
   }
}


void GamerInputScreen::joy_config_func(ALLEGRO_EVENT &event)
{
}


void GamerInputScreen::test_for_new_player_input_mappings(ALLEGRO_EVENT &event)
{
   switch(event.type)
   {
   case ALLEGRO_EVENT_KEY_DOWN:
   case ALLEGRO_EVENT_KEY_UP:
   case ALLEGRO_EVENT_KEY_CHAR:
      {
         if (!keyboard_detected)
         {
            keyboard_detected = true;
            players.push_back(PlayerInputConfiguration());
            PlayerInputConfiguration &config = players.back();
            config.setup_default_keyboard_mapping_for_ARROW_KEYS();
            emit_event(NEW_PLAYER_CREATED, players.size());
         }
      }
      break;
   case ALLEGRO_EVENT_JOYSTICK_AXIS:
   case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
   case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
   //case ALLEGRO_EVENT_JOYSTICK_CONFIGURATION:
      {
         ALLEGRO_JOYSTICK *joystick_used = event.joystick.id;
         std::vector<ALLEGRO_JOYSTICK *>::iterator it = std::find(joysticks_detected.begin(), joysticks_detected.end(), joystick_used);
         if (it == joysticks_detected.end())
         {
            joysticks_detected.push_back(joystick_used);
            players.push_back(PlayerInputConfiguration());
            PlayerInputConfiguration &config = players.back();
            config.setup_default_joystick_mapping_for_XBOX_360_CONTROLLER();
            emit_event(NEW_PLAYER_CREATED, players.size());
         }
      }
      joy_config_func(event);
      break;
   }
}


void GamerInputScreen::process_event(ALLEGRO_EVENT &event)
{
   test_for_new_player_input_mappings(event);

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
   case NEW_PLAYER_CREATED:
      break;
   }
}


