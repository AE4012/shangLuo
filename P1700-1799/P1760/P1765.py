
if __name__ == '__main__':
    mobile = {'a':1, 'b':2, 'c':3, 'd':1, 'e':2, 'f':3, 'g':1, 'h':2, 'i':3, 'j':1, 'k':2, 'l':3, 'm':1, 'n':2, 'o':3, 'p':1, 'q':2, 'r':3, 's':4, 't':1, 'u':2, 'v':3, 'w':1, 'x':2, 'y':3, 'z':4, ' ':1}
    data = input()
    cnt = 0

    # 统计data的字符对应的mobile上的数字
    for c in data:
        cnt += mobile[c]

    print(cnt)