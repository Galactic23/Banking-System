#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include<vector>

using namespace std;



//change CustomerLogin to login 
class Login {


public:
    string username;
    string password;
    bool AcessGranted;


    Login()
    {
        admin.push_back("admin");
        admin.push_back("password");

        position.push_back(admin);

        customer.push_back("customer123");
        customer.push_back("password2");

        position.push_back(customer);

        AcessGranted = 0;

    }

    vector<string> admin;
    vector<string> customer;
    vector<vector<string>> position;
    int loginAttempt;
    int option;
    int choice;


    int checkerID(string UserID)
    {
        int  counter = 0;
        for (int i = 0; i < position.size(); i++)
        {
            for (int j = 0; j < position[i].size(); j++)
            {
                if (UserID == position[0][j])
                    return 0;
                if (UserID == position[1][j])
                    return 1;
            }
            counter += 1;
        }
        if (counter == position.size())
            return -1;

        else return -2;
    }
    int checkerpswrd(string Password)
    {
        int  counter = 0;
        for (int i = 0; i < position.size(); i++)
        {
            for (int j = 0; j < position[i].size(); j++)
            {
                if (Password == position[0][j])
                    return 0;
                if (Password == position[1][j])
                    return 1;
            }
            counter += 1;
        }
        if (counter == position.size())
            return -1;

        else return -2;
    }
    void Login_page() {

        string UserID;
        string Password;

        cout << "Enter your Username ID:  ";
        cin >> UserID;

        //if admin 
        if (0 == checkerID(UserID))
        {

            cout << "Password:   ";
            cin >> Password;

            if (0 == checkerpswrd(Password)) {
                cout << "Logged in..." << endl << endl;
                option = 0;
            }
            else {
                cout << "Invalid Password!" << endl;
                cout << "Please try again." << endl;
                Login_page();
            }
        }
        //else if customer 
        else if (1 == checkerID(UserID)) {


            cout << "Password:   ";
            cin >> Password;

            if (1 == checkerpswrd(Password)) {
                cout << "Logged in..." << endl << endl;
                option = 1;
            }
            else //if password is bad you get this prompt 
            {
                cout << "Invalid Password!" << endl;
                cout << "Please try again." << endl;
                Login_page();
            }
        }

        else {
            cout << "Invalid Username!" << endl;
            cout << "Please try again." << endl;
            Login_page();
        }
    }

};

class Bank :public Login {
public:
    int bank_choice;
    Bank()
    {
        bank_choice = 1;
    }



    int options_bank() {

        cout << "****Welcome to Administration Page****" << endl

            << " 1. View Account Details " << endl
            << " 2. View Loan Details " << endl
            << " 3. Transactions " << endl
            << " 4. Approve Loan" << endl
            << " 5.Approve Transactions" << endl
            << " 6. Update Details " << endl
            << " 7.Generate Interest " << endl;

        cout << "Choose an option: ";
        cin >> bank_choice;
        cout << endl;

        return bank_choice;
    }
    void Bank_page() {

        bank_choice = options_bank();

        //while loop for customer's options
        while (bank_choice != 0) {
            switch (bank_choice)
            {
            case 1: viewAccountDetails();
                break;

            case 2:viewLoanDetails();
                break;

            case 3:  transactionInfo();
                break;

            case 4: bankApproveLoan();
                break;

            case 5: bankApproveTransaction();
                break;

            case 6:bankUpdateDetails();

                break;

            case 7:bankGenerateInterest();
                break;

            }
            bank_choice = options_bank();
        }
    }
    void viewAccountDetails() {
        char option;
        cout << "Would you like to view customer account information? Y or N";
        cin >> option;
        if (option == 'Y')
        {
            cout << "Displaying Account innformation" << endl;

        }
        else if (option == 'N')
        {
            cout << "Returning to main menu" << endl;
        }
        else {
            cout << "No option selected!" << endl;
        }
    }

