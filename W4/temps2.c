// Name: Selenko Margarita
// Student Number:147393169
// Email:margonia111@gmail.com
// Section: IPC144SXX
// Workshop:4

#include <stdio.h>
#define MaxAmount 10
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
  int day;
  int i;
  int high[MaxAmount];
  int low[MaxAmount];
  int max = 0;
  int min = 0;
  int dayl;
  int dayh;
  int numOfday;
  float average = 0;
  printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
  printf("Please enter the number of days between 3 and 10, inclusive: ");
  scanf("%d", &day);
  printf("\n");

  while (3 > day || day > 10) {
    printf("\nInvalid entry,please enter a number between 3 and 10, inclusive: ");
    scanf("%d", &day);
    printf("\n");
  }
  for (i = 0; i < day; i++) {
    printf("Day %d - High: ", i + 1);
    scanf("%d", &high[i]);
    printf("Day %d - Low: ", i + 1);
    scanf("%d", &low[i]);
    if (low[i] < min && high[i] > max) {
      min = low[i];
      dayl = i + 1;
      max = high[i];
      dayh = i + 1;
    }
    while (high[i] < low[i]) {
      printf("Incorrect values, high must be greater than low");
      printf("Day %d - High: ", i + 1);
      scanf("%d", &high[i]);
      printf("Day %d - Low: ", i + 1);
      scanf("%d", &low[i]);
    }
  }
  printf("\nDay  Hi  Low\n");
  for (i = 0; i < day; i++) {
    printf("%d %4d %5d\n", i + 1, high[i], low[i]);
  }
  printf("\nThe highest temperature was %d, on day %d\n", max, dayh);
  printf("The lowest temperature was %d, on day %d\n", min, dayl);
  do {
    printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
    scanf("%d", &numOfday);
    if (numOfday < 0) {
      printf("\nGoodbye!\n");
      break;
    }
    while (1 > numOfday || numOfday > day) {
      printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", day);
      scanf("%d", &numOfday);
    }
    average = 0;
    for (i = 0; i < numOfday; i++) {
      average += (high[i] + low[i]);
    }
    average /= (numOfday * 2);
    printf("\nThe average temperature up to day %d is: %.2f\n", numOfday, average);
  } while (numOfday != 0);

  return 0;
}
