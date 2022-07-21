#include <iostream>
#include <map>
#include <string>
#include<windows.h>
#include<ctime>
#include<fstream>
using namespace std;
map<string,float>inv;
map<string,float>user_input;
map<string,float>qty;
int price,invoice_number=0,tax,cash_received,balance;static float total;
string date_time;
float total_exc_taxes;
void add();
void display_inventory();
void generate_bill();
void remove_item();
float taxes(float a);
void display_invoice();
void data_to_file();
void billing(float &quantity,float &price,float &ttl,float unit_price);
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void display_record();
void user_ask();

int main()
{
    inv["Bread"] = 300;
    inv["Pastry"] = 70;
    inv["Biscuits"] = 100;
    inv["Doughnuts"] = 80;
    inv["Cake"] = 600;
    inv["Eggs"] = 400;
    inv["Sandwich"] = 100;
    inv["Milk"] = 200;
    inv["Cream Roll"] = 550;
    inv["Cookies"] = 900;
    menu:
    cout << "\t\t\t\t\t\t\t\t\tBAKERY BILLING SYSTEM " << endl;
    cout << "\t\t\t\t\t\t\t\t-------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t      MAIN MENU ";
    cout << "\n\n\n\t\t1. Display Inventory" << endl;
    cout << "\n\t\t2. Generate new Bill " << endl;
    cout << "\n\t\t3. Remove an item in inventory ";
    cout << "\n\n\t\t4. Display Bill Records ";
    cout<<"\n\n\t\t5. Exit ";

    cout<<"\nPlease select the required option : ";
    int user_choice;
    char ask_user;
    cin>>user_choice;
    
        if(user_choice==1)
        {

            display_inventory();
            do{
            cout<<"\nPRESS E to Exit or M to go back to menu : ";
            cin>>ask_user;
            ask_user=tolower(ask_user);
            }while((ask_user != 'e') && (ask_user != 'm'));
            
            if(ask_user=='m' )
            {
                goto menu;
            }
            else if( ask_user=='e')
            {
                return 0;
            }
        }   
        else if(user_choice==2)
        {
            ++invoice_number;
            generate_bill();
            if(!user_input.empty())
            {
            cout<<"Total amount payable is : "<<total;
            cout<<"\nPlease enter the amount of cash received from customer : ";
            cin>>cash_received;
            balance=cash_received-total;
            cout<<"\n Displaying final bill...";
            Sleep(1000);

            display_invoice();
            data_to_file();
            }
            if(user_input.empty())
            {
                Color(4);
                cout<<"\nNo items were added to bill \n\n";
            }
            do{
            cout<<"\nPRESS E to Exit or M to go back to menu : ";
            cin>>ask_user;
            ask_user=tolower(ask_user);
            }while((ask_user != 'e') && (ask_user != 'm'));
            
            if(ask_user=='m')
            {
                goto menu;
            }
            else if(ask_user=='e')
            {
                return 0;
            }

        
        }   
        else if(user_choice==3)
        {
            remove_item();
            do{
            cout<<"\nPRESS E to Exit or M to go back to menu : ";
            cin>>ask_user;
            ask_user=tolower(ask_user);
            }while((ask_user != 'e') && (ask_user != 'm'));
            

            
            if(ask_user=='m')
            {
                goto menu;
            }
            else if(ask_user=='e')
            {
                return 0;
            }
            
         }
        else if(user_choice==4)
        {
            display_record();
            do{
            cout<<"\nPRESS E to Exit or M to go back to menu : ";
            cin>>ask_user;
            ask_user=tolower(ask_user);
            }while((ask_user != 'e') && (ask_user != 'm'));
            

            
            if(ask_user=='m')
            {
                goto menu;
            }
            else 
            {
                return 0;
            }

         }
        else if(user_choice==5)
        {
            return 0;
        }
    else 
     {
        Color(4);
        cout<<"\nPLease enter a valid choice \n\n";
        Color(7);
        goto menu;
     }  
        
     } 

        
        
        


void display_inventory()
{

    cout << "\t\t Inventory";
    cout << "\nItems\t\t\t\t Price\n\n";

    for (auto i : inv)//i=inv.begin() to i=inv.end();i++
    {

        cout << i.first << "    \t\t\t" << i.second << endl;
    }
}

