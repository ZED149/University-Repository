"""
This file contains player class
"""


class Player:

    def __init__(self, name: str):
        if type(name) != str:
            raise Exception(TypeError, "invalid types")

        self.__name = name
        self.__grabbed_card = None
        self.__player_list = []
        self.__player_side_list = []

    def __str__(self):
        return f"{self.__name}"

    # grabbed_card getter
    @property
    def grabbed_card(self):
        return self.__grabbed_card

    # grabbed_card setter
    @grabbed_card.setter
    def grabbed_card(self, value):
        self.__grabbed_card = value

    # player_list getter
    @property
    def player_list(self):
        return self.__player_list

    # player_list setter
    @player_list.setter
    def player_list(self, value):
        self.__player_list = value

    # player_side_list getter
    @property
    def player_side_list(self):
        return self.__player_side_list

    # player_side_list setter
    @player_side_list.setter
    def player_side_list(self, value):
        self.__player_side_list = value

    # name getter
    @property
    def name(self):
        return self.__name

    # name setter
    @name.setter
    def name(self, value):
        self.__name = value

