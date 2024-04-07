

# Task 1 Removing Errors and Correcting Indentation
"""def vend(item_selected, amount_given):
    if item_selected == "Soda":     # adding equivalent operator '==' instead of '=' assignment operator
        price = 1.5
    elif item_selected == "Chips":
        price = 1.0
    else:
        price = 0.75                # adding 5 Tabs or 1 indent on this line in

    # adding some extra line for readability of the code
    change = amount_given - price
    if change < 0:                  # adding ':' at the end as this is the correct sequence of 'if' statement
        return "Insufficient funds!"
    else:                           # adding ':' at the end as this is the correct sequence of 'else' statement
        # removing incorrect '"' and newline characters in order for the code to execute.
        return "Thank you for purchasing " + item_selected + f". Your change is {str(change)}"


# removing extra indentation on lines (20, 21, 22, 23) and taking them out from scope of function vend(,,)
item = input("Choose an item (Soda/Chips/Candy): ")
money = float(input("Enter the amount given: "))    # renaming variable 'mony' to 'money'
result = vend(item, money)
print(result)"""


# Task 2 Pseudo Code
"""
1. Define function 'vend' taking two parameters: 'item_selected' and 'amount_given'.
2. Check if 'item_selected' is equal to "Soda":
      If true then set 'price' to 1.5.
4. If neither "Soda" nor "Chips" is selected:
       'price' = 0.75.
5. Calculate 'change' by subtracting 'price' from 'amount_given'.
6. If 'change' is less than 0:
      Return string "Insufficient funds!".      
7. If 'change' is greater than or equal to 0:
    return string "Thank you for purchasing " + item_selected + f". Your change is {str(change)}" 
    
Main Function of program
8. Ask user to input the selected item.
9. Ask user to input the amount given and convert it to float.
10. Call the 'vend' function with inputs 'item' and 'money', storing the result.
11. Print the result.
"""


# Task 3 Commenting
# defining a function named as vend() with two parameters
# param 1 is, item_selected
# param 2 is: amount_given
def vend(item_selected, amount_given):
    # performs a check on item_selected and if returns the amount after subtracting it from purchased item.
    # if amount is zero and a user purchases an item, then it returns "Insufficient Funds"

    # checking if item_selected is equal to Soda
    if item_selected == "Soda":
        # if it is, then set the price to 1.5
        price = 1.5
    elif item_selected == "Chips":  # checking if item_selected is equal to Chips
        # if it is, set the price to 1.0
        price = 1.0
    else:   # otherwise, set the price to 0.75
        # setting the price to 0.75
        price = 0.

    # computing change by subtracting amount_given from price
    change = amount_given - price
    # if change is less then zero means it is a negative integer
    if change < 0:
        # then return the following string
        return "Insufficient funds!"
    else:   # if change is not zero
        # return the following string containing item_selected and change variable
        return "Thank you for purchasing " + item_selected + f". Your change is {str(change)}"


# main() from here
# initializing item with the user input
item = input("Choose an item (Soda/Chips/Candy): ")
# initializing money with the user input and converting it into float
money = float(input("Enter the amount given: "))
# storing returned value from vend(,,) to result
result = vend(item, money)
# printing the result to the screen
print(result)
