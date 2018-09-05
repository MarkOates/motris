

#include <framework/event.hpp>


Event::Event(ALLEGRO_EVENT_TYPE event_type, intptr_t data1, intptr_t data2, intptr_t data3, intptr_t data4)
{
   event.type = event_type;
   event.user.data1 = data1;
   event.user.data2 = data2;
   event.user.data3 = data3;
   event.user.data4 = data4;
}


ALLEGRO_EVENT_TYPE Event::get_type()
{
   return event.type;
}


intptr_t Event::get_data1()
{
   return event.user.data1;
}


intptr_t Event::get_data2()
{
   return event.user.data2;
}


intptr_t Event::get_data3()
{
   return event.user.data3;
}


intptr_t Event::get_data4()
{
   return event.user.data4;
}


