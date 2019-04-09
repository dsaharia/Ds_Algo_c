def quick_sort(numbers, start, end):
	""" This function will take the list and start and end indices
	and make calls to perform recursive calls and partition calls"""

	if start < end:
		pindex = partition(numbers, start, end)
		quick_sort(numbers, start, pindex)
		quick_sort(numbers, pindex+1, end)

def partition(numbers, start, end):
	""" This function will choose a pivot and partion the list
	and return the index of the pivot"""
	pivot = numbers[end]
	p_index = start
	for i in range(start, end+1):
		if numbers[i] <= pivot:
			numbers[i], numbers[p_index] = numbers[p_index], numbers[i]
			p_index += 1
	numbers[p_index], numbers[end] = numbers[end], numbers[p_index]
	return p_index


numbers = [8, 4, 77, 22, 63, 24, 26, 6]
quick_sort(numbers, 0, len(numbers)-1)
print(numbers)