#include "zadanie4.h"
#include <iostream>


using namespace std;

int main() {

    int size = 5;
    Odcinek * S;
    S = new Odcinek[size];

    tworz_odcinki(S, size);

    merge_sort( S, 0, 4);

    for(int i = 0; i < size; i++) {
        cout << S[i].start.x << "   " << S[i].start.y;
        cout << S[i].stop.x << "   " << S[i].stop.y << endl;
    }



    return 0;
}
