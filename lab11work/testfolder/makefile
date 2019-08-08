CXX = clang++
DOX = doxygen

OFILES = traveling.o middleearth.o

main:	$(OFILES)
	$(CXX) $(OFILES)
	$(DOX)

middleearth.o: middleearth.h middleearth.cpp
	$(CXX) -c middleearth.cpp


traveling.o: traveling.cpp middleearth.cpp middleearth.h
