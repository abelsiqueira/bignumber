include ../make.inc

all: $(OBJ)
	ar rv $(LIBNAME) $(OBJ)
	mv $(LIBNAME) ..

%.o: ../src/%.c
	$(C) -c -o $@ $< $(CFLAGS) $(I)

clean:
	rm -f $(OBJ)
