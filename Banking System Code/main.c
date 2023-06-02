#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

#define MAX_LEN 20

void auth();
int adminlogin();
int customerlogin();
void admin_function();
int customer_function(char* accountNum, char* cus_usr, char* atmpin);
void acc_open();
void trac_admin();;
void update_acc();
void delete_acc();
void check_acc();
int cus_check_details(char* accountNum);
void cus_trans(char* accountNum);
int atm(char* accountNum, char* atmpin);


typedef struct Account
{
    char accountName[40];
    char acctholfathernam[40];
    char accountNumber[20];
    char DateOfBirth[15];
    char address[50];
    char contactNum[15];
    char username[40];
    char upassword[40];
    float accountBalance;
    char atmPin[04];
} Account;

void main () {
    system("CLS"); 
    printf("\n\n\n\n\t\t\t\t\t ******************** WELCOME TO NEPAL BANK LIMITED ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t  Press any Key to Continue.............");
    getch();
    auth();
}

// Function to handle user to choose admin or customer login 
void auth() {
    int choice;
    
    // Prompt user to choose admin or customer login
    system("CLS");
    printf("\n\n\n\n\t\t\t\t\t ******************** WELCOME TO NEPAL BANK LIMITED ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t ======================= NEPAL BANK LOGIN SYSTEM ======================= \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t ******************** ENTER YOUR CREDENTAIL PROPERLY ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t - Select Login Type: \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t    1. Admin Login. \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t    2. Customer login. \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t - Exit           \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*****************************************\n\n\n");
    printf("\t\t\t\t\t\t+ Note : Enter 1 for Admin login or 2 for Customer Login or 3 for Exit. \n\n\n");
    printf("\t\t\t\t\t\t+ Your Choice: ");
    scanf("%d", &choice);

    // Call login function based on user's choice
    switch (choice)
    {
        case 1:
            adminlogin();  // Admin login
            break;
        case 2:
            customerlogin();  // Customer login
            break;
        case 3:
            system("CLS");   // Exit 
            printf("\n\n\n\n\t\t\t\t\t *********************  Thank you Admin ! See you Later ! ********************* \t\t\t\t\t\t\t\t\n");
            printf("\n\n\n\n\t\t\t\t\t ********************       Press any Key to Exit.....      ********************");
            getch();
            exit(0);

        default:

        // Invalid login function, calling auth() again.

            system("CLS");
            printf("\n\n\n\t\t\t\t\t\t\t\n\n\n\t\t\t\t\t\t\t*************************************************\n");
            printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
            printf("\t\t\t\t\t\t\t*\t Invalid choice ! \t\t\t*\n");
            printf("\t\t\t\t\t\t\t*\t Sorry please try again ! \t\t*\n");
            printf("\t\t\t\t\t\t\t*\t Note: You are only allowed to choose: \t*\n");
            printf("\t\t\t\t\t\t\t*\t 1 or 2 or 3        \t\t\t*\n");
            printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
            printf("\t\t\t\t\t\t\t*************************************************\n\n\n");
            printf("\t\t\t\t\t\t\t*\t Press any Key to continue.....");
            getch();
            auth();
    }
}

