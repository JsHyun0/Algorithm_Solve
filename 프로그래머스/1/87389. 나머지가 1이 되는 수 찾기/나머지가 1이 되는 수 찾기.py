def solution(n):
    answer = 0
    n = n-1
    for i in range(2,10000001):
        if(n%i == 0):
            answer = i
            break
    return answer