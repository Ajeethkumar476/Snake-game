#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

struct snake_game{
	int x,y;
}snake[110];

//Fruit's position
int posx=18,posy=30;

//snake's original size
int tail=4;

void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,x,y);
}

void border(){
	printf("\n");
	for(int i=4;i<40;i++)
	{
		gotoxy(i,10);
		printf("!!");
	
		gotoxy(i,98);
		printf("!!");
	}
	for(int i=10;i<100;i++)
	{
		
		gotoxy(3,i);
		printf("!");
		gotoxy(40,i);
		printf("!");
	}
}

void main()
{
	snake[0].x=18;snake[0].y=16;
	snake[1].x=18;snake[1].y=18;
	snake[2].x=18;snake[2].y=20;
	snake[3].x=18;snake[3].y=22;
	int counter,col=8,i;
	int max=0,flag=4;
	fd_set rfds;
	
	while(max<10)
	{
	
		system("clear");char dir;
		
	    struct timeval tv;
	    tv.tv_sec = 0;
	    tv.tv_usec = 100;
		FD_ZERO(&rfds);
	    FD_SET(0, &rfds);
		border();
		gotoxy(2,40);
		printf("Score:%d",max);
		int temp=0;
		if(select(1, &rfds, NULL, NULL, &tv)==1){
			system("/bin/stty raw");
			printf("\n");
			dir=getchar();
			printf("\n");
			system("/bin/stty cooked");
			switch(dir){
				case 'w':flag=1;break;
				case 's':flag=2;break;
				case 'a':flag=3;break;
				case 'd':flag=4;break;
				default:break;
			
			}
		}
		if(flag==1)
			snake[0].x=snake[1].x-1;
		else if(flag==2)
			snake[0].x=snake[1].x+1;
		else if(flag==3)	
			snake[0].y=snake[1].y-2;
		else if(flag==4)
			snake[0].y=snake[1].y+2;
		
		for(i=tail;i>0;i-=1){
			snake[i].x=snake[i-1].x;
			snake[i].y=snake[i-1].y;
		}	
		
		if(snake[0].x==3 || snake[0].x==40 || snake[0].y==10 || snake[0].y==98){
			system("clear");system("clear");
			gotoxy(20,50);
			printf("Game Over!!!");
			printf("\tScore:%d",max);
			break;
		}	
			
		for(i=0;i<tail;i+=1){			
			if(snake[i].x==posx && snake[i].y==posy){
				posy+=10;
				tail+=1;
				temp=1;
				max+=1;
			}
			gotoxy(snake[i].x,snake[i].y);
			printf(" *");
			gotoxy(posx,posy);
			printf("0");
		
		}
		
		
		
		
		printf("\n");
		sleep(1);
	
	}	
gotoxy(100,60);
                        
	
}
