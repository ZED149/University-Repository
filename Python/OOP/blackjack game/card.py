"""
This file contains card class
"""


class Card:
    __rank_dict = {
        "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9, "10": 10, "Jack": 11, "Queen": 12, "King": 13,
        "Ace": 14,
    }
    __list_of_suits = ["Spades", "Clubs", "Hearts", "Diamonds"]

    # constructor
    def __init__(self, suit: str, rank: str):  # Card("Hearts", "Jack")
        # running validations
        if type(suit) != str or type(rank) != str:
            raise Exception(ValueError, "Invalid Types")
        if suit.capitalize() not in Card.__list_of_suits:
            raise Exception("Invalid card name")
        if rank not in Card.__rank_dict.keys():
            raise Exception("Invalid rank name")

        # initializing variables
        self.__suit = suit
        self.__rank = rank

    def __str__(self):
        return f"{self.__rank} of {self.__suit}"

    def __eq__(self, other):
        if self.__suit.capitalize() == other.__suit.capitalize():
            if self.__rank == other.__rank:
                return True
        return False

    def get_total(self):
        if self.__rank in ['2', '3', '4', '5', '6', '7', '8', '9', '10']:
            return int(self.__rank)
        elif self.__rank in ["Jack", "Queen", "King"]:
            return 10
        elif self.__rank == "Ace":
            return 1
