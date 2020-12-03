#include "myBank.h"

int main()
{
    void initReset();
    char choice = 0;

    printf("Welcome to account managment for accounts 901 - 950\n");
    printf("press the 'O' key to open a new account and give it an intitial balance\n");
    printf("press the 'B' key to check the balance of an open account\n");
    printf("press the 'D' key to add additional income to the given account\n");
    printf("press the 'W' key to withdraw funds from the account\n");
    printf("press the 'C' key to close an open account\n");
    printf("press the 'I' key to add intrest to all the open accounts\n");
    printf("press the 'P' key to print all the open accounts and their balance\n");
    printf("press the 'E' key to close all accounts and exit the program\n");
    
    while(choice != 'E')
    {
        printf("Transaction type?:");
        double accountNum = 0;
        double amount = 0;
        
        scanf(" %c", &choice);
        switch(choice)
        {
        case 'O':
            printf("Amount?:");
            amount = number(amount); 
            amount = money(amount);
            Open_Account(amount);
            break;
        case 'B':
            printf("Account number?:\n");
            accountNum = number(accountNum);
            Balance((int)accountNum);
            break;
        case 'D':
            printf("Account number?:\n");
            accountNum = number(accountNum);

            printf("Amount?:\n");
            amount = number(amount);
            amount = money(amount);
            Deposit((int)accountNum,amount);
            break;
        case 'W':
            printf("Account number?:\n");
            accountNum = number(accountNum);

            printf("Amount?:\n");
            amount = number(amount);
            amount = money(amount);
            Withdrawal((int)accountNum, amount);
            break;
        case 'C':
            printf("Account number?:\n");
            accountNum = number(accountNum);         
            Close_Account((int)accountNum);
            break;
        case 'I':
            printf("Interest rate?:\n");
            amount = number(amount);
            Interest((int)amount);
            break;
        case 'P':
            Print();
            break;
        case 'E': 
            Exit();
            break;
        //if the choice input was invalid
        default:
            
            printf("invalid action, please try again and make sure you are using capital letters\n");
        }
    }
    return 0;
}
