INCLUDE = -I../include
INCLUDE += -I../test

SRC = $(wildcard ../src/*.cpp)
SRC += $(wildcard ../test/*.cpp)

OBJ_DIR = ./obj
OBJ = $(filter-out $(TARGET_TEST_OBJ) $(TARGET_OBJ),$(addprefix $(OBJ_DIR)/,$(notdir $(SRC:%.cpp=%.o))))

TARGET_TEST_SRC = ../test/test.cpp
TARGET_TEST_OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(TARGET_TEST_SRC:%.cpp=%.o)))
TARGET_TEST = $(notdir $(TARGET_TEST_SRC:%.cpp=%))

TARGET_SRC = ../src/design_patterns.cpp
TARGET_OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(TARGET_SRC:%.cpp=%.o)))
TARGET = $(notdir $(TARGET_SRC:%.cpp=%))

DIR = $(dir $(SRC))
DIR += $(dir $(TARGET_SRC))

CC = g++
CFLAGS = $(INCLUDE) -Wall -g -std=c++11
RM = rm -rf

vpath %.cpp $(DIR)

.PHONY: all
all: $(TARGET) $(TARGET_TEST)
$(TARGET): $(OBJ) $(TARGET_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

$(TARGET_TEST): $(OBJ) $(TARGET_TEST_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	@$(RM) $(TARGET) $(OBJ_DIR) $(TARGET_TEST)

.PHONY: distclean
distclean: clean
