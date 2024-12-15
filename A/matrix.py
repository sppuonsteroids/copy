# Function to add two matrices
def add_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(A[i])):
            row.append(A[i][j] + B[i][j])
        result.append(row)
    return result

# Function to subtract two matrices
def subtract_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(A[i])):
            row.append(A[i][j] - B[i][j])
        result.append(row)
    return result

# Function to multiply two matrices
def multiply_matrices(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(B[0])):
            sum_product = 0
            for k in range(len(B)):
                sum_product += A[i][k] * B[k][j]
            row.append(sum_product)
        result.append(row)
    return result

# Function to find the transpose of a matrix
def transpose_matrix(A):
    result = []
    for j in range(len(A[0])):
        row = []
        for i in range(len(A)):
            row.append(A[i][j])
        result.append(row)
    return result

# Example matrices
A = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

B = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]

# Performing operations
print("Matrix A:")
for row in A:
    print(row)

print("\nMatrix B:")
for row in B:
    print(row)

print("\nAddition of A and B:")
add_result = add_matrices(A, B)
for row in add_result:
    print(row)

print("\nSubtraction of A and B:")
subtract_result = subtract_matrices(A, B)
for row in subtract_result:
    print(row)

print("\nMultiplication of A and B:")
multiply_result = multiply_matrices(A, B)
for row in multiply_result:
    print(row)

print("\nTranspose of Matrix A:")
transpose_result = transpose_matrix(A)
for row in transpose_result:
    print(row)
