
def solution(info, n, m):
    ## 1. A가 남기는 누적 개수의 최솟값
    ## 2. 두 팀 모두 경찰에 들키면 안됨.
    ## 3. 만약 해가 존재하지 않는다면 -1
    
    ## DP는 점화식이 필요하다
    ## 
    max = 999
    L = len(info)
    DP = [[max for _ in range(m)] for row in range(L)]
    ## 첫행 초기화
    DP[0][0] = info[0][0]
    if info[0][1] < m:
        DP[0][info[0][1]] = 0
        
    for idx, (x, y) in enumerate(info):
        if(idx == 0): ##최초 초기화가 필요함
            continue
        for j in range(m):
            try:
                DP[idx][j] = min([DP[idx-1][j] + x, DP[idx][j]]) #select A
                if(y + j < m):
                    DP[idx][j + y] = min([DP[idx-1][j], DP[idx][j+y]])
            except IndexError:
                print(f"idx: {idx}, j: {j}")
                
        
    #만약 마지막 행의 최솟값이 N보다 크다면, 조건을 만족할 수 없으므로 -1 리턴
    result = min(DP[L-1])
    answer = result if result < n else -1
        
    return answer