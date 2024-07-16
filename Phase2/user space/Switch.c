#include <linux/switchFlag.h>

int main(int argc, char ** argv)
{
    int value;
    value = atoi(argv[1]);
    switchFlag(value);

    printf("%d\n",value);
    return 0;
}
