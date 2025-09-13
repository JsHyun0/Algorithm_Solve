def check(wallet, bill):
    wallet_w, wallet_h = wallet
    bill_w, bill_h = bill
    print(wallet, bill)
    if(wallet_w >= bill_w and wallet_h >= bill_h):
        return True
    if(wallet_h >= bill_w and wallet_w >= bill_h):
        return True
    
    return False

def solution(wallet, bill):
    answer = 0
    while(True):
        if check(wallet, bill):
            break
        answer += 1
        #반으로 접기
        if(bill[0] > bill[1]):
            bill[0] = bill[0] // 2
        else:
            bill[1] = bill[1] // 2
    return answer