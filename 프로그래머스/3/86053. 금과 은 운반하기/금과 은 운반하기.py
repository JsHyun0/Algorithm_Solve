# Binary Search
def solution(a, b, g, s, w, t):
    answer = -1
    start = 0
    end = answer = 2 * 2 * 1e9 * 1e5
    
    
    while start <= end:
        mid = (start + end) // 2
        # check
        gold = 0
        silver = 0
        total = 0 # 왜필요한거지
        for i, (_g, _s, _w, _t) in enumerate(zip(g,s,w,t)):
            #현재 시간 내에서 트럭의 가능한 이동횟수 계산
            move = 1
            move += (mid-_t) // (2*_t)
    
            capability = move * _w
            i_gold = min(capability, _g)
            i_silver = min(capability, _s)
            total += min(capability, _g+_s) # 실제로 물리적으로 다 보냈는가?
            gold += i_gold
            silver += i_silver

        if (total >= a + b and gold >= a and silver >= b):
            #더 작은 값이 있는지 찾기
            answer = min(answer, mid)
            end = mid-1
        else:
            start = mid+1
        
    return answer