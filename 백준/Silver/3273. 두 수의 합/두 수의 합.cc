#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
// 시간 초과
int main() {
    int N, x, result = 0;
    cin >> N;
    vector<int> ary(N, 0);
    set<int> s;
    for(int i = 0; i < N; i++) {
        cin >> ary[i];
        s.insert(ary[i]);
    }
    cin >> x;

    for(int i = 0; i < N; i++) {
        if(s.find(x-ary[i]) != s.end()) {
            result++;
        }

    }
    
    
    cout << result/2;
    
    return 0;
}