#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned long generate()
{
  unsigned long cpf = 0;//= (99999999 + rand()) % 100000000;
  for (int i = 0; i < 8; ++i)
  {
    cpf += rand() % 10;
    cpf *= 10;
  }
  cpf += 9;
  unsigned long runner = cpf;
  int j, k;
  int sum = 0, sum2 = 0;
  for (int i = 0; i < 9; i++)
  {
    sum += (2 + i) * (runner % 10);
    if (i != 8)
      sum2 += (3 + i) * (runner % 10);
    runner /= 10;
  }
  j = 11 - sum % 11;
  sum2 += 2 * j;
  k = sum2 % 11;
  k = k < 2 ? 0 : 11 - k;

  printf("%9ld-%1d%1d\n", cpf, j, k);
  return cpf * 100 + 10 * j + k;
}

char validate(unsigned long cpf)
{
  long sum = 0, sum2 = 0;
  unsigned long runner = cpf / 100;
  unsigned int j, k;

  switch (cpf)
  {
    case 0:
    case 11111111111:
    case 22222222222:
    case 33333333333:
    case 44444444444:
    case 55555555555:
    case 66666666666:
    case 77777777777:
    case 88888888888:
    case 99999999999:
      return 0;
    default:
      break;    
  } 

  for (int i = 0; i < 9; i++)
  {
    sum += (2 + i) * (runner % 10);
    if (i != 8)
      sum2 += (3 + i) * (runner % 10);
    runner /= 10;
  }
  j = 11 - sum % 11;
  sum2 += 2 * j;
  k = sum2 % 11;
  k = k < 2 ? 0 : 11 - k;

  printf("cpf was: %ld\n", cpf);
  printf("State: %1ld\n", (cpf / 100) % 10);
  printf("j should be %1d, got %1ld\n", j, (cpf / 10) % 10);
  printf("k should be %1d, got %1ld\n", k, cpf % 10);

  return k == cpf % 10 && j == (cpf / 100) % 10;
}

int main(int argc, char **argv, char **envp) {
  (void) argc;
  (void) argv;
  (void) envp;

  printf("%s\n", validate(generate()) ? "valid" : "invalid");
  //validate(123456789123);
}
