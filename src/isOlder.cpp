/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isDateNotValid(int date, int month, int year){

	int noOfDays;
	int notValidFlag = 1;

	if (month == 2)
		noOfDays = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28;

	else if (month == 4 || month == 6 || month == 9 || month == 11)
		noOfDays = 30;

	else
		noOfDays = 31;

	if (date > 0 && date <= noOfDays)
		notValidFlag = 0;

	return notValidFlag;
}

int isOlder(char *dob1, char *dob2) {

	int date1 = 0, date2 = 0;
	int month1 = 0, month2 = 0;
	int year1 = 0, year2 = 0;
	int index;

	for (index = 0; dob1[index] != '-'; ++index)
		date1 = dob1[index] - 48 + date1 * 10;

	for (++index; dob1[index] != '-'; ++index)
		month1 = dob1[index] - 48 + month1 * 10;

	for (++index; dob1[index] != '\0'; ++index)
		year1 = dob1[index] - 48 + year1 * 10;

	for (index = 0; dob2[index] != '-'; ++index)
		date2 = dob2[index] - 48 + date2 * 10;

	for (++index; dob2[index] != '-'; ++index)
		month2 = dob2[index] - 48 + month2 * 10;

	for (++index; dob2[index] != '\0'; ++index)
		year2 = dob2[index] - 48 + year2 * 10;

	if (isDateNotValid(date1, month1, year1) || isDateNotValid(date2, month2, year2))
		return -1;

	if (year1 < year2)
		return 1;
	else if (year2 > year1)
		return 2;
	else if (year1 == year2){
		if (month1 < month2)
			return 1;
		else if (month1 > month2)
			return 2;
		else if (month1 == month2)
		if (date1 < date2)
			return 1;
		else if (date1 > date2)
			return 2;
		else
			return 0;
	}
}
