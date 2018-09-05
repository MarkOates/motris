#pragma once


#include <allegro5/allegro.h>


class Event
{
private:
   ALLEGRO_EVENT event;

public:
   Event(ALLEGRO_EVENT_TYPE event_type, intptr_t data1, intptr_t data2, intptr_t data3, intptr_t data4);

   ALLEGRO_EVENT_TYPE get_type();
   intptr_t get_data1();
   intptr_t get_data2();
   intptr_t get_data3();
   intptr_t get_data4();
};