// Function to handle admin login option
int adminlogin(){
    
    // Declare variables for username and password
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    system("CLS");

    // Get username and password from user input
    printf("\n\n\n\n\t\t\t\t\t ******************** WELCOME TO NEPAL BANK LIMITED ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t ======================= NEPAL BANK LOGIN SYSTEM ======================= \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t ******************** ENTER YOUR CREDENTAIL PROPERLY ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t* Enter your Username: ( Maximum 20 ) \t*\n ");
    printf("\t\t\t\t\t\t\t* => ");
    scanf("%s", username);
    printf("\t\t\t\t\t\t\t* Enter your Password: ( Maximum 20 ) \t*\n ");
    printf("\t\t\t\t\t\t\t* => ");
    int i=0;
    char ch;
    while ((ch = _getch()) != 13) {
        // ch = _getch(); // read a character from the user input

        if (ch == '\n') {
            password[i] = '\0';
            break;
        } else if (ch == '\b') { // backspace key
            if (i > 0) {
                i--;
                printf("\b \b"); // erase the last character on the screen
            }
        } else if ( ch != '\n' ) {
            password[i] = ch;
            i++;
            printf("*"); // display  * on the screen to mask the password
        }
        password[i] = '\0';
    }  
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*****************************************\n\n\n");

    // Define the valid usernames and passwords for the system
    char valid_admin_username[20];
    char valid_admin_password[20];

    // file 
    FILE *admin_file;
    char a_user[MAX_LEN], a_password[MAX_LEN];

    char admin[] = "Admin/admin.txt";

    // Admin Username and Password
    admin_file = fopen(admin, "r");
    if (admin_file == NULL) { 
        printf("Unable to valid the User ! Please try again !");
        return 1;
    }
    fgets(a_user, MAX_LEN, admin_file);
    strtok(a_user, "\n");  // remove newline character
    fgets(a_password, MAX_LEN, admin_file);
    strtok(a_password, "\n");  // remove newline character

    fclose(admin_file);

    strcpy(valid_admin_username, a_user);
    strcpy(valid_admin_password, a_password);

    // Check if the user is an admin
    if (strcmp(username, valid_admin_username) == 0 && strcmp(password, valid_admin_password) == 0)
    {
        admin_function();
    }
    else {
        
        printf("\n\n\n\t\t\t\t\t\t\t*************************************************\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t Invalid Username or Password ! \t*\n");
        printf("\t\t\t\t\t\t\t*\t Sorry Please Try Again ! \t\t*\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*************************************************\n\n\n");
        printf("\t\t\t\t\t\t\t Press any Key to continue..... ");
        getch();
        auth();  

    }
    return 0;
}

// Function to handle customer login option
int customerlogin(){
    
    // Declare variables for username and password
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    Account accountInfo;
    int found = 0;
    

    system("CLS");

    // Get username and password from user input
    printf("\n\n\n\n\t\t\t\t\t ******************** WELCOME TO NEPAL BANK LIMITED ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t ======================= NEPAL BANK LOGIN SYSTEM ======================= \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t ******************** ENTER YOUR CREDENTAIL PROPERLY ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t* Enter your Username: ( Maximum 20 ) \t*\n ");
    printf("\t\t\t\t\t\t\t* => ");
    scanf("%s", username);
    printf("\t\t\t\t\t\t\t* Enter your Password: ( Maximum 20 ) \t*\n ");
    printf("\t\t\t\t\t\t\t* => ");
    int i=0;
    char ch;
    while ((ch = _getch()) != 13) {
        // ch = _getch(); // read a character from the user input

        if (ch == '\n') {
            password[i] = '\0';
            break;
        } else if (ch == '\b') { // backspace key
            if (i > 0) {
                i--;
                printf("\b \b"); // erase the last character on the screen
            }
        } else if ( ch != '\n' ) {
            password[i] = ch;
            i++;
            printf("*"); // display  * on the screen to mask the password
        }
        password[i] = '\0';
    }  
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*****************************************\n\n\n");

    // file 
    FILE *customer_file;

    // Customer  Username and Password from accountinfo.bin
    customer_file = fopen("Sys/accountInfo.bin", "rb");
    if ( customer_file == NULL ) {
        printf("Unable to valid the User ! Please try again !");
        return 0;
    }

    char *accountNumber = NULL;
    char *cus_username = NULL;
    char *atmpin = NULL;
    // Search for the account with the matching username and password
    while (fread(&accountInfo, sizeof(struct Account), 1, customer_file) == 1) {
        if (strcmp(username, accountInfo.username) == 0 &&
            strcmp(password, accountInfo.upassword) == 0) {
            found = 1;
            accountNumber = accountInfo.accountNumber;
            cus_username = accountInfo.username;
            atmpin = accountInfo.atmPin;
            break;
        }
    }

    if (found) {
        customer_function(accountNumber, cus_username, atmpin);
        return 0;
    } else {
        printf("\n\n\n\t\t\t\t\t\t\t*************************************************\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t Invalid Username or Password ! \t*\n");
        printf("\t\t\t\t\t\t\t*\t Sorry Please Try Again ! \t\t*\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*************************************************\n\n\n");
        printf("\t\t\t\t\t\t\t Press any Key to continue..... ");
        getch();
        auth();  
        return 0;
    }
    
    return 0;
}

