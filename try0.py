def tc(n, a):
    mins = -1
    maxp = -1
    one, two, three = 0, 0, 0
    for j in range(n):
        i = a[j]
        if i == 1:
            one += 1
        elif i == 2:
            two += 1
        elif i == 3:
            three += 1
        if one and two and three:
            mins = j
            break
    one, two, three = 0, 0, 0
    for j in range(n - 1, -1, -1):
        i = a[j]
        if i == 1:
            one += 1
        elif i == 2:
            two += 1
        elif i == 3:
            three += 1
        if one and two and three:
            maxp = j
            break