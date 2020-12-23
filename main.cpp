#include "Utility.h"
#include "GameException.h"
#include "GameEntity.h"
#include "Location.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
  try
    {
	  GameEntity kingdom1_soldier("Soldier", "Soldier");
	  GameEntity kingdom1_assassin("Assassin","Assassin");
	  GameEntity kingdom1_knight("Knight","Knight");
	  GameEntity kingdom2_soldier("Soldier", "Soldier");
	  GameEntity kingdom2_assassin("Assassin","Assassin");
	  GameEntity kingdom2_knight("Knight","Knight");
	  GameEntity kingdom3_soldier("Soldier", "Soldier");
	  GameEntity kingdom3_assassin("Assassin","Assassin");
	  GameEntity kingdom3_knight("Knight","Knight");
	  GameEntity kingdom4_soldier("Soldier", "Soldier");
	  GameEntity kingdom4_assassin("Assassin","Assassin");
	  GameEntity kingdom4_knight("Knight","Knight");
	  // Soldier beats Assassin; Assassin beats Knight; Knight beats Soldier
	  Location kingdom1("Kingdom1","Kingdom1");
	  Location kingdom2("Kingdom2","Kingdom2");
	  Location kingdom3("Kingdom3","Kingdom3");
	  Location kingdom4("Kingdom4","Kingdom4");

	  kingdom1.AddExit("east",&kingdom2);
	  kingdom1.AddExit("south",&kingdom4);

	  kingdom2.AddExit("west",&kingdom1);
	  kingdom2.AddExit("south",&kingdom3);

	  kingdom3.AddExit("west",&kingdom4);
	  kingdom3.AddExit("north",&kingdom2);

	  kingdom4.AddExit("north",&kingdom1);
	  kingdom4.AddExit("east",&kingdom3);

	  kingdom1.Add(&kingdom1_soldier);
	  kingdom1.Add(&kingdom1_assassin);
	  kingdom1.Add(&kingdom1_knight);

	  kingdom2.Add(&kingdom2_soldier);
	  kingdom2.Add(&kingdom2_assassin);
	  kingdom2.Add(&kingdom2_knight);

	  kingdom3.Add(&kingdom3_soldier);
	  kingdom3.Add(&kingdom3_assassin);
	  kingdom3.Add(&kingdom3_knight);

	  kingdom4.Add(&kingdom4_soldier);
	  kingdom4.Add(&kingdom4_assassin);
	  kingdom4.Add(&kingdom4_knight);

	  int kingdom=1;
	  int choice=-1;
	  int flag=1;
	  string troops="";
	  string troopChoice;
	  vector<int> aliveKingdoms;
	  aliveKingdoms.push_back(1);
	  aliveKingdoms.push_back(2);
	  aliveKingdoms.push_back(3);
	  aliveKingdoms.push_back(4);
	  while(flag==1){
		  if(kingdom==2){
			  troops="";
			  cout<<"Kingdom 2: Who do you attack?\n 1: Kingdom 1\n 2: Kingdom 3\n> ";
			  cin>>choice;
			  if(kingdom2.FindInContents("Soldier")!=NULL){troops+="1) Soldier\n ";}
			  if(kingdom2.FindInContents("Assassin")!=NULL){troops+="2) Assassin\n ";}
			  if(kingdom2.FindInContents("knight")!=NULL){troops+="3) Knight\n ";}
			  cout<<"Kingdom 2: Who do you attack with? ";
			  cin>>troopChoice;
			  if(kingdom2.FindInContents(troopChoice)==NULL){cout<<"Not a valid option; Skipping your turn for bad behavior\n";}
			  if(choice==1){
				  cout<<"Kingdom 1: Who do you defend with? ";
				  cin>>troops;
				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 2 won.\n";
				  		kingdom1.Remove(troops);
				  }
				  else if(Utility::whoWon(troopChoice,troops)=="D"){
				  	cout<<"Kingdom 1 won.\n";kingdom2.Remove(troopChoice);
				  }
				  else{
				  	cout<<"Tie!!\n";
				  }
			}
			  else if(choice==2){
				  cout<<"Kingdom 3: Who do you defend with? ";
				  cin>>troops;
				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 2 won.\n";
				  	kingdom3.Remove(troops);
				  }
				  else if(Utility::whoWon(troopChoice,troops)=="D"){
				  	cout<<"Kingdom 3 won.\n";kingdom2.Remove(troopChoice);
				  }
				  else{
				  	cout<<"Tie!!\n";
				  }
			  }
			  else{throw GameException("Invalid number");}
		  }
		  if(kingdom==1){
		  			  troops="";
		  			  cout<<"Kingdom 1: Who do you attack?\n 1: Kingdom 2\n 2: Kingdom 4\n> ";
		  			  cin>>choice;
		  			  if(kingdom1.FindInContents("Soldier")!=NULL){troops+="1) Soldier\n ";}
		  			  if(kingdom1.FindInContents("Assassin")!=NULL){troops+="2) Assassin\n ";}
		  			  if(kingdom1.FindInContents("knight")!=NULL){troops+="3) Knight\n ";}
		  			  cout<<"Kingdom 1: Who do you attack with? ";
		  			  cin>>troopChoice;
		  			  if(kingdom1.FindInContents(troopChoice)==NULL){cout<<"Not a valid option; Skipping your turn for bad behavior\n";}
		  			  if(choice==1){
		  				  cout<<"Kingdom 2: Who do you defend with? ";
		  				  cin>>troops;
		  				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 1 won.\n";
		  				  		kingdom2.Remove(troops);
		  				  }
		  				  else if(Utility::whoWon(troopChoice,troops)=="D"){
		  				  	cout<<"Kingdom 2 won.\n";kingdom1.Remove(troopChoice);
		  				  }
		  				  else{
		  				  	cout<<"Tie!!\n";
		  				  }
		  			}
		  			  else if(choice==2){
		  				  cout<<"Kingdom 4: Who do you defend with? ";
		  				  cin>>troops;
		  				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 1 won.\n";
		  				  	kingdom4.Remove(troops);
		  				  }
		  				  else if(Utility::whoWon(troopChoice,troops)=="D"){
		  				  	cout<<"Kingdom 4 won.\n";kingdom1.Remove(troopChoice);
		  				  }
		  				  else{
		  				  	cout<<"Tie!!\n";
		  				  }
		  			  }
		  			  else{throw GameException("Invalid number");}
		  		  }
		  if(kingdom==3){
		  			  troops="";
		  			  cout<<"Kingdom 3: Who do you attack?\n 1: Kingdom 2\n 2: Kingdom 4\n> ";
		  			  cin>>choice;
		  			  if(kingdom3.FindInContents("Soldier")!=NULL){troops+="1) Soldier\n ";}
		  			  if(kingdom3.FindInContents("Assassin")!=NULL){troops+="2) Assassin\n ";}
		  			  if(kingdom3.FindInContents("knight")!=NULL){troops+="3) Knight\n ";}
		  			  cout<<"Kingdom 3: Who do you attack with? ";
		  			  cin>>troopChoice;
		  			  if(kingdom1.FindInContents(troopChoice)==NULL){cout<<"Not a valid option; Skipping your turn for bad behavior\n";}
		  			  if(choice==1){
		  				  cout<<"Kingdom 2: Who do you defend with? ";
		  				  cin>>troops;
		  				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 3 won.\n";
		  				  		kingdom2.Remove(troops);
		  				  }
		  				  else if(Utility::whoWon(troopChoice,troops)=="D"){
		  				  	cout<<"Kingdom 2 won.\n";kingdom3.Remove(troopChoice);
		  				  }
		  				  else{
		  				  	cout<<"Tie!!\n";
		  				  }
		  			}
		  			  else if(choice==2){
		  				  cout<<"Kingdom 4: Who do you defend with? ";
		  				  cin>>troops;
		  				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 3 won.\n";
		  				  	kingdom4.Remove(troops);
		  				  }
		  				  else if(Utility::whoWon(troopChoice,troops)=="D"){
		  				  	cout<<"Kingdom 4 won.\n";kingdom3.Remove(troopChoice);
		  				  }
		  				  else{
		  				  	cout<<"Tie!!\n";
		  				  }
		  			  }
		  			else{throw GameException("Invalid number");}
		  		  }
		  if(kingdom==4){
			  troops="";
			  cout<<"Kingdom 4: Who do you attack?\n 1: Kingdom 1\n 2: Kingdom 3\n> ";
			  cin>>choice;
			  if(kingdom4.FindInContents("Soldier")!=NULL){troops+="1) Soldier\n ";}
			  if(kingdom4.FindInContents("Assassin")!=NULL){troops+="2) Assassin\n ";}
			  if(kingdom4.FindInContents("knight")!=NULL){troops+="3) Knight\n ";}
			  cout<<"Kingdom 4: Who do you attack with? ";
			  cin>>troopChoice;
			  if(kingdom4.FindInContents(troopChoice)==NULL){cout<<"Not a valid option; Skipping your turn for bad behavior\n";}
			  if(choice==1){
				  cout<<"Kingdom 1: Who do you defend with? ";
				  cin>>troops;
				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 4 won.\n";
				  		kingdom1.Remove(troops);
				  }
				  else if(Utility::whoWon(troopChoice,troops)=="D"){
				  	cout<<"Kingdom 1 won.\n";kingdom4.Remove(troopChoice);
				  }
				  else{
				  	cout<<"Tie!!\n";
				  }
			}
			  else if(choice==2){
				  cout<<"Kingdom 3: Who do you defend with? ";
				  cin>>troops;
				  if(Utility::whoWon(troopChoice,troops)=="A"){cout<<"Kingdom 4 won.\n";
				  	kingdom3.Remove(troops);
				  }
				  else if(Utility::whoWon(troopChoice,troops)=="D"){
				  	cout<<"Kingdom 3 won.\n";kingdom4.Remove(troopChoice);
				  }
				  else{
				  	cout<<"Tie!!\n";
				  }
			  }
			  else{throw GameException("Invalid number");}
		  }
		  if(kingdom1.contents.size()==0){
			  aliveKingdoms.erase(aliveKingdoms.begin());
		  }
		  if(kingdom2.contents.size()==0){
		  			  aliveKingdoms.erase(aliveKingdoms.begin()+1);
		  }
		  if(kingdom3.contents.size()==0){
		  			  aliveKingdoms.erase(aliveKingdoms.begin()+2);
		  }
		  if(kingdom4.contents.size()==0){
		  			  aliveKingdoms.erase(aliveKingdoms.begin()+3);
		  }
		  if(aliveKingdoms.size()==1){
			  cout<<"Kingdom "<<aliveKingdoms[0]<<" won the game!";
			  exit(0);
		  }
		  kingdom++;
		  int flag=0;

		  while(flag==0){
			  for(int i=0;i<aliveKingdoms.size();i++){
			  			  if(kingdom==aliveKingdoms[i]){
			  				  flag=1;
			  			  }
			  }
			  kingdom++;
			  if(kingdom==5){kingdom=1;}
		  }
	  }
    }
  catch (GameException & e)
    {
      cout << "*** Internal Error: " << e.GetMessage() << endl;
    }

}
