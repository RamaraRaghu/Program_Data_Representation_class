CXX	= clang++ -m64
CXXFLAGS	= -Wall -g
AS	= nasm
ASFLAGS = -f elf64 -g
OFILES = mathlib.o mathfun.o

.SUFFIXES: .o .cpp
.SUFFIXES: .o .s

main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	/bin/rm -f *.o *~
