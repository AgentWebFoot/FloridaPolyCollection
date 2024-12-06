OBJECT = threads.cpp
COMPILER = g++
TARGET = threads
CFLAGS = -lpthread -lrt


all: $(TARGET)


$(TARGET): $(OBJECT)
	$(COMPILER) -std=c++11 -o $(TARGET) $(OBJECT) $(CFLAGS)


install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/$(TARGET)
	sudo chmod +x /usr/local/bin/$(TARGET)
	@echo "Installed $(TARGET) to /usr/local/bin"


uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Uninstalled $(TARGET) from /usr/local/bin"


clean:
	rm -f $(TARGET) *.o
	@echo "Cleaned up build files"


.PHONY: all install uninstall clean
