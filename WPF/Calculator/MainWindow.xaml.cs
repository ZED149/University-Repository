using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Calculator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private bool _flag = true;
        private string _output = null;

        //Constructor
        public MainWindow()
        {
            InitializeComponent();
            if(mainWindow.Height < 300)
            {
                outputTextBlock.Padding = new Thickness(5);
                outputTextBlock.Margin = new Thickness(2.5);
                outputTextBlock.Background = Brushes.Black;
            }
        }
        
        public string Output
        {
            get { return _output; }
            set { _output = value; }
        }


        private double _temp;

        public double Temp
        {
            get { return _temp; }
            set { _temp = value; }
        }

        private char _operand;

        public char Operand
        {
            get { return _operand; }
            set { _operand = value; }
        }

        private void NumericButtonClick(object sender, RoutedEventArgs e)
        {
            //getting name of the button clicked
            string _nameOfButton = ((Button)sender).Name;

            //deciding on the basis of name
            switch (_nameOfButton)
            {
                case "one":
                    _output += '1';
                    outputTextBlock.Text = _output;
                    break;
                case "two":
                    _output += '2';
                    outputTextBlock.Text = _output;
                    break;
                case "three":
                    _output += '3';
                    outputTextBlock.Text = _output;
                    break;
                case "four":
                    _output += '4';
                    outputTextBlock.Text = _output;
                    break;
                case "five":
                    _output += '5';
                    outputTextBlock.Text = _output;
                    break;
                case "six":
                    _output += '6';
                    outputTextBlock.Text = _output;
                    break;
                case "seven":
                    _output += '7';
                    outputTextBlock.Text = _output;
                    break;
                case "eight":
                    _output += '8';
                    outputTextBlock.Text = _output;
                    break;
                case "nine":
                    _output += '9';
                    outputTextBlock.Text = _output;
                    break;
                case "zero":
                    _output += '0';
                    outputTextBlock.Text = _output;
                    break;
                case "decimal":
                    if(_flag)
                    {
                        if(Output != null && Output.Contains('.'))
                        {
                            Output = "";
                            Output += ".";
                            outputTextBlock.Text = Output;
                            _flag = false;
                        }
                        else
                        {
                            Output += ".";
                            outputTextBlock.Text = Output;
                            _flag = false;
                        }
                    }
                    else
                    {
                        MessageBox.Show("Can't add more than 1 decimal point");
                    }
                    break;
            }
        }

        private void Equal_Click(object sender, RoutedEventArgs e)
        {
            //deciding operand
            switch (Operand)
            {
                case '+':
                    if(Output != null)
                    {
                        Temp += double.Parse(Output);
                        outputTextBlock.Text = Temp.ToString();
                        Output = null;
                        _flag = true;
                        Temp = 0;
                    }
                    break;
                case '-':
                    if(Output != null)
                    {
                        Temp -= double.Parse(Output);
                        Output = "";
                        outputTextBlock.Text = Temp.ToString();
                        _flag = true;
                        Temp = 0;
                        Output = null;
                    }
                    break;
                case '*':
                    if(Output != null)
                    {
                        Temp *= double.Parse(Output);
                        Output = "";
                        outputTextBlock.Text = Temp.ToString();
                        _flag = true;
                        Temp = 0;
                        Output = null;
                    }
                    break;
                case '/':
                    if(Output != null)
                    {
                        Temp /= double.Parse(Output);
                        Output = "";
                        outputTextBlock.Text = Temp.ToString();
                        _flag = true;
                        Temp = 0;
                        Output = null;
                    }
                    break;
                case 'x':
                    if (Output != null)
                    {
                        Temp = Math.Pow(Temp, double.Parse(Output));
                        Output = "";
                        outputTextBlock.Text = Temp.ToString();
                        _flag = true;
                        Temp = 0;
                        Output = null;
                    }
                    break;
            }
        }

        private void OperandClick(object sender, RoutedEventArgs e)
        {
            //getting name of the operand
            string nameOfOperand = ((Button)sender).Name;

            //deciding on the basis of operand
            switch (nameOfOperand)
            {
                case "add":
                    if(Output != null)
                    {
                        Temp = double.Parse(Output);
                        outputTextBlock.Text = Output = "";
                        Operand = '+';
                        _flag = true;
                        Output = null;
                    }
                    break;
                case "minus":
                    if(Output != null)
                    {
                        Temp = double.Parse(Output);
                        outputTextBlock.Text = Output = "";
                        Operand = '-';
                        _flag = true;
                        Output = null;
                    }
                    break;
                case "multiply":
                    if(Output != null)
                    {
                        Temp = double.Parse(Output);
                        outputTextBlock.Text = Output = "";
                        Operand = '*';
                        _flag = true;
                        Output = null;
                    }
                    break;
                case "divide":
                    if(Output != null)
                    {
                        Temp = double.Parse(Output);
                        outputTextBlock.Text = Output = "";
                        Operand = '/';
                        _flag = true;
                        Output = null;
                    }
                    break;
            }
        }

        private void ExtraButtonClick(object sender, RoutedEventArgs e)
        {
            //getting name of button clicked
            string nameOfButton = ((Button)sender).Name;

            //Perforing operation according to the button clicked
            switch (nameOfButton)
            {
                case "clear":
                    outputTextBlock.Text = "";
                    Output = null;
                    Temp = 0;
                    _flag = true;
                    break;
                case "square":
                    if(Output != null)
                    {
                        Temp = Math.Pow(double.Parse(Output), 2);
                        outputTextBlock.Text = Temp.ToString();
                        _flag = true;
                        Output = null;
                    }
                    break;
                case "xpower":
                    if(Output != null)
                    {
                        Temp = double.Parse(Output);
                        Output = null;
                        outputTextBlock.Text = "";
                        _flag = true;
                        Operand = 'x';
                    }
                    break;
                case "backspace":
                    if(Output != null && Output != "")
                    {
                        if (Output[Output.Length - 1] == '.')
                            _flag = true;
                        Output = Output.Remove(Output.Length - 1);
                        outputTextBlock.Text = Output;
                    }
                    break;
            }
        }

        private void mainWindow_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            if (mainWindow.Height < 530)
            {
                myBorder.Margin = new Thickness(0, 0, 0, 10);
                outputStackPanel.Height = 50;
                outputTextBlock.Margin = new Thickness(0);
                outputTextBlock.Padding = new Thickness(0);
                outputTextBlock.Height = 40;
            }
        }
    }
}
