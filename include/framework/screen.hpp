#pragma once


#include <allegro5/allegro.h>


class Screen
{
public:
   ALLEGRO_EVENT_SOURCE event_source;

   Screen();
   virtual ~Screen();

   void emit_event(int32_t event_type, intptr_t data1=0, intptr_t data2=0, intptr_t data3=0, intptr_t data4=0);
   virtual void process_event(ALLEGRO_EVENT &event);
};


