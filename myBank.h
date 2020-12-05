#ifndef _MYBANK_H_
#define _MYBANK_H_

#define accounts 50

extern double bankAccounts [accounts][2]; //The max ammount of accounts that is possible

void open(double amount); //open one account
int isFull(); //get an id and return true if exist
void getBalance(int id); //get an account number and returns the balance if the account exist
void setDeposit(int id, double deposit); //set a deposit in an account if the account exist
void withdrawl(int id, double amount); //withdraw money from the account if the account exist and it has enough money
void close(int id); //close one account
void addInterest(double interest); //insert the money from the interest to all open bank accounts
void printAll(); //print all the open bank accounts numbers, and balance
void closeAll(); //close all the bank accounts including erasing their balance

#endif