// Function to handle admin login
void admin_function()
{
    // Admin Main Menu
    int choice_admin;
    lineno219:
    system("CLS");
    printf("\n\n\n\n\t\t\t\t\t ******************** WELCOME TO NEPAL BANK LIMITED ******************** \t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t\t\t ******************** Welcome Admin! ******************** \t\t\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t \xB2\xB2\xB2 ** Main Menu ** \xB2\xB2\xB2 \t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 1. Open Account. \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 2. Transaction on Account.\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 3. Update Account. \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 4. Delete Account. \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 5. Check all Account. \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 6. Exit. \t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*****************************************\n\n\n");
    printf("\t\t\t\t\t\t\t+ Note : Enter 1, 2 , 3 , 4, 5 or 6 ( According to option ) \n\n");
    printf("\t\t\t\t\t\t\t+ Your Choice: ");
    scanf("%d", &choice_admin);

     // Call login function based on admin's choice
    switch (choice_admin)
    {
        case 1:
            acc_open();  // Account Open
            goto lineno219;
            break;
        case 2:
            trac_admin();  // Transaction on Account
            goto lineno219;
            break;
        case 3:
            update_acc(); // Update Account
            goto lineno219;
            break;
        case 4:
            delete_acc();  // Delete Account
            goto lineno219;
            break;
        case 5:
            check_acc();  // Check all Account
            goto lineno219;
            break;
        case 6:
            system("CLS");   // Exit 
            printf("\n\n\n\n\t\t\t\t\t ******************** Thank you Admin ! See you Later ! ******************** \t\t\t\t\t\t\t\t\n");
            printf("\n\n\n\n\t\t\t\t\t ********************      Press any Key to Exit......      ******************** \t\t\t\t\t\t\t\t\n");
            getch();
            auth();
        default:

        // Invalid option, calling auth() again.

            system("CLS");
            printf("*************************************************\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*\t Invalid choice ! \t\t\t*\n");
            printf("*\t Sorry please try again ! \t\t*\n");
            printf("*\t Note: You are only allowed to choose: \t*\n");
            printf("*\t 1, 2, 3, 4, 5, or 6         \t\t\t*\n");
            printf("*\t\t\t\t\t\t*\n");
            printf("*************************************************\n\n\n");
            printf("\t\t\t\t\t\t\t  Press any Key to Continue..... \t\t\t\t\t\t\t\t");
            getch();
            goto lineno219;
            break;
    }
}

// Function to handle admin Account Opening
void acc_open() 
{
    FILE *fileopen = fopen("Sys/accountInfo.bin", "ab+");

    if (fileopen == NULL)
    {
        printf("\n\t\t\t Error in Creating Account\n");
    }

    Account accountInformation;

    system("CLS");

    printf("\n\n\n\n\n\t\t\t\t\t************************************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t====== Create Account ======\n");

    

    printf("\n\t\t\t\t\t\t\tEnter Account's Name : ");
    getchar();
    gets(accountInformation.accountName);
    printf("\n\t\t\t\t\t\t\tEnter Account Holder's Father Name : ");
    gets(accountInformation.acctholfathernam);
    printf("\n\t\t\t\t\t\t\tEnter Account's Number : ");
    gets(accountInformation.accountNumber);
    printf("\n\t\t\t\t\t\t\tEnter Account Holder's Date of birth ( DD/MM/YY ) : ");
    gets(accountInformation.DateOfBirth);
    printf("\n\t\t\t\t\t\t\tEnter Account Holder's Address ( Street , Town, District, Country ) : ");
    gets(accountInformation.address);
    printf("\n\t\t\t\t\t\t\tEnter Account Holder's Contact Number ( +977-XXXXXXXXXX ) : ");
    gets(accountInformation.contactNum);
    printf("\n\t\t\t\t\t\t\tEnter Account Holder's Username: ");
    gets(accountInformation.username);
    printf("\n\t\t\t\t\t\t\tEnter Account Holder's Password: ");
    gets(accountInformation.upassword);
    printf("\n\t\t\t\t\t\t\tEnter Current Account Balance : Rs  ");
    scanf("%f", &accountInformation.accountBalance);
    getchar();
    printf("\n\t\t\t\t\t\t\tEnter the Pin for ATM :  ");
    gets(accountInformation.atmPin);




    printf("\n\n\t\t\t\t\t\t************************************************************************************\n\n");
    fwrite(&accountInformation, sizeof(accountInformation), 1, fileopen);

    printf("\n\n\t\t\t\t\t\tAccount has been opened sucessfully\n");
    printf("\n\n\t\t\t\t\t\tPress any Key to Continue.......");
    getch();

    fclose(fileopen);
}

