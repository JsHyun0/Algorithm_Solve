def main(n):
    first = n
    c = 1
    while(True):
        left = n // 10
        right = n % 10
        new = right * 10 + (left + right) % 10
        if new == first:
            break
        else:
            c += 1
            n = new
    result = c

    return result

if __name__ == '__main__':
    N = int(input())
    result = main(N)
    print(result)