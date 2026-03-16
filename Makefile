# Параметри компіляції
CC = gcc
CFLAGS = -g -Wall
ASAN_FLAGS = -fsanitize=address

# Назви вихідних файлів
TARGETS = stack_test heap_test stack_asan heap_asan

all: $(TARGETS)

# Звичайна збірка (для Valgrind та ulimit)
stack_test: stack_overflow.c
	$(CC) $(CFLAGS) stack_overflow.c -o stack_test

heap_test: heap_overflow.c
	$(CC) $(CFLAGS) heap_overflow.c -o heap_test

# Збірка з AddressSanitizer
stack_asan: stack_overflow.c
	$(CC) $(CFLAGS) $(ASAN_FLAGS) stack_overflow.c -o stack_asan

heap_asan: heap_overflow.c
	$(CC) $(CFLAGS) $(ASAN_FLAGS) heap_overflow.c -o heap_asan

clean:
	rm -f $(TARGETS)
