import math

def is_prime(number):
    for num in range(2, (int)(math.sqrt(number))):
        if number % num == 0:
            return False
    return True

number = (int)(input("Enter the number to find prime or not: "))

print(is_prime(number))