# this file contains the credit card class
import sqlite3
import pandas as pd


class CreditCard:
    # constructor
    def __init__(self, holder_name, number, expiry_date, cvc):
        self.holder_name = holder_name
        self.number = number
        self.expiry_date = expiry_date
        self.cvc = cvc

    # validate
    def validate(self, deduct_amount):
        """
        Validates the credit cart information provided by the user.
        :return: bool
        """

        # making connection to database
        conn = sqlite3.connect('cards.db')
        cursor = conn.cursor()
        # making query to DB
        query = """SELECT "amount" FROM "card information" WHERE "holder name"=? AND "number"=? AND "date"=? AND "cvc"=?"""
        cursor.execute(query, [self.holder_name, self.number, self.expiry_date, int(self.cvc)])
        # fetching results from cursor
        results = cursor.fetchall()
        if results:
            # it means that credit card record is found
            # now we need to deduct amount and write it to the DB
            # deducting amount
            amount = results[0][0] - deduct_amount
            # updating it in the DB
            query = """UPDATE "card information" SET "amount"=? WHERE "holder name"=? AND "number"=? AND "date"=? AND "cvc"=?"""
            cursor.execute(query, [amount, self.holder_name, self.number, self.expiry_date, int(self.cvc)])
            conn.commit()
            conn.close()
            return True
        else:
            conn.close()
            return False

    # secure validate
    def secure_validate(self, deduct_amount, card_number, password):
        """
        A more secure way to validate user credit card information.
        Performs a username and password check on the credit card information.
        :param deduct_amount:
        :return:
        """
        # creating dataframe object
        df = pd.read_csv('card_security.csv')

        # now check if the card number and password provided by the user match or not
        # if it matches then performs a transaction otherwise don't
        # At first we need to filter password provided by the user, as it cannot have slashes
        card_number = card_number.replace('-', '')
        card_number = int(card_number)
        # card_number = card_number.join("")
        password_check = df.loc[df['number'] == card_number]['password'].squeeze()
        if type(password_check) is pd.Series:
            if password_check.size == 0:
                print("Card Number is incorrect. Please try again.")
                exit(0)
        if password_check == password:
            return True
        else:
            return False
