#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Types.h"
/*********************************************/
//Private Do not change on it unil u understand all program
#define Up             			72
#define Dn  		   			80
#define Right 		   			77
#define Left 		   			75
#define Enter 		   			13
#define Esc   		   			27
#define ArrowPressed 		   224
#define Yes 					1
#define No  					0 
#define TailVal 				0
#define HeadVal 				2
#define LessThanNextPoint 		2
#define CoulmnEnd	 			0
		

#define VerticalLine   			219 
#define HerzontalLine  			219  
				
#define EatenChar      			259
#define SnakeChar	   			258       
#define ColBeforeLast  			(MaxCoulmn-3)       
#define StartFromNextCoulmn  	1  

#define SecondRow	  			 1       
			
#define EmptyPoint    			 0 
#define RemoveLastOneInSnake     0 

#define EatenPoint     			7

#define EatenPointScoreValue  	2
    
#define ZeroRow		0
#define ZeroCol		0

#define Close 		0
#define Open		1

/*********************************************/
//Configrable 

#define NormalSpeed    100 
#define IncreaseSpeed  10 
#define DecreaseSpeed  1



#define HighScoreVal	400

#define SnakeStartFromRow  15
#define SnakeStartFromCol  20



//#define MaxCoulmn	   120 //windows 10       
#define MaxCoulmn	   80        
#define MaxRow	  	   20       

#define LengthOfStartSnake     3
		 
/*********************************************/

void GameOver(u16 (*Locals16_Inti)[MaxCoulmn],u8 *PtrLocal_u8Key,u8 *PtrLocal_u8RandomFlagFunc,u16 *PtrLocal_u16CurrentScore,u8 *PtrLocal_u16GameOver,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8ColHeadPostion);
void Intialization(u16 (*Locals16_Inti)[MaxCoulmn],u16 *PtrLocal_u16CurrentScore,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u8HeadVal,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8ColHeadPostion);
void RectangularSystem(u16 (*Locals16_ArrRecSys)[MaxCoulmn],u16 *PtrLocal_u16Score,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8CoHeadlPostion);
void KeyDecision(u16 (*KeyDecision)[MaxCoulmn],u8 *PtrLocal_u8GameOver,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u16Score,u8 *PtrLocal_u8RandomFlagFunc,u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8 *PtrLocal_u8Key,u8* PtrLocal_u8HeadRow,u8* PtrLocal_u8HeadCol);
void RandomPoint(u16 (*Locals16_RandPoi)[MaxCoulmn],u8 *PtrLocal_u8RandomFlagFunc);
u8   GetPressedKeyWithoutBlock(u8 Local_u8Key,u8 *PtrLocal_u8Speed);
void GoToColRow(u8 RowPostion,u8 ColPostion);
void RemoveTail(u16 (*RemoveTail)[MaxCoulmn],u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8 Local_u8PressedKey,u8 Local_u8SnakeLength);
u8   getch_Func(void);
u16  HighScoreOpenFile(void);

int main(void)
{
	u16 Locals16_ArrGame[MaxRow][MaxCoulmn]={0},Local_u16CurrentScore,Local_u16HighScore=0,Local_u8HeadVal=HeadVal*LengthOfStartSnake/*point=2 */,Local_u8TailVal=LessThanNextPoint;	
	u8 Local_u8RowHeadPostion,Local_u8ColHeadPostion;
	u8 Local_u8PressedKey=Left,RandomFlag=Open,Local_u8GameOver=No,Local_u8Speed=NormalSpeed;
	 
	system("Cls");
	printf("\n\n\n				\n\n\n");
	printf("				Pure C Snake Game				\n\n\n");
	printf("			CopyRights:Ahmed Samir Elmenshawy						 \n\n");
	system("Pause");
    system("Cls");
	Intialization(Locals16_ArrGame,&Local_u16CurrentScore,&Local_u16HighScore,&Local_u8HeadVal,&Local_u8RowHeadPostion,&Local_u8ColHeadPostion);//intailize snake size 
	while(Local_u8GameOver==No)
	{
		GoToColRow(ZeroRow,ZeroCol);
		Local_u8PressedKey=GetPressedKeyWithoutBlock(Local_u8PressedKey,&Local_u8Speed);//take pressed PtrLocal_u8Key
		KeyDecision(Locals16_ArrGame,&Local_u8GameOver,&Local_u16HighScore,&Local_u16CurrentScore,&RandomFlag,&Local_u8HeadVal,&Local_u8TailVal,&Local_u8PressedKey,&Local_u8RowHeadPostion,&Local_u8ColHeadPostion);
		RandomPoint(Locals16_ArrGame,&RandomFlag);//to put eaten point random 
		RectangularSystem(Locals16_ArrGame,&Local_u16CurrentScore,&Local_u16HighScore,&Local_u8HeadVal,&Local_u8TailVal,&Local_u8RowHeadPostion,&Local_u8ColHeadPostion);
		Sleep(Local_u8Speed);
	}
	return 0;
}
/*********************************************/
u8 getch_Func(void) 
    {
        if (_kbhit())
            return getch();
        else
            return -1;
    }
