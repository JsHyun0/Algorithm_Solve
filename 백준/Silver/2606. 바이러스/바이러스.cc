#include <iostream>
using namespace std;
int mtx[100][100] = {0, }; //그래프의 인접행렬
int com[100];
void solve(int x);
int N, line;
int result = 0;
int main() {
	cin >> N;
	cin >> line;
	for(int i = 0; i < line; i++) {// 값을 입력 받으며 인접행렬에 저장
		int a, b;
		cin >> a;
		cin >> b;
		//cout << "we get " << a << " and " << b << endl;
		mtx[a-1][b-1] = 1;
		mtx[b-1][a-1] = 1;
	}
	com[0] = 1; //중요 !! 1번 자신을 재감염 시키는 일이 생기므로 1번은 이미 방문 처리하여야 함.
	solve(0);

	cout << result << endl;
	return 0;
}

void solve(int x) {
	for(int i = 0; i < N; i++) {
		if(com[i] == 0 && mtx[x][i] == 1) { //방문한적이 없고, 인접한 노드라면
			com[i] = 1; //방문을 확인하고
			solve(i); //그 노드와 인접한 노드를 확인한다
			result++; //그리고 현재노드는 감염을 확인한다.
		}
	}
}