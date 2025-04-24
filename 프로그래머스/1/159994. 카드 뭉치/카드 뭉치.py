
    
def solution(cards1, cards2, goal):
    top_1 = 0
    top_2 = 0
    for word in goal:
        if(top_1 < len(cards1) and cards1[top_1] == word):
            top_1 += 1
        elif(top_2 < len(cards2) and cards2[top_2] == word):
            top_2 += 1
        else:
            return "No"
        
    
    return "Yes"