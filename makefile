# all:	main.o
# main.o:	main.cpp
# 	g++ -o main.o framework/*.cpp examples/*.cpp main.cpp
# clean:
# 	rm main.o

CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -O2
LDFLAGS=-g -O2

FRAMEWORK_SRS=framework/Framework.cpp framework/Problema.cpp framework/Solucion.cpp
EXAMPLE_SRS=examples/MergeSortP.cpp examples/MergeSortS.cpp examples/QuickSortP.cpp examples/QuickSortS.cpp

SRCS=main.cpp $(FRAMEWORK_SRS) $(EXAMPLE_SRS)
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend
