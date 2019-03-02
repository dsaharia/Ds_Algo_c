def is_large_apples(apple_size, i, j):
	""" Takes two indices and tells
	which one of them is larger or smaller """

	if apple_size[i] > apple_size[j]:
		return 1
	elif apple_size[i] < apple_size[j]:
		return -1

def mergesort_apples(s, l, r):
	""" This function takes indexed list and
	 makes recursive calls to sort the array """
	if l < r:
		mid = (l+r)//2
		mergesort_apples(s, l, mid)
		mergesort_apples(s, mid+1, r)
		merge_apples(s, l, mid, r)


def merge_apples(s, l, mid, r):
	""" This function takes the list and
	the indices to merge them into the final array"""
	nl = mid - l + 1
	nr = r - mid
	left, right = [], []
	left = s[l:mid+1:1]
	right = s[mid+1:r+1:1]
	i, j, k = 0, 0, l;
	while i < nl and j < nr:
		# print(s)
		if is_large_apples(apple_size, left[i], right[j]) == -1:
			s[k] = left[i]
			i += 1
		else:
			s[k] = right[j]
			j += 1
		k += 1

	while i < nl:
		s[k] = left[i]
		k += 1
		i += 1
	while j < nr:
		s[k] = right[j]
		k += 1
		j += 1

apple_size = [5, 7, 2, 15, 66, 25, 26] # Given list of sizes.
s = [x for x in range(0,len(apple_size))] # Original list of indices.
mergesort_apples(s, 0, len(s)-1)
print("Final merged and sorted list of indices",s)
