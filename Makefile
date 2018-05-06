


LIBS_ROOT=~/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_LIB_DIR=$(ALLEGRO_DIR)/lib
ALLEGRO_INCLUDE_DIR=$(ALLEGRO_DIR)/include


ALLEGRO_LIBS_WITHOUT_MAIN=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro
ALLEGRO_LIBS=$(ALLEGRO_LIBS_WITHOUT_MAIN) -lallegro_main
OPENGL_LIB=-framework OpenGL


main:
	g++ -std=gnu++11 -Wall programs/motris.cpp -o bin/motris -L$(ALLEGRO_LIB_DIRS) $(ALLEGRO_LIBS) -I$(ALLEGRO_INCLUDE_DIR)



