#include <iostream>
#include <map>

using namespace std;

map<string, map<string, double>> items;
map<pair<int, int>, string> names;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void fillItems()
{
    items["Electronics"]["Apple"] = 100000;
    items["Electronics"]["Digital Camera"] = 150000;
    items["Electronics"]["Earphones"] = 1500;
    items["Electronics"]["HP"] = 50000;
    items["Electronics"]["LCD TV"] = 35000;
    items["Electronics"]["Lenovo"] = 38000;
    items["Electronics"]["Macbook"] = 250000;
    items["Electronics"]["Printers"] = 40000;
    items["Electronics"]["Redmi"] = 12000;
    items["Electronics"]["Samsung"] = 15000;
    items["Electronics"]["Smart Watch"] = 2000;
    items["Electronics"]["Tablet"] = 45000;

    items["Footware"]["Kolhapuri"] = 1800;
    items["Footware"]["Loafers"] = 1200;
    items["Footware"]["Puma Sneaker V2"] = 3499;
    items["Footware"]["Shoes"] = 2000;
    items["Footware"]["Slippers"] = 500;
    items["Footware"]["Sparx"] = 1500;

    items["Clothing"]["Blazer"] = 3500;
    items["Clothing"]["Casual TShirt"] = 799;
    items["Clothing"]["Hoodie"] = 1800;
    items["Clothing"]["Jacket"] = 1500;
    items["Clothing"]["Jeans"] = 2500;
    items["Clothing"]["Levi's shirt"] = 800;
    items["Clothing"]["Men's Dryflex"] = 2999;
    items["Clothing"]["Men's Solid Jacket"] = 2239;
    items["Clothing"]["Shirt"] = 1499;
    items["Clothing"]["US Polo TShirt"] = 999;

    names[{1, 1}] = "Apple";
    names[{1, 2}] = "Camera";
    names[{1, 3}] = "Earphones";
    names[{1, 4}] = "HP";
    names[{1, 5}] = "LCD TV";
    names[{1, 6}] = "Lenovo";
    names[{1, 7}] = "Macbook";
    names[{1, 8}] = "Printers";
    names[{1, 9}] = "Redmi";
    names[{1, 10}] = "Samsung";
    names[{1, 11}] = "Smart Watch";
    names[{1, 12}] = "Tablet";

    names[{2, 1}] = "Kolhapuri";
    names[{2, 2}] = "Loafers";
    names[{2, 3}] = "Sneaker";
    names[{2, 4}] = "Shoes";
    names[{2, 5}] = "Slippers";
    names[{2, 6}] = "Sparx";

    names[{3, 1}] = "Blazer";
    names[{3, 2}] = "TShirt";
    names[{3, 3}] = "Hoodie";
    names[{3, 4}] = "Jacket";
    names[{3, 5}] = "Jeans";
    names[{3, 6}] = "Levi's shirt";
    names[{3, 7}] = "Men's Dryflex";
    names[{3, 8}] = "Men's Solid Jacket";
    names[{3, 9}] = "Shirt";
    names[{3, 10}] = "US Polo TShirt";
}

class customer
{
    map<string, map<string, int>> selected_items;

    string name;
    string customer_name;
    long long customer_phone;
    string customer_address;

public:
    customer()
    {
        cout << "Enter customer name: ";
        getline(cin, customer_name);
        cout << "\nEnter customer address: ";
        getline(cin, customer_address);
        cout << "\nEnter customer mobile number: ";
        cin >> customer_phone;

        name = customer_name;
        cout << GREEN << "\nWelcome ";
        for (int i = 0; i < customer_name.length(); i++)
        {
            cout << char(toupper(customer_name[i]));
        }
        cout << "\n\n\n"
             << RESET;
    }

    void addToCart(string category, string model, int quantity)
    {
        selected_items[category][model] += quantity;
    }

    void printBill()
    {
        cout << GREEN << "\n-------------------------------------------------------------\n";
        cout << GREEN << "\n\t\t\tShopping Mall\n";
        cout << GREEN << "\n-------------------------------------------------------------\n\n";
        cout << GREEN << "Customer Name: " << customer_name;
        cout << GREEN << "\t\tPhone: " << customer_phone;
        cout << GREEN << "\n-------------------------------------------------------------\n\n";
        int total_amount = 0;
        cout << "\nCategory\t\t"
             << "Item\t\t"
             << "Quantity\t"
             << "Cost\n";

        for (const auto &category : selected_items)
        {
            for (const auto &item : category.second)
            {
                string model = item.first;
                int quantity = item.second;
                int temp = quantity * items[category.first][model];
                cout << "\n"
                     << category.first << "\t\t" << model << "\t\t"
                     << quantity << "\t\t" << temp << endl;
                total_amount += temp;
            }
        }

        cout << "-------------------------------------------------------------\n";
        cout << "Total amount:\t"
             << total_amount << endl;
        cout << "-------------------------------------------------------------\n";
        cout << "\t\t***\tTHANK YOU && VISIT AGAIN\t***" << RESET;
    }
};

