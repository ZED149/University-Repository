

# Task4
def task4():
    print("Task 4: ")
    string1 = "My name is: "
    string2 = "Huzaifa"
    # concatenating/joining two strings
    concatenated_string = string1 + string2
    # printing concatenated string
    print(f"String 1: {string1}")
    print(f"String 2: {string2}")
    print(f"Concatenated String is {concatenated_string}")


# Task 5
def task5():
    print("Task 5: ")
    sentence = "The study of algorithms is a fundamental aspect of computer science."
    word = "algorithms"
    # now we need to check that is word is present in the sentence or not
    if word in sentence:
        print(f"Word: ({word}) is present in the sentence. \"{sentence}\"")
    else:
        print(f"Word: ({word} is not present in the sentence.")


def task6():
    print("Task 6: ")
    name = input("Enter your name: ")
    age = int(input("Enter your age: "))
    print(f"Hello your name is {name}, you are {age} years old.")


def task7():
    print("Task 7: ")
    num1 = float(input("Enter number 1: "))
    num2 = float(input("Enter number 2: "))
    print("Addition: ", num1 + num2)
    print("Subtraction: ", num1 - num2)
    print("Multiplication: ", num1 * num2)
    try:
        print("Division: ", num1 / num2)
    except ZeroDivisionError:
        print("Division: Cannot divide by zero.")


def task8():
    print("Task 8: ")
    "Converts temperature from Celsius to Fahrenheit."
    celsius = 25
    fahrenheit = (9/5)*celsius+32
    print(f"Temp in Celsius is: {celsius} degree. Now after converting into Fahrenheit, it is {fahrenheit}F")


# main()
def main():
    task4()
    task5()
    task6()
    task7()
    task8()


# calling main
if __name__ == "__main__":
    main()

