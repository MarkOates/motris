#pragma once


// For consistency, the PLAYER_INPUT_COMMAND_* values are intended
// to emulate the controller layout of a Super Nintendo controller.
// These names wont't always correlate with with the button names
// of other controllers, for example the SNES "A" button is where
// the XBox controller's "B" button is.  When joysticks are mapped
// to the values below, they should represent the equivelent of the
// SNES joystick's button names


enum player_input_command_t
{
   PLAYER_INPUT_COMMAND_UNDEF = 0,
   PLAYER_INPUT_COMMAND_UP,
   PLAYER_INPUT_COMMAND_DOWN,
   PLAYER_INPUT_COMMAND_LEFT,
   PLAYER_INPUT_COMMAND_RIGHT,
   PLAYER_INPUT_COMMAND_START,
   PLAYER_INPUT_COMMAND_BACK,
   PLAYER_INPUT_COMMAND_A,
   PLAYER_INPUT_COMMAND_B,
   PLAYER_INPUT_COMMAND_X,
   PLAYER_INPUT_COMMAND_Y,
   PLAYER_INPUT_COMMAND_R,
   PLAYER_INPUT_COMMAND_L,
   PLAYER_INPUT_COMMAND_SIZE_MAX,
};


