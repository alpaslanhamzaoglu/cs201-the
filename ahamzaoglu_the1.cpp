// Alpaslan Hamzaoglu

#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string name;
	double midterm_grade, final_exam_grade, home_exam1, home_exam2, home_exam3, home_exam4, weighted_exam_avr, ratio, take_home_avr, quiz1, quiz2, quiz3, quiz4, course_numeric_grade, min, quiz_grade; 

	cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
	cin >> name;

	cout << "Hello " << name << ", what are your midterm and final exam grades? ";
	cin >> midterm_grade >> final_exam_grade;

	weighted_exam_avr = ((0.33 * midterm_grade) + (0.37 * final_exam_grade)) / 0.7;

	if (weighted_exam_avr > 30.0) 
	{
		cout << "What are the grades of your 4 take-home exams? ";
		cin >> home_exam1 >> home_exam2 >> home_exam3 >> home_exam4;

		take_home_avr = (home_exam1 + home_exam2 + home_exam3 + home_exam4) / 4.0;
		ratio = take_home_avr / weighted_exam_avr;

		if (ratio <= 2.0)
		{
			cout << "You'll get all the points earned from take-home exams!" << endl; 
			
		}
		
		else if (2.0 < ratio && ratio < 3.0)
		{
			take_home_avr *= (3.0 - ratio);
			cout << "You'll get " << take_home_avr << " from the points earned from take-home exams!" << endl;
		}

		else
		{
			cout << "You'll get NONE of the points earned from take-home exams!" << endl;
			take_home_avr = 0;
		}

		cout << "What are the grades of your 4 recitation quizzes? ";
		cin >> quiz1 >> quiz2 >> quiz3 >> quiz4;

		min = quiz1;
		if (quiz2 < min)
		{
			min = quiz2;
		}

		if (quiz3 < min) 
		{
			min = quiz3;
		}

		if (quiz4 < min) 
		{
			min = quiz4;
		}
		
		quiz_grade = ((quiz1 + quiz2 + quiz3 + quiz4) - min) / 3.0;
		course_numeric_grade = (quiz_grade * 0.15) + (take_home_avr * 0.15) + (midterm_grade * 0.33) + (final_exam_grade * 0.37);

		cout << "" << endl;
		cout << name << ", your grade for CS201 is: " << course_numeric_grade << endl;
	}

	else
	{
		cout << name << ", your weighted exam average is less than 30, you will fail the course!" << endl;
	}
	return 0;
}