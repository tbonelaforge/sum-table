
#include <stdio.h>

#include "sum_table.h"

int main() {
    int N;
    int elem_bound;
    int result;
    /*
    printf("About to construct a new sum_table, for N = 5, ELEM_BOUND = 3\n");
    N = 5;
    int A[] = { 1, -2, 2, 4, -3 };
    SumTable test = new_sum_table(A, N);
    printf("After constructing the new sum_table, the sums look like:\n");
    print_sums(test);
    printf("About to initialize the sum_table, with elements 1, -2, 2, 4, -3\n");

    initialize_sum_table(test, A);
    printf("After initialize_sum_table, the sums now look like:\n");
    print_sums(test);
    printf("About to fill_sums:\n");
    fill_sums(test);
    printf("After filling the sums, the sums now look like:\n");
    print_sums(test);
    printf("After filling the sums, going to destroy the test\n");
    destroy_sum_table(test);
    */


    printf("About to construct a new sum_table, for N = 4\n");
    N = 4;
    int A[] = { 1, 5, 2, -2 };
    SumTable test = new_sum_table(A, N);
    printf("After constructing the new sum_table, the sums look like:\n");
    print_sums(test);
    printf("\nAbout to initialize the sum_table, with elements 1, 5, 2, -2\n");

    initialize_sum_table(test, A);
    printf("After initialize_sum_table, the sums now look like:\n");
    print_sums(test);
    printf("\nAbout to fill_sums:\n");
    fill_sums(test);
    printf("After filling the sums, the sums now look like:\n");
    print_sums(test);
    printf("\nCalculating the result:\n");
    result = get_min_abs_sum(test);
    printf("The result is: \n%d\n", result);
    printf("\nAfter filling the sums, going to destroy the test\n");
    destroy_sum_table(test);


    /*
    printf("About to construct a new sum_table, for N = 4\n");
    N = 4;
    int A[] = { 4, 4, 4, 3 };
    SumTable test = new_sum_table(A, N);
    printf("After constructing the new sum_table, the sums look like:\n");
    print_sums(test);
    printf("\nAbout to initialize the sum_table, with elements 4, 4, 4, 3\n");

    initialize_sum_table(test, A);
    printf("After initialize_sum_table, the sums now look like:\n");
    print_sums(test);
    printf("\nAbout to fill_sums:\n");
    fill_sums(test);
    printf("After filling the sums, the sums now look like:\n");
    print_sums(test);
    printf("\nCalculating the result:\n");
    result = get_min_abs_sum(test);
    printf("The result is: \n%d\n", result);
    printf("\nAfter filling the sums, going to destroy the test\n");
    destroy_sum_table(test);
    */

    /*
    printf("About to construct a new sum_table, for N = 4\n");
    int A[] = {
        5 + 42,
        10 + 42,
        15 + 42,
        20 + 42,
        30 + 42,
        40 + 42,
        50 + 42
    };
    N = 7;
    SumTable test = new_sum_table(A, N);
    printf("After constructing the new sum_table, the sums look like:\n");
    print_sums(test);
    printf("About to initialize the sum_table, with elements 47, 52, 57, 62, 67, 72, 77, 82, 87, 92\n");

    initialize_sum_table(test, A);
    printf("After initialize_sum_table, the sums now look like:\n");
    print_sums(test);
    printf("About to fill_sums:\n");
    fill_sums(test);
    printf("After filling the sums, the sums now look like:\n");
    print_sums(test);
    printf("After filling the sums, going to destroy the test\n");
    destroy_sum_table(test);
    */

    /*
    printf("About to construct a new sum_table, for N = 6\n");
    N = 6;
    int A[] = { 1, 5, 3, -3, -5, 5 };
    SumTable test = new_sum_table(A, N);
    printf("After constructing the new sum_table, the sums look like:\n");
    print_sums(test);
    printf("\nAbout to initialize the sum_table, with elements 1, 5, 3, -3, -5, 5\n");

    initialize_sum_table(test, A);
    printf("After initialize_sum_table, the sums now look like:\n");
    print_sums(test);
    printf("\nAND...the counts look like:\n");
    print_counts(test);
    printf("\nAbout to fill_sums:\n");
    fill_sums(test);
    printf("After filling the sums, the sums now look like:\n");
    print_sums(test);
    printf("\nThe min absolute sum is:\n");
    result = get_min_abs_sum(test);
    printf("%d", result);
    printf("\nAfter filling the sums, going to destroy the test\n");
    destroy_sum_table(test);
    */
}
