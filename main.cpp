/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Pizza Parlor
 * Author: mxw13
 *
 * Created on April 8, 2016, 5:34 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
int cheeseQuantity = 200;
int pepperoniQuantity = 100;
int mushroomQuantity = 100;
int onionsQuantity = 100;
int sausageQuantity = 100;
int hamburgerQuantity = 100;
int baconBitsQuantity = 100;
int blackOlivesQuantity = 100;
int greenPeppersQuantity =100;
int pineappleQuantity = 50;

int thinCrustQuantity = 100;
int flatbreadQuantity = 100;
int thinckCrustQuantity = 100;

const int PERSONAL_PAN_SIZE = 6;
const int SMALL_SIZE = 6;
const int MEDIUM_SIZE = 8;
const int LARGE_SIZE = 10;
const int EXTRA_LARGE_SIZE = 10;
const int NY_STYLE_SIZE = 12;

const double PERSONAL_PAN_PRICE = 10.00;
const double SMALL_PRICE = 10.00;
const double MEDIUM_PRICE = 12.00;
const double LARGE_PRICE = 14.00;
const double EXTRA_LARGE_PRICE = 14.00;
const double NY_STYLE_PRICE = 16.00;

double orderTotal = 0.00;
double totalRevenue = 0.00;



void showMenu();

int addPizza(string &pizzaName, int &pizzaPrice);
string addCrust();
string addToppings();
int addGuests(int servingSize, string pizzaName);

void showTotal(string pizzaName, string crust, string toppings, int numberOfGuests, int pizzaPrice);
void showItemizedTotal(string pizzaName, string crust, string toppings, int pizzaPrice);
void showQOHTotals();

