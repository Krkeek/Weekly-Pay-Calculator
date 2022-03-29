#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .2
#define TAXRATE_REST .25
#define OVERTIME 40

int main(){

    double grossPay;
    double netPay;
    double hoursWorked = 0;
    double taxes_rate = 0;
    printf("Enter the number of hours worked in a week: ");
    scanf("%lf",&hoursWorked);
    if(hoursWorked > OVERTIME){
        grossPay = 40 * 12 + ((hoursWorked-40)*18);
    } else{
        grossPay = hoursWorked * PAYRATE;
    }

    if(grossPay <= 300){
        taxes_rate = grossPay * TAXRATE_300;
    } else if (grossPay>300 && grossPay <= 450){
        taxes_rate = 300 * TAXRATE_300 + (grossPay-300)*TAXRATE_150;
    } else{
        taxes_rate = 300 * TAXRATE_300 + 150 * TAXRATE_150 + (grossPay - 450) *TAXRATE_REST;
    }

    netPay = grossPay - taxes_rate;

    printf("The gross pay is $%.1lf\n",grossPay);
    printf("The taxes rate is $%.1lf\n",taxes_rate);
    printf("The net pay is $%.1lf\n",netPay);
    return 0;
}
