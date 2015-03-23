#ifndef _SUM_TABLE_H_
#define _SUM_TABLE_H_

struct sum_table {
    int * elements;
    int how_many_elements;
    int * counts; // 0..max abs(element) recording duplicates.
    int how_many_counts;
    int how_many_unique;
    int * previous_row;
    int * current_row;
    int how_many_columns; // sum(elements);
};

typedef struct sum_table * SumTable;

SumTable new_sum_table(int *, int);
void destroy_sum_table(SumTable);
void initialize_sum_table(SumTable, int *);
void initialize_elements(SumTable, int *);
void initialize_sums(SumTable);
void initialize_counts(SumTable);
void fill_sums(SumTable);
int get_min_abs_sum(SumTable);
void print_sums(SumTable);
void print_counts(SumTable);

#endif // _SUM_TABLE_H_
