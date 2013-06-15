C = gcc
CFLAGS = -Wall -Wextra -Werror

I = -Iinclude
OBJ = bignumber.o
LIBNAME = libbignumber.a
TESTS = tmp_test.tst

all: $(LIBNAME)

test: $(LIBNAME)
	(cd tests; make);

$(LIBNAME): 
	(cd obj; make)


clean:
	(cd obj; make clean)
	(cd tests; make clean)

purge: clean
	rm -f $(LIBNAME)
