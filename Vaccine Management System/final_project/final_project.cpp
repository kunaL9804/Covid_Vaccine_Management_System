#include <iostream>
#include <stdio.h> // gets(), fflush()
#include <fstream> // file handling
#include <conio.h> // getch()
#include <string.h> // string operations
#include <iomanip> // setiosflag(), setw()
#include <time.h> // time()
#include <stdlib.h>  // srand(), system("cls")
#include <windows.h> //sleep()
#define number_of_vaccine 200 // For the number of vaccines already tn stock to begin with

using namespace std;

int admin_login();// For the login of the admin

//Functions for login of staff
void staff_login_page();//For the page of the login of the staff with all the features
void staff_login();//For login of staff
void staff_registration();//For registration of staff
void staff_forgot_login();//For forgot login credentials feature for staff

// Function for the Main Menu layout after the login of the staff
void main_menu();

//Function for the commands at the main_menu
void main_menu_page();

// Function for the first row with column headings during the displaying of the data
void first_row();

class vaccine // for data of the vaccinated person
{
    string name; // for the name of the vaccinated person
    string aadhar_number; // for the aadhar number of the vaccinated person
    int age; // for the age of the vaccinated person
    string profession; // for the profession of the vaccinated patient
    char covid_patient; // whether the person has been a covid patient or not
    string blood_pressure; // for the B.P. of the patient at the time of the vaccination
    string temperature; // for the temperature of the patient at the time of the vaccination
    char gender; // for the gender of the vaccinated person
    string mobile_number; // for the mobile number of the vaccinated person
    string address; // for the address of the vaccinated person

    public:
    void new_record();//for adding the record of a vaccinated person
    void view_vaccine();// function for the handling of vaccine records
    int vaccine_in_stock();// function to reference the number of vaccines in stock in other functions
    void search();//the basic function to use for searching records
    void search_by_aadhar();//for searching by aadhar
    void search_by_age();//for searching by age
    void search_by_covid_history();//for searching by aadhar
    void search_by_gender();// for searching by gender
    void show_data();// to display the data after search
    void show_list();// to display the data in a list after search

    // Helper functions
    char covid_history_entry(); // to ensure that only Y or N is entered
    char gender_entry();// to ensure that only M or F is entered
    void aadhar_number_entry(); // to ensure that the aadhar number is entered in correct form
    int aadhar_number_duplicate(string); // to check for duplicate aadhar numbers during data entry
    void mobile_number_entry(); // to ensure that the mobile number is entered in correct form
    int is_digit(string); // to check if the given string has only numbers , to be used in aadhaar_number_entry and mobile number entry
};


// The main function
int main()
 {
    vaccine obj;
    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t\t   Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\n\t\t\tPress any key to continue.............  ";
    getch();

    int k = 3;// For the number of attempts left at login
    B: //  will be used to come back to here later
    system("cls");

    cout<<"\n\n\t\t\t\t  *********************************************";
    cout<<"\n\t\t\t\t\t\t  ADMIN LOGIN\n";
    cout<<"\t\t\t\t  *********************************************\n";
    while(k>=1)
    {
        int c = admin_login();
        if(c == 1){
            cout<<"\n\n\n\t\t\tAdmin Login Sucessful!!!";
            cout<<"\n\n\t\t\tSystem ready to use for Staff.";
            Sleep(4000);
            break;
        }

        else{

            system("cls");

            cout<<"\n\n\t\t\t\t  *********************************************";
            cout<<"\n\t\t\t\t\t\t  ADMIN LOGIN\n";
            cout<<"\t\t\t\t  *********************************************\n";
            cout<<"\n\n\t\t Wrong Password Or User Name ! ! \n\n\t\t You Can try Only "<<k-1<<" more times";
            k--;
        }
    }

    if(k<1)
    {
        for(int i=59; i>=0; i--)
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
            cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
            Sleep(1000);
        }
        k=3;
        goto B;
    }

    staff_login_page();

    return 0;
}