/*********************************************/	
void GameOver(u16 (*Locals16_Inti)[MaxCoulmn],u8 *PtrLocal_u8Key,u8 *PtrLocal_u8RandomFlagFunc,u16 *PtrLocal_u16CurrentScore,u8 *PtrLocal_u16GameOver,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8ColHeadPostion)
{
	char Local_u8KeyPressed;
	Sleep(2000);
	system("Cls");//clear Screen
	printf("										\n\n");
	
	printf("\n\n           			 Game Over            \n\n");
	printf("										\n\n");
	printf("\n\n        		 To Play Again Press Enter To exit Press ESC         \n\n");
	while(1)
	{
		Local_u8KeyPressed=getch_Func();
		if(Local_u8KeyPressed==Enter)
		{
			*PtrLocal_u8TailVal=0;
			system("Cls");//clear Screen
			*PtrLocal_u16GameOver=No;
			*PtrLocal_u8RandomFlagFunc=Open;
			*PtrLocal_u8Key=Left;
			Intialization(Locals16_Inti,PtrLocal_u16CurrentScore,PtrLocalu16_HighScore,PtrLocal_u8HeadVal,PtrLocal_u8HeadRowPostion,PtrLocal_u8ColHeadPostion);
			break;
		}
		else if(Local_u8KeyPressed==Esc)
		{
			*PtrLocal_u16GameOver=Yes;
			break;
		}
	}		
} 

void GoToColRow(u8 RowPostion,u8 ColPostion) // go to col and row in screen
{
        //GoToColRow(80,40);//max col and row then will start for 0,0
		HANDLE hOut;
        COORD Position;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        Position.X = ColPostion;
        Position.Y = RowPostion;
        SetConsoleCursorPosition(hOut, Position);
    }
/*********************************************/
u16 HighScoreOpenFile(void)
{
		u16 Localu16_Highscore;
		FILE *ObjectHighScore;
		ObjectHighScore=fopen("HighScorefile.txt", "r");//open if exist
		if(ObjectHighScore == NULL) //if file does not exist, create it
		{
			ObjectHighScore = fopen("HighScorefile.txt", "w");
			fprintf(ObjectHighScore,"%d   ", HighScoreVal);
			Localu16_Highscore=HighScoreVal;
		}
        fscanf(ObjectHighScore,"%d",&Localu16_Highscore);//read value and put it in  Localu16_Highscore
        fclose(ObjectHighScore);
		
		return Localu16_Highscore;
	}
