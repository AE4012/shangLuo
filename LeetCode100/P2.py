List = list  

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        str_map = {}
        
        for s in strs:
            key = "".join(sorted(s))
            if key not in str_map:
                str_map[key] = []

            str_map[key].append(s)
            
        return list(str_map.values())

if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    sol = Solution()
    print(sol.groupAnagrams(strs))
