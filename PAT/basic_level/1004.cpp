#include <iostream>

using namespace std;

struct Student
{
	string name;
	string sno;
	int grade;
	Student(int grade):grade(grade){}
};

int main() 
{
	int n = 0;
	cin >> n;
	
	Student maxGradeStudent(-1);
	Student minGradeStudent(101);

	while (n--)
	{
		string name, sno;
		int grade;
		cin >> name >> sno >> grade;
		
		if(grade > maxGradeStudent.grade)
		{
			maxGradeStudent.name = name;
			maxGradeStudent.sno = sno;
			maxGradeStudent.grade = grade;
		}

		if (grade < minGradeStudent.grade)
		{
			minGradeStudent.name = name;
			minGradeStudent.sno = sno;
			minGradeStudent.grade = grade;
		}
	}

	cout << maxGradeStudent.name << ' ' << maxGradeStudent.sno << endl;
	cout << minGradeStudent.name << ' ' << minGradeStudent.sno << endl;
}