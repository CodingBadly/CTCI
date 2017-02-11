#include <stdlib.h>
#include <stdio.h>

int test_set_1[] = { 2, 9, 3, 6, 5};
int test_set_2[] = { 65, 2, 34, 2, 6, 9, 11, 56};

int main()
{
    int *test_set = &test_set_1[0];
    int len = sizeof(test_set_1)/sizeof(test_set_1[0]);
    int min = 0;
    int i, j, tmp;
    
    for (i = 0; i < len; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (test_set[j] < test_set[min]) {
                min = j;
            }
        }
        tmp = test_set[i];
        test_set[i] = test_set[min];
        test_set[min] = tmp;
    }
    
    for (i = 0; i < len; i++) {
        printf("\r\n%d", test_set[i]);
    }
    
    return 0;
}