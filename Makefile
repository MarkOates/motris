

LIBS_ROOT=/Users/markoates/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_LIB_DIR=$(ALLEGRO_DIR)/lib
ALLEGRO_INCLUDE_DIR=$(ALLEGRO_DIR)/include


ALLEGRO_LIBS_WITHOUT_MAIN=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro
ALLEGRO_LIBS=$(ALLEGRO_LIBS_WITHOUT_MAIN) -lallegro_main
OPENGL_LIB=-framework OpenGL


GOOGLE_TEST_DIR=$(LIBS_ROOT)/googletest
GOOGLE_TEST_LIB_DIR=$(GOOGLE_TEST_DIR)/build/googlemock/gtest
GOOGLE_TEST_INCLUDE_DIR=$(GOOGLE_TEST_DIR)/googletest/include


GOOGLE_TEST_LIBS=gtest


SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)
TEST_SOURCES := $(shell find tests -name '*_test.cpp')
TEST_OBJECTS := $(TEST_SOURCES:tests/%.cpp=obj/tests/%.o)
INDIVIDUAL_TEST_EXECUTABLES := $(TEST_SOURCES:tests/%.cpp=bin/tests/%)


bin/main: programs/main.cpp $(OBJECTS)
	g++ -std=gnu++11 $(OBJECTS) $< -o $@ $(ALLEGRO_LIBS) -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_DIR)/include -I./include


obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	g++ -c -std=gnu++11 $< -o $@ -I$(ALLEGRO_DIR)/include -I./include


tests: $(INDIVIDUAL_TEST_EXECUTABLES)


bin/tests/%: obj/tests/%.o
	@mkdir -p $(@D)
	@printf "compiling standalone test \e[1m\e[36m$<\033[0m...\n"
	g++ -std=gnu++11 -Wall -Wuninitialized -Weffc++ $(OBJECTS) $< -o $@ -l$(GOOGLE_TEST_LIBS) -I./include -I$(GOOGLE_TEST_INCLUDE_DIR) -L$(GOOGLE_TEST_LIB_DIR) $(ALLEGRO_LIBS) -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_DIR)/include
	@echo "done. Executable at \033[1m\033[32m$@\033[0m"


obj/tests/%.o: tests/%.cpp $(OBJECTS)
	@mkdir -p $(@D)
	@printf "compiling test obj file \e[1m\e[36m$<\033[0m...\n"
	g++ -c -std=gnu++11 -Wall -Wuninitialized -Weffc++ $< -o $@ -I./include -I$(GOOGLE_TEST_INCLUDE_DIR)
	@echo "done. Object at \033[1m\033[32m$@\033[0m"


clean:
	-rm $(OBJECTS)
	-rm bin/main


