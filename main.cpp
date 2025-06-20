
#include <iostream>
#include<ctime>
#include <cstdlib> 
using namespace std;
enum enChoice {paper=1,stone=2,scissors=3};
enum enWinner{play1=1,computer=2,Draw=3};
struct  stRaundInfo
{
	short roundNumber;
	enChoice player1;
	enChoice computer;
	enWinner Winner;
	string name_ofwinner;
};
struct stRoundResult {
	short GameRound=0;
	short NumberPlayer1Win=0;
	short NumberComputerWin=0;
	short Number_OfDraw = 0;
	enWinner Winner;
	string Name_ofWinner="";
};
int ReadRandNum(int from, int to) {
	int round = rand() % (to - from + 1) + from;
	return round;
}
enChoice ComputerChoice() {
	return (enChoice)ReadRandNum(1, 3);
}
enChoice PlayerChoice() {
	int x;
	do {
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
		cin >> x;

	} while (x < 1 || x > 3);
	return (enChoice)x;
}
enWinner howWinTheRound(stRaundInfo stround) {
	if (stround.player1 == stround.computer)
		return enWinner::Draw;
	switch (stround.player1)
	{
	case enChoice::paper:
		return(stround.computer == enChoice::scissors) ? enWinner::computer : enWinner::play1;

	case enChoice::scissors:
		return(stround.computer == enChoice::stone) ? enWinner::computer : enWinner::play1;
	case enChoice::stone:
		return(stround.computer == enChoice::paper) ? enWinner::computer : enWinner::play1;
	
	}
}
enWinner HowWinTheGame(short player, short computer) {
	if (player > computer)
		return enWinner::play1;
	else if (player < computer)
		return enWinner::computer;
	else
	{
		return enWinner::Draw;
	}
	
	
}
string ChoiseName(enChoice choice) {
	string arraychoiceName[3] = { "stone","papper","scissors" };
	return arraychoiceName[choice - 1];
}
string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
	return arrWinnerName[Winner - 1];
}
void PrintRoundResult(stRaundInfo ROund) {
	cout << "\n-----------------Round[" << ROund.roundNumber << "]------------------\n\n";
	cout << "Player 1 Choice " << ChoiseName(ROund.player1) << "\n";
	cout << "computer choice " << ChoiseName(ROund.computer) << "\n";
	cout << "Round Winner " <<WinnerName( ROund.Winner) << endl;
	cout << "-------------------------------------------------------------\n";
}
stRoundResult PlayGame(short howManyRound) {
	stRaundInfo stRound;
	short play1WinTImes = 0, computerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1;GameRound <= howManyRound;GameRound++) {
		cout << "Round [" << GameRound << "] begins:\n";
		stRound.roundNumber = GameRound;
		stRound.player1 = PlayerChoice();
		stRound.computer = ComputerChoice();
		stRound.Winner = howWinTheRound(stRound);
		stRound.name_ofwinner = WinnerName(stRound.Winner);
		if (stRound.Winner == enWinner::play1)
			play1WinTImes++;
		else if (stRound.Winner == enWinner::computer)
			computerWinTimes++;
		else
		{
			DrawTimes++;
		}
		PrintRoundResult(stRound);


	}
	return { howManyRound,play1WinTImes,computerWinTimes,DrawTimes,HowWinTheGame(play1WinTImes,computerWinTimes),WinnerName(HowWinTheGame(play1WinTImes,computerWinTimes)) };

}
void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		system("cls");  // Clear the screen before starting a new game.
		stRoundResult GameResults = PlayGame(3); // Play 3 rounds.
		cout << "\nGame Over! Winner: " << GameResults.Name_ofWinner << endl;

		cout << "\nDo you want to play again? (Y/N): ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
	srand((unsigned)time(NULL)); 
	StartGame();
}
