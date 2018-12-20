#include <stdio.h>
#include "vec.h"

Vec3 ORIGIN = {0.0, 0.0, 0.0};

int main(void) {
    Vec3 vecA = {10.0, 20.0, 30.0};
    Vec3 vecB = {30.0, 20.0, 10.0};
    printf("Vec A: ");
    printVec3(&vecA);
    printf("Vec B: ");
    printVec3(&vecB);

    Vec3 mvec; // temp vector storage
    mvec = add3(&vecA, &vecB);
    printf("Sum:   ");
    printVec3(&mvec);
    mvec = sub3(&vecA, &vecB);
    printf("Diff:  ");
    printVec3(&mvec);
    mvec = cross3(&vecA, &vecB);
    printf("Cross: ");
    printVec3(&mvec);
    printf("Dot:   %f\n", dot3(&vecA, &vecB));
}