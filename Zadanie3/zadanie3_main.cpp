#include "zadanie3.h"

using namespace std;

int main() {

    Point * tab;
    Node * root = NULL;
    int size = 10;

    tab = new Point[size];

    generate_points(tab, size);

    show(tab, size);

    for(int j = 0; j < size; j++) {

        root = build_kd_tree(root, tab[j]);
    }

    show_tree(root);

    delete [] tab;

    return 0;
}
