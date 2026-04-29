from collections import Counter
class Solution:
    def minWindow(self, s:str, t:str) -> str:
        if not s or not t:
            return ""
        
        # target 记录 t 中各字符出现的次数
        # window 记录当前窗口中各字符出现的次数
        target = Counter(t)
        window = {}
        
        left, right = 0, 0
        # valid 记录窗口中已经满足 target 条件的字符个数
        valid = 0
        
        # 记录最小覆盖子串的起始位置及长度
        start, min_len = 0, float('inf')

        while right < len(s):
            char = s[right]
            right += 1

            if char in target:
                window[char] = window.get(char, 0) + 1
                if window[char] == target[char]:
                    valid += 1  # 某个字符数量够了

            while valid == len(target):
                if right - left < min_len:
                    start = left
                    min_len = right - left

                d = s[left]
                left += 1
                if d in target:
                    if window[d] == target[d]:
                        valid -= 1  # 某个字符数量不够了
                    window[d] -= 1
            
        return "" if min_len == float('inf') else s[start:start + min_len]

if __name__ == "__main__":
    s = "ADOBECODEBANC" 
    t = "ABC"

    sol = Solution()
    print(sol.minWindow(s, t))

