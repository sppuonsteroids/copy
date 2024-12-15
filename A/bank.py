def deposit(balance, amount):
    """Deposit a specified amount to the balance."""
    return balance + amount

def withdraw(balance, amount):
    """Withdraw a specified amount from the balance if sufficient funds are available."""
    if balance >= amount:
        return balance - amount
    else:
        print("Insufficient balance:", balance)
        return balance

account_balance = 10000

while True:
    transaction = input("Enter transaction (e.g., 'D 100' or 'W 200') or 'exit' to quit: ")
    
    if transaction.lower() == 'exit':
        print("Exiting the transaction system.")
        break
    
    try:
        operation, amount_str = transaction.split()
        amount = int(amount_str)
        
        if amount <= 0:
            print("Amount must be a positive integer.")
            continue
        
        if operation.upper() == "D":
            account_balance = deposit(account_balance, amount)
            print(f"Deposited {amount}. Current Account balance is: {account_balance}")
        elif operation.upper() == "W":
            account_balance = withdraw(account_balance, amount)
            print(f"Withdrew {amount}. Current Account balance is: {account_balance}")
        else:
            print("Invalid operation:", operation)
    except ValueError:
        print("Invalid input format. Please enter in the format 'D 100' or 'W 200'.")