def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]  # Choose the middle element as the pivot
        left = [x for x in arr if x < pivot]  # Elements less than the pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to the pivot
        right = [x for x in arr if x > pivot]  # Elements greater than the pivot
        return quick_sort(left) + middle + quick_sort(right)  # Recursively sort and combine

def main():
    n = int(input("Enter the number of students: ")) 
    percentages = [] 

    for i in range(n): 
        score = float(input(f"Enter the percentage for student {i + 1}: ")) 
        percentages.append(score)

    # Sort the percentages using Quick Sort
    sorted_percentages = quick_sort(percentages)

    # Display the top five scores
    print("Top five scores:")
    for score in sorted_percentages[-5:]:  # Get the last five elements (top scores)
        print(score)

if __name__ == "__main__":
    main()