def main():
    """
    1. take dimension input from user
    2. prints grid to console
    3. do player turn
    4. put value in grid
    5. perform check functions or check for wins
    6. toggle players input
    :return:
    """

    # some global variables for the program
    dimensions = int
    player1 = 'x'
    player2 = 'y'
    player_turn = 'x'
    game_flag = True

    def welcome_message():
        print("Welcome to ZED Tic Tac Toe")
        print("Symbol for player1 is: 'x'\nSymbol for player 2 is: 'o'")

    def validate_user_input_on_dimensions(dimensions):

        # check digit
        if dimensions.isdigit():
            # convert to int
            dimensions = int(dimensions)

            # check bound and return
            return dimensions > 2
        else:
            return False

    def validate_user_input_on_grid(grid_index):

        # check digit
        if grid_index.isdigit():

            # convert to int
            grid_index = int(grid_index)

            # check bound
            return 0 < grid_index <= (dimensions ** 2)
        else:
            return False

    def validate_user_input_on_grid_block(grid_index):

        # check digit
        if grid_index.isdigit():
            # convert to int
            grid_index = int(grid_index)

            # check grid block
            return grid[grid_index - 1] == " "
        else:
            return False

    def _display_grid():
        counter = dimensions
        index = 0
        while not counter == 0:
            print("|", end="")
            for i in range(dimensions):
                print(f" {grid[index]} |", end="")
                index += 1
            print("")
            counter -= 1

    def _check_horizontal():
        counter = dimensions
        index = 0
        flag = True

        while not counter == 0:
            inner_loop_iterator = 0
            temp = index
            flag = True
            while inner_loop_iterator < dimensions:
                if not grid[temp] == player_turn:
                    flag = False
                    break
                temp += 1
                inner_loop_iterator += 1
            # return flag
            if flag:
                return flag
            index += dimensions
            counter -= 1

        return flag

    def _check_vertical():
        counter = dimensions
        index = 0
        flag = True

        while not counter == 0:
            inner_loop_iterator = dimensions
            temp = index
            flag = True
            while not inner_loop_iterator == 0:
                if not grid[temp] == player_turn:
                    flag = False
                    break
                temp += dimensions
                inner_loop_iterator -= 1
            # return flag
            if flag:
                return flag
            index += 1
            counter -= 1

        return flag

    def _check_diagonal_x():
        index = 0
        counter = dimensions
        flag = True

        while not counter == 0:
            if not grid[index] == player_turn:
                flag = False
                return flag
            index += (dimensions + 1)
            counter -= 1

        return flag

    def _check_diagonal_y():
        index = (dimensions - 1)
        counter = dimensions
        flag = True

        while not counter == 0:
            if not grid[index] == player_turn:
                flag = False
                return flag
            index += (dimensions - 1)
            counter -= 1

        return flag

    # this runs all the checks
    def run_all_checks():

        # these are all the checks to be made to the grid
        return _check_horizontal() or _check_vertical() or _check_diagonal_x() or _check_diagonal_y()

    '''######################## Starts Here #################################################'''
    # game starts from here
    welcome_message()

    # taking dimensions input from user
    dimensions = input("Enter dimensions ")
    while not validate_user_input_on_dimensions(dimensions):
        dimensions = input("Invalid Input. Enter again [dimensions >= 3] ")

    # input is valid to be converted to integer
    dimensions = int(dimensions)
    grid = [" "] * (dimensions ** 2)  # creates 'n' no. of rows in list

    # game loop
    while game_flag:
        _display_grid()
        # asking player for grid number
        print(f"This is turn of player {player_turn}.", end="")
        print("Enter grid number --> ", end="")
        grid_number = input()
        while not validate_user_input_on_grid(grid_number):
            grid_number = input(f"Invalid number. Enter again. 0 > number <= {(dimensions ** 2)} ")

        # safe to be converted into integer
        grid_number = int(grid_number)

        # check if the slot is empty or not
        if not grid[grid_number - 1] == " ":
            grid_number = str(grid_number)
            while not validate_user_input_on_grid_block(grid_number):
                grid_number = input("Slot not empty. Enter again")

        # safe to convert to int and to be put on the grid
        grid_number = int(grid_number)
        grid[grid_number - 1] = player_turn

        # checking for win
        if run_all_checks():
            game_flag = False
            print(f"\nHurrah! player {player_turn} wins the game")
            _display_grid()
            break

        # toggling turns
        if player_turn == 'x':
            player_turn = 'o'
        else:
            player_turn = 'x'

        # check for draw
        if " " not in grid:
            _display_grid()
            print("Its a DRAW!\nBetter luck next time.")
            break


if __name__ == '__main__':
    main()
