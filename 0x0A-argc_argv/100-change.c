#include <stdio.h>
#include <stdlib.h>

int generate_coins(int money);

/* coin values */
#define QUATER 25
#define DIME 10
#define NICKEL 5
#define TWO 2
#define PENNY 1

/**
 * main - prints the minimum number of coins to make change for an
 * amount of money.
 * @argc: CLI counter
 * @argv: The amount of money
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int cents, money;

	if (argc != 2)
	{
		puts("Error");
		return (1); /* invalid number of arguments */
	}

	money = atoi(argv[1]);

	if (money < 0)
	{
		puts("0");
		return (-1); /* Money value should't be less than 0 */
	}
	cents = generate_coins(money);

	printf("%d\n", cents);

	return (0);
}

/**
 * generate_coins - Generates the minimum number of coins to make
 * change for an amount of money.
 * @money: Money
 *
 * Return: The minimum number of coins to make change for an amount of money.
 */
int generate_coins(int money)
{
	int quaters, dimes, nickels, pennies, twos;

	/* Get the number of quaters (25¢) owed */
	for (quaters = 0; money >= QUATER; money -= QUATER)
		++quaters;

	/* Get the number of dimes (10¢) owed */
	for (dimes = 0; money >= DIME; money -= DIME)
		++dimes;

	/* Get the number of nickels (5¢) owed*/
	for (nickels = 0; money >= NICKEL; money -= NICKEL)
		++nickels;

	/* Get the number of twos (2¢) owed */
	for (twos = 0; money >= TWO; money -= TWO)
		++twos;

	/* Calculates the number of pennies (1¢) owed */
	for (pennies = 0; money >= PENNY; money -= PENNY)
		++pennies;

	return (quaters + dimes + nickels + twos + pennies);
}
