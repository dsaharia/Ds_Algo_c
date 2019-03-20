# Assignment 4 -> Question Number (b)

def count_ball(height):
	"""Calculates number of balls by taking the height of the pyramid, makes the recursive calls"""
	if height == 1: # If layer is 1, then number of balls if also 1
		return 1
	else:
		return (height ** 2) + count_ball(height-1) # observing the pattern


def main():
	height = int(input("Enter the height:"))
	print("Number of balls are: {}" .format(count_ball(height)))

if __name__ == '__main__':
	main()