# include <stdio.h>

int* sm(int* a, int* b, int* ans);

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {5, 4, 3, 2, 1};
    int ans[5] = {0, 0, 0, 0, 0};
    int* val = sm(a, b, ans);
    (ans == val) ? printf("equal") : printf("not equal");
}

int* sm(int* a, int* b, int* ans) {
    for (int i; i < 5; i++) {
        ans[i] = a[i] + b[i];
    }
    return ans;
}