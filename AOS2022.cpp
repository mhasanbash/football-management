#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KCYN  "\x1B[36m"
#define KBLU  "\x1B[34m"
#define KGRN  "\x1B[32m"

FILE* users;
FILE* teams;
FILE* players;
FILE* league;
FILE* goal;
FILE* leagueinfor;
FILE* khastefile;
FILE* baziha;

struct team
{
    char teamname[20];
    char email[20];
    int money;
    char ID[5];
    char player[8][20];
    int cup;
    int submitsquad;
};
struct player
{
    char name[20];
    char teamname[20];
    int attackpower;
    int defencepower;
    int value;
    char ID[5];
};
struct league
{
    char teamname[31];
    int played;
    int won;
    int draw;
    int lost;
    int GF;
    int GA;
    int GD;
    int score;
    char RWF[31];
    int powerRWF[2];
    char LWF[31];
    int powerLWF[2];
    char RD[31];
    int powerRD[2];
    char LD[31];
    int powerLD[2];
    char GK[31];
    int powerGK[2];
    int submitsquad;
};
struct leagueinformation
{
    int weekith;
    int openclosetransfer;
    int endofleague;
};
struct khaste
{
    char playarname[31];
    int powerplayer[2];
};
struct week
{
    int play[4];
};
struct users
{
    char users[30];
    char passworld[30];
    char email[30];
};
struct goals
{
    char bazi[4][5];
};

int readfromfile();
int login();
int adminaccount();
int teamaccount();
int Counting();
int savinggame();
int startweeki();
int play(int a, int b);
int UpcomingOpponent(int a, int b);
int updatingtable(int a, int b, int c, int d);
int khasteh(int a);
int teamkeshi();
int winner();

struct users alluser[10];
struct team allteam[10];
struct player allplayer[100];
struct league teamleague[4];
struct leagueinformation leagueinfo;
struct khaste allkhaste[40];
struct goals allgoal[6];

//ghorekeshi team ha
struct week allweek[6];
int teama, teamb, teamc, teamd, teame;


//username
char input[31];

//line in player file
int count=0;
char c;

//line in team file
int count1=0;
char c1;

//while
int truee = 1;

//team account
int currentteam;
int flag;
int currentleagueteam;

//goal of team in play()
int goala = 0;
int goalb = 0;

int main()
{
    Counting();
    readfromfile();
    login();
    savinggame();
    return 0;
}


