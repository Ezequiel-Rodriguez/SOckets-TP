// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <stdio.h> // Reference: https://stackoverflow.com/questions/7690862/program-that-prints-itself-how-does-it-work
char *program = "#include <stdio.h> // Reference: https://stackoverflow.com/questions/7690862/program-that-prints-itself-how-does-it-work%cchar *program = %c%s%c;%cint main()%c{%c  printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10);%c  return 0;%c}";
int main()
{
  printf(program, 10, 34, program, 34, 10, 10, 10, 10, 10);
  return 0;
}