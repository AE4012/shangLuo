    

if __name__ == "__main__":
    N = int(input().strip())
    trees = input().strip()
    ans = []


    def postOrder(s):
        if '0' in s and '1' in s:
            node = 'F'
        elif '0' in s:
            node = 'B'
        else:
            node = 'I'

        if len(s) > 1:
            mid = len(s) // 2
            postOrder(s[:mid])
            postOrder(s[mid:])

        ans.append(node)

    postOrder(trees)
    """中序遍历
    def inOrder(s):
        if len(s) == 1:
            ans.append(s)
            return
        
        mid = len(s) // 2
        inOrder(s[:mid])
        ans.append(s[mid])
        inOrder(s[mid+1:])
    
    inOrder(trees)
    """

    print(''.join(ans))

