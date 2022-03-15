
int x[2][3];

int func() {
    int y[2][3];
    int i, j;

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 3; ++j) {
            y[i][j] = i + j;
            x[i][j] = i - j;
        }
    }

    return y[1][1] - x[1][1];
}