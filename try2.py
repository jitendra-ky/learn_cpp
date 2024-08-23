def findRestaurant(self, list1, list2):
        
        # creating the data-structure
        d = dict() 
        
        len1 = len(list1)
        len2 = len(list2)
        minsum = -1
        luse = max(len1, len2)
        for i in range(luse):
            if i<len1:
                e = list1[i]
                if d.get(e) is None:
                    d[e] = [i, None]
                elif d[e][0] is None:
                    d[e][0] = i
                    s = sum(d[e])
                    if s < minsum or minsum == -1:
                        minsum = s
            if i<len2:
                e = list2[i]
                if d.get(e) is None:
                    d[e] = [None, i]
                elif d[e][1] is None:
                    d[e][1] = i
                    s = sum(d[e])
                    if s < minsum or minsum == -1:
                        minsum = s
        
        # writing the altorithm 
        ans = []
        for k in d:
            dk = d[k]
            if None in dk:
                continue
            s = sum(dk)
            if s == minsum:
                ans.append(k)
        
        if ans:
            return ans
        return -1

l1 = ["Shogun","Tapioca Express","Burger King","box","king","boy","KFC"]
l2 = ["Piatti","box","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]

print(findRestaurant(None, l1, l2))