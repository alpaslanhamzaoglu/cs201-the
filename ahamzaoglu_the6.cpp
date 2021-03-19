// Alpaslan Hamzaoglu

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "strutils.h"
#include "student.h"

using namespace std;


void files(vector<Course>& course_info, vector<Course>& print_course)
{
	string course_txt = "courses.txt", schedule_txt = "schedule.txt";
	ifstream course, schedule1;
	vector<string> lines;
	vector<string> lines2;
	vector<int> lines2_CRN;
	int find = 0;
	Course info;
	Time info2;

	course.open(course_txt.c_str());
	schedule1.open(schedule_txt.c_str());

	if (course.fail() && schedule1.fail())
	{
		cout << "The file could not be open." << endl;
	}

	else
	{
		string line, line2;

		while (getline(course, line))
		{
			ToUpper(line);
			lines.push_back(line);
		}

		while (getline(schedule1, line2))
		{
			ToUpper(line2);
			lines2.push_back(line2);
		}
	}

	schedule1.close();
	course.close();

	for (int i = 0; i < lines2.size(); i++)  
	{
		find = lines2[i].find(" ");
		lines2_CRN.push_back(atoi(lines2[i].substr(0, find)));
	}

	for (int i = 0; i < lines.size(); i++)    
	{
		for (; i < lines[i].length(); i++)
		{
			if (lines[i][0] == ' ')
			{
				find = lines[i].find(" ");
				lines[i] = lines[i].substr(find+1, lines[i].length()-1);
			}

			else if (lines[i][0] == '\t')
			{
				find = lines[i].find('\t');
				lines[i] = lines[i].substr(find+1, lines[i].length()-1);
			}

			else
			{
				break;
			}
		}

		find = lines[i].find(' ');

		info.CRN = atoi(lines[i].substr(0, find));

		lines[i] = lines[i].substr(find+1, lines[i].length()-1);

		string a = "";

		for (int j = 0; j < lines[i].size(); j++)
		{
			if (lines[i][0] == ' ')
			{
				lines[i].erase(0, 1);
			}

			else if (lines[i][0] == '\t')
			{
				lines[i].erase(0, 1);
			}
		}

		info.name = lines[i].substr(0, lines[i].length());
		course_info.push_back(info);
		print_course.push_back(info);
	}

	for (int i = 0; i < lines2_CRN.size(); i++)  
	{
		for (int j = 0; j < course_info.size(); j++)
		{
			if (lines2_CRN[i] == course_info[j].CRN)
			{
				find = lines2[i].find(" ");
				lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);

				for (int m = 0; m < lines2[i].size(); m++)
				{
					if (lines2[i][0] == ' ')
					{
						find = lines2[i].find(" ");
						lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);
					}

					else if (lines2[i][0] == '\t')
					{
						find = lines2[i].find('\t');
						lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);
					}

					else
					{
						break;
					}
				}
			
				info2.day = lines2[i].substr(0, lines2[i].find(" "));

				find = lines2[i].find(" ");
				lines2[i] = lines2[i].substr(find, lines2[i].length()-1);
				
				for (int m = 0; m < lines2[i].size(); m++)
				{
					if (lines2[i][0] == ' ')
					{
						find = lines2[i].find(" ");
						lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);
					}

					else if (lines2[i][0] == '\t')
					{
						find = lines2[i].find('\t');
						lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);
					}

					else
					{
						break;
					}
				}

				find = lines2[i].find(":");

				info2.hour = atoi(lines2[i].substr(0, find));

				lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);

				info2.minute = atoi(lines2[i].substr(0, lines2[i].find(" ")));

				lines2[i] = lines2[i].substr(lines2[i].find(" "), lines2[i].length()-1);

				for (int m = 0; m < lines2[i].size(); m++)
				{
					if (lines2[i][0] == ' ')
					{
						find = lines2[i].find(" ");
						lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);
					}

					else if (lines2[i][0] == '\t')
					{
						find = lines2[i].find('\t');
						lines2[i] = lines2[i].substr(find+1, lines2[i].length()-1);
					}

					else
					{
						break;
					}
				}

				info2.duration = atoi(lines2[i].substr(0, lines2[i].length()));

				course_info[j].schedule.push_back(info2);
				print_course[j].schedule.push_back(info2);
			}
		}
	}
}