// Function for the login of the Admin
// Features: -
// 1. Hiding the password by *****
// 2. Captcha
int admin_login()
{
    char admin_username[30]; // for username input of the admin login
    char admin_password[20];//for password input of the admin login
    int ch; // for password input
    int i = 0 ; // loop iterator
    int captcha = 0;//for the captcha
    int captcha_input = 0;// for the captcha input from the admin
    cout << "\n\n\n\n\n\t\t\t\t\t Admin Username :    ";
    fflush(stdin);
    gets(admin_username);
    cout << "\n\n\t\t\t\t\t Admin Password :    ";
    fflush(stdin);
    // To hide the input password by *
    while ((ch= getch())!= 13) {
            if( ch == 8){
                cout<<"\b";
                i--;
        }
            else {
                cout<<'*';
                admin_password[i] = ch;
                i++;
        }
    }

    admin_password[i] = '\0' ; // termination of the array is a must

    srand(time(0)); // to generate different number each time
    captcha = rand(); // generation of a random number for captcha
    cout <<"\n\n\t\t\t\t\t Captcha        :    ";
    cout<<captcha;
    cout <<"\n\n\t\t\t Please enter the valid captcha :    ";
    cin >> captcha_input;

    // Validation of input credentials
    if ( (strcmp(admin_username,"krish2003") == 0) && (strcmp(admin_password,"coproject") == 0) && (captcha_input == captcha) ){
        return 1;
    }

    else {
        return 0;
    }
} // End of function


// The function with the features for the login of the staff
void staff_login_page(){
    system("cls");
    cout<<"\n\n\n\t\t\t\t       *****************************\n\n\n";
    cout<<"\t\t\t\t\t   Welcome to login page                               \n\n\n\n";
    cout<<"\t\t\t\t***********        MENU        ***********\n\n";
    cout<<"\t\t\t\t1. LOGIN"<<endl;
    cout<<"\t\t\t\t2. REGISTER"<<endl;
    cout<<"\t\t\t\t3. FORGOT PASSWORD (or) USERNAME"<<endl;
    cout<<"\t\t\t\t4. Exit"<<endl;

    int choice;
    cout<<"\n\t\t\t\tEnter your choice :   ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1:{
            staff_login();
            break;
        }
        case 2:{
            staff_registration();
            break;
        }
        case 3:{
            staff_forgot_login();
            break;
        }
        case 4:{
            system("cls");
            cout<<"\n\n\n\n\t\t\t\tThanks for using this program :) \n\t\t\t\tThis program is created by krish saini and kunal saini.\n\n";
            break;
        }
        default:{
            system("cls");
            cout<<"\n\n\n\t\t\t\tYou've made a mistake, give it a try again.\n";
            Sleep(2000);
            staff_login_page();
        }
    }

}// End of function

// Function for login of staff
void staff_login()
{
        system("cls");

        cout<<"\n\n\n\t\t\t\t       ******************************\n\n";
        cout<<"\t\t\t\t\t    Welcome to Login Page                               \n\n";
        cout<<"\t\t\t\t***********        LOGIN        ************\n\n";

        string staff_username, staff_password;
        string input_staff_username, input_staff_password;
        cout<<"\n\n\t\t\t\tPlease enter the following details :   "<<endl;
        cout<<"\n\n\t\t\t\tUSERNAME :   ";
        cin>>input_staff_username;
        cout<<"\n\n\t\t\t\tPASSWORD :   ";
        cin>>input_staff_password;

        ifstream input("stafflogin.txt");

        int flag = 0;
        while(input>>staff_username>>staff_password)
        {
            if( (input_staff_username == staff_username) && (input_staff_password == staff_password) ){
                flag=1;
            }
        }
        input.close();

        if(flag==1) {
            cout<<"\n\n\n\t\t\t\tLogging in..."  ;
            Sleep(2000);
            cout<<"\n\n\n\t\t\t\tHello !!  "<<input_staff_username<<"\n\t\t\t\tLOGIN SUCCESS!!!\n\t\t\t\tHave a nice day :)";
            Sleep(4000);
            main_menu_page();
        }

        else {
            cout<<"\n\n\n\t\t\t\tLogging in..."  ;
            Sleep(2000);
            cout<<"\n\t\t\t\tLOGIN ERROR!!!!\n\t\t\t\tPlease check your Username and Password";
            cout<<"\n\t\t\t\tPress any key to continue......   ";
            getch();
            staff_login_page();
        }
}//End of function

