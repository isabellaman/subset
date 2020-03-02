#Isabella Man
#1602153
#CSE 15
#10/11/19
#Makefile for pa1 with macros

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