// Function to handle admin Transaction 
void trac_admin() 
{
    FILE *fileOne = fopen("Sys/accountInfo.bin", "rb");
    FILE *temp = fopen("Sys/temp.bin", "wb");

    Account accountInformation, temp_Info;

    int op, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("CLS");
    printf("\n\n\n\n\t\t\t\t\t\t\t************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t====== Account Transaction ======\n\n");

    printf("\t\t\t\t\t\t\t\t\tEnter Account Number : ");
    getchar();
    gets(temp_Info.accountNumber);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.accountNumber, temp_Info.accountNumber) == 0)
        {
            flag++;
            printf("\n\n\t\t\t\t\t\t\t\t\tDo you want to ?\n\n\t\t\t\t\t\t\t\t\t\t1. Deposit\n\n\t\t\t\t\t\t\t\t\t\t2. Withdraw\n\n\t\t\t\t\t\t\t\t\t- Exit ( 3 )\n\n\t\t\t\t\t\t\t\t\t+ Enter your choice: ");
            scanf("%d", &op);
            if (op == 1)
            {
                system("CLS");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Diposit ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\t+ Current Balance:Rs %.2f", accountInformation.accountBalance);
                printf("\n\n\t\t\t\t\t\t\t\t\t+ Enter the amount you want to deposit:Rs ");
                scanf("%f", &temp_Info.accountBalance);
                accountInformation.accountBalance += temp_Info.accountBalance;
                printf("\n\t\t\t\t\t\t\t\t\t+ Current Balance after Deposit:Rs %.2f", accountInformation.accountBalance);
                printf("\n\n\t\t\t\t\t\t\t************************************************************************************\n");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tDeposited successfully!\n\n");
            }
            else if (op == 2 )
            {
                system("CLS");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Withdraw ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\t+ Current Balance:Rs %.2f", accountInformation.accountBalance);
                printf("\n\n\t\t\t\t\t\t\t\t\t+ Enter the amount you want to withdraw:Rs ");
                scanf("%f", &temp_Info.accountBalance);
                if (accountInformation.accountBalance < temp_Info.accountBalance)
                {
                    printf("\n\t\t\t\t\t\t\t\t\t Unsufficient Balance!\n\n");
                    fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                }
                else
                {
                    accountInformation.accountBalance -= temp_Info.accountBalance;
                    printf("\n\t\t\t\t\t\t\t\t\tCurrent Balance after Withdraw:Rs %.2f", accountInformation.accountBalance);

                    fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                    printf("\n\n\t\t\t\t\t\t\t\t\tWithdraw Successfully!\n\n");
                }
            }
            else if (op == 3 )
            {
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
            else 
            {
                printf("\n\n\t\t\t\t\t\t\t Invalid Option");
                getch();
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    if (flag == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t\tAccount is not found");
    }

    fclose(fileOne);
    fclose(temp);

    remove("Sys/accountInfo.bin");
    rename("Sys/temp.bin", "Sys/accountInfo.bin");

    printf("\n\n\t\t\t\t\t\t\t\t\tPress any Key to Continue.......");
    getch();
}

// Function to handle admin Update Account
void update_acc() 
{
    FILE *fileOne = fopen("Sys/accountInfo.bin", "rb");
    FILE *temp = fopen("Sys/temp.bin", "wb");

    Account accountInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("CLS");
	
    printf("\n\n\n\n\t\t\t\t\t\t\t************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n");

    printf("\n\t\t\t\t\t\t\t\t\tEnter Account Number : ");
    getchar();
    gets(tempInformation.accountNumber);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.accountNumber, tempInformation.accountNumber) == 0)
        {
            flag++;
            printf("\n\t\t\t\t\t\t\t\t\t- Choose your option :\n\n\t\t\t\t\t\t\t\t\t\t1. Update Account Name.\n\n\t\t\t\t\t\t\t\t\t\t2. Update Account Holder's Father's Name.\n\n\t\t\t\t\t\t\t\t\t\t3. Update Date of Birth.\n\n\t\t\t\t\t\t\t\t\t\t4. Update Address.\n\n\t\t\t\t\t\t\t\t\t\t5. Update Contact No.\n\n\t\t\t\t\t\t\t\t\t\t6. Update Username.\n\n\t\t\t\t\t\t\t\t\t\t7. Update Pin\n\n\t\t\t\t\t\t\t\t\t\t8. Exit");
            printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter Account's Name to Update: ");
                getchar();
                gets(tempInformation.accountName);
                strcpy(accountInformation.accountName, tempInformation.accountName);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter Account Holder's Father's Name : ");
                getchar();
                gets(tempInformation.acctholfathernam);
                strcpy(accountInformation.acctholfathernam, tempInformation.acctholfathernam);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter Date of Birth to Update: ");
                getchar();
                gets(tempInformation.DateOfBirth);
                strcpy(accountInformation.DateOfBirth, tempInformation.DateOfBirth);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter Address to Update: ");
                getchar();
                gets(tempInformation.address);
                strcpy(accountInformation.address, tempInformation.address);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter Contact No. to Update: ");
                getchar();
                gets(tempInformation.contactNum);
                strcpy(accountInformation.contactNum, tempInformation.contactNum);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 6)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter New Username to Update: ");
                getchar();
                gets(tempInformation.username);
                strcpy(accountInformation.username, tempInformation.username);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 7)
            {
                system("cls");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Update Account Information ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter New ATM Pin to Update: ");
                getchar();
                gets(tempInformation.atmPin);
                strcpy(accountInformation.atmPin, tempInformation.atmPin);

                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
                printf("\n\n\t\t\t\t\t\t\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 8)
            {
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\t\t\t\t\t\t\tInvalid Option.");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("Sys/accountInfo.bin");
    rename("Sys/temp.bin", "Sys/accountInfo.bin");

    if (flag == 0)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tAccount is not found");
    }

    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to Continue.......");
    getch();
}

// Function to handle admin Delete Account
void delete_acc() 
{
    FILE *fileOne = fopen("Sys/accountInfo.bin", "rb");
    FILE *temp = fopen("Sys/temp.bin", "wb");

    Account accountInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("CLS");
    printf("\n\n\n\n\t\t\t\t\t\t\t************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t====== Delete Account Information ======\n");

    printf("\n\t\t\t\t\t\t\t\t\tEnter Account Number : ");
    getchar();
    gets(tempInformation.accountNumber);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.accountNumber, tempInformation.accountNumber) == 0)
        { 
            flag++;
            printf("\n\t\t\t\t\t\t\t\t\t\tAre you sure to delete ?\n\n\t\t\t\t\t\t\t\t\t\t1. Yes\n\n\t\t\t\t\t\t\t\t\t\t2. Back\n\n\t\t\t\t\t\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            printf("\n\n\t\t\t\t\t\t\t************************************************************************************\n");
            if (choice == 1)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\tAccount has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t\t\t\tInvalid Option");
                fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("Sys/accountInfo.bin");
    rename("Sys/temp.bin", "Sys/accountInfo.bin");

    if (flag == 0)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\tAccount is not found\n\n");
    }

    printf("\n\t\t\t\t\t\t\t\t\tPress any key to Continue.......");
    getch();
}

