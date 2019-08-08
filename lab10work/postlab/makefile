CXX= clang++
CXXFLAGS = -Wall -g

OFILES =  huffnode.o heap.o huffmanenc.o
OOFILES = TreeNode.o huffmandec.o

.SUFFIXES: .o .cpp

all: encoder decoder

encoder: $(OFILES)
	$(CXX) $(OFILES) -o encoder

decoder: $(OOFILES)
	$(CXX) $(OOFILES) -o decoder


huffnode.o: huffnode.h huffnode.cpp
	$(CXX) -lrt -c huffnode.cpp

heap.o: heap.h huffnode.h huffnode.cpp heap.h heap.cpp
	$(CXX) -c heap.cpp huffnode.cpp

huffmanenc.o:  huffnode.h huffnode.cpp heap.cpp heap.h huffmanenc.cpp
	$(CXX) -c huffnode.cpp heap.cpp huffmanenc.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	$(CXX) -c TreeNode.cpp

huffmandec.o: TreeNode.h TreeNode.cpp huffmandec.cpp
	$(CXX) -c huffmandec.cpp

clean:
	/bin/rm -f *o. *~
