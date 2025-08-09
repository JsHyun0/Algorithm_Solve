from collections import defaultdict

class User:
    def __init__(self, name):
        self.name = name
        self.reported = 0
        self.reported_name = set()
        self.response = 0
        
def solution(id_list, report, k):
    answer = []
    user_list = {}
    for name in id_list:
        user_list[name] = (User(name))
    for x in report:
        # A -> B
        A, B = x.split(' ')
        #user_list[B].reported += 1
        user_list[B].reported_name.add(A)
    
    for user in user_list.values():
        if (len(user.reported_name) >= k):
            for name in user.reported_name:
                user_list[name].response += 1
    for user in user_list.values():
        answer.append(user.response)
    return answer