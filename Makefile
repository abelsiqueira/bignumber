include make.inc

all: $(LIBNAME)

test: $(LIBNAME)
	(cd tests; make);

memory: $(LIBNAME)
	(cd tests; make memory);

$(LIBNAME): 
	(cd obj; make)

clean:
	(cd obj; make clean)
	(cd tests; make clean)

purge: clean
	rm -f $(LIBNAME)
