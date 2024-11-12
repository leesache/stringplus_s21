CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 
LDFLAGS=-L/usr/local/lib
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CHECK_FLAGS = -lcheck -lm -lpthread -lsubunit -lrt
    OPEN_CMD = xdg-open
else ifeq ($(UNAME_S),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
    OPEN_CMD = open
endif



LIBRARY_SOURCES = insert.c \
				  memchr.c \
				  memcmp.c \
				  memcpy.c \
				  memset.c \
				  strchr.c \
				  strcspn.c \
				  strerror.c \
				  strlen.c \
				  strncat.c \
				  strncmp.c \
				  strncpy.c \
				  strpbrk.c \
				  strrchr.c \
				  strstr.c \
				  strtok.c \
				  to_lower.c \
				  to_upper.c \
				  trim.c \
				  sprintf.c 


LIBRARY_OBJECTS = insert.o \
				  memchr.o \
				  memcmp.o \
				  memcpy.o \
				  memset.o \
				  strchr.o \
				  strcspn.o \
				  strerror.o \
				  strlen.o \
				  strncat.o \
				  strncmp.o \
				  strncpy.o \
				  strpbrk.o \
				  strrchr.o \
				  strstr.o \
				  strtok.o \
				  to_lower.o \
				  to_upper.o \
				  trim.o \
				  sprintf.o 

TEST_SOURCES = ../tests/s21_insert_test.c \
../tests/s21_memchr_test.c \
 ../tests/s21_memcmp_test.c \
 ../tests/s21_memcpy_test.c \
../tests/s21_memset_test.c \
 ../tests/s21_strchr_test.c \
 ../tests/s21_strcspn_test.c \
 ../tests/s21_strerror_test.c \
 ../tests/s21_strlen_test.c \
 ../tests/s21_strncat_test.c \
 ../tests/s21_strncmp_test.c \
 ../tests/s21_strncpy_test.c \
 ../tests/s21_strpbrk_test.c \
 ../tests/s21_strrchr_test.c \
 ../tests/s21_strstr_test.c \
 ../tests/s21_strtok_test.c \
 ../tests/s21_to_lower_test.c \
 ../tests/s21_to_upper_test.c \
 ../tests/s21_trim_test.c \
../tests/test.c \
../tests/s21_sprintf_test.c 

all: test gcov_report

compile_objects:
	$(CC) $(CFLAGS) -c ${LIBRARY_SOURCES}

s21_string.a: compile_objects
	ar -rc s21_string.a ${LIBRARY_OBJECTS}
	#ranlib s21_string.a
	rm -f *.o


build: s21_string.a

rebuild: clean build

test: clean
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o tests.out ${LIBRARY_SOURCES} $(CHECK_FLAGS) $(GCOV_FLAGS)
	./tests.out
test_valgrind: rebuild
	$(CC) $(CFLAGS) $(LDFLAGS) -o tests.out $(TEST_SOURCES) s21_string.a $(CHECK_FLAGS) $(GCOV_FLAGS)
	valgrind --log-file=valgrind.log --leak-check=full --track-origins=yes ./tests.out

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	@if command -v $(OPEN_CMD) > /dev/null; then \
        $(OPEN_CMD) ./gcov_report/index.html; \
    else \
        echo "Please open ./gcov_report/index.html manually"; \
    fi

clean:
	@rm -rf ../src/*.o ../*/*.out ./*/*.a ../src/*.a
	@rm -rf *.gcda *.gcno *.info gcov_report
style:
	cp ../materials/linters/.clang-format .
	find .. -name "*.c" -exec clang-format -i {} \;
	find .. -name "*.h" -exec clang-format -i {} \;
	rm -rf .clang-format

style_test:
	cp ../materials/linters/.clang-format .
	find .. -name "*.c" -exec clang-format -n {} \;
	find .. -name "*.h" -exec clang-format -n {} \;
	rm -rf .clang-format

test_manual: rebuild
	$(CC) $(CFLAGS) ../tests/main.c s21_string.a -o main_test.out
	./main_test.out
