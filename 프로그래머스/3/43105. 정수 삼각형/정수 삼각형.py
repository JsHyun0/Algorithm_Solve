# DP
# [0+0, [1+0, 1+1], ]
# i = l + j in range(l+1)
def solution(triangle):
    Level = len(triangle)
    N = Level * (Level+1) // 2
    DP = [0 for _ in range(N)]
    DP[0] = triangle[0][0]
    for l in range(Level):
        if l == 0 : continue
        for j in range(l+1):
            i = l*(l+1)//2 + j
            DP[i] = triangle[l][j]
            if j == 0:
                DP[i] += DP[i-l] 
            elif j == l:
                DP[i] += DP[i-l-1] 
            else:
                DP[i] += max(DP[i-l], DP[i-l-1])
    answer = max(DP)
    return answer