void option_5(vector<Course> & print_course, student student_info)
{
	student_info.displayStudentInfo();
	cout << ", here are all the courses: " << endl; 

	if (print_course.size() == 0)
	{
		cout << "There is no courses left!" << endl;
	}

	else
	{
		
		int j, min, k, size = print_course.size()-1;

		for (k = 0; k < size; k++)
		{
			Course temp;
			min = k;

			for (j = k+1; j <= size; j++)
			{
				if (print_course[j].CRN < print_course[min].CRN)
				{
					min = j;
				}
			}

			temp = print_course[k];
			print_course[k] = print_course[min];
			print_course[min] = temp;
		}

		for(int i = 0; i < print_course.size(); i++)          
		{
			if (print_course[i].schedule.size() == 1)
			{		
				cout << " " << print_course[i].CRN << " " << print_course[i].name << " " << 
				print_course[i].schedule[0].day << " " << print_course[i].schedule[0].hour << ":" << 
				print_course[i].schedule[0].minute << "-" << print_course[i].schedule[0].hour + print_course[i].schedule[0].duration << ":" <<
				print_course[i].schedule[0].minute << " " << endl;
			}

			else if (print_course[i].schedule.size() == 2)
			{		
				cout << " " << print_course[i].CRN << " " << print_course[i].name << " " << 
				print_course[i].schedule[0].day << " " << print_course[i].schedule[0].hour << ":" << 
				print_course[i].schedule[0].minute << "-" << print_course[i].schedule[0].hour + print_course[i].schedule[0].duration << ":" << 
				print_course[i].schedule[0].minute << " " << print_course[i].schedule[1].day << " " << 
				print_course[i].schedule[1].hour << ":" << print_course[i].schedule[1].minute << "-" << 
				print_course[i].schedule[1].hour + print_course[i].schedule[1].duration << ":" << print_course[i].schedule[1].minute << " " << endl;	
			}
		}

	}
}


void menu()
{
	cout << "---" << endl;
	cout << "MENU" << endl;
	cout << "1. Change student information" << endl;
	cout << "2. Add courses" << endl;
	cout << "3. Drop courses" << endl;
	cout << "4. Print your schedule" << endl;
	cout << "5. Print all available courses" << endl;
	cout << "6. Exit" << endl;
	cout << "---" << endl;
}


int main()
{
	vector<Course> course_info;
	vector<Course> print_course;
	string option, name, surname, info;
	int ID;

	files(course_info, print_course);

	cout << "Enter your name, surname, and student ID: ";
	cin >> name >> surname >> ID;

	ToUpper(name);
	ToUpper(surname);

	student student_info(name, surname, ID);

	cout << "Welcome ";
	student_info.displayStudentInfo();
	cout << " to the add/drop simulation program..." << endl;
	
	do 
	{
		menu();

		cout << "Please enter your choice: ";
		cin >> option;

		if (option == "1")
		{
			cout << "Enter your name, surname, and student ID: ";
			cin >> name >> surname >> ID;

			ToUpper(name);
			ToUpper(surname);

			student_info.changeName(name);
			student_info.changeSurname(surname);
			student_info.changeID(ID);

			cout << "Student information has been modified." << endl;
		}

		else if (option == "2")
		{
			string add_crn;

			cout << "Enter CRN for the course you want to add: ";
			cin  >> add_crn;

			student_info.addCourse(add_crn, course_info);
		}

		else if (option == "3")
		{
			if (student_info.isScheduleEmpty())
			{
				student_info.displayStudentInfo();
				cout << ", you don't have any courses." << endl; 
			}

			else
			{
				string drop_crn;

				cout << "Enter CRN for the course you want to drop: ";
				cin >> drop_crn;
				
				student_info.dropcourse(drop_crn, course_info);					
			}
		}

		else if (option == "4")
		{
			if (student_info.isScheduleEmpty())
			{
				student_info.displayStudentInfo();
				cout << ", " << "you don't have any courses." << endl; 
			}

			else
			{
				student_info.displayStudentInfo();
				cout << ", here is your schedule: " << endl;

				student_info.displaySchedule();
			}
		}

		else if (option == "5")
		{
			option_5(print_course, student_info);
		}

		else if (option == "6")
		{	
			cout << "Goodbye, ";
			student_info.displayStudentInfo();
			cout << "!" << endl;
		}

		else
		{
			cout << "Invalid option!" << endl;
		}

	} while (option != "6");

	return 0;
}