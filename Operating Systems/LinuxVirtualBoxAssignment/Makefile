OBJECT = main.c LuckyNumber.o
COMPILER = gcc
TARGET = LuckyNumber

$(TARGET): $(OBJECT) LuckyNumber.h
	$(COMPILER) $(OBJECT) -o $(TARGET)

LuckyNumber.o: LuckyNumber.c LuckyNumber.h
	$(COMPILER) -c LuckyNumber.c

install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin

uninstall:
	sudo rm -f /usr/local/bin/$(TARGET)

clean:
	rm -f *.o $(TARGET)
