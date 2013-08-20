#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#ifdef DEBUG
#   include <stdio.h>
#endif

typedef struct VectorT* Vector;

Vector   Vector_new       (void);
void     Vector_free      (Vector vector);
unsigned Vector_size      (Vector vector);
unsigned Vector_capacity  (Vector vector);
unsigned Vector_empty     (Vector vector);
void     Vector_resize    (Vector vector, unsigned size);
void     Vector_reserve   (Vector vector, unsigned size);
void*    Vector_at        (Vector vector, unsigned index);
void**   Vector_data      (Vector vector);
void     Vector_assign    (Vector vector, unsigned index, void* data);
void     Vector_push_back (Vector vector, void* data);
void     Vector_pop_back  (Vector vector);
void     Vector_insert    (Vector vector, unsigned index, void* data);
void     Vector_erase     (Vector vector, unsigned index);
void     Vector_swap      (Vector vector);
void     Vector_clear     (Vector vector);

#endif /* VECTOR_H */

