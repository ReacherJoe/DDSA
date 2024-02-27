
#include "stdio.h"
#include "stdlib.h"


int email_scanner(char to_check_email[30]);
void email_valid_one(char to_valid_email[30]);
void email_valid_two(char to_valid_email[30]);
void copy_two_charArray(char first[50],char second[50]);
void registration();
void menu();
void login();
void login_checking(char l_email[30],char l_pass[20]);
int size_of_charArray(char arr[30]);
int compare_two_char_array(char first[50],char second[50]);
void my_privilege(int user_id);
void user_info_change(int user_id);
void TransferASM();
void strong_pass_validation(char pass[50]);


int g_userCount=0; 
int g_login_check=-1;
int strong_pass_valid=-1;
int email_exist=-1;

int email_validation=-1;


struct Db{
    int user_id;
    int ASM_point;
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
    char address[50];
    int postal_code;

};

struct Db data[10];

int main(){

    menu();

    return 0;
}

void menu(){

    while (1) { // 1 true 0 false
        int option = 0;
        printf(".......Welcome to our System!.......\n");
        printf("Press:1 To Login!\nPress:2 To Register!\nPress:3 To Exist!:\nEnter:");
        scanf("%d", &option); //

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
    scanf(" %[^\n]",&l_email);
    printf("Enter your password to login:");
    scanf(" %[^\n]",&l_password);

    login_checking(l_email,l_password);
    if(g_login_check != -1){

        printf("LoginSuccess!\n Your Id= %d\n",g_login_check);
        my_privilege(g_login_check);
    } else{
        printf("Login Failed!\n");
        menu();
    }

}

void my_privilege(int user_id){
    
    int m_option=-1;
    printf("......Welcome Sir.....: %s\n",data[user_id].user_name);
    printf("Your PhoneNumber: %d\n",data[user_id].phone_number);
    printf("You Have ASM POINT %d\n",data[user_id].ASM_point);

    printf("What you want to do!\n");
    printf("Enter 0 To Complete Exist:\nEnter 1 to Menu:\nEnter 2 to change user info:\nEnter 3 to transfer ASM POINT:");
    scanf("%d",&m_option);
    if(m_option == 0){
        exit(1);
    } else if(m_option==1){
        menu();
    } else if(m_option==2){
        user_info_change(user_id);
    }else if (m_option==3){
        TransferASM();
    }
    else{
        printf("Wrong Option Number:\n");
        my_privilege(user_id);
    }


}

void user_info_change(int user_id){
    int change_option=0;
    printf("Press 1: To change Name:\nPress 2: To change Email:\n");
    printf("Press 3: To change Password:\nPress 4: To change PhoneNumber:\n");
    printf("Press 5: To change Address:\nPress 6: To change PostCode:\n");
    printf("Press 7: For your privilege:");
    scanf("%d",&change_option);

    if(change_option==1){
        char newuser_name[50];
        printf("To change name:\n");
        printf("This is your user name: %s\n",data[user_id].user_name);
        printf("Enter your new user name:");
        scanf(" %[^\n]",&newuser_name[0]);
        copy_two_charArray(data[user_id].user_name,newuser_name);
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

void registration(){

    char r_username[30];
    char r_useremail[30];
    char r_userpassword[20];
    int r_phoneNumber=0;
    char r_address[50];
    int r_postal_code=0;
    int r_ASMpoint=500;
    printf("This is Registration Option:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]",&r_username);
    
    
    email_exist=-1;
    while (email_exist==-1){
        printf("Enter your user email to Register:");
        scanf(" %[^\n]",&r_useremail[0]);
        email_exist = email_scanner(r_useremail);
        if(email_exist==-1){
            printf("Your email already registered! %s\n",r_useremail);
            printf("Enter your new email address!\n");
        }

    }


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

    printf("Enter your Address to Register:");
    scanf(" %[^\n]",&r_address);
    printf("Enter your Postal code to Register:");
    scanf("%d",&r_postal_code);

    // collecting
    copy_two_charArray(data[g_userCount].user_name,r_username);
    printf("\nChecking for username: %s",data[g_userCount].user_name);

    copy_two_charArray(data[g_userCount].user_email,r_useremail);
    printf("\nChecking for userEmail: %s",data[g_userCount].user_email);

    copy_two_charArray(data[g_userCount].user_pass,r_userpassword);
    printf("\nChecking for Password: %s",data[g_userCount].user_pass);


    data[g_userCount].phone_number = r_phoneNumber;
    printf("\nChecking for PhoneNUmber: %d",data[g_userCount].phone_number);

    data[g_userCount].ASM_point = r_ASMpoint;
    printf("\nChecking for ASM_Point: %d",data[g_userCount].ASM_point);

    copy_two_charArray(data[g_userCount].address,r_address);
    printf("\nChecking for Address  %s",data[g_userCount].user_pass);

    data[g_userCount].postal_code = r_postal_code;
    printf("\nChecking for postal_code: %d \n",data[g_userCount].postal_code);

    data[g_userCount].user_id = g_userCount;
    g_userCount++;

}
void copy_two_charArray(char first[50],char second[50]){
    for(int x=0; x<30; x++){
        first[x]=='\0';
    }
    int i=0;
    for(i=0; i<30; i++){

        if(second[i]=='\0'){
            break;

        } else{
            first[i] = second[i];

        }
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
        return 1;// if same
    } else{
        return 0; // if not same
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

int email_scanner(char to_check_email[30]){
     int counter = size_of_charArray(to_check_email);

    int same_counting=0;
    for(register int gcc=0; gcc< g_userCount; gcc++){
        int db_email_count = size_of_charArray(data[gcc].user_email);

        if(counter == db_email_count){

            for(register int a=0; a<counter ; a++){
                if( to_check_email[a] !=data[gcc].user_email[a]){
                    break;
                }
                same_counting++;
            }
        }

        if(counter== same_counting){
            email_exist=gcc;
            break;
        }


    }


}


void email_valid_one(char to_valid_email[30]){


    char first[30];
    char second[30];
    char one_char;
    int xx=0;
    int arr_size = size_of_charArray(to_valid_email);
    for(int i=0; i<arr_size; i++){
        one_char = to_valid_email[i];
        if(one_char=='@'){
            for(int a=i; a<arr_size; a++){
                if(to_valid_email[a]=='\0'){
                    break;
                } else{
                    second[xx]=to_valid_email[a];
                    xx++;
                }
            }
        } else{
            if((one_char>=48 && one_char<=57)||(one_char>=97 &&one_char<=122)){

                first[i]=one_char;
            } else{
                email_validation= -1;
                break;
            }
        }
    }

}

void email_valid_two(char to_valid_email[30]){

    int first_count=0;
    char one_char;
    char first_valid=0;
   int arr_size =  size_of_charArray(to_valid_email);

    for (int i = 0; i < arr_size; ++i) {
        if(to_valid_email[i]=='@'){
            break;
        } else{
            first_count++;
        }
    }
    for(int x=0; x<first_count; x++){
        one_char = to_valid_email[x];
        if((one_char>=48 && one_char<=57)||(one_char>=97 &&one_char<=122)){
            first_valid++;
        } else{
            first_valid=-1;
        }
    }

    if(first_count!=first_valid || first_count==arr_size || first_count==0){
        email_validation=-1;
        return;
    } else{
        email_validation=1;
        printf("\n\n [+]First Part checking complete!\n");
    }

    printf("Arr Size: %d\n",arr_size);
    printf("first_count %d\n",first_count);
    printf("First count index value %c\n",to_valid_email[first_count]);

    char gmail[11]={'@','g','m','a','i','l','.','c','o','m'};
    char yahoo[11]={'@','y','a','h','o','o','.','c','o','m'};
    char outlook[12]={'@','o','u','t','l','o','o','k','.','c','o','m'};
    char apple[11]={'@','a','p','p','l','e','.','c','o','m'};
    char n1c[11]={'@','n','1','c','.','c','o','m'};
    int second_count=0;
    char arr_sec_part[13];
    int for_sec_index=0;

    second_count = arr_size-first_count;
    printf("second count value : %d\n",second_count);
    printf("Second Data :");
    for(int xxx=first_count; xxx<arr_size; xxx++){
        arr_sec_part[for_sec_index] = to_valid_email[xxx];
        printf("%c",arr_sec_part[for_sec_index]);
        for_sec_index++;

    }
    printf("\n");

    int g = compare_two_char_array(arr_sec_part,gmail);
    int y = compare_two_char_array(arr_sec_part,yahoo);
    int o = compare_two_char_array(arr_sec_part,outlook);
    int a = compare_two_char_array(arr_sec_part,apple);
    int n = compare_two_char_array(arr_sec_part,n1c);

    if(g||y||o||a||n){
        email_validation=1;
        printf("\n\n [+]Second Part checking complete!\n");

    } else{
        printf("Second email validatino failed!\n");
        email_validation=-1;
    }

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
void TransferASM (){
  
    char email_ASM[30];
    int amount_transfer=0;
    printf("This is Transfer Option....\n");

    int email_ASM_scanner=-1;
    while(email_ASM_scanner==-1){

    printf("Enter Recive Email>>");
    scanf(" %[^\n]",&email_ASM);
    email_ASM_scanner = email_scanner(email_ASM);

    if (email_ASM_scanner == -1){
        printf("This email is not found\n");
    }else {

    
    
        printf("You current Point is >> %d \nEnter amount for tanfer >>>>",data[g_login_check].ASM_point);
        scanf("%d",&amount_transfer);

        if (data[g_login_check].ASM_point < amount_transfer) {
            printf("you point is %d no enough....",data[g_login_check].ASM_point);
            break;
        }else {
            printf("-------Success-------\n");
        }
    

    int point = data[g_login_check].ASM_point-amount_transfer;
    printf("TransFer Is Success....$$...\nYou ASM Amount Point is >>%d\n",point);
    }
    }

}

   
 
       


