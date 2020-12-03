#include <stdio.h>
#define set 901


static double account[50][2];

void Open_Account(double amount)
{
    int i =0;
    while(i-50){
        if(account[i][0] == 0)
        {
            account[i][0] = 1;
            account[i][1] = amount;
            printf("Account number %d has been opened\n", i+set);
            break;
        }
        i++;

    }
    
    if(i == 50){printf("Accounts from 901 - 950 are already open, action cancelled\n");}
}

void Balance(int account_number)
{
    if(account_number > 900 && account_number < 951)
    {
        if(account[account_number - set][0] == 1)
        {
            printf("This account has a balance of: %.2lf\n", account[account_number - set][1]);
        }
        else
        {
           printf("Account number %d is currently closed, please try a diffrent account that is open\n", account_number);
        }
    }

    else
    {
        printf("Account number %d is out of bounds, please enter a number between 901 - 950\n", account_number);
    }
}

void Deposit(int account_number, double amount)
{
    if(account_number > 900 && account_number < 951)
    {
        if(account[account_number - set][0] == 1)
        {
            if(amount >= 0)
            {
            account[account_number - set][1] = account[account_number - set][1] + amount;
            printf("This account now has a balance of: %.2lf\n",account[account_number - set][1]);
            }
            else{printf("The input number is negative, no action was taken\n");}
        }
        else
        {
            printf("Account number %d is currently closed, please try a diffrent account that is open\n", account_number);
        }
    }

    else
    {
        printf("Account number %d is out of bounds so no action was commited, please eneter a number between 901 - 950\n", account_number);
    }
}

void Withdrawal(int account_number, double amount)
{
    if(account_number > 900 && account_number < 951)
    {
        if(account[account_number - set][0] == 1)
        {
            if(amount >= 0)
            {
                if(account[account_number - set][1] - amount >= 0)
                {
                
                    account[account_number - set][1] = account[account_number - set][1] - amount;
                    printf("This account now has a balance of: %.2lf\n",account[account_number - set][1]);
                }

                else
                {
                    printf("withdrawal amount exceeds the current balance of account number %d, withdrawal cancelled\n",account_number);
                }
            }
            else
            {
                printf("The amount given to withdraw is a negative, please try again with a non negative number\n");
            }
        }
        else
        {
            printf("Account number %d is currently closed, please try a diffrent account that is open\n", account_number);
        }
    }

    else
    {
        printf("Account number %d is out of bounds so no action was commited, please eneter a number between 901 - 950\n", account_number);
    }
}

void Close_Account(int account_number)
{
    if(account_number > 900 && account_number < 951)
    {
        if(account[account_number - set][0] == 1)
        {
            account[account_number - set][0] = 0;
            account[account_number - set][1] = 0;
        }
        
        else
        {
            printf("Account number %d is already closed, no action necessary \n", account_number);
        }
    }

    else
    {
        printf("Account number %d is out of bounds so no action was commited, please eneter a number between 901 - 950\n", account_number);
    }
}

void Interest(int intrest_rate)
{
    if(intrest_rate >= 0)
    {
        double num;
        num = (double)intrest_rate / 100 +1;
        
        for(int i = 0; i < 50; ++i)
        {
            if(account[i][0] == 1) 
            {
                account[i][1] = (account[i][1] * num);
            }
        }
    }
    else
    {
        printf("will not take into account 'negative intrest', action cancelled\n");
    }
}

void Print()
{
    for(int i = 0; i<50;++i)
        {
            if(account[i][0] == 1) {printf("Account number %d currently has a balance of: %.2lf\n", i+set, account[i][1]);}
        }
}

void Exit()
{
    for(int i = 0; i<50;i++)
        {
            if(account[i][0] == 1) 
            {
                account[i][0] = 0;
                account[i][1] = 0;
            }
        }

    printf("All accounts closed, have a nice day!\n");
    
}

//Utility functions

double number(double amount)
{//checks if the input number is correct
    if (scanf(" %lf", &amount) != 1)
    {
        printf("Invalid input, input set to 0\n");
        return 0;
    }
    else 
    {
        return amount;   
    }
}

double money(double amount)
{
    int temp;
    amount = amount*100;
    temp = (int)amount;
    amount = temp/100.0;
    return amount;
}

