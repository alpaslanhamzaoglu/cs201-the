// Alpaslan Hamzaoglu

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "strutils.h"


using namespace std;


struct SuperMarket  
{
	string name;
	int quantity;
	int price;
};


struct MarketList  
{
	string list_name;
	int list_quantity;
	int list_price;
};


void files(vector<SuperMarket> & vec)
{
	vector<string> lines;
	vector<string> lines2;
	bool txt_name = false;
	string stock_file, price_file, market_file, list_file, line, line2;
	ifstream file_stock, file_price, file_market, file_list;
	SuperMarket buy;

	cout << "Please enter the name of the stock file: ";
	cin >> list_file;

	while (list_file != "list.txt" && list_file != "stocks.txt")
	{
		cout << "File failed to open!" << endl;
		cout << "Please enter the name of the stock file: ";
		cin >> list_file;
	}

	cout << "Please enter the name of the price file: " ;
	cin >> price_file;
	
	while (txt_name == false)
	{
		if (list_file == "list.txt")
		{
			if (price_file != "prices.txt")
			{
				txt_name = false;
				cout << "File failed to open!" << endl;
				cout << "Please enter the name of the price file: " ;
				cin >> price_file;
			}

			else if (price_file == "prices.txt")
			{
				txt_name = true;
			}
		}
		
		else if (list_file == "stocks.txt")
		{
			if (price_file != "market.txt")
			{
				txt_name = false;
				cout << "File failed to open!" << endl;
				cout << "Please enter the name of the price file: " ;
				cin >> price_file;
			}

			else if (price_file == "market.txt")
			{
				txt_name = true;
			}
		}
	}

	file_list.open(list_file.c_str());
	file_price.open(price_file.c_str());

	while (getline(file_list, line))
	{
		ToUpper(line);
		lines.push_back(line);
	}

	while (getline(file_price, line2))
	{
		ToUpper(line2);
		lines2.push_back(line2);
	}

	file_list.close();
	file_price.close();
	
	for (int i = 0; i < lines.size(); i++)
	{
		int a = lines[i].find(";");
		buy.name = lines[i].substr(0, a);
		buy.quantity = atoi(lines[i].substr(a+1, lines[i].length()-1));
		buy.price = 0;
		vec.push_back(buy);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[i].name == vec[j].name)
			{
				vec[i].quantity += vec[j].quantity;
				vec.erase(vec.begin() + j);

				break;
			}
		}
	}

	for (int i = 0; i < lines2.size(); i++)
	{
		int a = lines2[i].find(";");	

		for (int j = 0; j < vec.size(); j++)
		{
			if (lines2[i].substr(0, a) == vec[j].name)
			{
				vec[j].price = atoi(lines2[i].substr(a+1, lines2[i].length()-1));
				break;
			}
		}
	}
}


void menu()
{
	cout << "---" << endl;
	cout << "MENU" << endl;
	cout << "1. Add item to the shopping cart" << endl;
	cout << "2. Delete item from the shopping cart" << endl;
	cout << "3. Print the shopping cart" << endl;
	cout << "4. Print the shopping cart in reverse order" << endl;
	cout << "5. Show total estimated cost of the cart" << endl;
	cout << "6. Exit" << endl;
	cout << "---" << endl;
}


void option_1(vector<SuperMarket> & vec, vector<MarketList> & vec2)
{
	string str;
	int i = 0, j = 0, quantity_1, k = 0;
	bool check_1 = true;
	MarketList list;
	
	cout << "Please enter the item name and quantity: ";
	cin.ignore();
	getline(cin, str);

	int a = str.length()-1;

	for (; a >= 0; a--)
	{
		if (str[a] == ' ')
		{
			break;
		}
	}

	quantity_1 = atoi(str.substr(a+1, str.length()-1));
	str = str.substr(0, a);
	ToUpper(str);
	
	for (; i < vec.size(); i++)
	{
		if (vec[i].name == str)
		{
			check_1 = true;
			break;
		}

		else
		{
			check_1 = false;
		}
	}

	if (check_1 == true)
	{
		for (; j <= vec2.size(); j++)
		{
			int h = 0;
			bool chk = false;

			for (; h < vec2.size(); h++)
			{
				if (vec2[h].list_name == str)
				{
					chk = true;
					break;
				}
			}

			if (vec2.empty())
			{
				list.list_name = vec[i].name;
				list.list_price = vec[i].price;
				list.list_quantity = 0;
				vec2.push_back(list);

				break;
			}

			else if (chk == true)
			{
				break;
			}

			else if (vec2[j].list_name != vec[i].name)
			{
				list.list_name = vec[i].name;
				list.list_price = vec[i].price;
				list.list_quantity = 0;
				vec2.push_back(list);

				break;
			}
		}

		for (; k < vec.size(); k++)
		{
			if (vec2[k].list_name == vec[i].name)
			{
				break;
			}
		}

		if (vec[i].quantity == 0)
		{
			cout << "None left in the market." << endl;
		}

		else if (vec[i].quantity < quantity_1)
		{
			cout << "Only " << vec[i].quantity << " left in the market. Adding all to your cart!" << endl;
			cout << "Added " << str << " with " << vec[i].quantity << " quantity to your cart." << endl;

			quantity_1 = vec[i].quantity;
			vec2[k].list_quantity += quantity_1;
			vec[i].quantity = 0;
		}

		else if (vec[i].quantity >= quantity_1)
		{
			cout << "Added " << str << " with " << quantity_1 << " quantity to your cart." << endl; 

			vec2[k].list_quantity += quantity_1;
			vec[i].quantity -= quantity_1;
		}
	}
	
	else
	{
		cout << "There is no such item in the market!" << endl;
	}
}


