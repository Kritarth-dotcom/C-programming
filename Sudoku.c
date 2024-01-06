 #include<stdio.h>
#include<stdlib.h>
void main()
{
    int a[9][9],flag=0;
    printf("Enter the values:\n");
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                if(a[i][j]==a[i][k] && a[i][j]>0)
                    flag+=1;
            if(flag>1)
            {
                printf("Invalid");
                exit(0);
            }
            }
            flag=0;
        }
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
          
            {
                if(a[j][i]==a[k][j] && a[j][i]>0)
                    flag+=1;
            if(flag>1)
            {
                printf("Invalid");
                exit(0);
            }
            }
            flag=0;
        }
    for(int y=0;y<9;y+=3)
        for(int i=0;i<9;i+=3)
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    for(int x=0;x<3;x++)
                    {
                        for(int z=0;z<3;z++)
                            if(a[x+i][z+y]==a[j+i][k+y] && a[j+i][k+y]>0)
                                flag+=1;
                    if(flag>1)
                    {
                        printf("Invalid");
                        exit(0);
                    }
                    }
                flag=0;
                }
            }
    printf("Valid");
}
