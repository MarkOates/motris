



#include <framework/screens/gamer_input_screen.hpp>
#include <framework/color.hpp>

#include <math.h>



static const int PLAYER_NUM = 1;




GamerInputScreen::GamerInputScreen()
   : Screen()
{
   al_init_user_event_source(&input_event_source);
   al_register_event_source(master_event_queue, &input_event_source);
   setup_default_joystick_mapping_for_XBOX_360_CONTROLLER();
      setup_default_keyboard_mapping_for_ARROW_KEYS();
}




GamerInputScreen::~GamerInputScreen()
{
   // uninit user event source?
   //al_init_user_event_source(&my_event_source);
   al_unregister_event_source(master_event_queue, &input_event_source);
}




std::string GamerInputScreen::get_button_name(button_t button)
{
   switch(button)
   {
   case GAMER_BUTTON_UNDEF: return "[UNDEF]"; break;
   case GAMER_BUTTON_UP: return "UP"; break;
   case GAMER_BUTTON_DOWN: return "DOWN"; break;
   case GAMER_BUTTON_LEFT: return "LEFT"; break;
   case GAMER_BUTTON_RIGHT: return "RIGHT"; break;
   case GAMER_BUTTON_START: return "START"; break;
   case GAMER_BUTTON_BACK: return "BACK"; break;
   case GAMER_BUTTON_A: return "A"; break;
   case GAMER_BUTTON_B: return "B"; break;
   case GAMER_BUTTON_C: return "C"; break;
   case GAMER_BUTTON_SIZE_MAX: return "[MAX]"; break;
   }
   return "[UNDEF]";
}




bool GamerInputScreen::is_pressed(button_t button)
{
   return pressed[button];
}




void GamerInputScreen::emit_gamer_button_up(button_t button)
{
   ALLEGRO_EVENT my_event;
   my_event.user.type = GAMER_BUTTON_UP_EVENT;
   my_event.user.data1 = PLAYER_NUM;
   my_event.user.data2 = button;
   pressed[button] = false;
   al_emit_user_event(&input_event_source, &my_event, NULL);
}




void GamerInputScreen::emit_gamer_button_down(button_t button)
{
   ALLEGRO_EVENT my_event;
   my_event.user.type = GAMER_BUTTON_DOWN_EVENT;
   my_event.user.data1 = PLAYER_NUM;
   my_event.user.data2 = button;
   pressed[button] = true;
   al_emit_user_event(&input_event_source, &my_event, NULL);
}




void GamerInputScreen::setup_default_keyboard_mapping_for_ARROW_KEYS()
{
   button_up_keyboard_keymap = ALLEGRO_KEY_UP;
   button_down_keyboard_keymap = ALLEGRO_KEY_DOWN;
   button_left_keyboard_keymap = ALLEGRO_KEY_LEFT;
   button_right_keyboard_keymap = ALLEGRO_KEY_RIGHT;
   button_start_keyboard_keymap = ALLEGRO_KEY_ENTER;
   button_back_keyboard_keymap = ALLEGRO_KEY_BACKSPACE;
   button_a_keyboard_keymap = ALLEGRO_KEY_Z;
   button_b_keyboard_keymap = ALLEGRO_KEY_SPACE;
   button_c_keyboard_keymap = ALLEGRO_KEY_X;
}




void GamerInputScreen::setup_default_joystick_mapping_for_LOGITECH_RUMBLEPAD_2()
{
   button_up_joystick_buttonmap = 999;
   button_down_joystick_buttonmap = 999;
   button_left_joystick_buttonmap = 999;
   button_right_joystick_buttonmap = 999;
   button_start_joystick_buttonmap = 9;
   button_back_joystick_buttonmap = 8;
   button_a_joystick_buttonmap = 0;
   button_b_joystick_buttonmap = 1;
   button_c_joystick_buttonmap = 2;
}




void GamerInputScreen::setup_default_joystick_mapping_for_XBOX_360_CONTROLLER()
{
   button_up_joystick_buttonmap = 999;
   button_down_joystick_buttonmap = 999;
   button_left_joystick_buttonmap = 999;
   button_right_joystick_buttonmap = 999;
   button_start_joystick_buttonmap = 11;
   button_back_joystick_buttonmap = 6;
   button_a_joystick_buttonmap = 3;
   button_b_joystick_buttonmap = 0;
   button_c_joystick_buttonmap = 1;
}