// Function to handle admin Check Account
void check_acc()
{
    FILE *fileOne = fopen("Sys/accountInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Account accountInformation;

    system("CLS");
    printf("\n\n\n\n\t\t\t\t\t\t\t************************************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t====== Display All Account's Information ======\n\n");

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        printf("\t\t\t\t\t\t\t\t\tx----x----x----x----x----x----x----x----x----x----x\n\n");
        printf("\t\t\t\t\t\t\t\t\tAccount Name : %s\n\n\t\t\t\t\t\t\t\t\tAccount Holder's father Name : %s\n\n\t\t\t\t\t\t\t\t\tAccount Number : %s\n\n\t\t\t\t\t\t\t\t\tDate of Birth : %s\n\n\t\t\t\t\t\t\t\t\tAddress : %s\n\n\t\t\t\t\t\t\t\t\tContact Number : %s\n\n\t\t\t\t\t\t\t\t\tUsername : %s\n\n\t\t\t\t\t\t\t\t\tCurrent Account's Balance : %.2f\n\n", accountInformation.accountName, accountInformation.acctholfathernam, accountInformation.accountNumber, accountInformation.DateOfBirth, accountInformation.address, accountInformation.contactNum, accountInformation.username, accountInformation.accountBalance);
        printf("\t\t\t\t\t\t\t\t\tx----x----x----x----x----x----x----x----x----x----x\n\n");
    }

    fclose(fileOne);
    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to Continue.......");
    getch();
}

