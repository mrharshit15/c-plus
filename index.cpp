#include <iostream>
using namespace std;

// Input of data_

class employe
{
  // Data members for storing employee information 
protected:          
  string name, department, username, password;
  double basic_income;

public:
  int id;
  // function to create user passward
  void user_password()
  {
    cout << "Create Username = ";
    cin >> username;
    cout << "Create password = ";
    cin >> password;
  }
  // function to get employee info
  void get_employe_data()
  {
    cout << "Enter Employe Name = ";
    cin >> name;
    cout << "Enter Employe id = ";
    cin >> id;
    cout << "Enter Employe department = ";
    cin >> department;
    cout << "Enter Employe basic Income = ";
    cin >> basic_income;
  }
  // function to display employee info
  void show_employe_data()
  {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Department: " << department << endl;
    cout << "Basic Income: " << basic_income << endl;
  }
//function to verify login info
  string get_username()
  {
    return username;
  }
  string get_password()
  {
    return password;
  }
};

//_class to calculation of hra and da____________________

class salary : public employe
{

protected:
  double hra, da;
  double income;

public:
//function to calculate the hra and da
  void hra_da()
  {
    income = basic_income;
    hra = (income * 10) / 100;
    da = (income * 5) / 100;
    cout << "Hra = " << hra << endl;
    cout << "Da = " << da << endl;
    income = income + hra + da;
    cout << "Total income is = " << income << endl;
  }
};

// ______________________class to update info of employe_________________


class update : public salary
{
public:
  // Function to update the user's name
  void update_name(const string &new_name)
  {
    name = new_name;
    cout << "Name updated successfully!" << endl;
  }

  // Function to update the user's ID
  void update_id(int new_id)
  {
    id = new_id;
    cout << "ID updated successfully!" << endl;
  }

  // Function to update the user's department
  void update_department(const string &new_department)
  {
    department = new_department;
    cout << "Department updated successfully!" << endl;
  }

  // Function to update the user's basic income
  void update_income(double new_income)
  {
    basic_income = new_income;
    cout << "Income updated successfully!" << endl;
  }
};

// _______________________class to display leave info_________________________

class leave : public update
{

protected:
  int leave1;
  int casual_leave, sike_leave, n, m;

public:
// function to get leave type 
  void display_leave()
  {
    cout << "Press (1) for Casual leave" << endl;
    cout << "Press (2) for Sick leave" << endl;
    cout << "Press (3) for No leave" << endl;
    cin >> leave1;
  }
  // function to calculate salary deduction after leave
  void get_leave_data()
  {
    switch (leave1)
    {
    case 1:
      cout << "Enter amount of Casual leave = ";
      cin >> n;
      casual_leave = basic_income / 30;
      casual_leave = casual_leave * n;
      basic_income = basic_income - casual_leave;
      cout << " Deducted amount = " << casual_leave << endl;
      cout << "Remaining Income is = " << basic_income << endl;
      break;
    case 2:
      cout << "Enter amount of Sick leave = ";
      cin >> m;
      sike_leave = basic_income / 60;
      sike_leave = sike_leave * m;
      basic_income = basic_income - sike_leave;
      cout << "Now Currently Deducted income = " << sike_leave << endl;
      cout << "Remaining Income is = " << basic_income << endl;
      break;
    case 3:
      cout << "You will get 1 week holiday next year" << endl;
      cout << "welldone your current income is = " << basic_income << endl;
      cout << endl;
      break;
    default:
      cout << "Invalid input." << endl;
      break;
    }
  }
};
   
