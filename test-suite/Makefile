include ../make.inc

BIN=../bin
INC=../include
OBJ=../obj

INC=$(INCLUDE) -I../include
TEST_LIST=$(BIN)/test_list
SRC_LIST=linked_list_test.cpp
OBJS_LIST:=$(OBJ)/$(patsubst %.cpp,%.cpp.o,$(SRC_LIST))
ALL=$(TEST_LIST)

all: $(TEST_LIST)

$(TEST_LIST): $(OBJS_LIST)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(OBJS_LIST): $(SRC_LIST)
	    $(CXX) $(CXXFLAGS) $(OPTS) $(INC) -o $@ -c $<
