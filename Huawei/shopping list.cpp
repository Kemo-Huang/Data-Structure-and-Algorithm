#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    int N, m;
    cin >> N >> m;
    int n = N / 10;
    int dp[3200]{};
    int v[60];
    int p[60];
    int q[60];
    int idx[60];
    int tmp;
    for (int i=1;i<=m;++i){
        cin >> v[i] >> p[i] >> q[i];
        v[i] = v[i] / 10 * p[i];
        idx[i] = n;
    }
    for (int i=1; i<=m; ++i){
        for (int j=v[i]; j<=n; ++j){
            if (q[i] > 0 && idx[q[i]] > j-v[i]) {
                continue;
            }
            tmp = dp[j-v[i]] + v[i];
            // todo
            if (dp[j] < tmp){
                dp[j] = tmp;
                idx[i] = min(idx[i], j);
            }
        }
    }
    cout << dp[n] * 10;
    return 0;
}