/// /// /// /// ///




void GamerInputScreen::key_down_func(ALLEGRO_EVENT &event)
{
   if (event.keyboard.keycode == button_up_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_UP);
   else if (event.keyboard.keycode == button_down_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_DOWN);
   else if (event.keyboard.keycode == button_left_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_LEFT);
   else if (event.keyboard.keycode == button_right_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_RIGHT);
   else if (event.keyboard.keycode == button_start_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_START);
   else if (event.keyboard.keycode == button_back_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_BACK);
   else if (event.keyboard.keycode == button_a_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_A);
   else if (event.keyboard.keycode == button_b_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_B);
   else if (event.keyboard.keycode == button_c_keyboard_keymap) emit_gamer_button_down(GAMER_BUTTON_C);
}




void GamerInputScreen::key_up_func(ALLEGRO_EVENT &event)
{
   if (event.keyboard.keycode == button_up_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_UP);
   else if (event.keyboard.keycode == button_down_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_DOWN);
   else if (event.keyboard.keycode == button_left_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_LEFT);
   else if (event.keyboard.keycode == button_right_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_RIGHT);
   else if (event.keyboard.keycode == button_start_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_START);
   else if (event.keyboard.keycode == button_back_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_BACK);
   else if (event.keyboard.keycode == button_a_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_A);
   else if (event.keyboard.keycode == button_b_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_B);
   else if (event.keyboard.keycode == button_c_keyboard_keymap) emit_gamer_button_up(GAMER_BUTTON_C);
}




void GamerInputScreen::joy_axis_func(ALLEGRO_EVENT &event)
{
   float pos = event.joystick.pos;

   //ALLEGRO_EVENT &e = *Framework::current_event;
   //std::cout << "stick " << e.joystick.stick << " axis: " << e.joystick.axis << " pos: " << e.joystick.pos << std::endl;

   if (event.joystick.axis == 0) // left-right
   {
      if (fabs(pos) < 0.5)
      {
         // it is in the "neutral" position
         if (pressed[GAMER_BUTTON_LEFT]) emit_gamer_button_up(GAMER_BUTTON_LEFT);
         if (pressed[GAMER_BUTTON_RIGHT]) emit_gamer_button_up(GAMER_BUTTON_RIGHT);
      }
      else if (pos <= 0.5) // is pointing left
      {
         if (pressed[GAMER_BUTTON_RIGHT]) emit_gamer_button_up(GAMER_BUTTON_RIGHT);
         if (!pressed[GAMER_BUTTON_LEFT]) emit_gamer_button_down(GAMER_BUTTON_LEFT);
      }
      else if (pos >= 0.5) // is pointing right
      {
         if (pressed[GAMER_BUTTON_LEFT]) emit_gamer_button_up(GAMER_BUTTON_LEFT);
         if (!pressed[GAMER_BUTTON_RIGHT]) emit_gamer_button_down(GAMER_BUTTON_RIGHT);
      }
   }
   if (event.joystick.axis == 1) // up-down
   {
      if (fabs(pos) < 0.5)
      {
         // it is in the "neutral" position
         if (pressed[GAMER_BUTTON_UP]) emit_gamer_button_up(GAMER_BUTTON_UP);
         if (pressed[GAMER_BUTTON_DOWN]) emit_gamer_button_up(GAMER_BUTTON_DOWN);
      }
      else if (pos <= 0.5) // is pointing left
      {
         if (pressed[GAMER_BUTTON_DOWN]) emit_gamer_button_up(GAMER_BUTTON_DOWN);
         if (!pressed[GAMER_BUTTON_UP]) emit_gamer_button_down(GAMER_BUTTON_UP);
      }
      else if (pos >= 0.5) // is pointing right
      {
         if (pressed[GAMER_BUTTON_UP]) emit_gamer_button_up(GAMER_BUTTON_UP);
         if (!pressed[GAMER_BUTTON_DOWN]) emit_gamer_button_down(GAMER_BUTTON_DOWN);
      }
   }
}




