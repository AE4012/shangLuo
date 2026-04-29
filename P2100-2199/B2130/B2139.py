import math
def is_prime(n: int)->bool:
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

if __name__ == "__main__":
    ans = []
    M, N = map(int, input().strip().split())
    for i in range(M, N + 1):
        if is_prime(i) and is_prime(int(str(i)[::-1])):
            ans.append(i)
    
    if ans == []:
        print("No")
    else:
        print(",".join(map(str, ans)))