int login()
{
    while (truee)
    {
        flag = 0;
        printf("%s                          Attack On Soccer                  %s         \n"
               "                           _,aaadP""""""Ybaaaa,,_                        \n"
               "                       ,adP,__,,,aaaadPYYYYYY888888a,_                   \n"
               "                    ,a8888888P                 Y8888888b,                \n"
               "                 _a888888888                    `Y88888888b,             \n"
               "               ,d888888888P'                        888888888b,          \n"
               "             ,88888888PYY8,                       ,P'      Y888b,        \n"
               "           ,d8888P '      Ya,                    ,P'         `Ya`b,      \n"
               "          ,P88'            `Ya,                 ,P'            `b`Yi     \n"
               "         d',P                ` Y,              ,P'              `Y 'i    \n"
               "       ,P' P'                    888888888888888b                `b 'i   \n"
               "      ,P' d'                    d8888888888888888b                `b `b  \n"
               "      d' d'                    ,888888888888888888b                I, Y, \n"
               "     ,f ,f                    ,88888888888888888888b               `b, b \n"
               "     d' d'                    d888888888888888888888b              ,88,I \n"
               "    ,P  8                    ,88888888888888888888888b,_          ,d8888 \n"
               "    d'  8,                   d8888888888888888888888P'`'Ya,_     ,d88888 \n"
               "    8  d88b,             ,adP''Y888888888888888888P'      `''Ya, d88888P \n"
               "    8 ,88888b,       ,adP''     `'Y8888888888888''             `'888888I \n" 
               "    Y,88888888b, ,adP''             ''Y888888P'                  888888' \n"
               "    `888888888888P'                     ''YP'                    888888  \n" 
               "     I88888888888                          8                     88888I  \n"
               "     `Y8888888888                          8                     88888'  \n"
               "      `Y888888888        Normand           8                     8888I   \n"
               "       `Y88888888        Veilleux          8                     8P'8'   \n"
               "        `Y8888888,                         8                   ,d',d'    \n"
               "         `b''''Y8b                         8                 ,d' ,d'     \n"
               "           'b,   'Y,                       8               ,P' ,d'       \n"
               "             'b,   'Ya,_                 ,d88ba,,___   _,aP' ,P'        \n"
               "               'Ya_   ''Ya,_       _,,ad88888888888888P'' _,d'          \n"
               "                 `'Ya_    ''Yaaad88888888888888888888P _,d''            \n"
               "                     `'Ya,_     'Y888888888888888888P', d'              \n"
               "                        `""Ya,__`Y888888888888888P'''                   \n"
               "                             ``'''''''''''''''''''''\n",KGRN,KNRM);
 

        printf("\n1-login\n2-forgot password\n3-exit\n");
        int n;
        scanf("%d", &n);

        if (n == 1)
        {

            while (truee)
            {
                if (flag == 1)
                {
                    break;
                }
                //chek user and password
                printf("\nEnter your username:");
                
                char inputpas[31];
                scanf("%s", input);

                //enter admin account
                if (strcmp(input, "admin") == 0)
                {
                    printf("\nEnter your password:");
                    scanf("%s", inputpas);
                    if (strcmp(inputpas, "admin") == 0)
                    {
                        adminaccount();
                        break;
                    }

                }
                else
                {
                    for (int i = 0; i <= count1; i+=1)
                    {
                        if (strcmp(input,alluser[i].users) == 0)
                        {
                            printf("\nEnter your password:");
                            scanf("%s", inputpas);
                            if (strcmp(inputpas, alluser[i].passworld) == 0)
                            {
                                currentteam = i;
                                for (int i = 0; i < 4; i++)
                                {
                                    if (strcmp(allteam[currentteam].teamname, teamleague[i].teamname) == 0)
                                    {
                                        currentleagueteam = i;
                                    }
                                }
                                teamaccount();
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (flag == 0)
                    {
                        printf("Your username or password is incurrent!\n");
   
                    }
                }
                
            }
        }
    
        if (n == 2)
        {
            while (truee)
            {
                int flag = 0;
                printf("enter your team name\n");
                char str11[30];
                scanf("%s", str11);
                for (int i = 0; i < count1; i++)
                {
                    if (strcmp(str11, alluser[i].users) == 0)
                    {
                        printf("enter your team email\n");
                        char str12[30];
                        scanf("%s", str12);
                        if (strcmp(str12, alluser[i].email) == 0)
                        {
                            printf("Enter New Password:");
                            char str13[30];
                            scanf("%s", str13);
                            strcpy(alluser[i].passworld, str13);
                            printf("%syour password changed%s\n", KGRN, KNRM);
                            savinggame();
                            flag = 1;
                        }
                    }
                }
                if (flag == 0)
                {
                    printf("%syour user name or password is incurrect%s\n", KRED, KNRM);
                }
                printf("1-exit\n2-try again\n");
                int exit = 0;
                scanf("%d", &exit);
                if (exit == 1)
                {
                    break;
                }
            }
        }

        if (n == 3)
        {
            break;
        }
    }
    return 0;
}


int adminaccount()
{
    system("cls");
    while (truee)
    {
        system("cls");
        printf("%sweek %dth%s\n", KRED, leagueinfo.weekith, KNRM);
        if (leagueinfo.weekith == 4)
        {
            printf("%sthe nimfasl is tamoom%s\n", KRED, KNRM);
        }
        if (leagueinfo.weekith == 7)
        {
            printf("%sthe fasl is tamoom%s\n", KRED, KNRM);
        }
        if (leagueinfo.openclosetransfer == 0)
        {
            printf("%sthe transfer windows is closed\n%s",KRED, KNRM);
        }
        if (leagueinfo.openclosetransfer == 1)
        {
            printf("%sthe transfer windows is Open\n%s", KYEL, KNRM);
        }

        
        printf("%s_________________________________________________________________\n"      
        "                ________________________________________________________\n"
        "               /                          /                            /\n"
        "              /________                  /                    ________/ \n"
        "           /|/______  /                 /                   /  ____/|   \n"
        "          /_|/    /  /-              --/--                 /  /   / |_  \n"
        "        _/_/     /  /   :         /   /   \\              /  /_  / __ | \n"
        "        /|/     /  /   /         (   /    /              /  /    |\     \n"
        "       /_|     /  /.-       o     \ /_._ /              /  /     |_\/   \n"
        "        /-----   /         /|\\    /                   /   -----/       \n"
        "       /--------           /)     /                    --------/        \n"
        "      /                          /                            /         \n"
        "     /__________________________/____________________________/          %s\n",KGRN,KNRM);


        printf("\nadminaccount\n");
        printf("1-Add Team\n2-Add Player\n3-Show Teams\n4-Show Players\n5-Manage league\n6-log out\n");
        int n;
        scanf("%d", &n);

        //Add Team
        if (n == 1)
        {
            teams = fopen("teames.txt", "a");
            printf("Enter your team name:");
            fputc(',', teams);
            char str[31];
            scanf("%s", str);
            fputs(str, teams);
            fputc(',', teams);
            char str1[31];
            printf("Enter your email:");
            scanf("%s", str1);
            fputs(str1, teams);
            fputc(',', teams);
            fputs("100", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fputs("NULL", teams);
            fputc(',', teams);
            fprintf(teams, "%d", 0);
            fputc(',', teams);
            fprintf(teams, "%d", 0);
            fputc(',', teams);
            int id = 800 + count1;
            fputc('#', teams);
            fprintf(teams, "%d", id);
            fputc(',', teams);
            fputc('\n', teams);
            fclose(teams);

            //craete user name password
            users = fopen("users.txt", "a"); 
            fputc(',', users);
            fputs(str, users);
            fputc(',', users);
            fputs(str1, users);
            fputc(',', users);
            fputs(str1, users);
            fputc(',', users);
            fputc('\n', users);
            fclose(users);
            
            readfromfile();
        }

        //Add Player
        if (n == 2)
        {
            players = fopen("player.txt", "a");
            
            char str2[31];
            //enter player name
            printf("\nEnter player name :");
            fputc(',', players);
            scanf("%s", str2);
            fputs(str2, players);
            fputc(',', players);
            //player teams
            char str3[31] = "Free Agent";
            fputs(str3, players);
            fputc(',', players);
            //enter attacking power
            char str4[31];
            printf("\nEnter Attacking power:");
            scanf("%s", str4);
            fputs(str4, players);
            fputc(',', players);
            //enter defencing power
            char str5[31];
            printf("\nEnter Defencing power:");
            scanf("%s", str5);
            fputs(str5, players);
            fputc(',', players);
            //enter Value
            char str6[31];
            printf("\nEnter Value:");
            scanf("%s", str6);
            fputs(str6, players);
            fputc(',', players);
            //generate ID
            int id = count;
            fputs("#00", players);
            fprintf(players, "%d", count);
            fputc(',', players);
            fputc('\n', players);
            
            fclose(players);
            
            readfromfile();

        }

        //Show Teams
        if (n == 3)
        {
            
            printf("team name   |   cup\n");
            for (int i = 0; i < count1; i++)
            {
                printf("_____________________________\n");
                printf("%d-%s      ",i, allteam[i].teamname);
                printf("%d\n", allteam[i].cup);
            }
            while (truee)
            {
                
                int n;
                scanf("%d", &n);
                system("cls");
                //print player and detale player of curent team
                switch (n) {
                case 0:
                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(allplayer[i].teamname, allteam[0].teamname) == 0)
                        {
                            printf("%s - %d - %d - %d\n", allplayer[i].name, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value);
                        }
                    }
                    break;

                case 1:
                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(allplayer[i].teamname, allteam[1].teamname) == 0)
                        {
                            printf("%s - %d - %d - %d\n", allplayer[i].name, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value);
                        }
                    }
                    break;

                case 2:
                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(allplayer[i].teamname, allteam[2].teamname) == 0)
                        {
                            printf("%s - %d - %d - %d\n", allplayer[i].name, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value);
                        }
                    }
                    break;

                case 3:
                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(allplayer[i].teamname, allteam[3].teamname) == 0)
                        {
                            printf("%s - %d - %d - %d\n", allplayer[i].name, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value);
                        }
                    }
                    break;
                }
                printf("1-back");
                int contin = 0;
                scanf("%d", &contin);
                if (contin == 1)
                {
                    break;
                }
            }
        }

        //Show Players
        if (n == 4)
        {
            system("cls");
            printf("player name - team name - attacking power - defencing power - value\n");
            for (int i = 0; i < count; i++)
            {
                printf("%s - %s - %d - %d - %d\n", allplayer[i].name, allplayer[i].teamname, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value);
            }
            printf("1-countinue");
            int contin = 0;
            scanf("%d", &contin);
        }

        //Manage league
        if (n == 5)
        {
            league = fopen("league.txt", "r");
            
            if (fgetc(league) == EOF)
            {
                fclose(league);
                printf("1-Start League:\n");
                leagueinfor = fopen("leagueinfo.txt", "w");
                fprintf(leagueinfor, "%d%c%d%c%d%c", 1, ',', 1, ',', 0, ',');
                fclose(leagueinfor);
                readfromfile();
                int counti = 0;
                scanf("%d", &counti);
                league = fopen("league.txt", "w");

                int amade = 0;
                for (int i = 0; i < count1; i++)
                {
                    if (allteam[i].submitsquad == 1)
                    {
                        amade += 1;
                    }
                }


                if (amade == 4)
                {
                    int t = 0;
                    while(t!=4)
                    {
                        for (int i = 0; i < count1; i++)
                        {
                            printf("%d-%s%s%s\n", i, KGRN, allteam[i].teamname, KNRM);
                        }
                        int i = 0;
                        scanf("%d", &i);

                        if (allteam[i].submitsquad == 1)
                        {
                            allteam[i].submitsquad = 0;
                            fputc(',', league);
                            fputs(allteam[i].teamname, league);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fputs("NULL", league);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fputs("NULL", league);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fputs("NULL", league);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fputs("NULL", league);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fputs("NULL", league);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fprintf(league, "%d", 0);
                            fputc(',', league);
                            fputc('\n', league);
                            printf("%sthe team was secsefully added to league%s\n", KBLU, KNRM);
                            t += 1;

                        }
                        else
                        {
                            printf("%sthe teams is not ready!%s\n",KRED,KNRM);
                        }
                    }
                    fclose(league);


                    //goal file
                    goal = fopen("goal.txt", "w");
                    for (int i = 0; i < 6; i++)
                    {
                        fputc(',', goal);
                        fputc('*', goal);
                        fputc(',', goal);
                        fputc('*', goal);
                        fputc(',', goal);
                        fputc('*', goal);
                        fputc(',', goal);
                        fputc('*', goal);
                        fputc(',', goal);
                        fputc('\n', goal);
                    }
                    fclose(goal);
                    printf("the league was started\n");

                    //league unformation
                    leagueinfor = fopen("leagueinfo.txt", "w");
                    fprintf(leagueinfor, "%d%c%d%c%d%c", 1, ',', 1, ',', 0, ',');
                    fclose(leagueinfor);
                    //saving to struct
                    teamkeshi();
                    readfromfile();

                }
                else
                {
                    printf("%syour teams in not ready%s\n1-back",KRED,KNRM);
                    int back = 0;
                    scanf("%d",&back);
                }
            }
            else
            {
                printf("1-Open / Close Transfer Window\n2--Start Week i-th Games\n");
                if (leagueinfo.weekith == 7)
                {
                    printf("3--End Season and Announce The Champion\n");
                }
                int n;
                scanf("%d", &n);

                //Open / Close Transfer Window
                if (n == 1)
                {
                    system("cls");
                    printf("1-Open Transfer Window\n2-Close Transfer Window\n");
                    int n = 0;
                    scanf("%d", &n);
                    system("cls");
                    if (n == 1)
                    {
                        for (int i = 0; i < count1; i++)
                        {
                            allteam[i].submitsquad = 0;
                        }
                        leagueinfo.openclosetransfer = 1;
                    }
                    else
                    {
                        int amade = 0;
                        for (int i = 0; i < count1; i++)
                        {
                            for (int j = 0; j < count1; j++)
                            {
                                if (strcmp(allteam[i].teamname, teamleague[j].teamname) == 0)
                                {
                                    printf("%s ", allteam[i].teamname);
                                    if (allteam[i].submitsquad==1)
                                    {
                                        printf("%sis ready%s\n",KGRN,KNRM);
                                        amade += 1;
                                    }
                                    else
                                    {
                                        printf("%sis not ready%s\n",KRED, KNRM);
                                    }
                                }
                            }
                        }
                        if (amade == 4)
                            leagueinfo.openclosetransfer = 0;
                        else
                            printf("teams is not ready\n");
                    }
                    int back = 0;
                    printf("1-back\n");
                    scanf("%d", & back);
                    savinggame();
                }

                //2--Start Week i-th Games
                if (n == 2)
                {
                    startweeki();
                    savinggame();
                }

                //End Season and Announce The Champion
                if (n == 3)
                {
                    if (leagueinfo.weekith == 7)
                    {
                        winner();
                    }
                }
            }

        }

        //log out
        if (n == 6)
        {
            system("cls");
            break;
            login();
        }
    }
    return 0;
}


int teamaccount()
{
    
    while (truee)
    {
        
        system("cls");
        printf("Welcome %s%s%s\n",KRED ,alluser[currentteam].users,KNRM);
        printf("week %dth\nMoney:%d\n", leagueinfo.weekith,allteam[currentteam].money);
        flag = 0;
        printf("                                                                        \n"
            "                                                     -------------------                             \n"
            "                                                           My Team                                   \n"
            "                                                     -------------------                             \n"
            "                                                                                                                                           %s               \n"
            "     %s                            %s                         %s                             %s                    %s                                                                          \n"
            "                                                                                                                                              ,/)       \n"
            "                                                                                                                                              |_|       \n"
            "           _                       _                            _                            _                          _                     ].[       \n"
            "          |.|                     |.|                          |.|                          |.|                        |.|                  /~`-~`|    \n"
            "          ]^[                     ]^[                          ]^[                          ]^[                        ]^[                 (<|   |>)    \n"
            "        /~`-'~|                 /~`-'~|                      /~`-'~|                      /~`-'~|                    /~`-'~|               |_______|    \n"
            "       {<|   |>}               {<|   |>}                    {<|   |>}                    {<|   |>}                  {<|   |>}              {/      }    \n"
            "        {{|___|/                {|___|/                      {|___|/                      {|___|/                    {|___|/                |     |     \n"
            "       /      |                  /    |                       /    |                       /    |                     /    |                |  |  |     \n"
            "       |/>/|_ |                 /__|__|                      / _|_ |                      /__|__|                    /__|__|                |__|__|     \n"
            "      _|)   |_|                 | / | |                      | / | |                      | / | |                    | / | |                {}   {}     \n"
            "     (_,|   | )                 (/  | )                      (/  | )                      (/  | )                    (/  | )                |)   (|     \n"
            "     / \\    (|_               _|)   (|_                    _|)   (|_                    _|)   (|_                  _|)   (|_              _||   ||_    \n"
            "  .,.\\_/,...,|,_)            (_,|,.,|,_)                  (_,|,.,|,_)                  (_,|,.,|,_)                (_,|,.,|,_)            (_,|.,.|,_).,.\n\n"
            "                 %s                                %s                                   \n"
            "                                _                                  _                    \n"
            "                               |.|                                |.|                   \n"
            "                               ]^[                                ]^[                   \n"
            "                             /~`-'~|                            /~`-'~|                 \n"
            "                            {<|   |>}                          {<|   |>}                \n"
            "                             {|___|/                            {|___|/                 \n"
            "                              /    |                             /    |                 \n"
            "                             /__|__|                            /__|__|                 \n"
            "                             | / | |                            | / | |                 \n"
            "                             (/  | )                            (/  | )                 \n"
            "                            _|)   (|_                          _|)   (|_                \n"
            "                           (_,|,.,|,_)                        (_,|,.,|,_)               \n",allteam[currentteam].player[0], allteam[currentteam].player[1], allteam[currentteam].player[2], allteam[currentteam].player[3], allteam[currentteam].player[4], allteam[currentteam].player[5], allteam[currentteam].player[6], allteam[currentteam].player[7]);
        printf("1- Buy a Player\n2- Sell a Player\n3- Select Squad (Submit Squad)\n4- League Standing\n5- Fixtures\n6- Upcoming Opponent\n7- Change Password\n8- Exit\n");
        int n;
        scanf("%d", &n);

        //Buy a Player
        if (n == 1)
        {
            system("cls");
            //check the teansfer window
            if (leagueinfo.openclosetransfer == 1)
            {
                printf("________________________________________________________________________________\nyour money :%d\n", allteam[currentteam].money);
                printf("player name - team name - attacking power - defencing power - value\n");
                for (int j = 20; j != 9; j--)
                {
                    for (int i = 0; i < count; i++)
                    {
                        if (allplayer[i].value == j)
                        {
                            if (strcmp(allplayer[i].teamname, "Free Agent") == 0)
                            {
                                printf("%s - %s - %d - %d - %d - %s\n", allplayer[i].name, allplayer[i].teamname, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value, allplayer[i].ID);
                            }
                        }
                    }
                }

                //input current player ID
                printf("enter your player ID:");
                char str8[12];
                scanf("%s", str8);

                for (int i = 0; i < count; i++)
                {
                    if ((strcmp(allplayer[i].ID, str8) == 0) && (allplayer[i].value <= allteam[currentteam].money))
                    {
                        for (int j = 0; j < 9; j++)
                        {
                            if (strcmp(allteam[currentteam].player[j], "NULL") == 0)
                            {
                                flag = 1;
                                //add player to team
                                strcpy(allteam[currentteam].player[j], allplayer[i].name);
                                //add taemname to player detales
                                strcpy(allplayer[i].teamname, allteam[currentteam].teamname);
                                //Money deduction
                                allteam[currentteam].money = allteam[currentteam].money - allplayer[i].value;
                                //print add player was secsefully
                                printf("your player add to team\n1-continue");
                                //saving game
                                savinggame();
                                int countinue;
                                scanf("%d", &countinue);
                                break;
                            }
                        }
                    }

                }
                if (flag == 0)
                {
                    printf("your squad is full or your money is not enogh");
                    int countinue;
                    scanf("%d", &countinue);
                }
            }
            else
            {
                printf("teansfer window is closed\n1-countinue\n");
                int countinue;
                scanf("%d", &countinue);
            }
        }

        //Sell a Player
        if (n == 2)
        {
            system("cls");
            //check the teansfer window
            if (leagueinfo.openclosetransfer == 1)
            {
                printf("________________________________________________________________________________\nyour money :%d\n", allteam[currentteam].money);
                printf("player name - team name - attacking power - defencing power - value\n");
                for (int i = 0; i <= count; i++)
                {
                    //print player in team
                    if (strcmp(allplayer[i].teamname, allteam[currentteam].teamname) == 0)
                    {
                        printf("%s - %s - %d - %d - %d - %s\n", allplayer[i].name, allplayer[i].teamname, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value, allplayer[i].ID);
                    }
                }
                //input current player ID
                printf("enter your player ID:");
                char str9[10];
                scanf("%s", str9);

                for (int j = 0; j < count; j++)
                {
                    if (strcmp(allplayer[j].ID, str9) == 0)
                    {
                        //remove teamname in player detales
                        strcpy(allplayer[j].teamname, "Free Agent");

                        //remove playername in teamplayer
                        for (int i = 0; i <= 8; i++)
                        {
                            if (strcmp(allplayer[j].name, allteam[currentteam].player[i]) == 0)
                            {
                                strcpy(allteam[currentteam].player[i], "NULL");
                            }
                        }

                        //add value of player in money
                        allteam[currentteam].money = allteam[currentteam].money + allplayer[j].value;

                        //saving game
                        savinggame();
                        int countinue;
                        printf("________________________________________________________________________________\nyour money :%d\n", allteam[currentteam].money);
                        scanf("%d", &countinue);
                        break;
                    }
                }
            }
            else
            {
                printf("teansfer window is closed\n1-back\n");
                int countinue=0;
                scanf("%d", &countinue);
            }
            
        }

        //Select Squad (Submit Squad)
        if (n == 3)
        {
            system("cls");
            readfromfile();
            if (leagueinfo.openclosetransfer == 0)
            {
                printf("1-Select Squad\n");
                int back = 0;
                scanf("%d",  &back);
                //show player in team
                printf("%splayer name | teamname | attackpower | defencepower | value | ID |\n%s", KYEL, KNRM);
                for (int i = 0; i < count; i++)
                {
                    //print player in team
                    if (strcmp(allplayer[i].teamname, allteam[currentteam].teamname) == 0)
                    {
                        printf("%s - %s - %d - %d - %d - %s\n", allplayer[i].name, allplayer[i].teamname, allplayer[i].attackpower, allplayer[i].defencepower, allplayer[i].value, allplayer[i].ID);
                    }
                }

                printf("\n\n\nkhaste playar:\n%s| playername | \\/attackpower | \\/defencepower |%s\n", KYEL, KNRM);
                //show khaste player in team
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (strcmp(allkhaste[i].playarname, allteam[currentteam].player[j]) == 0)
                        {
                            printf("%s%s - %d - %d\n", KRED, allkhaste[i].playarname, allkhaste[i].powerplayer[0], allkhaste[i].powerplayer[1]);
                        }
                    }
                }
                printf("\n\n%s", KNRM);

                printf("1-select previus squad\n2-select new squad\n");
                int select = 0;
                scanf("%d", &select);

                if (select == 2)
                {
                    char sqd[6][4] = { "RWF","LWF","RD","LF","GK" };

                    for (int j = 0; j < 5; j++)
                    {
                        printf("enter your %s name: ", sqd[j]);

                        char str9[31];
                        scanf("%s", str9);

                        for (int k = 0; k < count; k++)
                        {
                            if (strcmp(allplayer[k].name, str9) == 0)
                            {
                                switch (j)
                                {
                                case(0):
                                    strcpy(teamleague[currentleagueteam].RWF, str9);
                                    for (int i = 0; i <= 20; i++)
                                    {
                                        if (strcmp(str9, allkhaste[i].playarname) == 0)
                                        {
                                            teamleague[currentleagueteam].powerRWF[0] = allkhaste[i].powerplayer[0];
                                            teamleague[currentleagueteam].powerRWF[1] = allkhaste[i].powerplayer[1];
                                            break;
                                        }
                                        if (i == 20)
                                        {
                                            teamleague[currentleagueteam].powerRWF[0] = allplayer[k].attackpower;
                                            teamleague[currentleagueteam].powerRWF[1] = allplayer[k].defencepower;
                                        }
                                    }
                                    break;

                                case(1):
                                    strcpy(teamleague[currentleagueteam].LWF, str9);
                                    for (int i = 0; i <= 20; i++)
                                    {
                                        if (strcmp(str9, allkhaste[i].playarname) == 0)
                                        {
                                            teamleague[currentleagueteam].powerLWF[0] = allkhaste[i].powerplayer[0];
                                            teamleague[currentleagueteam].powerLWF[1] = allkhaste[i].powerplayer[1];
                                            break;
                                        }
                                        if (i == 20)
                                        {
                                            teamleague[currentleagueteam].powerLWF[0] = allplayer[k].attackpower;
                                            teamleague[currentleagueteam].powerLWF[1] = allplayer[k].defencepower;
                                        }
                                    }
                                    break;

                                case(2):
                                    strcpy(teamleague[currentleagueteam].RD, str9);
                                    for (int i = 0; i <= 20; i++)
                                    {
                                        if (strcmp(str9, allkhaste[i].playarname) == 0)
                                        {
                                            teamleague[currentleagueteam].powerRD[0] = allkhaste[i].powerplayer[0];
                                            teamleague[currentleagueteam].powerRD[1] = allkhaste[i].powerplayer[1];
                                            break;
                                        }
                                        if (i == 20)
                                        {
                                            teamleague[currentleagueteam].powerRD[0] = allplayer[k].attackpower;
                                            teamleague[currentleagueteam].powerRD[1] = allplayer[k].defencepower;
                                        }
                                    }
                                    break;

                                case(3):
                                    strcpy(teamleague[currentleagueteam].LD, str9);
                                    for (int i = 0; i <= 20; i++)
                                    {
                                        if (strcmp(str9, allkhaste[i].playarname) == 0)
                                        {
                                            teamleague[currentleagueteam].powerLD[0] = allkhaste[i].powerplayer[0];
                                            teamleague[currentleagueteam].powerLD[1] = allkhaste[i].powerplayer[1];
                                            break;
                                        }
                                        if (i == 20)
                                        {
                                            teamleague[currentleagueteam].powerLD[0] = allplayer[k].attackpower;
                                            teamleague[currentleagueteam].powerLD[1] = allplayer[k].defencepower;
                                        }
                                    }
                                    break;

                                case(4):
                                    strcpy(teamleague[currentleagueteam].GK, str9);
                                    for (int i = 0; i <= 20; i++)
                                    {
                                        if (strcmp(str9, allkhaste[i].playarname) == 0)
                                        {
                                            teamleague[currentleagueteam].powerGK[0] = allkhaste[i].powerplayer[0];
                                            teamleague[currentleagueteam].powerGK[1] = allkhaste[i].powerplayer[1];
                                            break;
                                        }
                                        if (i == 20)
                                        {
                                            teamleague[currentleagueteam].powerGK[0] = allplayer[k].attackpower;
                                            teamleague[currentleagueteam].powerGK[1] = allplayer[k].defencepower;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
                    printf("%syour squad secsesfully selected%s", KGRN, KNRM);
                }
                
                
                printf("\nyour squad:\n_____________________________________________________________________________\n");
                printf("%s(%d)           %s(%d)\n\n%s(%d)           %s(%d)\n\n         |%s|(%d)      \n-----------------------------------------------------", teamleague[currentleagueteam].RWF, teamleague[currentleagueteam].powerRWF[0], teamleague[currentleagueteam].LWF, teamleague[currentleagueteam].powerLWF[0], teamleague[currentleagueteam].RD, teamleague[currentleagueteam].powerRD[1], teamleague[currentleagueteam].LD, teamleague[currentleagueteam].powerLD[1], teamleague[currentleagueteam].GK, teamleague[currentleagueteam].powerGK[1]);
                printf("1-select squad");
                scanf("%d", &teamleague[currentleagueteam].submitsquad);
                savinggame();
                readfromfile();
            }
            else
            {
                printf("1-submit squad\n");
                int countin = 0;
                scanf("%d", &countin);
                int chek = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (strcmp(allteam[currentteam].player[i], "NULL") == 0)
                    {
                        chek = 1;
                    }
                }
                if (chek == 1)
                {
                    allteam[currentteam].submitsquad = 0;
                    printf("your squad is not fully");
                }
                else
                {
                    allteam[currentteam].submitsquad = 1;
                    printf("your team is ready");
                }
                printf("1-back");
                savinggame();
                int back = 0;
                scanf("%d", &back);
            }
        }

        //League Standing
        if (n == 4)
        {
            system("cls");
            int a = 0, b = 1, c = 2, d = 3;
            int standing[4] = {a,b,c,d };
            int temp=0;
            printf("%steamname  |  played  |  won  |  draw  |  lose  | GF | GA | GD |  score  |%s\n",KCYN,KNRM);
            for (int j = 0,i =0; j < 4; j++)
            {
                int p = i;
                for(int l=0; l<4, i+1<4 ; l++,i++)
                {
                    if (teamleague[standing[j]].score < teamleague[standing[i + 1]].score)
                    {
                        temp = standing[i + 1];
                        standing[i + 1] = standing[j];
                        standing[j] = temp;
                    }
                    else if (teamleague[standing[j]].score == teamleague[standing[i + 1]].score)
                    {
                        if (teamleague[standing[j]].GD < teamleague[standing[i + 1]].GD)
                        {
                            temp = standing[i + 1];
                            standing[i + 1] = standing[j];
                            standing[j] = temp;
                        }
                        else if (teamleague[standing[j]].GD == teamleague[standing[i + 1]].GD)
                        {
                            if (teamleague[standing[j]].GF < teamleague[standing[i + 1]].GF)
                            {
                                temp = standing[i + 1];
                                standing[i + 1] = standing[j];
                                standing[j] = temp;
                            }
                            else if (teamleague[standing[j]].GF == teamleague[standing[i + 1]].GF)
                            {
                                if (teamleague[standing[j]].GA >= teamleague[standing[i + 1]].GA)
                                {
                                    temp = standing[i + 1];
                                    standing[i + 1] = standing[j];
                                    standing[j] = temp;
                                }
                            }
                        }
                    }
                }
                i = p;
                i++;
            }
        
            for (int i = 0; i < 4; i++)
            {
                printf("%s%s  %s|    %d    |    %d    |    %d    |    %d    | %d | %d | %d |    %d    |\n",KCYN ,teamleague[standing[i]].teamname,KYEL, teamleague[standing[i]].played, teamleague[standing[i]].won, teamleague[standing[i]].draw, teamleague[standing[i]].lost, teamleague[standing[i]].GF, teamleague[standing[i]].GA, teamleague[standing[i]].GD, teamleague[standing[i]].score);
            }
            printf("%s1-back",KNRM);
            int countinue = 0;
            scanf("%d", &countinue);
        }

        //Fixtures
        if (n == 5)
        {
            for (int i = 0; i < 6; i++)
            {
                printf("%sweek %d%s\n",KRED ,i + 1,KGRN);
                for (int j = 0; j < 4; j+=2)
                {
                    printf("%s %s-%s %s\n", teamleague[allweek[i].play[j]].teamname,allgoal[i].bazi[j], allgoal[i].bazi[j+1], teamleague[allweek[i].play[j + 1]].teamname);
                }
            }
            printf("%s1-back",KNRM);
            int countinue = 0;
            scanf("%d", &countinue);
        }

        //Upcoming Opponent
        if (n == 6)
        {
            system("cls");
            startweeki();
            printf("1-back");
            int countinue = 0;
            scanf("%d", &countinue);
        }

        //Change Password
        if (n == 7)
        {
            while (truee)
            {
                printf("enter your team email\n");
                char str12[30];
                scanf("%s", str12);
                if (strcmp(str12, alluser[currentteam].email) == 0)
                {
                    printf("Enter New Password:");
                    char str13[30];
                    scanf("%s", str13);
                    strcpy(alluser[currentteam].passworld, str13);
                    printf("%syour password changed%s\n", KGRN, KNRM);
                    savinggame();
                    flag = 1;
                }


                if (flag == 0)
                {
                    printf("%syour user name or password is incurrect%s\n", KRED, KNRM);
                }
                printf("1-exit\n2-try again\n");
                int exit = 0;
                scanf("%d", &exit);
                if (exit == 1)
                {
                    break;
                }
            }
        }

        if (n == 8)
        {
            system("cls");
            break;
        }
    }
    return 0;
}


int Counting()
{
    
    //count number of lines in  players file
    players = fopen("player.txt", "r");
    count = 0;
    for (c = getc(players); c != EOF; c = getc(players))
    {
        if (c == '\n') // Increment count if this character is newline
            count += 1;
    }
    fclose(players);


    //count number of lines teams file
    teams = fopen("teames.txt", "r");
    count1 = 0;
    for (c1 = getc(teams); c1 != EOF; c1 = getc(teams))
    {
        if (c1 == '\n') // Increment count if this character is newline
            count1 = count1 + 1;
    }
    fclose(teams);
    return 0;
}


int readfromfile()
{
    
    Counting();
    int payan[15];
    int payan1[15];
    int payan2[30];
    int payan3[5];
    int payan4[6];
    int payan5[4];
    int payan6[7];
    //read teams with deatles from file
    teams = fopen("teames.txt", "r");
    for (int i = 0; i < count1; i++)
    {
        int t = 0;
        while (t != 15)
        {
            if (fgetc(teams) == ',')
            {
                payan[t] = ftell(teams);
                t += 1;
            }
        }

        fseek(teams, payan[0], SEEK_SET);

        fgets(allteam[i].teamname, payan[1] - payan[0], teams);


        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].email, payan[2] - payan[1], teams);


        fseek(teams, 1, SEEK_CUR);
        fscanf(teams, "%d", &allteam[i].money);


        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[0], payan[4] - payan[3], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[1], payan[5] - payan[4], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[2], payan[6] - payan[5], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[3], payan[7] - payan[6], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[4], payan[8] - payan[7], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[5], payan[9] - payan[8], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[6], payan[10] - payan[9], teams);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].player[7], payan[11] - payan[10], teams);
        fseek(teams, 1, SEEK_CUR);
        fscanf(teams, "%d", &allteam[i].cup);
        fseek(teams, 1, SEEK_CUR);
        fscanf(teams, "%d", &allteam[i].submitsquad);
        fseek(teams, 1, SEEK_CUR);
        fgets(allteam[i].ID, payan[14] - payan[13], teams);
        fseek(teams, 1, SEEK_CUR);
    }
    fclose(teams);

    //read users file
    users = fopen("users.txt", "r");
    for (int i = 0; i < count1; i++)
    {
        int t = 0;
        while (t != 4)
        {
            if (fgetc(users) == ',')
            {
                payan5[t] = ftell(users);
                t += 1;
            }
        }
        fseek(users, payan5[0], SEEK_SET);
        fgets(alluser[i].users, payan5[1] - payan5[0], users);
        fseek(users, 1, SEEK_CUR);
        fgets(alluser[i].email, payan5[2] - payan5[1], users);
        fseek(users, 1, SEEK_CUR);
        fgets(alluser[i].passworld, payan5[3] - payan5[2], users);
        fseek(users, 1, SEEK_CUR);
    }
    fclose(users);


    //read player from file
    players = fopen("player.txt", "r");
    for (int i = 0; i < count; i++)
    {
        int t = 0;
        while (t != 7)
        {
            if (fgetc(players) == ',')
            {
                payan1[t] = ftell(players);
                t += 1;
            }
        }

        fseek(players, payan1[0], SEEK_SET);
        fgets(allplayer[i].name, payan1[1] - payan1[0], players);
        fseek(players, 1, SEEK_CUR);
        fgets(allplayer[i].teamname, payan1[2] - payan1[1], players);
        fseek(players, 1, SEEK_CUR);
        fscanf(players, "%d", &allplayer[i].attackpower);
        fseek(players, 1, SEEK_CUR);
        fscanf(players, "%d", &allplayer[i].defencepower);
        fseek(players, 1, SEEK_CUR);
        fscanf(players, "%d", &allplayer[i].value);
        fseek(players, 1, SEEK_CUR);
        fgets(allplayer[i].ID, payan1[6] - payan1[5], players);
        fseek(players, 1, SEEK_CUR);

    }
    fclose(players);


    //read league from file
    league = fopen("league.txt", "r");
    fseek(league, 0, SEEK_SET);
    if (fgetc(league) == ',')
    {
        fclose(league);
        league = fopen("league.txt", "r");
        for (int i = 0; i < 4; i++)
        {
            int t = 0;
            while (t != 26)
            {
                if (fgetc(players) == ',')
                {
                    payan2[t] = ftell(players);
                    t += 1;
                }
            }
            fseek(league, payan2[0], SEEK_SET);
            fgets(teamleague[i].teamname, payan2[1] - payan2[0], league);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].played);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].won);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].draw);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].lost);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].GF);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].GA);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].GD);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].score);
            fseek(league, 1, SEEK_CUR);
            fgets(teamleague[i].RWF, payan2[10] - payan2[9], league);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerRWF[0]);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerRWF[1]);
            fseek(league, 1, SEEK_CUR);
            fgets(teamleague[i].LWF, payan2[13] - payan2[12], league);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerLWF[0]);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerLWF[1]);
            fseek(league, 1, SEEK_CUR);
            fgets(teamleague[i].RD, payan2[16] - payan2[15], league);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerRD[0]);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerRD[1]);
            fseek(league, 1, SEEK_CUR);
            fgets(teamleague[i].LD, payan2[19] - payan2[18], league);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerLD[0]);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerLD[1]);
            fseek(league, 1, SEEK_CUR);
            fgets(teamleague[i].GK, payan2[22] - payan2[21], league);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerGK[0]);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].powerGK[1]);
            fseek(league, 1, SEEK_CUR);
            fscanf(league, "%d", &teamleague[i].submitsquad);
            fseek(league, 1, SEEK_CUR);
        }
        fclose(league);
    }

    //read league information
    leagueinfor = fopen("leagueinfo.txt", "r");

    if (fgetc(leagueinfor) != EOF)
    {
        fseek(leagueinfor, 0, SEEK_SET);
        fscanf(leagueinfor, "%d", &leagueinfo.weekith);
        fseek(leagueinfor, 1, SEEK_CUR);
        fscanf(leagueinfor, "%d", &leagueinfo.openclosetransfer);
        fseek(leagueinfor, 1, SEEK_CUR);
        fscanf(leagueinfor, "%d", &leagueinfo.endofleague);
        fseek(leagueinfor, 1, SEEK_CUR);
    }
    fclose(leagueinfor);

    //read khaste player
    khastefile = fopen("khaste.txt", "r");
    fseek(khastefile, 0, SEEK_SET);
    if (fgetc(khastefile) == ',')
    {
        fclose(khastefile);
        khastefile = fopen("khaste.txt", "r");
        for (int i = 0; i < 20; i++)
        {
            int t = 0;
            while (t != 4)
            {
                if (fgetc(khastefile) == ',')
                {
                    payan3[t] = ftell(khastefile);
                    t += 1;
                }
            }
            fseek(khastefile, payan3[0], SEEK_SET);
            fgets(allkhaste[i].playarname, payan3[1] - payan3[0], khastefile);
            fseek(khastefile, 1, SEEK_CUR);
            fscanf(khastefile, "%d", &allkhaste[i].powerplayer[0]);
            fseek(khastefile, 1, SEEK_CUR);
            fscanf(khastefile, "%d", &allkhaste[i].powerplayer[1]);
            fseek(khastefile, 1, SEEK_CUR);
        }
    }
    fclose(khastefile);


    //read baziha file
    baziha = fopen("baziha.txt", "r");
    fseek(baziha, 0, SEEK_SET);
    if (fgetc(baziha) == ',')
    {
        fclose(baziha);
        baziha = fopen("baziha.txt", "r");
        for (int i = 0; i < 6; i++)
        {
            int t = 0;
            while (t != 5)
            {
                if (fgetc(baziha) == ',')
                {
                    payan4[t] = ftell(baziha);
                    t += 1;
                }
            }
            fseek(baziha, payan4[0], SEEK_SET);
            fscanf(baziha, "%d", &allweek[i].play[0]);
            fseek(baziha, 1, SEEK_CUR);
            fscanf(baziha, "%d", &allweek[i].play[1]);
            fseek(baziha, 1, SEEK_CUR);
            fscanf(baziha, "%d", &allweek[i].play[2]);
            fseek(baziha, 1, SEEK_CUR);
            fscanf(baziha, "%d", &allweek[i].play[3]);
            fseek(baziha, 1, SEEK_CUR);
        }
    }
    
    //read goal file
    league = fopen("league.txt", "r");
    fseek(league, 0, SEEK_SET);
    if (fgetc(league) == ',')
    {
        fclose(league);
        goal = fopen("goal.txt", "r");
        for (int i = 0; i < 6; i++)
        {
            int t = 0;
            while (t != 5)
            {
                if (fgetc(goal) == ',')
                {
                    payan6[t] = ftell(goal);
                    t += 1;
                }
            }
            fseek(goal, payan6[0], SEEK_SET);
            fgets(allgoal[i].bazi[0], payan6[1] - payan6[0], goal);
            fseek(goal, 1, SEEK_CUR);
            fgets(allgoal[i].bazi[1], payan6[2] - payan6[1], goal);
            fseek(goal, 1, SEEK_CUR);
            fgets(allgoal[i].bazi[2], payan6[3] - payan6[2], goal);
            fseek(goal, 1, SEEK_CUR);
            fgets(allgoal[i].bazi[3], payan6[4] - payan6[3], goal);
            fseek(goal, 1, SEEK_CUR);
        }
        fclose(goal);
    }
    return 0;
}


int savinggame()
{
    //saving teams file
    Counting();
    teams = fopen("teames.txt", "w");

    for (int i = 0; i < count1; i++)
    {
        fputc(',', teams);
        fputs(allteam[i].teamname, teams);
        fputc(',', teams);
        fputs(allteam[i].email, teams);
        fputc(',', teams);
        fprintf(teams, "%d", allteam[i].money);
        fputc(',', teams);
        for (int j = 0; j < 8; j++)
        {
            fputs(allteam[i].player[j], teams);
            fputc(',', teams);
        }
        fprintf(teams, "%d", allteam[i].cup);
        fputc(',', teams);
        fprintf(teams, "%d", allteam[i].submitsquad);
        fputc(',', teams);
        fputs(allteam[i].ID, teams);
        fputc(',', teams);
        fputc('\n', teams);
    }
    fclose(teams);

    //saving users
    users = fopen("users.txt", "w");
    for (int i = 0; i < count1; i++)
    {
        fputc(',', users);
        fputs(alluser[i].users, users);
        fputc(',', users);
        fputs(alluser[i].email, users);
        fputc(',', users);
        fputs(alluser[i].passworld, users);
        fputc(',', teams);
        fputc('\n', teams);
    }
    fclose(users);


    //saving player file
    players = fopen("player.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fputc(',', players);
        fputs(allplayer[i].name, players);
        fputc(',', players);
        fputs(allplayer[i].teamname, players);
        fputc(',', players);
        fprintf(players,"%d",allplayer[i].attackpower);
        fputc(',', players);
        fprintf(players, "%d", allplayer[i].defencepower);
        fputc(',', players);
        fprintf(players, "%d", allplayer[i].value);
        fputc(',', players);
        fputs(allplayer[i].ID, players);
        fputc(',', players);
        fputc('\n', players);
    }
    fclose(players);

    //saving league
    league = fopen("league.txt", "r");
    fseek(league, 0, SEEK_SET);
    if (fgetc(league)==',')
    {
        fclose(league);
        league = fopen("league.txt", "w");
        for (int i = 0; i < 4; i++)
        {
            fputc(',', league);
            fputs(teamleague[i].teamname, league);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].played);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].won);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].draw);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].lost);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].GF);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].GA);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].GD);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].score);
            fputc(',', league);
            fputs(teamleague[i].RWF, league);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerRWF[0]);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerRWF[1]);
            fputc(',', league);
            fputs(teamleague[i].LWF, league);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerLWF[0]);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerLWF[1]);
            fputc(',', league);
            fputs(teamleague[i].RD, league);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerRD[0]);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerRD[1]);
            fputc(',', league);
            fputs(teamleague[i].LD, league);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerLD[0]);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerLD[1]);
            fputc(',', league);
            fputs(teamleague[i].GK, league);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerGK[0]);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].powerGK[1]);
            fputc(',', league);
            fprintf(league, "%d", teamleague[i].submitsquad);
            fputc(',', league);
            fputc('\n', league);
        }
        fclose(league);
    }

    //saving league information
    leagueinfor = fopen("leagueinfo.txt", "w");
    fprintf(leagueinfor, "%d%c%d%c%d%c", leagueinfo.weekith, ',', leagueinfo.openclosetransfer, ',', leagueinfo.endofleague, ',');
    fclose(leagueinfor);

    //saving  teamkeshi
    league = fopen("league.txt", "r");
    fseek(league, 0, SEEK_SET);
    if (fgetc(league) == ',')
    {
        fclose(league);
        baziha = fopen("baziha.txt", "w");
        for (int i = 0; i < 6; i++)
        {

            
            fputc(',', baziha);
            fprintf(baziha, "%d", allweek[i].play[0]);
            fputc(',', baziha);
            fprintf(baziha, "%d", allweek[i].play[1]);
            fputc(',', baziha);
            fprintf(baziha, "%d", allweek[i].play[2]);
            fputc(',', baziha);
            fprintf(baziha, "%d", allweek[i].play[3]);
            fputc(',', baziha);
            fputc('\n', baziha);
        }
    }
    fclose(baziha);

    //saving goals
    league = fopen("league.txt", "r");
    fseek(league, 0, SEEK_SET);
    if (fgetc(league) == ',')
    {
        fclose(league);
        goal = fopen("goal.txt", "w");
        for (int i = 0; i < 6; i++)
        {
            fputc(',', goal);
            fputs(allgoal[i].bazi[0], goal);
            fputc(',', goal);
            fputs(allgoal[i].bazi[1], goal);
            fputc(',', goal);
            fputs(allgoal[i].bazi[2], goal);
            fputc(',', goal);
            fputs(allgoal[i].bazi[3], goal);
            fputc(',', goal);
            fputc('\n', goal);
        }
        fclose(goal);
    }
    return 0;
}


int startweeki()
{
    int weekithe = leagueinfo.weekith;
    if (weekithe == 7)
    {
        printf("fasl tamoome\n");  
    }
    else
    {
        int a = allweek[weekithe-1].play[0];
        int b = allweek[weekithe-1].play[1];
        int c = allweek[weekithe-1].play[2];
        int d = allweek[weekithe-1].play[3];

        //show lineup
        if ((strcmp(teamleague[a].teamname, teamleague[currentleagueteam].teamname) == 0) || (strcmp(teamleague[b].teamname, teamleague[currentleagueteam].teamname) == 0) || (strcmp(input, "admin") == 0))
        {
            UpcomingOpponent(a, b);
        }
        if ((strcmp(teamleague[c].teamname, teamleague[currentleagueteam].teamname) == 0) || (strcmp(teamleague[d].teamname, teamleague[currentleagueteam].teamname) == 0) || (strcmp(input, "admin") == 0))
        {
            UpcomingOpponent(c, d);
        }



        //start weeck i-th
        if (strcmp(input, "admin") == 0)
        {
            if (teamleague[a].submitsquad == 1 && teamleague[b].submitsquad == 1 && teamleague[c].submitsquad == 1 && teamleague[d].submitsquad == 1)
            {
                khastefile = fopen("khaste.txt", "w");
                
                //kam shodan ghodrat bazikona -5
                if (weekithe == 3 || weekithe == 6)
                {
                    khastefile = fopen("khaste.txt", "w");
                    fclose(khastefile);
                   
                }
                else
                {
                    khasteh(a);
                    khasteh(b);
                }
                play(a, b);
                //saving goal 
                char snum[5];
                itoa(goala, snum, 10);
                strcpy(allgoal[weekithe - 1].bazi[0], snum);
                char snum1[5];
                itoa(goalb, snum1, 10);
                strcpy(allgoal[weekithe - 1].bazi[1], snum1);

                //saving game
                updatingtable(a, b, goala, goalb);

                //savinggame();inobardar aakhar
                printf("______________________________________________________________________________________________________________________\n");
                printf("%s| %d - %d |%s\n", teamleague[a].teamname, goala, goalb, teamleague[b].teamname);


                play(c, d);

                //saving goal 
                char snum2[5];
                itoa(goala, snum2, 10);
                strcpy(allgoal[weekithe - 1].bazi[2], snum2);
                char snum3[5];
                itoa(goalb, snum3, 10);
                strcpy(allgoal[weekithe - 1].bazi[3], snum3);

                //saving game
                updatingtable(c, d, goala, goalb);
                //savinggame();
                printf("%s| %d - %d |%s\n", teamleague[c].teamname, goala, goalb, teamleague[d].teamname);
                printf("______________________________________________________________________________________________________________________\n");
                if (weekithe == 3 || weekithe == 6)
                {
                    khastefile = fopen("khaste.txt", "w");
                    fclose(khastefile);
                }
                else
                {
                    khasteh(c);
                    khasteh(d);
                }
                for (int i = 0; i < 4; i++)
                {
                    teamleague[i].submitsquad = 0;
                }
                leagueinfo.weekith += 1;
                fclose(khastefile);
            }
            else
            {
                printf("teams in not ready\n");
            }
            savinggame();
        }
        
    }
    printf("1-countinue\n");
    int contin = 0;
    scanf("%d", &contin);
    return 0;
}
    

int play(int a, int b)
{
    goala = 0;
    goalb = 0;

    goala = ((teamleague[a].powerRWF[0] + teamleague[a].powerLWF[0] + teamleague[a].powerRD[0] + teamleague[a].powerLD[0] + teamleague[a].powerGK[0]) - (teamleague[b].powerRWF[1] + teamleague[b].powerLWF[1] + teamleague[b].powerRD[1] + teamleague[b].powerLD[1] + teamleague[b].powerGK[1])) / 100;
    goalb = ((teamleague[b].powerRWF[0] + teamleague[b].powerLWF[0] + teamleague[b].powerRD[0] + teamleague[b].powerLD[0] + teamleague[b].powerGK[0]) - (teamleague[a].powerRWF[1] + teamleague[a].powerLWF[1] + teamleague[a].powerRD[1] + teamleague[a].powerLD[1] + teamleague[a].powerGK[1])) / 100;

    if (goala < 0)
    {
        goala = 0;
    }

    if (goalb < 0)
    {
        goalb = 0;
    }
    return 0;
}


int UpcomingOpponent(int a, int b)
{
    if (teamleague[a].submitsquad == 1 || teamleague[b].submitsquad == 1)
    {
        if (teamleague[a].submitsquad == 1)
        {
            printf("sum of team Defencing power %s:%d\n", teamleague[a].teamname, teamleague[a].powerRWF[1] + teamleague[a].powerLWF[1] + teamleague[a].powerRD[1] + teamleague[a].powerLD[1] + teamleague[a].powerGK[1]);
            printf("sum of team Attacking power %s:%d\n", teamleague[a].teamname, teamleague[a].powerRWF[0] + teamleague[a].powerLWF[0] + teamleague[a].powerRD[0] + teamleague[a].powerLD[0] + teamleague[a].powerGK[0] );
            printf("\nsquad %s:\n_____________________________________________________________________________\n", teamleague[a].teamname);
            printf("%s/%sAP:(%d)%sDP:(%d)           %s%s/%sAP:(%d)%sDP:(%d) \n\n%s%s/%sAT:(%d)%sDP:(%d)           %s%s/%sAP:(%d)%sDP:(%d) \n\n         %s|%s|%sAP:(%d)%sDP:(%d)%s       \n-----------------------------------------------------\n", teamleague[a].RWF, KRED, teamleague[a].powerRWF[0], KCYN, teamleague[a].powerRWF[1], KNRM, teamleague[a].LWF, KRED, teamleague[a].powerLWF[0], KCYN, teamleague[a].powerLWF[1], KNRM, teamleague[a].RD, KRED, teamleague[a].powerRD[0], KCYN, teamleague[a].powerRD[1], KNRM, teamleague[a].LD, KRED, teamleague[a].powerLD[0], KCYN, teamleague[a].powerLD[1], KNRM, teamleague[a].GK, KRED, teamleague[a].powerGK[0], KCYN, teamleague[a].powerGK[1], KNRM);
        }
        if (teamleague[b].submitsquad == 1)
        {
            printf("sum of team Defencing power %s:%d\n", teamleague[b].teamname, teamleague[b].powerRWF[1] + teamleague[b].powerLWF[1] + teamleague[b].powerRD[1] + teamleague[b].powerLD[1] + teamleague[b].powerGK[1]);
            printf("sum of team Attacking power %s:%d\n", teamleague[b].teamname, teamleague[b].powerRWF[0] + teamleague[b].powerLWF[0] + teamleague[b].powerRD[0] + teamleague[b].powerLD[0] + teamleague[b].powerGK[0]);
            printf("\nsquad %s:\n_____________________________________________________________________________\n", teamleague[b].teamname);
            printf("%s/%sAP:(%d)%sDP:(%d)           %s%s/%sAP:(%d)%sDP:(%d) \n\n%s%s/%sAT:(%d)%sDP:(%d)           %s%s/%sAP:(%d)%sDP:(%d) \n\n         %s|%s|%sAP:(%d)%sDP:(%d)%s        \n-----------------------------------------------------\n", teamleague[b].RWF, KRED, teamleague[b].powerRWF[0], KCYN, teamleague[b].powerRWF[1], KNRM, teamleague[b].LWF, KRED, teamleague[b].powerLWF[0], KCYN, teamleague[b].powerLWF[1], KNRM, teamleague[b].RD, KRED, teamleague[b].powerRD[0], KCYN, teamleague[b].powerRD[1], KNRM, teamleague[b].LD, KRED, teamleague[b].powerLD[0], KCYN, teamleague[b].powerLD[1], KNRM, teamleague[b].GK, KRED, teamleague[b].powerGK[1], KCYN, teamleague[b].powerGK[1], KNRM);
        }
    }
    else
    {
        printf("the teams (%s or %s) did not select their squad\n", teamleague[a].teamname, teamleague[b].teamname);
    }
    return 0;
}


int updatingtable(int a ,int b , int c, int d)
{
    if (c > d)
    {
        teamleague[a].played += 1;
        teamleague[b].played += 1;

        teamleague[a].won += 1;
        teamleague[b].lost += 1;

        teamleague[a].GF += c;
        teamleague[b].GF += d;

        teamleague[a].GA += d;
        teamleague[b].GA += c;

        teamleague[a].GD = teamleague[a].GD + (c - d);
        teamleague[b].GD = teamleague[b].GD + (d - c);

        teamleague[a].score += 3;
        for(int i=0;i<count1;i++)
        {
            if (strcmp(teamleague[a].teamname, allteam[i].teamname) == 0)
            {
                allteam[i].money += 5;
            }
        }
        for (int i = 0; i < count1; i++)
        {
            if (strcmp(teamleague[b].teamname, allteam[i].teamname) == 0)
            {
                allteam[b].money += 1;
            }
        }
        
    }
    else if (c == d)
    {
        teamleague[a].played += 1;
        teamleague[b].played += 1;

        teamleague[a].draw += 1;
        teamleague[b].draw += 1;

        teamleague[a].GF += c;
        teamleague[b].GF += d;

        teamleague[a].GA += d;
        teamleague[b].GA += c;

        teamleague[a].score += 1;
        teamleague[b].score += 1;
        for (int i = 0; i < count1; i++)
        {
            if (strcmp(teamleague[a].teamname, allteam[i].teamname) == 0)
            {
                allteam[i].money += 3;
            }
        }
        for (int i = 0; i < count1; i++)
        {
            if (strcmp(teamleague[b].teamname, allteam[i].teamname) == 0)
            {
                allteam[b].money += 3;
            }
        }
    }
    else if (d > c)
    {
        teamleague[b].played += 1;
        teamleague[a].played += 1;

        teamleague[b].won += 1;
        teamleague[a].lost += 1;

        teamleague[b].GF += d;
        teamleague[a].GF += c;

        teamleague[b].GA += c;
        teamleague[a].GA += d;

        teamleague[b].GD = teamleague[a].GD + (d - c);
        teamleague[a].GD = teamleague[b].GD + (c - d);

        teamleague[b].score += 3;
        for (int i = 0; i < count1; i++)
        {
            if (strcmp(teamleague[a].teamname, allteam[i].teamname) == 0)
            {
                allteam[i].money += 1;
            }
        }
        for (int i = 0; i < count1; i++)
        {
            if (strcmp(teamleague[b].teamname, allteam[i].teamname) == 0)
            {
                allteam[b].money += 5;
            }
        }
    }
    return 0;
}


int khasteh(int a)
{

    //injaghodratarokamkon
    teamleague[a].powerRWF[0] -= 5;
    teamleague[a].powerRWF[1] -= 5;

    teamleague[a].powerLWF[0] -= 5;
    teamleague[a].powerLWF[1] -= 5;

    teamleague[a].powerRD[0] -= 5;
    teamleague[a].powerRD[1] -= 5;

    teamleague[a].powerLD[0] -= 5;
    teamleague[a].powerLD[1] -= 5;

    teamleague[a].powerGK[0] -= 5;
    teamleague[a].powerGK[1] -= 5;

    khastefile = fopen("khaste.txt", "a");
    fputc(',', khastefile);
    fputs(teamleague[a].RWF,khastefile);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerRWF[0]);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerRWF[1]);
    fputc(',', khastefile);
    fputc('\n', khastefile);

    fputc(',', khastefile);
    fputs(teamleague[a].LWF, khastefile);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerLWF[0]);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerLWF[1]);
    fputc(',', khastefile);
    fputc('\n', khastefile);

    fputc(',', khastefile);
    fputs(teamleague[a].RD, khastefile);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerRD[0]);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerRD[1]);
    fputc(',', khastefile);
    fputc('\n', khastefile);

    fputc(',', khastefile);
    fputs(teamleague[a].LD, khastefile);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerLD[0]);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerLD[1]);
    fputc(',', khastefile);
    fputc('\n', khastefile);

    fputc(',', khastefile);
    fputs(teamleague[a].GK, khastefile);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerGK[0]);
    fputc(',', khastefile);
    fprintf(khastefile, "%d", teamleague[a].powerGK[1]);
    fputc(',', khastefile);
    fputc('\n', khastefile);
    fclose(khastefile);
    
    return 0;
}


int teamkeshi()
{
    time_t t;
    srand((unsigned)time(&t));
    int arry[4] = { 0,1,2,3 };


    do
    {
        teama = (rand() % 4);
    } while (arry[teama] == -1);

    allweek[0].play[0] = arry[teama];
    allweek[1].play[0] = arry[teama];
    allweek[2].play[0] = arry[teama];
    arry[teama] = -1;

    do
    {
        teamb = (rand() % 4);
    } while (arry[teamb] == -1);

    allweek[0].play[2] = arry[teamb];
    allweek[1].play[2] = arry[teamb];
    allweek[2].play[1] = arry[teamb];
    arry[teamb] = -1;

    do
    {
        teamc = (rand() % 4);
    } while (arry[teamc] == -1);
    allweek[0].play[1] = arry[teamc];

    do
    {
        teamd = (rand() % 4);
    } while (arry[teamd] == -1 || arry[teamd] == allweek[0].play[1]);
    allweek[0].play[3] = arry[teamd];

    do
    {
        teamc = (rand() % 4);
    } while (arry[teamc] == -1 || arry[teamc] == allweek[0].play[1]);
    allweek[1].play[1] = arry[teamc];

    do
    {
        teamd = (rand() % 4);
    } while (arry[teamd] == -1 || arry[teamd] == allweek[1].play[1]);
    allweek[1].play[3] = arry[teamd];

    allweek[2].play[2] = allweek[1].play[1];
    allweek[2].play[3] = allweek[1].play[3];



    //nim fasl dovom
    int arr[4] = { 0,1,2,3 };


    do
    {
        teama = (rand() % 4);
    } while (arr[teama] == -1);

    allweek[3].play[0] = arr[teama];
    allweek[4].play[0] = arr[teama];
    allweek[5].play[0] = arr[teama];
    arr[teama] = -1;

    do
    {
        teamb = (rand() % 4);
    } while (arr[teamb] == -1);

    allweek[3].play[2] = arr[teamb];
    allweek[4].play[2] = arr[teamb];
    allweek[5].play[1] = arr[teamb];
    arr[teamb] = -1;

    do
    {
        teamc = (rand() % 4);
    } while (arr[teamc] == -1);
    allweek[3].play[1] = arr[teamc];

    do
    {
        teamd = (rand() % 4);
    } while (arr[teamd] == -1 || arr[teamd] == allweek[3].play[1]);
    allweek[3].play[3] = arr[teamd];

    do
    {
        teamc = (rand() % 4);
    } while (arr[teamc] == -1 || arr[teamc] == allweek[3].play[1]);
    allweek[4].play[1] = arr[teamc];

    do
    {
        teamd = (rand() % 4);
    } while (arr[teamd] == -1 || arr[teamd] == allweek[4].play[1]);
    allweek[4].play[3] = arr[teamd];

    allweek[5].play[2] = allweek[4].play[1];
    allweek[5].play[3] = allweek[4].play[3];
    return 0;
}


int winner()
{
    int a = 0, b = 1, c = 2, d = 3;
    int standing[4] = { a,b,c,d };
    int temp = 0;
    printf("%steamname  |  played  |  won  |  draw  |  lose  | GF | GA | GD |  score  |%s\n", KCYN, KNRM);
    for (int j = 0, i = 0; j < 4; j++)
    {
        int p = i;
        for (int l = 0; l < 4, i + 1 < 4; l++, i++)
        {
            if (teamleague[standing[j]].score < teamleague[standing[i + 1]].score)
            {
                temp = standing[i + 1];
                standing[i + 1] = standing[j];
                standing[j] = temp;
            }
            else if (teamleague[standing[j]].score == teamleague[standing[i + 1]].score)
            {
                if (teamleague[standing[j]].GD < teamleague[standing[i + 1]].GD)
                {
                    temp = standing[i + 1];
                    standing[i + 1] = standing[j];
                    standing[j] = temp;
                }
                else if (teamleague[standing[j]].GD == teamleague[standing[i + 1]].GD)
                {
                    if (teamleague[standing[j]].GF < teamleague[standing[i + 1]].GF)
                    {
                        temp = standing[i + 1];
                        standing[i + 1] = standing[j];
                        standing[j] = temp;
                    }
                    else if (teamleague[standing[j]].GF == teamleague[standing[i + 1]].GF)
                    {
                        if (teamleague[standing[j]].GA >= teamleague[standing[i + 1]].GA)
                        {
                            temp = standing[i + 1];
                            standing[i + 1] = standing[j];
                            standing[j] = temp;
                        }
                    }
                }
            }
        }
        i = p;
        i++;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%s%s  %s|    %d    |    %d    |    %d    |    %d    | %d | %d | %d |    %d    |\n", KCYN, teamleague[standing[i]].teamname, KYEL, teamleague[standing[i]].played, teamleague[standing[i]].won, teamleague[standing[i]].draw, teamleague[standing[i]].lost, teamleague[standing[i]].GF, teamleague[standing[i]].GA, teamleague[standing[i]].GD, teamleague[standing[i]].score);
    }


    printf("%swienner is :%s%s\n",KGRN,teamleague[standing[0]].teamname,KNRM);
    printf("%s                    "
        "         .-=========-.  \n"
        "        \\'-=======-'/  \n"
        "         _|   .=.   |_  \n"
        "        ((|  {{1}}  |)) \n"
        "        \\|   /|\   |/  \n"
        "         \\__ '`' __/   \n"
        "            _`) (`_|    \n"
        "           _|_______|   \n"
        "         |____________| \n"
        "           %s           %s \n",KRED, teamleague[standing[0]].teamname,KNRM);

    for (int i = 0; i < count1; i++)
    {
        if (strcmp(teamleague[standing[0]].teamname, allteam[i].teamname) == 0)
        {
            allteam[i].cup += 1;
            break;
        }
    }
    league = fopen("league.txt", "w");
    fclose(league);
    leagueinfor = fopen("leagueinfo.txt", "w");
    fclose(leagueinfor);
    baziha = fopen("baziha.txt", "w");
    fclose(baziha);
    printf("%s1-back", KNRM);
    int countinue = 0;
    scanf("%d", &countinue);
    return 0;
}
