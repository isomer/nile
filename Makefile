

all: nile lib_dir tests_dir

nile:
	$(MAKE) -C compiler 

lib_dir:
	$(MAKE) -C lib

tests_dir:
	$(MAKE) -C tests

clean: nile_clean lib_clean tests_clean

nile_clean:
	$(MAKE) -C compiler clean
lib_clean:
	$(MAKE) -C lib clean
tests_clean:
	$(MAKE) -C tests clean
