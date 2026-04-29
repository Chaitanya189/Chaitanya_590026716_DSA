Name - Chaitanya Sharma
SAP ID - 590026716
Batch 39
GitHub - https://github.com/Chaitanya189

Q1) Write a program to check a number is a prime or not.
#include <stdio.h>
int main(){
    int n,i,c = 1;
    printf("Enter a number:");
    scanf("%d",&n);

    if (n <= 1) {
        c = 0;
    } 
    else {
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                c = 0;
            }
        }
    }
    if (c == 1)
        printf("%d is a Prime number", n);
    else
        printf("%d is not a Prime number", n);
    return 0;
}



Q2) Write a program to reverse a 3-digit number.
#include <stdio.h>
int main(){
    int n,rev = 0, dig;
    printf("Enter a 3-digit number:");
    scanf("%d", &n);

    for (int i = 1; i <= 3; i++) {
        dig = n % 10;          
        rev = rev * 10 + dig;   
        n = n / 10;           
    }
    printf("Reversed number is: %d", rev);

    return 0;
}



Q3) Write a program to find the factorial of a number (use both iterative and recursion method)

--> using iterative method.
#include <stdio.h>
int main(){
    int n,fact = 1;
    printf("Enter a number:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    printf("Factorial of %d is %lld", n, fact);

    return 0;
}
-------------------------------------------------------------------
--> using recursion method.
#include <stdio.h>
int fact(int n){
    if (n == 0) {
        return 1; 
    } else {
        return n * fact(n -1);
    }
}

int main(){
    int n, result;
    printf("Enter a number:");
    scanf("%d", &n);

    result = fact(n);
    printf("Factorial of %d is %d", n, result);

    return 0;
}

Q4) Write a C program to print the Fibonacci series up to n terms.
#include <stdio.h>
int main() {
    int n, t1 = 0, t2 = 1, next_term;    
    printf("Enter number of terms: ");
    scanf("%d", &n);   
    printf("Fibonacci Series: ");  
    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }  
    printf("\n");
        return 0;
}



Q5) Write a program using temp variable to swap two numbers.
#include <stdio.h>
int main(){
    int a, b, temp;
    printf("Enter value of a:");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping:\n");
    printf("a = %d\nb = %d", a, b);
    return 0;
}
