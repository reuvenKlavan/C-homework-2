#include <stdio.h>
#include "myBank.h"

double bankAccounts [accounts][2]={0};

//if the bank is full return 1.
int isFull() {
	int i;
	for (i = 0; i < accounts; i++) {
		if (bankAccounts[i][0] == 0) return 0;
	}
	return 1;
    }

//open new account with given amount
			void open(double amount) {
				int count = 901;
				int i;
				if (amount >= 0){
					if (isFull() != 1) {
						for (i = 0; i < accounts; i++) {
							if (bankAccounts[i][0] == 0) {
								bankAccounts[i][0] = count;
								bankAccounts[i][1] = amount;
					printf("Your new account number is %d\n", count);
					break;
							}
							count++;
						}
						count = 901;
					}
					else {
						printf("the bank is full\n");
					}
				}
				else {printf ("invalid amount\n");
				}	
			}

//return balance of a valid account
			void getBalance(int id) {
					int flag = 0;
					int i;				
				for (i = 0; i < accounts; i++) {
					if (bankAccounts[i][0] == id) {
						printf("your balance is: %0.2lf\n", bankAccounts[i][1]);
						flag = 1;
					}
				}
					if (flag == 0) printf("the account dosent exist\n");
			}

//enter the given deposit to the given account
			void setDeposit(int id, double deposit) {
				int flag = 0;
				int i;
				for (i = 0; i < accounts; i++) {
					if(deposit<= 0)return; //invalid input
					if (bankAccounts[i][0] == id){
						bankAccounts[i][1] += deposit;
						flag = 1;
						printf("The new amount in account %d is %0.2lf\n", id, bankAccounts[i][1]);
					}
				}
				if (flag==0)printf("the account dosent exist\n");
			}

//draw given amount from given account
			void withdrawl(int id, double amount) {
			int flag =0;
			int i;
			for (i = 0; i < accounts; i++) {
				if(amount <= 0)return; //invalid input
					if (bankAccounts[i][0] == id) {
						if ((bankAccounts[i][1] - amount) >= 0) {
							bankAccounts[i][1] -= amount;
							flag=1;
			printf("The new amount in your account is: %0.2lf\n", bankAccounts[i][1]);
						}
					}
				}
				if(flag == 0) printf("the account dosent exist\n");
			}

//close the given account
			void close(int id) {
				int flag = 0;
				int i;
				for (i = 0; i < accounts; i++) {
					if (bankAccounts[i][0] == id) {
						bankAccounts[i][0] = 0;
						bankAccounts[i][1] = 0;
						flag = 1;
						printf("The account %d had successfully been closed\n",id);
					}
				}
				if (flag == 0) printf("The account dosent exist\n");
			}

//enter an interest to all accounts
			void addInterest(double interest) {
			double Nrib = interest;
			Nrib += 100;
			Nrib /= 100;
				for (int i = 0; i < accounts; i++) {
					if (bankAccounts[i][0] != 0){
						if((bankAccounts[i][1]*Nrib) >= 0)bankAccounts[i][1] *= Nrib;
					}
				}
				printf("The interest had successfully been inserted to all accounts\n");
			}

//print all the database accounts details.
			void printAll() {
				int i;
				for (i = 0; i < accounts; i++) {
					if (bankAccounts[i][0] != 0) {
					int ac = (int)bankAccounts[i][0];
					printf("The amount in the account %d is: %0.2lf\n ",ac, bankAccounts[i][1]);
					}
				}
			}

//close all the database accounts
			void closeAll() {
				int i;
				for (i = 0; i < accounts; i++) {
					if (bankAccounts[i][0] != 0) {
						bankAccounts[i][0] = 0;
						bankAccounts[i][1] = 0;
					}
				}
				printf("All accounts are closed\n");
			}