//Function for registration of staff
void staff_registration()
{
        string registration_username;
        string registration_password;
        system("cls");

        cout<<"\n\n\n\t\t\t\t       *****************************\n\n\n";
        cout<<"\t\t\t\t\tWelcome to Registration Page                               \n\n\n\n";
        cout<<"\t\t\t\t***********    REGISTRATION    ***********\n\n";

        cout<<"\n\n\t\t\t\tEnter the Username :   ";
        cin>>registration_username;
        cout<<"\n\n\t\t\t\tEnter the password :   ";
        cin>>registration_password;

        ofstream reg("stafflogin.txt",ios::app);
        reg<<registration_username<<' '<<registration_password<<endl;
        reg.close();
        cout<<"\n\n\t\t\t\tRegistering...\n";
        Sleep(2000);
        cout<<"\n\n\t\t\t\tRegistration Sucessful!!\n";
        cout<<"\n\t\t\t\tPress any key to continue......   ";
        getch();
        staff_login_page();

}// End of function


//Function for forgot login credentials for staff login
void staff_forgot_login()
{
system("cls");

        cout<<"\n\n\t\t\t\t       ******************************\n";
        cout<<"\t\t\t\t\t  Welcome to Recovery Page                               \n\n\n";
        cout<<"\t\t\t\t***********       FORGOT?       ************\n\n";

cout<<"\t\t\t\tForgotten ? We're here for help\n";
cout<<"\n\n\t\t\t\t1. Search your ID by Username"<<endl;
cout<<"\t\t\t\t2. Search your ID by Password"<<endl;
cout<<"\t\t\t\t3. Back"<<endl;

int choice;
cout<<"\n\n\t\t\t\tEnter your choice :   ";
cin>>choice;
switch(choice)
{
    case 1:
    {
        string search_usernme;
        string staff_username;
        string staff_password;
        cout<<"\n\n\t\t\t\tEnter your remembered Username :   ";
        cin>>search_usernme;

        ifstream searchu("stafflogin.txt");

        int flag=0;
        while(searchu>>staff_username>>staff_password)
        {
            if(search_usernme == staff_username){
                flag=1;
            }
        }
        searchu.close();

        if(flag == 1){
            cout<<"\n\n\t\t\t\tHurray !! Account found !!!\n";
            cout<<"\n\t\t\t\tYour password is :   "<<staff_password;
            cin.get();
            cin.get();
            system("cls");
            staff_login_page();
        }

        else{
            cout<<"\n\t\t\t\tSorry, Your UserID is not found in our database :(\n";
            cout<<"\n\t\t\t\tPlease contact the System Administrator for more details. \n";
            cin.get();
            cin.get();
            staff_login_page();
        }

        break;

    }

    case 2:
    {

        string search_password;
        string staff_username;
        string staff_password;
        cout<<"\n\n\t\t\t\tEnter the remembered Password :   ";
        cin>>search_password;

        ifstream searchp("stafflogin.txt");

        int flag=0;
        while(searchp>>staff_username>>staff_password)
        {
            if(search_password == staff_password)
            {
                flag = 1;
            }
        }
        searchp.close();

        if(flag == 1)
        {
            cout<<"\n\n\t\t\t\tHurray !! Account found !!!\n";
            cout<<"\n\t\t\t\tYour Username is :   "<<staff_username;
            cout<<"\n\n\t\t\t\tPress any key to continue....";
            cin.get();
            cin.get();
            system("cls");
            staff_login_page();
        }
        else
        {
            cout<<"\n\n\t\t\t\tSorry, your password was not found in our database. :( \n";
            cout<<"\n\t\t\t\tKindly contact the System Administrator for more information.\n";
            cin.get();
            cin.get();
            staff_login_page();
        }

        break;
    }

    case 3:
    {
        cin.get();
        staff_login_page();
    }

    default:
    {
        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
        staff_forgot_login();
    }
}
}// End of function


// Function for the Main Menu layout after the login of the staff
void main_menu()
{
    system("cls");
    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\t\t\t *****************************************\n";
    cout<<"\t\t\t\t\t   MENU";
    cout<<"\n\t\t\t *****************************************\n";
    cout<<"\n\t\t 1: Add New Record\t\t\t 2: View Vaccine Data"<<endl;
    cout<<"\n\t\t 3: Search   \t\t\t\t 4: Logout"<<endl;
}// End of function


