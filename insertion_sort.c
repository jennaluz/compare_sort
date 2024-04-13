#include "insertion_sort.h"

#include <stdio.h>

// Print the list
void print_insertion_sort(int list[], int length, int sorted_length)
{
   for (int i = 0; i < length; i++) {
      printf("%d ", list[i]);

      if ((sorted_length == 0 && i == 0) || i + 1 == sorted_length) {
         printf("| ");
      }
   }

   printf("\n");
}

// Use the insertion sort algorithm to sort the list
void insertion_sort(int list[], int length)
{
   for (int i = 1; i < length; i++) {
      int current_value = list[i];
      int search_idx = i - 1;

      while (search_idx >= 0 && list[search_idx] > current_value) {
         list[search_idx + 1] = list[search_idx];
         search_idx--;
      }

      list[search_idx + 1] = current_value;
#ifdef DEBUG
      print_insertion_sort(list, length, i + 1);
#endif
   }
}
