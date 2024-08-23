
def test_case(n, ar):
    sm = 0
    emx = 0
    omi = float('inf')
    for i in range(1, n+1):
        e = abs(ar[i-1])
        if i%2 != 0:
            sm += e
            omi = min(omi, e)
        else:
            sm -= e
            emx = max(emx, e)
    if emx > omi:
        return sm + 2*(emx - omi)
    return sm

'''
2
10 -10
7
-3 -2 -1 0 1 2 3
'''
tc = [
    (2, [10, -10], 0),
    (7, [-3, -2, -1, 0, 1, 2, 3], 6),
    (2, [-685721634, 6921969], 678799665),
    (2, [-100, 10], 90)
]

for i in tc:
    print(test_case(*i[:-1]), i[-1])


