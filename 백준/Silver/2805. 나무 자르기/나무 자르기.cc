#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    long long M, N, H;
    cin >> N >> M;
    vector<int> trees(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    long long start = 0;
    long long end = *(trees.end() - 1);
    long long result = -1; // height가 0일수 있음

    while(start <= end) {
        long long sum = 0;
        long long mid = (start + end) / 2;

        // 나무 길이 계산
        for(int i = 0; i < N; i++){
            if(trees[i] - mid > 0)
                sum += (trees[i] - mid);
        }
        if(sum >= M) {
            // M 이상을 만족하는 경우, H의 최대값을 찾기 위해 더 큰 범위에서 탐색
            start = mid + 1;
            if(mid > result) {
                result = mid;
            }
        }
        else // M값을 만족하는 높이를 찾기 위해 더 많이 자르는 범위를 탐색
            end = mid - 1;
    }

    cout << result << endl;


    return 0;
}