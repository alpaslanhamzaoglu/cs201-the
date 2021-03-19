//Alpaslan Hamzaoglu

#include <iostream>
#include <string> 
#include "strutils.h"

using namespace std;


bool check_partyname(string party)
{
	if (47 < party[0] && party[0] < 58)
	{
		return false;
	}

	for (int i = 0; i < party.length(); i++)
	{
		if (party[i] < 47)
		{
			return false;
		}

		else if (57 < party[i] && party[i] < 65)
		{
			return false;
		}

		else if (90 < party[i] && party[i] < 97)
		{
			return false;
		}

		else if (122 < party[i])
		{
			return false;
		}
	}

	return true;
}


void party_name(string & party1, string & party2, string & party3)
{	
	cout << "Please enter the name of the 1st party: ";	
	cin >> party1;

	while (check_partyname(party1) == false)
	{
		cout << "Invalid party name. Please enter again: ";
		cin >> party1;
	}

	ToLower(party1);

	cout << "Please enter the name of the 2nd party: ";
	cin >> party2;

	while (check_partyname(party2) == false)
	{
		cout << "Invalid party name. Please enter again: ";
		cin >> party2;
	}

	ToLower(party2);

	while (party1 == party2)
	{
		cout << "Party1 already exists. Please enter again: ";
		cin >> party2;

		ToLower(party2);
	}

	cout << "Please enter the name of the 3rd party: ";
	cin >> party3;

	while (check_partyname(party3) == false)
	{
		cout << "Invalid party name. Please enter again: ";
		cin >> party3;
	}

	ToLower(party3);

	while (party1 == party3 || party2 == party3)
	{
		if (party1 == party3)
		{
			cout << "Party1 already exists. Please enter again: ";
			cin >> party3;

			ToLower(party3);
		}
		
		if (party2 == party3)
		{
			cout << "Party2 already exists. Please enter again: ";
			cin >> party3;

			ToLower(party3);
		}
	}

	ToLower(party3);
	
	party1[0] = toupper(party1[0]);
	party2[0] = toupper(party2[0]);
	party3[0] = toupper(party3[0]);
}


bool check_cityname(string city)
{
	for (int i = 0; i < city.length(); i++)
	{
		if (city[i] < 57)
		{
			return false;
		}

		else if (57 < city[i] && city[i] < 65)
		{
			return false;
		}

		else if (90 < city[i] && city[i] < 97)
		{
			return false;
		}

		else if (122 < city[i])
		{
			return false;
		}
	}

	return true;
}


void atoi(string result, double & num1, double & num2, double & num3, double & max)
{
	num1 = atof(result.substr(0, result.find("-")));
	result = result.substr(result.find("-")+1, result.length()-1);
	num2 = atof(result.substr(0, result.find("-")));
	result = result.substr(result.find("-")+1, result.length()-1);
	num3 = atof(result.substr(0, result.length()));

	max = num1;

	if (num2 > max)
	{
		max = num2;
	}

	if (num3 > max) 
	{
		max = num3;
	}
}


bool check_result(string result)
{
	int count = 0, num1, num2, num3;

	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] == '-')
		{
			if (result[i+1] == '-')
			{
				return false;
			}

			count += 1;
		}

		if (result[i] < 45 || result[i] == 47)
		{
			return false;
		}

		else if (57 < result[i])
		{
			return false;
		}
	}

	if (count != 2)
	{
		return false;
	}

	num1 = atof(result.substr(0, result.find("-")));
	result = result.substr(result.find("-")+1, result.length()-1);
	num2 = atof(result.substr(0, result.find("-")));
	result = result.substr(result.find("-")+1, result.length()-1);
	num3 = atof(result.substr(0, result.length()));

	if (num1 + num2 + num3 > 100.0)
	{
		return false;
	}

	return true;
}


bool check_option(string option, int & number)
{
	for (int i = 0; i < option.length(); i++)
	{
		if (option[i] < 49)
		{
			return false;
		}

		else if (52 < option[i])
		{
			return false;
		}
	}

	number = atoi(option.substr(0));

	return true;
}