void generate_bill()
{
    qty.clear();
    user_input.clear();
    total=0;
    string not_defined;
    float quantity,price;
    display_inventory();
    cout<<"\n If the item is not available in Pre-defined inventory, Type \"NA\"";
    char condition;
    do
    { 
        string name;
        cout << "\n\n Type what you want:";
        cin.ignore();
        getline (cin, name);
        if (name == "Bread")
        {
            billing(quantity,price,total,inv["Bread"]);
            user_input.insert({"Bread",price});
            qty.insert({"Bread_q",quantity});
    
        }

        else if (name == "Pastry")
        {
            billing(quantity,price,total,inv["Pastry"]);
            user_input.insert({"Pastry",price});
            qty.insert({"Pastry_q",quantity});
        
        }
        
        else if (name == "Biscuits" )
        {
            billing(quantity,price,total,inv["Biscuits"]);
            user_input.insert({"Biscuits",price});
            qty.insert({"Biscuits_q",quantity});
    
        }

        else if (name == "Doughnuts")
        {   
            billing(quantity,price,total,inv["Doughnuts"]);
            user_input.insert({"Doughnuts",price});
            qty.insert({"Doughnuts_q",quantity});
        }
        else if (name == "Cake")
        {   
           billing(quantity,price,total,inv["Cake"]);
           user_input.insert({"Cake",price});
           qty.insert({"Cake_q",quantity});
        }
        else if (name == "Eggs")
        {   
            billing(quantity,price,total,inv["Eggs"]);
            user_input.insert({"Eggs",price});
            qty.insert({"Eggs_q",quantity});
        }
        
        else if (name == "Sandwich")
        {
            billing(quantity,price,total,inv["Sandwich"]);
            user_input.insert({"Sandwich",price});
            qty.insert({"Sandwich_q",quantity});
        }
    
        else if (name == "Milk")
        {   
            billing(quantity,price,total,inv["Milk"]);
            user_input.insert({"Milk",price});
            qty.insert({"Milk_q",quantity});
        }
        
        else if (name == "Cream Roll")
        {
            billing(quantity,price,total,inv["Cream Roll"]);
            user_input.insert({"Cream Roll",price});
            qty.insert({"Creamroll_q",quantity});
        }
    
        else if (name == "Cookies")
        {
            billing(quantity,price,total,inv["Cookies"]);
            user_input.insert({"Cookies",price});    
            qty.insert({"Cookies_q",quantity});
        }
        else if(name =="NA"||name=="na")
        {
            Color(4);
            cout<<"\n Note: Items added in NA category cannot be removed later \n\n";
            Color(7);
            cout<<"Enter the name of the new item: ";
            cin>>not_defined;
            cout<<"Enter the unit price of new item : ";
            int unit_price;cin>>unit_price;
            billing(quantity,price,total,unit_price);
            user_input.insert(pair<string,float>(not_defined,price));
            qty.insert(pair<string,float>(not_defined,quantity));
        }
        else
       {
           Color(4);
           cout<<"\nSelected Item is not available, please select an available item \n\n";
       }
        Color(7);
        do{
            cout << "Do you want to Add more items?(Y/N):";
            cin >> condition;
            condition=tolower(condition);
           }while((condition != 'y') && (condition != 'n'));

    } while (condition== 'y');

    if(!user_input.empty())
    {
        char remove;
        do
        {
        cout << "Do you want to remove an item?(Y/N) ";
        cin >> remove;
        remove=tolower(remove);
        }while((remove != 'y') && (remove != 'n'));
        while (remove == 'y')
        {
    
            cout << "\n Type what you want to remove:";
            string name;
            cin.ignore();
            getline(cin,name);
            if (user_input.count(name)==0)
            {
                Color(4);
                cout<<"This item was not added in bill previously \n";
                Color(7);
            }
            
            else
            {
                if (name == "Bread")
                {
                    total -= user_input["Bread"];
                    user_input.erase("Bread");
                    qty.erase("Bread_q");
    
                }   
                else if (name == "Pastry")
                {
                    total -=  user_input["Pastry"];
                    user_input.erase("Pastry");
                    qty.erase("Pastry_q");
                    
                }
                else if (name == "Biscuits")
                {
                    total -= user_input["Biscuits"];
                    user_input.erase("Biscuits");
                    qty.erase("Biscuits_q");
                }
                else if (name == "Doughnuts ")
                {
                    total -=  user_input["Doughnuts"];
                    user_input.erase("Doughnuts");
                    qty.erase("Doughnuts_q");
                }
                else if (name == "Cake")
                {   
                    total -=  user_input["Cake"];
                    user_input.erase("Cake"); 
                    qty.erase("Cake_q");      
                }
                else if (name == "Eggs")
                {
                    total -=  user_input["Eggs"];
                    user_input.erase("Eggs");
                    qty.erase("Eggs_q");
                }
                else if (name == "Sandwich")
                {
                    total -=  user_input["Sandwich"];
                    user_input.erase("Sandwich");
                    qty.erase("Sandwich_q");
                }
                else if (name == "Milk")
                {
                    total -=  user_input["Milk"];
                    user_input.erase("Milk");
                    qty.erase("Milk_q");
                }
                else if (name == "Cream Roll")
                {
                    total -=  user_input["Cream Roll"];
                    user_input.erase("Cream Roll");
                    qty.erase("Creamroll_q");
                }
                else if (name == "Cookies")
                {
                    total -=  user_input["Cookies"];
                    user_input.erase("Cookies");
                    qty.erase("Cookies_q");
                }
            }
            if(!user_input.empty())
            {
              
        
                char rem;
                cout << "Do you want to remove another item?(Y/N)";
                cin >> rem;
                rem=tolower(rem);
                if(rem=='n'){
                    break;
                }
                else if (rem=='y'){
                    continue;
                }
            }
            break;
        }
    }
}

