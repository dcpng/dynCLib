#include "dyn_c_lib.h"
#include <stdlib.h>

typedef struct dcl_context_s
{
    dcl_object_t hdr
} dcl_context_t;

static dcl_result_t *dcl_call(
    dcl_object_t *self,
    dcl_atom_t method_atom,
    dcl_value_t *output,
    dcl_arglist_t input)
{

}

dcl_object_t *dcl_new_context()
{
    dcl_context_t *result = calloc(1, sizeof(dcl_context_t));
    result->hdr.call = dcl_call;
}