/*********************************************/
void Intialization(u16 (*Locals16_Inti)[MaxCoulmn],u16 *PtrLocal_u16CurrentScore,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u8HeadVal,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8ColHeadPostion)
{
	u8 Local_u8Col,Localu8_CounterRow,Local_u8HeadVal=HeadVal*LengthOfStartSnake;
	
	*PtrLocal_u8HeadVal=HeadVal*LengthOfStartSnake;
	system("color A");//green color	
	system("Cls");//clear Screen
	
	for(Localu8_CounterRow=MaxRow;Localu8_CounterRow>0;Localu8_CounterRow--)//Vetrical line
	{
		for(Local_u8Col=MaxCoulmn;Local_u8Col>0;Local_u8Col--)//-2 cause we add vertical two line
		{
		  Locals16_Inti[Localu8_CounterRow][Local_u8Col]=0;
		}   
	}	
	for(Local_u8Col=SnakeStartFromCol;Local_u8Col< (LengthOfStartSnake+SnakeStartFromCol);Local_u8Col++)//4+20
	{
		Locals16_Inti[SnakeStartFromRow][Local_u8Col]=Local_u8HeadVal;//
		Local_u8HeadVal-=LessThanNextPoint;//every point less than next point by 2 
	}
	*PtrLocal_u16CurrentScore=0;
	//*PtrLocal_u8TailVal=LessThanNextPoint;//last one in snake,start from 2	
	
	*PtrLocal_u8ColHeadPostion=SnakeStartFromCol;//+ beacuse we move reverse array//22
	
	*PtrLocal_u8HeadRowPostion=SnakeStartFromRow;
	
	*PtrLocalu16_HighScore=HighScoreOpenFile();//open high score file
}
/******************************************************************/
void RemoveTail(u16 (*RemoveTail)[MaxCoulmn],u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8 Local_u8PressedKey,u8 Local_u8SnakeLength)
{
	u8  Localu8_CounterCoul,Localu8_CounterRow;
	for(Localu8_CounterRow=ZeroRow;Localu8_CounterRow<MaxRow;Localu8_CounterRow++)
		{
			for(Localu8_CounterCoul=ZeroCol;Localu8_CounterCoul<MaxCoulmn;Localu8_CounterCoul++)
			{
				if(RemoveTail[Localu8_CounterRow][Localu8_CounterCoul]==*PtrLocal_u8TailVal)
				{
					RemoveTail[Localu8_CounterRow][Localu8_CounterCoul]=EmptyPoint;
				}
				else;
			}
		}
	*PtrLocal_u8TailVal+=LessThanNextPoint;
}
/*********************************************/
void KeyDecision(u16 (*KeyDecision)[MaxCoulmn],u8 *PtrLocal_u8GameOver,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u16Score,u8 *PtrLocal_u8RandomFlagFunc,u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8 *PtrLocal_u8Key,u8* PtrLocal_u8HeadRow,u8* PtrLocal_u8HeadCol)
{
	switch(*PtrLocal_u8Key)
	{
		case Left:
		
		if(*PtrLocal_u8HeadCol==CoulmnEnd)
		{
			*PtrLocal_u8HeadCol=MaxCoulmn-3;
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol-1]==EmptyPoint)
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][--*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
		}	
		else if(KeyDecision[* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol-1]==EatenPoint) //
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint+LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][--*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
			*PtrLocal_u8RandomFlagFunc=Open;
			*PtrLocal_u16Score+=EatenPointScoreValue;
		}
		
		else //snake collision on tail
		{
			GameOver(KeyDecision,PtrLocal_u8Key,PtrLocal_u8RandomFlagFunc,PtrLocal_u16Score,PtrLocal_u8GameOver,PtrLocalu16_HighScore,PtrLocal_u8HeadVal,PtrLocal_u8TailVal,PtrLocal_u8HeadRow,PtrLocal_u8HeadCol);
		}
		break;
		
		case Right:
		
		if(*PtrLocal_u8HeadCol==MaxCoulmn-3)
		{
			*PtrLocal_u8HeadCol=CoulmnEnd;
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow][*PtrLocal_u8HeadCol+1]==EmptyPoint)
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][++*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol+1]==EatenPoint) //
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint+LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][++*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
			*PtrLocal_u8RandomFlagFunc=Open;
			*PtrLocal_u16Score+=EatenPointScoreValue;
		}
		else //snake collision on tail
		{
			GameOver(KeyDecision,PtrLocal_u8Key,PtrLocal_u8RandomFlagFunc,PtrLocal_u16Score,PtrLocal_u8GameOver,PtrLocalu16_HighScore,PtrLocal_u8HeadVal,PtrLocal_u8TailVal,PtrLocal_u8HeadRow,PtrLocal_u8HeadCol);
		}
		break;
		
		case Up:
		
		if(* PtrLocal_u8HeadRow==CoulmnEnd)
		{
			*PtrLocal_u8HeadRow=MaxRow-1;
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[*PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;////next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow-1][*PtrLocal_u8HeadCol]==EmptyPoint)
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[--* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;////next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow-1 ][*PtrLocal_u8HeadCol]==EatenPoint) //
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint+LessThanNextPoint;
			KeyDecision[--* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;////next postion take new head val
			*PtrLocal_u8RandomFlagFunc=Open;
			*PtrLocal_u16Score+=EatenPointScoreValue;
		}
		else //snake collision on tail
		{
			GameOver(KeyDecision,PtrLocal_u8Key,PtrLocal_u8RandomFlagFunc,PtrLocal_u16Score,PtrLocal_u8GameOver,PtrLocalu16_HighScore,PtrLocal_u8HeadVal,PtrLocal_u8TailVal,PtrLocal_u8HeadRow,PtrLocal_u8HeadCol);
		
		}
		break;
		
		
		case Dn:
		
		if(*PtrLocal_u8HeadRow==MaxRow-1)
		{
			*PtrLocal_u8HeadRow=ZeroRow;
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow+1][*PtrLocal_u8HeadCol]==EmptyPoint)
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint;
			KeyDecision[++* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
		}
		else if(KeyDecision[* PtrLocal_u8HeadRow+1 ][*PtrLocal_u8HeadCol]==EatenPoint) //
		{
			*PtrLocal_u8HeadVal+=LessThanNextPoint+LessThanNextPoint;
			KeyDecision[++* PtrLocal_u8HeadRow ][*PtrLocal_u8HeadCol]=*PtrLocal_u8HeadVal;//next postion take new head val
			*PtrLocal_u8RandomFlagFunc=Open;
			*PtrLocal_u16Score+=EatenPointScoreValue;
		}
		else //snake collision on tail
		{
			GameOver(KeyDecision,PtrLocal_u8Key,PtrLocal_u8RandomFlagFunc,PtrLocal_u16Score,PtrLocal_u8GameOver,PtrLocalu16_HighScore,PtrLocal_u8HeadVal,PtrLocal_u8TailVal,PtrLocal_u8HeadRow,PtrLocal_u8HeadCol);
		}
		break;
		
		
	}
	
	
}
/*********************************************/
	
