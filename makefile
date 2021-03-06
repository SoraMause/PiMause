COMPILER  = g++
CFLAGS    = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-missing-field-initializers -std=c++11 -O0
ifeq "$(shell getconf LONG_BIT)" "64"
  LDFLAGS = -pthread
else
  LDFLAGS = -pthread
endif
LIBS      =
INCLUDE   = -I./Inc/peripheral \
						-I./Inc/Maze \
						-I./Inc/Common \
						-I./Inc/Controller \
						-I./Inc

TARGET    = ./build/$(shell basename `readlink -f .`)

SOURCES   = main.cpp \
$(wildcard Src/peripheral/*.cpp) \
$(wildcard Src/Maze/*.cpp) \
$(wildcard Src/Common/*.cpp) \
$(wildcard Src/Controller/*.cpp) \
$(wildcard Src/*.cpp) 



OBJDIR    = ./build
OBJECTS = $(addprefix $(OBJDIR)/,$(notdir $(SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(SOURCES)))
DEPENDS   = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o:%.cpp
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

run:
	$(TARGET)

clean:
	-rm -rf $(OBJDIR)

-include $(DEPENDS)