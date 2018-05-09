

#include <framework/screens/gamer_input_screen.hpp>
#include <framework/framework.hpp>
#include <motris/screens/gameplay.hpp>


int main(int, char**)
{
   al_init();

   Framework framework;

   GamerInputScreen gamer_input_screen;
   Gameplay gameplay;

   framework.add_screen(&gamer_input_screen);
   framework.add_screen(&gameplay);

   framework.loop();

   return 0;
}


