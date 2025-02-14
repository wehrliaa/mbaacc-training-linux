PREFIX = i686-w64-mingw32
# flags copied from my personal fork of Rhekar's CCCaster v3.1004
FLAGS = -Wall -std=c++11 -m32 -static -lws2_32 -lpsapi -lwinpthread -lwinmm -lole32 -ldinput -lwininet -ldwmapi -lgdi32 -lshlwapi
CC = $(PREFIX)-g++

all: training.exe

training.exe: main.cpp
	$(CC) -o $@ $(FLAGS) -Iinclude/ $<

clean:
	rm -f training.exe
