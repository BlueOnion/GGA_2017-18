#include "zadanie2.h"

using namespace std;

void generate_points(Point * tab, int size) {

    double MAX = 100;
    double MIN = 0;
    double tmp;

    srand(time(NULL));

    for(int i = 0; i < size; i++) {

        tmp = (double)rand()/ RAND_MAX;
        tab[i].x = MIN + tmp * (MAX - MIN);
        //cout << tab[i].x << " : ";
        tmp = (double)rand()/ RAND_MAX;
        tab[i].y = MIN + tmp * (MAX - MIN);
        //cout << tab[i].y << endl;
    }
}

void show(Point tab[], int size) {

    for(int i = 0; i < size; i++) {
        cout << tab[i].x << " : ";
        cout << tab[i].y << endl;
    }
}

void mix_tables(Point * tab, Point * X, Point * Y, int size) {

    for(int i = 0; i < size; i++) {
        X[i].x = tab[i].x;
        X[i].y = tab[i].y;
        Y[i].x = tab[i].x;
        Y[i].y = tab[i].y;
    }
}

void merge_x(Point * tab, int p, int q, int r) {

    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;

    Point * L = new Point[n1];
    Point * R = new Point[n2];

    for (i = 0; i < n1; i++) {
        L[i].x = tab[p + i].x;
        L[i].y = tab[p + i].y;
	}

    for (j = 0; j < n2; j++) {
        R[j].x = tab[q + 1+ j].x;
        R[j].y = tab[q + 1+ j].y;
	}

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {

		if (L[i].x <= R[j].x) {
            tab[k].x = L[i].x;
			tab[k].y = L[i].y;
            i++;
        }
        else {
            tab[k].x = R[j].x;
			tab[k].y = R[j].y;
            j++;
        }
        k++;
    }

    while (i < n1) {
        tab[k].x = L[i].x;
		tab[k].y = L[i].y;
        i++;
        k++;
    }

    while (j < n2) {
        tab[k].x = R[j].x;
		tab[k].y = R[j].y;
        j++;
        k++;
    }

    delete [] L;
    delete [] R;
}

void merge_y(Point * tab, int p, int q, int r) {

    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;

    Point * L = new Point[n1];
    Point * R = new Point[n2];

    for (i = 0; i < n1; i++) {
        L[i].x = tab[p + i].x;
        L[i].y = tab[p + i].y;
	}

    for (j = 0; j < n2; j++) {
        R[j].x = tab[q + 1+ j].x;
        R[j].y = tab[q + 1+ j].y;
	}

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {

		if (L[i].y <= R[j].y) {
            tab[k].x = L[i].x;
			tab[k].y = L[i].y;
            i++;
        }
        else {
            tab[k].x = R[j].x;
			tab[k].y = R[j].y;
            j++;
        }
        k++;
    }

    while (i < n1) {
        tab[k].x = L[i].x;
		tab[k].y = L[i].y;
        i++;
        k++;
    }

    while (j < n2) {
        tab[k].x = R[j].x;
		tab[k].y = R[j].y;
        j++;
        k++;
    }

    delete [] L;
    delete [] R;
}

void merge_sort(Point * tab, int p, int r, char xy) {

	if (p < r) {

        int q = p + (r - p)/2;

        if(xy == 'x') {
            merge_sort(tab, p, q, xy);
            merge_sort(tab, q+1, r, xy);
            merge_x(tab, p, q, r);
        }
        else if(xy == 'y') {
            merge_sort(tab, p, q, xy);
            merge_sort(tab, q+1, r, xy);
            merge_y(tab, p, q, r);
        }
    }
}

Point_dist calc_distance(Point a, Point b) {

    Point_dist temp;

    temp.x1 = a.x;
    temp.y1 = a.y;

    temp.x2 = b.x;
    temp.y2 = b.y;

    temp.dist = sqrt(pow((temp.x1 - temp.x2), 2) + pow((temp.y1 - temp.y2), 2));

    return temp;
}

double find_l(int size, Point * X) {

    double l;
    int tmp = size/2;

    l = round((X[tmp-1].x + X[tmp].x)/2);
    return l;
}

void closest_pair_of_points(int size, Point * tab, Point * X, Point * Y) {

    Point_dist result;
    Point_dist resultL;
    Point_dist resultR;
    Point * XL;
    Point * XR;
    Point * YL;
    Point * YR;
	double l, d;
	int m = 0;

	if(size == 2) {

		result = calc_distance(tab[0], tab[1]);
	}

    XL = new Point[size/2];
    XR = new Point[size/2];
    YL = new Point[size - (size/2)];
    YR = new Point[size - (size/2)];

    l = find_l(size, X);

    while(m < size/2) {

        XL[m].x = X[m].x;
        XL[m].y = X[m].y;
        m++;
    }

    show(XL, size/2);
    cout << endl;

    while(m+1 < size) {

        XR[m].x = X[m].x;
        XR[m].y = X[m].y;
        m++;
    }

    show(XR, size - size/2);

    // recursion
    //resultL = closest_pair_of_points(tabx, p, q, taby);
    //resultR = closest_pair_of_points(tabx, q+1, r, taby);


}




