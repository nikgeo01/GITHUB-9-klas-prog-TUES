#include <stdio.h>

void printcharsonnewline(char *s);

int main() {
  char input[] = "someString";
  printcharsonnewline(input);

  return 0;
}

void printcharsonnewline(char *s) {
  for (int index = 0; s[index] != '\0'; index++)//Char e zamenen s int zashtoto index e celochisen.
  {                                             //Slozhena e naklonena cherta zashtoto
    char currentchar = s[index];                //taka se oznachava nuleviqt bajt. drugoto e simvolyt 0.
    printf("%c\n", currentchar);
  }
}
