#include <linux/getInfoSpring2024.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <asm/current.h>
#include <asm/uaccess.h>


asmlinkage int sys_getInfoSpring2024(struct structSpring2024 *data){


    cli();
    struct structSpring2024 parameter;


    copy_from_user(&parameter, data, sizeof(struct structSpring2024));
    struct task_struct *task;
    task= get_current();

    if(parameter.flag > 0 && parameter.flag <= 24){
        parameter.pid= task-> pid;
        parameter.pid_parent= task-> p_opptr->pid;
        parameter.process_counter= task-> counter;
        parameter.nice= task-> nice;
        parameter.nice_parent = task-> p_opptr->nice;
        parameter.uid = (long)task-> uid;
	if(task->counter){
		parameter.weight= task-> counter + 20 - task-> nice;
	}
	else{
		parameter.weight=0;
	}
        copy_to_user(data, &parameter, sizeof(struct structSpring2024));
        sti();
        return 0;
    }
    else if(parameter.flag > 24){

        int weight2;
	if(task -> counter){
		weight2= task->counter + 20 - task->nice;
	}
	else{
		weight2=0;
	}
        sti();
        return weight2;

    }
    else{
        sti();
        return -1;
    }
}
