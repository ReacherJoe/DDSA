//
// Created by winht on 2/12/2024.
//

#ifndef DDSA_1_TRANSACTIONUTIL_H
#define DDSA_1_TRANSACTIONUTIL_H
#include "stdio.h"
#include "n1c.h"
#include "validationUtil.h"
#include <time.h> 
void transaction(int sender_id , int receiver_id,double amount){

     double deducted_amount = amount * 0.05; 
    double transferred_amount = amount - deducted_amount; 


    data[sender_id].amount -= transferred_amount;

    
    data[1].amount += deducted_amount;

    data[receiver_id].amount += transferred_amount;

    printf("Transaction Complete From %s to %s : amount=%lf\n",data[sender_id].user_name,data[receiver_id].user_name,amount);
    transaction_record(sender_id , receiver_id,transferred_amount);
    all_data();
    my_privilege(sender_id);

}

void transaction_record(int sender_id, int receiver_id, double amount) {
    int sender_index = data[sender_id].trans_counter;
    int receiver_index = data[receiver_id].trans_counter;

    char *from = "From-";
    char *sender = data[sender_id].user_name;
    char *to = "-To-";
    char *receiver = data[receiver_id].user_name;
    char *receive = "ReceiveFrom-";

   
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    
    char timestamp[20];
    sprintf(timestamp, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    
    sprintf((char *)data[sender_id].trans[sender_index].trans_record, "%s%s%s%s%c%lf %s", from, sender, to, receiver, '-', amount, timestamp);
    sprintf((char *)data[receiver_id].trans[receiver_index].trans_record, "%s%s%c%lf %s", receive, sender, '-', amount, timestamp);

    data[sender_id].trans_counter++;
    data[receiver_id].trans_counter++;
}

void to_transfer_checking(int id){
    double amount=0;
    int receiver_phone=0;//
    int phone_id=0;
    int option=0;
    int cout_wrong=0;
    printf("Enter your amount to transfer:");
    scanf("%lf",&amount);

    while(data[id].amount>amount+100){

        printf("Enter receiver phone number to send money:");
        scanf("%d",&receiver_phone);
        phone_id =to_check_phone(receiver_phone);
        if(phone_id!=-1){   
            
            transaction(id,phone_id,amount);
        } else{
            printf("This phone number is not available in our system!\n");
            cout_wrong++;
            if(cout_wrong>2){
                fprintf(stderr,"Wrong Phone Number!");
                my_privilege(id);
            }
        }
    }

    printf("Insufficient Amount: %lf\n",data[id].amount);
    printf("Press 1 to continue transaction:\nPress 2 To get Privilege:\n");
    scanf("%d",&option);
    if(option==1){
        to_transfer_checking(id);
    } else if(option==2){
        my_privilege(id);
    } else{
        fprintf(stderr,"Invalid Option\n");
        menu();
    }


}


#endif //DDSA_1_TRANSACTIONUTIL_H
