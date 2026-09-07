#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

int main() {

  printf("=====Empty Dequeue=====");
  Deq q=deq_new();

  char *s=deq_str(q,0);
  printf("\nEmpty Queue: %s\n",s); //Queue shouldn't print anything
  free(s);

  deq_del(q,0);

  
  return 0;
}
