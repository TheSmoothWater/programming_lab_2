CC = gcc
CFLAGS = -Wall -g

TARGET = time

OBJS = main.o ipc.o time.o 

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c lab2.h

ipc.o: ipc.c lab2.h
	$(CC) $(CFLAGS) -c ipc.c

time.o: time.c lab2.h
	$(CC) $(CFLAGS) -c time.c

clean:
	rm -f $(OBJS) $(TARGET)


.PHONY: clean
clean : 
	-rm -f *.o
	@echo "All clean!"