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

//int thinCrustQuantity = 100;
//int flatbreadQuantity = 100;
//int thickCrustQuantity = 100;
int crustQuantityArray[3] = {100,100,100};

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



//void showMenu();

int addPizza(string &pizzaName, double &pizzaPrice);
string addCrust();
string addToppings();
int addGuests(int servingSize, string pizzaName);

void showTotal(string pizzaName, string crust, string toppings, int numberOfGuests, double pizzaPrice);
void showItemizedTotal(string pizzaName, string crust, string toppings, double pizzaPrice);
void showQOHTotals();

int main() {
    string pizzaName = " ";
    double pizzaPrice = 0;
    int pizzaChoice = 0;
    string crust;
    string toppings;
    int numberOfGuests = 0;
    char orderMore;
    for(int i = 1;i <= 4;i++){
               
 //int pizza choice stores the pizza selected by the user
    // addPizza’s parameters pass back (by reference) the values of the pizza name and price
        pizzaChoice = addPizza(pizzaName, pizzaPrice);
    
// stores the name of the crust in sting crust
        crust = addCrust();

// stores the toppings added by the user in string toppings
        toppings = addToppings();
    
// stores the number of guest in numberOfGuests
        numberOfGuests = addGuests(pizzaChoice, pizzaName);
    
// shows the total of the current order and takes in the values of pizzaName, crust, toppings, numberOfGuests, pizzaPrice
        showTotal(pizzaName, crust, toppings, numberOfGuests, pizzaPrice);
        
        cout << "Would you like to order another pizza? You have "<<
                (4-i) <<" Pizzas remaining" << endl << "(Y = Yes N = No)\n";

        // capture the user’s choice to order or not order more pizza
        cin >> orderMore;
       
// calculates the overall total revenue of the day's order 
        totalRevenue+=orderTotal;
        
    // if the user doesn’t order more show the total revenue and quantity on hand totals
        if(orderMore == 'n'){
            cout << "Thank you for eating at the Pizza Parlor! Please come again soon!\n";
            cout << "My total revenue for the night was $" << totalRevenue;
            showQOHTotals();
            
    // break the for loop so the program can end
break;
        }
        // reset current order’s total to 0, so that the next order has a separate total
        orderTotal = 0;
    }
    return 0;
}
    // adds a pizza to the order
    int addPizza(string &pizzaName, double &pizzaPrice){
        int pizzaChoice = 0;
        
        cout << "Welcome to Pizza Parlor, please enter a number from 1 to 6 to indicate the size pizza you want" << endl;
        // takes the user’s choice for a pizza
        cin >> pizzaChoice;
        
        // takes that choice through a switch case statement to:
    // store and pass back the pizza’s name and price;
    // add price of pizza to the current order total
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
                cout << "You have chosen to order a small pizza. This will feed "
                << SMALL_SIZE <<" people";
                break;
            case 3:
                pizzaName = "medium";
                pizzaPrice = MEDIUM_PRICE;
                orderTotal+=MEDIUM_PRICE;
                cout << "You have chosen to order a medium. This will feed "
                << MEDIUM_SIZE <<" people";
                break;
            case 4:
                pizzaName = "large";
                pizzaPrice = LARGE_PRICE;
                orderTotal+=LARGE_PRICE;
                cout << "You have chosen to order a large. This will feed "
                << LARGE_SIZE <<" people";
                break;
            case 5:
                pizzaName = "extra large";
                pizzaPrice = EXTRA_LARGE_PRICE;
                orderTotal+=EXTRA_LARGE_PRICE;
                cout << "You have chosen to order a extra large. This will feed "
                << EXTRA_LARGE_SIZE <<" people";
                break;
            case 6:
                pizzaName = "NY style";
                pizzaPrice = NY_STYLE_PRICE;
                orderTotal+=NY_STYLE_PRICE;
                cout << "You have chosen to order a NY style. This will feed "
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
    
    // adds crust to the order
    string addCrust(){
        int crust = 0;
        string crustName;
        cout << "Please enter a number from 1 to 3 to indicate the type of crust you want."
                << endl;
        // capture user’s choice of crust
cin >> crust;
        
    // takes that choice through a switch case statement to:
    // capture the name of the crust and subtract the quantity on hand for each
        switch(crust){
            case 1:
                cout << "You have chosen thin crust as your crust" << endl;
                crustName = "Thin Crust";
                crustQuantityArray[0]--;
                break;
            case 2:
                cout << "You have chosen flatbread crust as your crust" << endl;
                crustName = "Flatbread Crust";
                crustQuantityArray[1]--;
                break;
            case 3:
                cout << "You have chosen thick crust as your crust" << endl;
                crustName = "Thick Crust";
                orderTotal+= 2.00;
                crustQuantityArray[2]--;
                break;
            default:
                cout << "No crust.....OK" << endl;
                crustName = "";
                addCrust();
        }
        return crustName;
    }
    
    // adds toppings to the order
    string addToppings(){
        int toppings = 0;
        char addMore = 'y';
        string listOfToppings;

    // loops until the user enters a character that isn’t ‘y’
    do {
        
        cout << "Please enter a number from 1 to 10 to indicate what toppings you would like on your pizza" << endl;
        
    // captures user’s choice for a topping
        cin >> toppings;
        
      
    // takes that choice through a switch case statement to:
    // add a topping to a list of toppings;
    // subtract topping from quantity on hand;
    // add the price of premium toppings to current total order
            switch(toppings){
                case 1:
                    cout << "You have added cheese to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Cheese\t$NC\n";
                    cheeseQuantity--;
                    break;
                case 2:
                    cout << "You have added pepperoni to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Pepperoni\t$NC\n";
                    pepperoniQuantity--;
                    break;
                case 3:
                    cout << "You have added mushroom to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Mushroom\t$1.00\n";
                    orderTotal+=1.00;
                    mushroomQuantity--;
                    break;
                case 4:
                    cout << "You have added onions to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Onions\t$1.00\n";
                    orderTotal+=1.00;
                    break;
                case 5:
                    cout << "You have added sausage to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Sausage\t$NC\n";
                    break;
                case 6:
                    cout << "You have added hamburger to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Hamburger\t$NC\n";
                    break;
                case 7:
                    cout << "You have added bacon bits to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Bacon Bits\t$NC\n";
                    orderTotal+=1.00;
                    break;
                case 8:
                    cout << "You have added black olives to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Black Olives\t$NC\n";
                    break;
                case 9:
                    cout << "You have added green peppers to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Green Peppers\t$NC\n";
                    break;
                case 10:
                    cout << "You have added pineapple to your order. Would you like to add more toppings (Y = Yes N = N)" << endl;
                    listOfToppings+= "Pineapple\t$NC\n";
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

    // asks the 
    int addGuests(int numberOfSlices, string pizzaName){
        int guests = 0;
        
    // loop until the number of guests is less than the number of slices
        do {
            cout << "Please enter the number of guests you have in your party" << endl;


           // capture the number of guests 
            cin >> guests;

    // takes that choice through a switch case statement to:
    // capture the number of slices from the size of each pizza
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
    
    // shows the total cost of the current order
    void showTotal(string pizzaName, string crust, string toppings, int numberOfGuests, double pizzaPrice){
        char showItems;
        cout << "Great your total for today’s order at the Pizza Parlor was $" << orderTotal << endl;
        cout << "Would you like an itemized list of your order? (Y = Yes N = No)" << endl;
        // capture the users choice to show or not show an itemized total of the current order
cin >> showItems;
        
// if the user enters ‘y’ then show the itemized list by calling its function
        if(showItems == 'y'){
            showItemizedTotal(pizzaName, crust, toppings, pizzaPrice);
        }
    
        // output the price that each guest should play
         cout << "The total cost for each of your " <<  numberOfGuests << "guests will be "
                 << "$"<< (orderTotal / numberOfGuests) << endl;
         
         
    }
    
    // the function that creates the itemized list
    void showItemizedTotal(string pizzaName, string crust, string toppings, double pizzaPrice){
        cout << "Great your itemized total for your order was as follows:" << endl;
        // output the name and price of the pizza that was passed through parameter(by value) 
        cout << pizzaName << "\t"<<"$"<< pizzaPrice << endl;
    // output the list of toppings
        cout << toppings;
    // output the current order total
        cout << "Total Cost\t $" << orderTotal;
    }
        
    // outputs the quantity on hand totals
    void showQOHTotals(){
        cout << "My new QOH totals are as follows: \n\n";
        cout << "Topping QOH:\n";
        cout << "Cheese\t" << cheeseQuantity<< endl;
        cout << "Pepperoni\t" << pepperoniQuantity<< endl;
        cout << "Mushroom\t" << mushroomQuantity<< endl;
        cout << "Onions\t" << onionsQuantity<< endl;
        cout << "Sausage\t" << sausageQuantity<< endl;
        cout << "Hamburger\t" << hamburgerQuantity<< endl;
        cout << "Bacon Bits\t" << baconBitsQuantity << endl;
        cout << "Black Olives\t" << blackOlivesQuantity << endl;
        cout << "Green Peppers\t" << greenPeppersQuantity << endl;
        cout << "Pineapple\t" << pineappleQuantity<< endl;
        
        cout << "Crust QOH:\n";
        cout << "Thin\t" << crustQuantityArray[0]<< endl;
        cout << "Flatbread\t" << crustQuantityArray[1]<< endl;
        cout << "Thick\t" <<crustQuantityArray[2]<< endl;
    }

