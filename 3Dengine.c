/* 3Dengine by Oslomayor,2018 Aug 24th,15:20 */

#include <stdio.h>
#include <math,h>

/* size of 3D Buff */
#define SIZE 255

/* 3D data Buff */
char _3D_Buff[SIZE][SIZE][SIZE]
/* display data Buff */
char Display_Buff[SIZE][SIZE][SIZE]

/* Initialize the 3D Buffer */
void init_3D_Buff()
{
    unsigned char x,y,z;
    for(x=0;x<=SIZE;x++)
		for(y=0;y<=SIZE;y++)
			for(z=0;z<=SIZE;z++)
            {
                if(128<=z&&z<=137)    
                {
                    if((x-127)*(x-127)+(y-127)*(y-127)==900)
                        _3D_Buff[x][y][z]=1;
                    else
                        _3D_Buff[x][y][z]=0;
                }
            }
    return;
}

void turn(char xyz, char theta)
{
    unsigned char x,y,z;
    for(x=0;x<=SIZE;x++)
		for(y=0;y<=SIZE;y++)
			for(z=0;z<=SIZE;z++)
            {
                unsigned char x_temp,y_temp,z_temp;
                switch(xyz)    
                {
                    case 'x':
                    {
                        x_temp = x*cos(theta)-y*sin(theta);
                        y_temp = y*cos(theta)+x*sin(theta);
                        break;
                    }
                    case 'y':
                    {
                        x_temp = x*cos(theta)+z*sin(theta);
                        z_temp = z*cos(theta)-x*sin(theta);
                        break;
                    }
                    case 'z':
                    {
                        y_temp = y*cos(theta)-z*sin(theta);
                        z_temp = z*cos(theta)+y*sin(theta);
                        break;
                    }
                    for(x=0;x<=SIZE;x++)
                        for(y=0;y<=SIZE;y++) 
                            for(z=0;z<=SIZE;z++)
                            {
                                _3D_Buff[x][y][z]=_3d_Buff_Temp[x][y][z];
                            }
                }
            }
    return;
}

void project(char xyz)
{
    /* screen x,y */
    unsigned char xx,yy;
    switch(xyz)
    {

    }
}



