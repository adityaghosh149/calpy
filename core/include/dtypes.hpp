#ifndef DTYPES_HPP
#define DTYPES_HPP

#include <cstddef>

typedef enum DType {
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    INT8,
    INT16,
    INT32,
    INT64,
    FLOAT32,
    FLOAT64
} DType;

class DTypeDesc {
public:
    const char *name; 
    DType type;
    size_t typeSize;
    size_t alignment;
};

static DTypeDesc dTypeDesc[] = {
    {"uint8_t",  UINT8,   1, 0},
    {"uint16_t", UINT16,  2, 0},
    {"uint32_t", UINT32,  4, 0},
    {"uint64_t", UINT64,  8, 0},
    {"int8_t",   INT8,    1, 0},
    {"int16_t",  INT16,   2, 0},
    {"int32_t",  INT32,   4, 0},
    {"int64_t",  INT64,   8, 0},
    {"float",    FLOAT32, 4, 0},
    {"double",   FLOAT64, 8, 0}
};

#endif // DTYPES_HPP


