import math

def factorization(number):
    factors = []
    for num in range(2, (int)(math.sqrt(number))+1):
        if number % num == 0:
            factors.append(num)
            if num != (int)(math.sqrt(number)):
                factors.append(number//num)
    return factors

number = (int)(input("Enter the number to factorize: "))

print(factorization(number))