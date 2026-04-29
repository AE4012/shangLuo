from typing import List
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        s_len = len(s)
        p_len = len(p)

        if p_len > s_len:
            return []
        
        s_list = [0] * 26
        p_list = [0] * 26

        for i in range(p_len):
            p_list[ord(p[i]) - ord('a')] += 1
            s_list[ord(s[i]) - ord('a')] += 1

        ans =[]
        if p_list == s_list:
            ans.append(0)

        for i in range(s_len-p_len):
            s_list[ord(s[i]) - ord('a')] -= 1
            s_list[ord(s[i+p_len]) - ord('a')] += 1

            if p_list == s_list:
                ans.append(i+1)

        return ans

if __name__ == "__main__":
    s = "cbaebabacd"
    p = "abc"

    sol = Solution()
    print(sol.findAnagrams(s, p))