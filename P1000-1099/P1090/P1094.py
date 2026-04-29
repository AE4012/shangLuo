"""
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品，并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。

你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。
"""

if __name__ == "__main__":
    # 第一行包括一个整数 w，为每组纪念品价格之和的上限。
    w = int(input().strip())
    # 第二行为一个整数 n，表示购来的纪念品的总件数 G。
    n = int(input().strip())
    #第 3∼n+2 行每行包含一个正整数 Pi, 表示所对应纪念品的价格。
    p_list = []
    for _ in range(n):
        p = int(input().strip())
        p_list.append(p)

    # 对 p_list 进行排序
    p_list.sort()

     # 双指针法
    left = 0
    right = n-1
    group_num = 0
    while left < right:
        if p_list[left] + p_list[right] <= w:
            left += 1
            right -= 1
            group_num += 1
        else:
            right -= 1
            group_num += 1
    # 处理剩余的纪念品
    if left == right:
        group_num += 1
    
     # 输出最少的分组数目
    print(group_num)

    