int main() {
    string pizzaName = " ";
    int pizzaPrice = 0;
    int pizzaChoice = 0;
    string crust;
    string toppings;
    int numberOfGuests = 0;
    char orderMore;
    for(int i = 1;i <= 4;i++){
                
        pizzaChoice = addPizza(pizzaName, pizzaPrice);
        crust = addCrust();
        toppings = addToppings();
        numberOfGuests = addGuests(pizzaChoice, pizzaName);
        showTotal(pizzaName, crust, toppings, numberOfGuests, pizzaPrice);
        
        cout << "Would you like to order another pizza? You have "<< 
                (4-i) <<" Pizzas remaining" << endl << "(Y = Yes N = No)\n";
        
        cin >> orderMore;
        
        totalRevenue+=orderTotal;
        
        if(orderMore == 'n'){
            cout << "Thank you for eating at the Pizza Parlor! Please come again soon!\n";
            cout << "My total revenue for the night was $" << totalRevenue;
            showQOHTotals();
            break;
        }
        
        orderTotal = 0;
    }
    return 0;
}

    int addPizza(string &pizzaName, int &pizzaPrice){
        int pizzaChoice = 0;
        
        cout << "Welcome to Pizza Parlor, please enter a number from 1 to 6 to indicate the size pizza you want";
        
        cin >> pizzaChoice;
        
        
        switch(pizzaChoice){
            case 1: 
                pizzaName = "personal pan";
                pizzaPrice = PERSONAL_PAN_PRICE;
                orderTotal+=PERSONAL_PAN_PRICE;
                cout << "You have chosen to order a  Personal Pan pizza. This will feed " 
                << PERSONAL_PAN_SIZE <<" people";
                break;
            case 2: 
                pizzaName = "small";
                pizzaPrice = SMALL_PRICE;
                orderTotal+=SMALL_PRICE;
                cout << "You have chosen to order a smMll pizza. This will feed " 
                << SMALL_SIZE <<" people";
                break;
            case 3: 
                pizzaName = "medium";
                pizzaPrice = MEDIUM_PRICE;
                orderTotal+=MEDIUM_PRICE;
                cout << "You have chosen to order a ______. This will feed " 
                << MEDIUM_SIZE <<" people";
                break;
            case 4: 
                pizzaName = "";
                pizzaPrice = LARGE_PRICE;
                orderTotal+=LARGE_PRICE;
                cout << "You have chosen to order a _______. This will feed " 
                << LARGE_SIZE <<" people";
                break;
            case 5: 
                pizzaName = "";
                pizzaPrice = EXTRA_LARGE_PRICE;
                orderTotal+=EXTRA_LARGE_PRICE;
                cout << "You have chosen to order a _______. This will feed " 
                << EXTRA_LARGE_SIZE <<" people";
                break;
            case 6: 
                pizzaName = "";
                pizzaPrice = NY_STYLE_PRICE;
                orderTotal+=NY_STYLE_PRICE;
                cout << "You have chosen to order a ______. This will feed " 
                << NY_STYLE_SIZE <<" people";
                break;
            default:
                pizzaName = "NONE";
                pizzaPrice = 0;
                cout << "No pizza.....OK" << endl;
               // addPizza(" ");
        }
        return pizzaChoice;
    }
    
    string addCrust(){
        int crust = 0;
        string crustName;
        cout << "Please enter a number from 1 to 3 to indicate the type of crust you want."
                << endl;
        cin >> crust;
        
        switch(crust){
            case 1:
                cout << "You have chosen ______  as your crust" << endl;
                crustName = "Thin Crust";
                break;
            case 2:
                cout << "You have chosen ______  as your crust" << endl;
                crustName = "Flatbread Crust";
                break;
                cout << "You have chosen ______  as your crust" << endl;
            case 3:
                cout << "You have chosen ______  as your crust" << endl;
                crustName = "Thick Crust";
                orderTotal+= 2.00;
                break;
            default:
                cout << "No crust.....OK" << endl;
                crustName = "";
                addCrust();
        }
        return crustName;
    }
    
    string addToppings(){
        int toppings = 0;
        char addMore = 'y';
        string listOfToppings;
    do {
        
        cout << "Please enter a number from 1 to 10 to indicate what toppings you would like on your pizza" 
                << endl;
        
        cin >> toppings;
        
      

            switch(toppings){
                case 1:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Cheese\t$NC\n";
                    break;
                case 2:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Pepperoni\t$NC\n";
                    break;
                case 3:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Mushroom\t$1.00\n";
                    orderTotal+=1.00;
                    break;
                case 4:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Onions\t$1.00\n";
                    orderTotal+=1.00;
                    break;
                case 5:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "";
                    break;
                case 6:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "";
                    break;
                case 7:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "";
                    orderTotal+=1.00;
                    break;
                case 8:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "";
                    break;
                case 9:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "";
                    break;
                case 10:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "";
                    orderTotal+=1.00;
                    break;

                default:
                    cout << "Wrong!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    addToppings();
            }
            
            cin >> addMore;
        
        } while(addMore == 'y');    
        return listOfToppings;
    }

    int addGuests(int numberOfSlices, string pizzaName){
        int guests = 0;
        
        do {
            cout << "Please enter the number of guests you have in your party" << endl;


            
            cin >> guests;

            switch(numberOfSlices){
                case 1: 
                    numberOfSlices = PERSONAL_PAN_SIZE;
                    break;
                case 2: 
                    numberOfSlices = SMALL_SIZE;
                    break;
                case 3: 
                    numberOfSlices = MEDIUM_SIZE;
                    break;
                case 4: 
                    numberOfSlices = LARGE_SIZE;
                    break;
                case 5: 
                    numberOfSlices = EXTRA_LARGE_SIZE;
                    break;
                case 6: 
                   numberOfSlices = NY_STYLE_SIZE;
                    break;
                default:
                    addGuests(6, pizzaName);        
            }

            if(guests > numberOfSlices){
                cout << "I am sorry you must enter a number less than "
                        << numberOfSlices << " for a " << pizzaName << " pizza.";            
            }
            
        }while(guests > numberOfSlices);
        return guests;
    }
    
    void showTotal(string pizzaName, string crust, string toppings, int numberOfGuests, int pizzaPrice){
        char showItems;
        cout << "Great your total for today’s order at the Pizza Parlor was $" << orderTotal << endl;
        cout << "Would you like an itemized list of your order? (Y = Yes N = No)" << endl;
        cin >> showItems;
        
        if(showItems == 'y'){
            showItemizedTotal(pizzaName, crust, toppings, pizzaPrice);
        }
        
         cout << "The total cost for each of your " <<  numberOfGuests << "guests will be "
                 << "$"<< (orderTotal / numberOfGuests) << endl;
         
         
    }

    void showItemizedTotal(string pizzaName, string crust, string toppings, int pizzaPrice){
        cout << "Great your itemized total for your order was as follows:" << endl;
        
        cout << pizzaName << "\t"<<"$"<< pizzaPrice << endl;
        cout << toppings;
        cout << "Total Cost\t $" << orderTotal;
    } 
    
    void showQOHTotals(){
        
    }