void option3(string cityname_list, string result_list, string result, string city, string party1, string party2, string party3, double & num1, double & num2, double & num3, double & max)
{
	if (cityname_list == "")
			{
				cout << "No information available yet..." << endl;
			}

			else
			{
				for (int i = 0; i < cityname_list.length(); i++)
				{
					int a = cityname_list.find("/");
					city = cityname_list.substr(0, a);
					cityname_list = cityname_list.substr(a+1, cityname_list.length());

					int b = result_list.find("/");
					result = result_list.substr(0, b);
					result_list = result_list.substr(b+1, result_list.length());

					atoi(result, num1, num2, num3, max);

					city[0] = toupper(city[0]);

					if (max == num1 && num1 != num2 && num2 != num3)
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party1 << " is leading" << endl;	
					}

					else if (max == num2 && num1 != num2 && num2 != num3)
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party2 << " is leading" << endl;
					}

					else if (max == num3 && num1 != num2 && num2 != num3)
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party3 << " is leading" << endl;
					}

					else if (max == num1 && num1 == num2 && num2 != num3)
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party1 << ", " << party2 << " are leading" << endl;
					}

					else if (max == num2 && num2 == num3 && num1 != num3)
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party2 << ", " << party3 << " are leading" << endl;
					}

					else if (max == num1 && num1 == num3 && num2 != num1 )
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party1 << ", " << party3 << " are leading" << endl;
					}

					else if (num1 == num2 && num2 == num3)
					{
						cout << city << " " << num1 << " " << num2 << " " << num3 << " --> " << party1 << ", " << party2 << ", " << party3 << " are leading" << endl;
					}
				}
			}
}


void console()
{
	int number;
	double num1, num2, num3, max;
	string city, result, party1, party2, party3, option, cityname_list = "", result_list = "";

	party_name(party1, party2, party3);

	do
	{
		cout << endl;
		cout << "Menu:" << endl;
		cout << "1. Enter results for a new city." << endl;
		cout << "2. Change results of a specific city." << endl;
		cout << "3. Show current results." << endl;
		cout << "4. Exit." << endl;

		cout << endl;

		cout << "Select one of the options (1-4): ";
		cin >> option;

		while (check_option(option, number) == false)
		{
			cout << "You have entered an invalid input for menu selection. Please enter again: " ;
			cin >> option;
		}

		if (number == 1)
		{
			cout << "Please enter the name of the city: ";
			cin >> city;
			
			while (check_cityname(city) == false)
			{
				cout << "Invalid city name. Please enter again: ";
				cin >> city;
			}

			ToLower(city);

			int bul = cityname_list.find(city) + city.length();
			 
			if (cityname_list.find(city) != string::npos && cityname_list[bul] == '/')
			{
				ToLower(city);
				city[0] = toupper(city[0]);

				cout << "You cannot enter " << city << " since this city has already been entered. If you want you can update the results of this city by using the 2nd menu option.";
				cout << endl;
			}

			else
			{
				ToLower(city);

				cityname_list.append(city);
				cityname_list.append("/");
				city[0] = toupper(city[0]);

				cout << "Please enter results for " << city << ": ";
				cin >> result;

				while (check_result(result) == false)
				{
					cout << "Wrong format for city results. Please enter again: ";
					cin >> result;
				}

				result_list.append(result);
				result_list.append("/");
			}
		}

		else if (number == 2)
		{
			cout << "Please enter the name of the city to be objected: ";
			cin >> city;

			ToLower(city);

			int bul = cityname_list.find(city) + city.length();

			if (cityname_list.find(city) == string::npos || cityname_list[bul] != '/')
			{
				city[0] = toupper(city[0]);
				cout << "You cannot change the result of " << city << " since no result has been entered for this city yet." << endl;
			} 

			else
			{
				city[0] = toupper(city[0]);

				cout << "Please enter results for " << city << ": ";
				cin >> result;
				
				while (check_result(result) == false)
				{
					cout << "Wrong format for city results. Please enter again: ";
					cin >> result;
				}

				ToLower(city);
				int a = cityname_list.find(city);
				string new_list = cityname_list.substr(0, a);
				int count = 0, count2 = 0;

				for (int i = 0; i < new_list.length(); i++)
				{
					if (new_list[i] == '/')
					{
						count++;
					}
				}

				for (int i = 0; i < result_list.length(); i++)
				{
					if (result_list[i] == '/')
					{
						count2++;
					}

					if (count2 == count)
					{
						if (count == 0)
						{
							string part1 = result_list.substr(0, i);
							result_list = result_list.substr(i+1, result_list.length());
							int slash = result_list.find("/");
							string part3 = result_list.substr(slash+1, result_list.length());
							string part2 = result_list.substr(0, slash);
							part2 = result + "/";
							result_list = part1 + part2 + part3;			
						}

						else
						{
							string part1 = result_list.substr(0, i+1);
							result_list = result_list.substr(i+1, result_list.length());
							int slash = result_list.find("/");
							string part3 = result_list.substr(slash+1, result_list.length());
							string part2 = result_list.substr(0, slash);
							part2 = result + "/";
							result_list = part1 + part2 + part3;
						}

						break;
					}
					
				}
			}
		}

		else if (number == 3)
		{
			option3(cityname_list, result_list, result, city, party1, party2, party3, num1, num2, num3, max);
		}

	} while (number != 4);
		 		
	cout << "**************" << endl;
	cout << "Terminating, good bye dear citizen!!! Do not forget to vote in elections :)" << endl;
}


int main()
{
	cout << "Welcome to this virtual local elections C++ program." << endl;
	cout << endl;

	console();

	return 0;
}