    void viewLoanDetails() {
        char option;
        cout << "Display customer loan details, Y or N?";
        cin >> option;

        if (option == 'Y') {
            // Display_loan_amount;
             //Display_loan_type;
             //Display_customer_name;
             //Display_customer_ID;
        }
        else if (option == 'N') {
            cout << "Returning to main menu" << endl;
        }
        else {
            cout << "No option selected" << endl;
        }
    }

    void transactionInfo() {
        int price;
        string transactionName;
        int time;
        cout << "Your last transaction was" << endl;
        cin >> transactionName;
        price;
        time;

    }

    void bankGenerateInterest()
    {
        double currentBalance = { 0 };
        double rate = 0.05;
        int time = 12;
        double interest = 0.05;

        interest = currentBalance * rate * time;

        cout << interest;


    }

    void bankApproveLoan()
    {
        char bankAprroval;

        cout << "Would you like to approve this Loan?" << endl;
        cin >> bankAprroval;
        if (bankAprroval == 'Y')
        {
            cout << "You have been approved for the current transaction!";
        }
        else
            cout << "You have not been approved";

    }

    void bankApproveTransaction()
    {
        char bankAprroval;

        cout << "Would you like to approve this transaction?" << endl;
        cin >> bankAprroval;
        if (bankAprroval == 'Y')
        {
            cout << "You have been approved for the current transaction!";
        }
        else
            cout << "You have not been approved";

    }

    void bankUpdateDetails()
    {
        int bankInput;
        char name;
        char password;
        int PhoneNumber;
        int userId;
        cout << "What will you like to update? (1name/2password/3userId/4phone) ? " << endl;
        cin >> bankInput;

        bankInput = toupper(bankInput); //makes string all caps, for no case sensitive issues

        if (bankInput == 1)
        {
            cout << "Change Name " << endl;
            cin >> name;
        }
        else if (bankInput == 2)
        {
            cout << "Change Password " << endl;
            cin >> password;
        }
        else if (bankInput == 3)
        {
            cout << "Input New User ID " << endl;
            cin >> userId;
        }
        else if (bankInput == 4)
        {
            cout << "Input New Phone Number " << endl;
            cin >> PhoneNumber;
        }
        else
            NULL;
    }




};

class Customer_Service : public Bank // parent class will be changed to custommer class
{
public:
    int id{};
    string name{};
    int cust_choice;
    //constructor 
    Customer_Service(int id_customerserv = 0, const std::string& name_customerserv = "")
        : id{ id_customerserv }, name{ name_customerserv }
    {
    }
    //return name
    const std::string& getName() const { return name; }
    //return id
    int getid() const { return id; }




    int cust_service_option() {

        cout << "****Welcome to Customer Service****" << endl

            << " 1. Open Account " << endl
            << " 2. Close Account " << endl
            << " 3. Loan Request " << endl
            << " 4. Provide Information " << endl
            << " 5. Issue Card " << endl
            << " 6. Replace Card " << endl
            << " 7. Replace Checkbook " << endl
            << " 8. Go Back To Options" << endl; // always make this option last

        cout << "Choose an option: ";
        cin >> cust_choice;
        cout << endl;

        return cust_choice;
    }
    void page(double& bal2, bool& LoanDec, int& loanAmount, long& accountNum2, bool& newaccount) {

        cust_choice = cust_service_option();

        //while loop for customer's options
        while (cust_choice != 0) {
            switch (cust_choice)
            {
            case 1: CustomerOpenNewAccount(accountNum2, newaccount);
                break;

            case 2:CloseAccount(bal2, accountNum2, newaccount);
                break;

            case 3:  LoanRequest(LoanDec, loanAmount);
                break;

            case 4: ProvideInfo();
                break;

            case 5:  issueCard();
                break;

            case 6: replaceCard();
                break;

            case 7: replaceCheckBook();
                break;

            case 8: goBackToOptions();
                return;
            }
            cust_choice = cust_service_option();
        }
    }

