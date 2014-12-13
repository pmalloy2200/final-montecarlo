# Makefile for Final project

CC = clang
CFLAGS = -Wall -O0 -g
LFLAGS = -O0 -g
LIBS = -lm -lgsl
SOURCES = main.o mc_se.o 
EXEC = main 
FUNS = 

  

$(EXEC): $(SOURCES)
	${CC} $(LFLAGS) $(LIBS) -o $@ $^

$(SOURCES): $(FUNS)

mc: $(EXEC)
	./$(EXEC) > $@

v5n.png: mc alt.gpl
	gnuplot alt.gpl

clean:
	rm -f *.o

veryclean: clean
	rm -f $(EXEC)
	rm -f *.png