void remove_item()
{
    display_inventory();
    string item;
    cout << "\n Enter the name of item: ";
    cin >> item;
    if (inv.count(item)==0)
        {
            Color(4);
            cout<<"\nThis item is not in inventory, You cannot remove it\n";
            Color(7);
        }
    else
    {
         inv.erase(item);
         display_inventory();
    }

}
float taxes(float a) 
{
   total_exc_taxes= a-(0.17*a);
   return total_exc_taxes;
}
void display_invoice()
{
    system("CLS");
    cout << "\t\t\t\t\t\t\t\t\t ABC BAKERY " << endl;
    cout << "\t\t\t\t\t\t\t\t\t CASH RECEIPT " << endl;
    cout<< "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Invoice Number = " <<invoice_number<< endl;
    time_t now=time(0);
    date_time =asctime(localtime(&now));
    cout<< "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Date and Time of purchase : "<<date_time;

    cout << "\nItem Name \t\t\t  Price\t\t\t Quantity\n\n";

    for (auto itr = user_input.begin(),i=qty.begin(); itr != user_input.end(),i!=qty.end(); ++itr,++i)
    {
        cout << itr->first << "    \t\t\t" << itr->second<< "   \t\t\t"<<i->second<<endl;
    }
    cout<<"\n\nTotal bill inclusive of taxes is : "<<total;
    cout<<"\n\nAmount of Tax : "<<0.17*total;
    cout<<"\n\nTotal bill exclusive of taxes is : "<<taxes(total);
    cout<<"\n\nCash Paid by Customer is : "<<cash_received;
    cout<<"\n\nBalance is : "<<balance;

}
void data_to_file()
{

    ofstream file;
    file.open("database.txt",ios::app);
    file<<"Order Number  : "<<invoice_number<<"\n";
    file<< "\n Date and Time of purchase : "<<date_time;
    file<<"\nTotal bill with taxes is : "<<total<<"\n";
    file<<"\nTotal bill without tax is : "<<total_exc_taxes<<"\n";
    file<<"\nTotal tax is : "<<0.17*total<<"\n";    
    file<<"***********************\n\n"   ;                              
    file.close();
}
void billing(float &quantity,float &price,float &ttl,float unit_price)
{
    cout<<"Enter the quantity : ";
    cin>>quantity;
    price=quantity*unit_price;
    ttl=ttl+price;
}
void display_record()
{
 string getcontent;
    ifstream openfile ("database.txt");
        while(! openfile.eof())
        {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }   
}
