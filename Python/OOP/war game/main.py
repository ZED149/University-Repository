from war_game import WarGame
from player import Player
from deck import Deck


p1 = Player("Player_1")
p2 = Player("Player_2")
g = WarGame(p1, p2)
g.run()

