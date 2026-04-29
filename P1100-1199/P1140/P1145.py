import sys

def ok(k, m):
    # 0..k-1 是好人，k..2k-1 是坏人（只要删到 <k 就失败）
    pos = 0
    size = 2 * k
    for dead_bad in range(k):
        pos = (pos + m - 1) % size
        if pos < k:
            return False
        # 删除 pos：相当于把后续索引左移，size-1
        size -= 1
        # 删除的是坏人段里的一个点，且坏人段起点 k 不变在“索引体系”里会改变，
        # 直接用 pos < k 的判定需要配合“好人固定为前 k 个”的索引模型才行；
        # 这也是为何工程上不建议现场算，细节很容易错。
    return True

def solve():
    k = int(sys.stdin.readline().strip())
    m = k + 1
    while True:
        if ok(k, m):
            print(m)
            return
        m += 1

if __name__ == "__main__":
    solve()
