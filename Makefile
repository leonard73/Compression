cc:=gcc
PROJECT_ROOT_PATH:=$(shell pwd)
include src/source.mk
DEMO_SOURCE:=$(PROJECT_ROOT_PATH)/demo/demo.c
EXE_FILE:=demo_
build_demo:
		$(cc) $(SOURCE_FILES) $(DEMO_SOURCE) -I$(INCLUDE_FOLDER) -o $(EXE_FILE)
clean:
		rm -rf $(EXE_FILE)
run:
		sudo ./$(EXE_FILE)