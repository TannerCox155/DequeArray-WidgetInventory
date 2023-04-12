#include "DequeArray.h"
#include "QueueDeque.h"
#include "StackDeque.h"
#include "Widget.h"

#if !defined INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

class InventoryManager {
private:
	int fifoORlifo; //1 for fifo or 2 for lifo
	double totalProfit; //tracks total profit for widgets sold
	StackDeque<Widget>* stack = nullptr; //StackDeque
	QueueDeque<Widget>* queue = nullptr; //QueueDeque
public:
	//Pre: Constructor, user passes int defining what inventory they'd like to use
	//Post: Choice is computed and a queue or stack is created to store widgets
	InventoryManager(int inventory_choice);
	//Pre: Destructor
	//Post: Not used
	~InventoryManager();

	//Pre: Price and quantity of widgets are passed as parameters by the user
	//Post: Depending on inventory choice, Widgets are added to stack or queue array
	void buyWidgets(double cost, int num_to_buy);
	//Pre: User has generated Widget(s) and sold them
	//Post: Returns the total profit of all sales made during execution
	double getTotalProfit();
	//Pre: User has Widgets in inventory and passed a price and the amount of widgets to be sold
	//Post: Widgets are removed from inventory, profit is added to total profit, current transaction is returned
	double sellWidgets(double price, int num_to_sell);
};
#endif
