import sys
import time


def get_shortest_path(cur, visited):
    if visited == (1 << n) - 1:
        return w[cur][0]

    if dp[cur][visited] >= 0:
        return dp[cur][visited]

    ret = 9876543210

    for i in range(n):
        if (visited & (1 << i)) != 0:
            continue

        if w[cur][i] == 0:
            continue

        ret = min(ret, w[cur][i] + get_shortest_path(i, visited + (1 << i)))

    dp[cur][visited] = ret
    return ret


for k in range(2, 24):
    f = open("../data/" + str(k) + ".txt","r")
    
    n = int(f.readline())
    w = [[]] * n
    dp = [[-1] * (1 << n) for _ in range(n)]
    for i in range(n):
        w[i] = list(map(int, f.readline().replace("\n", "").split()))
        
    start = time.time()
    print("N = " + str(n) + " :: " + str(get_shortest_path(0, 1)))
    finish = time.time()
    print("Execution Time : " + str(finish-start) + "\n")

