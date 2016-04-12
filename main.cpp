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





void showMenu();

int addPizza(string &pizzaName);
void addCrust();
void addToppings();
void addGuests(int servingSize, string pizzaName);

void showTotal();
void showItemizedTotal();
void showQOHTotals();

int main() {
    string pizzaName = " ";
    int pizzaChoice = 0;
    for(int i = 0;i < 4;i++){
                
        pizzaChoice = addPizza(pizzaName);
        addCrust();
        addToppings();
        addGuests(pizzaChoice, pizzaName);
        showTotal();
        
    }
    

    return 0;
}

    int addPizza(string &pizzaName){
        int pizzaChoice = 0;
        
        cout << "Welcome to Pizza Parlor, please enter a number from 1 to 6 to indicate the size pizza you want";
        
        cin >> pizzaChoice;
        
        
        switch(pizzaChoice){
            case 1: 
                pizzaName = "Personal Pan";
                cout << "You have chosen to order a  Personal Pan pizza. This will feed " 
                << PERSONAL_PAN_SIZE <<" people";
                break;
            case 2: 
                pizzaName = "small";
                cout << "You have chosen to order a samll pizza. This will feed " 
                << SMALL_SIZE <<" people";
                break;
            case 3: 
                pizzaName = "medium";
                cout << "You have chosen to order a ______. This will feed " 
                << MEDIUM_SIZE <<" people";
                break;
            case 4: 
                pizzaName = "";
                cout << "You have chosen to order a _______. This will feed " 
                << LARGE_SIZE <<" people";
                break;
            case 5: 
                pizzaName = "";
                cout << "You have chosen to order a _______. This will feed " 
                << EXTRA_LARGE_SIZE <<" people";
                break;
            case 6: 
                pizzaName = "";
                cout << "You have chosen to order a ______. This will feed " 
                << NY_STYLE_SIZE <<" people";
                break;
            default:
                pizzaName = "NONE";
                cout << "No pizza.....OK" << endl;
               // addPizza(" ");
        }
        return pizzaChoice;
    }
    
    void addCrust(){
        int crust = 0;
        cout << "Please enter a number from 1 to 3 to indicate the type of crust you want."
                << endl;
        cin >> crust;
        
        switch(crust){
            case 1:
                cout << "You have chosen ______  as your crust" << endl;
                break;
            case 2:
                cout << "You have chosen ______  as your crust" << endl;
                break;
                cout << "You have chosen ______  as your crust" << endl;
            case 3:
                cout << "You have chosen ______  as your crust" << endl;
                break;
            default:
                cout << "No crust.....OK" << endl;
                addCrust();
        }
    }
    
    void addToppings(){
        int toppings = 0;
        char addMore = 'y';
        cout << "Please enter a number from 1 to 10 to indicate what toppings you would like on your pizza" 
                << endl;
        
        cin >> toppings;
        
        do {

            switch(toppings){
                case 1:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 2:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 3:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 4:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 5:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 6:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 7:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 8:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 9:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;
                case 10:
                    cout << "You have added _____ to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    break;

                default:
                    cout << "Wrong!!!!!!!!!!!!!!!!!!!!!!" << endl;
                    addToppings();
            }
            
            cin >> addMore;
        
        } while(addMore == 'y');        
    }

    void addGuests(int numberOfSlices, string pizzaName){
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
    }
    
    void showTotal(){
     
        //showQOHTotals()
    }
