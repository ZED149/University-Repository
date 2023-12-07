
from player import Player
from blackjack import BlackJack
from deck import Deck
import os

p1 = Player("salman", 1000.0)
o = BlackJack(p1)
o.run()