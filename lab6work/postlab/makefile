CXX= clang++ -O2
CXXFLAGS = -Wall -g

OFILES =  timer.o hashTable.o wordPuzzle.o ListNode.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *o. *~

timer.o: timer.h timer.cpp
	$(CXX) -lrt -c timer.cpp

ListNode.o: ListNode.h ListNode.cpp
	$(CXX) -c ListNode.cpp

hashTable.o: hashTable.cpp ListNode.cpp hashTable.h ListNode.h
	$(CXX) -c hashTable.cpp ListNode.cpp

wordPuzzle.o:  wordPuzzle.cpp hashTable.cpp timer.cpp ListNode.cpp hashTable.h timer.h ListNode.h

clean:
	/bin/rm -f *o. *~
