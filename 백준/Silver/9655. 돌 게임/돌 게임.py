def solve(N):
    result = ''
    if(N%2) == 0:
        result = 'CY'
    else:
        result = 'SK'
    return result

if __name__ == '__main__':
    N = int(input())
    result = solve(N)
    print(result)