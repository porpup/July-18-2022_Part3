//Date: July-18-2022
//Name: Oleksandr Shyryayev
//Description: Student List in C++

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Person{
    string firstName;
    string lastName;
};

struct Address{
    string numberAndStreet;
    string city;
    string postalCode;
    string provinceState;
};

struct Student{
    int studentNumber;
    Person name;
    Address address;
    string email;
    string phoneNumber;
};

vector <Student> vecStudents;

void createStudentData(Student& data);
void searchStudent();
void modifyStudentData();
void deleteStudent();
void displayStudents();

int main(){
    char option;
    Student student;

    //Adding first student to vector
    vecStudents.push_back({202210888, "Oleksandr", "Shyryayev", "10580 Av Georges Baril", "Montreal", "H2C 2N3", "Quebec", "oleksandr.shyryayev@lcieducation.net", "(514)235-9240"});
    vecStudents.push_back({202110845, "Beaver", "Von Canada", "10080 Main Street", "Toronto", "T3C 2N3", "Ontario", "beaver.voncanada@lcieducation.net", "(514)230-9000"});
    vecStudents.push_back({202200123, "Harry", "Larry", "10000 Av Noware", "New York", "N1C 2N3", "Washington", "harry.larry@lcieducation.net", "(500)200-9240"});
    vecStudents.push_back({202010555, "Who Let", "Thedogs Out", "10111 Bld Dogs House", "Texas", "T1C 2T8", "Texas", "wholet.thedogsout@lcieducation.net", "(500)235-8000"});
    //Printing programs header
    cout << "********************************************************" << endl;
    cout << "*             Oleksandr Shyryayev - 2210888            *" << endl;
    cout << "*                    LaSalle Student                   *" << endl;
    cout << "*            Student List (Version: 0.2 BETA)          *" << endl;
    cout << "********************************************************" << endl;

    do{
        cout << " ------------------------------------------------------" << endl;
        cout << "|  '1' -- Create and add a student                     |" << endl;
        cout << "|  '2' -- Search for a student by number               |" << endl;
        cout << "|  '3' -- Modify the information of the student        |" << endl;
        cout << "|  '4' -- Delete the information of the student        |" << endl;
        cout << "|  '5' -- Display the student list                     |" << endl;
        cout << "|  '0' -- Exit                                         |" << endl;
        cout << " ------------------------------------------------------" << endl;
        cout << "   Option: ";
        cin >> option;

        switch(option){
        case '1':
            system("cls");
            createStudentData(student);
            break;
        case '2':
            system("cls");
            searchStudent();
            break;
        case '3':
            system("cls");
            modifyStudentData();
            break;
        case '4':
            system("cls");
            deleteStudent();
            break;
        case '5':
            system("cls");
            cout << "------------------------------------------------------------------------------------" << endl;
            displayStudents();
            cout << endl;
            break;
        case '0':
            char confirmation;
            system("cls");
            cout << "Are you sure? (Y - Yes): ";
            cin >> confirmation;
            if(confirmation == 'Y' || confirmation == 'y'){
                cout << "\nAu revoir!" << endl;
                cout << "Exiting program..." << endl;
            }else{
                option = 'n';
            }
            break;
        default:
            system("cls");
            cout << "\nError: Invalid option..." << endl << endl;
        }

    }while(option != '0');

    return 0;
}

void createStudentData(Student& data){
    do{
        cout << "Student No.: ";
        cin >> data.studentNumber;
        if(data.studentNumber<1000000 || data.studentNumber>999999999){
            cout << "Wrong student id (7 - 9 digits)!\n";
        }
    }while(data.studentNumber<1000000 || data.studentNumber>999999999);
    cout << "First Name: ";
    cin.ignore();
    getline(cin, data.name.firstName);
    cout << "Last Name: ";
    getline(cin, data.name.lastName);
    cout << "Address, House No. & Street: ";
    getline(cin, data.address.numberAndStreet);
    cout << "Address, City: ";
    getline(cin, data.address.city);
    cout << "Address, Postal Code: ";
    getline(cin, data.address.postalCode);
    cout << "Address, Province / State: ";
    getline(cin, data.address.provinceState);
    cout << "Email: ";
    getline(cin, data.email);
    cout << "Phone No.: ";
    getline(cin, data.phoneNumber);

    //Store data in vecStudents
    vecStudents.push_back({data.studentNumber, data.name.firstName, data.name.lastName, data.address.numberAndStreet, data.address.city, data.address.postalCode, data.address.provinceState, data.email, data.phoneNumber});
    cout << "\nStudent data has been saved." << endl << endl;
}

