if __name__ == '__main__':
    x = int(input())
    St = input().strip()
    
    # 0-9 对应的索引就是 0-9，A 的索引是 10，Z 的索引是 35
    num_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    res = 0
    for i in St:
        # num_str.index(i) 可以直接找出字符 i 对应的十进制大小
        res = res * x + num_str.index(i)
        
    print(res)