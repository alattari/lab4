#include <stdarg.h>
#include <stdio.h>

float average(int n_args, ...)
{
    va_list myList;
    va_start(myList, n_args);
    int numbersAdded = 0;
    int sum = 0;
    while (numbersAdded < n_args) {
        /* Get next number from list */
        int number = va_arg(myList, int);
        sum += number;
        numbersAdded += 1;
    }
    va_end(myList);
    /* Find the average */
    float avg = (float)(sum) / (float)(numbersAdded); 
    return avg;
}

int main(void)
{
    float i;
    i = average(2, 10, 20);
    printf("Avg: %.2f\n", i);
    i = average(6, 1, 2, 3, 4, 5, 6);
    printf("Avg: %.2f\n", i);
    return(0);
}
