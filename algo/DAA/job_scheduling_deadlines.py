def sort_by_profits(data):
    """This function will take the data and sort in decreasing order """
    for i in range(len(data)):
        j = i+1
        while j < len(data):
            if data[i][2] < data[j][2]:
                data[i],data[j] = data[j],data[i]
            j+=1
    print ("Jobs in sorted order of profits(Decreasing) -> ")
    print(data)


def max_deadline(data):
    """This function will take the data and return the maximum allowed deadline"""
    current_max = data[0][1]
    for i in range(len(data)):
        
        for j in range(len(data) - 1 - i):

            if current_max <= data[j][1]:
                current_max = data[j][1]
    print ("Max deadline is : {}".format(current_max))
    return current_max

def job_scheduling(data):
    sort_by_profits(data)
    max_deadline_value = max_deadline(data)
    total_marks = 0
    schedule_list = [False] * max_deadline_value
    
    
    for i in range(len(data)):
        j = data[i][1]-1
        for j in range(j, -1, -1):
            if schedule_list[j] == False:
                schedule_list[j] = data[i][0]
                total_marks += data[i][2]
                break


    print("Optimal Sequence: {}".format(schedule_list))
    print("Total Marks: {}".format(total_marks))




def main():
    data = [
    ['1', 9, 14],
    ['2', 2, 4],
    ['3', 5, 18],
    ['4', 7, 1],
    ['5', 4, 25],
    ['6', 2, 20],
    ['7', 5, 8],
    ['8', 7, 10],
    ['9', 4, 12],
    ['10', 3, 5]
    ]
    job_scheduling(data)
    


if __name__ == '__main__':
    main()