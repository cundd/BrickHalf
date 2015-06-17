CC=g++
CFLAGS=-c -Wall -std=c++11 -stdlib=libc++
LDFLAGS=
SOURCES=main.cpp MapParser.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=brickhalf

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS)

test: $(EXECUTABLE)
	@echo "Run tests:";
#	@./$(EXECUTABLE) "a=1;b=2"
	@echo "a=1;b=2" | ./$(EXECUTABLE)
	@./$(EXECUTABLE)
