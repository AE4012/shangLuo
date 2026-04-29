
import math

if __name__ == "__main__":
    n = float(input().strip())

    # Fn
    Fn = (((1+math.sqrt(5))/2)**n - ((1-math.sqrt(5))/2)**n) / math.sqrt(5)

    print(f"{Fn:.2f}")

