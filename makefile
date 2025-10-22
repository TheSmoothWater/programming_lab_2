CC = gcc
CFLAGS = -Wall -g

TARGET = time

OBJS = main.o ipc.o time.o 

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lrt

main.o: main.c lab2.h
	$(CC) $(CFLAGS) -c main.c

ipc.o: ipc.c lab2.h
	$(CC) $(CFLAGS) -c ipc.c

time.o: time.c lab2.h
	$(CC) $(CFLAGS) -c time.c

#there is no lab1.0???
lab1.o: lab1.c lab2.h
	$(CC) $(CFLAGS) -c lab1.c

.PHONY: clean
clean : 
	-rm -f *.o
	@echo "All clean!"