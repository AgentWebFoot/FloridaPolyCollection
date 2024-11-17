OBJECT = scheduler.cpp
COMPILER = g++
TARGET = scheduler
CFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(OBJECT)
	$(COMPILER) $(CFLAGS) -std=c++11 -o $(TARGET) $(OBJECT)

install: $(TARGET)
	sudo cp $(TARGET) /bin/$(TARGET)
	sudo chmod +x /bin/$(TARGET)

uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

clean:
	rm -f $(TARGET) *.0

.PHONY: all install uninstall clean