void option_2(vector<SuperMarket> & vec, vector<MarketList> & vec2)
{
	bool check = false;
	string str;
	int quantity, i = 0, j = 0;

	if (!vec2.empty())
	{
		cout << "Please enter the item name and quantity: ";
		cin.ignore();
		getline(cin, str);

		int a = str.length()-1;

		for (; a >= 0; a--)
		{
			if (str[a] == ' ')
			{
				break;
			}
		}

		quantity = atoi(str.substr(a+1, str.length()-1));
		str = str.substr(0, a);
		ToUpper(str);
	
		for (; i < vec.size(); i++)
		{
			if (vec[i].name == str)
			{
				break;
			}
		}

		for (; j < vec2.size(); j++)
		{
			if (str == vec2[j].list_name)
			{
				check = true;
				break;
			}
		}

		if (check == true)
		{
			if (quantity == vec2[j].list_quantity)
			{
				cout << "Removed all " << str	<< " from your cart." << endl;

				vec2.erase(vec2.begin() + j);
				vec[i].quantity += quantity;
			}

			else if (quantity < vec2[j].list_quantity)
			{
				cout << "Removed " << str << " with quantity " << quantity << " from your cart." << endl;

				vec2[j].list_quantity -= quantity;
				vec[i].quantity += quantity;
			}

			else if (quantity > vec2[j].list_quantity)
			{
				cout << "You have only " << vec2[j].list_quantity << " " << vec2[j].list_name << " in your cart. Removing all from your cart!" << endl; 

				vec2.erase(vec2.begin() + j);
				vec[i].quantity += vec2[j].list_quantity;
			}
		}

		else
		{
			cout << "There is no such item in your shopping cart!" << endl;
		}
	}

	else
	{
		cout << "Your shopping cart is empty!" << endl;
	}
}


void option_3(vector<SuperMarket> & vec, vector<MarketList> & vec2)
{
	if (!vec2.empty())
	{
		int j, k, max, size = vec2.size()-1;
		MarketList temp;

		for (k = 0; k < size; k++)
		{
			MarketList temp;
			max = k;

			for (j = k+1; j <= size; j++)
			{
				if ((vec2[j].list_price * vec2[j].list_quantity) == (vec2[max].list_price * vec2[max].list_quantity))
				{
					if (vec2[j].list_name[0] > vec2[max].list_name[0])
					{
						max = k;
					}

					else if (vec2[j].list_name[0] < vec2[max].list_name[0])
					{
						max = j;
					}
				}

				else if ((vec2[j].list_price * vec2[j].list_quantity) > (vec2[max].list_price * vec2[max].list_quantity))
				{
					max = j;
				}
			}

			temp = vec2[k];
			vec2[k] = vec2[max];
			vec2[max] = temp;
		}

		for (int i = 0; i < vec2.size(); i++)
		{
			cout << vec2[i].list_name << " " << vec2[i].list_quantity << " " << vec2[i].list_price << endl;
		}
	}

	else
	{
		cout << "Your shopping cart is empty!" << endl; 
	}
}


void option_4(vector<MarketList> & vec2)
{
	if (!vec2.empty())
	{
		int j, k, max, size = vec2.size()-1;
		MarketList temp;

		for (k = 0; k < size; k++)
		{
			MarketList temp;
			max = k;

			for (j = k+1; j <= size; j++)
			{
				if ((vec2[j].list_price * vec2[j].list_quantity) == (vec2[max].list_price * vec2[max].list_quantity))
				{
					if (vec2[j].list_name[0] > vec2[max].list_name[0])
					{
						max = k;
					}

					else if (vec2[j].list_name[0] < vec2[max].list_name[0])
					{
						max = j;
					}
				}

				else if ((vec2[j].list_price * vec2[j].list_quantity) > (vec2[max].list_price * vec2[max].list_quantity))
				{
					max = j;
				}
			}

			temp = vec2[k];
			vec2[k] = vec2[max];
			vec2[max] = temp;
		}

		for (int i = vec2.size()-1; i >= 0; i--)
		{
			cout << vec2[i].list_name << " " << vec2[i].list_quantity << " " << vec2[i].list_price << endl;
		}
	}

	else
	{
		cout << "Your shopping cart is empty!" << endl; 
	}
}


void option_5(const vector<MarketList> & vec2)
{
	if (!vec2.empty())
	{
		int sum = 0, i = 0;

		for (; i < vec2.size(); i++)
		{
			sum += (vec2[i].list_quantity * vec2[i].list_price);
		}

		cout << "The total cost of " << i << " kinds of items is: " << sum << endl;
	}

	else
	{
		cout << "Your shopping cart is empty!" << endl;
	}
}


int main()
{
	vector<SuperMarket> vec;
	vector<MarketList> vec2;
	string option;
	
	files(vec);

	do 
	{
		menu();

		cout << "Enter your choice: ";
		cin >> option;

		while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6")
		{
			cout << "---" << endl;
			cout << "This is not a valid option!" << endl;
			
			menu();

			cout << "Enter your choice: ";
			cin >> option;
		}

		cout << "---" << endl;

		if (option == "1")
		{
			option_1(vec, vec2);
		}

		else if (option == "2")
		{
			option_2(vec, vec2);
		}

		else if (option == "3")
		{
			option_3(vec, vec2);
		}

		else if (option == "4")
		{
			option_4(vec2);
		}

		else if (option == "5")
		{
			option_5(vec2);
		}

		else 
		{
			cout << "Your order has been completed!" << endl;
		}
		
	} while (option != "6");

	return 0;
}