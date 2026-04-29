"""
P1500-1599.P1590.P1597 的 Docstring
# P1597 语句解析

## 题目背景

木有背景……

## 题目描述

一串长度不超过 $255$ 的 PASCAL 语言代码，只有 $a,b,c$ 三个变量，而且只有赋值语句，赋值只能是一个一位的数字或一个变量，每条赋值语句的格式是 `[变量]:=[变量或一位整数];`。未赋值的变量值为 $0$ 输出 $a,b,c$ 的值。

## 输入格式

一串符合语法的 PASCAL 语言，只有 $a,b,c$ 三个变量，而且只有赋值语句，赋值只能是一个一位的数字或一个变量，未赋值的变量值为 $0$。

## 输出格式

输出 $a,b,c$ 最终的值。

## 输入输出样例 #1

### 输入 #1

```
a:=3;b:=4;c:=5;
```

### 输出 #1

```
3 4 5
```

## 说明/提示

输入的 PASCAL 语言长度不超过 $255$。
"""

if __name__ == "__main__":
    data = input().strip()
    data = data.split(';')
    a, b, c = 0, 0, 0
    for str in data:
        if str == '':
            continue
        var, val = str.split(":=")
        var = var.strip()
        val = val.strip()
        if val.isdigit():
            val = int(val)
        else:
            if val == 'a':
                val = a
            elif val == 'b':
                val = b
            elif val == 'c':
                val = c
        if var == 'a':
            a = val
        elif var == 'b':
            b = val
        elif var == 'c':
            c = val
    print(a, b, c)
