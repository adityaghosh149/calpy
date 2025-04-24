#ifndef NDIMARRAY_HPP
#define NDIMARRAY_HPP

#include <cstdint>

#include "dtypes.hpp"

class NDimArray {
public:
    int ndim;
    int64_t* shape;
    DTypeDesc *desc;
    void *data;
    int64_t* strides;
    int flags;
};

#endif // NDIMARRAY_HPP
