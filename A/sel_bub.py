def Bubble(a, n): 
    for i in range(n): 
        for j in range(0, n - i - 1): 
            if a[j] > a[j + 1]: 
                # Swap
                a[j], a[j + 1] = a[j + 1], a[j] 
    return a  # Return the sorted list

def Selection(a, n): 
    for i in range(n): 
        min_index = i 
        for j in range(i + 1, n): 
            if a[j] < a[min_index]: 
                min_index = j 
        # Swap
        a[i], a[min_index] = a[min_index], a[i] 
    return a  # Return the sorted list

a = [] 
n = int(input("Enter number of elements you want in list: ")) 
for i in range(n): 
    m = float(input("Enter element: ")) 
    a.append(m) 

while True: 
    print("Please press '1' for bubble sort:") 
    print("Please press '2' for selection sort:") 
    print("Please press '3' for none:") 
    opt = int(input("Enter your choice: ")) 

    if opt == 1: 
        sorted_list = Bubble(a.copy(), n)  # Use a copy to keep original list intact
        print("The sorted list using bubble sort is:", sorted_list) 
    elif opt == 2: 
        sorted_list = Selection(a.copy(), n)  # Use a copy to keep original list intact
        print("The sorted list using selection sort is:", sorted_list) 
    elif opt == 3: 
        print("You opted for none.")
        break
    else:
        print("Invalid option. Please try again.")