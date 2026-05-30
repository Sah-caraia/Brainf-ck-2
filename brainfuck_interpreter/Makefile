CMD = g++
FILES = ./main.cpp \
				./src/utils/read_bytecode/read_bytecode.cpp \
				./src/interpreter/interpreter.cpp
OUT = bfi

ZIP = /sdcard/BFCOMPILER.zip

all:
	clear;$(CMD) $(FILES) -o $(OUT);

zip:
	clear;rm $(ZIP);zip $(ZIP) -r *
