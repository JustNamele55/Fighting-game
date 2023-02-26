#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>
#include <Windows.h>
using namespace std;
class zaidimas
{
    private:
        int attack[2] = {0, 0},combop1[100], combop2[100], combodone1 = 0, combodone2 = 0, i = 0, hp1 = 10, hp2 = 10, player2, show, turn = 1, menu = 1, combo1[3] = {1, 1, 3}, combo2[3] = {3, 2, 1}, combo3[3] = {2, 1, 2}, combo4[3] = {2, 2, 3};
        string attack1, attack2;
        queue<int> p1;
        queue<int> p2;
    public:
        void Menu()
        {
            int input;
            do
            {
                system("CLS");
                cout << "-------------------------------------------------" << endl;
                cout << "1. Start the game" << endl;
                cout << "*************************************************" << endl;
                cout << "2. Settings" << endl;
                cout << "*************************************************" << endl;
                cout << "3. Quit" << endl;
                cout << "-------------------------------------------------" << endl;
                cin >> input;
                switch (input)
                {
                    case 1:
                        Start();
                        break;
                    case 2:
                        Settings();
                        break;
                    case 3:
                        Quit();
                }
            } while (input != 3);
        }
        void Start()
        {
            int start = 0;
            do
            {
                system("CLS");
                cout << "-------------------------------------------------" << endl;
                cout << "1. Player vs player" << endl;
                cout << "*************************************************" << endl;
                cout << "2. Player vs computer" << endl;
                cout << "*************************************************" << endl;
                cout << "3. Return to menu" << endl;
                cout << "-------------------------------------------------" << endl;
                cin >> start;
                switch (start)
                {
                    case 1:
                        player2 = 1;
                        Display();
                        break;
                    case 2:
                        player2 = 2;
                        Display();
                        break;
                    case 3:
                        Menu();
                        break;
                }
            } 
            while (start == 0);
        }
        void Settings()
        {
            int setup;
            do
            {
                system("CLS");
                cout << "-------------------------------------------------" << endl;
                cout << "1. Toggle show combinations" << endl;
                cout << "*************************************************" << endl;
                cout << "2. Change terminal text color" << endl;
                cout << "*************************************************" << endl;
                cout << "3. Coming soon" << endl;//padaryt-----------------------------------------
                cout << "*************************************************" << endl;
                cout << "4. Return to menu" << endl;
                cout << "-------------------------------------------------" << endl;
                cin >> setup;
                switch (setup)
                {
                    case 1:
                        setup = 4;
                        ComboShow();
                        break;
                    case 2:
                        setup = 4;
                        Color();
                        break;
                    case 3:
                        setup = 4;
                        //bbz
                        break;
                    case 4:
                        Menu();
                        break;
                }
            } while (setup != 4);
        }
        void Color()
        {
            int text;
            system("CLS");
            do
            {
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "Choose Background:" << endl;
                cout << "**************************************************************************" << endl;
                cout << "1. Blue, 2. Green, 3. Aqua, 4. Red, 5. Purple" << endl;
                cout << "**************************************************************************" << endl;
                cout << "6. Yellow, 7. White, 8. Gray, 9. Light blue, 0. Black" << endl;
                cout << "**************************************************************************" << endl;
                cout << "10. Return to menu" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cin >> text;
                switch (text)
                {
                    case 10:
                        Settings();
                        break;
                    case 1:
                        system("Color 01");
                        break;
                    case 2:
                        system("Color 02");
                        break;
                    case 3:
                        system("Color 03");
                        break;
                    case 4:
                        system("Color 04");
                        break;
                    case 5:
                        system("Color 05");
                        break;
                    case 6:
                        system("Color 06");
                        break;
                    case 7:
                        system("Color 07");
                        break;
                    case 8:
                        system("Color 08");
                        break;
                    case 9:
                        system("Color 09");
                        break;
                    case 0:
                        system("Color 00");
                        break;
                }
            } 
            while (text != 10);
        }
        bool ComboShow()
        {
            system("CLS");
            do
            {
                cout << "-------------------------------------------------" << endl;
                cout << "1. Show combinations" << endl;
                cout << "*************************************************" << endl;
                cout << "2. Hide combinations" << endl;
                cout << "*************************************************" << endl;
                cout << "3. Return to settings" << endl;
                cout << "-------------------------------------------------" << endl;
                cin >> show;
                switch (show)
                {
                case 1:
                    return show;
                case 2:
                    return show;
                case 3:
                    Settings();
                    break;
                }
            } while (show != 3);
        }
        void Display()
        {
            do
            {
                system("CLS");
                cout << "-------------------------------------------------" << endl;
                cout << "Controls:" << endl;
                cout << "*************************************************" << endl;
                cout << "1. Sword" << endl;
                cout << "*************************************************" << endl;
                cout << "2. Spear" << endl;
                cout << "*************************************************" << endl;
                cout << "3. Bow+Arrow" << endl;
                cout << "*************************************************" << endl;
                cout << "4. Return to main menu (player 1)" << endl;
                cout << "*************************************************" << endl;
                if (show == 2)
                {
                    cout << endl << "Combos are hidden" << endl << endl;
                }
                else
                {
                    cout << "Combos:" << endl;
                    cout << "1. " << combo1[0] << " -> " << combo1[1] << " -> " << combo1[2] << endl;
                    cout << "2. " << combo2[0] << " -> " << combo2[1] << " -> " << combo2[2] << endl;
                    cout << "3. " << combo3[0] << " -> " << combo3[1] << " -> " << combo3[2] << endl;
                    cout << "4. " << combo4[0] << " -> " << combo4[1] << " -> " << combo4[2] << endl;
                }
                cout << "*************************************************" << endl << endl;;
                cout << "   ( O_o)                      (O_o )" << endl;
                cout << "   (/   )/                    /(   /)" << endl << endl;;
                cout << "*************************************************" << endl << endl;
                if (player2 == 1)
                {
                    if (p1.empty() && p2.empty())
                    {
                        cout << "Player 1 hp: " << hp1 << "       Player 2 hp: " << hp2 << endl << endl;
                    }
                    else
                    {
                        cout << "Player 1 hp: " << hp1 << "       Player 2 hp: " << hp2 << endl << endl;
                        cout << "Player 1 attacked with: " << attack1 << "       Player 2 attacked with: " << attack2 << endl << endl;
                    }
                    cout << "Player 1 input:" << endl;
                    cin >> attack[0];
                    if (attack[0] == 4)
                    {
                        Menu();
                        system("pause");
                    }
                    cout << endl << "Player 2 input:" << endl;
                    cin >> attack[1];
                    if (attack[1] == 4)
                    {
                        Menu();
                        system("pause");
                    }
                    PVP();
                }
                else 
                {
                    if (p1.empty() && p2.empty())
                    {
                        cout << "Player 1 hp: " << hp1 << "       PC hp: " << hp2 << endl << endl;
                    }
                    else
                    {
                        cout << "Player 1 hp: " << hp1 << "       Player 2 hp: " << hp2 << endl << endl;
                        cout << "Player 1 attacked with: " << attack1 << "       PC attacked with: " << attack2 << endl << endl;
                    }
                    cout << "Player 1 input:" << endl;
                    cin >> attack[0];
                    if (attack[0] == 4)
                    {
                        Menu();
                        system("pause");
                    }
                    PVE();
                }
                switch (attack[0])
                {
                case 1:
                    attack1 = "Sword";
                    break;
                case 2:
                    attack1 = "Spear";
                    break;
                case 3:
                    attack1 = "Bow+Arrow";
                    break;
                case 4:
                    Menu();
                    break;
                }
                switch (attack[1])
                {
                case 1:
                    attack2 = "Sword";
                    break;
                case 2:
                    attack2 = "Spear";
                    break;
                case 3:
                    attack2 = "Bow+Arrow";
                    break;
                case 4:
                    Menu();
                    break;
                }
                cout << "-------------------------------------------------" << endl;
                attack[0] = 0;
                attack[1] = 0;
                if (combodone1 == 1)
                {
                    combop1[i - 2] = 0;
                    combop1[i - 1] = 0;
                    combop1[i] = 0;
                }
                if (combodone2 == 1)
                {
                    combop2[i - 2] = 0;
                    combop2[i - 1] = 0;
                    combop2[i] = 0;
                }
                combodone1 = 0;
                combodone2 = 0;
                if (hp2 <= 0)
                {
                    cout << "Player 1 is the winner" << endl;
                    system("pause");
                    Winner();
                    system("pause");
                    Menu();
                }
                if (hp1 <= 0)
                {
                    if (player2 == 1)
                    {
                        cout << "Player 2 is the winner" << endl;
                        system("pause");
                        Winner();
                        system("pause");
                        Menu();
                    }
                    if (player2 == 2)
                    {
                        cout << "PC is the winner" << endl;
                        system("pause");
                        Winner();
                        system("pause");
                        Menu();
                    }
                }
            } while (hp1 > 0 || hp2 > 0);
        }
        void PVP()
        {
            int winner = -1;
            p1.push(attack[0]);
            p2.push(attack[1]);
            if (attack[0] == 1)
            {
                if (attack[1] == 1)
                {
                    winner = 0;
                }
                else if (attack[1] == 2)
                {
                    winner = 2;
                }
                else if (attack[1] == 3)
                {
                    winner = 1;
                }
            }
            if (attack[0] == 2)
            {
                if (attack[1] == 1)
                {
                    winner = 1;
                }
                else if (attack[1] == 2)
                {
                    winner = 0;
                }
                else if (attack[1] == 3)
                {
                    winner = 2;
                }
            }
            if (attack[0] == 3)
            {
                if (attack[1] == 1)
                {
                    winner = 2;
                }
                else if (attack[1] == 2)
                {
                    winner = 1;
                }
                else if (attack[1] == 3)
                {
                    winner = 0;
                }
            }
            ComboCheck();
            if (winner == 0)
            {
                cout << "Draw" << endl;
            }
            else if (winner == 1)
            {
                cout << "Player 1 wins this round, Player 2 takes 1 damage" << endl;
                hp2--;
            }
            else if (winner == 2)
            {
                cout << "Player 2 wins this round, Player 1 takes 1 damage" << endl;
                hp1--;
            }
            system("pause");
            if (combodone1 == 1)
            {
                cout << "Player 1 did a combo and hits the opponent an additional time" << endl;
                hp2--;
                system("pause");
            }
            if (combodone2 == 1)
            {
                cout << "Player 2 did a combo and hits the opponent an additional time" << endl;
                hp1--;
                system("pause");
            }
        }
        void PVE()
        {
            AttackGeneretor();
            int winner = -1;
            p1.push(attack[0]);
            p2.push(attack[1]);
            if (attack[0] == 1)
            {
                if (attack[1] == 1)
                {
                    winner = 0;
                }
                else if (attack[1] == 2)
                {
                    winner = 2;
                }
                else if (attack[1] == 3)
                {
                    winner = 1;
                }
            }
            if (attack[0] == 2)
            {
                if (attack[1] == 1)
                {
                    winner = 1;
                }
                else if (attack[1] == 2)
                {
                    winner = 0;
                }
                else if (attack[1] == 3)
                {
                    winner = 2;
                }
            }
            if (attack[0] == 3)
            {
                if (attack[1] == 1)
                {
                    winner = 2;
                }
                else if (attack[1] == 2)
                {
                    winner = 1;
                }
                else if (attack[1] == 3)
                {
                    winner = 0;
                }
            }
            ComboCheck();
            if (winner == 0)
            {
                cout << "Draw" << endl;
            }
            else if (winner == 1)
            {
                cout << "Player 1 wins this round, Player 2 takes 1 damage" << endl;
                hp2--;
            }
            else if (winner == 2)
            {
                cout << "PC wins this round, Player 1 takes 1 damage" << endl;
                hp1--;
            }
            system("pause");
            if (combodone1 == 1)
            {
                cout << "Player 1 did a combo and hits the opponent an additional time" << endl;
                hp2--;
                system("pause");
            }
            if (combodone2 == 1)
            {
                cout << "PC did a combo and hits the opponent an additional time" << endl;
                hp2--;
                system("pause");
            }
        }
        void Winner()
        {
            system("CLS");
            if (hp1 <= 0)
            {
                cout << "The losing combo:" << endl;
                while (!p1.empty())
                {
                    cout << p1.front() << " ";
                    p1.pop();
                }
                cout << endl << "The winning combo:" << endl;
                while(!p2.empty())
                {
                    cout << p2.front() << " ";
                    p2.pop();
                }
                cout << endl;
            }
            if (hp2 <= 0)
            {
                cout << "The winning combo:" << endl;
                while (!p1.empty())
                {
                    cout << p1.front() << " ";
                    p1.pop();
                }
                cout << endl << "The losing combo:" << endl;
                while (!p2.empty())
                {
                    cout << p2.front() << " ";
                    p2.pop();
                }
                cout << endl;
            }
            system("pause");
        }
        void AttackGeneretor()
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distr(1, 3);
            attack[1] = distr(gen);
        }
        void ComboCheck()
        {
            combop1[i] = attack[0];
            combop2[i] = attack[1];
            if (p1.size() >= 3)
            {
                if (combop1[i - 2] == combo1[0])
                {
                    if (combop1[i - 1] == combo1[1])
                    {
                        if (combop1[i] == combo1[2])
                        {
                            combodone1 = 1;
                        }
                    }
                }
                if (combop1[i - 2] == combo2[0])
                {
                    if (combop1[i - 1] == combo2[1])
                    {
                        if (combop1[i] == combo2[2])
                        {
                            combodone1 = 1;
                        }
                    }
                }
                if (combop1[i - 2] == combo3[0])
                {
                    if (combop1[i - 1] == combo3[1])
                    {
                        if (combop1[i] == combo3[2])
                        {
                            combodone1 = 1;
                        }
                    }
                }
                if (combop1[i - 2] == combo4[0])
                {
                    if (combop1[i - 1] == combo4[1])
                    {
                        if (combop1[i] == combo4[2])
                        {
                            combodone1 = 1;
                        }
                    }
                }
                if (combop2[i - 2] == combo1[0])
                {
                    if (combop2[i - 1] == combo1[1])
                    {
                        if (combop2[i] == combo1[2])
                        {
                            combodone2 = 1;
                        }
                    }
                }
                if (combop2[i - 2] == combo2[0])
                {
                    if (combop2[i - 1] == combo2[1])
                    {
                        if (combop2[i] == combo2[2])
                        {
                            combodone2 = 1;
                        }
                    }
                }
                if (combop2[i - 2] == combo3[0])
                {
                    if (combop2[i - 1] == combo3[1])
                    {
                        if (combop2[i] == combo3[2])
                        {
                            combodone2 = 1;
                        }
                    }
                }
                if (combop2[i - 2] == combo4[0])
                {
                    if (combop2[i - 1] == combo4[1])
                    {
                        if (combop2[i] == combo4[2])
                        {
                            combodone2 = 1;
                        }
                    }
                }
            }
            i++;
        }
        void Quit()
    {
        int quit;
        system("CLS");
        cout << "-------------------------------------------------" << endl;
        cout << "Are you sure you want to quit?" << endl;
        cout << "*************************************************" << endl;
        cout << "1. Yes" << endl;
        cout << "*************************************************" << endl;
        cout << "2. No" << endl;
        cout << "-------------------------------------------------" << endl;
        cin >> quit;
        if (quit == 1)
        {
            system("CLS");
            terminate();
        }
        else
        {
            Menu();
        }
    }
};
int main()
{
    zaidimas print;
    print.Menu();
    return 0;
}