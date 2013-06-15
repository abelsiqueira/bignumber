include ../make.inc

TESTS = tmp_test.tst

all: $(TESTS)
	@for i in $(TESTS); do \
		/bin/echo -e "\e[0;31mRunning test $$i\e[0m"; \
		./$$i; \
	done

%.tst: %.c
	$(C) -o $@ $< ../$(LIBNAME) $(I)

clean:
	rm -f *.tst

purge: clean
