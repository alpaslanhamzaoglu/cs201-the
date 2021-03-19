// Alpaslan Hamzaoglu

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "strutils.h"

using namespace std;


void file_vector(vector<string> & pokemon_vec, vector<string> & attacks_vec, vector<string> & types_vec)
{
	string attacks_txt = "attacks.txt", pokemon_txt = "pokemon.txt", types_txt = "types.txt", pok_name, pok_type, pok_att1, pok_att2, attack_name, damage, energy, type1, type2;
	ifstream file1, file2, file3;
	
	file1.open(pokemon_txt.c_str());
	file2.open(attacks_txt.c_str());
	file3.open(types_txt.c_str());

	while (file1 >> pok_name >> pok_type >> pok_att1 >> pok_att2)
	{
		pokemon_vec.push_back(pok_name);
		pokemon_vec.push_back(pok_type);
		pokemon_vec.push_back(pok_att1);
		pokemon_vec.push_back(pok_att2);
	}

	while (file2 >> attack_name >> damage >> energy)
	{
		attacks_vec.push_back(attack_name);
		attacks_vec.push_back(damage);
		attacks_vec.push_back(energy);
	}

	while (file3 >> type1 >> type2)
	{
		types_vec.push_back(type1);
		types_vec.push_back(type2);
	}

	file1.close();
	file2.close();
	file3.close();
}


bool check_pokemonname(vector<string>pokemon_vec, string pokemon)
{
	for (int i = 0; i < pokemon_vec.size(); i++)
	{
		if (pokemon_vec[i] == pokemon)
		{
			return true;
		}
	}

	return false;
}


void check_choice(string & choice)
{
	cout << "Which move do you choose? ";
	cin >> choice;

	while (choice != "1" && choice != "2")
	{
		cout << "There's no such move! Please choose again: ";
		cin >> choice;
	}
}


void menu_index(int & index, int & index2, int & index3, int & ind, int & ind2, int & ind3, vector<string>pokemon_vec, vector<string>attacks_vec, string pokemon1, string pokemon2)
{

	for (int i = 0; i < pokemon_vec.size(); i++)
	{
		if (pokemon_vec[i] == pokemon1)
		{
			index = i;
		}

		if (pokemon_vec[i] == pokemon2)
		{
			ind = i;
		}
	}
	
	for (int i = 0; i < attacks_vec.size(); i++)
	{
		if (attacks_vec[i] == pokemon_vec[index+2])
		{
			index2 = i;
		}

		if (attacks_vec[i] == pokemon_vec[index+3])
		{
			index3 = i;
		}

		if (attacks_vec[i] == pokemon_vec[ind+2])
		{
			ind2 = i;
		}

		if (attacks_vec[i] == pokemon_vec[ind+3])
		{
			ind3 = i;
		}
	}	
}


void type_bool(vector<string>types_vec, string type1, string type2, bool & ty1, bool & ty2)
{
	for (int i = 0; i < types_vec.size(); i++)
	{
		if (types_vec[i] == type1)
		{
			if (types_vec[i+1] == type2)
			{
				ty1 = true;
			}
		}

		if (types_vec[i] == type2)
		{
			if (types_vec[i+1] == type1)
			{
				ty2 = true;
			}
		}
	}
}


