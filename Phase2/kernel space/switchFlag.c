#include <linux/switchFlag.h>

int scheduleFlag = 0;

asmlinkage int sys_switchFlag(int value)
{
     scheduleFlag = value;
     return scheduleFlag;
}