    //change to int
    void CustomerOpenNewAccount(long& accountNum2, bool& newaccount) {
        char userInput;
        int option;

        if (newaccount)
        {
            cout << "You may only have two accounts." << endl;
            cout << endl;
            return;
        }

        cout << "Would you like to open a new account? Y/N" << endl;
        cin >> userInput;

        userInput = toupper(userInput);

        if (userInput == 'Y')
        {
            cout << "What type of account will you be opening?" << endl
                << "1. Checking account" << endl
                << "2. Savings accounnnt" << endl;

            cout << "Please choose an option" << endl;
            cin >> option;

            accountNum2 = rand() % 30 + 100000000000000;

            cout << "Congrats on opening account. Your Account #: " << accountNum2;
            cout << endl;
            newaccount = true;
        }

        else
        {
            return;
        }
    }

    void CloseAccount(double& bal2, long& accountNum2, bool& newaccount) { //only closes new account

        if (newaccount == true)
        {
            char response;
            cout << "Do you wish to delete your 2nd account? (Y/N) " << endl;
            cin >> response;

            response = toupper(response);

            if (response == 'Y')
            {
                newaccount = 0;
                bal2 = 0;
                accountNum2 = 000000000;

                cout << "You have successfully deleted your 2nd account." << endl;
                cout << endl;
            }
            else
            {
                cout << "We are glad to hear that you will be keeping your 2nd account. " << endl;
                cout << endl;
            }
        }
        else
        {
            cout << "You cannot choose delete your 2nd account, because it does not exist." << endl;
            cout << endl;
        }
    }

    void LoanRequest(bool& LoanDecision, int& loan) {
        string option;


        if (LoanDecision)
        {
            cout << "You cannot apply for a new loan, if you have an existing loan with our bank. " << endl;
            cout << endl;
            return;
        }

        cout << "Would you like to apply for a loan? Y/N " << endl;
        cin >> option;
        cout << "What amount are you looking to loan? " << endl;
        cin >> loan;

        transform(option.begin(), option.end(), option.begin(), ::toupper);

        if (option == "Y" || option == "YES")
        {
            LoanDecision = rand() % 2;

            if (LoanDecision == 1)
            {
                cout << "Congratulations, You've been approved for a loan of $" << loan << "." << endl;
                cout << endl;
            }
            else
            {
                cout << "After review, we are sorry to inform you that you have been decline for a loan." << endl;
                cout << endl;
            }
        }
        else if (option == "NO" || option == "N")
        {
            cout << "Sorry to hear that, hope you can reconsider on the loan in the future. " << endl;
            cout << endl;
        }
        else
        {
            cout << "Incorrect input. Try again" << endl;
            LoanRequest(LoanDecision, loan);
        }
    }

    void ProvideInfo() {
        string short_answer;
        cout << "what information are you currently looking for?";
        cout << endl;
        /*For this we can give options to the user and they chose the one closely related and information is displayed and if they have further
        questions or their issue isnt an option we can put an option to call a costumer service rep*/
        cin >> short_answer;

        if (0 == 0) {
            //short_questions(short_answer) is true [input for IF STATEMENT]
            //finish document part
            cout << " searching ... " << endl;

            //cout << file_with_links;
        }
        else
            cout << "Sorry we have not found anything related to your search. Please ";
        cout << "contact 111-111-1111, for better attendance." << endl;

    }

    void issueCard() {

        char option;
        cout << "Would you like to order a new card?";
        cin >> option;
        if (option == 'y') {
            cout << "You will receive a new card with 2-5 business days!" << endl;
        }
        else {
            cout << "Anytime you want to order a new card please visit this page!" << endl;
        }

    }

    void replaceCard() {
        char option;

        cout << "Would you like to replace your card, Y or N?";
        cin >> option;

        if (option == 'Y') {
            //remove_card;
            cout << "Your new card will be delivered in a few days" << endl;
        }
        else {
            cout << "Returning to main menu" << endl;
        }
    }

