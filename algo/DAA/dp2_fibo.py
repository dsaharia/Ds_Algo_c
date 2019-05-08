def fibo(n):
    lookup = [-1 for _ in range(n+1)]
    lookup[0] = 0
    lookup[1] = 1
    for i in range(2,n+1):
        lookup[i] = lookup[i-1] + lookup[i-2]
    print("Fibonnaci Series upto {} is {}".format(n, lookup))

def main():
    n = int(input("Enter the value of n: "))
    fibo(n)

if __name__ == '__main__':
    main()