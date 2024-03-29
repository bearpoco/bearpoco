#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
    }
    vector<int> dp;
    // dp[i] - minimum cost to reach stone 'i'
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j : {i + 1, i + 2}) {
            if(j < n) {
                dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
            }
        }
    }
    printf("%d\n", dp[n-1]);
}
