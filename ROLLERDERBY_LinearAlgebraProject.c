#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

double sin_square(double angle) // sin^2 theta //
{
	double temp;
	temp = sin(angle);
	return temp*temp;
}

void SetColor(int Color)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
    	wColor = (csbi.wAttributes & 0xF0) + (Color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int main()
{
	SetConsoleTitle("APPLIED ROLLER DERBY");
	int i;																		// initialization and declaration //
	double first, second, third, fourth;				
	double *time, *I, angle, sinsquare, height, g=9.8;	
	I = (double*) calloc(4, sizeof(double));
	time = (double*) calloc(4, sizeof(double));
	SetColor(10);
	printf("\t\t\t\t\tROLLER DERBY\n\n");
	SetColor(15); 
	
	printf("Enter Angle of Inclination of the plane? ");						// input for height and angle //
	scanf("%lf", &angle);
	
	printf("Enter Height? ");
	scanf("%lf", &height);
	
	sinsquare=sin_square(angle);
	printf("\nOBJECTS:\n1)Solid ball\n2)Hollow ball\n3)Solid cylinder\n4)Hollow cylinder\n\n");
	printf("Input Moment Of Inertia (I*) for the above objects:\n");
	
	
	for (i=0;i<4;i++)															// input inertia then calculating total time for every object //
	{
		printf("%d) ", i+1);
		scanf("%lf", &I[i]);
	time[i]=sqrt((2*height*(1+I[i]))/(g*sinsquare));
	}
	
	
	printf("\nThe Total Length of Time objects take:\n");						// printing total time //
	for (i=0;i<4;i++)
	{
		printf("%d) ", i+1);
		time[i]=sqrt((2*height*(1+I[i]))/(g*sinsquare));
		printf("%lf\n", time[i]);
	}
	
	SetColor(12);
	printf("\n\nRESULT IS:\n");													// checking for results //
	SetColor(15);
	
	
	
	// tree of possiblilities //
	
	if ((time[0] < time[1]) && (time[0] < time[2]) && (time[0] < time[3]))		
	{
		if ((time[1] < time[2]) && (time[1] < time[3]))					
		{
			if (time[2] < time[3])
			{
				first = time[0];
				printf("Solid ball wins. FIRST! Time: %.2lf\n", first);					
	 			second = time[1];
				printf("Hollow ball is SECOND! Time: %.2lf\n", second);
				third = time[2];
				printf("Solid cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[3];
				printf("Hollow cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}	
		}
	}
	
	
	if ((time[1] < time[0]) && (time[1] < time[2]) && (time[1] < time[3]))
	{
		if ((time[0] < time[2]) && (time[0] < time[3]))
		{
			if (time[2] < time[3])
			{
				first = time[1];
				printf("Hollow ball wins. FIRST! Time: %.2lf\n", first);				
				second = time[0];
				printf("Solid ball is SECOND! Time: %.2lf\n", second);				
				third = time[2];
				printf("Solid cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[3];
				printf("Hollow cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[1] < time[0]) && (time[1] < time[2]) && (time[1] < time[3]))
	{
		if ((time[2] < time[0]) && (time[2] < time[3]))
		{
			if (time[0] < time[3])
			{
				first = time[1];
				printf("Hollow ball wins. FIRST! Time: %.2lf\n", first);
				second = time[2];
				printf("Solid cylinder is SECOND! Time: %.2lf\n", second);
				third = time[0];
				printf("Solid ball is THIRD! Time: %.2lf\n", third);				
				fourth = time[3];
				printf("Hollow cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[1] < time[0]) && (time[1] < time[2]) && (time[1] < time[3]))
	{
		if ((time[2] < time[0]) && (time[2] < time[3]))
		{
			if (time[3] < time[0])
			{
				first = time[1];
				printf("Hollow ball wins. FIRST! Time: %.2lf\n", first);
				second = time[2];
				printf("Solid cylinder is SECOND! Time: %.2lf\n", second);
				third = time[3];
				printf("Hollow cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[0];
				printf("Solid ball is FOURTH! Time: %.2lf\n", fourth);				
				exit(0);
			}
		}
	}


	if ((time[0] < time[1]) && (time[0] < time[2]) && (time[0] < time[3]))
	{
		if ((time[2] < time[1]) && (time[2] < time[3]))
		{
			if (time[1] < time[3])
			{
				first = time[0];
				printf("Solid ball wins. FIRST! Time: %.2lf\n", first);
				second = time[2];
				printf("Solid cylinder is SECOND! Time: %.2lf\n", second);
				third = time[1];
				printf("Hollow ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[3];
				printf("Hollow cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[0] < time[1]) && (time[0] < time[2]) && (time[0] < time[3]))
	{
		if ((time[2] < time[1]) && (time[2] < time[3]))
		{
			if (time[3] < time[1])
			{
				first = time[0];
				printf("Solid ball wins. FIRST! Time: %.2lf\n", first);
				second = time[2];
				printf("Solid cylinder is SECOND! Time: %.2lf\n", second);
				third = time[3];
				printf("Hollow cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[1];
				printf("Hollow ball is FOURTH! Time: %.2lf\n", fourth);				
				exit(0);
			}
		}
	}
	
	
	if ((time[2] < time[0]) && (time[2] < time[1]) && (time[2] < time[3]))		
	{
		if ((time[0] < time[1]) && (time[0] < time[3]))					
		{
			if (time[1] < time[3])
			{
				first = time[2];
				printf("Solid cylinder wins. FIRST! Time: %.2lf\n", first);					
	 			second = time[0];
				printf("Solid ball is SECOND! Time: %.2lf\n", second);
				third = time[1];
				printf("Hollow ball is THIRD! Time: %.2lf\n", third);
				fourth = time[3];
				printf("Hollow cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}	
		}
	}
		
		
	if ((time[3] < time[0]) && (time[3] < time[1]) && (time[3] < time[2]))	
	{
		if ((time[0] < time[1]) && (time[0] < time[2]))					
		{
			if (time[1] < time[2])
			{
				first = time[3];
				printf("Hollow cylinder wins. FIRST! Time: %.2lf\n", first);					
	 			second = time[0];
				printf("Solid ball is SECOND! Time: %.2lf\n", second);
				third = time[1];
				printf("Hollow ball is THIRD! Time: %.2lf\n", third);
				fourth = time[2];
				printf("Solid cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}	
		}
	}
	
	
	if ((time[0] < time[1]) && (time[0] < time[2]) && (time[0] < time[3]))
	{
		if ((time[3] < time[1]) && (time[3] < time[2]))
		{
			if (time[1] < time[2])
			{
				first = time[0];
				printf("Solid ball wins. FIRST! Time: %.2lf\n", first);				
				second = time[3];
				printf("Hollow cylinder is SECOND! Time: %.2lf\n", second);				
				third = time[1];
				printf("Hollow ball is THIRD! Time: %.2lf\n", third);
				fourth = time[2];
				printf("Solid cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[0] < time[1]) && (time[0] < time[2]) && (time[0] < time[3]))
	{
		if ((time[1] < time[2]) && (time[1] < time[3]))
		{
			if (time[3] < time[2])
			{
				first = time[0];
				printf("Solid ball wins. FIRST! Time: %.2lf\n", first);
				second = time[1];
				printf("Hollow ball is SECOND! Time: %.2lf\n", second);
				third = time[3];
				printf("Hollow cylinder is THIRD! Time: %.2lf\n", third);					
				fourth = time[2];
				printf("Solid cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}    						
	
	
	if ((time[2] < time[0]) && (time[2] < time[1]) && (time[2] < time[3]))
	{
		if ((time[1] < time[0]) && (time[1] < time[3]))
		{
			if (time[3] < time[0])
			{
				first = time[2];
				printf("Solid cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[1];
				printf("Hollow ball is SECOND! Time: %.2lf\n", second);
				third = time[3];
				printf("Hollow cylinder is THIRD! Time: %.2lf\n", third);					
				fourth = time[0];
				printf("Solid ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[2] < time[0]) && (time[2] < time[1]) && (time[2] < time[3]))
	{
		if ((time[1] < time[0]) && (time[1] < time[3]))
		{
			if (time[0] < time[3])
			{
				first = time[2];
				printf("Solid cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[1];
				printf("Hollow ball is SECOND! Time: %.2lf\n", second);
				third = time[0];
				printf("Solid ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[3];
				printf("Hollow cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[2] < time[0]) && (time[2] < time[1]) && (time[2] < time[3]))	
	{
		if ((time[0] < time[1]) && (time[0] < time[3]))
		{
			if (time[3] < time[1])
			{
				first = time[2];
				printf("Solid cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[0];
				printf("Solid ball is SECOND! Time: %.2lf\n", second);
				third = time[3];
				printf("Hollow cylinder is THIRD! Time: %.2lf\n", third);					
				fourth = time[1];
				printf("Hollow ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[3] < time[0]) && (time[3] < time[1]) && (time[3] < time[2])) 
	{
		if ((time[2] < time[0]) && (time[2] < time[1]))
		{
			if (time[1] < time[0])
			{
				first = time[3];
				printf("Hollow cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[2];
				printf("Solid cylinder is SECOND! Time: %.2lf\n", second);
				third = time[1];
				printf("Hollow ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[0];
				printf("Solid ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[3] < time[0]) && (time[3] < time[1]) && (time[3] < time[2])) 
	{
		if ((time[2] < time[0]) && (time[2] < time[1]))
		{
			if (time[0] < time[1])
			{
				first = time[3];
				printf("Hollow cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[2];
				printf("Solid cylinder is SECOND! Time: %.2lf\n", second);
				third = time[0];
				printf("Solid ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[1];
				printf("Hollow ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[3] < time[0]) && (time[3] < time[1]) && (time[3] < time[2]))
	{
		if ((time[1] < time[0]) && (time[1] < time[2]))
		{
			if (time[0] < time[2])
			{
				first = time[3];
				printf("Hollow cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[1];
				printf("Hollow ball is SECOND! Time: %.2lf\n", second);
				third = time[0];
				printf("Solid ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[2];
				printf("Solid cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[3] < time[0]) && (time[3] < time[1]) && (time[3] < time[2])) 
	{
		if ((time[1] < time[0]) && (time[1] < time[2]))
		{
			if (time[2] < time[0])
			{
				first = time[3];
				printf("Hollow cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[1];
				printf("Hollow ball is SECOND! Time: %.2lf\n", second);
				third = time[2];
				printf("Solid cylinder is THIRD! Time: %.2lf\n", third);					
				fourth = time[0];
				printf("Solid ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[1] < time[0]) && (time[1] < time[2]) && (time[1] < time[3])) 
	{
		if ((time[3] < time[0]) && (time[3] < time[2]))
		{
			if (time[2] < time[0])
			{
				first = time[1];
				printf("Hollow ball wins. FIRST! Time: %.2lf\n", first);
				second = time[3];
				printf("Hollow cylinder is SECOND! Time: %.2lf\n", second);
				third = time[2];
				printf("Solid cylinder is THIRD! Time: %.2lf\n", third);					
				fourth = time[0];
				printf("Solid ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[1] < time[0]) && (time[1] < time[2]) && (time[1] < time[3])) 
	{
		if ((time[3] < time[0]) && (time[3] < time[2]))
		{
			if (time[0] < time[2])
			{
				first = time[1];
				printf("Hollow ball wins. FIRST! Time: %.2lf\n", first);
				second = time[3];
				printf("Hollow cylinder is SECOND! Time: %.2lf\n", second);
				third = time[0];
				printf("Solid ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[2];
				printf("Solid cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[0] < time[1]) && (time[0] < time[2]) && (time[0] < time[3]))
	{
		if ((time[3] < time[1]) && (time[3] < time[2]))
		{
			if (time[2] < time[1])
			{
				first = time[0];
				printf("Solid ball wins. FIRST! Time: %.2lf\n", first);				
				second = time[3];
				printf("Hollow cylinder is SECOND! Time: %.2lf\n", second);				
				third = time[2];
				printf("Solid cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[1];
				printf("Hollow ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[3] < time[0]) && (time[3] < time[1]) && (time[3] < time[2]))	
	{
		if ((time[0] < time[1]) && (time[0] < time[2]))					
		{
			if (time[2] < time[1])
			{
				first = time[3];
				printf("Hollow cylinder wins. FIRST! Time: %.2lf\n", first);					
	 			second = time[0];
				printf("Solid ball is SECOND! Time: %.2lf\n", second);
				third = time[2];
				printf("Solid cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[1];
				printf("Hollow ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}	
		}
	}
	
	
	if ((time[1] < time[0]) && (time[1] < time[2]) && (time[1] < time[3]))
	{
		if ((time[0] < time[2]) && (time[0] < time[3]))
		{
			if (time[3] < time[2])
			{
				first = time[1];
				printf("Hollow ball wins. FIRST! Time: %.2lf\n", first);				
				second = time[0];
				printf("Solid ball is SECOND! Time: %.2lf\n", second);				
				third = time[3];
				printf("Hollow cylinder is THIRD! Time: %.2lf\n", third);
				fourth = time[2];
				printf("Solid cylinder is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[2] < time[0]) && (time[2] < time[1]) && (time[2] < time[3])) 
	{
		if ((time[3] < time[0]) && (time[3] < time[1]))
		{
			if (time[1] < time[0])
			{
				first = time[2];
				printf("Solid cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[3];
				printf("Hollow cylinder is SECOND! Time: %.2lf\n", second);
				third = time[1];
				printf("Hollow ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[0];
				printf("Solid ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	
	
	if ((time[2] < time[0]) && (time[2] < time[1]) && (time[2] < time[3])) 
	{
		if ((time[3] < time[0]) && (time[3] < time[1]))
		{
			if (time[0] < time[1])
			{
				first = time[2];
				printf("Solid cylinder wins. FIRST! Time: %.2lf\n", first);
				second = time[3];
				printf("Hollow cylinder is SECOND! Time: %.2lf\n", second);
				third = time[0];
				printf("Solid ball is THIRD! Time: %.2lf\n", third);					
				fourth = time[1];
				printf("Hollow ball is FOURTH! Time: %.2lf\n", fourth);
				exit(0);
			}
		}
	}
	

	
	return 0; 																			// program ends //
	
	
	
}
