

def main():
    array = [9, 2, 3, 8, 14, 11, 12]
    k = 3
    l = len(array)
    print("Original list: {}".format(array))
    result_index_min = []
    result_index_max = []
    min_sum = 1000
    max_sum = 0
    arr_left = []
    arr_right = []
    for i in range(l-2):
        temp_sum = array[i]+array[i+1]+array[i+2]
        if temp_sum < min_sum:
            min_sum = temp_sum
            result_index_min = [i,i+1,i+2]
        if temp_sum > max_sum:
            max_sum = temp_sum
            result_index_max = [i, i+1, i+2]
    arr_left = [array[result_index_min[0]], array[result_index_min[1]] , array[result_index_min[2]]]
    print("Left Subarray: {}".format(arr_left))
    arr_right = [array[result_index_max[0]], array[result_index_max[1]] , array[result_index_max[2]]]
    print("Old Right Subarray: {}".format(arr_right))
    max_left = max(arr_left)
    min_right = min(arr_right)
    if max_left >= min_right:
        print("Third Condition satisfied")
    else:
        index = array.index(max_left) # getting the index of the element.
        # arr_right = [array[index], array[index+1], array[index+2]]
        # print("New Right Subarray: {}".format(arr_right))
        # print("Third Condition Satisfied")
        max_sum = 0
        for i in range(index, l-2):
            temp_sum = array[i]+array[i+1]+array[i+2]
            temp_min = min(array[i],array[i+1],array[i+2])
            if temp_sum >= max_sum and max_left >= temp_min:
                max_sum = temp_sum
                result_index_max = [i, i+1, i+2]
                break
        arr_right = [array[result_index_max[0]], array[result_index_max[1]] , array[result_index_max[2]]]
        print("New Right Subarray: {}".format(arr_right))


if __name__ == '__main__':
    main()