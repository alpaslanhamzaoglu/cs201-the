// Alpaslan Hamzaoglu


#include <iostream>
#include <string>
#include "strutils.h"

using namespace std;


bool check(string str)
{	
	string ope = "";
	int equality = str.find("=");
	int summation = str.find("+");
	int subtraction = str.find("-");


	if (str[0] == '+' || str[0] == '-')
	{
		ope = str[0];
		str = str.substr(1, str.length()-1);

		if (str[0] == '+' || str[0] == '-')
		{
			return false;
		}

		str = ope + str;
	}


	if (subtraction != -1)
	{
		if (str[subtraction] == str[subtraction+1])
		{
			if (str[subtraction+1] == str[subtraction+2])
			{
				return false;
			}
		}
	}
	
	else if (summation != -1)
	{
		if (str[summation] == str[summation+1])
		{
			if (str[summation+1] == str[summation+2])
			{
				return false;
			}
		}
	}


	if (summation == -1)
	{
		if (subtraction > equality)
		{
			return false;
		}
	}

	else if (subtraction == -1)
	{
		if (summation > equality)
		{
			return false;
		}
	}


	if (equality == -1)
	{
		return false;
	}

	else if (subtraction == -1 && summation == -1)
	{
		return false;
	}


	for (int i = 0; i <= str.length()-1; i++)
	{
		if (str[i] <= 42 || str[i] == 44 || 61 < str[i])
		{
			return false;
		}

		else if (45 < str[i] && str[i] <= 47)
		{
			return false;
		}

		else if (57 < str[i] && str[i] <= 60)
		{
			return false;	
		}
	}
	return true;
}


bool calculation(int num1, int num2, int & num3, bool minus)
{
	if (minus == true)
	{
		if (num1 - num2 == num3)
		{
			return true;
		}

		else 
		{
			num3 = num1 - num2;
			return false;
		}
	}

	else 
	{
		if (num1 + num2 == num3)
		{
			return true;
		}

		else 
		{
			num3 = num1 + num2;
			return false;
		}
	}
}


void conversion(string str, int & num1, int & num2, int & num3, bool & minus)
{
	string ope = "";
	minus = false;

	if (str[0] == '-' || str[0] == '+')                      
	{	
		ope = str[0];
		str = str.substr(1, str.length()-1);
		int summation = str.find("+");
		int subtraction = str.find("-");

		if (summation == -1)
		{
			summation = str.length()-1;
			minus = true;
		}

		else if (subtraction == -1)
		{
			subtraction = str.length()-1;
		}
		
		if (summation < subtraction)
		{
			str = ope + str;
			num1 = atoi(str.substr(0, str[summation]));
			str = str.substr(summation+1, str.length()-1);
		}

		else 
		{
			str = ope + str;
			num1 = atoi(str.substr(0, str[subtraction]));
			str = str.substr(subtraction+1, str.length()-1);
		}
		
		ope = "";
		int equality = str.find("=");
			
		if (str[0] == '-' || str[0] == '+')
		{
			str = str.substr(1, str.length());
			num2 = atoi(str.substr(0, equality));
		}

		else 
		{
			num2 = atoi(str.substr(0, equality));
		}

		str = str.substr(equality, str.length());

		if (str[0] == '-' || str[0] == '+')
		{
			num3 = atoi(str.substr(0, str.length()));
		}

		else
		{
			num3 = atoi(str.substr(0, str.length()));
		}
		
		
	}

	else                                                            
	{
		
		int summation = str.find("+");
		int subtraction = str.find("-");

		if (summation == -1)
		{
			summation = str.length()-1;
			minus = true;
		}

		else if (subtraction == -1)
		{
			subtraction = str.length()-1;
		}
		
		if (summation < subtraction)
		{
			num1 = atoi(str.substr(0, summation+1));
			str = str.substr(summation+1, str.length()-1);
		}

		else 
		{
			num1 = atoi(str.substr(0, subtraction+1));
			str = str.substr(subtraction+1, str.length()-1);
		}
		
		ope = "";
		int equality = str.find("=");
			
		if (str[0] == '-' || str[0] == '+')
		{
			str = str.substr(0, str.length());
			num2 = atoi(str.substr(0, equality));
		}

		else 
		{
			num2 = atoi(str.substr(0, equality));
		}

		str = str.substr(equality+1, str.length());

		if (str[0] == '-' || str[0] == '+')
		{
			num3 = atoi(str.substr(0, str.length()));
		}

		else
		{
			num3 = atoi(str.substr(0, str.length()));
		}
		
	}
}


int main()
{
	string str;
	bool minus;
	int i = 1, num1, num2, num3;
	float point = 0, question_number;

	cout << "Please enter the number of questions: ";
	cin >> question_number;
	    
 	while (i <= question_number)
	{
		cout << "Please enter question #" << i << " and its answer: ";
		cin >> str;

		if (check(str) == false)
		{
			while (check(str) == false)
			{
				cout << "Wrong input format! Try again." << endl;	
				cout << "Please enter question #" << i << " and its answer: ";
				cin >> str;
			}
		}

		conversion(str, num1, num2, num3, minus);

		if (calculation(num1, num2, num3, minus) == true)
		{
			point += (100 / question_number);

			cout << "Correct answer! You have " << point << " points." << endl;
		}

		else
		{
			cout << "Wrong! The answer should have been: " << num3 << ". You have " << point << " points." << endl;
		}

		i++;
	}	

	cout << "End of the quiz. You got " << point << " points in total." << endl; 

	return 0;
}