    void replaceCheckBook() {
        char option;
        int reason;
        cout << "Would you like to replace your checkbook, Y or N";
        cin >> option;
        if (option == 'Y') {
            cout << "What is the reason your check book needs replacing? 1. Lost 2. Stolen 3. New one needed 4. Other. Please type 1, 2, 3, or 4 for your reason";
            cin >> reason;
        }
        if (reason == 1) {
            cout << "Thank you a new checkbook will be sent right away";
        }
        else if (reason == 2) {
            cout << "Thank you we will monitor you account for any fishy activity and your new check book should arrive in the next few days" << endl;
        }
        else if (reason == 3) {
            cout << "Thank you a new check will be sent right away" << endl;
        }
        else if (reason == 4) {
            cout << "Please state your reason and we will contact you as soon as possible" << endl;
        }
        else {
            cout << "No valid option selected returning to main menu, please try again" << endl;
        }
    }
    void goBackToOptions() {
        char option;
        cout << " Do you want to go back to options?" << endl;
        cin >> option;
        if (option == 'Y') {
            return;
        }
        else {
            return;
        }
    }

};


class Customer :public Customer_Service {
public:
    string newpassword;
    int accountNum{};
    int loginAttemp;

    int choice;
    double bal = { 0 }; //initilize balance
    double bal2 = { 0 }; //initilize balance 2
    bool loan{}; //initilize loan
    int loanAmount = { 0 };
    long accountNum2 = { 0 };//initilize accountNo2
    bool newAcc{};//initilize accountNo

    Customer()
    {

        string password = "password";
        string newpassword = "password123";
        int accountNum = 473728347;
        bool AcessGranted;
    }
    void customer_page()
    {

        choice = user_option();

        //while loop for customer's options
        while (choice != 0) {

            switch (choice) {

            case 1: Deposit(bal, bal2, accountNum2, newAcc);
                break;

            case 2: Withdraw(bal, bal2, accountNum2, newAcc);
                break;

            case 3: Balance(bal, bal2, loanAmount, accountNum2, newAcc);
                break;

            case 4: ChangePassword();
                break;

            case 5: TransferFunds(bal, bal2, accountNum2, newAcc);
                break;

            case 6: accountInfo();
                break;

            case 7: zipcode();
                break;

            case 8:  Customer_Service::page(bal2, loan, loanAmount, accountNum2, newAcc);

                break;
            }
            choice = user_option();

        }



    }
    int user_option() {

        cout << "****Welcome to Chase****" << endl

            << " 1. Deposit " << endl
            << " 2. Withdraw " << endl
            << " 3. Balance " << endl
            << " 4. Change Password " << endl
            << " 5. Transfer Funds " << endl
            << " 6. Update Account Information " << endl
            << " 7. Locate ATM " << endl
            << " 8. Contact Costumer Service " << endl;

        cout << "Choose an option: ";
        cin >> choice;
        cout << endl;


        return choice;
    }

