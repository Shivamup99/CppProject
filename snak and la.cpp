#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;
void gotoxy(int x,int y)                                  //defiation of gotoxy it is use to point the cursor
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
static int temp1=0,temp2=0,count=0;                                   //global
/*                                                              HERE CODE STARTS                   */
class function{
	public:
		virtual void fun()=0;                          //Abstact function
		void rules();	                               //A function which by another class  via inheritance.
		void board_view();                             //it gives the diagram of board.
     	void board_info();                             //it tells about the snake and ladder position.
	    void board_rules();                            //it tells about rules and regulation.
	    void horizonlinemaker(int a,char v);           //defination of horizontal line function.
        void new_game();                               //It is use to call new game.
        void p1status(int a);                          //Gives the live status of 1st player.
        void p2status(int b);                          //Gives the live status of 2nd player.
        int check(int chk);                            //Use to check is there snake or ladder is present or not.
        void info();
        void dicee();                                  //flipflop
        void dicooo(int t);                           //dice vlue
	    void prevs();                                 //file handadaling 
};
//////////////////////////////////////////////Rules ///////////////////////////////////////////
void function::rules(){
    board_view();
	board_info();
	board_rules(); 
}
///////////////////////////////////////// [     B VIEW     ] /////////////////////////////////  
void function::board_view(){
	system("cls");
                     gotoxy(74,2);
                     system("color 0f");
                     cout<<"Board view";
                     gotoxy(76,4);
                     horizonlinemaker(50,'_');
                     gotoxy(75,5);
                     cout<<"| 100 | 99 | 98 | 97 | 96 | 95 | 94 | 93 | 92 | 91 |";
                     gotoxy(76,6);
                     horizonlinemaker(50,'_');
                     gotoxy(75,7);
                     cout<<"| 82  | 82 | 83 | 84 | 85 | 86 | 87 | 88 | 89 | 90 |";
                     gotoxy(76,8);
                     horizonlinemaker(50,'_');
                     gotoxy(75,9);
                     cout<<"| 80  | 79 | 78 | 77 | 76 | 75 | 74 | 73 | 72 | 71 |";
                     gotoxy(76,10);
                     horizonlinemaker(50,'_');
                     gotoxy(75,11);
                     cout<<"| 61  | 62 | 63 | 74 | 65 | 66 | 67 | 68 | 69 | 70 |";
                     gotoxy(76,12);
                     horizonlinemaker(50,'_');
                     gotoxy(75,13);
                     cout<<"| 60  | 59 | 58 | 57 | 56 | 55 | 54 | 53 | 52 | 51 |";
                     gotoxy(76,14);
                     horizonlinemaker(50,'_');
                     gotoxy(75,15);
                     cout<<"| 41  | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |";
                     gotoxy(76,16);
                     horizonlinemaker(50,'_');
                     gotoxy(75,17);
                     cout<<"| 40  | 39 | 38 | 37 | 36 | 35 | 34 | 33 | 32 | 31 |";
                     gotoxy(76,18);
                     horizonlinemaker(50,'_');
                     gotoxy(75,19);
                     cout<<"| 21  | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 |";
                     gotoxy(76,20);
                     horizonlinemaker(50,'_');
                     gotoxy(75,21);
                     cout<<"| 20  | 19 | 18 | 17 | 16 | 15 | 14 | 13 | 12 | 11 |";
                     gotoxy(76,22);
                     horizonlinemaker(50,'_');
                     gotoxy(75,23);
                     cout<<"|  1  | 2  | 3  | 4  | 5  | 5  | 7  | 8  | 9  | 10 |";
                     gotoxy(76,24);
                     horizonlinemaker(50,'_');

}
////////////////////////////////////////////////Line maker//////////////////////////////////////////
inline void function::horizonlinemaker(int a,char v)          //inline
         {
             for(int i=0;i<a;i++)
             {
              cout<<v;
             }
         }
