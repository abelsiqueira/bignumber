include ../make.inc

TESTS = test1.tst test2.tst test3.tst test4.tst
VALGRIND = valgrind --leak-check=yes

all: $(TESTS)
	@for i in $(TESTS); do \
		/bin/echo -e "\e[0;31mRunning test $$i\e[0m"; \
		./$$i; \
	done

%.tst: %.c
	$(C) -o $@ $< ../$(LIBNAME) $(I) $(CFLAGS)

memory: $(TESTS)
	@for i in $(TESTS); do \
		/bin/echo -e "\e[0;31mRunning test $$i\e[0m"; \
		$(VALGRIND) ./$$i; \
	done

clean:
	rm -f *.tst

purge: clean
