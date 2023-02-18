#include <bits/stdc++.h>
using namespace std;
class Employee
{
private:
public:
	string name;
	string role;
	int salary;
	int attendance;
	Employee(string name, string role, int salary, int attendance)
		: name(name), role(role), salary(salary), attendance(attendance) {}

	string getName() const { return name; }
	void setName(string name) { this->name = name; }

	string getRole() const { return role; }
	void setRole(string role) { this->role = role; }

	int getSalary() const { return salary; }
	void setSalary(int salary) { this->salary = salary; }

	int getAttendance() const { return attendance; }
	void setAttendance(int attendance) { this->attendance = attendance; }
};

void addEmployee(vector<Employee> &employees)
{
	string name, role;
	int salary, attendance;
	cout << "Enter employee name: ";
	cin >> name;
	cout << "Enter employee role: ";
	cin >> role;
	cout << "Enter employee salary: ";
	cin >> salary;
	cout << "Enter employee attendance (within last 30 days): ";
	cin >> attendance;
	Employee emp(name, role, salary, attendance);
	employees.push_back(emp);

	// write to file
	ofstream outfile("employees.txt", ios::app);
	if (outfile.is_open())
	{
		outfile << emp.name << " " << emp.role << " " << emp.salary << " " << emp.attendance << endl;
		outfile.close();
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}

void displayEmployeeList(vector<Employee> &employees)
{
	cout << "\n\n==========================================================================" << endl;
	cout << "                          Employee List                              " << endl;
	cout << "==========================================================================" << endl;
	cout << setw(15) << left << "| Name" << setw(15) << left << "| Role" << setw(15) << left << "| Salary" << setw(18) << left << "|  Attendance               |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	for (auto &emp : employees)
	{
		cout << "| " << setw(13) << left << emp.name << "| " << setw(13) << left << emp.role << "| " << setw(13) << left << emp.salary << "| " << (emp.attendance * 100) / 30 << "%                       |" << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl;

	cout << "--------------------------------------------------------------------------" << endl;
}

// update employee functions
void updateEmployee(vector<Employee> &employees)
{
	string name;
	cout << "Enter the name of the employee you want to update: ";
	cin >> name;

	bool found = false;
	for (auto &emp : employees)
	{
		if (emp.getName() == name)
		{
			found = true;
			int choice;
			cout << "What do you want to update for " << emp.getName() << "?" << endl;
			cout << "1. Name" << endl;
			cout << "2. Role" << endl;
			cout << "3. Salary" << endl;
			cout << "4. Attendance" << endl;
			cin >> choice;

			if (choice == 1)
			{
				string new_name;
				cout << "Enter new name: ";
				cin >> new_name;
				emp.setName(new_name);
				break;
			}
			else if (choice == 2)
			{
				string new_role;
				cout << "Enter new role: ";
				cin >> new_role;
				emp.setRole(new_role);
				break;
			}
			else if (choice == 3)
			{
				int new_salary;
				cout << "Enter new salary: ";
				cin >> new_salary;
				emp.setSalary(new_salary);
				break;
			}

			else if (choice == 4)
			{
				int new_attendance;
				cout << "Enter new attendance: ";
				cin >> new_attendance;
				emp.setAttendance(new_attendance);
				break;
			}
			else
			{
				cout << "Invalid choice! Please try again." << endl;
			}
		}
	}

	// update file
	ofstream outfile("employees.txt");
	if (outfile.is_open())
	{
		for (auto &emp : employees)
		{
			outfile << emp.getName() << " " << emp.getRole() << " " << emp.getSalary() << " " << emp.getAttendance() << endl;
		}
		outfile.close();
		cout << "Employee record updated successfully!" << endl;
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	if (!found)
	{
		cout << "Employee not found!" << endl;
	}
}

bool validateLogin(const string &username, const string &password)
{
	// Check if the username and password match some predefined values
	const string validUsername = "Twahanur";
	const string validPassword = "1234";
	return (username == validUsername && password == validPassword);
}

int main()
{
	while (true)
	{
		string username, password;
		cout << "Please enter your username and password to login.\n";
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

		if (!validateLogin(username, password))
		{
			cout << "Invalid username or password. Exiting program." << endl;
			continue;
		}
		else
			break;
	}

	cout << "\t%%      %%      ";
	cout << "\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
	cout << "\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
	cout << "\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
	cout << "\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
	cout << "\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
	cout << "\n\n\t\t\t        $$$$$$$$  $$$$$        ";
	cout << "\n\t\t\t           $$     $   $      ";
	cout << "\n\t\t\t           $$     $$$$$    ";

	cout << "\n\n\n\t\t  (******** Emoloyee MANAGEMENT SYSTEM *******)";
	cout << "\n\n\t\t       BY:";
	cout << "\n\n\t\t\t  Twahanur Rahman";
	cout << "\n\n\t\t\t\t ID:11220120771";
	vector<Employee> employees;
	ifstream infile("employees.txt");
	if (infile.is_open())

	{
		string name, role;
		int salary, attendance;
		while (infile >> name >> role >> salary >> attendance)
		{
			Employee emp(name, role, salary, attendance);
			employees.push_back(emp);
		}
		infile.close();
	}
	else
	{
		cout << "Error opening file!" << endl;
		return 1;
	}

	int choice;
	do
	{
		cout << "\n\nChoose an option: " << endl;
		cout << "1. Add Employee" << endl;
		cout << "2. Display Employee List" << endl;
		cout << "3. Update Employee" << endl;
		cout << "4. log Out" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addEmployee(employees);
			break;
		case 2:
			displayEmployeeList(employees);
			break;
		case 3:
		{
			updateEmployee(employees);
			break;
		}
		case 4:
			cout << "system Log Out successfully";
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 4);

	return 0;
}
