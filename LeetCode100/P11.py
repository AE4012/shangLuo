from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        res = 0
        i, j = 0, len(height) - 1
        while i < j:
            # 计算当前面积
            current_height = min(height[i], height[j])
            current_area = (j - i) * current_height
            
            # 更新最大值
            res = max(res, current_area)
            
            # 移动较短的指针
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1

        return res

if __name__ == "__main__":
    s = Solution()
    print(s.maxArea([1,8,6,2,5,4,8,3,7]))