TARGET=prog
SRCS=main.c func.c
OBJS=main.o func.o
CC=gcc


$(TARGET): $(SRCS) $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<


clean:
	rm -rf *~ *.o $(TARGET)

