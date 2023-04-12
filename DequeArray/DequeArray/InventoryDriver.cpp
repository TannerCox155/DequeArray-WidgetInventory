#include "InventoryManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

InventoryManager::InventoryManager(int inventory_choice) {

    fifoORlifo = inventory_choice;
    totalProfit = 0;
    if (fifoORlifo == 1) {
        queue = new QueueDeque<Widget>(); //fifo
    }
    else if (fifoORlifo == 2) {
        stack = new StackDeque<Widget>(); //lifo
    }
}

InventoryManager::~InventoryManager() {

}

void InventoryManager::buyWidgets(double cost, int num_to_buy) {

    for (int i = 0; i < num_to_buy; ++i) {
        Widget* w = new Widget(cost);//new widget w is created each iteration
        if (fifoORlifo == 1) {
            queue->Enqueue(w);
        }
        else if (fifoORlifo == 2) {
            stack->Push(w);
        }
    }
}

double InventoryManager::getTotalProfit() {
    return totalProfit;
}

double InventoryManager::sellWidgets(double price, int num_to_sell) {
    int accumulatedCost = 0;
    if (fifoORlifo == 1) {
        if (num_to_sell > queue->size()) {
            num_to_sell = queue->size();
        }
        for (int i = 0; i < num_to_sell; ++i) {
            accumulatedCost += queue->Peek()->getCost(); //aCost = aCost + queue->Peek(item at front)->getCost(value of item)
            queue->Dequeue();                           //^^^example iteration 0: aCost = 0 + 5(value at front), aCost = 5
        }
    }
    if (fifoORlifo == 2) {
        if (num_to_sell > stack->size()) {
            num_to_sell = stack->size();
        }
        for (int i = 0; i < num_to_sell; ++i) {
            accumulatedCost += stack->Peek()->getCost();
            stack->Pop();
        }
    }
    double profit = (price * num_to_sell) - accumulatedCost;
    totalProfit += profit; //total profit
    return profit; //return this transaction
}

///////////////////////////////////////////Menus and User Prompts Below///////////////////////////////////////////

//Pre: User is prompted to choose an inventory type
//Post: Depending on input, user will use FiFo or Lifo inventory managment. 1 or 2 will be returned indicating choice.
int inventoryChoice() {

    int fifoLifo = 0;
    do {
        //Ask the user for Inventory choice and return validated input
        cout << "Are you using (1) FIFO or (2) LIFO inventory managment? ";
        cin >> fifoLifo;
        cout << endl;
        if (fifoLifo == 1) {
            return 1;
        }
        if (fifoLifo == 2) {
            return 2;
        }
        if (fifoLifo > 2) {
            cout << "Invalid inventory choice\n" << endl;
            fifoLifo = 0;
        }

    } while (fifoLifo == 0);
}
//Pre: User is prompted for input on amount and price of widgets to be purchased
//Post: Other buy widgets function is called and user passed input to perform tasks.
void buyWidgets(InventoryManager* im) {

    int quantity;
    double price;

    cout << "How many widgets would you like to buy? ";
    cin >> quantity;
    cout << "What is the cost for each widget? ";
    cin >> price;
    cout << endl;

    im->buyWidgets(price, quantity);
}

//Pre: User must have widgets in inventory to sell. Prompt user for input on quantity to sell and price point.
//Post: Function calls the other sell widgets function to perform tasks from current inputs,
//      current transaction profit is output upon return to this function.
double sellWidgets(InventoryManager* im) {

    int quantity;
    double price;

    cout << "How many widgets would you like to sell? ";
    cin >> quantity;
    cout << "What is the selling price of each widget? ";
    cin >> price;
    cout << endl;

    cout << setprecision(2) << fixed;
    cout << "Your profit on this transaction is: $" << im->sellWidgets(price, quantity) << endl;

    return 0;
}
//Pre: User is prompted to buy, sell, or quit.
//Post: Depending on input, user is sent to buy prompt/input, or sell prompt/input. 1 is returned to keep bool ask true
bool mainMenu(InventoryManager* im) {

    int menuChoice = 0;
    do {
        cout << "1.) Buy widgets\n" << "2.) Sell widgets\n" << "3.) Quit\n" << "What would you like to do? ";
        cin >> menuChoice;
        cout << endl;
        if (menuChoice == 1) {
            buyWidgets(im);
            return 1;
        }
        else if (menuChoice == 2) {
            sellWidgets(im);
            return 1;
        }
        else if (menuChoice > 3) {
            cout << "Invalid choice\n" << endl;
        }
        else {
            return 0;
        }
    } while (menuChoice != 3);
}

int main() {

    cout << "*** P03: Widget Inventory ***\n" << endl;
    cout << setprecision(2) << fixed;

    int inv_choice = inventoryChoice(); //choose LiFo or FiFo
    InventoryManager* im = new InventoryManager(inv_choice); //choice stored

    bool ask = 1;
    while (ask) {
        ask = mainMenu(im);
    }

    double runningTotal = im->getTotalProfit();
    cout << "Your total profit for all transactions is $" << runningTotal << endl;

    delete im;
}