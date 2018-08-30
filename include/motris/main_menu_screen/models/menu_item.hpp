#pragma once


#include <string>


namespace MainMenu
{
   class MenuItem
   {
   private:
      std::string text;
      int32_t event;

   public:
      MenuItem(std::string text, int32_t event);
      ~MenuItem();

      std::string get_text();
      int32_t get_event();
   };
}


