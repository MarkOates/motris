

#include <framework/screens/gamer_input_screen.hpp>
#include <framework/framework.hpp>
#include <motris/screens/motris.hpp>


int main(int, char**)
{
   al_init();

   Framework framework;

   GamerInputScreen gamer_input_screen;
   Motris motris;

   framework.add_screen(&gamer_input_screen);
   framework.add_screen(&motris);

   framework.loop();

   return 0;
}


