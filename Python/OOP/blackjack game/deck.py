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

    def grab_card(self):
        return self.__deck_list.pop()

    def __str__(self):
        printable = "The Deck is: "
        for i in self.__deck_list:
            printable += "\n" + i.__str__()

        return printable
