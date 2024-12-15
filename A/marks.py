def Average(marks, n): 
    total = sum(marks)  # Using built-in sum function
    average = total / n if n > 0 else 0  # Avoid division by zero
    return average 

def Maximum(marks, n): 
    max_mark = -1  # Initialize to -1 to handle cases where all marks are -1
    for i in range(n): 
        if marks[i] > max_mark: 
            max_mark = marks[i] 
    return max_mark 

def Minimum(marks, n): 
    min_mark = float('inf')  # Initialize to infinity
    for i in range(n): 
        if marks[i] < min_mark and marks[i] >= 0: 
            min_mark = marks[i] 
    return min_mark if min_mark != float('inf') else -1  # Return -1 if no valid marks

def Absent(marks, n): 
    cnt = 0 
    for i in range(n): 
        if marks[i] == -1: 
            cnt += 1 
    return cnt 

def Cntmax(marks, n, s): 
    cntmax = 0 
    for i in range(n): 
        if marks[i] == s: 
            cntmax += 1 
    return cntmax 

marks = [] 
n = int(input("Enter number of students (if absent please enter -1): ")) 
for i in range(n): 
    m = int(input("Enter your marks: ")) 
    marks.append(m) 

while True: 
    print("\nPlease choose an option:")
    print("1. Average")
    print("2. Maximum marks")
    print("3. Minimum marks")
    print("4. Absent students")
    print("5. Count of maximum marks")
    print("6. Exit")
    
    opt = int(input("Enter your choice: ")) 
    
    if opt == 1: 
        avg = Average(marks, n) 
        print("Average is:", avg) 
    elif opt == 2: 
        max_mark = Maximum(marks, n) 
        print("Maximum marks:", max_mark) 
    elif opt == 3: 
        min_mark = Minimum(marks, n) 
        print("Minimum marks:", min_mark) 
    elif opt == 4: 
        cnt = Absent(marks, n) 
        print("No. of absent students:", cnt) 
    elif opt == 5: 
        max_mark = Maximum(marks, n) 
        cntmax = Cntmax(marks, n, max_mark) 
        print("The number of students having maximum marks:", cntmax) 
    elif opt == 6: 
        print("Exiting the program.")
        break  # Exit the loop
    else:
        print("Invalid option, please try again.")