#include <stdio.h>
#include <linux/getInfoSpring2024.h>

int main(){
    struct structSpring2024 struct2;
    struct2.flag = 10; //we said 10 for example
    nice(5);
    setuid(5);
    int Value = getInfoSpring2024(&struct2);
    if(Value == 0){
        printf("Flag: %d\nPid: %d\nPid parent: %d\nCounter: %d\nNice: %d\nNice parent: %d\nUid: %d\nWeight: %d\n",
        struct2.flag, struct2.pid, struct2.pid_parent, struct2.process_counter, struct2.nice, struct2.nice_parent, struct2.uid, struct2.weight);
    }
    else if(Value == -1){
        printf("Invalid flag\n");
    }
    else{
        printf("Weight: %d\n", Value);
    }
}
