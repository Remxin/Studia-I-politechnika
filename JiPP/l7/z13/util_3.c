void DodWekt(double *w1, double *w2, double *w3, int n) {
    int k;
    for (k = 0; k < n; k++) {
        w3[k] = w1[k] + w2[k];
    }
}

double IloczynSkal(double *w1, double *w2, int n) {
    int k;
    double s =0;
    for (k = 0; k < n; k++) {
        s += w1[k] * w2[k];
    }
    return s;
}



double MaxElem(double *w, int n) {
    double mx;
    mx = w[0];
    int k;

    for (k = 0; k < n; k++) {
        mx = w[k] > mx ? w[k] : mx;
    }
    return mx;
}