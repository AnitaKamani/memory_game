#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>
using namespace std;
void home();
void menuu();
void new_game();
void player();
void nname();
void funny_counter();
void cpu_level();
void single_player();
void multiplayer();
void c_out();
void wait(float sec, bool t);
void sshow_hint(int hint_counter);
void space(bool space);
void finish();
void record();
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
int nn, ii11 = -1, jj11 = -2, ii21 = -3, jj21 = -4, ii12 = -5, jj12 = -6, ii22 = -7, jj22 = -8;
int words_test[50];
int turn = 1, turn_counter1 = 0, turn_counter2 = 0, hint_counter1 = 0, hint_counter2 = 0, wrong_counter1 = 0, wrong_counter2 = 0;
/////pc
bool pc = 0;
int pc_uses_hint = 0;
int memory[10][10], memory_coordinates[2][100];
int cpu = 0, hint_memory = 0;
int intelligence = 2; ////&//&//&// an intiger coefficient for the level of computer intelligence, can be toggled between 1 to 10, I would suggest 2 as default
////
string n[10][10], name_1 = "0000", name_2 = "0000", wwordss[50];
string words[360] = {" 0 ", " 1 ", "1.1", " 2 ", "2.2", " 3 ", "3.3", " 4 ", "4.4", " 5 ", "5.5", " 6 ", "6.6", " 7 ", "7.7", " 8 ", "8.8", " 9 ", "9.9", "100", "101", "111", "200", "202", "222", "300", "303", "333", "400", "404", "444", "500", "505", "555", "600", "606", "666", "700", "707", "777", "800", "808", "888", "900", "909", "999", " ! ", " $ ", " % ", " & ", " ? ", " @ ", " ^ ", " + ", " = ", " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H ", " I ", " J ", " K ", " L ", " M ", " N ", " O ", " P ", " Q ", " R ", " S ", " T ", " U ", " V ", " W ", " X ", " Y ", " Z ", "!-!", "$%$", "$O$", "&*&", ":*:", ":^|", ":_(", ":+)", ":3)", ":-P", ";-#", ";-)", "?-?", "???", "@*@", "@=@", "\"@\"", "\"_\"", "=.=", "^&^", "^*^", "^8^", "0I0", "8-)", "8^|", "ABS", "ACE", "ACT", "ADD", "ADS", "AGE", "AID", "AIR", "ALL", "ALP", "ALT", "ANA", "AND", "ANT", "ANY", "APP", "ARC", "ARE", "ARM", "ART", "ASA", "ASH", "ASK", "BAD", "BAG", "BAN", "BAR", "BAT", "BED", "BEE", "BEG", "BEN", "BET", "BIG", "BIN", "BIT", "BMW", "BOT", "BOW", "BOX", "BOY", "BRO", "BUG", "BUS", "BUT", "BUY", "BYE", "CAB", "CAM", "CAN", "CAP", "CAR", "CAT", "COP", "CRY", "CUP", "CUT", "DAD", "DAY", "DEF", "DID", "DIE", "DIS", "DOC", "DOT", "E10", "E11", "E20", "E22", "E30", "E33", "E40", "E44", "E50", "E55", "E60", "E66", "E70", "E77", "E80", "E88", "E90", "E99", "EGO", "ELF", "END", "EYE", "FAN", "FAR", "FAT", "FAX", "FED", "FEW", "FIG", "FIN", "FIT", "FIX", "FLU", "FLY", "FOG", "FOR", "FOX", "FRY", "GAS", "GET", "GIT", "GOO", "GOT", "GUM", "GUN", "GUT", "GUY", "GYM", "HAD", "HAS", "HAT", "HEN", "HER", "HEX", "HIM", "HIS", "HIT", "HOT", "HOW", "ICE", "ICH", "INK", "JAM", "JAR", "JET", "JOB", "JOE", "JOY", "KEY", "KID", "KIT", "LAB", "LAC", "LAD", "LAY", "LEE", "LEG", "LET", "LEY", "LIB", "LID", "LOG", "LOL", "LOW", "MAC", "MAD", "MAG", "MAN", "MAP", "MAT", "MAX", "MEG", "MID", "MIX", "MOM", "MUG", "NAP", "NET", "NEW", "NOD", "NOR", "NOT", "NOW", "O8O", "ODD", "OFF", "OIL", "OLD", "O-o", "OUT", "OWN", "OXO", "PAL", "PAN", "PAY", "PEN", "PER", "PET", "PHI", "PIE", "PIG", "PIN", "PIP", "PIT", "PRO", "PUT", "Q*Q", "RAD", "RAM", "RAP", "RAT", "RED", "RIB", "RIP", "ROW", "RUN", "SAD", "SAT", "SAY", "SEE", "SET", "SHE", "SHY", "SIN", "SIT", "SKI", "SKY", "SON", "SOS", "SUM", "SUN", "TAB", "TAG", "TAP", "TED", "THE", "TIE", "TIP", "TOE", "TOO", "TOP", "TOT", "TOY", "TRY", "UIU", "USE", "VAN", "WAR", "WAS", "WAY", "WEB", "WHO", "WHY", "WIN", "WIZ", "WON", "WOW", "YEP", "YES", "YET", "YOU", "YOY", "YUM", "YUP", "ZAP", "ZED", "ZIP", "ZOO", "Zzz"};
bool show_hint = 0, card_flag = 0, ans[10][10];
bool pccc_uses_hint = 1;
float score1 = 0, score2 = 0;
fstream output_file("records.txt", ios::out);
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
int main()
{
	system("mode 171");
	system("color 07");
	home();
	cout << "\n\nDelay time";
	int Delay;
	cin >> Delay;
	return 0;
}
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
//////////////////////////////////////////////////////////////////first screen including new game/records..
void home()
{
	system("CLS");
	cout << "\n   WELCOME TO THE MATCHING GAME \n\n";
	string choice;
	cout << "    N = New game\n    R = Records\n    E = Exit\n \n ";
	cout << "   Enter your choice : ";
	for (bool flag_choice = 0; flag_choice == 0;)
	{
		cin >> choice;
		if (choice == "n" || choice == "N")
		{
			flag_choice = 1;
			srand(time(0));

			system("CLS");
			for (int i = 0; i < 18; i++)
			{
				if (i % 2)
					system("color 07");
				else
					system("color 0E");
				system("CLS");
				wait(.01, 0);
				cout << "\n   !IMPORTANT!  Please note that you can ALLWAYS and ANYWHERE use 0 to see the menu";
				wait(.1, 0);
			}
			cout << "\n\n   ";
			system("pause");
			new_game();
		}
		else if (choice == "r" || choice == "R")
		{
			record();
			home();
		}
		else if (choice == "0")
		{
			menuu();
			home();
		}
		else if (choice == "e" || choice == "E")
			exit(0);
		else
		{
			cout << "\n    !ERROR! Did\'nt recognize that please enter your choice again : ";
		}
	}
}
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
//////////////////////////////////////////////////////////////////the menu that is everywhere when you need it :)
void menuu()
{
	system("CLS");
	string menu;
	cout << "\n   MENU\n\n    H = Home\n    R = Records\n    E = Exit\n\n    or any other chracter to return : ";
	cin >> menu;
	if (menu == "h" || menu == "H")
		home();
	else if (menu == "r" || menu == "R")
	{
		cout << "\n   HERE ARE THE SCORES";
		record();
		menuu();
	}
	else if (menu == "e" || menu == "E")
		exit(0);
}
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
//////////////////////////////////////////////////////////////////most of the work of resetting data and generating new game is considered here
void new_game()
{
	system("CLS");
	system("color 07");
	cout << "\n   Please enter an even number as the dimensions : ";
	for (bool flag_even = 0; flag_even == 0;)
	{
		cin >> nn;
		if (!cin)
		{ //////////////////////////////////////////////////////in case of entering a non-numeric input
			cout << "\n   !ERROR! You did not enter an integer, try again : ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (nn > 0 && nn <= 10)
			{
				if (nn % 2 == 0)
					flag_even = 1;
				else
					cout << "\n   !ERROR! Please enter an EVEN NUMBER not an odd one : ";
			}
			else if (nn < 0)
				cout << "\n   !ERROR! Please enter a positive number : ";
			else if (nn > 10)
			{
				cout << "\n   !ERROR! Please enter the maximum number of 10 : ";
			}
			else if (nn == 0)
			{
				menuu();
				new_game();
			}
		}
	}
	//////////////////////////////////////////////////////
	//////////////////////////////////////////////////////000000000000000000000000000000000setting to 000000000000000000000
	ii11 = -1;
	jj11 = -2;
	ii21 = -3;
	jj21 = -4;
	ii12 = -5;
	jj12 = -6;
	ii22 = -7;
	jj22 = -8;
	turn = 1;
	name_1 = "0000";
	name_2 = "0000";
	show_hint = 0;
	turn_counter1 = 0;
	turn_counter2 = 0;
	wrong_counter1 = 0;
	wrong_counter2 = 0;
	score1 = 0;
	score2 = 0;
	card_flag = 0;
	pc = 0;
	cpu = 0;
	pc_uses_hint = 0;
	pccc_uses_hint = 1;
	hint_memory = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			ans[i][j] = 0;
			n[i][j] = "0000";
			memory[i][j] = 0;
			memory_coordinates[0][i * 10 + j] = 0;
			memory_coordinates[1][i * 10 + j] = 0;
		}
	for (int i = 0; i < 50; i++)
	{
		words_test[i] = 0;
		wwordss[i] = "0";
	}
	//////////////////////////////////////////////////////
	//////////////////////////////////////////////////////generating random numbers for selecting words from word_list later
	for (int i = 0; i < (nn * nn / 2);)
	{
		bool unique_test = 1;
		int tmp = rand() % 360;
		for (int j = 0; j < i; j++)
			if (wwordss[j] == words[tmp])
			{
				unique_test = 0;
			}
		if (unique_test == 1)
		{
			wwordss[i] = words[tmp];
			i++;
		}
	}
	//////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	//////////////////////////////////////////////////////making our main table of cards
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < nn;)
		{
			int tmp = rand() % (nn * nn / 2);
			if (words_test[tmp] < 2)
			{
				n[i][j] = wwordss[tmp];
				words_test[tmp]++;
				j++;
			}
		}
	}
	///////////////////////////////////////////choosing to play with pc or friend
	player();
}
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
//////////////////////////////////////////////////////////////////here we type the players' names
void player()
{
	system("CLS");
	cout << "\n   OK now chose how you wanna play \n\n";
	string choice;
	cout << "    M = Multiplayer mode \n    C = Computer mode\n\n";
	cout << "    Enter your choice : ";
	for (bool flag_choice = 0; flag_choice == 0;)
	{
		cin >> choice;
		if (choice == "m" || choice == "M")
		{
			nname();
			funny_counter();
			multiplayer();
		}
		else if (choice == "c" || choice == "C")
		{
			pc = 1;
			nname();
			pccc_uses_hint = 1;
			cpu_level();
			funny_counter();
			single_player();
		}
		else if (choice == "0")
		{
			menuu();
			player();
		}
		else
		{
			cout << "\n    !ERROR! Did\'nt recognize that please enter your choice again : ";
		}
	}
}
void nname()
{
	system("CLS");
	cout << "\n    You chose to play a " << nn << "*" << nn << " game\n";
	bool uniquee = 0;
	while (uniquee == 0)
	{
		cout << "\n    Please type first player name : ";
		cin >> name_1;
		if (name_1 == "0")
		{
			menuu();
			nname();
		}
		else if (pc)
			uniquee = 1;
		else
		{
			cout << "\n    Please type second Player name : ";
			cin >> name_2;
			if (name_2 == "0")
			{
				menuu();
				nname();
			}
			else if (name_1 == name_2)
				cout << "\n   !ERROR! Please enter unique names for each player\n";
			else
				uniquee = 1;
		}
	}
}
void funny_counter()
{
	system("CLS");
	system("color 09");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "                                                                               ______________ " << endl;
	cout << "                                                                              |              |" << endl;
	cout << "                                                                              |_________     |" << endl;
	cout << "                                                                                        |    |" << endl;
	cout << "                                                                               _________|    |" << endl;
	cout << "                                                                              |              |" << endl;
	cout << "                                                                              |_________     |" << endl;
	cout << "                                                                                        |    |" << endl;
	cout << "                                                                               _________|    |" << endl;
	cout << "                                                                              |              |" << endl;
	cout << "                                                                              |______________|" << endl;
	wait(0.6, 0);
	system("CLS");
	system("color 0B");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "                                                                               ______________ " << endl;
	cout << "                                                                              |              |" << endl;
	cout << "                                                                              |_________     |" << endl;
	cout << "                                                                                        |    |" << endl;
	cout << "                                                                               _________|    |" << endl;
	cout << "                                                                              |              |" << endl;
	cout << "                                                                              |     _________|" << endl;
	cout << "                                                                              |    |          " << endl;
	cout << "                                                                              |    |_________ " << endl;
	cout << "                                                                              |              |" << endl;
	cout << "                                                                              |______________|" << endl;
	wait(0.8, 0);
	system("CLS");
	system("color 0D");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "                                                                                    ____ " << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |    |" << endl;
	cout << "                                                                                   |____|" << endl;
	wait(1, 0);
	system("CLS");
	system("color 0E");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "                                                               _______________                           ____ " << endl;
	cout << "                                                              |               |                         |    |" << endl;
	cout << "                                                              |     __________|                         |    |" << endl;
	cout << "                                                              |    |                ______________      |    |" << endl;
	cout << "                                                              |    |   _______     |              |     |    |" << endl;
	cout << "                                                              |    |  |       |    |    ______    |     |    |" << endl;
	cout << "                                                              |    |  |__     |    |   |      |   |     |    |" << endl;
	cout << "                                                              |    |     |    |    |   |      |   |     |____|" << endl;
	cout << "                                                              |    |_____|    |    |   |______|   |      ____ " << endl;
	cout << "                                                              |               |    |              |     |    |" << endl;
	cout << "                                                              |_______________|    |______________|     |____|" << endl;
	for (int i = 0; i < 5; i++)
	{
		wait(0.2, 0);
		system("color 0F");
		wait(0.2, 0);
		system("color 0E");
	}
	system("color 07");
	show_hint = 1;
	system("CLS");
	c_out();
	cout << "\n\n";
	wait(nn, 1);
}
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
//////////////////////////////////////////////////////////////////the game board
void c_out()
{

	for (int k = (10 - nn + 2) / 2; k > 0; k--)
		cout << "\n";
	space(0);
	cout << "         ";
	for (int k = 1; k <= nn; k++)
		if (k != 10)
			cout << "   " << k << "   ";
		else
			cout << "  10   ";

	cout << "\n         ";
	space(0);
	for (int k = 0; k < nn; k++)
		cout << "  ___  ";
	cout << "\n\n";

	for (int ii = 0; ii < nn; ii++)
	{
		space(0);
		cout << "         ";
		for (int jj = 0; jj < nn; jj++)
			if (((ii11 == ii && jj11 == jj || ii21 == ii && jj21 == jj || ii12 == ii && jj12 == jj || ii22 == ii && jj22 == jj) && card_flag == 1) || show_hint == 1)
				cout << "       ";
			else
				cout << " +---+ ";
		cout << endl;
		space(0);
		if (ii == 9)
			cout << "  10 |   ";
		else
			cout << "  " << ii + 1 << "  |   ";
		for (int jj = 0; jj < nn; jj++)
			if (show_hint == 1 && ans[ii][jj] == 1)
				cout << "  "
					 << "   "
					 << "  ";
			else if (((ii11 == ii && jj11 == jj || ii21 == ii && jj21 == jj || ii12 == ii && jj12 == jj || ii22 == ii && jj22 == jj) && card_flag == 1) || show_hint == 1 || ans[ii][jj] == 1)
				cout << "  " << n[ii][jj] << "  ";
			else
				cout << " | # | ";
		cout << endl;
		cout << "         ";
		space(0);
		for (int jj = 0; jj < nn; jj++)
			if (((ii11 == ii && jj11 == jj || ii21 == ii && jj21 == jj || ii12 == ii && jj12 == jj || ii22 == ii && jj22 == jj) && card_flag == 1) || show_hint == 1)
				cout << "       ";
			else
				cout << " +---+ ";
		cout << endl;
	}
}
//////////////////////////////////////////////////////////////////
//*********************************************************************************************************************************************************************************************************************************************************************
//////////////////////////////////////////////////////////////////we are going to actually play our game here
void multiplayer()
{
	show_hint = 0;
	card_flag = 0;
	system("CLS");
	c_out();
	cout << endl;
	space(1);
	cout << " Please enter your card or any key for a 2 sec hint :\n";
	if (turn == 1)
	{
		ii21 = -3;
		jj21 = -4;
		ii22 = -7;
		jj22 = -8;
		space(1);
		cout << " It's " << name_1 << "'s turn : ";
		bool unique_card = 0;
		while (unique_card == 0)
		{
			cin >> ii11;
			if (!cin)
				sshow_hint(1);
			else if (ii11 == 0)
			{
				menuu();
				multiplayer();
			}
			cin >> jj11;
			if (!cin)
			{
				sshow_hint(1);
				multiplayer();
			}
			else if (jj11 == 0)
			{
				menuu();
				multiplayer();
			}
			cin >> ii12;
			if (!cin)
			{
				sshow_hint(1);
				multiplayer();
			}
			else if (ii12 == 0)
			{
				menuu();
				multiplayer();
			}
			cin >> jj12;
			if (!cin)
			{
				sshow_hint(1);
				multiplayer();
			}
			else if (jj12 == 0)
			{
				menuu();
				multiplayer();
			}
			if (ii11 == ii12 && jj11 == jj12)
			{
				space(1);
				cout << "   !ERROR! Please enter 2 sepreate cards : ";
			}
			else if ((ii11 > nn || ii11 < 1) || (jj11 > nn || jj11 < 1) || (ii12 > nn || ii12 < 1) || (jj12 > nn || jj12 < 1))
			{
				space(1);
				cout << "   !ERROR! Please enter your card number between 1 and " << nn << " : ";
			}
			else if (ans[ii11 - 1][jj11 - 1] || ans[ii12 - 1][jj12 - 1])
			{
				space(1);
				cout << "   !ERROR! This card has been revealed before please take another : ";
			}
			else
				unique_card = 1;
		}
		turn = 2;
		ii11--;
		jj11--;
		ii12--;
		jj12--;
		if (n[ii11][jj11] == n[ii12][jj12])
		{
			ans[ii11][jj11] = 1;
			ans[ii12][jj12] = 1;
		}
		card_flag = 1;
		system("CLS");
		c_out();
		cout << "\n\n";
		if (n[ii11][jj11] == n[ii12][jj12])
		{
			space(1);
			cout << "!BRAVO!";
		}
		else
			wrong_counter1++;
		wait(2, 0);
		turn_counter1++;
		if ((turn_counter1 == (nn * nn) / 2) && (turn_counter2 == (nn * nn) / 2))
			finish();
	}
	else if (turn == 2)
	{
		ii11 = -3;
		jj11 = -4;
		ii12 = -7;
		jj12 = -8;
		space(1);
		cout << " It's " << name_2 << "'s turn : ";
		bool unique_card = 0;
		while (unique_card == 0)
		{
			cin >> ii21;
			if (!cin)
				sshow_hint(2);
			else if (ii21 == 0)
			{
				menuu();
				multiplayer();
			}
			cin >> jj21;
			if (!cin)
			{
				sshow_hint(2);
				multiplayer();
			}
			else if (jj21 == 0)
			{
				menuu();
				multiplayer();
			}
			cin >> ii22;
			if (!cin)
			{
				sshow_hint(2);
				multiplayer();
			}
			else if (ii21 == 0)
			{
				menuu();
				multiplayer();
			}
			cin >> jj22;
			if (!cin)
			{
				sshow_hint(2);
				multiplayer();
			}
			else if (ii21 == 0)
			{
				menuu();
				multiplayer();
			}
			if (ii21 == ii22 && jj21 == jj22)
			{
				space(1);
				cout << "   !ERROR! Please enter 2 sepreate cards : ";
			}
			else if ((ii21 > nn || ii21 < 1) || (jj21 > nn || jj21 < 1) || (ii22 > nn || ii22 < 1) || (jj22 > nn || jj22 < 1))
			{
				space(1);
				cout << "   !ERROR! Please enter your card number between 1 and " << nn << " : ";
			}
			else if (ans[ii21 - 1][jj21 - 1] || ans[ii22 - 1][jj22 - 1])
			{
				space(1);
				cout << "   !ERROR! This card has been revealed before please take another : ";
			}
			else
				unique_card = 1;
		}
		turn = 1;
		ii21--;
		jj21--;
		ii22--;
		jj22--;
		if (n[ii21][jj21] == n[ii22][jj22])
		{
			ans[ii21][jj21] = 1;
			ans[ii22][jj22] = 1;
		}
		card_flag = 1;
		system("CLS");
		c_out();
		cout << "\n\n";
		if (n[ii21][jj21] == n[ii22][jj22])
		{
			space(1);
			cout << "!BRAVO!";
		}
		else
			wrong_counter2++;
		wait(2, 0);
		turn_counter2++;
		if ((turn_counter2 == (nn * nn) / 2) && (turn_counter1 == (nn * nn) / 2))
			finish();
	}
	////////////////////////////////////
	int suum = 0;
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			if (ans[i][j])
				suum++;
	if (suum == nn * nn)
		finish();
	////////////////////////////////////
	multiplayer();
}
void cpu_level()
{
	system("CLS");
	cout << "\n   Please enter a number between 1 and " << nn << " as the level of cpu: ";
	for (bool flag = 0; flag == 0;)
	{
		cin >> cpu;
		if (!cin)
		{ //////////////////////////////////////////////////////in case of entering a non-numeric input
			cout << "\n   !ERROR! You did not enter an integer, try again : ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (cpu > 0 && cpu <= nn)
			{							  /////////////intelligence
				cpu = cpu * intelligence; ///////////////////////

				flag = 1;
			}
			else if (cpu < 0)
				cout << "\n   !ERROR! Please enter a positive number : ";
			else if (cpu > nn)
			{
				cout << "\n   !ERROR! Please enter the maximum number of " << nn << " : ";
			}
			else if (cpu == 0)
			{
				menuu();
				cpu_level();
			}
		}
	}
}
void single_player()
{
	show_hint = 0;
	card_flag = 0;
	system("CLS");
	c_out();
	cout << endl;
	space(1);
	cout << " Please enter your card or any key for a 2 sec hint :\n";
	if (turn == 1)
	{
		ii21 = -3;
		jj21 = -4;
		ii22 = -7;
		jj22 = -8;
		space(1);
		cout << " It's " << name_1 << "'s turn : ";
		bool unique_card = 0;
		while (unique_card == 0)
		{
			cin >> ii11;
			if (!cin)
				sshow_hint(1);
			else if (ii11 == 0)
			{
				menuu();
				single_player();
			}
			cin >> jj11;
			if (!cin)
			{
				sshow_hint(1);
				single_player();
			}
			else if (jj11 == 0)
			{
				menuu();
				single_player();
			}
			cin >> ii12;
			if (!cin)
			{
				sshow_hint(1);
				single_player();
			}
			else if (ii12 == 0)
			{
				menuu();
				single_player();
			}
			cin >> jj12;
			if (!cin)
			{
				sshow_hint(1);
				//////////////////
				pccc_uses_hint = 1;
				hint_memory = int(pow(cpu, 0.6));
				///////////////////
				single_player();
			}
			else if (jj12 == 0)
			{
				menuu();
				single_player();
			}
			if (ii11 == ii12 && jj11 == jj12)
			{
				space(1);
				cout << "   !ERROR! Please enter 2 sepreate cards : ";
			}
			else if ((ii11 > nn || ii11 < 1) || (jj11 > nn || jj11 < 1) || (ii12 > nn || ii12 < 1) || (jj12 > nn || jj12 < 1))
			{
				space(1);
				cout << "   !ERROR! Please enter your card number between 1 and " << nn << " : ";
			}
			else if (ans[ii11 - 1][jj11 - 1] || ans[ii12 - 1][jj12 - 1])
			{
				space(1);
				cout << "   !ERROR! This card has been revealed before please take another : ";
			}
			else
				unique_card = 1;
		}
		turn = 2;
		ii11--;
		jj11--;
		ii12--;
		jj12--;
		if (n[ii11][jj11] == n[ii12][jj12])
		{
			ans[ii11][jj11] = 1;
			ans[ii12][jj12] = 1;
			memory[ii11][jj11] = 2;
			memory[ii12][jj12] = 2;
		}
		////////////////checking if pc have one of the cards or not
		for (int z = 0; z < 2; z++)
			for (int i = 0; i < cpu; i++)
			{
				if ((memory_coordinates[0][i]) && (memory_coordinates[1][i]))
				{
					if (n[(memory_coordinates[0][i]) - 1][(memory_coordinates[1][i]) - 1] == n[ii11][jj11] || n[(memory_coordinates[0][i]) - 1][(memory_coordinates[1][i]) - 1] == n[ii12][jj12])
					{

						/////////////////////////////shifting the pc old memory  1 right
						for (int j = 0; j < i; j++)
						{
							memory_coordinates[0][i - j] = memory_coordinates[0][i - j - 1];
							memory_coordinates[1][i - j] = memory_coordinates[1][i - j - 1];
						}
						memory_coordinates[0][0] = 0;
						memory_coordinates[1][0] = 0;
					}
				}
			}

		////////////if it does not have it we will give it;
		/////////////////////////////shifting the pc old memory left 2 times
		if (n[ii11][jj11] != n[ii12][jj12])
		{
			for (int i = 0; i < cpu - 2; i++)
			{
				memory_coordinates[0][i] = memory_coordinates[0][i + 2];
				memory_coordinates[1][i] = memory_coordinates[1][i + 2];
			}
			memory_coordinates[0][cpu - 2] = ii11 + 1;
			memory_coordinates[1][cpu - 2] = jj11 + 1;
			memory_coordinates[0][cpu - 1] = ii12 + 1;
			memory_coordinates[1][cpu - 1] = jj12 + 1;
		}

		card_flag = 1;
		system("CLS");
		c_out();
		cout << "\n\n";
		if (n[ii11][jj11] == n[ii12][jj12])
		{
			space(1);
			cout << "!BRAVO!";
		}
		else
			wrong_counter1++;
		wait(2, 0);
		turn_counter1++;
		if ((turn_counter1 == (nn * nn) / 2) && (turn_counter2 == (nn * nn) / 2))
			finish();
	}
	////////////////////////////////////////////pc's turn
	else if (turn == 2)
	{

		space(1);
		cout << " It's PC's turn : ";
		wait(1, 0);
		srand(time(0));
		// pc using hint
		if (hint_counter2 != cpu && !pccc_uses_hint)
		{
			// srand(time(0));
			if (!(rand() % (12 - (cpu / intelligence))))
				pccc_uses_hint = 1;
			if (pccc_uses_hint)
			{
				hint_memory = int(pow(cpu, 0.7));
				sshow_hint(3);
			}
		}

		ii11 = -3;
		jj11 = -4;
		ii12 = -7;
		jj12 = -8;
		cout << " tmp0 ";
		if (!pccc_uses_hint)
		{
			cout << " tmp1 ";
			bool unq_pc_card = 0;
			while (unq_pc_card == 0)
			{
				cout << " tmp 2";
				// srand(time(0));
				ii21 = rand() % nn;
				// srand(time(0));
				jj21 = rand() % nn;
				if (memory[ii21][ii21] == 0)
					unq_pc_card = 1;
			}
			cout << " tmp3 ";
			bool match_in_memory = 0;

			for (int i = 0; i < cpu; i++)
			{
				if ((memory_coordinates[0][i]) && (memory_coordinates[1][i]))
				{
					if (n[(memory_coordinates[0][i]) - 1][(memory_coordinates[1][i]) - 1] == n[ii21][jj21])
					{
						match_in_memory = 1;
						ii22 = (memory_coordinates[0][i]) - 1;
						jj22 = (memory_coordinates[1][i]) - 1;

						/////////////////////////////shifting the pc old memory  1 right
						for (int j = 0; j < i; j++)
						{
							memory_coordinates[0][i - j] = memory_coordinates[0][i - j - 1];
							memory_coordinates[1][i - j] = memory_coordinates[1][i - j - 1];
						}
						memory_coordinates[0][0] = 0;
						memory_coordinates[1][0] = 0;
					}
				}
			}
			if (!match_in_memory)
			{
				bool unq_pc_card2 = 0;
				while (unq_pc_card2 == 0)
				{
					srand(time(0));
					ii22 = rand() % nn;
					srand(time(0));
					jj22 = rand() % nn;
					if (memory[ii22][jj22] == 0 && !(ii21 == ii22 && ii21 == jj22))
						unq_pc_card2 = 1;
				}
				/////////////////////////////shifting the pc old memory left 2 times
				if (n[ii21][jj21] != n[ii22][jj22])
				{
					wrong_counter2++;
					for (int i = 0; i < cpu - 2; i++)
					{
						memory_coordinates[0][i] = memory_coordinates[0][i + 2];
						memory_coordinates[1][i] = memory_coordinates[1][i + 2];
					}
					memory_coordinates[0][cpu - 2] = ii21 + 1;
					memory_coordinates[1][cpu - 2] = jj21 + 1;
					memory_coordinates[0][cpu - 1] = ii22 + 1;
					memory_coordinates[1][cpu - 1] = jj22 + 1;
				}
			}
		}
		else if (pccc_uses_hint)
		{
			cout << " tmp4 ";
			hint_memory--;
			bool unq_pc_card = 0;
			while (unq_pc_card == 0)
			{
				cout << " tmp5 ";
				ii21 = rand() % nn;
				// srand(time(0));
				jj21 = rand() % nn;
				cout << memory[ii21][jj21];
				if (memory[ii22][jj22] == -1)
				{
					cout << " tmp6 ";
					unq_pc_card = 1;
					////////we need to make sure our card is new to memory
					for (int i = 0; i < cpu; i++)
						if (memory_coordinates[0][i] == (ii21 + 1) && memory_coordinates[1][i] == (jj21 + 1))
							unq_pc_card = 0;
				}
			}
			unq_pc_card = 0;
			cout << " tmp7 ";
			while (unq_pc_card == 0)
			{
				cout << " tmp8 ";
				// srand(time(0));
				ii22 = rand() % nn;
				// srand(time(0));
				jj22 = rand() % nn;
				cout << ii21 << jj21;
				cout << ii22 << jj22;
				if (ii21 != ii22 && jj21 != jj22)
					unq_pc_card = 1;
			}
		}
		turn = 1;
		if (n[ii21][jj21] == n[ii22][jj22])
		{
			cout << ii21 << jj21;
			cout << ii22 << jj22;
			ans[ii21][jj21] = 1;
			ans[ii22][jj22] = 1;
			memory[ii21][jj21] = 2;
			memory[ii22][jj22] = 2;
			card_flag = 1;
		}

		wait(4, 0);

		system("CLS");
		c_out();
		cout << "\n\n";

		wait(2, 0);
		turn_counter2++;
		if ((turn_counter2 == (nn * nn) / 2) && (turn_counter1 == (nn * nn) / 2))
			finish();
	}
	////////////////////////////////////
	int suum = 0;
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			if (ans[i][j])
				suum++;
	if (suum == nn * nn)
		finish();
	////////////////////////////////////
	if (!hint_memory)
		pccc_uses_hint = 1;
	single_player();
}
void wait(float sec, bool t)
{
	space(0);
	clock_t time;
	time = clock();
	float tmp = 0;
	if (t == 0)
		while (tmp < (sec * 1000))
		{
			tmp = clock() - time;
		}
	else
		for (int i = sec; i > -1; i--)
		{
			clock_t time;
			time = clock();
			tmp = 0;
			while (tmp < 1000)
			{
				tmp = clock() - time;
			}
			cout << " " << i << " ";
		}
}
void sshow_hint(int hint_counter)
{
	if (hint_counter == 1)
		hint_counter1++;
	if (hint_counter > 1)
		hint_counter2++;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	show_hint = 1;
	system("CLS");
	if (hint_counter == 3)
	{
		space(0);
		cout << "Computer is using hint";
	}
	c_out();
	cout << "\n\n";
	space(1);
	cout << "The remaining cards are:\n";
	cout << "\n\n";
	wait(2, 1);
	///////////////////////
	if (pc)
		single_player();
	else
		multiplayer();
}
void space(bool spacee)
{
	if (!spacee)
		for (int k = (10 - nn) / 2; k > -6; k--)
			cout << "       ";
	else
		cout << "                                                            ";
}
void finish()
{
	system("CLS");
	cout << "fin";
	system("CLS");
	for (int k = (10 - nn) / 2; k > 0; k--)
		cout << "\n";
	for (int ii = 0; ii < nn; ii++)
	{
		space(0);
		cout << "         ";
		for (int jj = 0; jj < nn; jj++)
			if (ans[ii][jj])
				cout << " +---+ ";
			else
				cout << "       ";
		cout << endl;
		space(0);
		cout << "         ";
		for (int jj = 0; jj < nn; jj++)
			cout << "  " << n[ii][jj] << "  ";
		cout << endl;
		space(0);
		cout << "         ";
		for (int jj = 0; jj < nn; jj++)
			if (ans[ii][jj])
				cout << " +---+ ";
			else
				cout << "       ";
		cout << endl;
	}
	score1 = pow(nn / (wrong_counter1 + 1), 1 / (1 + hint_counter1));
	score2 = pow(nn / (wrong_counter2 + 1), 1 / (1 + hint_counter2));

	ofstream output_file("records.txt", ios::app);
	if (name_1 != "0000")
	{
		output_file << "\n    " << name_1 << "     " << score1 << "     ";
		if (!pc)
			output_file << "\n    " << name_2 << "     " << score2 << "     ";
	}
	output_file.close();

	system("pause");
	record();
	home();
}
void record()
{
	system("CLS");
	ifstream output_file("records.txt");
	string score;
	if (output_file.is_open())
	{
		while (getline(output_file, score))
			cout << score << "\n";
		cout << "\n\n";
		output_file.close();
		if (score == "")
			cout << "\n   !ERORR! File is empty!\n\n   ";
	}
	else
		cout << "\n   !ERORR! Can not open records file!\n\n   ";
	system("pause");
	system("CLS");
}