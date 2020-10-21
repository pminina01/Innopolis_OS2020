#include <stdio.h>
#include <stdlib.h> //for malloc
int main() {
  char **s;
  char foo[] = "Hello World";
  s = malloc(sizeof(char *)); //allocate memory for s
  *s = foo;

  //printf("s is %s\n”,s); last vertion
  printf("*s is %p\n",*s); //new fixed vertion

  s[0] = foo;
  printf("s[0] is %s\n",s[0]);
  return(0);
} 