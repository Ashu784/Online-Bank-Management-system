#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct user {
char phone[100];
char ac[100];
char password[100];
float balance;
};
int main(){
struct user usr,usr1;
FILE*fp;
char
filename[50],phone[50],pword[50];
int opt,choice;
char cont='y';
float amount;
printf("\nChoose your option");
 printf("\n\n1. Create an account");
 printf("\n2. login to account");
 printf("\n\nYour choice:\t");
 scanf("%d",&opt);if(opt==1){
 system("cls");
 printf("Enter your account number:\t");
 scanf("%s",usr.ac);
 printf("Enter your phone number:\t");
 scanf("%s",usr.phone);
 printf("Enter your password:\t");
 scanf("%s",usr.password);
 usr.balance=0;
 strcpy(filename,usr.phone);
 fp=fopen(strcat(filename,".dat"),"w");
 fwrite(&usr,sizeof(struct user),1,fp);
 if(fwrite!=0){
 printf("\n\nACCOUNT SUCCESSFULLY REGISTERED");
 }else{
 printf("\n\nSOMETHING WENT WRONG PLEASE TRY AGAIN");
 }
 fclose(fp);
 }
 if(opt==2){
 system("cls");
 printf("\nPhone number:\t");
 scanf("%s",phone);
 printf("Password:\t");
 scanf("%s",pword);
 strcpy(filename,phone);
 fp=fopen(strcat(filename,".dat"),"r");if(fp==NULL){
 printf("\nAccount not Registered");}
 else{
 fread(&usr,sizeof(struct user),1,fp);
 fclose(fp);
 if(!strcmp(pword,usr.password)){
 printf("\n\tWELCOME %s",usr.phone);
 while(cont=='y'){
 system("cls");
 printf("\nPress 1 for balance inquiry");
 printf("\nPress 2 for depositing cash");
 printf("\nPress 3 for cash withdraw");
 printf("\nPress 4 for online transfer");
 printf("\nPress 5 for password change");
 printf("\n\nYour choice:\t");
 scanf("%d",&choice);
 switch(choice)

 {
 case 1:
    printf("\n your current balance is: Rs.%.2f",usr.balance);
 break;

 case 2:
 printf("\nEnter the amount:\t");
 scanf("%f",&amount);
 usr.balance += amount;
 fp=fopen(filename,"w");
fwrite(&usr,sizeof(struct user),1,fp);
 if(fwrite!=NULL) printf("\nSuccessfully Deposited.");
 fclose(fp);
 break;
 case 3:
 printf("\nEnter the amount:\t");
 scanf("%f",&amount);
 usr.balance-=amount;
 fp= fopen(filename,"w");
 fwrite(&usr,sizeof(struct user),1,fp);
 if(fwrite!=NULL) printf("\nSuccessfully Withdrwal");
 fclose(fp);
 break;
 case 4:
 printf("\nPlease enter the phone number to tansfer the balance:\t");
 scanf("%s",phone);
 printf("\nPlease enter the amount to tansfer:\t");
 scanf("%f",&amount);
 strcpy(filename,phone);
 fp=fopen(strcat(filename,".dat"),"r");
 if(fp==NULL) printf("\nAccount number not registered");
 else{
 fread(&usr1,sizeof(struct user),1,fp);
 fclose(fp);
 if(amount>usr.balance) printf("\nInsufficient balance");
else{
 fp=fopen(filename,"w");
 usr1.balance+= amount;
 fwrite(&usr1,sizeof(struct user),1,fp);
 fclose(fp);
 if(fwrite!=NULL){
 printf("\nYou have successfully transfered Rs.%2f to %s",amount,phone);
 strcpy(filename,usr.phone);
 fp=fopen(strcat(filename,".dat"),"w");
 usr.balance-=amount;
 fwrite(&usr,sizeof(struct user),1,fp);
 fclose(fp);
 }
 }
 break;
 case 5:
 printf("\nPlease enter your new password:\t");
 scanf("%s",pword);
 fp=fopen(filename,"w");
 strcpy(usr.password,pword);
 fwrite(&usr,sizeof(struct user),1,fp);
 if(fwrite!=NULL)
 printf("\nPassword successfully changed");
 }
 break;
 default:
printf("\nInvalid option");
 }
 printf("\nDo you want to continue the transaction [y/n]\t");
 scanf("%s",&cont);
 }
 }
 else{
 printf("\nInvalid Password");
 }
 }
 }
return 0;
 }
