
class Solution(object):
        

    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        def isSame(op, cp):
            if op == '(' and cp == ')':
                return True
            elif op == '[' and cp == ']':
                return True
            elif op == '{' and cp == '}':
                return True
            return False
    
        cur_longest = 0
        stk = []
        is_bal = True
        l = 0
        for c in s:
            l += 1
            if c in '([{':
                stk.append(c)
            else:
                if not stk:
                    is_bal = False
                else:
                    last_paren = stk.pop()
                    if not isSame(last_paren, c):
                        is_bal = False
        
            if len(stk) == 0 and is_bal:
                cur_longest = max(l, cur_longest)

            if not is_bal:
                l = 0
                stk.clear()
                is_bal = True
        
        return cur_longest

        
        

s = Solution()

print(s.longestValidParentheses("()(()"))
        