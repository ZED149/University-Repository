
import pandas as pd
# this file contains the hotel class


class Hotel:

    # constructor
    def __init__(self, hotel_id):
        self.hotel_id = hotel_id

    # book
    def book(self):
        """
        This function books a hotel by changing the availability of the hotel on the file.
        :return:
        """
        # opening dataframe object
        df = pd.read_csv('hotels.csv')
        # changing availability to no
        df.loc[df['id'] == self.hotel_id, 'available'] = 'no'
        # writing changes to csv file
        df.to_csv("hotels.csv", index=False)

    # available
    def available(self):
        """
        This function checks the availability of the hotel by reading the file.
        :return:
        """
        # creating data frame object
        df = pd.read_csv('hotels.csv')
        # checking if hotel id match or not
        availability = df.loc[df['id'] == self.hotel_id, "available"].squeeze()
        if type(availability) is pd.Series:
            if availability.size == 0:
                availability = 'no'
                print("The hotel id not found.\n")
                exit(0)

        if availability == "yes":
            return True
        else:
            return False
