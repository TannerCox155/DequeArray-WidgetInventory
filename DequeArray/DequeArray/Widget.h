#if !defined WIDGET_H
#define WIDGET_H

class Widget {
private:
	double cost; //double value used to hold the cost of a widget
public:
	//Pre: Widget object is created and passed a double as its parameter
	//Post: Cost is set to the value passed by the user
	Widget(double value);
	//Pre: Destructor
	//Post: Not used
	~Widget();
	//Pre: Widget object is created
	//Post: returns value held in cost
	double getCost();
};
#endif