// Function to handle customer login
int customer_function(char* accountNum, char* cus_usr, char* atmpin)
{
    // Customer Main Menu
    int choice_customer;
    lineno752:
    system("CLS");
    printf("\n\n\n\n\t\t\t\t\t ******************** WELCOME TO NEPAL BANK LIMITED ******************** \t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t\t\t ******************** Welcome %s ******************** \t\t\t\t\t\t\t\t\n\n\n", cus_usr);
    printf("\t\t\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t \xB2\xB2\xB2 ** Main Menu ** \xB2\xB2\xB2 \t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 1. Check Your Own Details \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 2. Transaction on Account.\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 3. ATM feature \t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t 4. Exit. \t\t\t*\n");
    printf("\t\t\t\t\t\t\t*\t\t\t\t\t*\n");
    printf("\t\t\t\t\t\t\t*****************************************\n\n\n");
    printf("\t\t\t\t\t\t\t+ Note : Enter 1, 2 , 3 or 4 ( According to option ) \n\n");
    printf("\t\t\t\t\t\t\t+ Your Choice: ");
    scanf("%d", &choice_customer);

    // Call login function based on user's choice
    switch (choice_customer)
    {
        case 1:
            cus_check_details(accountNum);  // customers check details
            goto lineno752;
            break;
        case 2:
            cus_trans(accountNum );  // Customer Transaction 
            goto lineno752;
            break;
        case 3:
            atm(accountNum, atmpin); // ATM feautres
            goto lineno752;
            break;
        case 4:
            system("CLS");   // Exit 
            printf("\n\n\n\n\t\t\t\t\t *********************  Thank you Customers ! See you Later ! ********************* \t\t\t\t\t\t\t\t\n");
            printf("\n\n\n\n\t\t\t\t\t ********************       Press any Key to Exit.....      ********************");
            getch();
            exit(0);

        default:

        // Invalid login function, calling auth() again.

            system("CLS");
            printf("\n\n\n\t\t\t\t\t\t\t\n\n\n\t\t\t\t\t\t\t*************************************************\n");
            printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
            printf("\t\t\t\t\t\t\t*\t Invalid choice ! \t\t\t*\n");
            printf("\t\t\t\t\t\t\t*\t Sorry please try again ! \t\t*\n");
            printf("\t\t\t\t\t\t\t*\t Note: You are only allowed to choose: \t*\n");
            printf("\t\t\t\t\t\t\t*\t 1 or 2 or 3 or 4        \t\t\t*\n");
            printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
            printf("\t\t\t\t\t\t\t*************************************************\n\n\n");
            printf("\t\t\t\t\t\t\t*\t Press any Key to continue.....");
            getch();
            auth();
    }

    return 0;
}

// Function to handle customer Check Account
int cus_check_details(char* accountNum) {

    FILE *detailsfile = fopen("Sys/accountInfo.bin", "rb");

    Account acc_details;
    int acc_found = 0;

    if (detailsfile == NULL )
    {
        printf("\n\t\t\tError !\n");
    }

    system("CLS");
    printf("\n\n\n\n\n\t\t\t\t\t************************************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t====== Your Bank Details ======\n");

    while (fread(&acc_details, sizeof(acc_details), 1, detailsfile) == 1) {

        if (strcmp(acc_details.accountNumber, accountNum) == 0) {

            acc_found = 1 ;
            break;
        }
    }
    fclose(detailsfile);

    // Print details of account if found
    if (acc_found) {
        printf("\t\t\t\t\t\t\t\tx----x----x----x----x----x----x----x----x----x----x\n\n");
        printf("\n\t\t\t\t\t\t\t\tAccount Name : %s\n\n\t\t\t\t\t\t\t\tAccount Holder's father Name : %s\n\n\t\t\t\t\t\t\t\tAccount Number : %s\n\n\t\t\t\t\t\t\t\tDate of Birth : %s\n\n\t\t\t\t\t\t\t\tAddress : %s\n\n\t\t\t\t\t\t\t\tContact Number : %s\n\n\t\t\t\t\t\t\t\tUsername : %s\n\n\t\t\t\t\t\t\t\tCurrent Account's Balance : %.2f\n\n", acc_details.accountName, acc_details.acctholfathernam, acc_details.accountNumber, acc_details.DateOfBirth, acc_details.address, acc_details.contactNum, acc_details.username, acc_details.accountBalance);
        printf("\n\t\t\t\t\t\t\t\tx----x----x----x----x----x----x----x----x----x----x\n\n");
    } else {
        printf("\t\t\t\t\t\t\t\tAccount not found\n");
    }

    printf("\n\n\t\t\t\t\tEnter any keys to continue.......");
    getch();
}