void menu(vector<string>pokemon_vec, vector<string>attacks_vec, vector<string>types_vec, string pokemon1, string pokemon2)
{
	int health1 = 100, health2 = 100, index, index2, index3, ind, ind2, ind3, energy1, energy2, energy3, energy4, sum, sum2;
	string choice, type1, type2;
	bool ty1 = false, ty2 = false;

	menu_index(index, index2, index3, ind, ind2, ind3, pokemon_vec, attacks_vec, pokemon1, pokemon2);

	type1 = pokemon_vec[index+1];
	type2 = pokemon_vec[ind+1];

	type_bool(types_vec, type1, type2, ty1, ty2);

	energy1 = atoi(attacks_vec[index2+2]);
	energy2 = atoi(attacks_vec[index3+2]);
	energy3 = atoi(attacks_vec[ind2+2]);
	energy4 = atoi(attacks_vec[ind3+2]);

	do 
	{
		cout << "Player 1's turn! " << pokemon1 << " has the following stats:" << endl;
		cout << "Health: " << health1 << endl;
		cout << "Attacks: " << endl;
		cout << "1. " << pokemon_vec[index+2] << " Damage: " << atoi(attacks_vec[index2+1]) << " Energy: " << energy1 << endl;
		cout << "2. " << pokemon_vec[index+3] << " Damage: " << atoi(attacks_vec[index3+1]) << " Energy: " << energy2 << endl;

		check_choice(choice);

		if (choice == "1")
		{
			if (energy1 == 0)
			{
				cout << "This move has no energy left! Please choose another move: ";
				cin >> choice;

				while (choice != "1" && choice != "2")
				{
					cout << "There's no such move! Please choose again: ";
					cin >> choice;
				}
			}

			else
			{
				energy1--;

				if (ty1 == true)
				{
					cout << pokemon1 << "'s move is super effective!" << endl;

					health2 -= (atoi(attacks_vec[index2+1])) * 2;
				}

				else
				{
					health2 -= atoi(attacks_vec[index2+1]);
				}
			}
			
		}

		if (choice == "2")
		{
			if (energy2 == 0)
			{
				while (choice == "2")
				{
					cout << "This move has no energy left! Please choose another move: ";
					cin >> choice;
				}

				while (choice != "1" && choice != "2")
				{
					cout << "There's no such move! Please choose again: ";
					cin >> choice;
				}

				if (choice == "1")
				{
					if (energy1 == 0)
					{
						cout << "This move has no energy left! Please choose another move: ";
						cin >> choice;

						while (choice != "1" && choice != "2")
						{
							cout << "There's no such move! Please choose again: ";
							cin >> choice;
						}
					}

					else
					{
						energy1--;

						if (ty1 == true)
						{
							cout << pokemon1 << "'s move is super effective!" << endl;

							health2 -= (atoi(attacks_vec[index2+1])) * 2;
						}

						else
						{
							health2 -= atoi(attacks_vec[index2+1]);
						}
					}
				}
			}

			else
			{
				energy2--;

				if (ty1 == true)
				{
					cout << pokemon1 << "'s move is super effective!" << endl;

					health2 -= (atoi(attacks_vec[index3+1])) * 2;
				}

				else
				{
					health2 -= atoi(attacks_vec[index3+1]);
				}
			}
			
		}

		cout << "Player 2 now has " << health2 << " health." << endl;
		cout << endl;

		sum = energy1 + energy2;

		if (sum == 0 || health2 <= 0)
		{
			break;
		}

		cout << "Player 2's turn! " << pokemon2 << " has the following stats:" << endl;
		cout << "Health: " << health2 << endl;
		cout << "Attacks: " << endl;
		cout << "1. " << pokemon_vec[ind+2] << " Damage: " << atoi(attacks_vec[ind2+1]) << " Energy: " << energy3 << endl;
		cout << "2. " << pokemon_vec[ind+3] << " Damage: " << atoi(attacks_vec[ind3+1]) << " Energy: " << energy4 << endl;

		check_choice(choice);

		if (choice == "1")
		{
			if (energy3 == 0)
			{
				cout << "This move has no energy left! Please choose another move: ";
				cin >> choice;

				while (choice != "1" && choice != "2")
				{
					cout << "There's no such move! Please choose again: ";
					cin >> choice;
				}
			}

			else
			{
				energy3--;

				if (ty2 == true)
				{
					cout << pokemon2 << "'s move is super effective!" << endl;

					health1 -= (atoi(attacks_vec[ind2+1])) * 2;
				}

				else
				{
					health1 -= atoi(attacks_vec[ind2+1]);
				}	
			}
			
		}

		if (choice == "2")
		{
			if (energy4 == 0)
			{
				cout << "This move has no energy left! Please choose another move: ";
				cin >> choice;

				while (choice == "2")
				{
					cout << "This move has no energy left! Please choose another move: ";
					cin >> choice;
				}

				while (choice != "1" && choice != "2")
				{
					cout << "There's no such move! Please choose again: ";
					cin >> choice;
				}

				if (choice == "1")
				{
					if (energy3 == 0)
					{
						cout << "This move has no energy left! Please choose another move: ";
						cin >> choice;

						while (choice != "1" && choice != "2")
						{
							cout << "There's no such move! Please choose again: ";
							cin >> choice;
						}
					}

					else
					{
						energy3--;

						if (ty2 == true)
						{
							cout << pokemon2 << "'s move is super effective!" << endl;

							health1 -= (atoi(attacks_vec[ind2+1])) * 2;
						}

						else
						{
							health1 -= atoi(attacks_vec[ind2+1]);
						}	
					}
				}

			}

			else
			{
				energy4--;

				if (ty2 == true)
				{
					cout << pokemon2 << "'s move is super effective!" << endl;

					health1 -= (atoi(attacks_vec[ind3+1])) * 2;
				}

				else
				{
					health1 -= atoi(attacks_vec[ind3+1]);
				}	
			}
			
		}

		cout << "Player 1 now has " << health1 << " health." << endl;
		cout << endl;

		sum2 = energy3 + energy4;
			
	} while (health1 > 0 && health2 > 0 && sum2 != 0);

	if (health2 <= 0)
	{
		cout << "Player 1 won with " << pokemon1 << "!" << endl;
	}

	else if (sum == 0)
	{
		cout << "Player 1 has no energy left!" << endl;
		cout << "Player 2 won with " << pokemon2 << "!" << endl;
	}

	else if (health1 <= 0)
	{
		cout << "Player 2 won with " << pokemon2 << "!" << endl;
	}

	else if (sum2 == 0)
	{
		cout << "Player 2 has no energy left!" << endl;
		cout << "Player 1 won with " << pokemon1 << "!" << endl;
	}
}


int main()
{
	vector<string>pokemon_vec;
	vector<string>attacks_vec;
	vector<string>types_vec;
	string pokemon1, pokemon2, pokemon;

	file_vector(pokemon_vec, attacks_vec, types_vec);

	do
	{
		cout << "Player 1, please choose a Pokemon: ";
		cin >> pokemon;

		if (check_pokemonname(pokemon_vec, pokemon) == false)
		{
			cout << "There's no Pokemon called " << pokemon <<". Please enter again." << endl;
		}

	} while (check_pokemonname(pokemon_vec, pokemon) == false);

	pokemon1 = pokemon;

	cout << "You chose " << pokemon << "!" << endl;
	cout << endl;

	do
	{
		cout << "Player 2, please choose a Pokemon: ";
		cin >> pokemon;

		if (check_pokemonname(pokemon_vec, pokemon) == false)
		{
			cout << "There's no Pokemon called " << pokemon <<". Please enter again." << endl;
		}

	} while (check_pokemonname(pokemon_vec, pokemon) == false);

	pokemon2 = pokemon;

	cout << "You chose " << pokemon << "!" << endl;
	cout << endl;

	menu(pokemon_vec, attacks_vec, types_vec, pokemon1, pokemon2);

	return 0;
}