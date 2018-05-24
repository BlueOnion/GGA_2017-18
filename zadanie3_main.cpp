#include "zadanie3.h"

using namespace std;

int main() {

    Point * tab;
    Node * root = NULL;
    int size = 10;

    tab = new Point[size];

    generate_points(tab, size);

    //show(tab, size);



    //show_tree(root);
    cout << 5/2 << endl;
    delete [] tab;

    return 0;
}
