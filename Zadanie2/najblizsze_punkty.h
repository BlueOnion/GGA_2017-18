#ifndef najblizsze_punkty_h
#define najblizsze_punkty_h

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>

struct Punkt {

    double x;
    double y;
};

struct Punkt_dist {

    double x1;
    double x2;
    double y1;
    double y2;
    double dist;
};

void generuj_punkty(Punkt * tab, int size);

void show(Punkt tab[], int size);

bool sort_x(Punkt a, Punkt b);

Punkt_dist oblicz_odleglosc(Punkt a, Punkt b);

Punkt_dist znajdz_odleglosci(Punkt * X, int size);

Punkt_dist para_najblizszych_punkt(Punkt * X, int size);

#endif
