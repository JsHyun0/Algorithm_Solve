#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<int> s;

// 재귀-dfs로 풀어내면 함수의 stack 호출 순서를 이용해서 사전 순으로 출력할 수 있다다
void dfs(int idx, vector<int>& result) {
    // leaf node
    if(result.size() == 6){
        for(const auto& i : result)
            cout << i << " ";
        cout << "\n";
        return;
    }
    if(idx == k)
        return;
    
    result.push_back(s[idx]);
    dfs(idx + 1, result);
    result.pop_back();  // 백트래킹
    dfs(idx + 1, result);
}

int main() {
    
    while(true) {
        cin >> k;
        if(k == 0)
            break;
            
        s.clear();  // 벡터 초기화
        s.reserve(k);  // 메모리 미리 할당
        
        for(int i = 0; i < k; i++) {
            int tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        
        vector<int> result;
        result.reserve(6);  // 결과 벡터 메모리 미리 할당
        dfs(0, result);
        cout << "\n";
    }
    
    return 0;
}