void GamerInputScreen::joy_button_down_func(ALLEGRO_EVENT &event)
{
   std::cout << "GamerInputScreen::joy_button_down_func(): " << event.joystick.button << std::endl;

   if (event.joystick.button == button_up_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_UP);
   else if (event.joystick.button == button_down_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_DOWN);
   else if (event.joystick.button == button_left_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_LEFT);
   else if (event.joystick.button == button_right_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_RIGHT);
   else if (event.joystick.button == button_start_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_START);
   else if (event.joystick.button == button_back_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_BACK);
   else if (event.joystick.button == button_a_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_A);
   else if (event.joystick.button == button_b_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_B);
   else if (event.joystick.button == button_c_joystick_buttonmap) emit_gamer_button_down(GAMER_BUTTON_C);
}




void GamerInputScreen::joy_button_up_func(ALLEGRO_EVENT &event)
{
   std::cout << "GamerInputScreen::joy_button_up_func(): " << event.joystick.button << std::endl;

   if (event.joystick.button == button_up_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_UP);
   else if (event.joystick.button == button_down_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_DOWN);
   else if (event.joystick.button == button_left_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_LEFT);
   else if (event.joystick.button == button_right_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_RIGHT);
   else if (event.joystick.button == button_start_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_START);
   else if (event.joystick.button == button_back_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_BACK);
   else if (event.joystick.button == button_a_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_A);
   else if (event.joystick.button == button_b_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_B);
   else if (event.joystick.button == button_c_joystick_buttonmap) emit_gamer_button_up(GAMER_BUTTON_C);
}




void GamerInputScreen::draw_gamer_input_state(bool button[GAMER_BUTTON_SIZE_MAX], float opacity, float x, float y, float align_x, float align_y, float scale_x, float scale_y)
{
   throw std::runtime_error("This feature has been disabled because of a dependency on a bitmap, and should be refactored");

   //// get the controller bmp
   //ALLEGRO_BITMAP *controller = nullptr;//Framework::bitmap("game_controller.png");

   //// store the state and use a new transform
   //ALLEGRO_STATE prev_state;
   //al_store_state(&prev_state, ALLEGRO_STATE_TRANSFORM);

   //ALLEGRO_TRANSFORM t;
   //al_identity_transform(&t);
   //al_translate_transform(&t, -align_x*al_get_bitmap_width(controller), -align_y*al_get_bitmap_height(controller));
   //al_scale_transform(&t, scale_x, scale_y);
   //al_translate_transform(&t, x, y);
   //al_use_transform(&t);

   //// draw the controller backdrop
   //al_draw_tinted_bitmap(controller, al_map_rgba_f(opacity, opacity, opacity, opacity), 0, 0, 0);

   //// draw the buttons
   //al_draw_filled_circle(163, 42, 9, button[GAMER_BUTTON_A] ? color::lime : color::transparent); // button 1
   //al_draw_filled_circle(182, 57, 9, button[GAMER_BUTTON_B] ? color::lime : color::transparent); // button 2
   //al_draw_filled_circle(201, 42, 9, button[GAMER_BUTTON_C] ? color::lime : color::transparent); // button 3 

   //al_draw_filled_circle(122, 83, 7, button[GAMER_BUTTON_BACK] ? color::lime : color::transparent); // button back 
   //al_draw_filled_circle(148, 83, 7, button[GAMER_BUTTON_START] ? color::lime : color::transparent); // button start 

   //// draw the hat
   //float s = 6;
   //al_draw_filled_rounded_rectangle(79-s, 38-s, 79+s, 38+s, 3, 3, button[GAMER_BUTTON_UP] ? color::lime : color::transparent); // button up
   //al_draw_filled_rounded_rectangle(79-s, 65-s, 79+s, 65+s, 3, 3, button[GAMER_BUTTON_DOWN] ? color::lime : color::transparent); // button down
   //al_draw_filled_rounded_rectangle(65-s, 51-s, 65+s, 51+s, 3, 3, button[GAMER_BUTTON_LEFT] ? color::lime : color::transparent); // button left
   //al_draw_filled_rounded_rectangle(93-s, 51-s, 93+s, 51+s, 3, 3, button[GAMER_BUTTON_RIGHT] ? color::lime : color::transparent); // button right

   //// clean up
   //al_restore_state(&prev_state);
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



