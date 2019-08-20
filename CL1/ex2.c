// *
// *
// *
// *
// Para atender o exercício foi alterado o alfabeto para 𝝨={A,B}, e inclui a variavel b
// para controlar a recursão.
// *
// *
// *
#include<stdio.h>

static char *cur_char;
static int b;

int B_prod()
{
  if (*cur_char == 'A' && b==0) {
    cur_char++;
    //B_prod == 1 (!0==1)
    if (!B_prod()) return 0;

    if (*cur_char != 'B')
      return 0;
    b=1;
    cur_char++;

    return B_prod();
  }
  
  return 1;
}

int main()
{
  char buffer[256];

  while (scanf("%255s", buffer)) {
    cur_char = buffer;
    b=0;
    if (!B_prod() || *cur_char) {
      printf("Palavra inválida:\n");
      printf("    %s\n", buffer);

      for (int i = 0; i < cur_char - buffer; i++)
        putchar(' ');

      printf("    ^\n");
    }
    else
      printf("Palavra válida\n");
  }

  return 0;
}