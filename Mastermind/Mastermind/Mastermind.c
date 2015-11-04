//Mastermind in C by MartinColeman
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declare methods
int showMenu();
void showInstructions();
void play();
void displayScore();
void selectDifficulty();
void selectNoGuess();
void generateSequenceEasy();
void generateSequenceMedium();
void generateSequenceHard();
void inputPegs();
void compare();
void convert();

//declare variables
int iDiff,iOption,iGuess,guessCount=0,r,i;
char c;
int p1,p2,p3,p4;
int randomPegs[4],p1Pegs[4];
char userPegs[4];
int toupper(int c);

//Main
main()
{
	int iChoice;
	do
	{
	switch(iChoice=showMenu())
	{
		case 1:
			{
				play();
				break;
			}
		case 2:
			{
				showInstructions();
				break;
			}
		case 3:
			{
				displayScore();
				break;
			}
		case 4:
			{
				printf("\n Thanks For Playing");
				printf("\n\n\n");
				system("pause");
				exit(0);
				break;
			}
		default:
			{
				printf("\n\tInvalid Input");
				printf("\n\n\n");
				system("pause");
			}
	}

	}while(iChoice!=4);	

}//end main

int showMenu()
{
	int iChoice;

	do
	{
		system("cls");
		printf("\n\n\tMastermind Menu");
		printf("\n\n\t1: Play");
		printf("\n\n\t2: Instuctions");
		printf("\n\n\t3: View Highscores");
		printf("\n\n\t4: Exit");

		printf("\n\n\n\tEnter a valid choice: ");
		fflush(stdin);
		scanf("%d",&iChoice);
	
	}while((iChoice<=1)&&(iChoice>=4));

	return(iChoice);
}

void displayScore()
{
	do
	{
		system("cls");
		printf("\n\tHighscores");
		printf("\n--------------------------------------------------------------------------------");
		printf("\n\t1: Show Best Round");
		printf("\n\t2: Show Percentage Win and loses");
		printf("\n\t3: Return to Main Menu");

		printf("\n\n\tEnter a valid choice: ");
		fflush(stdin);
		scanf("%d",&iOption);

		if (iOption==1)
		{
			printf("\n\t1: display Best Round method here");
			printf("\n\n\n");
			system("pause");
		}

		if (iOption==2)
		{
			printf("\n\t2: Display Percentage Win and loses method here");
			printf("\n\n\n");
			system("pause");
		}

		if((iOption<1)||(iOption>3))
		{
			printf("\n\t1: Invalid Option");
			printf("\n\n\n");
			system("pause");
		}
	
	}while((iOption!=3));
}//end displayScore

void showInstructions()
{
	printf("\n\n\n\tMASTERMIND INSTRUCTIONS");
	printf("\n\n\n--------------------------------------------------------------------------------");
	printf("\n\n\nMastermind is a game where the object is to guess the order of four prearranged pegs that are generated randomly by the computer.\nThe four colours may be repeated and there may be blank spots in the pattern as well.\nThe colours are drawn from the rainbow\nRed, Orange, Yellow, Green, Blue, Indigo and Violet. \nThe player has to guess the order of the pegs.\nOnly a winning guess will be confirmed by the program.\nIn all other cases a combination of black and white pegs will be used to give \nfeedback in the following way:\na white peg indicates a correct colour in the wrong position,\na black peg indicates a correct colour in the correct position\nSo if the user guesses all of the colours correctly,\nbut has no peg correctly placed,\nthen the feedback is four white pegs.\nIf no colours are correct, then no pegs are awarded for that guess.");
	printf("\n\n\n--------------------------------------------------------------------------------");
	printf("\n\n");
	system("pause");
}//end showIns

void selectDifficulty()
{
	printf("\n\tSelect Your Difficulty");
	printf("\n--------------------------------------------------------------------------------");

	do
	{
		printf("\n\t1: Easy");
		printf("\n\t2: Medium");
		printf("\n\t3: Hard");

		printf("\n\n\tEnter a valid choice: ");
		fflush(stdin);
		scanf("%d",&iDiff);
	
	}while((iDiff<1)||(iDiff>3));

}//end selectDifficulty