//Th e function with the features at the main menu after the staff login: like:-
// 1. Adding new data
// 2. Searching data by several parameters
// 3. Viewing and updating vaccine status
void main_menu_page()
{
    vaccine obj;
    int main_menu_choice;
    do{
        main_menu();
        cout<<"\n\n\t\tChoose according to your need :   ";
        cin>>main_menu_choice;

        switch(main_menu_choice)
        {
            case 1:
            {   system("cls");
                obj.new_record();
                break;
            }

            case 2:
            {   system("cls");
                obj.view_vaccine();
                break;
            }

            case 3:
            {   system("cls");
                obj.search();
                break;
            }

            case 4:
            {   system("cls");
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t Logged out successfully ! !";
                cout<<"\n\n\t\t\t\t\t ****HAVE A NICE DAY*****";
                Sleep(2000);
                staff_login_page();
            }

            default:
            {   system("cls");
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tINVALID OPTION!!";
                cout<<"\n\n\t\t\t\t\t*****   TRY AGAIN  *****";
                Sleep(3000);
                main_menu_page();
            }
        }
    } while(main_menu_choice!=0);
}


// Function for the first row with column headings during the displaying of the data
void first_row()
{
    cout<<"\n\n\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t            DETAILS";
    cout<<"\n\t\t\t  *****************************************\n\n";

    cout<<setw(20)<<setiosflags(ios::left)<<"Name";
    cout<<setw(20)<<"Aadhar No.";
    cout<<setw(10)<<"Age";
    cout<<setw(20)<<"Profession";
    cout<<setw(20)<<"Covid Patient";
    cout<<setw(8)<<"B.P.";
    cout<<setw(15)<<"Temperature";
    cout<<setw(10)<<"Gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<"Address"<<endl<<endl;
}// End of function

//Fnction for adding new record
void vaccine :: new_record()
{

    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\t\t\t *****************************************\n";
    cout<<"\t\t\t\t          DATA ENTRY";
    cout<<"\n\t\t\t *****************************************\n\n";

    int available_vaccines;
    available_vaccines = vaccine_in_stock();

    if(available_vaccines < 1 )
    {
        cout<<"\n\t\t There are no vaccines remaining in stock ! ! ";
        cout<<"\n\n\t\t Add more vaccines first. ";
        getch();
        main_menu_page();
    }
    else
    {
        fstream outin;
        outin.open("records.txt",ios::app|ios::in);
        fflush(stdin);
            cout<<"\n\t\t Enter Name \t\t\t\t:- \t";
            getline(cin,name);
            cout<<"\n\t\t Enter Aadhar Number \t\t\t:- \t";
            aadhar_number_entry(); // to ensure correct format of aadhar number
            cout<<"\n\t\t Enter Age \t\t\t\t:- \t";
            cin>>age;
            cout<<"\n\t\t Enter Profession \t\t\t:- \t";
            fflush(stdin);
            getline(cin,profession);
            cout<<"\n\t\t CoVid Patient (Y|N) \t\t\t:- \t";
            covid_patient = covid_history_entry(); // a function to ensure that only Y or N is entered
            cout<<"\n\t\t Enter Blood Pressure \t\t\t:- \t";
            cin>>blood_pressure;
            cout<<"\n\t\t Enter Body Temperature \t\t:- \t";
            cin>>temperature;
            cout<<"\n\t\t Enter Gender (M|F) \t\t\t:- \t";
            gender = gender_entry(); // a function to ensure that only M or F is entered
            fflush(stdin);
            cout<<"\n\t\t Enter Mobile Number \t\t\t:- \t";
            mobile_number_entry();
            cout<<"\n\t\t Enter Permanent Address \t\t:- \t";
            getline(cin,address);

        outin.write((char*)this,sizeof(vaccine));

        cout<<"\n\n\t\tYOUR DATA HAS BEEN SUCCESSFULLY INSERTED !!! ";
        outin.close();
        getch();//holding the screen
    }
}// End of function

 // Helper function to ensure that only Y or N is entered for covid_history
char vaccine :: covid_history_entry()
{
    char covid_history_input;
    cin>>covid_history_input;
    while (1){
            toupper(covid_history_input);
            if ( covid_history_input == 'Y' || covid_history_input == 'N' ){
                return covid_history_input;
            }
            else {
                cout<<"\n\t\t Please enter only Y | N !  ";
                cout<<"\n\t\t CoVid Patient (Y|N) \t\t\t:- \t";
                cin>>covid_history_input;
            }
    }
}

 // Helper function to ensure that only Y or N is entered for gender
