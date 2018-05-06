

#include <framework/bitmap.hpp>

#include <framework/color.hpp>


Bitmap::Bitmap(ALLEGRO_BITMAP *al_bitmap, float x, float y)
   : placement(x, y, 0, 0, 0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0)
   , al_bitmap(al_bitmap)
   , color(color::white)
   , opacity(1.0)
   , flags(0)
{
   this->bitmap(al_bitmap);
}


Bitmap::~Bitmap()
{
}


//Bitmap &opacity(float opacity)
//{
   //opacity(opacity); return *this;
//}


//Bitmap &save(std::string filename)
//{
   //al_save_bitmap(filename.c_str(), al_bitmap); return *this;
//}


Bitmap &Bitmap::reset()
{
   placement.clear();
   placement.align.x = 0.0;
   placement.align.y = 0.0;
   return *this;
}


Bitmap &Bitmap::set_flags(int flags)
{
   this->flags = flags; return *this;
}


ALLEGRO_BITMAP *Bitmap::get_bitmap()
{
   return al_bitmap;
}


Bitmap &Bitmap::bitmap(ALLEGRO_BITMAP *bitmap)
{
   al_bitmap = bitmap;
   if (al_bitmap)
   {
      placement.w = al_get_bitmap_width(al_bitmap);
      placement.h = al_get_bitmap_height(al_bitmap);
   }
   else
   {
      placement.w = 1;
      placement.h = 1;
   }
   return *this;
}


Bitmap &Bitmap::draw_raw()
{
   if (al_bitmap)
   {
      al_draw_tinted_bitmap(al_bitmap, ::color::color(color, opacity), 0, 0, flags);
   }
   return *this;
}


Bitmap &Bitmap::draw()
{
   placement.start_transform();
   draw_raw();
   placement.restore_transform();
   //draw_crosshair(x, y);
   return *this;
}


