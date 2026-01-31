# 합승 경로
# 개별 경로 A, B
# 3 <= |n| <= 200
# s,a,b = [1,n]
# fares = [(u, v, fare)]
# 완전 연결 그래프는 아님.

# Floyd Warshall을 통해 N^3 탐색을 하면 해결 !

# Phase 1. Start를 바꾸는 비용 (둘이 함께 움직임)

# Phase 2. S' 에서부터 각자 이동하는 비용. 이때 S'은 움직이지 않는 경우도 포함됨.

# Phase 3. 각 지점에서 출발 했을 때의 비용의 합이 가장 작은 경우
### O(n^3)
import math
def solution(n, s, a, b, fares):
    inf = 10000000000
    answer = inf
    DP =  [[inf for _ in range(n)] for _ in range(n)]
    # 1. Initialize DP table
    for u,v,fare in fares:
        DP[u-1][v-1] = DP[v-1][u-1] = fare if fare != 0 else inf
    # 2. Floyd warshall (DP) iteration
    for k in range(n):
        DP[k][k] = 0
        for i in range(n):
            for j in range(n):
                if(i > j): # for undirected graph
                    DP[i][j] = DP[j][i]
                else:
                    DP[i][j] = min(DP[i][j], DP[i][k]+DP[k][j])
    
    for idx, _s in enumerate(DP[s-1]):
        len = _s + DP[idx][a-1] + DP[idx][b-1]
        if len < answer:
            answer = len
    return answer