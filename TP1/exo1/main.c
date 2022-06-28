#include <stdio.h>

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d", &(*pa));
    scanf("%d", &(*pb));
    printf("%d + %d = %d\n", a, b, a+b);

    return 0;
}