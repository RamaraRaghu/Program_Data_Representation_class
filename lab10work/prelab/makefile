CXX= clang++ -O2
CXXFLAGS = -Wall -g

OFILES =  treenode.o heap.o huffmanenc.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *o. *~

treenode.o: treenode.h treenode.cpp
	$(CXX) -lrt -c treenode.cpp

heap.o: heap.h treenode.h treenode.cpp heap.h heap.cpp
	$(CXX) -c heap.cpp treenode.cpp

huffmanenc.o:  treenode.h treenode.cpp heap.cpp heap.h huffmanenc.cpp

clean:
	/bin/rm -f *o. *~
