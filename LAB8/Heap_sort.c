
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bottom_up_heapify(int n, int a[]);
void swap(int *a, int *b);
void heap_sort(int n, int a[]);

void bottom_up_heapify(int n, int a[]) {
    int p, item, c;
    for (p = (n-1)/2; p >= 0; p--) {
        item = a[p];
        c = 2 * p + 1;

        while (c <= n - 1) {
            if (c + 1 <= n - 1 && a[c] < a[c + 1]) {
                c++;
            }
            if (item >= a[c]) {
                break;
            }
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        a[p] = item;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(int n, int a[]) {
    int i;
    bottom_up_heapify(n, a);

    for (i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        bottom_up_heapify(i, a);
    }
}


int main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;
    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                printf("\nEnter array elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                heap_sort(n, a);
                end = clock();
                printf("\nSorted array is: ");
                for (i = 0; i < n; i++)
                    printf("%d\t", a[i]);
                printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;

            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) {
                        //a[i] = rand() % 1000;
                        a[i] = n - i;
                    }
                    start = clock();
                    heap_sort(n, a);
                    //Dummy loop to create delay
                    for (j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                    n = n + 1000;
                }
                break;
            case 3:
                exit(0);
        }
        getchar();
    }
    return 0;
}