void cus_trans(char* accountNum) {

    char recevier[20];
    float amount;

    // open account info file
    FILE *file = fopen("Sys/accountInfo.bin", "r+b");
    if (file == NULL) {
        printf("\t\t\t\t\t\t\t Error: Could not open account info file.\n");
        return;
    }

    printf("\t\t\t\t\t\t\t+ Enter the account number: ");
    scanf("%s", recevier );

    // printf("Sender %s , Receiver %s, Amount %f", accountNum,  recevier, amount );

    Account from_account, to_account;
    
    // find 'Sender' account
    int found_from_account = 0, found_to_account = 0;

    while (fread(&from_account, sizeof(Account), 1, file) == 1) {
        if (strcmp(from_account.accountNumber, accountNum ) == 0) {
            found_from_account = 1;
            // printf("\t\t\t\t\t\t\t Sender Account found");
            printf("\t\t\t\t\t\t\t+ Enter the amount: Rs  ");
            scanf("%f", &amount );

            if (from_account.accountBalance < amount) {
                printf("\t\t\t\t\t\t\tError: Insufficient balance.\n");
                getch();
                fclose(file);
                return;
            }
            from_account.accountBalance -= amount;
            fseek(file, (long)(-sizeof(Account)), SEEK_CUR);
            fwrite(&from_account, sizeof(Account), 1, file);
            printf("\t\t\t\t\t\t\t Transaction Completed");
            getch();
            break;
        }
    }

    // find 'to' account
    fseek(file, 0, SEEK_SET);
    while (fread(&to_account, sizeof(Account), 1, file) == 1) {
        if (strcmp(to_account.accountNumber, recevier) == 0) {
            found_to_account = 1;
            to_account.accountBalance += amount;
            fseek(file, (long)(-sizeof(Account)), SEEK_CUR);
            fwrite(&to_account, sizeof(Account), 1, file);
            break;
        }
    }

    // close file and print message
    fclose(file);
    if (!found_from_account) {
        printf("Error: From account not found.\n");
        return;
    }
    if (!found_to_account) {
        printf("Error: To account not found.\n");
        return;
    }
    printf("Transaction successful.\n");
}


