int	ft_isalnum(char a)
{
	return ((a >= '0' && a <= '9') || ((a >= 'a' && a <= 'z') || (a >= 'A'
				&& a <= 'Z')));
}
