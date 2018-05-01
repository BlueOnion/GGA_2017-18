#include "zadanie2.h"

// program oblicza dwa najblizsze punty na p≥aszczyünie E^2

using namespace std;

int main() {

    Point * tab;
    Point * X;
    Point * Y;
    int size = 10;

    tab = new Point[size];
    X = new Point[size];        // tablica posortowana po wspolrzednej x
    Y = new Point[size];        // tablica posortowana po wspolrzednej y

    generate_points(tab, size);

    mix_tables(tab, X, Y, size);

    merge_sort(X, 0, size-1, 'x');

    merge_sort(Y, 0, size-1, 'y');

    show(X, size);
    cout << endl;
    closest_pair_of_points(size, tab, X, Y);

    //cout << endl;
    //show(Y, size);
    delete [] tab;
    delete [] X;
    delete [] Y;

	return 0;
}