class shop
{
public:
    shop() {}

    virtual void show() {}
    virtual void select(customer &obj) {}

    void showMenu()
    {
        cout << YELLOW << "\n\t\t\tMENU" << RESET;
        cout << YELLOW << "\n------------------------------------------------------\n"
             << RESET;
        cout << YELLOW << "\t1. Electronics \n\t2. Footware \n\t3. Clothings \n\t4. Checkout\n"
             << RESET;
        cout << YELLOW << "\n------------------------------------------------------\n"
             << RESET;
    }
};

class electronics : public shop
{
public:
    void show()
    {
        cout << "- - - - - - - - - - -"
             << " - -\nSr.\tItem ---------- Cost\n";
        int cnt = 1;
        for (const auto &it : items["Electronics"])
        {
            cout << cnt++ << "\t " << YELLOW << it.first << "----------" << RED << " Rs."
                 << it.second << "/-\n"
                 << RESET;
        }

        cout << "- - - - - - - - - - - - -\n\n";
    }

    void select(customer &obj)
    {
        cout << "These are the smartphone categories we "
                "have....\n";
        int num, quantity;
        cout << "Enter your selection\n";
        cin >> num;
        if (num < 1 || num > 12)
        {
            cout << "Correct Input\n";
            return;
        }
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "\n\nPURCHASE SUCCESSFULL!! ";
        cout << names[{1, num}]
             << " (Quantity: " << quantity << ") IS ADDED TO THE CART\n\n";
        obj.addToCart("Electronics", names[{1, num}], quantity);
    }
};

class footware : public shop
{
public:
    void show()
    {
        cout << "- - - - - - - - - - -"
             << " - -\nSr.\tItem ---------- Cost\n";
        int cnt = 1;
        for (const auto &it : items["Footware"])
        {
            cout << cnt++ << "\t " << YELLOW << it.first << "----------" << RED << " Rs."
                 << it.second << "/-\n"
                 << RESET;
        }

        cout << "- - - - - - - - - - - - -\n\n";
    }

    void select(customer &obj)
    {
        cout << "These are the footware categories we "
                "have....\n";
        int num, quantity;
        cout << "Enter your selection\n";
        cin >> num;
        if (num < 1 || num > 6)
        {
            cout << "Wrong Input\n";
            return;
        }
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "\n\nPURCHASE SUCCESSFULL!! ";
        cout << names[{2, num}]
             << " (Quantity: " << quantity << ") IS ADDED TO THE CART\n\n";
        obj.addToCart("Footware", names[{2, num}], quantity);
    }
};

class clothing : public shop
{
public:
    void show()
    {
        cout << "- - - - - - - - - - - "
             << " - -\nSr.\tItem ---------- Cost\n";
        int cnt = 1;
        for (const auto &it : items["Clothing"])
        {
            cout << cnt++ << "\t " << YELLOW << it.first << "----------" << RED << " Rs."
                 << it.second << "/-\n"
                 << RESET;
        }

        cout << "- - - - - - - - - - - - -\n\n";
    }

    void select(customer &obj)
    {
        cout << "These are the clothings categories we "
                "have....\n";
        int num, quantity;
        cout << "Enter your selection\n";
        cin >> num;
        if (num < 1 || num > 10)
        {
            cout << "Wrong Input\n";
            return;
        }
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "\n\nPURCHASE SUCCESSFULL!! ";
        cout << names[{3, num}]
             << " (Quantity: " << quantity << ") IS ADDED TO THE CART\n\n";
        obj.addToCart("Clothing", names[{3, num}], quantity);
    }
};

int main()
{
    fillItems();
    cout << RED << "\n\n________________________\n\n"
         << RESET;
    cout << CYAN << "\t\t\tWELCOME TO OUR SHOP" << RESET;
    cout << RED << "\n\n________________________\n"
         << RESET;
    customer c;
    shop *s;

    while (1)
    {

        s->showMenu();
        cout
            << "Please select an option to proceed "
            << "further. If you choose to checkout, "
            << "shopping will end and bill will be "
            << "generated for the items bought so far...\n";
        int val;
        cin >> val;

        if (val == 1)
        {
            electronics mb;
            s = &mb;
            s->show();
            s->select(c);
        }
        else if (val == 2)
        {
            footware lp;
            s = &lp;
            s->show();
            s->select(c);
        }
        else if (val == 3)
        {
            clothing clo;
            s = &clo;
            s->show();
            s->select(c);
        }

        else if (val == 4)
        {
            c.printBill();
            break;
        }
        else
        {
            cout << "Wrong Input. If you want to checkout, "
                    "you can press 4\n\n";
        }
        cout << "REDIRECTING TO THE MAIN MENU.....\n\n";
        system("cls");
    }

    return 0;
}