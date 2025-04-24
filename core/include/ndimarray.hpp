#ifndef NDIMARRAY_HPP
#define NDIMARRAY_HPP

struct NDimArray {
    int ndim;
    int64_t* shape;
    DTypeDesc *desc;
    void *data;
    int64_t* strides;
    int flags;
};

#endif 