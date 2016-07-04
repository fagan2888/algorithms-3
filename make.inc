#CPP Makefile

CXX:=g++
DBG:=-g
CXXFLAGS:=-std=c++14 $(DBG)
LDFLAGS:=
OPTS:=-O0

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

BOOSTLIB:=
LIBDIR:=
INCLUDE:=