/////////////////////////////////////////// RULES AND REGULATION //////////////////          
void function::board_rules(){
	 gotoxy(0,57);
                cout<<"Rules and regulation";
                gotoxy(0,59);
                cout<<"* In this game 2 players are require.";
                gotoxy(0,60);
                cout<<"* Both of the players are given chance to start their game.";
                gotoxy(0,61);
                cout<<"* If 6 is come then player is allow to enter the game else he make further try.";
                gotoxy(0,62);
                cout<<"* If any player reach at the position of  ladder , Then they reach to the ending point of th ladder .";
                gotoxy(0,63);
                cout<<"* If any player reach at the position of snake , Then they come back to the ending position of the snake.";
                gotoxy(0,64);
                cout<<"* The person Who first reach at 100 position are become the Winner of this game.";
                cout<<endl;
}   
void function::board_info() {
	 gotoxy(76,29);
                    cout<<"Board information ";
            
                    gotoxy(20,35);
                    cout<<"~~~~~~~~~~~~~> SNake PosiTION <~~~~~~~~~~~~~~~~";
                    gotoxy(20,38);
                    cout<<"24 ~ 11 ";
                    gotoxy(20,40);
                    cout<<"52 ~ 29 ";
                    gotoxy(20,42);
                    cout<<"62 ~ 19 ";
                    gotoxy(20,44);
                    cout<<"66 ~ 59 ";
                    gotoxy(20,46);
                    cout<<"74 ~ 17 ";
                    gotoxy(20,48);
                    cout<<"89 ~ 69 ";
                    gotoxy(20,50);
                    cout<<"95 ~ 75 ";
                    gotoxy(20,52);
                    cout<<"98 ~ 79";
                   

                    gotoxy(120,35);
                    cout<<"|-| |-| |-| |-| LADder posiTION |-| |-| |-| |-|";
                    gotoxy(120,38);
                    cout<<"4 ~ 14 ";
                    gotoxy(120,40);
                    cout<<"9 ~ 31 ";
                    gotoxy(120,42);
                    cout<<"18 ~ 45 ";
                    gotoxy(120,44);
                    cout<<"21 ~ 42 ";
                    gotoxy(120,46);
                    cout<<"28 ~ 84 ";
                    gotoxy(120,48);
                    cout<<"51 ~ 67 ";
                    gotoxy(120,50);
                    cout<<"71 ~ 91 ";
                    gotoxy(120,52);
                    cout<<"78 ~ 97";
} 
///////////////////////////////////////////// GAME BEAGAIN ////////////////////////////////////////////////// 
void function::new_game()
{   system("color 0f");
    fstream f1;
	f1.open("snakeandl.txt",ios::out);
	srand(time(NULL));                                     //Initilize rand to null.
	system("color 07");
string firstplayer ;
string secondplayer ;
system("cls");
static int pos1=0,pos2=0,base;
gotoxy(74,12);
fflush(stdin);
cout<<"Enter first player's Name";
gotoxy(74,15);
getline(cin,firstplayer);
f1<<"first player name is "<<firstplayer<<endl;
system("cls");
gotoxy(74,12);
cout<<"Enter second player's Name"<<endl;
gotoxy(74,14);
getline(cin,secondplayer);
f1<<"second player name is"<<secondplayer<<endl;
system("cls");
gotoxy(74,12);
cout<<"!!Press any key for start the game!!"<<endl;
gotoxy(75,13);
getch();
system("clr");
board_info();
while(temp1<100 || temp2<100){
	++count;
	system("color 07");
    	p1status(temp1);
	    p2status(temp2);
system("cls");
board_info();
        p1status(temp1);
	     p2status(temp2);
gotoxy(12,12);

cout<<firstplayer<<" press any key to roll the dice"<<endl;
gotoxy(13,13);
getch();
pos1=rand()%6+1;
dicee();
dicooo(pos1);
                    if(temp1!=0){
					    	temp1=temp1+pos1;
					        getch();
	                        temp1=check(temp1);
                          	if(temp1>100){
		                             temp1=temp1-pos1;
	                            }
	                        if(temp1==100){
	                        	      system("color 60");
		                              cout<<"Yipee!! :) cogratulation "<<firstplayer<<" you won"<<endl;
		                              f1<<"Winner is "<<firstplayer<<endl;
									  f1<<"player  takes "<<count<<" chance\n";
		                              exit(1);
			                    }
			                p1status(temp1);
						    p2status(temp2);
                        }
						/*!!!!!!!!!!!!!*/
                    if(temp1==0){
                    	gotoxy(16,20);
                    	if(pos1==6){
                        	cout<<"HURRAY!! ): You are in the game"<<endl;
                           	getch();
                        	system("cls");
                        	board_info();
                            pos1=1;
                            temp1=1;
							p1status(temp1);
							p2status(temp2);
                        }
                        
                        else{
                        	gotoxy(16,20);
                           	cout<<"Unlucky!! :( Try again"<<endl;
                           	getch();
						    system("cls");
						    board_info();
                        }
                    }    

p1status(temp1);
p2status(temp2);                        
gotoxy(12,12);
cout<<secondplayer<<" press any key to roll the dice"<<endl;
gotoxy(13,13);
getch();
pos2=(rand()%6+1);
dicee();
dicooo(pos2);
                        if(temp2!=0){
						       temp2=temp2+pos2;
	                           temp2=check(temp2);
	                           if(temp2>100){
		                           temp2=temp2-pos2;
                               	}
	                           if(temp2==100){
	                           	system("color 60");
		                            cout<<"Yipee!! :) cogratulation "<<secondplayer<<" you won"<<endl;
		                            f1<<"Winner is "<<secondplayer<<endl;
									f1<<"player  takes "<<count<<" chances"<<endl;
		                            exit(1); 
			                       }
			                    p1status(temp1);
						    	p2status(temp2);
                           }
                             /*!!!!!!!!!!!!!*/
 
                         if(temp2==0){
                            	gotoxy(16,20);
                            	if(pos2==6){
	                            cout<<"HURRAY!! :) You are in the game"<<endl;
	                            system("cls");
	                            board_info();
	                            pos2=1;
	                            temp2=1;
							    p1status(temp1);
	                            p2status(temp2);
                              }
                           
                           else{
                           	   gotoxy(16,20);
	                           cout<<"Unlucky!! ): Try again"<<endl;
							   getch();
	                           system("cls");
	                           board_info();
                           }
                       }                       
    }
	f1.close();		
}
////////////////////////////////////////////position 1 ka status /////////////////////////////////////////////
inline void function::p1status(int a){
                                gotoxy(100,12);
                                horizonlinemaker(40,'-');
                                gotoxy(100,13);
                                cout<<"|                                      |";
                                gotoxy(100,14);
                                cout<<"|  Position of player 1 is "<<a <<"          |";
}
/////////////////////////////////////////////positon 2 ka status ////////////////////////////////////////////////
inline void function::p2status(int b)
{
                                gotoxy(100,15);
                                cout<<"|                                      |";
                                gotoxy(100,16);
                                cout<<"|  Position of player 2 is "<<b <<"          |";
                                gotoxy(100,17);
                                cout<<"|                                      |";
                                gotoxy(100,18);
                                horizonlinemaker(40,'-');
}
///////////////////////////////////////////////Check switch case //////////////////////////////////////////
int function::check(int chk)
{
	    gotoxy(16,20);
		switch(chk)
	{
		case 4:
			system("color 10");
			cout<<"\n\n\t\tHurray :) you found a ladder at 4, Now you climbed at 14"<<endl;
			getch();
			system("cls");
			board_info();
			return 14;
			break;
		case 9:
			system("color 10");
			cout<<"\n\n\t\tHurray :) you found a ladder at 9, Now you climbed at 31"<<endl;
			getch();
			system("cls");
			board_info();
			return 31;
			break;
		case 18:
			system("color 10");
			cout<<"\n\n\t\tHurray :) you found a ladder at 18, Now you climbed at 45"<<endl;
			getch();
			system("cls");
			board_info();
			return 45;
			break;
		case 21:
			system("color 10");
			cout<<"\n\n\t\tHurray :) you found a ladder at 21, Now you climbed at 42"<<endl;
			getch();
			system("cls");
			board_info();
			return 42 ;
			break;
	    case 28 :
	    	system("color 10");
		    cout<<"\n\n\t\tHurray :) you found a ladder at 28, Now you climbed at 84"<<endl;
			getch();
			system("cls");
			board_info();
			return 84;
			break;
		case 51:
			system("color 10");
			cout<<"\n\n\t\tHurray :) you found a ladder at 51, Now you climbed at 67"<<endl;
			getch();
			system("cls");
			board_info();
			return 67 ;
			break;
		case 71:
			system("color 10");
			cout<<"\n\n\t\tHurray :) you found a ladder at 71, Now you climbed at 91"<<endl;
			getch();
			system("cls");
			board_info();
			return 91;
			break;
		case 78:
			system("color C0");
			cout<<"\n\n\t\tHurray :) you found a ladder at 78, Now you climbed at 97"<<endl;
			getch();
			system("cls");
			board_info();
			return 97 ;
			break;
			/*snake*/
     	case 24 :
     		system("color C0");
     		cout<<"\n\n\t\tUnluckly ): you found a snake at 24, Now you dropped at 11"<<endl;
			getch();
			system("cls");
			board_info();
			return 11;
			break;
		case 52:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake at 52, Now you dropped at 29"<<endl;
			getch();
			system("cls");
			board_info();
			return 29;
			break;
		case 62:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake 62, Now you dropped at 19"<<endl;
			getch();
			system("cls");
			board_info();
			return 19;
			break;
		case 66:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake at 66, Now you dropped at 59"<<endl;
			getch();
			system("cls");
			board_info();
			return 59;
			break;
		case 74:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake at 74, Now you dropped at 17"<<endl;
			getch();
			system("cls");
			board_info();
			return 17;
			break;
		case 89:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake at 89, Now you dropped at 69"<<endl;
			getch();
			system("cls");
			board_info();
			return 69;
			break;
		case 95:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake at 95, Now you dropped at 75"<<endl;
			getch();
			system("cls");
			board_info();
			return 75;
			break;
		case 98:
			system("color C0");
			cout<<"\n\n\t\tUnluckly ): you found a snake at 98, Now you dropped at 79"<<endl;
			getch();
			system("cls");
			board_info();
			return 79;
			break;
		default:
				return chk;
				break;
	}
	
	}
