def solution(n, w, num):
    ## index approach
    answer = 0
    box = num
    while(box <= n):
        if box%w == 0:
            r = w
        else:
            r = box%w
        box = box + (w-r)*2 + 1
        answer+=1
        
    
    return answer

