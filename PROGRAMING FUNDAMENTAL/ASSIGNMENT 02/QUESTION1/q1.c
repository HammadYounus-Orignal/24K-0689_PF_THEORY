// NAME HAMMAD YOUNUS
// ID   24K-0689




#include <stdio.h>

int main() {
int arr[5];
int smallest=9999 , secsmallest=9999 ;
printf("Enter 5 values less than 9999\n");
for (int i=0 ;i<5 ;i++){
    printf("element-%d:",i);
    scanf("%d",&arr[i]);
if (arr[i]>9999){
    printf("invalid number entered");
    return 0;
}
}
for (int i=0 ;i<5 ;i++){
    if (arr[i]<smallest){
        secsmallest=smallest;
        smallest = arr[i];
    }
    
}
printf("EXPECTED OUTPUT:\n");
printf("The Second smallest element in the array is: %d",secsmallest);

    return 0;
}