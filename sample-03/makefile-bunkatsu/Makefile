TARGET=prog
SRCS=main.c func.c
OBJS=main.o func.o
CC=gcc


$(TARGET): $(SRCS) $(OBJS)
	$(CC) -o $@ $(OBJS)

.C.O:
	$(CC) -c $<


clean:
	rm -rf *~ *.o $(TARGET)

