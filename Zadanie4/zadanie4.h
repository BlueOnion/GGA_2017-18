#ifndef zadanie4_h
#define zadanie4_h

#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <vector>

struct Punkt {

    int x;
    int y;
};

struct Odcinek {

    Punkt start;
    Punkt stop;
};

struct miotla {

    vector <Odcinek> odcinki;
};

void tworz_odcinki(Odcinek * S, int size);

void merge(Odcinek * tab, int p, int q, int r);

void merge_sort(Odcinek * tab, int p, int r);

#endif // zadanie4_h
