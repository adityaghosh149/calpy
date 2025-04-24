#ifndef DTYPES_HPP
#define DTYPES_HPP

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
};

struct DTypeDesc {
    const char *name; 
    DType type;
    size_t typeSize;
    size_t alignment;
}

#endif 


