#include "zadanie4.h"
#include <iostream>

using namespace std;

void tworz_odcinki(Odcinek * S, int size) {

    int MAX = 100;
    int MIN = 0;
    int tmp;

    srand(time(NULL));
/*
    for(int i = 0; i < size; i++) {

        tmp = rand()/ RAND_MAX;
        S[i].start.x = MIN + tmp * (MAX - MIN);
        //cout << tab[i].x << " : ";
        tmp = rand()/ RAND_MAX;
        S[i].start.y = MIN + tmp * (MAX - MIN);
        //cout << tab[i].y << endl;
        tmp = rand()/ RAND_MAX;
        S[i].stop.x = MIN + tmp * (MAX - MIN);
        //cout << tab[i].x << " : ";
        tmp = rand()/ RAND_MAX;
        S[i].stop.y = MIN + tmp * (MAX - MIN);
        //cout << tab[i].y << endl;
    }
    */
        S[0].start.x = 4;
        S[0].start.y = 4;
        S[0].stop.x = 4;
        S[0].stop.y = 1;

        S[1].start.x = 1;
        S[1].start.y = 6;
        S[1].stop.x = 4;
        S[1].stop.y = 6;

        S[2].start.x = 3;
        S[2].start.y = 3;
        S[2].stop.x = 8;
        S[2].stop.y = 3;

        S[3].start.x = 7;
        S[3].start.y = 2;
        S[3].stop.x = 10;
        S[3].stop.y = 2;

        S[4].start.x = 6;
        S[4].start.y = 3;
        S[4].stop.x = 6;
        S[4].stop.y = 1;
}

void merge(Odcinek * tab, int p, int q, int r) {

    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;

    Odcinek * L = new Odcinek[n1];
    Odcinek * R = new Odcinek[n2];

    for (i = 0; i < n1; i++) {
        L[i] = tab[p + i];
	}

    for (j = 0; j < n2; j++) {
        R[j] = tab[q + 1+ j];
	}

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {

		if (L[i].start.x <= R[j].start.x) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }

    delete [] L;
    delete [] R;
}

void merge_sort(Odcinek * tab, int p, int r) {

	if (p < r) {

        int q = p + (r - p)/2;
        merge_sort(tab, p, q);
        merge_sort(tab, q+1, r);
        merge(tab, p, q, r);
    }
}

void punkty_przeciec(Odcinek * S, int size) {




}





