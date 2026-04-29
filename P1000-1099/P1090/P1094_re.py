
import sys
if __name__ == "__main__":
    data = sys.stdin.readlines()
    w = int(data[0]) # 为每组纪念品价格之和的上限。
    n = int(data[1]) # 表示购来的纪念品的总件数 G

    value_list = []
    # 将data的其余元素转换为整数并添加到value_list中
    for i in range(2, len(data)):
        value_list.append(int(data[i]))

    value_list.sort()
    # 双指针
    left = 0
    right = n - 1
    count = 0
    while left < right:
        if value_list[left] + value_list[right] <= w:
            count += 1
            left += 1
            right -= 1
        else:
            right -= 1
            count += 1
    if left == right:
        count += 1
    print(count)

