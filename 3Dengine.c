/* 3Dengine by Oslomayor,2018 Aug 24th,15:20 */

#include <stdio.h>
#include <math.h>

/* size of 3D Buff */
#define SIZE 255

/* 3D data Buff */
char $3D_Buff[SIZE][SIZE][SIZE]
/* display data Buff */
char Display_Buff[SIZE][SIZE][SIZE]

/** 
  * @brief  Initialize the 3D Data Buffer
  * @note   Be careful about the buffer SIZE
  * @param  None 
  */
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
                        $3D_Buff[x][y][z]=1;
                    else
                        $3D_Buff[x][y][z]=0;
                }
            }
    return;
}

/** 
  * @brief  Rotate the 3D Module in the Data Buffer
  * @note   
  * @param  xyz: where the 3D Mudule can be rotated via certain coordinate axis
  *           This parameter can be one of the following values:
  *            @arg 'x': rotate via x axis
  *            @arg 'y': rotate via y axis
  *            @arg 'z': rotate via z axis
  * @param  theta: where the 3D Mudule rotation angle can be set
  *           This parameter can be set from [0,360]
  */
void rotate(char xyz, char theta)
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
                }
                for(x=0;x<=SIZE;x++)
                        for(y=0;y<=SIZE;y++) 
                            for(z=0;z<=SIZE;z++)
                                $3D_Buff[x][y][z]=_3d_Buff_Temp[x][y][z];
            }
    return;
}

/**
  * @breaf  Project the 3D Mudule to a plane to display
  * @note   This function can help you transform 3D data to 2D data
  *         in selected direction
  * @param  xyz: where the project direction can be selected
  *           This parameter can be one of the following values:
  *            @arg 'x': project to yz plane
  *            @arg 'y': project to zx plane
  *            @arg 'z': project to xy plane
  */
void project(char xyz)
{
    /* screen x,y */
    unsigned char x_screen,y_screen;
    switch(xyz)
    {
        case 'x': 
            for(y=0;y<=SIZE;y++)
                for(z=0;z<=SIZE;z++)
                    for(x=0;x<=SIZE;x++)
                    {
                        if(0 != $3D_Buff[x][y][z])
                            Display_Buff[y][z] = $3D_Buff[x][y][z];
                        else
                            Display_Buff[y][z] = 0;
                    }break;
        case 'y': 
            for(z=0;z<=SIZE;z++)
                for(x=0;x<=SIZE;x++)
                    for(y=0;y<=SIZE;y++)
                    {
                        if(0 != $3D_Buff[x][y][z])
                            Display_Buff[z][x] = $3D_Buff[x][y][z];
                        else
                            Display_Buff[z][x] = 0;
                    }break;

        case 'z': 
            for(x=0;x<=SIZE;x++)
                for(y=0;y<=SIZE;y++)
                    for(z=0;z<=SIZE;z++)
                    {
                        if(0 != $3D_Buff[x][y][z])
                            Display_Buff[x][y] = $3D_Buff[x][y][z];
                        else
                            Display_Buff[x][y] = 0;
                    }break;
    }
}

