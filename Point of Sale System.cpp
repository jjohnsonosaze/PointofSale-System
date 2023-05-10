#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Product class to store the details of all products in Group 3 Stores -------
class Product {
private:
    string name;
    double price;
public:
    Product(string _name, double _price) {
        name = _name;
        price = _price;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
};

// Point of Sale class to handle the transactions initiated by the customer
// In Group 3 Stores
class PointOfSale {
private:
    Product products[5] = { Product("Sure deodorant spray for men", 1300), Product("Rexona deodorant spray", 900), Product("Canned Tiger beer", 200), Product("Maryland cookies", 500), Product("Hair closure", 2500) };
    int itemCounts[5] = { 0, 0, 0, 0, 0 };
    double totalAmount = 0;
public:
    void displayProducts() {
        cout << "Products Available:" << endl;
        cout << "---------------------" << endl;

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << setw(30) << left << products[i].getName() << "N" << fixed << setprecision(2) << products[i].getPrice() << endl;
        }

        cout << endl;
    }
    void processTransaction() {
        int productIndex, quantity;

        do {
            // Display the products available in Group 3 Stores
            displayProducts();

            // Allow the user to select a product among available products in Group 3 Stores
            cout << "Select a product (1-5, 0 to exit): ";
            cin >> productIndex;

            if (productIndex > 0 && productIndex <= 5) {
                // Ask the user to enter the quantity of the selected product in Group 3;Stores
                cout << "Enter quantity: ";
                cin >> quantity;

                // Update the total amount and item count for the selected product
                totalAmount += products[productIndex - 1].getPrice() * quantity;
                itemCounts[productIndex - 1] += quantity;

                // Display a message indicating that the product (s) has been added to the cart
                cout << quantity << " " << products[productIndex - 1].getName() << " added to cart." << endl;
            }
        } while (productIndex != 0);

        // Display the receipt of item (s) selected  for the customer at Group 3 Stores
        cout << endl;
        cout << "Receipt:" << endl;
        cout << "--------" << endl;

        for (int i = 0; i < 5; i++) {
            if (itemCounts[i] > 0) {
                cout << itemCounts[i] << " " << products[i].getName() << " - N" << fixed << setprecision(2) << products[i].getPrice() * itemCounts[i] << endl;
            }
        }

        cout << endl;
        cout << "Total: N" << fixed << setprecision(2) << totalAmount << endl;
    }
};

// Main function to run the program
int main() {
    PointOfSale pos;

    // Process the transaction
    pos.processTransaction();

    return 0;
}
