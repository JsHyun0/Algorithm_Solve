#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100000

vector<vector<int>> graph(MAX+1);
vector<int> parents(MAX+1, 0);

void dfs(int N, int node) {
    for(int next : graph[node]) {
        // 나와 연결된 노드 중 부모가 배정되지 않은 노드를 내 자식으로 지정
        if(parents[next] == 0) {
            parents[next] = node;
            // DFS로 leaf node까지 내려간다.
            dfs(N, next);
        }
    }
}
// node N, edge N-1
int main() {
    parents[1] = 1;
    int N;
    cin >> N;

    int a, b;
    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        // 공간 효율을 위해 각 노드별로 가변 길이의 리스트를 가진다.
        // N * N 배열을 사용할 경우 메모리 초과함
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(N, 1);

    for(int i = 2; i <= N; i++) {
        cout << parents[i] << '\n';
    }

    return 0;
}