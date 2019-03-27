CXX      = g++

.DEFAULT_GOAL := main

SOURCES = 
SOURCES += Parking.cpp
SOURCES += Set_Parking.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS  += -g  -Wall -std=c++11 -pedantic
LDFLAGS +=-ggdb

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 

########## test_liste ##########

LISTE_SOURCES = main.cpp
LISTE_OBJECTS = $(LISTE_SOURCES:.cpp=.o)

main : $(LISTE_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(LISTE_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(LISTE_OBJECTS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : main
TARGETS += main
CLEAN_OBJECTS += $(LISTE_OBJECTS)


########## cleanup ##########
DEPS = $(CLEAN_OBJECTS:.o)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)
