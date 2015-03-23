
#include <stdio.h>

// include sub_table.h

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

// End include sum_table.h

// Include sum_table.c


#include <stdio.h>
#include <stdlib.h>

//#include "sum_table.h"

int get_max_abs_sum(int A[], int N, int * max_abs_element) {
    int max_abs_sum = 0;
    int i;

    *max_abs_element = 0;
    for (i = 0; i < N; i++) {
        if (A[i] >= 0) {
            max_abs_sum += A[i];
            if (A[i] > *max_abs_element) {
                *max_abs_element = A[i];
            }
        } else {
            max_abs_sum += -A[i];
            if (-A[i] > *max_abs_element) {
                *max_abs_element = -A[i];
            }
        }
    }
    return max_abs_sum;
}

SumTable new_sum_table(int A[], int N) {
    int * elements = NULL;
    SumTable self = NULL;
    int max_abs_element;
    int num_columns = get_max_abs_sum(A, N, &max_abs_element) + 1;

    self = malloc(sizeof(struct sum_table));
    if (!self) {
        return NULL;
    }
    self->elements = NULL;
    self->counts = NULL;
    self->previous_row = NULL;
    self->current_row = NULL;
    elements = malloc(N * sizeof(int));
    if (!elements) {
        destroy_sum_table(self);
        return NULL;
    }
    self->elements = elements;
    self->how_many_elements = N;
    self->counts = malloc((max_abs_element + 1) * sizeof(int));
    if (!self->counts) {
        destroy_sum_table(self);
        return NULL;
    }
    self->how_many_counts = max_abs_element + 1;
    self->previous_row = malloc(num_columns * sizeof(int));
    if (!self->previous_row) {
        destroy_sum_table(self);
        return NULL;
    }
    self->current_row = malloc(num_columns * sizeof(int));
    if (!self->current_row) {
        destroy_sum_table(self);
        return NULL;
    }
    self->how_many_columns = num_columns;
    return self;
}

void destroy_sum_table(SumTable self) {
    if (!self) {
        return;
    }
    if (self->elements) {
        free(self->elements);
    }
    if (self->counts) {
        free(self->counts);
    }
    if (self->previous_row) {
        free(self->previous_row);
    }
    if (self->current_row) {
        free(self->current_row);
    }
    free(self);
}

void initialize_sum_table(SumTable self, int A[]) {
    initialize_elements(self, A);
    initialize_counts(self);
    initialize_sums(self);
}

void initialize_elements(SumTable self, int A[]) {
    int i;

    for (i = 0; i < self->how_many_elements; i++) {
        self->elements[i] = ( A[i] >= 0 ) ? A[i] : -A[i];
    }
}

void initialize_sums(SumTable self) {
    int j;

    for (j = 0; j < self->how_many_columns; j++) {
        self->previous_row[j] = -1;
        self->current_row[j] = -1;
    }
    self->current_row[0] = 0;
}

void initialize_counts(SumTable self) {
    int i;

    for (i = 0; i < self->how_many_counts; i++) {
        self->counts[i] = 0;
    }
    for (i = 0; i < self->how_many_elements; i++) {
        self->counts[self->elements[i]] += 1;
    }
}

void swap_current_row(SumTable self) {
    int * temp = self->current_row;

    self->current_row = self->previous_row;
    self->previous_row = temp;
}

void fill_sums(SumTable self) {
    int i;
    int j;
    int reachable_sum;

    for (i = 1; i < self->how_many_counts; i++) {
        if (self->counts[i] <= 0) {
            continue;
        }
        swap_current_row(self);
        for (j = 0; j < self->how_many_columns; j++) {
            reachable_sum = self->previous_row[j];
            if (reachable_sum > -1) {
                self->current_row[j] = self->counts[i];
            } else {
                if (j >= i && self->current_row[j - i] > 0) {
                    self->current_row[j] = self->current_row[j - i] - 1;
                }
            }
        }
    }
}

int get_min_abs_sum(SumTable self) {
    int S = self->how_many_columns - 1;
    int min_abs_sum = S;
    int i;
    int abs_sum;

    for (i = 0; i <= S / 2; i++) {
        if (self->current_row[i] > -1) {
            abs_sum = (S - i) - i;
            if (abs_sum < min_abs_sum) {
                min_abs_sum = abs_sum;
            }
        }
    }
    return min_abs_sum;
}

void print_sums(SumTable self) {
    int j;

    for (j = 0; j < self->how_many_columns; j++) {
        printf("%3d", self->current_row[j]);
        if (j < self->how_many_columns - 1) {
            printf(", ");
        }
    }
}

void print_counts(SumTable self) {
    int j;

    for (j = 0; j < self->how_many_counts; j++) {
        printf("%1d", self->counts[j]);
        if (j < self->how_many_counts - 1) {
            printf(", ");
        }
    }
}

// End include sum_table.c

int solution(int A[], int N) {
    SumTable table;
    int result;

    table = new_sum_table(A, N);
    initialize_sum_table(table, A);
    fill_sums(table);
    result = get_min_abs_sum(table);
    destroy_sum_table(table);
    return result;
}

int main() {
    int N;
    int result;

    N = 4;
    int A[] = { 1, 5, 2, -2 };
    printf("About to compute the minAbsSum, for the test example\n");
    result = solution(A, N);
    printf("The result is: %d\n", result);
}