void RandomPoint(u16 (*Locals16_RandPoi)[MaxCoulmn],u8 *PtrLocal_u8RandomFlagFunc)//,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8CoHeadlPostion)
{
   time_t t;
   u8 Local_u8Row,Local_u8Col; 
   /* Intializes random number generator */
   srand((u16) time(&t));
    
   while(*PtrLocal_u8RandomFlagFunc==Open)
   {
	   Local_u8Row=rand() % MaxRow;//random row value
	   Local_u8Col=rand() % ColBeforeLast;//random column value & ColBeforeLast beacuse dont give me more than Max-3
	   if(Locals16_RandPoi[Local_u8Row][Local_u8Col]==EmptyPoint)
	   {
		Locals16_RandPoi[Local_u8Row][Local_u8Col]=EatenPoint; 
		*PtrLocal_u8RandomFlagFunc=Close;		
	   }
	   else;
   }
}
/*********************************************/
void RectangularSystem(u16 (*Locals16_ArrRecSys)[MaxCoulmn],u16 *Local_u16CurrentScore,u16 *PtrLocalu16_HighScore,u16 *PtrLocal_u8HeadVal,u16 *PtrLocal_u8TailVal,u8* PtrLocal_u8HeadRowPostion,u8* PtrLocal_u8CoHeadlPostion)
{
		   u8  Localu8_CounterCoul,Localu8_CounterRow;
		   
		   for(Localu8_CounterCoul=MaxCoulmn;Localu8_CounterCoul>0;Localu8_CounterCoul--)//Top herzontal line
		   {
			   printf("%c",HerzontalLine);
		   }
		   for(Localu8_CounterRow=0;Localu8_CounterRow<MaxRow;Localu8_CounterRow++)//Vetrical line
		   {
			   printf("%c",VerticalLine);//put First line
			   for(Localu8_CounterCoul=0;Localu8_CounterCoul<MaxCoulmn-2;Localu8_CounterCoul++)//-2 cause we add vertical two line
				{
				   ///*
				   if(Locals16_ArrRecSys[Localu8_CounterRow][Localu8_CounterCoul]==*PtrLocal_u8TailVal)
					{
						Locals16_ArrRecSys[Localu8_CounterRow][Localu8_CounterCoul]=EmptyPoint;
					}
					//*/
				   if(Locals16_ArrRecSys[Localu8_CounterRow][Localu8_CounterCoul]==EmptyPoint)//
				   {//no point here put blank 
					 printf(" ");
				   }
				   else if(Locals16_ArrRecSys[Localu8_CounterRow][Localu8_CounterCoul]==EatenPoint)
				   {//when you find EatenPoint put Eaten sign  
					   printf("%c",EatenChar);
				   }
				   else if(Locals16_ArrRecSys[Localu8_CounterRow][Localu8_CounterCoul] > EmptyPoint)//snake value
				   {//when you find SnakeValue put Snake  
					   //Debug;
					   printf("%c",SnakeChar);
				   }
				   
				   else;
				   if(Localu8_CounterCoul==ColBeforeLast)//put second line in last coulmn
				   {
						printf("%c",VerticalLine);
				   }
				   else ;				   
			   }
		   }
		   *PtrLocal_u8TailVal+=LessThanNextPoint;
		   for(Localu8_CounterCoul=MaxCoulmn;Localu8_CounterCoul>0;Localu8_CounterCoul--)//Bottom herizontal line
		   {
			   printf("%c",HerzontalLine);
		   }
		   printf("Current Score=%d,High Score=%d" ,*Local_u16CurrentScore,*PtrLocalu16_HighScore);
    }
