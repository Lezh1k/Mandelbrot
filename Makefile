CC = gcc
CXX = g++
LINK = g++

LIBS = \
       -lpthread \
       -lgtest \
       -lm \

INCLUDES := -Iinc 
SRC_DIR = src
TST_DIR = tests
SRC = $(wildcard $(SRC_DIR)/*.cpp) \
      $(wildcard $(TST_DIR)/*.cpp) 

BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
BIN_DIR  := $(BUILD)/bin
TARGET   := mandelbrot
DEFS := 
CXXFLAGS = -std=gnu++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -W -fPIC $(INCLUDES) $(DEFS)
LDFLAGS = $(LIBS)

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
all: createdirs $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(LINK) -o $(BIN_DIR)/$(TARGET) $^ $(LDFLAGS) 

.PHONY: all createdirs clean debug release test 

createdirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -O0 -g
debug: all

release: CXXFLAGS += -O2
release: all

test:	CXXFLAGS += -g -O0
test: DEFS += -DTESTMODE
test: all

clean:
	@rm -rvf $(OBJ_DIR)/*
	@rm -rvf $(BIN_DIR)/*
