#include "stl.h"
#include "matrix.h"

#ifndef __TRANSFORM_H
#define __TRANSFORM_H

#define PI 3.1415926

typedef struct s_stl_transformer {
		stl_object *object;

		float4x4 transform;
} stl_transformer;

stl_transformer *transformer_alloc(stl_object *obj);
void transformer_free(stl_transformer *t);

stl_transformer *transformer_init(stl_transformer *t, stl_object *obj);

void transform_chain(stl_transformer *t, float4x4 transform);
void transform_apply(stl_transformer *t);

// Composite wrappers
#define mp_transformer_free(x) transformer_free(kl_val(x))
KLIST_INIT(transformer, stl_transformer*, mp_transformer_free)

// Conversion helpers
void float3tofloat4x1(const float3 *v, float4x1 *m);
void float4x1tofloat3(const float4x1 *m, float3 *v);

// Available transforms definition
typedef float4x4* (*transform_t)(float4x4 *t, char *args);
typedef struct s_transformer {
		char *name;
		char *description;
		transform_t fun;
} transformer;

// The UI searches for transforms by name from this list.
// The last element is a NULL'd out `transformer'
extern const transformer transformers[];
transform_t transform_find(const char *name);


#endif
