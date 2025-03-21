#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  /* initialize random seed: */
  srand(time(NULL));

  /* generate secret number between 0 and 1: */
  int iSecret = rand() % 2;

  return iSecret;
}