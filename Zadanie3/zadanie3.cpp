#include "zadanie3.h"

using namespace std;

void generate_points(Point * tab, int size) {

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

void show(Point tab[], int size) {

    for(int i = 0; i < size; i++) {
        cout << tab[i].x << " : ";
        cout << tab[i].y << endl;
    }
    cout << endl;
}

Node * new_node(Point arr) {

    Node * temp = new Node;

    temp->p = arr;

    temp->left = temp->right = NULL;

    return temp;
}

Node * insert_kd_tree(Node *r, Point p, int d) {

    if(r == NULL) return new_node(p);

    int c = d % 2;      // porównujemy albo po wspó³rzêdnej x(0) albo y(1)

    if(c == 0) {
        if(p.x < (r->p.x)) {
            r->left  = insert_kd_tree(r->left, p, d + 1);
        }
        else {
            r->right = insert_kd_tree(r->right, p, d + 1);
        }
    }
    else if(c == 1) {
        if(p.y < (r->p.y)) {
            r->left  = insert_kd_tree(r->left, p, d + 1);
        }
        else {
            r->right = insert_kd_tree(r->right, p, d + 1);
        }
    }

    return r;
}

Node * build_kd_tree(Node *r, Point p) {

    return insert_kd_tree(r, p, 0);
}

void show_node(Node * n) {

    cout << n->p.x << "  :  " << n->p.y << endl;

    if(n->left == NULL && n->right == NULL) {

    } else if(n->left == NULL && !(n->right == NULL)) {
    cout << "right" << endl;
        show_node(n->right);
    } else if(!(n->left == NULL) && n->right == NULL) {
    cout << "left" << endl;
        show_node(n->left);
    } else {
    cout << "right" << endl;
        show_node(n->right);
    cout << "left" << endl;
        show_node(n->left);
    }
}

void show_tree(Node * t) {

    cout << t->p.x << "  :  " << t->p.y << endl;

    cout << "main left" << endl;
    show_node(t->left);
    cout << "main right" << endl;
    show_node(t->right);

}
