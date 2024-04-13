#include "insertion_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void randomize_input(int input[], int length);
float measure_insertion_sort(int input[], int length);
float measure_quick_sort(int input[], int length);
float measure_selection_sort(int input[], int length);
void print_metrics(float metrics[]);

int main(int argc, char* argv[])
{
   if (argc <= 1) {
      return 0;
   }

   int min_size = atoi(argv[1]);
   int input_one_length = min_size;
   int input_two_length = min_size * 10;
   int input_three_length = min_size * 100;

   int input_one[input_one_length];
   int input_two[input_two_length];
   int input_three[input_three_length];

   //randomize_input(input_one, input_one_length);
   //randomize_input(input_two, input_two_length);
   randomize_input(input_three, input_three_length);

   //float insertion_sort_metrics[3];
   //float quick_sort_metrics[3];
   //float selection_sort_metrics[3];

   //insertion_sort_metrics[0] = measure_insertion_sort(input_one, input_one_length);
   //insertion_sort_metrics[1] = measure_insertion_sort(input_two, input_two_length);
   //insertion_sort_metrics[2] = measure_insertion_sort(input_three, input_three_length);

   printf("%f \n", measure_quick_sort(input_one, input_one_length));
   printf("%f \n", measure_quick_sort(input_two, input_two_length));
   printf("%f \n", measure_quick_sort(input_three, input_three_length));

   //printf("%f\n", measure_selection_sort(input_one, input_one_length));
   //printf("%f\n", measure_selection_sort(input_two, input_two_length));
   //printf("%f\n", measure_selection_sort(input_three, input_three_length));

   //print_metrics(insertion_sort_metrics);
   //print_metrics(quick_sort_metrics);
   //print_metrics(selection_sort_metrics);
}

void randomize_input(int input[], int length)
{
   srand(time(NULL));

   for (int i = 0; i < length; i++) {
      input[i] = rand() % 10;
   }
}

float measure_insertion_sort(int input[], int length)
{
   struct timeval start;
   struct timeval stop;

   gettimeofday(&start, NULL);
   insertion_sort(input, length);
   gettimeofday(&stop, NULL);

   return (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
}

float measure_quick_sort(int input[], int length)
{
   struct timeval start;
   struct timeval stop;

   gettimeofday(&start, NULL);
   quick_sort(input, length, 0, length - 1);
   gettimeofday(&stop, NULL);

   return (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
}

float measure_selection_sort(int input[], int length)
{
   struct timeval start;
   struct timeval stop;

   gettimeofday(&start, NULL);
   selection_sort(input, length);
   gettimeofday(&stop, NULL);

   return (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;
}


void print_metrics(float metrics[])
{
   for (int i = 0; i < 3; i++) {
      printf("%f ", metrics[i]);
   }
   printf("\n");
}
