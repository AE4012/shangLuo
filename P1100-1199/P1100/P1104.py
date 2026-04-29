

if __name__ == "__main__":
    n = int(input().strip())
    data = []
    for i in range(n):
        # 数据：str, int, int, int
        # 姓名 出生年 出生月 出生日
        name, y, m, d = input().split()
        data.append([name,int(y),int(m),int(d),i])


    # 按出生年、月、日排序
    # 如果有两个同学生日相同，输入靠后的同学先输出

    data.sort(key=lambda x: (x[1],x[2],x[3],-x[4]))

    for name, y, m, d, i in data:
        print(name)