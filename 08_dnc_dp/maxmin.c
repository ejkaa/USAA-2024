#include "maxmin.h"

#ifndef MAX
#define MAX(a,b) ((a)>(b)?a:b)
#endif
#ifndef MIN
#define MIN(a,b) ((a)<(b)?a:b)
#endif


pair MaxMin(int A[], int L, int H) {
    int length = H - L;
    pair ret1, ret2, ret;

    ret.min = A[L];
    ret.max = A[H];

    if (length == 1) {
        if (A[L] > A[H]) {
            ret.min = A[H];
            ret.max = A[L];
        }
    }

    else if (length > 1) {
        int middle = (L+H) /2;

        ret1 = MaxMin(A, L, middle);
        ret2 = MaxMin(A, middle +1, H);

        ret.min = MIN(ret1.min, ret2.min);
        ret.max = MAX(ret1.max, ret2.max);
    }
    return ret;
}

