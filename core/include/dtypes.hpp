#ifndef DTYPES_HPP
#define DTYPES_HPP

#include <cstddef>


/* Enum to represent different data types */
typedef enum DType {
    UINT8,              // Unsigned 8-bit integer
    UINT16,             // Unsigned 16-bit integer
    UINT32,             // Unsigned 32-bit integer
    UINT64,             // Unsigned 64-bit integer
    INT8,               // Signed 8-bit integer
    INT16,              // Signed 16-bit integer
    INT32,              // Signed 32-bit integer
    INT64,              // Signed 64-bit integer
    FLOAT32,            // 32-bit floating point (float)
    FLOAT64             // 64-bit floating point (double)
} DType;


/* Structure to describe properties of a data type */
class DTypeDesc {
public:
    const char *name;   // Name of the data type as a string (e.g., "int32_t")
    DType type;         // The enum value representing the type
    size_t typeSize;    // Size of the data type in bytes
    size_t alignment;   // Alignment requirement (currently unused, set to 0)
};


/* A static array holding descriptions for each data type
 * Each entry gives the name, type, size (in bytes), and alignment (currently 0)
 */
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

