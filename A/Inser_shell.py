def Insertion(a, n): 
    for i in range(n): 
        temp = a[i] 
        j = i - 1 
        while j >= 0 and a[j] > temp: 
            a[j + 1] = a[j] 
            j -= 1 
        a[j + 1] = temp 

def ShellSort(a, n): 
    d = n // 2 
    while d > 0: 
        for i in range(d, n): 
            temp = a[i] 
            j = i 
            while j >= d and a[j - d] > temp: 
                a[j] = a[j - d] 
                j -= d 
            a[j] = temp 
        d //= 2 

a = [] 
n = int(input("Enter number of elements you want in list: ")) 
for i in range(n): 
    m = float(input("Enter element: ")) 
    a.append(m) 

while True: 
    print("Please press '1' for insertion sort:") 
    print("Please press '2' for shell sort:") 
    print("Please press '3' for none:") 
    opt = int(input("Enter your choice: ")) 

    if opt == 1: 
        Insertion(a, n) 
        print("The sorted list using insertion sort is:", a) 
    elif opt == 2: 
        ShellSort(a, n) 
        print("The sorted list using shell sort is:", a) 
    elif opt == 3: 
        print("You opted for none.")
        break
    else:
        print("Invalid option. Please try again.")