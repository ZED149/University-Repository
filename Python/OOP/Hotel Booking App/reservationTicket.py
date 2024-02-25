

# this file contains reservationTicket class
from fpdf import FPDF
import pandas as pd

class ReservationTicket:
    """
    Generates a reservation ticket in pdf format.
    """
    # constructor
    def __init__(self, customer_name, hotel_object):
        self.customer_name = customer_name
        self.hotel = hotel_object

    # generate
    def generate(self):
        """
        Generates a reservation ticket in pdf.
        :return:
        """
        df = pd.read_csv("hotels.csv")
        pdf = FPDF(orientation='P', unit='mm', format='A4')
        pdf.set_auto_page_break(auto=False, margin=0)
        pdf.add_page()

        # writing Header
        pdf.set_font(family='Times', style='B', size=24)
        pdf.cell(w=0, h=12, txt=f"ZED Hotel Booking App")
        pdf.image("pythonhow.png", w=10, x=102)
        pdf.line(11, 22, 200, 22)
        pdf.ln(2)

        # writing hotel information
        pdf.set_font(family='Times', style='BIU', size=20)
        pdf.cell(w=0, h=10, ln=1, align='C', txt="Hotel Information")
        pdf.set_font(family="Times", size=12)
        pdf.cell(w=30, h=6, align='L', txt=f"ID:", border=1)
        pdf.cell(w=0, h=6, align='L', ln=1, txt=f"{df.loc[df['id'] == self.hotel.hotel_id, "id"].squeeze()}", border=1)
        pdf.cell(w=30, h=6, align='L', txt=f"Hotel:", border=1)
        pdf.cell(w=0, h=6, align='L', ln=1, txt=f"{df.loc[df['id'] == self.hotel.hotel_id, "name"].squeeze()}", border=1)
        pdf.cell(w=30, h=6, align='L', txt=f"City:", border=1)
        pdf.cell(w=0, h=6, align='L', ln=1, txt=f"{df.loc[df['id'] == self.hotel.hotel_id, "city"].squeeze()}", border=1)

        # writing customer information
        pdf.set_font(family='Times', style='BIU', size=20)
        pdf.cell(w=0, h=10, ln=1, align='C', txt="Customer Information")
        pdf.set_font(family="Times", size=12)
        pdf.cell(w=50, h=6, align='L', txt=f"Customer Name: ", border=1)
        pdf.cell(w=0, h=6, align='L', ln=1, txt=f"{self.customer_name.title()}", border=1)

        # outputting
        output_filename = f"{self.hotel.hotel_id}_{self.customer_name.title()}.pdf"
        pdf.output(output_filename)

        return f"Generated Successfully as {output_filename}"
