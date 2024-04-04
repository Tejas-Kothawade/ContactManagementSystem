#include<iostream>
#include<string>
using namespace std;

#define Max 1000

struct Contacts
{
    string cName;     
    int cGender = 1;    
    int cAge = 0;       
    string cPhone;    
    string cAdd;       
};


struct AddressBooks
{
    Contacts contactsArray[Max];    
    int aCount = 0;                 
};

void showMenu()
{
    cout << "********************************" << endl;
    cout << "***** Address Book Management System *****" << endl;
    cout << "********************************" << endl;
    cout << "*****    1. Add Contact     *****" << endl;
    cout << "*****    2. Show Contacts   *****" << endl;
    cout << "*****    3. Delete Contact  *****" << endl;
    cout << "*****    4. Search Contact  *****" << endl;
    cout << "*****    5. Modify Contact  *****" << endl;
    cout << "*****    6. Clear Contacts  *****" << endl;
    cout << "*****    0. Exit Address Book  *****" << endl;
    cout << "********************************" << endl;
    cout << "*********** Version 1.0 ***********" << endl;
    cout << "********************************" << endl;
}


void AddContacts(AddressBooks* abs)
{

    if (abs->aCount == Max)
    {
        cout << "Address book is full, cannot add more!" << endl;
        return;
    }
    else
    {

        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        abs->contactsArray[abs->aCount].cName = name;


        int gender;
        cout << "Enter gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->contactsArray[abs->aCount].cGender = gender;
                break;
            }
            cout << "Invalid input. Please try again!" << endl;
        }


        int age;
        cout << "Enter age: " << endl;
        cin >> age;
        abs->contactsArray[abs->aCount].cAge = age;


        string phone;
        cout << "Enter phone number: " << endl;
        cin >> phone;
        abs->contactsArray[abs->aCount].cPhone = phone;


        string add;
        cout << "Enter address: " << endl;
        cin >> add;
        abs->contactsArray[abs->aCount].cAdd = add;


        abs->aCount += 1;
        cout << "Contact added successfully!" << endl;
        system("pause");

        system("cls");
    }

}


void ShowContacts(AddressBooks* abs)
{
    if (abs->aCount == 0)
    {
        cout << "No contacts available. Please add some!" << endl;
    }
    else
    {

        for (int i = 0; i < abs->aCount; i++)
        {
            cout << "Name: " << abs->contactsArray[i].cName << " Gender: " << (abs->contactsArray[i].cGender != 2 ? "Male" : "Female") << " Age: " << abs->contactsArray[i].cAge << " Phone: " << abs->contactsArray[i].cPhone << " Address: " << abs->contactsArray[i].cAdd << endl;
        }
    }
    system("pause");
    system("cls");
}


int IsExit(AddressBooks* abs, string name)
{
    for (int i = 0; i < abs->aCount; i++)
    {
        if (abs->contactsArray[i].cName == name)
        {
            return i;
        }
    }
    return -1;
}


void DeleteContacts(AddressBooks* abs)
{

    string name;
    cout << "Enter the name of the user you want to delete: " << endl;
    cin >> name;
    
    int index = IsExit(abs, name);
 
    if (index > -1)
    {
        for (int i = index; i < abs->aCount - 1; i++)
        {
       
            Contacts temp = abs->contactsArray[i];
            abs->contactsArray[i] = abs->contactsArray[i + 1];
            abs->contactsArray[i + 1] = temp;
        }

        abs->aCount--;
        cout << "Deleted successfully!" << endl;
    }
    else
    {
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}


void GetContacts(AddressBooks* abs)
{

    string name;
    cout << "Enter the name of the user you want to search for: " << endl;
    cin >> name;

    int index = IsExit(abs, name);
    if (index > -1)
    {

        cout << "Name: " << abs->contactsArray[index].cName << endl;
        cout << "Gender: " << abs->contactsArray[index].cGender << endl;
        cout << "Age: " << abs->contactsArray[index].cAge << endl;
        cout << "Phone: " << abs->contactsArray[index].cPhone << endl;
        cout << "Address: " << abs->contactsArray[index].cAdd << endl;
    }
    else
    {

        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}


void ModefyContacts(AddressBooks* abs)
{

    string name;
    cout << "Enter the name of the user you want to modify: " << endl;
    cin >> name;

    int index = IsExit(abs, name);
    if (index > -1)
    {

        string name;
        cout << "Enter the modified name: " << endl;
        cin >> name;
        abs->contactsArray[index].cName = name;


        int gender;
        cout << "Enter the modified gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->contactsArray[index].cGender = gender;
                break;
            }
            cout << "Invalid input. Please try again!" << endl;
        }


        int age;
        cout << "Enter the modified age: " << endl;
        cin >> age;
        abs->contactsArray[index].cAge = age;


        string phone;
        cout << "Enter the modified phone number: " << endl;
        cin >> phone;
        abs->contactsArray[index].cPhone = phone;


        string add;
        cout << "Enter the modified address: " << endl;
        cin >> add;
        abs->contactsArray[index].cAdd = add;
        cout << "Modification successful!" << endl;
    }
    else
    {

        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}


void ClearContacts(AddressBooks* abs)
{
    string choose = "N";
    cout << "Are you sure you want to clear the address book? (Y for Yes/N for No)" << endl;

    while (true)
    {
        cin >> choose;
        if (choose == "Y" || choose == "N")
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please try again!" << endl;
        }
    }

    if (choose == "Y")
    {
        abs->aCount = 0;
        cout << "Cleared successfully!" << endl;
    }
    else
    {
        cout << "Operation canceled!" << endl;
    }
    system("pause");
    system("cls");
}


int main()
{

    int select = 0;

    AddressBooks abs;

    abs.aCount = 0;

    while (true)
    {

        showMenu();

        cin >> select;
        switch (select)
        {
        case 1:
            AddContacts(&abs);
            break;
        case 2:
            ShowContacts(&abs); 
            break;
        case 3:
            DeleteContacts(&abs);
            break;
        case 4:
            GetContacts(&abs);
            break;
        case 5:
            ModefyContacts(&abs);
            break;
        case 6:
            ClearContacts(&abs);
            break;
        case 0:
            cout << "Welcome back next time, goodbye!" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }


    system("pause");
    return 0;
}
