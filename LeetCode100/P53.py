import sys
List = list

class Solution:
    def maxSubArray(self, nums:List[int]) -> int:
        # 整数数组nums，找出具有最大和的连续子数组，返回最大值
        max_sum = nums[0]
        current_sum = 0
        for x in nums:
            # 如果当前和小于 0，则丢弃之前的，从当前数重新开始
            current_sum = max(x, current_sum + x)
            # 更新全局最大值
            max_sum = max(max_sum, current_sum)
        return max_sum

if __name__ == "__main__":
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    sol = Solution()
    print(sol.maxSubArray(nums))