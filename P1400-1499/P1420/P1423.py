

if __name__ == "__main__":
    s = float(input().strip())
    now = 2.0
    origin = 2.0
    step = 1
    while(True):
        if now > s:
            print(step)
            break
        else:
            origin *= 0.98
            now += origin
            step += 1

        