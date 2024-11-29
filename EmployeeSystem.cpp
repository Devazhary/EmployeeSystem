#include <iostream>
using namespace std;

struct stEmployee
{
	string name;
	int age;
	int salary;
	char gender;
};

struct stEmpSystem
{
	stEmployee EmployeeList[100];
	int Repeated = 0;
};

stEmployee GetInfo()
{
	stEmployee Info;
	cout << "\nEnter Name: ";
	cin >> Info.name;
	cout << "Enter Age: ";
	cin >> Info.age;
	cout << "Enter salary: ";
	cin >> Info.salary;
	cout << "Enter Gender (M/F): ";
	cin >> Info.gender;
	cout << "_______________________________\n";
	return Info;
}

void addEmployee(stEmpSystem& EmpSys)
{
	EmpSys.EmployeeList[EmpSys.Repeated] = GetInfo();
	EmpSys.Repeated++;
}

void PrintEmployee(stEmpSystem& EmpSys)
{
	for (int i = 0; i < EmpSys.Repeated; i++)
	{
		cout << "\n";
		cout << EmpSys.EmployeeList[i].name << "  " << EmpSys.EmployeeList[i].age << "  " << EmpSys.EmployeeList[i].salary << "  " << EmpSys.EmployeeList[i].gender << endl;
		cout << "_______________________________\n";
	}
}

int UpdateSalaryByName(stEmpSystem& stEmp)
{
	string Name;
	int sal;

	cout << "Enter The Name: ";
	cin >> Name;
	cout << "Enter The new salary: ";
	cin >> sal;
	for (int i = 0; i < stEmp.Repeated; i++)
	{
		if (stEmp.EmployeeList[i].name == Name)
		{
			stEmp.EmployeeList[i].salary = sal;
			return 1;
		}
	}
	return -1;
}

int GetIndex(stEmpSystem EmpSys)
{
	int initValue, finValue;
	cout << "\nEnter init age: ";
	cin >> initValue;
	cout << "Enter final age: ";
	cin >> finValue;

	for (int i = 0; i < EmpSys.Repeated; i++)
	{
		if (EmpSys.EmployeeList[i].age > initValue && EmpSys.EmployeeList[i].age < finValue)
		{
			return i;
		}
	}
}

void DeleteByAge(stEmpSystem& EmpSys)
{
	for (int i= GetIndex(EmpSys); i < EmpSys.Repeated ; i++)
	{
		EmpSys.EmployeeList[i] = EmpSys.EmployeeList[i + 1];
	}
	EmpSys.Repeated--;
}

void DisplayScreen()
{
	int Choice;
	stEmpSystem EmpSystem;

	do
	{
		cout << "Enter Your Choice: " << endl;
		cout << "1) Add new employee\n";
		cout << "2) Print all employee\n";
		cout << "3) Delete by age\n";
		cout << "4) Update Salary by name\n";
		cout << "5) Exit\n";

		cin >> Choice;

		if (Choice == 1)
		{
			addEmployee(EmpSystem);
		}
		else if (Choice == 2)
		{
			PrintEmployee(EmpSystem);
		}
		else if (Choice == 3)
		{
			DeleteByAge(EmpSystem);
		}
		else if (Choice == 4)
		{
			if (UpdateSalaryByName(EmpSystem) == -1)
			{
				cout << "No, Employee with this name\n";
			}
		}

	} while (Choice != 5);

}

int main()
{
	DisplayScreen();
	return 0;
}