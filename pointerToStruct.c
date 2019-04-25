#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int year;
  int month;
  int day;
} date;

int main(void) {

  date *today;
  today = malloc(sizeof(date));

  // the explicit way of accessing fields of our struct
  (*today).day = 15;
  (*today).month = 6;
  (*today).year = 2012;

  // the more readable shorthand way of doing it
  today->day = 15;
  today->month = 6;
  today->year = 2012;

  printf("the date is %d/%d/%d\n", today->day, today->month, today->year);

  free(today);

  return 0;
}