char vaccine :: gender_entry()
{
    char gender_input;
    cin>>gender_input;
    while (1){
            toupper(gender_input);
            if ( gender_input == 'M' || gender_input == 'F' ){
                return gender_input;
            }
            else {
                cout<<"\n\t\t Please enter only M | F !  ";
                cout<<"\n\t\t Enter Gender (M|F) \t\t\t:- \t";
                cin>>gender_input;
            }
    }
}

void vaccine :: aadhar_number_entry()
{
    string aadhar_number_input;
    getline(cin,aadhar_number_input);

     while (1){
        if ( ( aadhar_number_input.length() == 12 ) && (is_digit(aadhar_number_input) == 1 )  && (aadhar_number_duplicate(aadhar_number_input) == 1) ){
            aadhar_number = aadhar_number_input ;
            return;
        }
        else {
            cout<<"\n\t\t Aadhar Number Incorrect or Duplicate !  ";
            cout<<"\n\t\t Enter Aadhar Number \t\t\t:- \t";
             fflush(stdin);
            getline(cin,aadhar_number_input);
        }
     }
} // end of function

// function for mobile number entry
void vaccine :: mobile_number_entry()
{
    string mobile_number_input;
    getline(cin,mobile_number_input);

     while (1){
        if ( ( mobile_number_input.length() == 10 ) && (is_digit(mobile_number_input) == 1 )){
            mobile_number = mobile_number_input ;
            return;
        }
        else {
            cout<<"\n\t\t Mobile Number format is incorrect !  ";
            cout<<"\n\t\t Enter Mobile Number \t\t\t:- \t";
            fflush(stdin);
            getline(cin,mobile_number_input);
        }
     }
} // end of function

// function to check whether all characters in the aadhar number are numbers
int vaccine :: is_digit(string aadhar_number_input)
{
    int flag = 1;
    for ( int i = 0 ; i < aadhar_number_input.length() ; i++ ){
        if ( aadhar_number_input[i] >= '0' && aadhar_number_input[i] <= '9' ){
            flag = 1;
        }
        else {
            flag = 0;
            break;
        }
    }

        if (flag == 1 ){
            return 1;
        }

        else{
            return 0;
        }

}// End of function


// Function to check for duplicate aadhar numbers
int vaccine :: aadhar_number_duplicate(string search_aadhar_number){
     ifstream in("records.txt");
    in.read((char*)this,sizeof(vaccine));
    int flag = 0;

    while(!in.eof()){
        if(search_aadhar_number.compare(aadhar_number)==0){
            flag=1;
        }
    in.read((char*)this,sizeof(vaccine));
    }

    in.close();

    if(flag==0){
        return 1;
    }
    else{
        return 0;
    }
}// End of function


//Function for the handling of vaccine records
void vaccine :: view_vaccine(){

    ifstream ind;
    ind.open("records.txt");
    ind.seekg(0,ios::beg);// for the pointer at the beginning of the file

    int number_of_records = 0;// for the number of records filled
    while(ind.read((char*)this,sizeof(vaccine))){// code to read the records one at a time
        number_of_records++;
    }
    ind.close();

    int number_of_vaccines_remianing;
    number_of_vaccines_remianing = number_of_vaccine - number_of_records;

    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\t\t\t *****************************************\n";
    cout<<"\t\t\t\t     VACCINE STATISTICS";
    cout<<"\n\t\t\t *****************************************\n\n";
    cout<<"\t\t   1. Add More        \t\t\t    2. View Available \n\t\t\t\t\t   3. Back"<<endl;

    int total_number_of_added_vaccines = 0;
    fstream file("count.txt", ios::in | ios::out);
    file>>total_number_of_added_vaccines;

    int vaccine_choice;
    cout<<"\n\n\n\t\tPlease choose according to your need :   ";
    cin>>vaccine_choice;
    switch(vaccine_choice){

    case 1:
        int added_vaccines;
        cout<<"\n\n\t\tEnter number of vaccines you want to add :   ";
        cin>>added_vaccines;
        total_number_of_added_vaccines = total_number_of_added_vaccines + added_vaccines;
        file.seekg(0);
        file<<total_number_of_added_vaccines;
        cout<<"\n\n\t\tNow total number of vaccines are :   "<<total_number_of_added_vaccines + number_of_vaccines_remianing;
        break;

    case 2:
        cout<<"\n\n\t\tAvailable number of vaccines are :   "<<total_number_of_added_vaccines + number_of_vaccines_remianing;
        if ( (total_number_of_added_vaccines + number_of_vaccines_remianing) < 10 ) {
            cout<<"\n\n\t\tVaccines in stock are running low ! !   ";
        }
        break;

    case 3:
        system("cls");
        main_menu();

    default:
        system("cls");
        cout<<"\n\n\n\t\t\t\tEnter Valid option !!!! "<<endl;
        main_menu();
    }

    file.close();
    getch();
} // End of function


