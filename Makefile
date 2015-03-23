all: sum_table.o sum_table_test.bin codility_version.bin

sum_table.o: sum_table.c sum_table.h
	gcc -c sum_table.c -o sum_table.o

sum_table_test.bin: sum_table_test.c sum_table.c sum_table.h
	gcc -I ./ sum_table_test.c sum_table.o -o sum_table_test.bin

codility_version.bin: codility_version.c sum_table.c sum_table.h
	gcc codility_version.c -o codility_version.bin
