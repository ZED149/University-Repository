"""
This file contains BlackJack class
"""
from player import Player
from deck import Deck


class BlackJack:
    def __init__(self, player=Player):
        # running validations
        if not isinstance(player, Player):
            raise Exception(TypeError, "Passed object must be of player type.")

        # assigning values
        self.__player = player
        self.__dealer = Player("Dealer", 99999)

    def run(self):
        # creating deck of cards
        game_deck = Deck(True)

        # shuffling deck
        game_deck.shuffle()

        # player is placing a bet
        player_bet_money = -1
        while player_bet_money == -1:
            player_bet_money = self.__player.place_bet()
        self.__player.balance = self.__player.balance - player_bet_money

        # distributing two cards to both Dealer and Player
        # distributing to Player
        for i in range(0, 2):
            mc = game_deck.grab_card()
            self.__player.add_to_card_list(mc)
        # distributing to Dealer
        for i in range(0, 2):
            mc = game_deck.grab_card()
            self.__dealer.add_to_card_list(mc)

        # displaying player cards and dealer face card
        for i in range(0, 2):
            if i == 0:
                print(f"[Dealer ({self.__dealer.get_total()})] --> {self.__dealer.card_list[-1]}")
            print(f"[{self.__player.name} ({self.__player.get_total()})] --> {self.__player.card_list[i]}")

        # game loop
        game_flag = True
        player_decision = ""
        while game_flag:
            # Player's Turn
            while player_decision not in ["h", "s"]:
                player_decision = input("To HIT press 'h', To STAT press 's'. ")

            if player_decision == 'h':
                hit = True
                stay = False
                while hit:
                    mc = game_deck.grab_card()
                    self.__player.add_to_card_list(mc)
                    print(f"[{self.__player.name} ({self.__player.get_total()})] --> {mc}")
                    # checking for total
                    if self.__player.get_total() == 21:
                        print(f"{self.__player.name} ({self.__player.get_total()}) wins. Game Over!")
                        game_flag = False
                        break
                    elif self.__player.get_total() > 21:
                        print(f"{self.__player.name} is BUSTED. Game Over!")
                        game_flag = False
                        break
                    else:
                        # asking again for hit
                        player_decision = input("To hit again press 'h', to stay press 's'")
                        if player_decision == 's':
                            hit = stay
            # checking if the player is already busted or not
            if not game_flag:
                break
            # check player total
            player_total = self.__player.get_total()
            if player_total > 21:
                print(f"{self.__player.name} is BUSTED. Game Over!")
                game_flag = False
                break

            # Dealer's Turn
            dealers_total = self.__dealer.get_total()
            if dealers_total >= 17:
                if dealers_total > player_total:
                    print(f"Dealer wins. Dealer ({dealers_total}), {self.__player.name} ({player_total}). Game Over!")
                    game_flag = False
                    break
                if dealers_total == player_total:
                    print("Its a Tie. A Lucky one")
                    game_flag = False
                    break
                if dealers_total < player_total:
                    print(f"{self.__player.name} ({player_total}) wins. Game Over!")
                # stay with hand (means don't take turn)
                print(f"Dealer will stay with hand as he has total of {self.__dealer.get_total()}")
                game_flag = False
                break
            elif dealers_total <= 16:
                # take hits until total exceeds 21, or it exceeds player's total
                while dealers_total <= 16:
                    if dealers_total > player_total:
                        print(f"Dealer ({dealers_total}) wins. Game Over!")
                        game_flag = False
                        break
                    mc = game_deck.grab_card()
                    self.__dealer.add_to_card_list(mc)
                    print(f"[{self.__dealer.name} ({self.__dealer.get_total()})] --> {mc}")
                    dealers_total = self.__dealer.get_total()
                if dealers_total > 21:
                    print(f"Dealer BUSTED. {self.__player.name} wins. Game Over!")
                    game_flag = False
            if not game_flag:
                break
