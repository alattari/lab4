/*
  CPSC 223C
  Spring 2015
  CSU Fullerton
  Lab 4: variable arguments
  Authors: Kevin Wortman (kwortman@csu.fullerton.edu)
           Victor Pires (victor.pires@csu.fullerton.edu)
*/

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

/* num is the number of variable arguments, all of type int. Compute
   and return the median of the variable arguments. Recall that in the
   case of an even number of arguments, you need to take the mean of
   the two arguments closest to the middle, which is why the return
   type is double. */
double median(int num, ...);

/* num is the number of variable arguments, all of type int. Compute
   and return the mode of the variable arguments. Recall that the mode
   is the most frequently-ocurring value. If there are multiple values
   tied for the same number of occurences, return the lesser of the
   tied values.
 */
int mode(int num, ...);

double median(int num, ...) {
    int array [num];
    int x, y, temp;
    double med;
    va_list myList;
    va_start (myList, num);
    for (x = 0; x < num; x++)
        array[x] = va_arg (myList, int);
    for(x = 0; x < num; x++) {
        for(y = 0; y < (num - 1); y++) {
            if(array[y] > array[y + 1]) {
                int temp = array[y + 1];
                array[y + 1] = array[y];
                array[y] = temp;
            }
        }
    }
    if (!(num%2)) {
        med = ((array[(num / 2) - 1] + array[(num / 2)]) / 2.0);
    } else {
        if (num == 1) {
            med = array[0];
        } else {
            med = array[(num/2)];
        }
    }
    va_end (myList);
    return(med);
}

int mode(int num, ...) {
    int array [num];
    int x, y, temp;
    int mod;
    int aux = 1, auxMax = 1, pos = 0;
    va_list myList;
    va_start (myList, num);
    for (x = 0; x < num; x++)
        array[x] = va_arg (myList, int);
    printf("[");
    for (x = 0; x < (num-1); x++)
        printf("%d, ", array[x]);
    printf("%d]\n", array[x]);
    /* Bubble sort */
    for ( x = 0; x < num; x++) {
        for ( y = 0; y < (num - 1); y++) {
            if(array[y] > array[y + 1]) {
                int temp = array[y + 1];
                array[y + 1] = array[y];
                array[y] = temp;
            }
        }
    }

    for (x = 0; x < (num); x++){
        if(array[x] != array[x + 1])
        {
            auxMax = aux;
            aux = 1;
        }
        else if(aux > auxMax)
        {
            pos = x;
        }

        else{
            aux++;
        }
    }

    va_end (myList);
    return(array[pos]);
}

int main() {

  /* MEDIAN */

  /* one argument */
  assert(median(1, 1) == 1);

  /* special case: even number of arguments */
  assert(median(2, 1, 2) == 1.5);

  /* straightforward three-argument cases */
  assert(median(3, 1, 2, 3) == 2);
  assert(median(3, 3, 2, 1) == 2);
  assert(median(3, 3, 3, 3) == 3);

  /* straightforward four-argument cases */
  assert(median(6, 9, -10, -1, 8, 3, 5) == 4);
  assert(median(7, 5, 6, 4, 1, 2, 3, 7) == 4);

  /* TODO: you should add at least two more test cases for your
     median() function here. */
  assert(median(1, 7) == 7);
  assert(median(7, 1, 1, 1, 1, 1, 1, 1) == 1);

    printf ("Median done!\n");//<<<<<<<<<<<<<<<<<<<
  /* MODE */
  mode(1, 1);

  /* straightforward cases */
  assert(mode(1, 1) == 1);
  assert(mode(3, 2, 1, 1) == 1);
  assert(mode(7, 1, 1, 1, 2, 2, 2, 2) == 2);

  /* special case: tie */
  assert(mode(6, 3, 3, 3, 2, 2, 2) == 2);
  assert(mode(6, 2, 3, 2, 3, 2, 3) == 2);

  /* TODO: you should add at least two more test cases for your mode()
     function here. */

  printf ("Mode done!\n");//<<<<<<<<<<<<<<<<<<<
  return(0);
}
