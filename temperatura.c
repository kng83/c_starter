#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SCALE "Celesjusza"
#define COLD 0
int main(){

float temperature;
int cold_days =0;
int all_days =0;
printf("Give list of temperature per day\n");
printf("Press any key to end list\n");

while(scanf("%f",&temperature)==1){
    all_days++;
    if(temperature<COLD){
        cold_days++;
    }
}

printf("\nThere was %i cold days in list of %i days",cold_days,all_days);

}