def solution(number, limit, power):
    answer = 0
    arr = [0 for _ in range(number)]
    for i in range(number):
        num = i+1
        # 약수의 개수 구하기
        for j in range(number//num):
            arr[(j+1)*num - 1] += 1
    for atk in arr:
        if(atk > limit):
            answer += power
        else:
            answer += atk
    return answer