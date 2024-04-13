#include "selection_sort.h"

#include <stdio.h>

// Print the list
void print_selection_sort(int list[], int length)
{
   for (int i = 0; i < length; i++) {
      printf("%d ", list[i]);
   }

   printf("\n");
}

// Use the selection sort algorithm to sort the list
void selection_sort(int list[], int length)
{
   for (int i = 0; i < length - 1; i++) {
      int min_idx = i;

      for (int j = i + 1; j < length; j++) {
         if (list[j] < list[min_idx]) {
            min_idx = j;
         }
      }

      if (min_idx != i) {
         int tmp = list[i];
         list[i] = list[min_idx];
         list[min_idx] = tmp;
      }

#ifdef DEBUG
      print_selection_sort(list, length);
#endif
   }
}
