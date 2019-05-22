#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
//variables
    long int seconds;
    struct tm current_time, *time_ptr;
    int mem_size;
    mem_size=30;
    seconds=time(0); //poner un argumento nulo en el tiempo
    //sincroinuzar time ptr con current_time
    time_ptr=&current_time;
    //sincrinizar segundos de time since epoch.
    localtime_r(&seconds, time_ptr);
    //bucle de las horas, minutos, segundos.
    system("clear");
    for ( int h=current_time.tm_hour; h<=24; h=h+1) {
    for ( int m=time_ptr->tm_min; m<60; m=m+1) {
	fflush(stdout);
    for ( int s=time_ptr->tm_sec; s<60; s=s+1) {
	system("clear && echo '\e[00;32m'");
	printf ("┌[ %02d : %02d : %02d ]\n",h,m,s);
	system("bat.sh");
        //delay de un segundos
	sleep(1);
	continue;
		}
	//se redefinen los segundos a ceros
	time_ptr->tm_sec=0;
		}
	//si es el minuto 59 comienza a contar desde 0
	if(time_ptr->tm_min==59) {
	   time_ptr->tm_min=0;
				}
	//pero si no continua en el siguiente minuto
	else {
	time_ptr->tm_min=current_time.tm_min;
		}
		}
	return 0;
		}
