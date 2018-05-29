#include "najblizsze_punkty.h"

using namespace std;

void generuj_punkty(Punkt * tab, int size) {

    double MAX = 100;
    double MIN = 0;
    double tmp;

    srand(time(NULL));

    for(int i = 0; i < size; i++) {

        tmp = (double)rand()/ RAND_MAX;
        tab[i].x = MIN + tmp * (MAX - MIN);
        tmp = (double)rand()/ RAND_MAX;
        tab[i].y = MIN + tmp * (MAX - MIN);
    }
}

void show(Punkt tab[], int size) {

    for(int i = 0; i < size; i++) {
        cout << tab[i].x << " : ";
        cout << tab[i].y << endl;
    }
    cout << endl;
}

bool sort_y(Punkt a, Punkt b) {

    return (a.y < b.y);
}

bool sort_x(Punkt a, Punkt b) {

    return (a.x < b.x);
}

Punkt_dist oblicz_odleglosc(Punkt a, Punkt b) {

	Punkt_dist temp;

    temp.x1 = a.x;
    temp.y1 = a.y;

    temp.x2 = b.x;
    temp.y2 = b.y;

    temp.dist = sqrt(pow((temp.x1 - temp.x2), 2) + pow((temp.y1 - temp.y2), 2));

    return temp;
}

Punkt_dist znajdz_odleglosci(Punkt * X, int size) {

	Punkt_dist min;
	Punkt_dist tmp;

	min = oblicz_odleglosc(X[0], X[1]);

	for(int k = 1; k < size; k++ ) {
		for(int l = k+1; l < size; l++) {
		
			tmp = oblicz_odleglosc(X[k], X[l]);
			if(tmp.dist < min.dist)	min = tmp;
		}
	}
	
	tmp = oblicz_odleglosc(X[0], X[size-1]);
	if(tmp.dist < min.dist)		min = tmp;

	return min;
}

Punkt_dist najblizsze_punkty_sigma(vector <Punkt> S, Punkt_dist wynik) {

	Punkt_dist min = wynik;
	int size = S.size();
	Punkt_dist tmp;

	sort(S.begin(), S.end(), sort_y);

	for(int m = 0; m < size; m++) {
		for(int n = m+1; m < size && (S[n].y - S[m].y) < min.dist; n++) {
		
			tmp = oblicz_odleglosc(S[m], S[n]);

			if(tmp.dist < min.dist)		min = tmp;
		}
	}
	
	return min;
}

Punkt_dist para_najblizszych_punkt(Punkt * X, int size) {

	Punkt_dist wynik;
	Punkt_dist wynikL;
	Punkt_dist wynikR;
	int srodek;
	Punkt sr;

	// jesli trzy punkty to obliczamy miêdzy nimi odleglosci
	if(size <= 3) {

		wynik = znajdz_odleglosci(X, size);
		return wynik;
	}

	srodek = size/2;
	sr = X[srodek];

	// obliczamy rekurencyjnie
	wynikL = para_najblizszych_punkt(X, srodek);
	wynikR = para_najblizszych_punkt(X+srodek, size-srodek);

	if(wynikL.dist < wynikR.dist)	wynik = wynikL;
	else 							wynik = wynikR;

	// zaczynamy czesc sprawdzania wokol pola dookola pionowej linii
	vector <Punkt> punkty_sigma;

	for(int i = 0; i < size; i++) {
		
		if(abs(X[i].x - sr.x) < wynik.dist)
			punkty_sigma.push_back(X[i]);
	}

	wynikL = najblizsze_punkty_sigma(punkty_sigma, wynik);

	if(wynikL.dist < wynik.dist)	{

		wynik = wynikL;
		return wynik;
	}
	else return wynik;

}


