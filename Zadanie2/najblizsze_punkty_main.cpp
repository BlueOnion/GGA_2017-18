#include "najblizsze_punkty.h"

using namespace std;

int main() {

	int size = 10;
	Punkt_dist wynik;
	Punkt * S = new Punkt[size];	

	generuj_punkty(S, size);

	sort(S, S+size, sort_x);
	show(S, size);
	
	wynik = para_najblizszych_punkt(S, size);
	
	cout << wynik.dist << endl;
	cout << wynik.x1 << "  :  " << wynik.y1 << endl;
	cout << wynik.x2 << "  :  " << wynik.y2 << endl;

	return 0;
}