/*********************************************/
u8 GetPressedKeyWithoutBlock(u8 Local_u8Key,u8 *PtrLocal_u8Speed) 
	{//return left or right or dn or up if pressed else return PtrLocal_u8Key value in argument
    u8 Local_u8Check;
	u8 static Local_u8LastState=Left;
	if (_kbhit())//if any PtrLocal_u8Key pressed
	{
        Local_u8Check=getch();//update Local_u8Check with new PtrLocal_u8Key
		if (Local_u8Check == ArrowPressed||Local_u8Check == 0  )//if arrow pressed
		{	
			Local_u8Check = getch();
			if(Local_u8Check==Left &&Local_u8LastState==Right )//if last PtrLocal_u8Key Right then pressed left PtrLocal_u8Key will Right 
			{
				Local_u8Check=Right;
			}
			else if(Local_u8Check==Right &&Local_u8LastState==Left )//if last PtrLocal_u8Key Left then pressed Right PtrLocal_u8Key will Left
			{
				Local_u8Check=Left;
			}
			else if(Local_u8Check==Up &&Local_u8LastState==Dn )//if last PtrLocal_u8Key Dn then pressed Up PtrLocal_u8Key will Dn
			{
				Local_u8Check=Dn;
			}
			else if(Local_u8Check==Dn &&Local_u8LastState==Up )//if last PtrLocal_u8Key Up then pressed Dn PtrLocal_u8Key will Up
			{
				Local_u8Check=Up;
			}
			
			else if(Local_u8Check==Dn &&Local_u8LastState==Up )//if last PtrLocal_u8Key Up then pressed Dn PtrLocal_u8Key will Up
			{
				Local_u8Check=Up;
			}
			else;
			if(*PtrLocal_u8Speed > IncreaseSpeed)//if pressed on arrow speed will increase
			{
				*PtrLocal_u8Speed-=IncreaseSpeed;
			}
			else;
		}
		else 
		{
			Local_u8Check=Local_u8Key;//put the last PtrLocal_u8Key pressed 
		}
    }
	else//if nothing pressed return PtrLocal_u8Key
	{
         Local_u8Check=Local_u8Key;
		 if(*PtrLocal_u8Speed < NormalSpeed)//if no pressed  key will decrease speed
		 {
			 *PtrLocal_u8Speed+=DecreaseSpeed;
		 }
		else;	
	}
	Local_u8LastState=Local_u8Check;
	return Local_u8Check;
}