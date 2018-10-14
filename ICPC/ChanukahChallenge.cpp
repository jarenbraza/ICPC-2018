#include <stdio.h>
using namespace std;

int main() {
    long long P, K, N;
    scanf("%lld", &P);

    while (P--) {
        scanf("%lld %lld", &K, &N);
        printf("%lld %lld\n", K, N + (N * (N + 1) / 2));
    }

    return 0;
}
