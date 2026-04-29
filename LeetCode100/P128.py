class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if not nums:
            return 0
        nums = set(nums)
        max_len = 0

        for num in nums:
            if num - 1 not in nums:
                cur_num = num
                cur_len = 1
                while cur_num + 1 in nums:
                    cur_num += 1
                    cur_len += 1
                max_len = max(max_len, cur_len)
        return max_len


if __name__ == "__main__":
    nums = [100, 4, 200, 1, 3, 2]
    print(Solution().longestConsecutive(nums))