all:
	gcc main.c split.c hash.c data.c disk_logic.c -lm

tests:
	gcc test/tests.c test/split_test.c test/data_test.c test/hash_test.c test/disk_logic_test.c \
	split.c hash.c data.c disk_logic.c \
	-lm -Wl,--wrap=calloc -Wl,--wrap=malloc -Wl,--wrap=open -Wl,--wrap=close -Wl,--wrap=lseek -Wl,--wrap=write -Wl,--wrap=read

debug:
	gcc -O0 -g3 main.c split.c hash.c data.c disk_logic.c -lm -DHASH_ARRAY_SIZE=2

clean:
	rm -f a.out