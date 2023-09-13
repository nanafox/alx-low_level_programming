#include <stdio.h>
#include "main.h"
#define LEAP_YEAR 366
#define NON_LEAP_YEAR 365

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 *
 * @month: month in number format
 * @day: day of month
 * @year: year
 */
void print_remaining_days(int month, int day, int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		if (month >= 3 && day >= 60)
			day++;
		printf("Day of the year: %d\n", day);
		printf("Remaining days: %d\n", LEAP_YEAR - day);
	}
	else
	{
		if (month == 2 && day == 60)
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		else
		{
			printf("Day of the year: %d\n", day);
			printf("Remaining days: %d\n", NON_LEAP_YEAR - day);
		}
	}
}
