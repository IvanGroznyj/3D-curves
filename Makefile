CC=g++
CFLAGS=-c -O2 -g -fPIC
lib_name=libcore.so

EXECUTABLE=runner

debug_dir=build
sfext=cpp

includes_dir=-I./core/includes -I./example/includes

source_dir=core
lib_files=$(wildcard ./$(source_dir)/src/*.$(sfext))
lib_objects=$(patsubst ./$(source_dir)/src/%.$(sfext), ./$(debug_dir)/$(source_dir)/%.o, $(lib_files))

example_src_dir=example
example_files=$(wildcard ./$(example_src_dir)/src/*.$(sfext))
example_objects=$(patsubst ./$(example_src_dir)/src/%.$(sfext), ./$(debug_dir)/$(example_src_dir)/%.o, $(example_files))

.PHONY: info folders lib example unittests clean

info:
	@echo "$(lib_files)"
	@echo "$(lib_objects)"

./$(debug_dir)/$(example_src_dir)/%.o: ./$(example_src_dir)/src/%.$(sfext)
	@mkdir -p $(@D)
	@echo Compile file: $<
	@$(CC) $(CFLAGS) $< -o $@ $(includes_dir)

./$(debug_dir)/$(source_dir)/%.o: ./$(source_dir)/src/%.$(sfext)
	@mkdir -p $(@D)
	@echo Compile file: $<
	@$(CC) $(CFLAGS) $< -o $@ $(includes_dir)

lib: $(lib_objects)
	@echo Build lib: $(debug_dir)/$(lib_name)
	@$(CC) $(debug_dir)/$(source_dir)/*.o -o $(debug_dir)/$(lib_name) $(LFLAGS) -g -shared
	
all: lib $(example_objects)
	@echo Build executable file: $(debug_dir)/$(EXECUTABLE)
	@$(CC) $(debug_dir)/$(example_src_dir)/*.o -o $(debug_dir)/$(EXECUTABLE) $(LFLAGS) -g -L./$(debug_dir) -lcore

clean:
	@echo Clean build directory...
	@rm $(debug_dir)/$(source_dir)/*.o $(debug_dir)/$(example_src_dir)/*.o $(debug_dir)/$(EXECUTABLE)
