/*
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    AUTHOR: ABU S.G.
    STUDENT NUMBER: 3310572
    OPERATING SYSTEMS with A/Prof BILL TUCKER
    ::::::::::::::::::::::::::::::::PRACTICAL 1::::::::::::::::::::::::
                              THE DAY - DATE PROBLEM
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    DESCRIPTION:
    The program/code below solves the day-date problem.
    The program requires formatted input (e.g. "Mar 31 2010")
    for it to work otherwise it returns the string "Input not valid"
    and quietly exits.
    The Algorithm I used is the famous "Key Value Method".

    DEFINITION OF TERMS:
    - Calculation Variable: This term will be used to describe the 
      variable used for the day-date calculation in this code.
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int last_two_digits_of_year(int yr){
	int result = 0;    
	result = yr % 100;  
	return result;
}

int add_month_key_value(int digits, char * the_month){
	int result = 0;
	if(strncmp(the_month, "Jan", 3)== 0){
        	result = digits + 1;
    	}
    	if(strncmp(the_month, "Feb", 3)== 0){
    		result = digits + 4;
    	}
    	if(strncmp(the_month, "Mar", 3)== 0){
        	result = digits + 4;
    	}
    	if(strncmp(the_month, "Apr", 3)== 0){
        	result = digits + 0;
    	}
    	if(strncmp(the_month, "May", 3)== 0){
	        result = digits + 2;
    	}
    	if(strncmp(the_month, "Jun", 3)== 0){
	        result = digits + 5;
	}
    	if(strncmp(the_month, "Jul", 3)== 0){
       		result = digits + 0;
    	}
    	if(strncmp(the_month, "Aug", 3)== 0){
	        result = digits + 3;
    	}
    	if(strncmp(the_month, "Sep", 3)== 0){
	        result = digits + 6;
	}
    	if(strncmp(the_month, "Oct", 3)== 0){
	        result = digits + 1;
    	}
    	if(strncmp(the_month, "Nov", 3)== 0){
	        result = digits + 4;
    	}
    	if(strncmp(the_month, "Dec", 3)== 0){
	        result = digits + 6;
    	}
    	return result;
}

int leap_year_check(int year, char * month, int digits)
{
	if (((year % 4 == 0) && (year % 100!= 0)) || (year %400 == 0)){    
		if(strncmp(month, "Jan", 3)==0){
        		digits = digits - 1;
        	}
        	if(strncmp(month, "Feb", 3)==0){
			digits = digits - 1;
        	}
    	}
    	return digits;
}

int day_of_the_week(int remainder){
	if(remainder == 0){
	        printf("Sat\n");
    	}
    	if(remainder == 1){
	        printf("Sun\n");
    	}
    	if(remainder == 2){
	        printf("Mon\n");
    	}
    	if(remainder == 3){
	        printf("Tue\n");
    	}
    	if(remainder == 4){
	        printf("Wed\n");
    	}
    	if(remainder == 5){
	        printf("Thu\n");
    	}
    	if(remainder == 6){
	        printf("Fri\n");
    	}
    	return 0;
}

int check_input(char * input_month, int input_date, int input_year){
	char * valid [] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct", "Nov", "Dec"};
    	int i = 0;
    	int n = 12; 
	int input_confirm = 1;

	for (i = 0; i < n; i++){      
		if(strncmp(input_month, valid[i], 3) == 0){
			input_confirm = 0;
			if((input_year < 1901) || (input_year > 2038)){
				input_confirm = 1;
				break;
			}
			if((input_year >= 1901) || (input_year <= 2038)){
				if (((input_year % 4 == 0) && (input_year % 100!= 0)) || (input_year % 400 == 0))   
					if(strncmp(input_month, "Feb", 3)==0){
						if(input_date < 1 || input_date > 29){
							input_confirm = 1;
					      	}
					      	if(input_date==29){
							input_confirm = 0;
							break;
					      	}
					  }
				}
				if(strncmp(input_month, "Feb", 3)==0){
					if(input_date < 1 || input_date >28){
						input_confirm = 1;
						break;    
				    	}
				}
				if((strncmp(input_month, "Jan", 3)==0) || (strncmp(input_month, "Mar", 3)==0) 
				|| (strncmp(input_month, "May", 3)==0) || (strncmp(input_month, "Jul", 3)==0)
				|| (strncmp(input_month, "Aug", 3)==0) || (strncmp(input_month, "Oct", 3)==0)
				|| (strncmp(input_month, "Dec", 3)==0)){
					if(input_date < 1 || input_date > 31){
						input_confirm = 1;
						break;
				    	}
				}
				if((strncmp(input_month, "Apr", 3)==0) || (strncmp(input_month, "Jun", 3)==0)
				||(strncmp(input_month, "Sep", 3)==0) || (strncmp(input_month, "Nov", 3)==0)){
					if(input_date < 1 || input_date > 30){
						input_confirm = 1;
						break;
				    	}
				}
			}
	}
	return input_confirm;
}

int main(int argc, char * argv[])
{
  
	if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL){
		fprintf(stderr, "Input not valid\n");
      		exit(0);
    	}
    	if(strlen(argv[1]) > 3){
   		fprintf(stderr, "Input not valid\n");
      		exit(0);
    	}
    
	int input = check_input(argv[1], atoi(argv[2]), atoi(argv[3]));

	if(input == 0){
		char *month = argv[1];
		int date = atoi(argv[2]);
		int year = atoi(argv[3]);

/*  The basic instructions of the Key Value Method are followed below and numbered
    accordingly.
            
    1. Take the last 2 digits of the year.    */
		int calculation_variable = last_two_digits_of_year(year);
		int temp = calculation_variable;

/*  2. Divide the last 2 digits of the year by 4.   */
		calculation_variable = calculation_variable / 4;

/*  3. Add the date.    */
		calculation_variable = calculation_variable + date;

/*  4. Add month key value.   */
		calculation_variable = add_month_key_value(calculation_variable,month);

/*  5. If its a leap year and also a Jan or Feb, subtract 1   */
		calculation_variable = leap_year_check(year, month, calculation_variable);

/*  6. Add century code. 

    The practical asked that I cater for the dates from 1901 - 2038. According to the 
    Key Value Method, the century code for the 1900s is 0 and the century code for the
    2000s is 6.   */ 
		if(year == 2000 || year > 2000){
			calculation_variable = calculation_variable + 6;
		}

/*  7.  Add the last 2 digits of the year.

    I previously saved the last 2 digits in a temporary variable and it comes in handy now
    because I have been using one variable for the bulk of the calculations so far.   */
		calculation_variable = calculation_variable + temp;

/*  8.  Modulus divide by 7.   */
		calculation_variable = calculation_variable % 7;

/*  9.  The result of the modulus division is checked across a table from the 0 - 6. 

    0 equals Sat, 1 equals Sun, 2 equals Mon...5 equals Thu and 6 equals Fri.
    The day_of_the_week() function performs this check and displays the appropriate result.  */
		day_of_the_week(calculation_variable);
    	}
	if(input != 0){
        	fprintf(stderr, "Input not valid\n");
        	exit(0);
    	}
  	return 0;
}
