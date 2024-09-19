# cook your dish here
def tc(n, a):
    a.sort()
    s = sum(a)

    ln = None

    for i in range(0,n,2):
        a1 = a[i]
        if i == n-1:
            return s
        a2 = a[i+1]
        if a1 <= 0 and a2 <=0:
            ts = (a1 + a2) * -1
            s += 2*ts
        elif a1 <= 0:
            ln = i
            break
        elif a2 <= 0:
            ln = i+1
            break
    
    if ln == None or ln == (n-1):
        return s

    aln = abs(a[ln])
    aln2 = a[ln+1]
    if aln > aln2:
        s += 2*(aln-aln2)
    
    return s



a = [-9,-6,-5,1,2]
ans = tc(len(a), a)
print(ans)