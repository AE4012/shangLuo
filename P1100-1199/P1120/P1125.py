

def is_prime(n: int)->bool:
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

if __name__ == "__main__":
    # 输入一个单词，只可能出现小写字母，长度小于100
    word = input().strip()


    """
    Lucky Word
    假设 maxn 是单词中出现次数最多的字母的出现次数，minn 是单词中出现次数最少的字母的出现次数，如果 maxn−minn 是一个质数，那么笨小猴就认为这是个 Lucky Word，这样的单词很可能就是正确的答案。
    """
    # 统计每个字母出现的次数
    cnt = [0] * 26
    for c in word:
        cnt[ord(c) - ord('a')] += 1
    maxn = max(cnt)
    # 排除出现次数为0的字母
    cnt = [x for x in cnt if x > 0]
    minn = min(cnt)
    # print(maxn, minn)
    if is_prime(maxn - minn):
        print("Lucky Word")
        print(maxn - minn)
    else:
        print("No Answer")
        print(0)