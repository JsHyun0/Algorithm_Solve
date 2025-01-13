#include <iostream>
#include <algorithm>

using namespace std;
bool compare_x(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second <= b.second;
    return a.first < b.first;
}

bool compare_y(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first <= b.first;
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> arr;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }
    int result = 0;
    // 정렬해서 x좌표 같은 점에서 가까운 쌍의 수직 거리 합계
    sort(arr.begin(), arr.end(), compare_x);
    for(auto iter = arr.begin(); iter < (arr.end()-1); iter++) {
        if((iter+1)->first == iter->first) {
            result += (iter+1)->second - iter->second;
            iter++;
        }
        else
            continue;
    }
    // 정렬해서 y좌표 같은 점에서 가까운 쌍의 수평 거리 합계
    sort(arr.begin(), arr.end(), compare_y);
    for(auto iter = arr.begin(); iter < (arr.end()-1); iter++) {
        if((iter+1)->second == iter->second) {
            result += (iter+1)->first - iter->first;
            iter++;
        }
        else
            continue;
    }
    cout << result;

    return 0;
}