void selectNoGuess()
{
	printf("\n--------------------------------------------------------------------------------");
	printf("\n\tSelect Number of Guesses");
	printf("\n--------------------------------------------------------------------------------");
	
	do
	{
		printf("\n\t Select Number of guesses(Max 15)");

		printf("\n\n\tEnter a valid choice: ");
		fflush(stdin);
		scanf("%d",&iGuess);

		}while((iGuess<1)||(iGuess>15));//while guess less than 1 or guess greater than 15 repeat
}

void generateSequenceEasy()
{
	srand(time(NULL));

	r = (rand() % 7) +1;
	p1=r;//saves random num as peg 1

	do
	{
		r = (rand() % 7) +1;
	}while(r==p1);//keeps looping until pegs 1 and 2 dont repeat
	p2=r;//saves random num as peg 2

	do
	{
		r = (rand() % 7) +1;
	}while(r==p1||r==p2);//keeps looping until pegs 1,2 and 3 pegs repeats
	p3=r;//saves random num as peg 3

	do
	{
		r = (rand() % 7) +1;
	}while(r==p1||r==p2||r==p3);//keeps looping until no peg repeats
	p4=r;//saves random num as peg 4
	
	/* 
		red=1
		orange=2
		yellow=3
		green=4
		blue=5
		indigo=6
		violet=7
	*/
	
	/*
	//show the numbers generated
	printf("\n\tRandom Test is %d %d %d %d",p1,p2,p3,p4);
	printf("\n\n\n");
	system("pause");
	*/
	
	//stores values in array
	 randomPegs[0] = p1;
	 randomPegs[1] = p2;
	 randomPegs[2] = p3;
	 randomPegs[3] = p4;

	printf("\n\tComputer has generated four random pegs with no repeats pegs or spaces");
}

void generateSequenceMedium()
{
	srand(time(NULL));
	//generates repeats with no blanks
	r = (rand() % 7) +1;//Random num 1-7
	p1=r;//Store random num

	r = (rand() % 7) +1;//Random num 1-7
	p2=r;//Store random num

	r = (rand() % 7) +1;//Random num 1-7
	p3=r;//Store random num

	r = (rand() % 7) +1;//Random num 1-7
	p4=r;//Store random num

	/* 
		red=1
		orange=2
		yellow=3
		green=4
		blue=5
		indigo=6
		violet=7
	*/

	/*
	//show the numbers generated
	printf("\n\tRandom Test is %d %d %d %d",p1,p2,p3,p4);
	printf("\n\n\n");
	system("pause");
	*/
	
	//stores values in array
	 randomPegs[0] = p1;
	 randomPegs[1] = p2;
	 randomPegs[2] = p3;
	 randomPegs[3] = p4;

	printf("\n\tComputer has generated four random pegs with repeats pegs but no spaces");
}
void generateSequenceHard()
{
	srand(time(NULL));
	//generates repeats with no blanks
	r = (rand() % 8) +1;//Random num 1-8
	p1=r;//Store random num

	r = (rand() % 8) +1;//Random num 1-8
	p2=r;//Store random num

	r = (rand() % 8) +1;//Random num 1-8
	p3=r;//Store random num

	r = (rand() % 8) +1;//Random num 1-8
	p4=r;//Store random num

	/* 
		red=1
		orange=2
		yellow=3
		green=4
		blue=5
		indigo=6
		violet=7
		blank space=8
	*/

	/*
	//show the numbers generated
	printf("\n\tRandom Test is %d %d %d %d",p1,p2,p3,p4);
	printf("\n\n\n");
	system("pause");
	*/

	//stores values in array
	 randomPegs[0] = p1;
	 randomPegs[1] = p2;
	 randomPegs[2] = p3;
	 randomPegs[3] = p4;
	

	printf("\n\tComputer has generated four random pegs with repeats pegs and spaces");
}