    void Deposit(double& balance, double& balance2, long& accountNum2, bool& newaccount) {
        double deposit;

        if (newaccount == 1)
        {
            int input;
            cout << "Which Account do you want to deposit to? (1 or 2)" << endl << "1. " << accountNum << endl << "2. " << accountNum2 << endl;
            cin >> input;

            if (input == 1)
            {
                cout << fixed << setprecision(2) << "Current Balance is $" << balance << endl;
                cout << "How much would you like to deposit? " << endl;
                cin >> deposit;

                balance = balance + deposit;

                cout << fixed << setprecision(2) << "Thank You, your new balance is $" << balance << endl;
                cout << endl;
            }
            else
            {
                cout << fixed << setprecision(2) << "Current Balance is $" << balance2 << endl;
                cout << "How much would you like to deposit? " << endl;
                cin >> deposit;

                balance2 = balance2 + deposit;

                cout << fixed << setprecision(2) << "Thank You, your new balance is $" << balance2 << endl;
                cout << endl;
            }
        }

        else
        {
            cout << fixed << setprecision(2) << "Current Balance is $" << balance << endl;
            cout << "How much would you like to deposit? " << endl;
            cin >> deposit;

            balance = balance + deposit;

            cout << fixed << setprecision(2) << "Thank You, your new balance is $" << balance << endl;
            cout << endl;
        }

    }
    void Withdraw(double& balance, double& balance2, long accountNum2, bool& newaccount) {
        double cash;

        if (newaccount == 1)
        {
            int input;
            cout << "Which Account do you want to withdraw from? (1 or 2)" << endl << "1. " << accountNum << endl << "2. " << accountNum2 << endl;
            cin >> input;

            if (input == 1)
            {
                cout << "How much would you like to withdraw? " << endl;
                cin >> cash;

                if (cash > balance)
                {
                    cout << "You have insufficient funds to withdraw $" << cash << " from your account." << endl;
                    cout << endl;
                }
                else if (balance == 0)
                {
                    cout << "There is no funds in your account, please deposit first or use another account " << endl;
                    cout << endl;
                }
                else if (cash > 500)
                {
                    cout << "To withdraw more than $500, you will have to visit one of our bank facilities. Thank you and have a nice day. " << endl;
                    cout << endl;
                }
                else
                {
                    balance = balance - cash;

                    cout << fixed << setprecision(2) << "You have successfully withdrawn $" << cash << endl;
                    cout << fixed << setprecision(2) << "Your new balance is $" << balance << endl;
                    cout << endl;
                }
            }
            else if (input == 2)
            {
                cout << "How much would you like to withdraw? " << endl;
                cin >> cash;

                if (cash > balance2)
                {
                    cout << "You have insufficient funds to withdraw $" << cash << " from your account." << endl;
                    cout << endl;
                }
                else if (balance2 == 0)
                {
                    cout << "There is no funds in your account, please deposit first or use another account " << endl;
                    cout << endl;
                }
                else if (cash > 500)
                {
                    cout << "To withdraw more than $500, you will have to visit one of our bank facilities. Thank you and have a nice day. " << endl;
                    cout << endl;
                }
                else
                {
                    balance2 = balance2 - cash;

                    cout << fixed << setprecision(2) << "You have successfully withdrawn $" << cash << endl;
                    cout << fixed << setprecision(2) << "Your new balance is $" << balance2 << endl;
                    cout << endl;
                }
            }
            else
            {
                cout << "Incorrect input. Select the appropriate account 1 or 2" << endl;
                cout << endl;
            }

        }
        else
        {
            cout << "How much would you like to withdraw? " << endl;
            cin >> cash;

            if (cash > balance)
            {
                cout << "You have insufficient funds to withdraw $" << cash << " from your account." << endl;
                cout << endl;
            }
            else if (balance == 0)
            {
                cout << "There is no funds in your account, please deposit first or use another account " << endl;
                cout << endl;
            }
            else if (cash > 500)
            {
                cout << "To withdraw more than $500, you will have to visit one of our bank facilities. Thank you and have a nice day. " << endl;
                cout << endl;
            }
            else
            {
                balance = balance - cash;

                cout << fixed << setprecision(2) << "You have successfully withdrawn $" << cash << endl;
                cout << fixed << setprecision(2) << "Your new balance is $" << balance << endl;
                cout << endl;
            }
        }
    }
    void Balance(double& balance, double& balance2, int& loan, long& accountNum2, bool& newaccount) {

        if (newaccount == 1)
        {
            if (loan > 0)
            {
                cout << "Account Number: " << accountNum << endl;
                cout << "Your account balance is $" << balance << endl;
                cout << "Account Number: " << accountNum2 << endl;
                cout << "Your account balance is $" << balance2 << endl;
                cout << "Total Loan Amount: $" << loan << endl;
                cout << endl;

            }
            else
            {
                cout << "Account Number: " << accountNum << endl;
                cout << "Your account balance is $" << balance << endl;
                cout << "Account Number: " << accountNum2 << endl;
                cout << "Your account balance is $" << balance2 << endl;
                cout << endl;
            }


        }
        else if (loan > 0)
        {
            cout << "Account Number: " << accountNum << endl;
            cout << "Your account balance is $" << balance << endl;
            cout << "Total Loan Amount: $" << loan << endl;
            cout << endl;

        }
        else
        {
            cout << "Account Number: " << accountNum << endl;
            cout << "Your account balance is $" << balance << endl;
            cout << endl;
        }
    }
    void TransferFunds(double& bal, double& bal2, long& accountNum2, bool& newaccount)
    {
        int transfer;
        if (newaccount == 1)
        {
            int user_input = { 0 };
            cout << "Which account do you want to transfer money from? (1 or 2)" << endl << "1. " << accountNum << endl << "2. " << accountNum2 << endl;
            cin >> user_input;


            if (user_input == 1)
            {
                cout << "How much money would you like to transfer into your 2nd account? " << endl;
                cin >> transfer;

                if (transfer > bal)
                {
                    cout << "Insuffient funds to transfer, since the desired amount exceeds the balance from the account." << endl;
                    cout << endl;
                }
                else
                {
                    bal = bal - transfer;
                    bal2 = bal2 + transfer;
                }
                user_input = 0;
            }
            else if (user_input == 2)
            {
                cout << "How much money would you like to transfer into your 1st account? " << endl;
                cin >> transfer;

                if (transfer > bal2)
                {
                    cout << "Insuffient funds to transfer, since the desired amount exceeds the balance from the account." << endl;
                    cout << endl;
                }
                else
                {
                    bal2 = bal2 - transfer;
                    bal = bal + transfer;
                }
                user_input = 0;
            }
        }
        else
        {
            cout << "You only have 1 account, therefore you cannot transfer any funds. " << endl;
            cout << endl;
        }
    }
    void accountInfo()
    {
        char firstName[15], lastName[15], streetName[30], city[30], state[30];

        int streetNumber, zipcode;

        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Street Number: ";
        cin >> streetNumber;
        cout << "Street Name: ";
        cin >> streetName;
        cout << "city: ";
        cin >> city;
        cout << "state: ";
        cin >> state;
        cout << "zipcode: ";
        cin >> zipcode;

        cout << "Hello, " << firstName << " " << lastName << endl;
        cout << "You have updated your current address to " << endl;
        cout << streetNumber << " " << streetName << ", " << city << ", " << state << ", " << zipcode << endl;

    }
    void zipcode()
    {
        string zipCode;

        cout << "Please enter a zipcode: ";
        cin >> zipCode;
        cout << "https://www.google.com/maps/d/viewer?msa=0&mid=1L82VgoYGPWcjzE4vX7bOu5stCDQ&ll=48.74856204820343%2C-122.47680000000001&z=17" << endl;
        cout << "These are all the closests banks/ATM's to you" << endl;
    }
    void ChangePassword()
    {
        string password2;

        cout << "Please enter current password. ";
        cin >> password;
        cout << "Please enter new password. ";
        cin >> password2;

        if (password2 == newpassword)
        {
            cout << "Password Updated." << endl;
        }
        else {

            cout << " Unable to update Password" << endl;
        }




    }

private:

};

int main() {

    Login obj;//Object created to execute program
    Bank obj2;
    Customer obj3;
    Customer_Service obj5;

    obj.Login_page();// execute login page

    if (obj.option == 0)
        obj2.Bank_page();

    else if (obj.option == 1)
        obj3.customer_page();
    else
    {
        system("pause");
        return 0;
    }
}