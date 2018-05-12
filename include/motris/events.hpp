#pragma once


enum game_events
{
   GAME_EVENT_GOTO_GAMEPLAY_SCREEN = ALLEGRO_GET_EVENT_TYPE('M','t','r','s'),
   GAME_EVENT_FIGURE_DROP,
   GAME_EVENT_ROTATE_FIGURE,
   GAME_EVENT_MOVE_FIGURE_LEFT,
   GAME_EVENT_MOVE_FIGURE_RIGHT,
   GAME_EVENT_PLACE_FIGURE,
   GAME_EVENT_ACCELERATE_DROP,
   GAME_EVENT_NORMALIZE_DROP_SPEED,
   GAME_EVENT_SPAWN_NEW_FIGURE,

   GAME_EVENT_HUD_UPDATE_LEVEL,
   GAME_EVENT_HUD_UPDATE_SCORE,
   GAME_EVENT_HUD_UPDATE_LINES_CLEARED,
   GAME_EVENT_HUD_UPDATE_TIME,
   GAME_EVENT_HUD_UPDATE_PIECES_SINCE_LAST_LONGBAR,
   GAME_EVENT_HUD_UPDATE_NEXT_FIGURE,
   GAME_EVENT_HUD_CLEAR_NOTIFICATION,
   GAME_EVENT_HUD_UPDATE_NOTIFICATION_GAME_OVER,

   GAME_EVENT_START_GAMEPLAY,
   GAME_EVENT_PLAYER_LOST,
};


