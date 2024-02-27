
#include "stdio.h"
#include "stdlib.h"



void registration();
void menu();
void login();
void login_checking(char l_email[30],char l_pass[20]);
int size_of_charArray(char arr[30]);
int compare_two_char_array(char first[30],char second[30]);
int email_check(char to_check_email[30]);
void option(int user_id);
void change_data(int user_id);
void strong_pass_validation(char pass[50]);
void email_validation(char to_check[50]);


int g_userCount=0;
int g_login_check=-1;
int strong_pass_valid=-1;
int G_index=-1;
int email_valid=-1;
int email_found=0;




struct Db{
    int user_id;
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
 
};

struct Db data[10];

int main(){

    menu();

    return 0;
}

void menu(){

    while (1) { 
        int option = 0;
        printf("Welcome to our System!\n");
        printf("Press:1 To Login!\nPress:2 To Register!\nPress:3 To Exist!:\nEnter:");
        scanf("%d", &option); 

        if (option == 1) {
            login();

        } else if (option == 2) {

            registration();
        } else {

            exit(1);
        }

    }

}
void login(){

    char l_email[30];
    char l_password[20];
    printf("This is login!\n");
    printf("Enter your email to login:");
    scanf(" %[^\n] ",&l_email[0]);
    printf("Enter your password to login:");
    scanf(" %[^\n] ",&l_password[0]);

    login_checking(l_email,l_password);
    if(g_login_check != -1){

        printf("LoginSuccess!\n Your Id= %d",g_login_check);
        option(g_login_check);
    } else{
        printf("Login Failed!\n");
        menu();
    }

}

void option(int user_id){

    int m_option=-1;
    printf("Welcome Sir: %s\n",data[user_id].user_name);
    printf("Your PhoneNumber: %d\n",data[user_id].phone_number);

    printf("What you want to do!\n");
    printf("Enter 0 To Complete Exist:\nEnter 1 to Menu:\nEnter 2 to change user info:");
    scanf("%d",&m_option);
    if(m_option == 0){
        exit(1);
    } else if(m_option==1){
        menu();
    } else if(m_option==2){
        change_data(user_id);
    }
    else{
        printf("Wrong Option Number:\n");
        option(user_id);
    }


}

void change_data(int user_id){
    int change_option=0;
    printf("Press 1: To change Name:\nPress 2: To change Email:\n");
    printf("Press 3: To change Password:\nPress 4: To change PhoneNumber:\n");
    printf("Press 5: To change Address:\nPress 6: To change PostCode:\n");
    printf("Press 7: For your privilege:");
    scanf("%d",&change_option);

    if(change_option==1){
        char newuser_name[30];
        printf("To change name:\n");
        printf("This is your user name: %s\n",data[user_id].user_name);
        printf("Enter your new user name:");
        scanf(" %[^\n] ",&newuser_name[0]);
        compare_two_char_array(data[user_id].user_name,newuser_name);
        printf("This is your new user name: %s",data[user_id].user_name);


    }else if(change_option==2){
        printf("To change email:\n");
    }




}
void login_checking(char l_email[50],char l_pass[50]){
    int i=0;
    g_login_check=-1;
    for(i=0; i<g_userCount ; i++){
        int email_check =compare_two_char_array(data[i].user_email,l_email);

        if(email_check == 1){
            int pass_check =compare_two_char_array(data[i].user_pass,l_pass);
            if(pass_check==1){
                g_login_check=data[i].user_id;
                break;
            }

        }

    }

}

