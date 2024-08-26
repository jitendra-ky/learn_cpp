def tc(N):
    if N < 3:
        return 1
    t = N - 2
    s = t*(t+1) + 1
    return s


print(tc(5))