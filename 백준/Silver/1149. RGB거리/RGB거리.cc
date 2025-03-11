#include <iostream>
#include <algorithm>

using namespace std;
//R: 0, G: 1, B: 2
int N;
int DP[1000][3];
int min(int a, int b) {
    if (a < b)
        return a;
    else return b;
}
int main() {
    cin >> N;
    vector< vector<int> > cost(N, vector<int>(3,0));
    for(int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    DP[0][0] = cost[0][0];
    DP[0][1] = cost[0][1];
    DP[0][2] = cost[0][2];

    for(int i = 1; i < N; i++) {
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + cost[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + cost[i][1];
        DP[i][2] = min(DP[i-1][1], DP[i-1][0]) + cost[i][2];
    }

    int result = DP[N-1][0];
    for(int i = 1; i < 3; i++) {
        if(result > DP[N-1][i])
            result = DP[N-1][i];
    }

    cout << result;
}