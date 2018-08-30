

#include <motris/main_menu_screen/models/menu_item.hpp>


namespace MainMenu
{


MenuItem::MenuItem(std::string text, int32_t event)
   : text(text)
   , event(event)
{
}


MenuItem::~MenuItem()
{
}


std::string MenuItem::get_text()
{
   return text;
}


int32_t MenuItem::get_event()
{
   return event;
}


} // namespace


