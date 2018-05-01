#ifndef zadanie3_h
#define zadanie3_h

#include <iostream>
#include <stdlib.h>
#include <math.h>

const int MAX = 100;
const int MIN = 1;

struct Point{

    double x;
    double y;
};

struct Node {

    Point p;
    Node *left, *right;
};

Node * new_node(Point arr);

void generate_points(Point * tab, int size);

void show(Point tab[], int size);

Node *build_kd_tree(Node *r, Point p);

Node *insert_kd_tree(Node *r, Point p, int d);

void show_node(Node * n);

void show_tree(Node * r);

#endif
