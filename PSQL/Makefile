INC=/usr/include/postgresql 
LIB=/usr/lib
CFLAGS=-I$(INC)
LDLIBS=-L$(LIB) -lpq
CC=gcc
#Wymagana biblioteka postgresql
ALL=connect create create2 select print cursor async1 async2
# ponizej przyklady regul i zaleznosci kompilacji wybranych plikow
1: 1.c
	$(CC) $(CFLAGS) -o 1 1.c $(LDLIBS)
clean:
	@rm -f *.o *~ $(ALL)
all: clean connect create create2 select print cursor async1 async2
