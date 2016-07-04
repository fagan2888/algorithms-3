all: test

test: 
	cd test-suite && $(MAKE)

clean: 
	rm obj/*.o && rm bin/*
