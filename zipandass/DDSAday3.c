#include <stdio.h>


int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

int main() {
    int operator, num1, num2, result;

    
    printf("Enter the operation (1 for +, 2 for -, 3 for *, 4 for /): ");
    scanf("%d", &operator);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (operator == 1) {
        result = add(num1, num2);
    } else if (operator == 2) {
        result = subtract(num1, num2);
    } else if (operator == 3) {
        result = multiply(num1, num2);
    } else if (operator == 4) {
        if (num2 != 0) {
            result = divide(num1, num2);
        } else {
            printf("Error: Division by zero\n");
            return 1; 
        }
    } else {
        printf("Error: Invalid operation\n");
        return 1;
    }
    printf("Result: %d\n", result);

    return 0; 
}

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    return num1 / num2;
}
