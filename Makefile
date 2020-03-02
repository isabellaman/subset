#------------------------------------------------------------------------------
#  Makefile with macros, clean.
#------------------------------------------------------------------------------

ASSIGNMENT = pa1
EXEBIN     = Subset
SOURCES    = $(EXEBIN).c
OBJECTS    = $(EXEBIN).o
FLAGS      = -std=c99 -Wall

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
