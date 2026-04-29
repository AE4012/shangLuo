import math

def cal_prime(n: int)->list:
    if n < 2:
        return []
    for i in range(2, int(math.sqrt(n))):
        if n % i == 0:
            return [i, n//i]
    return []

if __name__ == "__main__":
    n = int(input().strip())

    # 求小的质数
    print(max(cal_prime(n)))