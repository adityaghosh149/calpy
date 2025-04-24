#ifndef NDIMARRAY_HPP
#define NDIMARRAY_HPP

#include <cstdint>

#include "dtypes.hpp"

/* Class representing a multi-dimensional array */
class NDimArray {
public:
    int ndim;               // Number of dimensions of the array (e.g., 1D, 2D, 3D)
    int8_t* shape;         // Pointer to array storing the size of each dimension
                            // Example: shape = [2, 3] means a 2x3 matrix

    DTypeDesc *desc;        // Pointer to data type description (from dtypes.hpp)
                            // Contains type info like name, size, etc.

    void *data;             // Raw pointer to the data stored in the array
                            // The actual data (int, float, etc.) is stored here

    int64_t* strides;       // Pointer to array of strides (steps to move in memory between elements)
                            // Used to calculate how to move across elements in memory

    int flags;              // Flags to store extra properties (e.g., whether memory is contiguous)
                            // Not used yet but can be helpful later
};


NDimArray* narray(int* shape, DType type=FLOAT32);

#endif // NDIMARRAY_HPP
