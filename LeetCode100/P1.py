List = list

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            
            hashmap[num] = i
            
        return []
 
if __name__ == "__main__":
    nums = [3,2,4]
    target = 6
    sol = Solution()
    print(sol.twoSum(nums, target))
    