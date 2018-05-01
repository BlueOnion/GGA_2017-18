#ifndef zadanie2_h
#define zadanie2_h
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>

struct Point {

    double x;
    double y;
};

struct Point_dist {

    double x1;
    double x2;
    double y1;
    double y2;
    double dist;
};

void generate_points(Point * tab, int size);

void show(Point tab[], int size);

void mix_tables(Point * tab, Point * X, Point * Y, int size);

void merge_x(Point * tab, int p, int q, int r);

void merge_y(Point * tab, int p, int q, int r);

void merge_sort(Point * tab, int p, int r, char xy);

Point_dist calc_distance(Point a, Point b);

double find_l(int size, Point * X);

void closest_pair_of_points(int size, Point * tab, Point * X, Point * Y);

#endif
