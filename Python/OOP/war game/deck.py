"""
This file contains deck class
"""
from card import Card
from random import shuffle


class Deck:

    def __init__(self, flag: bool):
        # running validations
        if type(flag) != bool:
            raise Exception(TypeError, "must be true or false")

        # initializing variables
        self.__deck_list = []
        '''
            flag = true = full set
            flag = false = empty set
        '''
        # making deck of class
        if flag:
            list_of_ranks = [2, 3, 4, 5, 6, 7, 8, 9, 10, "Jack", "Queen", "King", "Ace"]
            list_of_suits = ["Spades", "Clubs", "Hearts", "Diamonds"]

            c = 0
            spades_list = []
            diamonds_list = []
            hearts_list = []
            clubs_list = []
            md = {
                "0": "spades_list",
                "1": "diamonds_list",
                "2": "hearts_list",
                "3": "clubs_list"
            }

            while c != 4:
                for i in list_of_ranks:
                    mc = Card(list_of_suits[c], str(i))
                    self.__deck_list.append(mc)
                c += 1

        else:
            self.__deck_list.append("")

    def __len__(self):
        size = 0
        for i in self.__deck_list:
            size += 1
        return size

    def print(self):
        for i in self.__deck_list:
            print(i)

    def shuffle(self):
        shuffle(self.__deck_list)

    def remove(self, item: Card):
        if isinstance(item, Card):
            if item in self.__deck_list:
                self.__deck_list.remove(item)
        else:
            raise Exception("Item is not a card")

    def split_deck(self):
        first_half = []
        second_half = []

        for index, item in enumerate(self.__deck_list):
            if index < 26:
                first_half.append(item)
            else:
                second_half.append(item)

        # Return!
        return first_half, second_half

    def grab_card(self):
        return self.__deck_list.pop()
