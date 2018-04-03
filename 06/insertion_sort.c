#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ARRAY_MAX determines the max number of items you can sort */
#define ARRAY_MAX 30000

/** sorts an array using insertion sort.
    @param int a* takes an array.
    @param n is the length of the array.
*/
void insertion_sort(int *a, int n){
    int p=0, key=0, left=0;

    /* keeps place in the array */
    for (p = 1; p < n; p++){
        key = a[p];
        left = p-1;

        /* checks comparison and swaps elements as necessary */
        while (left>=0 && a[left] > key){
            a[left+1] = a[left];
            left --;
        }  
        a[left+1]=key;
    }      
}

void print_array(int *a, int n){
    if (n > 0){
        printf("%d\n", a[0]);
        print_array(a+1, n-1);
    }
}

/** main method takes no parameters and populates an array with the input
    from a scan and then calls inserton_sort on the array.
    times insertion_sort and prints this out to stderr.
    @return 0 for unsuccessful and 1 for successful.
*/
int main(void){
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    /*populates array with input from scan */
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count ++;
    }
    start = clock();
    insertion_sort(my_array, count);
    end = clock();

    /* prints out the sorted array */
    for (i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    /* prints out the time insertion sort took to stderr */
    fprintf (stderr, "%d %f\n", count, (end-start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}