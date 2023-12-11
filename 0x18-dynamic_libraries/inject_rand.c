/**
 * rand - thwarts the original rand() function
 *
 * Note: This function is injected into the `gm` program using the LD_PRELOAD
 * trick. The idea is to have the rand() function generate the exact numbers we
 * want so our user hits the jackpot. In this case, there's no true generation
 * of random numbers. The numbers generated are what makes the program work the
 * way we want and that's all we care about about.
 *
 * On the first call, the number in the range of 1 - 15 numbers pool is
 * generated first. It's essentially one less than the number the user has. The
 * same is the done for the rest of the five in the range of 1 - 75 numbers
 * pool. The numbers generated are in this order, one for each call to our
 * rand() function. 8 8 7 9 23 74
 *
 * The original numbers the user received after buying the ticket is as follows
 * 9 8 10 24 75 9. This is in the order of the first five, then the last one.
 *
 * Return: a number based on a pre-determined value we want the program to use
 */
int rand(void)
{
	static int calls;
	static int jack_pot_numbers[6] = {8, 8, 7, 9, 23, 74};

	return (jack_pot_numbers[calls++]);
}
