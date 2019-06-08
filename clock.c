#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
	/* declarations */
	long int seconds;
	struct tm current_time, *time_ptr;
	int mem_size;
	int h, m, s; /* loop variables */
	/* initialization */
	mem_size = 30;
	seconds = time(0); /*poner un argumento nulo en el tiempo*/
	/*sincroinuzar time ptr con current_time*/
	time_ptr = &current_time;
	/*sincrinizar segundos de time since epoch.*/
	localtime_r(&seconds, time_ptr);
	/* begin */
	/*bucle de las horas, minutos, segundos.*/
	system("clear"); /* stop using system! */
	for (h = current_time.tm_hour; h < 24; h++) /* 24, not 25 hour days */
	{
		for (m = time_ptr->tm_min; m < 60; m++)
		{
			fflush(stdout);
			for (s = time_ptr->tm_sec; s < 60; s++)
			{
				system("clear && echo '\e[00;32m'"); /* stop using system! */
				printf ("┌[ %02d : %02d : %02d ]\n",h,m,s);
				system("bat.sh"); /* stop using system! */
				/*delay de un segundos*/
				sleep(1);
			}
			/*se redefinen los segundos a ceros*/
			time_ptr->tm_sec=0;
		}
		/* you can probably simplify this by doing a % 60 */
		/*si es el minuto 59 comienza a contar desde 0*/
		if (time_ptr->tm_min == 59)
		{
			time_ptr->tm_min = 0;
		}
		/*pero si no continua en el siguiente minuto*/
		else
		{
			time_ptr->tm_min = current_time.tm_min;
		}
	}
	return 0;
}
