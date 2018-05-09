#pragma once


#include <framework/framework.hpp>
#include <framework/screen.hpp>


class Motris : public Screen
{
private:
   Framework &framework;

public:
   Motris(Framework &framework);

   void process_event(ALLEGRO_EVENT &event) override;
};


