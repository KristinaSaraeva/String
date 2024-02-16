TARGET = my_string.a test 
SLIB = my_string.a
CC = gcc
TEST_LIBS = -lcheck -lm  

SRC = my_string.c
AR = ar rc
RAN = ranlib
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname)
ifeq ($(OS), Linux)
	TEST_LIBS += -lpthread -lrt -lsubunit
endif

all : $(TARGET)

all_obj : $(SRC)
	$(CC) -c $(SRC)

test : my_string.a
	$(CC) my_test.c -L. $(SLIB) -o test $(TEST_LIBS)
	./test

my_string.a : all_obj
	$(AR) $(SLIB) my_string.o
	$(RAN) $(SLIB)

gcov_report : $(SRC)
	$(CC) $(GCOV_FLAGS) $(SRC) my_test.c $(TEST_LIBS) -o test_gcov
	./test_gcov
	lcov -c -d . -o report.info
	genhtml -o cov_res/ report.info

open :
	xdg-open cov_res/index.html
	
clean :
	rm -rf -R *.o *.a a.out *.gcda *.gcno *.info test test_gcov cov_res
	