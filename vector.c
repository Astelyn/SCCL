#include "vector.h"

struct VectorT {
    void**   data;
    unsigned size;
    unsigned capacity;
};

Vector Vector_new(void)
{
    Vector vector = malloc(sizeof(struct VectorT));
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    return vector;
}

void Vector_free(Vector vector)
{
    free(vector->data);
    free(vector);
}

unsigned Vector_size(Vector vector)
{
    return vector->size;
}

unsigned Vector_capacity(Vector vector)
{
    return vector->capacity;
}

unsigned Vector_empty(Vector vector)
{
    return vector->size == 0;
}

void Vector_resize(Vector vector, unsigned size)
{
    if (size == 0) {
        free(vector->data);
        vector->size = 0;
        vector->capacity = 0;
        return;
    }

    if (size < vector->size)
        vector->size = size;

    vector->capacity = size;
    vector->data = realloc(vector->data, sizeof(void*) * size);
}

void Vector_reserve(Vector vector, unsigned size)
{
    if (size <= vector->capacity)
        return;

    vector->capacity = size;
    vector->data = realloc(vector->data, sizeof(void*) * size);
}

void* Vector_at(Vector vector, unsigned index)
{
    if (index >= vector->capacity)
        return NULL;

    return vector->data[index];
}

void** Vector_data(Vector vector)
{
    return vector->data;
}

void Vector_assign(Vector vector, unsigned index, void* data)
{
    if (index >= vector->size)
        return;

    vector->data[index] = data;
}

void Vector_push_back(Vector vector, void* data)
{
    if (vector->capacity == 0) {
        vector->capacity = 1;
        vector->data = calloc(1, sizeof(void*));
    }

    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(void*) * vector->capacity);
    }

    vector->data[vector->size] = data;
    vector->size++;
}

void Vector_pop_back(Vector vector)
{
    if (vector->size == 0)
        return;

    vector->size--;
    vector->data[vector->size] = NULL;
}

void Vector_insert(Vector vector, unsigned index, void* data)
{
    // TODO
}

void Vector_erase(Vector vector, unsigned index)
{
    if (index >= vector->size)
        return;

    // TODO

    vector->size--;
}

void Vector_clear(Vector vector)
{
    free(vector->data);
    vector->size = 0;
    vector->capacity = 0;
}

#ifdef DEBUG
int main(void)
{
    Vector vec = Vector_new();
    fprintf(stderr, "Vector initialized\n");

    Vector_push_back(vec, "test1");
    fprintf(stderr, "Pushed 'test1' | ");
    fprintf(stderr, "Size: %d, Capacity: %d\n", Vector_size(vec), Vector_capacity(vec));
    Vector_push_back(vec, "test2");
    fprintf(stderr, "Pushed 'test2' | ");
    fprintf(stderr, "Size: %d, Capacity: %d\n", Vector_size(vec), Vector_capacity(vec));
    Vector_push_back(vec, "test3");
    fprintf(stderr, "Pushed 'test3' | ");
    fprintf(stderr, "Size: %d, Capacity: %d\n", Vector_size(vec), Vector_capacity(vec));

    Vector_pop_back(vec);
    fprintf(stderr, "Popped back    | ");
    fprintf(stderr, "Size: %d, Capacity: %d\n", Vector_size(vec), Vector_capacity(vec));

    char** data = (char**)Vector_data(vec);
    fprintf(stderr, "data[1]: %s\n", data[1]);

    Vector_free(vec);
    fprintf(stderr, "Vector freed\n");

    return 0;
}
#endif