// Function to find the number of remaining vaccines for reference in another functions
int vaccine :: vaccine_in_stock()
{
    ifstream ind;
    ind.open("records.txt");
    ind.seekg(0,ios::beg);// for the pointer at the beginning of the file

    int number_of_records = 0;// for the number of records filled
    while(ind.read((char*)this,sizeof(vaccine))){// code to read the records one at a time
        number_of_records++;
    }
    ind.close();

    int number_of_vaccines_remianing;
    number_of_vaccines_remianing = number_of_vaccine - number_of_records;

    int total_number_of_added_vaccines = 0;
    fstream file("count.txt", ios::in | ios::out);
    file>>total_number_of_added_vaccines;

    int vaccine_in_stock;
    vaccine_in_stock = total_number_of_added_vaccines + number_of_vaccines_remianing;

    return vaccine_in_stock;
}// End of function

//The  master function with all the search features :-
// 1. Search by Aadhar
// 2. Search by Gender
// 3. Search by CoVid history
// 4. Search by Age
void vaccine :: search(){

    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t     SEARCHING STATISTICS";
    cout<<"\n\t\t\t  *****************************************\n\n";
    cout<<"\n\t\t 1. By Aadhar \t\t\t\t 2. By Age "<<endl;
    cout<<"\n\t\t 3. By CoVid History   \t\t\t 4. By Gender "<<endl;

    cout<<"\n\n\t\tEnter your choice :   ";
    int search_choice;
    cin>>search_choice;

    switch(search_choice){

    case 1:
        system("cls");
        search_by_aadhar();
        getch();
        break;

    case 2:
        system("cls");
        search_by_age();
        getch();
        break;

    case 3:
        system("cls");
        search_by_covid_history();
        getch();
        break;

    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;

    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        main_menu();
    }
}// End of function

//Function to display data after search
void vaccine :: show_data()
{
    cout<<"\n\n\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t            DETAILS";
    cout<<"\n\t\t\t  *****************************************\n\n";

    cout<<"\t\t Name is\t\t\t\t: \t"<<name<<endl;
    cout<<"\t\t Aadhar number is\t\t\t: \t"<<aadhar_number<<endl;
    cout<<"\t\t Age is\t\t\t\t\t: \t"<<age<<endl;
    cout<<"\t\t Profession is\t\t\t\t: \t"<<profession<<endl;
    cout<<"\t\t CoVid History is\t\t\t: \t"<<covid_patient<<endl;
    cout<<"\t\t Blood pressure is\t\t\t: \t"<<blood_pressure<<endl;
    cout<<"\t\t Body temperature is\t\t\t: \t"<<temperature<<endl;
    cout<<"\t\t Gender is\t\t\t\t: \t"<<gender<<endl;
    cout<<"\t\t Address is\t\t\t\t: \t"<<address<<endl;
    cout<<"\t\t Mobile number is\t\t\t: \t"<<mobile_number<<endl;
}//End of function

// Function to display data in a list after search
void vaccine :: show_list()
{

    cout<<setw(20)<<setiosflags(ios::left)<<name;
    cout<<setw(20)<<aadhar_number;
    cout<<setw(10)<<age;
    cout<<setw(20)<<profession;
    cout<<setw(20)<<covid_patient;
    cout<<setw(8)<<blood_pressure;
    cout<<setw(15)<<temperature;
    cout<<setw(10)<<gender;
    cout<<setw(15)<<mobile_number;
    cout<<address<<endl;
}// End of function

