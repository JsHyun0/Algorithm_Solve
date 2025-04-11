def isLate(a, b):
    
    
    a_hour = a//100
    b_hour = b//100
    a_min = a%100
    b_min = b%100
    a_time = a_hour*60 + a_min
    b_time = b_hour*60 + b_min
    if(a_time - b_time > 10):
        return 1
    else:
        return 0
        
            

    
def solution(schedules, timelogs, startday):
    answer = 0
    n = len(schedules)
    attendance = [0 for _ in range(n)]
    # 1 2 3 4 5 6 7
    # 0 1 2 3 4 5 6
    # 7 - startday
    # 6 - startday
    for idx in range(7):
        day = (startday+idx) % 7
        if(day == 6 or day == 0):
            continue
        for j in range(n):
            if(isLate(timelogs[j][idx],schedules[j])):
                attendance[j] = 1
    for i in attendance:
        if(i == 0):
            answer += 1
    return answer
