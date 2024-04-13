#include <stdio.h>
#include <stdlib.h>

void swap(int list[], int idx_1, int idx_2)
{
   int tmp = list[idx_1];

   list[idx_1] = list[idx_2];
   list[idx_2] = tmp;
}

// Use the Hoare's Partition algorithm to divide the list
int hoare_partition(int list[], int start, int end)
{
   int pivot = list[start];
   int i = start + 1;
   int j = end;

   //printf("before partition start %d end %d\n", start, end);

   for (;;) {
      while (list[i] <= pivot && i < end) {
         i++;
      }

      while (list[j] >= pivot && j > start) {
         j--;
      }

      if (i < j) {
         swap(list, i, j);
      } else {
         swap(list, start, j);
         return j;
      }
   }

   //printf("after partition start %d end %d\n", start, end);
}

void print_quick_sort(int list[], int length, int start, int end)
{
   for (int i = 0; i < length; i++) {
      if (i == start) {
         printf("[%d ", list[i]);
         continue;
      }
      if (i == end) {
         printf("%d]  ", list[i]);
         continue;
      }

      printf("%d ", list[i]);
   }

   printf("\n");
}

void quick_sort(int list[], int length, int start, int end)
{
   if (start < end) {
      int split = hoare_partition(list, start, end);

      //printf("before sort length %d start %d end %d\n", length, start, end);
      quick_sort(list, length, start, split - 1);
      //printf("middle sort length %d start %d end %d\n", length, start, end);
      quick_sort(list, length, split + 1, end);
      //printf("after sort length %d start %d end %d\n", length, start, end);

#ifdef DEBUG
      print_quick_sort(list, length, start, end);
#endif
   }
}
