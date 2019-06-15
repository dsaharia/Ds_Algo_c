import math

def is_prime(number):
    primes = []
    for num in range(2, (int)(math.sqrt(number))+1):
        if number % num == 0:
            primes.append(num)
            if num != (int)(math.sqrt(number)):
                primes.append(number//num)
    return primes

number = (int)(input("Enter the number to factorize: "))

print(is_prime(number))