def solution(name, yearning, photo):
    answer = []
    scores = {}
    for i in zip(name, yearning):
        scores[i[0]]=i[1]
    for x in photo:
        s = 0
        for people in x:
            if people in scores:
                s += scores[people]
        answer.append(s)
    return answer