int atm(char* accountNum, char* atmpin) {

    int right_pin = atoi(atmpin);
    int enteredpin, count;
    int continuetransaction = 1;

    time_t now;
    time(&now);
    system("CLS");
    printf("\n\n");
    printf("\n\n\n\n\n\t\t\t\t\t************************************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t====== Welcome to ATM System ======\n\n");
    printf("\t\t\t\t\t\t\t\t    %s", ctime(&now));

    while (right_pin != enteredpin )
    {
    system("CLS");
    printf("\n\n\n\n\n\t\t\t\t\t************************************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t====== Welcome to ATM System ======\n");
    printf("\n\n\n\n\t\t\t\t\t Enter your Pin : ");
    scanf("%d", &enteredpin);
    }

    if ( enteredpin != right_pin ) {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t\t\n\n\n\t\t\t\t\t\t\t*************************************************\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t Invalid choice ! \t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t Sorry please try again ! \t\t*\n");
        printf("\t\t\t\t\t\t\t*\t Note: You are only allowed to choose: \t*\n");
        printf("\t\t\t\t\t\t\t*\t 1 or 2 or 3 or 4        \t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*************************************************\n\n\n");
        printf("\t\t\t\t\t\t\t*\t Press any Key to continue.....");
        getch();
    }
    count++;
    if( count == 3 && right_pin != enteredpin ) {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t\t\n\n\n\t\t\t\t\t\t\t*************************************************\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t No more allowed ! \t\t\t*\n");
        printf("\t\t\t\t\t\t\t*\t Sorry please try again later !  \t\t*\n");
        printf("\t\t\t\t\t\t\t*\t\t\t\t\t\t*\n");
        printf("\t\t\t\t\t\t\t*************************************************\n\n\n");
        printf("\t\t\t\t\t\t\t*\t Press any Key to continue.....");
        getch();
    }
    while ( continuetransaction != 0)
    {
    if ( enteredpin  = right_pin ) 
    {
        FILE *fileOne = fopen("Sys/accountInfo.bin", "r+b");
        // FILE *temp = fopen("Sys/temp.bin", "w+b");

        Account accountInformation, temp_Info;

        int op, flag = 0;

        if (fileOne == NULL)
        {
        printf("\n\t\t\tError !\n");
        }

        system("CLS");
        printf("\n\n\n\n\t\t\t\t\t\t\t************************************************************************************\n");
        printf("\t\t\t\t\t\t\t\t\t\t====== Account Transaction ======\n\n");

        strcpy(temp_Info.accountNumber, accountNum);

        while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
        {
            if (strcmp(accountInformation.accountNumber, temp_Info.accountNumber) == 0)
            {
            flag++;
            printf("\n\n\t\t\t\t\t\t\t\t\tDo you want to ?\n\n\t\t\t\t\t\t\t\t\t\t1. Deposit\n\n\t\t\t\t\t\t\t\t\t\t2. Withdraw\n\n\t\t\t\t\t\t\t\t\t- Exit ( 3 )\n\n\t\t\t\t\t\t\t\t\t+ Enter your choice: ");
            scanf("%d", &op);
            if (op == 1)
            {
                system("CLS");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Diposit ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\t+ Current Balance:Rs %.2f", accountInformation.accountBalance);
                printf("\n\n\t\t\t\t\t\t\t\t\t+ Enter the amount you want to deposit:Rs ");
                scanf("%f", &temp_Info.accountBalance);
                accountInformation.accountBalance += temp_Info.accountBalance;
                printf("\n\t\t\t\t\t\t\t\t\t+ Current Balance after Deposit:Rs %.2f", accountInformation.accountBalance);
                printf("\n\n\t\t\t\t\t\t\t************************************************************************************\n");
                fseek(fileOne, (long)(-sizeof(Account)), SEEK_CUR);
                fwrite(&accountInformation, sizeof(Account), 1, fileOne);
                printf("\n\n\t\t\t\t\t\t\t\t\tDeposited successfully!\n\n");
            }
            else if (op == 2 )
            {
                system("CLS");
                printf("\t\t\t\t\t\t\t************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t====== Withdraw ======\n\n");
                printf("\n\t\t\t\t\t\t\t\t\t+ Current Balance:Rs %.2f", accountInformation.accountBalance);
                printf("\n\n\t\t\t\t\t\t\t\t\t+ Enter the amount you want to withdraw:Rs ");
                scanf("%f", &temp_Info.accountBalance);
                if (accountInformation.accountBalance < temp_Info.accountBalance)
                {
                    printf("\n\t\t\t\t\t\t\t\t\t Unsufficient Balance!\n\n");
                    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
                }
                else
                {
                    accountInformation.accountBalance -= temp_Info.accountBalance;
                    printf("\n\t\t\t\t\t\t\t\t\tCurrent Balance after Withdraw:Rs %.2f", accountInformation.accountBalance);

                    fseek(fileOne, (long)(-sizeof(Account)), SEEK_CUR);
                    fwrite(&accountInformation, sizeof(Account), 1, fileOne);
                    printf("\n\n\t\t\t\t\t\t\t\t\tWithdraw Successfully!\n\n");
                }
            }
            else if (op == 3 )
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t Thank you ! Visit Again.......\n\n");
                return 0;
            }
            else 
            {
                printf("\n\n\t\t\t\t\t\t\t Invalid Option");
                getch();
                fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
            }
            }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
        }
        }

        if (flag == 0)
        {
            printf("\n\t\t\t\t\t\t\t\t\tAccount is not found");
        }   

        fclose(fileOne);
        // fclose(temp);

        remove("Sys/accountInfo.bin");
        rename("Sys/temp.bin", "Sys/accountInfo.bin");

        printf("\n\n\t\t\t\t\t\t\t\t\tPress any Key to Continue.......");
        getch();
    }
    }

    printf("\t\t\t\t\t\t\t\t + Do You want to Continue ? ");
    printf("\t\t\t\t\t\t\t\t + Press 1 for Continue or 0 for Exit ");
    scanf("%d",&continuetransaction);
    
   
    return 0;
}
