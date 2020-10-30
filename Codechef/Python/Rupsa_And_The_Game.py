testcases = int(input())
for i in range(testcases):
    N = int(input())
    array = list(map(int, input().split()))
    res = 0
    m = 1
    a = array[0]
    for i in range(1, len(array)):
        res = (2*res + 2*a*array[i]) % 1000000007
        a = (a + m*array[i]) % 1000000007
        m = (2*m) % 1000000007
    print(res)