void inputPegs()
{
	do
	{
		system("cls");
		printf("\n\tEnter Your Guess");
		printf("\n--------------------------------------------------------------------------------");
		printf("\n\tred=R	orange=O	yellow=Y	green=G 	blue=B");
		printf("\n\tindigo=I	violet=V    blank space='-'");
		printf("\n--------------------------------------------------------------------------------");


		printf("\n\n\tEnter a First valid Peg(R,O,Y,G,B,I,V,'-'for blank):");
		fflush(stdin);
		scanf("%c",&c);
		c=toupper(c);
	
	}while((c!='R'&&c!='O'&&c!='Y'&&c!='G'&&c!='B'&&c!='I'&&c!='V'&&c!='-'));
	userPegs[0]=c;
	do
	{
		printf("\n\n\n\tEnter a Second valid Peg(R,O,Y,G,B,I,V,'-'for blank):");
		fflush(stdin);
		scanf("%c",&c);
		c=toupper(c);
	
	}while((c!='R'&&c!='O'&&c!='Y'&&c!='G'&&c!='B'&&c!='I'&&c!='V'&&c!='-'));
	userPegs[1]=c;
	do
	{
		printf("\n\n\n\tEnter a	Third valid Peg(R,O,Y,G,B,I,V,'-'for blank):");
		fflush(stdin);
		scanf("%c",&c);
		c=toupper(c);
	
	}while((c!='R'&&c!='O'&&c!='Y'&&c!='G'&&c!='B'&&c!='I'&&c!='V'&&c!='-'));
	userPegs[2]=c;

	do
	{
		printf("\n\n\n\tEnter a Fourth valid Peg(R,O,Y,G,B,I,V,'-'for blank):");
		fflush(stdin);
		scanf("%c",&c);
		c=toupper(c);
	
	}while((c!='R'&&c!='O'&&c!='Y'&&c!='G'&&c!='B'&&c!='I'&&c!='V'&&c!='-'));
	userPegs[3]=c;
	
	//output user input
	printf("\n\tYour Guess is ");	
	for(i = 0; i <= 3; i++)
	{
        printf("%c ", userPegs[i]);	
	} 

	//stored as, char userPegs[4] = {input1,input2,input3,input4};
	
	convert();//converts char array to a seperate number array
}

void convert()
{
	/* 
		red=1
		orange=2
		yellow=3
		green=4
		blue=5
		indigo=6
		violet=7
		blank space=8
	*/
	for(i=0;i<=3;i++)
	{
		if(userPegs[i]=='R')
		{
			p1Pegs[i]=1;
		}//if

		else if(userPegs[i]=='O')
		{
			p1Pegs[i]=2;
		}

		else if(userPegs[i]=='Y')
		{
			p1Pegs[i]=3;
		}

		else if(userPegs[i]=='G')
		{
			p1Pegs[i]=4;
		}

		else if(userPegs[i]=='B')
		{
			p1Pegs[i]=5;
		}

		else if(userPegs[i]=='I')
		{
			p1Pegs[i]=6;
		}

		else if(userPegs[i]=='V')
		{
			p1Pegs[i]=7;
		}

		else if(userPegs[i]=='-')
		{
			p1Pegs[i]=8;
		}

		else
		{
			p1Pegs[i]=999;
		}

	}//for

	printf("\n\tYour numerical Guess is ");	
	for(i = 0; i <= 3; i++)
	{
        printf("%d ", p1Pegs[i]);	
	} 
	system("pause");
}//convert

void compare()
{
	if(userPegs[0]==p1Pegs[0])
	{
		printf("\n\t1: Easy");
	}


}//end compare

void play()
{
	system("cls");
	printf("\n\tWELCOME TO MASTERMIND");
	printf("\n--------------------------------------------------------------------------------");
	
	selectDifficulty();//Method to select difficulty

	selectNoGuess();//Method to select No of guesses

	//generate sequence
	if(iDiff==1)//easy Generator
	{
		generateSequenceEasy();
	}

	if(iDiff==2)//meduim generator
	{
		generateSequenceMedium();
	}

	if(iDiff==3)//hard generator
	{
		generateSequenceHard();
	}

	
	do
	{
		inputPegs();//takes in users guess
		compare();//compare guess and returns value
		guessCount++;

	}while(guessCount!=iGuess);

	printf("\n\tGame Over!!");
	printf("\n\tReturning To Main Menu");
	printf("\n\n\n");
	system("pause");
}//end play