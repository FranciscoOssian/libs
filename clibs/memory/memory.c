#include <stdlib.h>
#include <stdio.h>

#include "memory.h"

void *mallocc (size_t nbytes) {
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == NULL) {
      printf ("bad malloc - NULL!\n");
      exit (EXIT_FAILURE);
   }
   return ptr;
}
