OBJECT = shell.cpp
COMPILER = g++
TARGET = shell
CFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(OBJECT)
	$(COMPILER) $(CFLAGS) -o $(TARGET) $(OBJECT)

install: $(TARGET)
	sudo cp $(TARGET) /bin/$(TARGET)
	sudo chmod +x /bin/$(TARGET)

uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

clean:
	rm -f $(TARGET) *.o

.PHONY: all install uninstall clean
