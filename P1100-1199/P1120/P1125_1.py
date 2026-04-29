def is_prime(n: int)->bool:
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

if __name__ == "__main__":
    input_str = input().strip()
    dicts = {}
    for ch in input_str:
        if ch not in dicts:
            dicts[ch] = 1
        else:
            dicts[ch] += 1
    maxn = max(dicts.values())
    minn = min(dicts.values())

    if is_prime(maxn - minn):
        print("Lucky Word")
        print(maxn - minn)
    else:
        print("No Answer")
        print(0)

