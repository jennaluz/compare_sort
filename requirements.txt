Compare sorts

Important: Since you can only submit one file, you will need to merge your other
           three sorting progrms into a single file.

Important 2: When you submit, the command line parameter will be 10 (the size of
             the smallest array), but when you use thsi program for your next
             written assignment, you will have to make the smallest input size
             about 10,000 or 100,000 to ensure that every time is at least one
             millisecond (ms).

Important 3: Times on the compueter are in ns, not ms, so you have to divide
             them by 1,000 and still have a number greater than 1.

Important 4: Other than the size of the smallest array there is no input for
             this program. The arrays need to be populated by the code itself.
             Make three copies of each of the three array sizes.

Important 5: This assignment will be marked manually. You will only get 2 marks
             when you submit (for passing the syntax checker).

Write a computer programs merging
   i) straight insertion sort,
   ii) selection sort, and
   iii) quicksort;
and compare their performance on random arrays. The smallest array for each of
them will be the size given as the command line argument.

For example if the user runs ./a.out 10, the output will look somehting like this:
//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                     10|                0|               0|           0|
//|                    100|                0|               0|           0|
//|                   1000|                1|               2|           0|
//+-----------------------+-----------------+----------------+------------+

This is not very useful for comparisons since almost all of the runs were less
than a ms. Once your program is running, try higer initial values until every
value is at least 1. 10,000 is generally enough, but beware, this will take
a while to run, so you might want to start it running and come back to it.

Output the comparative performance (as system-time taken by the programs) in a table.

If the user runs ./a.out 10000, the output will look somehting like this:
//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                  10000|               50|              60|          30|
//|                 100000|              700|             800|         400|
//|                1000000|             8000|            1200|        6000|
//+-----------------------+-----------------+----------------+------------+

Notice that the output table is formatted like a comment.
Run your code three times with values large enough that there are no 0s in the
table and copy and paste the output to the end of your code before you submit it.

Note: To get the current time in milliseconds:
http://man7.org/linux/man-pages/man2/gettimeofday.2.html
   #include <time.h>
   #include <sys/time.h>

   struct timeval start, stop;
   gettimeofday(&start, NULL);
   /// Run code here
   gettimeofday(&stop, NULL);
   selection1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

Note 2: To create a random number:
Do this once:
   #include <stdlib.h>     /* srand, rand */
   #include <time.h>       /* time */
   srand (time(NULL));

Then use this any time you need another random number:
   int newvalue = rand() %10; // get a number from 0 to 9
Error: Init Input failed
