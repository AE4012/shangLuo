List = list
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k == 0:
            return []
        
        res = []
        # dq 存储的是下标
        dq = deque()
        
        for i in range(len(nums)):
            # 1. 保持队列单调递减
            # 如果当前元素大于队尾元素，队尾元素就不可能成为最大值了
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()
            
            dq.append(i)
            
            # 2. 检查队首元素是否超出窗口范围
            if dq[0] <= i - k:
                dq.popleft()
            
            # 3. 当窗口形成（长度达到 k）时，记录队首作为最大值
            if i >= k - 1:
                res.append(nums[dq[0]])
                
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))
