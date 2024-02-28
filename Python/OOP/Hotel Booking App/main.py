

# this is the main for hotel booking application

import pandas as pd
from hotel import Hotel
from user import User
from reservationTicket import ReservationTicket
from credit_card import CreditCard

# creating dataframe object
df = pd.read_csv("hotels.csv")

# printing data frame to screen
print(df)

hotel_id = int(input("Enter hotel id: "))
hotel = Hotel(hotel_id)

if hotel.available():
    # first we deduct amount from user credit card
    user_info = ("Salman Ahmad", "1234-5678-1525-6987", "0424", "123")
    # creating card instance
    credit_card = CreditCard(user_info[0], user_info[1], user_info[2], user_info[3])
    # book a hotel if credit card is validated successfully
    # performing secure credit card validation
    if credit_card.secure_validate(200, "1234-5678-9012-3456", "mypass"):
        if credit_card.validate(200):
            hotel.book()
            print("Book successful")
            name = input("Enter your name: ")
            reservation_ticket = ReservationTicket(name, hotel)
            print(reservation_ticket.generate())
        else:
            print("Invalid Details or not enough credits!")
            exit(0)
    else:
        print("User password doesn't match.")

else:
    # hotel isn't available
    print("Hotel not available")
