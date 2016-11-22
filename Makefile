.PHONY: run all clean 

CC = gcc
IDIR = include
CFLAGS = -I $(IDIR) 

DIR = obj 
OBJS = obj/watch_state.o obj/started_state.o obj/stopped_state.o obj/split_state.o obj/client_sw.o 

good : $(OBJS) 
	$(CC) -o good $(OBJS) $(CFLAGS)

