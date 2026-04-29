

if __name__ == "__main__":
    s, x = map(float, input().split())
    position = 0
    now_speed = 7.0


    while position <= (s+x):
        if position >= s-x and position <= s+x:
            position += now_speed*0.98
            if position <= s+x:
                print('y')
                exit(0)
            else:
                break
        position += now_speed
        now_speed *= 0.98

    print('n')