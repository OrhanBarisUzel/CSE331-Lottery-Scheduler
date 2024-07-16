int main(int argc, char ** argv)
{
	int i = 0;
	setuid(atoi(argv[1]));
	while(1)
	{
		i = (i + 1) %10000;
	}
}