//Function for searching by Aadhar Number
void vaccine::search_by_aadhar(){

    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t       AADHAR SEARCHING";
    cout<<"\n\t\t\t  *****************************************\n\n";

    cout<<"\n\n\t\t\tPlease enter the Aadhar number to search :   ";
    string search_aadhar_number;
    fflush(stdin);
    getline(cin,search_aadhar_number);

    ifstream in("records.txt");
    in.read((char*)this,sizeof(vaccine));
    int flag = 0;

    while(!in.eof()){
        if(search_aadhar_number.compare(aadhar_number)==0){
            show_data();
            flag=1;
            break;
        }
    in.read((char*)this,sizeof(vaccine));
    }

    if(flag==0){
        cout<<"\n\n\t\t\t\tAadhar Number not found!!!! "<<endl;
    }
    in.close();
}//End of function

//Function for searching by Age
void vaccine :: search_by_age(){

    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:- krish saini and kunal saini "<<endl<<endl;
    cout<<"\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t         AGE SEARCHING";
    cout<<"\n\t\t\t  *****************************************\n\n";

    cout<<"\n\n\t\t\tPlease enter the Age to search :   ";
    int search_age;
    cin>>search_age;

    ifstream in("records.txt");
    int flag = 0;
    int number_of_records_found = 0;
    in.read((char*)this,sizeof(vaccine));
    first_row();
    while(!in.eof()){
        if(search_age== age)
        {
            show_list();
            flag=1;
            number_of_records_found++;
        }
    in.read((char*)this,sizeof(vaccine));
    }

    if(flag == 0){
    cout<<"\n\n\t\t\tAge you entered is not found!!!!"<<endl;
    }
    cout<<"\n\n\n\t\t\tNO of people vaccinated by this age are  :  "<<number_of_records_found;
    in.close();

}//End of function

//Function for searching by CoVid history
void vaccine::search_by_covid_history()
{
    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:- krish saini and kunal saini"<<endl<<endl;
    cout<<"\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t       CoVid  SEARCHING";
    cout<<"\n\t\t\t  *****************************************\n\n";

    cout<<"\n\n\t\t\tEnter Y|N to see the list of Covid Positive|Covid Negative people vaccinated :   ";

    char search_covid_history;
    cin>>search_covid_history;
    int number_of_records_found = 0;

    ifstream in("records.txt");
    in.read((char*)this,sizeof(vaccine));
    int flag =0;
    first_row();
    while(!in.eof()){
        if(toupper(search_covid_history) == toupper(covid_patient)){/*Avoiding making cases seperatety by coverting to uppercase before comparision */
            show_list();
            flag=1;
            number_of_records_found++;
        }
    in.read((char*)this,sizeof(vaccine));
    }

    if(flag == 0){
    cout<<"\n\t\t\tNo one has been vaccinnated with this past CoVid record!!!!"<<endl;
    }

    cout<<"\n\n\n\t\t\tNO. of people vaccinated with this CoVid record are :  "<<number_of_records_found<<endl;
    in.close();

}// End of function

//Function for search by Gender
void vaccine::search_by_gender()
{
    cout<<"\n\n\t\t\t\xB3\xB2 \xB2 \xB2 \xB3 VACCINE MANAGEMENT SYSTEM  \xB3 \xB2 \xB2 \xB2\xB3\n\n"<<endl;
    cout<<"\t\t\t\t\t\t   Presented By:-kunal saini and krish saini"<<endl<<endl;
    cout<<"\n\t\t\t  *****************************************\n";
    cout<<"\t\t\t\t       GENDER SEARCHING";
    cout<<"\n\t\t\t  *****************************************\n\n";

    cout<<"\n\n\t\t\tEnter M|F to search by gender :   ";

    char search_gender;
    cin>>search_gender;
    int number_of_records_found = 0;

    ifstream in("records.txt");
    in.read((char*)this,sizeof(vaccine));
    int flag =0;
    first_row();
    while(!in.eof()){
        if(toupper(search_gender) == toupper(gender))/*Avoiding making cases seperatety by coverting to uppercase before comparision */
        {
            show_list();
            flag=1;
            number_of_records_found++;
        }
    in.read((char*)this,sizeof(vaccine));
    }

    if(flag == 0){
    cout<<"\n\t\t\tNo one with this gender has been vaccinnated yet!!!!"<<endl;
    }

    cout<<"\n\n\t\t\tNO. of people vaccinated by this gender are :  "<<number_of_records_found<<endl;
    in.close();

}// End of function

