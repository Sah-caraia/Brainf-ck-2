CMD = g++
FILES = ./main.cpp \
				./src/get_lines/get_lines.cpp \
				./src/core/lexer/lexer.cpp \
				./src/core/parser/parser.cpp \
				./src/core/bytecode_generator/bytecode_generator.cpp \
				./src/utils/write_bytecode/write_bytecode.cpp \
				./src/utils/char_utils/char_utils.cpp
OUT = bfc
ZIPFILE = brainfuck2.zip


all:
	clear;$(CMD) $(FILES) -o $(OUT);

zip:
	clear;rm /sdcard/$(ZIPFILE); zip /sdcard/$(ZIPFILE) -r *;
