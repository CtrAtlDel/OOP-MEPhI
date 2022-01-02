#ifndef SPARCEMATRIX_SPARCEMATRIX_H
#define SPARCEMATRIX_SPARCEMATRIX_H

namespace Matrix {
    struct Data {
        int i;
        int j;
        int element;
    };
    struct Line {
        Data *data;
        Line *line;
    };
    struct Collumn {
        Line **first;
    };
    struct Matrix {
        Collumn 
    };
}

#endif //SPARCEMATRIX_SPARCEMATRIX_H
