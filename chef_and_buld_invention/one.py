


def with_reminder_r(N, k, r) :
    n = N-1
    ans = n//k
    if n%k >= r :
        ans += 1;
    return ans


def with_max_rem_m(N, k, p):
    n = N-1
    m = p%k -1# maximum reminder
    l = n%k # last number reminder

    ans = 1
    ans += (m+1)* (n//k)
    ans += min(l,m)

    ans += with_reminder_r(p+1, k, p%k)

    return ans

N, k, r = 11, 4, 1
print(with_reminder_r(N, k, r))

N , k, p = 13, 4, 7
print(with_max_rem_m(N, k, p))