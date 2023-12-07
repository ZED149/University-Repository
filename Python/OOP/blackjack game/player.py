"""
This file contains player class
"""
from card import Card


class Player:

    def __init__(self, name: str, balance: float):
        # running validations
        if type(name) != str:
            raise Exception(TypeError, "Name must be a string")
        if type(balance) != float:
            if type(balance) != int:
                raise Exception(TypeError, "Balance must be int/float")

        # initializing values
        self.__name = name
        self.__balance = balance
        self.__card_list = []

    def __str__(self):
        return f"{self.__name}"

    # name getter
    @property
    def name(self):
        return self.__name

    # name setter
    @name.setter
    def name(self, value):
        self.__name = value

    # balance getter
    @property
    def balance(self):
        return self.__balance

    # balance setter
    @balance.setter
    def balance(self, value):
        self.__balance = value

    def add_balance(self, value: float):
        if isinstance(value, float):
            self.__balance += value
        elif isinstance(value, int):
            self.__balance += value

    # card list getter
    @property
    def card_list(self):
        return self.__card_list

    def add_to_card_list(self, value):
        if isinstance(value, Card):
            self.__card_list.append(value)
        elif isinstance(value, list):
            self.__card_list.extend(value)

    def place_bet(self):
        bet_money = float(input(f"Enter bet amount [{self.__balance}]: "))
        return bet_money if bet_money <= self.__balance else -1

    def get_total(self):
        total = 0
        for i in self.__card_list:
            total += i.get_total()
        return total
