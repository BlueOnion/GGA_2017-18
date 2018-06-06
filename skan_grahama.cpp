
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

struct Punkt {

    double x;
    double y;
};

void generuj_punkty(Punkt * tab, int size) {

    double MAX = 100;
    double MIN = 0;
    double tmp;

/*    srand(time(NULL));

    for(int i = 0; i < size; i++) {

        tmp = (double)rand()/ RAND_MAX;
        tab[i].x = MIN + tmp * (MAX - MIN);
        tmp = (double)rand()/ RAND_MAX;
        tab[i].y = MIN + tmp * (MAX - MIN);
    } */

	tab[0].x = 5;
	tab[0].y = 5;
	tab[1].x = 0;
	tab[1].y = 0;
	tab[2].x = 10;
	tab[2].y = 0;
	tab[3].x = 15;
	tab[3].y = 5;
	tab[4].x = 17;
	tab[4].y = -3;
	tab[5].x = 10;
	tab[5].y = 5;
	tab[6].x = 8;
	tab[6].y = 8;
	tab[7].x = 5;
	tab[7].y = -5;
}

void show(Punkt tab[], int size) {

    for(int i = 0; i < size; i++) {
        cout << tab[i].x << " : ";
        cout << tab[i].y << endl;
    }
    cout << endl;
}

bool sort_x(Punkt a, Punkt b) {

    return (a.x < b.x);
}

vector <Punkt> otoczka_wypukla(Punkt * S, int size) {

	vector <Punkt> otoczka_wypukla;
	vector <Punkt> status_miotly;
	double miotla;
	double y_max, y_min;
	
	sort(S, S+size, sort_x);
	show(S, size);

	otoczka_wypukla.push_back(S[0]);
	y_max = S[0].y;
	y_min = S[0].y;

	for(int i = 1; i < size; i++) {
	
		if(S[i].y > y_max)		otoczka_wypukla.push_back(S[i]);
		if(S[i].y < y_min)		otoczka_wypukla.push_back(S[i]);

		otoczka_wypukla.push_back(S[size-1]);
		y_max = S[size-1].y;
		y_min = S[size-1].y;	
	}

	for(int j = size-1; j > 0; j--) {

		if(S[j].y > y_max)		otoczka_wypukla.push_back(S[j]);
		if(S[j].y < y_min)		otoczka_wypukla.push_back(S[j]);
	}

	return otoczka_wypukla;
}

int main() {

	int size = 8;
	Punkt * S = new Punkt[size];	
	vector <Punkt> otoczka_wyp;

	generuj_punkty(S, size);

	otoczka_wyp = otoczka_wypukla(S, size);

    for(int i = 0; i < size; i++) {
        cout << S[i].x << " : ";
        cout << S[i].y << endl;
    }

	return 0;
}
