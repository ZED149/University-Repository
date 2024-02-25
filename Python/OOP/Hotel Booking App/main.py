

# this is the main for hotel booking application

import pandas as pd
from hotel import Hotel
from user import User
from reservationTicket import ReservationTicket

# creating dataframe object
df = pd.read_csv("hotels.csv")

# printing data frame to screen
print(df)

hotel_id = int(input("Enter hotel id: "))
hotel = Hotel(hotel_id)

if hotel.available():
    hotel.book()
    name = input("Enter your name: ")
    reservation_ticket = ReservationTicket(name, hotel)
    print(reservation_ticket.generate())
    pass
else:
    # hotel isn't available
    print("Hotel not available")