void searchStudent(){
    int studentNo;
    bool studentExist = false;

    cout << "Student No.: ";
    cin >> studentNo;

    for(int i=0; i<vecStudents.size(); i++){
        if (studentNo == vecStudents[i].studentNumber){
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "| " << setw(9) << vecStudents[i].studentNumber;
            cout << " | " << vecStudents[i].name.firstName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].name.lastName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.numberAndStreet << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.city << " " << vecStudents[i].address.postalCode << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.provinceState << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].email << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].phoneNumber << endl;
            cout << "------------------------------------------------------------------------------------" << endl << endl;
            studentExist = true;
        }
    }
    if (!studentExist){
        cout << "Student Number " << studentNo << " doesn't exist" << endl << endl;
    }
}

void modifyStudentData(){
    int studentNo;
    string firstName;
    string lastName;
    string addressNumberAndStreet;
    string addressCity;
    string addressPostalCode;
    string addressProvinceState;
    string email;
    string phoneNumber;
    bool studentExist = false;

    cout << "Student Number to modify: ";
    cin >> studentNo;

    for(int i=0; i<vecStudents.size(); i++){
        if (studentNo == vecStudents[i].studentNumber){
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "| " << setw(9) << vecStudents[i].studentNumber;
            cout << " | " << vecStudents[i].name.firstName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].name.lastName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.numberAndStreet << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.city << " " << vecStudents[i].address.postalCode << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.provinceState << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].email << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].phoneNumber << endl;
            cout << "------------------------------------------------------------------------------------" << endl << endl;

            cout << vecStudents[i].studentNumber << endl;
            cout << "New First Name: ";
            cin.ignore();
            getline(cin, firstName);
            //Skiping modification by pressing "Space" - data stays without changes
            if (firstName != ""){
                vecStudents[i].name.firstName = firstName;
            }
            cout << "New Last Name: ";
            getline(cin, lastName);
            if (lastName != ""){
                vecStudents[i].name.lastName = lastName;
            }
            cout << "Address, New House No. & Street: ";
            getline(cin, addressNumberAndStreet);
            if (addressNumberAndStreet != ""){
                vecStudents[i].address.numberAndStreet = addressNumberAndStreet;
            }
            cout << "Address, New City: ";
            getline(cin, addressCity);
            if (addressCity != ""){
                vecStudents[i].address.city = addressCity;
            }
            cout << "Address, New Postal Code: ";
            getline(cin, addressPostalCode);
            if (addressPostalCode != ""){
                vecStudents[i].address.postalCode = addressPostalCode;
            }
            cout << "Address, New Province / State: ";
            getline(cin, addressProvinceState);
            if (addressProvinceState != ""){
                vecStudents[i].address.provinceState = addressProvinceState;
            }
            cout << "New Email: ";
            getline(cin, email);
            if (email != ""){
                vecStudents[i].email = email;
            }
            cout << "New Phone No.: ";
            getline(cin, phoneNumber);
            if (phoneNumber != ""){
                vecStudents[i].phoneNumber = phoneNumber;
            }

            system("cls");
            cout << "New Student data has been saved." << endl << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "| " << setw(9) << vecStudents[i].studentNumber;
            cout << " | " << vecStudents[i].name.firstName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].name.lastName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.numberAndStreet << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.city << " " << vecStudents[i].address.postalCode << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.provinceState << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].email << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].phoneNumber << endl;
            cout << "------------------------------------------------------------------------------------" << endl << endl;
            studentExist = true;
        }
    }
    if (!studentExist){
        cout << "Student Number " << studentNo << " doesn't exist" << endl << endl;
    }
}

void deleteStudent(){
    int studentNo;
    char confirmation;
    bool studentExist = false;

    cout << "Student Number to delete: ";
    cin >> studentNo;

    for(int i=0; i<vecStudents.size(); i++){
        if (studentNo == vecStudents[i].studentNumber){
           cout << "Are you sure? (Y - Yes): ";
           cin >> confirmation;
           if(confirmation == 'Y' || confirmation == 'y'){
                vecStudents.erase(vecStudents.begin() + i);
                cout << "Student " << studentNo << " has been deleted." << endl << endl;
                studentExist = true;
           }else{
                studentExist = true;
           }

        }
    }
    if (!studentExist){
        cout << "Student Number " << studentNo << " doesn't exist" << endl << endl;
    }
}

void displayStudents(){
    if (vecStudents.size() == 0){
        cout << "Student list is empty." << endl;
    }else{
        for(int i=0; i<vecStudents.size(); i++){
            cout << "| " << setw(9) << vecStudents[i].studentNumber;
            cout << " | " << vecStudents[i].name.firstName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].name.lastName << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.numberAndStreet << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.city << " " << vecStudents[i].address.postalCode << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].address.provinceState << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].email << endl;
            cout << "| " << setw(12) << "| " << vecStudents[i].phoneNumber << endl;
            cout << "------------------------------------------------------------------------------------" << endl;
        }
    }
}
