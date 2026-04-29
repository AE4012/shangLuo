
List = list

class Solution:
    def firstMissingPositive(self, nums:List[int]) -> int:
        # 给你一个未排序的整数数组 nums，找出其中没有出现的最小的正整数
        n = len(nums)

        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] -1] != nums[i]:
                t = nums[i] -1 
                nums[i], nums[t] = nums[t], nums[i]
                # print(nums)

        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        

if __name__ == "__main__":   
    nums = [3,4,-1,1]
    sol = Solution()
    print(sol.firstMissingPositive(nums))