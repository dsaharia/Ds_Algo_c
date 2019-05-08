def cut_rod(prices, total_length):
    price_result = [ 0 for _ in range(total_length+1)] # Base case when rod length is 0
    
    for i in range(1, total_length+1):
        max_value = -11;
        for j in range(i):
            max_value = max(max_value, prices[j] + price_result[i-j-1])
        price_result[i] = max_value
    print(price_result)
    print("Max prices with length 8 is : {}".format(price_result[total_length]))


def main():
    prices = [1, 5, 8, 9, 10, 17, 17, 20]
    total_length = 8
    cut_rod(prices, total_length)


if __name__ == '__main__':
    main()