void registion(){

    char r_username[30];
    char r_useremail[50];
    char r_userpassword[50];
    int r_phoneNumber=0;
    char r_address[50];
    int r_postal_code=0;
    printf("This is Registration Option:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]",&r_username[0]);

    email_valid=-1;
    while (email_valid==-1) {
        printf("Enter your email to register>>:");
        scanf(" %[^\n]", &r_useremail[0]);


        email_validation(r_useremail);
        if (email_valid == -1) {
            printf("Your email format was not valid\n");
        }
    }
    printf("Your email form was valid:\n");
    email_found=-1;
    email_check(r_useremail);
    if( email_found !=-1 ){
        printf("Your email was already register:\n");
        login();
    } else{
        printf(" Del re_email %s\n",r_useremail);

    strong_pass_valid=-1;
        while (strong_pass_valid==-1){

            printf("Enter your password:");
            scanf(" %[^\n]",&r_userpassword[0]);

            strong_pass_validation(r_userpassword);

            if(strong_pass_valid==-1){

                printf("[-]Your password format too weak and Try Again!\n");
            }
        }
        printf("[+]Your password format was correct and was saved!\n");

    printf("Enter your PhoneNumber to Register:");
    scanf("%d",&r_phoneNumber);

    
    compare_two_char_array(data[g_userCount].user_name,r_username);
    printf("\nChecking for username: %s",data[g_userCount].user_name);

    compare_two_char_array(data[g_userCount].user_email,r_useremail);
    printf("\nChecking for userEmail: %s",data[g_userCount].user_email);

    compare_two_char_array(data[g_userCount].user_pass,r_userpassword);
    printf("\nChecking for Password: %s",data[g_userCount].user_pass);


    data[g_userCount].phone_number = r_phoneNumber;
    printf("\nChecking for PhoneNUmber: %d",data[g_userCount].phone_number);



    data[g_userCount].user_id = g_userCount;
    g_userCount++;
    }
}

int compare_two_char_array(char first[50],char second[50]){

    int size1= size_of_charArray(first);
    int size2= size_of_charArray(second);
    int sameCount=0;
    if( size1 == size2){
        for(int i=0; i<size1; i++){

            if(first[i]==second[i]){
                sameCount++;
            }
        }
    }
    if(size1 == sameCount){
        return 1;
    } else{
        return 0;
    }
}

int size_of_charArray(char arr[30]){
    int size=0;
    for(int i=0; i<30 ;i++){

        if(arr[i]=='\0'){
            break;
        }
        size++;
    }

    return size;
}
void strong_pass_validation(char pass[50]){

    int i=0;
    int special=0;
    int number=0;
    int smallChar=0;
    int capChar=0;


    int pass_counter = size_of_charArray(pass);

    if(pass_counter >=6) {

        while (strong_pass_valid == -1) {
            if( i == pass_counter){
                strong_pass_valid=-1;
                break;
            }
            if(pass[i] >=33 && pass[i]<=42){
                special++;
            } else if( pass[i] >=48 && pass[i]<=57){
                number++;
            } else if( pass[i]>=97 && pass[i]<=122){
                smallChar++;
            } else if(pass[i]>=65 && pass[i]<=90){
                capChar++;
            }
            i++;
            if(special>0 && number>0 && capChar >0 && smallChar>0){
                strong_pass_valid=1;
            }

        }
    } else{
        printf("[-]we need at least 6 characters!\n");
        strong_pass_valid=-1;
    }

}
int email_check(char to_check_email[30]){
    int exit_or_not=-1;
    if(g_userCount==0){
        return 1;
    } else{
        for(int i=0; i<g_userCount ; i++){
        
            exit_or_not=compare_two_char_array(data[i].user_email,to_check_email);
            if(exit_or_not==1){
                return -1; 
            }
        }
    }

    return 1;

}
void email_validation(char to_check[50]){

    int space=1;
    int format=1;
    char valid_form[10]={'@','g','m','a','i','l','.','c','o','m'};
    int check_counter = size_of_charArray(to_check);

    int front_counter = check_counter-10;

    for(int i=0; i<front_counter ; i++){
        if(to_check[i]==' '){
            space=-1;
            break;
        }
    }
    for(int f=0; f<10; f++){
        if(to_check[front_counter] != valid_form[f]){
            format = -1;
            break;
        }
        front_counter++;
    }

    if(space == 1 && format==1){
        email_valid=1;
    }
}