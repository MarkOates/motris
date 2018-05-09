

#include <framework/framework.hpp>
#include <motris/screens/motris.hpp>


int main(int, char**)
{
   al_init();

   Framework framework;
   Motris motris(framework);

   framework.add_screen(&motris);
   framework.loop();

   return 0;
}


