
CXX = clang++

CXXFLAGS = -Wall -g

OFILES = AVLTree.o AVLNode.o AVLPathTest.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(OFILES)

clean:
	/bin/rm -f *.o *~

AVLNode.o: AVLNode.cpp AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
