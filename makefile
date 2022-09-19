CC=g++
CODEDIRS=. src
INCDIRS=. ./include
OPT=-O0
DEPFLAGS=-MP -MD
CPPFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CPPFILES= $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS= $(patsubst %.cpp,%.o,$(CPPFILES))
DEPFILES= $(patsubst %.cpp,%.d,$(CPPFILES))

LIBS= -lgtest_main -lgtest -lgmock -lgmock_main -lpthread  

BINARY=main

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS) 

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $< $(LIBS) 

-include $(DEPFILES)

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES) 