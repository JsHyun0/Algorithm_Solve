#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define line pair<int, int>
// LIS 문제래요
// 줄이 교차하고 있을 때, 한쪽을 기준으로 정렬한다면, A (index 열)이 증가함에 따라 B 쪽도 증가해야 교차하지 않음
// 가장 길게 증가하는 부분의 길이가 최대로 제거하지 않고 가져갈 수 있는..건 아닌거같은데

int compare(line &x, line &y) {
    return x.first < y.first;
}

int main() {
    int N;
    cin >> N;
    vector< line > lines;
    for(int i=0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back(make_pair(a,b));
    }
    sort(lines.begin(), lines.end(), compare);
    int tmp = -1;
    vector<int> DP(N,1);

// O(N^2)
// 이전 칸보다 증가하는지만 비교할 것이 아니고, 어디부터 증가하는지를 확인해야 함 
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(lines[i].second > lines[j].second) // 이전 칸 j보다 클 때, DP값을 비교하여 큰 값으로 갱신한다.
                DP[i] = max(DP[i], DP[j]+1);
                
        }
    }

    cout << N - *max_element(DP.begin(), DP.end());
    return 0;
}