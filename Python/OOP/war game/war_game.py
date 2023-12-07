"""
This file contains wargame class
"""
from player import Player
from deck import Deck
from card import Card


class WarGame:

    def __init__(self, p1: Player, p2: Player):
        # running validations
        if not isinstance(p1, Player) or not isinstance(p2, Player):
            raise Exception(TypeError, "Player names must be a string")

        # initializing variables
        self.__player1 = p1
        self.__player2 = p2
        self.__first_half = []
        self.__second_half = []

    def run(self):
        game_deck = Deck(True)
        game_deck.shuffle()
        self.__first_half, self.__second_half = game_deck.split_deck()

        self.__player1.grabbed_card = self.__first_half.pop()
        self.__player2.grabbed_card = self.__second_half.pop()
        game_deck.remove(self.__player1.grabbed_card)
        game_deck.remove(self.__player2.grabbed_card)

        counter = 1
        while game_deck.__len__() > 0:

            print(f"[{counter}] Grabbed cards are: {self.__player1.grabbed_card} and {self.__player2.grabbed_card} respectively")

            if Card.calculate_ranks(self.__player1.grabbed_card) == Card.calculate_ranks(self.__player2.grabbed_card):
                popped_item = None
                self.__player1.player_side_list.append(self.__player1.grabbed_card)
                self.__player2.player_side_list.append(self.__player2.grabbed_card)
                for i in range(0, 3):
                    if self.__first_half.__len__() > 0:
                        popped_item = self.__grab_from_first_half()
                        self.__player1.player_side_list.append(popped_item)
                        game_deck.remove(popped_item)

                for i in range(0, 3):
                    if self.__second_half.__len__() > 0:
                        popped_item = self.__grab_from_second_half()
                        self.__player2.player_side_list.append(popped_item)
                        game_deck.remove(popped_item)

            elif Card.calculate_ranks(self.__player1.grabbed_card) > Card.calculate_ranks(self.__player2.grabbed_card):
                while self.__player2.player_side_list.__len__() > 0:
                    self.__player1.player_list.append(self.__player2.player_side_list.pop())
                while self.__player1.player_side_list.__len__() > 0:
                    self.__player1.player_list.append(self.__player1.player_side_list.pop())
                self.__player1.player_list.append(self.__player1.grabbed_card)
                self.__player1.player_list.append(self.__player2.grabbed_card)
            else:
                while self.__player2.player_side_list.__len__() > 0:
                    self.__player2.player_list.append(self.__player2.player_side_list.pop())
                while self.__player1.player_side_list.__len__() > 0:
                    self.__player2.player_list.append(self.__player1.player_side_list.pop())
                self.__player2.player_list.append(self.__player1.grabbed_card)
                self.__player2.player_list.append(self.__player2.grabbed_card)

            if self.__first_half.__len__() > 0:
                self.__player1.grabbed_card = self.__first_half.pop()
            if self.__second_half.__len__() > 0:
                self.__player2.grabbed_card = self.__second_half.pop()
            game_deck.remove(self.__player1.grabbed_card)
            game_deck.remove(self.__player2.grabbed_card)

            counter += 1

        if self.__player1.player_list.__len__() > self.__player2.player_list.__len__():
            print(f"{self.__player1.name} wins")
        elif self.__player1.player_list.__len__() == self.__player2.player_list.__len__():
            print("Its a Tie!")
        else:
            print(f"{self.__player2.name} wins")

    def __grab_from_first_half(self):
        if self.__first_half.__len__() > 0:
            return self.__first_half.pop()

    def __grab_from_second_half(self):
        if self.__second_half.__len__() > 0:
            return self.__second_half.pop()

    def __grab_3_card_from_first_half(self):
        first, second, third = [Card, Card, Card]
        if self.__first_half.__len__() > 0:
            first = self.__first_half.pop()
        if self.__first_half.__len__() > 0:
            second = self.__first_half.pop()
        if self.__first_half.__len__() > 0:
            third = self.__first_half.pop()
        return first, second, third

    def __grab_3_card_from_second_half(self):
        first, second, third = [Card, Card, Card]
        if self.__second_half.__len__() > 0:
            first = self.__second_half.pop()
        if self.__second_half.__len__() > 0:
            second = self.__second_half.pop()
        if self.__second_half.__len__() > 0:
            third = self.__second_half.pop()
        return first, second, third
