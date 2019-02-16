#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getColor(char *name) {
  char *code;
  char *output = "";

  if (strcasecmp(name, "yellow") == 0) {
    code = "33";
  } else if (strcasecmp(name, "red") == 0) {
    code = "31";
  } else if (strcasecmp(name, "cyan") == 0) {
    code = "36";
  } else if (strcasecmp(name, "reset") == 0) {
    code = "0";
  }
  
  asprintf(&output, "\033[0;%sm", code);

  return output;
}

char *months[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

char *getMonth(int counter) {
  return months[counter];
}

int main(void) {
  char *output = "";
  double avg = 0;
  int monthLength = sizeof(months) / sizeof(*months);
  double sum = 0;

  for (int counter = 0; counter < monthLength; counter++) {
    char *currentMonth = getMonth(counter);
    double temperature;

    printf("%sEnter for temperature for %s%s:%s ", getColor("yellow"), getColor("cyan"), currentMonth, getColor("reset"));
    scanf("%lf", &temperature);
    sum += temperature;
    asprintf(&output, "%s%s: %.2f; ", output, currentMonth, temperature);
  }

  avg = sum / monthLength;

  printf("\n%sResults:%s %s\n\n", getColor("yellow"), getColor("reset"), output);
  printf("%sTemperature sum for the year: %s%.2f%s\n", getColor("yellow"), getColor("red"), sum, getColor("reset"));
  printf("%sAverage temperature for the year: %s%.2f%s\n", getColor("yellow"), getColor("red"), avg, getColor("reset"));
}
