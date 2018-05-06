

LIBS_ROOT=~/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_LIB_DIR=$(ALLEGRO_DIR)/lib
ALLEGRO_INCLUDE_DIR=$(ALLEGRO_DIR)/include


ALLEGRO_LIBS_WITHOUT_MAIN=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro
ALLEGRO_LIBS=$(ALLEGRO_LIBS_WITHOUT_MAIN) -lallegro_main
OPENGL_LIB=-framework OpenGL


SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)


bin/motris: programs/motris.cpp $(OBJECTS)
	g++ -std=gnu++11 $(OBJECTS) $< -o $@ $(ALLEGRO_LIBS) -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_DIR)/include -I./include


obj/%.o: src/%.cpp $(OBJECTS)
	@mkdir -p $(@D)
	g++ -c -std=gnu++11 $< -o $@ -I$(ALLEGRO_DIR)/include -I./include


