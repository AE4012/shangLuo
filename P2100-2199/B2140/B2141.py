
def check_jinzhi(p, q, r, base):
    try:
        p_new = int(p, base)
        q_new = int(q, base)
        r_new = int(r, base)
        if p_new * q_new == r_new:
            return True
        else:
            return False
    except ValueError:
        return False

if __name__ == "__main__":
    p, q, r = map(str, input().strip().split())
    for i in range(2, 17):
        if check_jinzhi(p, q, r, i):
            print(i)
            break
    else:
        print(0)
            