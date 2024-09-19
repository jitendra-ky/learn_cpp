# cook your dish here
def tc(n, m, a):
    a.sort(reverse=True)
    chain_peek = 0
    total_weight = a[0]
    cut = 0
    while total_weight != n:
        if a[-1] != 0:
            a[-1] -= 1
            total_weight += a[chain_peek + 1] + 1
            chain_peek += 1
            cut += 1
        else:
            a.pop()
    return cut

def main():
    n, m = 10, 4
    a = [4, 3, 2, 1]
    ans = tc(n, m, a)
    print(ans)
    
main()
