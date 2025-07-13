// Project1: Stone-Paper-Scissor.
#include <iostream>
using namespace std;
enum En_Choice { Scissor = 1, Stone, Paper };
enum En_Winner { User = 1, Computer, Draw };
struct St_Round_Info {
    En_Choice user_choice;
    En_Choice computer_choice;
    En_Winner winner;
    string winner_name;
};
struct St_Game_Info {
    short rounds;
    short num_user_win = 0;
    short num_computer_win = 0;
    short draw = 0;
    En_Winner winner;
    string winner_name;
};
short Read_Rounds() {
    short rounds;
    do {
        cout << "Please, enter the number of rounds from 1 to 10: ";
        cin >> rounds;
    } while (rounds < 1 || rounds>10);
    return rounds;
}
En_Choice Read_Choice(short& counter) {
    short choice;
    counter++;
    cout << "\n----------------------------------| Round [" << counter << "] |----------------------------------\n";
    do {
        cout << "Please, enter your number of choice (3 for Paper, 2 for Stone, 1 for Scissor): ";
        cin >> choice;
    } while (!(choice == 1 || choice == 2 || choice == 3));
    return En_Choice(choice);
}
En_Choice Random_Num(short from, short to) {
    return En_Choice(rand() % to + from);
}
En_Winner Check_Round_Winner(St_Round_Info round_info) {
    if (round_info.user_choice == round_info.computer_choice) {
        system("color 67");
        return En_Winner::Draw;
    }
    switch (round_info.user_choice) {
    case En_Choice::Scissor:
        if (round_info.computer_choice == En_Choice::Stone) {
            cout << "\a";
            system("color 47");
            return En_Winner::Computer;
        }
    case En_Choice::Stone:
        if (round_info.computer_choice == En_Choice::Paper) {
            cout << "\a";
            system("color 47");
            return En_Winner::Computer;
        }
    case En_Choice::Paper:
        if (round_info.computer_choice == En_Choice::Scissor) {
            cout << "\a";
            system("color 47");
            return En_Winner::Computer;
        }
    default:
        system("color 27");
        return En_Winner::User;
    }
}
En_Winner Check_Game_Winner(St_Game_Info game_info) {
    if (game_info.num_user_win > game_info.num_computer_win)
        return En_Winner::User;
    else if (game_info.num_user_win < game_info.num_computer_win) {
        cout << "\a";
        return En_Winner::Computer;
    }
    return En_Winner::Draw;
}
string Times(short time) {
    if (time == 1)
        return " time.\n";
    return " times.\n";
}
string Choice_Name(En_Choice en_choice) {
    string choice[3] = { "Scissor", "Stone", "Paper" };
    return choice[short(en_choice) - 1];
}
string Winner_Name(En_Winner en_winner) {
    string winner[3] = { "User","Computer","No Winner (Draw)" };
    return winner[short(en_winner) - 1];
}
string Taps(short num) {
    string t = "";
    for (short i = 0; i < num; i++)
        t += "\t";
    return t;
}
void Final_Result(St_Game_Info game_info) {
    cout << "\n" << Taps(2) << "--------------------------------------------------------------------\n";
    cout << Taps(3) << "    +++ G a m e  O v e r +++\n";
    cout << Taps(2) << "--------------------------------------------------------------------\n";
    cout << Taps(2) << "___________________________[Game Results]___________________________\n";
    cout << Taps(2) << "Game Rounds: " << game_info.rounds << ".\n";
    cout << Taps(2) << "The user won " << game_info.num_user_win << Times(game_info.num_user_win);
    cout << Taps(2) << "The computer won " << game_info.num_computer_win << Times(game_info.num_computer_win);
    cout << Taps(2) << "They draw " << game_info.draw << Times(game_info.draw);
    cout << Taps(2) << "Final Winner: " << game_info.winner_name << ".\n";
    cout << Taps(2) << "____________________________________________________________________\n";
}
void Play_Rounds() {
    St_Game_Info game_info;
    St_Round_Info round_info;
    short counter = 0;
    game_info.rounds = Read_Rounds();
    for (short i = 0; i < game_info.rounds; i++) {
        round_info.user_choice = Read_Choice(counter);
        round_info.computer_choice = Random_Num(1, 3);
        round_info.winner = Check_Round_Winner(round_info);
        if (round_info.winner == En_Winner::User)
            game_info.num_user_win++;
        else if (round_info.winner == En_Winner::Computer)
            game_info.num_computer_win++;
        else
            game_info.draw++;
        cout << "\n------| The result |------\n";
        cout << "Player Choice: " << Choice_Name(round_info.user_choice) << ".\n";
        cout << "Computer Choice: " << Choice_Name(round_info.computer_choice) << ".\n";
        cout << "Round Winner: " << Winner_Name(round_info.winner) << ".\n";
    }
    game_info.winner = Check_Game_Winner(game_info);
    game_info.winner_name = Winner_Name(game_info.winner);
    Final_Result(game_info);
}
void Start_Game() {
    char replay;
    do {
        Play_Rounds();
        do {
            cout << Taps(2) << "Please, do you want to play again (y/n)? ";
            cin >> replay;
        } while (!(replay == 'y' || replay == 'n'));
        if (replay == 'y') {
            system("color 07");
            system("cls");
        }
    } while (replay == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    Start_Game();
    return 0;
}