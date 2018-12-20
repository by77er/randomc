#pragma once

typedef struct _ind Block;

struct _ind {
    int value;
    Block* next;
};

typedef struct _v3 {
    double x;
    double y;
    double z;
} Vec3;

typedef struct _v2 {
    double x;
    double y;
    double z;
} Vec2;

int veq2(Vec2* v1, Vec2* v2);

int veq3(Vec3* v1, Vec3* v2);

void printVec3(Vec3* v);

void printVec2(Vec2* v);

double mag2(Vec2* v);

double mag3(Vec3* v);

Vec2 add2(Vec2* v1, Vec2* v2);

Vec3 add3(Vec3* v1, Vec3* v2);

Vec2 sub2(Vec2* v1, Vec2* v2);

Vec3 sub3(Vec3* v1, Vec3* v2);

double dot2(Vec2* v1, Vec2* v2);

double dot3(Vec3* v1, Vec3* v2);

Vec3 cross3(Vec3* v1, Vec3* v2);