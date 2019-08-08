CXX= clang++
CXXFLAGS = -Wall -g

OFILES =  TreeNode.o huffmandec.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	$(CXX) $(OFILES)


TreeNode.o: TreeNode.h TreeNode.cpp
	$(CXX) -c TreeNode.cpp


huffmandec.o: TreeNode.h TreeNode.cpp huffmandec.cpp

clean:
	/bin/rm -f *o. *~
