# include "../../include/milx.h"

void	ft_putchar_fd(char c, int fd)
{
	fd = 1;
	write(fd, &c, 1);
}

void	ft_dectohexa_plus(int n)
{
	if (n > 15)
	{
		ft_dectohexa_plus(n / 16);
		n %= 16;
		printf("\nn =1= %d\n", n);
	}
	if (n > 9)
	{
		ft_putchar_fd(n + 87, 0);
		printf("\nn =2= %d\n", n);
	}
	else
	{
		ft_putchar_fd(n + 48, 0);
		printf("\nn =3= %d\n", n);
	}
}

int calculate_rgb(int r, int g, int b)
{
	return((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int main(void)
{
	printf("color = %d\n", calculate_rgb(255, 255, 255));
	return (0);

}