/////////////////////////////////////////////// About developer////////////////////////////////////////		
	void function::info(){
		system("color 0f");
		system("cls");
		system("color 0f");
		gotoxy(62,11);
		horizonlinemaker(50,'_');
		gotoxy(62,12);
		cout<<"|            developed by -: Gaurav phalke        |";
		gotoxy(62,13);
		cout<<"|            At year     -: 2018                  |";
		gotoxy(62,14);
		cout<<"|            Develop in c++  language             |";
		gotoxy(62,15);
		system("color 05");
		cout<<"|            LOVELY PROFESSIONAL UNIVERSITY       |";
		gotoxy(62,16);
		horizonlinemaker(50,'_');
	}
/////////////////////////////////////////////////DICE ROLLING/////////////////////////////////////////////////	
void function::dicee()
{                                                        
int i;
    for(i=0;i<10;i++)
    {  
        
        {
        gotoxy(16,15);
        cout<<" _____"<<endl;
        gotoxy(16,16);
        cout<<"|       |"<<endl;
        gotoxy(16,17);
        cout<<"|   *   |"<<endl;
        gotoxy(16,18);
        cout<<"|_______|"<<endl;
        for(int k;k<300000;k++);
        p1status(temp1);
	    p2status(temp2);
		board_info();
        }
        {
        gotoxy(16,15);
        cout<<" _______"<<endl;
        gotoxy(16,16);
        cout<<"|   *   |"<<endl;
        gotoxy(16,17);
        cout<<"|   *   |"<<endl;
        gotoxy(16,18);
        cout<<"|_______|"<<endl;
        
        for(int k;k<300000;k++);
        p1status(temp1);
	    p2status(temp2);
		board_info();        
        }
        {
		gotoxy(16,15);	
        cout<<" _______"<<endl;
        gotoxy(16,16);
        cout<<"| *   * |"<<endl;
        gotoxy(16,17);
        cout<<"|   *   |"<<endl;
        gotoxy(16,18);
        cout<<"|_______|"<<endl;
        for(int k;k<300000;k++);
        p1status(temp1);
	    p2status(temp2);
		board_info();        
        }
        {
        gotoxy(16,15);
        cout<<" _______"<<endl;
        gotoxy(16,16);
        cout<<"|  * *  |"<<endl;
        gotoxy(16,17);
        cout<<"|  * *  |"<<endl;
        gotoxy(16,18);
        cout<<"|_______|"<<endl;
        for(int k;k<300000;k++);
        p1status(temp1);
	    p2status(temp2);
		board_info();        
        }
        {
        gotoxy(16,15);
        cout<<" _______"<<endl;
        gotoxy(16,16);
        cout<<"| * * * |"<<endl;
        gotoxy(16,17);
        cout<<"|  * *  |"<<endl;
        gotoxy(16,18);
        cout<<"|_______|"<<endl;
        for(int k;k<300000;k++);
        p1status(temp1);
	    p2status(temp2);
		board_info();        
        }
        {
        gotoxy(16,15);
        cout<<" _______"<<endl;
        gotoxy(16,16);
        cout<<"| * * * |"<<endl;
        gotoxy(16,17);
        cout<<"| * * * |"<<endl;
        gotoxy(16,18);
        cout<<"|_______|"<<endl;
        for(int k;k<30000;k++);
        p1status(temp1);
	    p2status(temp2);
		board_info();        
        }
        
    }
}	
////////////////////////////////////////////////fINAAL DICE VALUE/////////////////////////////////////
void function::dicooo(int t)                          
{ 
	switch(t)
	{
		case 1:
			{
			        p1status(temp1);
	                p2status(temp2);
		            board_info();
		            gotoxy(16,15);
			        cout<<" _______"<<endl;
			        gotoxy(16,16);
			        cout<<"|       |"<<endl;
			        gotoxy(16,17);
			        cout<<"|   *   |"<<endl;
			        gotoxy(16,18);
			        cout<<"|_______|"<<endl; 
			        
			break;
			}
		case 2:
			{
			
			         p1status(temp1);
	                 p2status(temp2);
					 gotoxy(16,15);
			        cout<<" _______"<<endl;
			        gotoxy(16,16);
			        cout<<"|   *   |"<<endl;
			        gotoxy(16,17);
			        cout<<"|   *   |"<<endl;
			        gotoxy(16,18);
			        cout<<"|_______|"<<endl;
			        
			break;
			}
		case 3:
			{
	                 p1status(temp1);
	                 p2status(temp2);
		             board_info();
		             gotoxy(16,15);
			        cout<<" _______"<<endl;
			        gotoxy(16,16);
			        cout<<"| *   * |"<<endl;
			        gotoxy(16,17);
			        cout<<"|   *   |"<<endl;
			        gotoxy(16,18);
			        cout<<"|_______|"<<endl;
			break;
			}
		case 4:
			{
		             p1status(temp1);
	                 p2status(temp2);
		             board_info();
		             gotoxy(16,15);
			        cout<<" _______"<<endl;
			        gotoxy(16,16);
			        cout<<"|  * *  |"<<endl;
			        gotoxy(16,17);
			        cout<<"|  * *  |"<<endl;
			        gotoxy(16,18);
			        cout<<"|_______|"<<endl;
	        break;
			}
		case 5:
			{       
			         p1status(temp1);
	                 p2status(temp2);
		             board_info();
		             gotoxy(16,15);
			        cout<<" _______"<<endl;
			        gotoxy(16,16);
			        cout<<"| * * * |"<<endl;
			        gotoxy(16,17);
			        cout<<"|  * *  |"<<endl;
			        gotoxy(16,18);
			        cout<<"|_______|"<<endl;
			break;
			}
		case 6:
			{
				     p1status(temp1);
	                 p2status(temp2);
		             board_info();
		             gotoxy(16,15);
					cout<<" _______"<<endl;
					gotoxy(16,16);
			        cout<<"| * * * |"<<endl;
			        gotoxy(16,17);
			        cout<<"| * * * |"<<endl;
			        gotoxy(16,18);
			        cout<<"|_______|"<<endl;
				break;
			}
	}
	getch();
}
//////////////////////////////////////////////file handaling prev cont..////////////////////////////////////////	
void function::prevs()                                                   
{
	system("clour 0F");
	system("cls");
	gotoxy(0,1);
	ifstream f1;
	f1.open("snakeandl.txt");
	if(!f1)
	{
		cout<<"No record found";
		f1.close();
	}
	else{
		char j;
		while(!f1.eof())
		{
			j=f1.get();
			cout<<j;
		}
	}
	f1.close();
}
/*                                              MENU CLASS STARTS        */
class menu:public function{
	public:
		void menu1(){
			top:
                     system("cls");
                     system("color 17");
                     gotoxy(72,15);
                     cout<<"-:::::::::::::::::Menu::::::::::::::-"<<endl;
                     gotoxy(72,16);
                     cout<<":                                  :";
                     gotoxy(72,17);
                     cout<<":       (1) New game.              :";
                     gotoxy(72,18);
                     cout<<":                                  :";
                     gotoxy(72,19);
                     cout<<":       (2) Game rules.            :";
                     gotoxy(72,20);
                     cout<<":                                  :";
                     gotoxy(72,21);
                     cout<<":       (3) Previous statics.      :";
                     gotoxy(72,22);
                     cout<<":                                  :";
                     gotoxy(72,23);
                     cout<<":       (4) credits.               :";
                     gotoxy(72,24);
                     cout<<":                                  :";
                     gotoxy(72,25);
                     cout<<"::::::::::::::::::::::::::::::::::::";
                     cout<<endl<<endl<<"  press any other key for Exit"<<endl;
                     int icon;
                     gotoxy(72,29);
                     cin>>icon;
                     switch(icon){
                                case 1:{
                                    new_game();
                                    break;}
                                case 2:{
                                   rules();
                                   cout<<endl<<endl<<endl<<"Do you want to go back to the Menu press Y ";
                                   char m;
                                   m=getch();
                                   if(m=='Y' || m=='y'){
                                   	goto top;
								   }
								   else{
                                    break;}
                                }
                                case 4: {
                                	info();
                                   cout<<endl<<endl<<endl<<"Do you want to go back to the Menu press Y ";
                                   char m;
                                   m=getch();
                                   if(m=='Y' || m=='y'){
                                   	goto top;
								   }
								   else{
                                    break;}
								}
                        case 3: {
                                	prevs();
                                   cout<<endl<<endl<<endl<<"Do you want to go back to the Menu press Y ";
                                   char m;
                                   m=getch();
                                   if(m=='Y' || m=='y'){
                                   	goto top;
								   }
								   else{
                                    break;}
								}								
                                default:{
                                    exit(1);}
                     }


         }
		
};
/*                                             PUBLIC CLASS STARTS                                                                       */
class parent:public menu
{
	public:
		void fun(){
		}
       parent(){                     //default constructor called
                system("color f2");
                int x=135,y=20,icon;
                while(x>1){
                         gotoxy(x,y);
                         cout<<"~<:<<<<<>>>>Welcome to the game of snake and ladder";

               system("cls");
               x--;
            }


      }
         
};
/*                                                 MAIN STARTS           */
int main(){
parent p1;
p1.menu1();	
}
