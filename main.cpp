#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct menu_item {
string nm;
string catg;
string desc;
bool veg;
double price;
};

int count_menu(){
    string n;
    string c;
    string d;
    string v;
    string p;

    string s;
    ifstream rmenu1("menu.txt");int line_count = 0;while (!rmenu1.eof()){getline(rmenu1, s);line_count++;}
    rmenu1.close();
    return line_count/5;

}

void read_menu(menu_item * myMenu){

    string n;
    string c;
    string d;
    string v;
    string p;

    int i = 0;
    ifstream rmenu("menu.txt");

    while (!rmenu.eof()){
        getline(rmenu, n); getline(rmenu, c); getline(rmenu, d);getline(rmenu, v);getline(rmenu, p);
        //cout << n << "  " << c << "  " << d << "  " << v << "  " << p << "  " << endl;
        (myMenu[i]).nm = n; (myMenu[i]).catg = c;(myMenu[i]).desc = d;
        if (v.compare("Yes") != 0) (myMenu[i]).veg=false;
        else (myMenu[i]).veg=true;
        istringstream(p) >> (myMenu[i]).price;

        cout << i+1 << ".  " << (myMenu[i]).nm << "  " << (myMenu[i]).catg << "  " << (myMenu[i]).desc << "  " << (myMenu[i]).veg << "  " << (myMenu[i]).price << "  " << endl;
        i++;
    }
    rmenu.close();
}

void del_menu_item(menu_item* myMenu, int item_num){


}

void add_menu_item(menu_item* myMenu){
    ofstream amenu("menu.txt", ios::app);
    string nme, category, desc, vegan, price;
cout << "please enter the name, category, descpiption, whether it is vegan, and price." << endl;
cout << "press Ctrl+Z to quit." << endl;

while(cin >> nme >> category >> desc >> vegan >> price)
    amenu << nme << category << desc << vegan << price;

}

int main()
{
    //ofstream rmenu("menu.txt", ios::app );

    int menu_count = count_menu(); cout << menu_count  << endl;
    menu_item *myMenu;
    myMenu = new menu_item[menu_count];
    //vector<menu_item> myMenu;
    read_menu( myMenu);

    cout << "Please enter number of the option you would like to complete: " << endl;
    cout << "1: Add menu item." << endl;
    cout << "2: Delete menu item: " << endl;
    int cont;
    cin >> cont;
    if (cont == 1){
         void add_menu_item (menu_item* myMenu);
    }
    if (cont == 2)
    cout << "Please enter a number item to delete: " << endl;


    int del_num; cin >> del_num; cout << del_num << endl;

    ofstream dmenu("menu.txt");

    for (int j = 0; j < menu_count; j++) {

        if (j + 1 == del_num){

        }
        else{
            dmenu << myMenu[j].nm << endl;
            dmenu << myMenu[j].catg << endl;
            dmenu << myMenu[j].desc << endl;
            dmenu << myMenu[j].veg << endl;
            dmenu << myMenu[j].price << endl;
        }
    }

    dmenu.close();

    cout << "Menu item " << del_num << " is deleted.";
    //menu_count = count_menu();cout << menu_count  << endl;
    //read_menu( myMenu);

    return 0;

}
