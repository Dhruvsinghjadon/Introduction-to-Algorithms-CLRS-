#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

//k1 < k2 < k3 < k4 < k5
double p[6] = {0, 0.15, 0.1, 0.05, 0.1, 0.2};
double q[6] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};
 
double e[10][10], w[10][10];
int  root[10][10];
 
const int N = 5;
 
void OptimalBST(int n) {
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }//for(r)
        }//for(i)
    }//for(l)
}
 
int main() {
     OptimalBST(N);
     puts("e[i][j] :");
     for (int i = 1; i <= 6; i++) {
        for (int j = 0; j <= 5; j++) {
            if (!e[i][j]) {
                printf("     ");
                continue;
            }
            printf("%.2f ", e[i][j]);
        }puts("");
     }
 
     puts("\nw[i][j]：");
     for (int i = 1; i <= 6; i++) {
        for (int j = 0; j <= 5; j++) {
            if (!w[i][j]) {
                printf("     ");
                continue;
            }
            printf("%.2f ", w[i][j]);
        }puts("");
     }
 
     puts("\nroot[i][j]:");
     for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (!root[i][j]) {
                printf("  ");
                continue;
            }
            printf("%d ", root[i][j]);
        }puts("");
     }
     return 0;
}