int main()
{
// object created of class leave
  leave obj[30];
  cout << endl
       << endl
       << "____ Employe Management System _____" << endl
       << endl;
  cout << "____ Create Your Login Id ____" << endl
       << endl;
  int n, i;
  cout << "Enter number of employe = ";
  cin >> n;

  for (i = 0; i < n; i++)
  {
    obj[i].user_password();
    obj[i].get_employe_data();
    cout << endl
         << "Employe Information Succsesfully stored" << endl
         << endl;
  }
  // for clear the screen
  system("cls");
// infinite loop until the user exit
  while (1)
  {
    int chose;   //to get input for switch contol
    string username;
    string password;
    string name;
    int id;
    string department;
    int choice;  //to get input for switch contol in case 4

    cout << "press (1) To see Employe info  " << endl;
    cout << "press (2) To delete Employe  " << endl;
    cout << "press (3) to Update Employe info  " << endl;
    cout << "press (4) for Add new Employe  " << endl;
    cout << "press (0) To End " << endl;
    cin >> chose;
    system("cls");     //  to clear the screen
    switch (chose)
    {
    case 4:              // to add new employee
      int no;
      cout << "Enter number of employee";
      cin >> no;
      for (; i < n + no; i++)
      {
        obj[i].user_password();
        obj[i].get_employe_data();
        cout << endl
             << "Employee Information Succsesfuly entered" << endl
             << endl;
      }
      break;

    case 3:                 //to update employe info
    {
      cout << "Enter the username : " << endl;
      cin >> username;
      cout << "Enter the password: " << endl;
      cin >> password;

      double basic_income;
      bool userFound = false;      //variable declaired to see weither username and passward is correct 

      for (int i = 0; i < n; i++)   // verification of employee
      {
        if (obj[i].get_username() == username && obj[i].get_password() == password)
        {
          userFound = true;
          obj[i].show_employe_data();   // function calling to show previous info
              // to get input what you want to update
          cout << "Press (1) to update Name" << endl;
          cout << "Press (2) to update Id" << endl;
          cout << "Press (3) to update Department" << endl;
          cout << "Press (4) to update Income" << endl;
          cin >> choice;
               
          switch (choice)
          {
          case 1:
          {
            cout << "Enter new name: ";
            cin >> name;
            obj[i].update_name(name);
            break;
          }
          case 2:
          {
            cout << "Enter new Id: ";
            cin >> id;
            obj[i].update_id(id);
            break;
          }
          case 3:
          {
            cout << "Enter new department: ";
            cin >> department;
            obj[i].update_department(department);
            break;
          }
          case 4:
          {
            cout << "Enter new Income: ";
            cin >> basic_income;
            obj[i].update_income(basic_income);
            break;
          }
          default:
            cout << "Invalid input" << endl;
            break;
          }
        }
      }

      if (!userFound)  // if username pasward does not match if statements gets exicuted
      {
        cout << "Invalid username or password" << endl;
      }
    }
    break;

    case 1:
    {
      cout << "Enter the username : " << endl;
      cin >> username;
      cout << "Enter the password: " << endl;
      cin >> password;
      bool userchose = false;

      for (auto &user : obj)
      {
        if (user.get_username() == username && user.get_password() == password)
        {
          userchose = true;
          cout << "Press (1) to see salary Status" << endl;
          cout << "Press (2) to see leave Status" << endl;
          cout << "Press (3) to see Personal Information" << endl;
          cin >> choice;

          switch (choice)
          {
          case 1:
            user.hra_da();
            break;
          case 2:
            user.display_leave();
            user.get_leave_data();
            break;
          case 3:
            user.show_employe_data();
            break;
          default:
            cout << "Invalid input" << endl;
            break;
          }
        }
      }

      if (!userchose)
      {
        cout << "Username and password do not match" << endl;
      }
    }
    break;
    case 2:
    {
      cout << "Enter the username : " << endl;
      cin >> username;
      cout << "Enter the password: " << endl;
      cin >> password;
      bool userFound = false;

      for (int i = 0; i < n; i++)
      {
        if (obj[i].get_username() == username && obj[i].get_password() == password)
        {
          userFound = true;
          for (int j = i; j < n - 1; j++)
          {
            obj[j] = obj[j + 1];
          }
          n--;
          cout << "Employee deleted successfully!" << endl;
          break;
        }
      }

      if (!userFound)
      {
        cout << "Invalid username or password" << endl;
      }
    }
    break;

    case 0:

      exit(0);

    default:
      cout << "invalid input" << endl
           << endl;
      break;
    }
  }

  return 0;
}