#pragma once
#include <stdint.h>

typedef struct dcl_atom_s
{
    char *name;
    uint32_t value;
} dcl_atom_t;

typedef struct dcl_object_s dcl_object_t;
typedef union dcl_value_u
{
    uint8_t uint8;
    int8_t int8;
    uint16_t uint16;
    int16_t int16;
    uint32_t uint32;
    int32_t int32;
    uint64_t uint64;
    int64_t int64;
    float float32;
    double float64;
    dcl_object_t *obj;
    char *user;
} dcl_value_t;

typedef struct dcl_result_s
{
    char *type_name;
    dcl_value_t value;
} dcl_result_t;

typedef struct dcl_arglist_s
{
    size_t length;
    dcl_value_t values[];
} dcl_arglist_t;

/**
 * @brief interface for invoking a method from an object
 * @param self     The object that owns the method to be called
 * @param method   The atom representing the method to be called
 * @param input    The Input arg list
 * @param output   The output of the method
 *
 * @return returns a result
 */
typedef dcl_result_t *(*dcl_call_t)(dcl_object_t *self, dcl_atom_t method, dcl_value_t *output, dcl_arglist_t input);

/**
 * @brief interface to an object
 */
struct dcl_object_s
{
    /**
     * @brief use by the service consumer to call different methods
     */
    dcl_call_t call;
};

/**
 * @brief creates new dcl plugin-context for managing dynamic objects
 * @return dcl_object_t* object for the plugin-context
 */
dcl_object_t *dcl_new_context();

#define DCL_CALL_ATOM_REGISTER ((dcl_atom_t){"[dcl.core]atom_register", 0x01})
#define DCL_CALL_ATOM_UNREGISTER ((dcl_atom_t){"[dcl.core]atom_unregister", 0x02})
#define DCL_CALL_ATOM_GET_DOMAIN_ID ((dcl_atom_t){"[dcl.core]atom_get_domain_id", 0x03})
#define DCL_CALL_ATOM_GET_VALUE_ID ((dcl_atom_t){"[dcl.core]atom_get_value_id", 0x04})