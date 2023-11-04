#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ComputerComponent 
{
    string itemCode;
    string description;
    double price;
};

int main() 
{
    ComputerComponent components[] = 
	{
        {"A1", "Compact", 75.00},
        {"A2", "Tower", 150.00},
        {"B1", "8 GB RAM", 79.99},
        {"B2", "16 GB RAM", 149.99},
        {"B3", "32 GB RAM", 299.99},
        {"C1", "1 TB HDD", 49.99},
        {"C2", "2 TB HDD", 89.99},
        {"C3", "4 TB HDD", 129.99}
    };

    double basicSetCost = 200.00;

    string chosenCase;
    string chosenRAM;
    string chosenHDD;

    vector<ComputerComponent> additionalItems;

    cout << "Welcome to the Online Computer Shop!" << endl;
    cout << "Please choose one case, one RAM, and one Main Hard Disk Drive:" << endl;

    for (const ComputerComponent &component : components) 
	{
        cout << component.itemCode << " - " << component.description << " - $" << component.price << endl;
    }

    cout << "Choose one Case (Enter the item code): ";
    cin >> chosenCase;

    cout << "Choose one RAM (Enter the item code): ";
    cin >> chosenRAM;

    cout << "Choose one Main Hard Disk Drive (Enter the item code): ";
    cin >> chosenHDD;

    double totalCost = basicSetCost;
    for (const ComputerComponent &component : components) 
	{
        if (component.itemCode == chosenCase || component.itemCode == chosenRAM || component.itemCode == chosenHDD) 
		{
            totalCost += component.price;
        }
    }

    char purchaseAdditionalItems;
    cout << "Do you want to purchase additional items (Y/N)? ";
    cin >> purchaseAdditionalItems;

    while (purchaseAdditionalItems == 'Y' || purchaseAdditionalItems == 'y') 
	{
        cout << "Additional Items:" << endl;
        for (const ComputerComponent &component : components) 
		{
            cout << component.itemCode << " - " << component.description << " - $" << component.price << endl;
        }

        string additionalItemCode;
        cout << "Choose an additional item (Enter the item code): ";
        cin >> additionalItemCode;

        for (const ComputerComponent &component : components) 
		{
            if (component.itemCode == additionalItemCode) 
			{
                additionalItems.push_back(component);
                totalCost += component.price;
                break;
            }
        }

        cout << "Do you want to purchase more additional items (Y/N)? ";
        cin >> purchaseAdditionalItems;
    }

    double discount = 0.0;
    if (additionalItems.size() == 1) 
	{
        discount = 0.05;
    } else if (additionalItems.size() >= 2) 
	{
        discount = 0.10;
    }

    double discountAmount = totalCost * discount;
    double discountedTotalCost = totalCost - discountAmount;

    cout << "\nYour customized computer configuration:" << endl;
    cout << "Case: " << chosenCase << endl;
    cout << "RAM: " << chosenRAM << endl;
    cout << "Main Hard Disk Drive: " << chosenHDD << endl;

    if (!additionalItems.empty()) 
	{
        cout << "Additional Items:" << endl;
        for (const ComputerComponent &additionalItem : additionalItems) 
		{
            cout << additionalItem.description << " - $" << additionalItem.price << endl;
        }
    }

    cout << "Discount Applied: " << (discount * 100) << "%" << endl;
    cout << "Discount Amount: $" << discountAmount << endl;
    cout << "New Total Cost (After Discount): $" << discountedTotalCost << endl;

    return 0;
}
