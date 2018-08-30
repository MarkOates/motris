

#include <motris/main_menu_screen/renderers/menu_renderer.hpp>


namespace MainMenu
{


MenuRenderer::MenuRenderer(Menu *menu, float x, float y)
   : menu(menu)
   , place(x, y, 0, 0)
{
}


MenuRenderer::~MenuRenderer()
{
}


void MenuRenderer::render()
{
}


};


