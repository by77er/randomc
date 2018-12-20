#include <stdio.h>
#include <math.h>
#include "vec.h"

int veq2(Vec2* v1, Vec2* v2) {
    if (v1->x == v2->x && v1->y == v2->y) {
        return 1;
    } else {
        return 0;
    }
}

int veq3(Vec3* v1, Vec3* v2) {
    if (v1->x == v2->x && v1->y == v2->y && v1->z == v2->z) {
        return 1;
    } else {
        return 0;
    }
}

void printVec3(Vec3* v) {
    printf("< x: %f, y: %f, z: %f >\n", v->x, v->y, v->z);
}

void printVec2(Vec2* v) {
    printf("< x: %f, y: %f >\n", v->x, v->y);
}

double mag2(Vec2* v) {
    return sqrt(pow(v->x, 2.0) + pow(v->y, 2.0));
}

double mag3(Vec3* v) {
    return sqrt(pow(v->x, 2.0) + pow(v->y, 2.0) + pow(v->z, 2.0));
}

Vec2 add2(Vec2* v1, Vec2* v2) {
    Vec2 sum;
    sum.x = v1->x + v2->x;
    sum.y = v1->y + v2->y;
    return sum;
}

Vec3 add3(Vec3* v1, Vec3* v2) {
    Vec3 sum;
    sum.x = v1->x + v2->x;
    sum.y = v1->y + v2->y;
    sum.z = v1->z + v2->z;
    return sum;
}

Vec2 sub2(Vec2* v1, Vec2* v2) {
    Vec2 sum;
    sum.x = v1->x - v2->x;
    sum.y = v1->y - v2->y;
    return sum;
}

Vec3 sub3(Vec3* v1, Vec3* v2) {
    Vec3 sum;
    sum.x = v1->x - v2->x;
    sum.y = v1->y - v2->y;
    sum.z = v1->z - v2->z;
    return sum;
}

double dot2(Vec2* v1, Vec2* v2){
    return v1->x * v2-> x + v1->y * v2->y;
}

double dot3(Vec3* v1, Vec3* v2) {
    return v1->x * v2-> x + v1->y * v2->y + v1->z * v2->z;
}

Vec3 cross3(Vec3* v1, Vec3* v2) {
    Vec3 n;
    n.x = v1->y * v2->z - v1->z * v2->y;
    n.y = v1->z * v2->x - v1->x * v2->z;
    n.z = v1->x * v2->y - v1->y * v2->x;
    return n;
}