/**
 * get_sqrt - gets the square of a number - a helper function
 * @target: number
 * @current: accumulator
 *
 * Return: square root on @target else -1 if @target is not a natural
 * square root
 */
int get_sqrt(int target, int current)
{
	if ((current * current) > target) /* not a natural square root */
		return (-1);
	if ((current * current) == target)
		return (current);
	return (get_sqrt(target, current + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @target: number
 *
 * Return: natural square root of a number
 */
int _sqrt_recursion(int target)
{
	if (target < 0)
		return (-1);
	if (target == 0 || target == 1)
		return (1);
	return (get_sqrt(target, 0));
}
