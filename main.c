#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

int con = 0;

typedef struct {            //사용하는 유저에 관한 구조체 태그
    long sol;
    long peo;
    double SP;
    long long tax;
    unsigned long tec;
    unsigned long eco;
    double feel;
    int CS;
    char name[10];
    int time[12];
    long Nano;
}User;
User U;
typedef struct {       //영토 설정에 관한 구조체 태그
    char country[10];
}Coun;
Coun C[13];
typedef struct {  //북한에 관한 구조체 태그
    long Nsol[12];
    double NSP;
    int def[12];
    long sol;
}North;
North N;
typedef struct {     //사용되는 돈과 관련
    unsigned long long mon[3][9]; /*
                    {
                        soldier
                        economy
                        technology
                    }
                    */
    long Nano[3];
    double tax[12];
}Money;
Money M;
typedef struct {     //행복도와 관련
    double feel[2][9]; /*
                        {
                            soldier
                            economy
                        }
                        */
}Feel;
Feel F;
typedef struct {    //인구 수와 관련
    unsigned long peo[2][9]; /*
                    {
                        solider
                        economy
                    }
                    */
}People;
People P;
typedef struct {   //경제력 및 기술력에 관련
    unsigned long eco[9];
    unsigned long tec[9];
    unsigned long Tec[9];
}EcoTec;
EcoTec E;
typedef struct {  //군사력에 관련
    unsigned long sol[9];
    int line;
}Soilder;
Soilder S;
void Set(void) {  //게임 시작에 필요한 설정들
    int register i = 0;
    U.sol = 50;
    U.peo = 5000;
    U.SP = 5.00;
    U.tax = 1000;
    U.tec = 0;
    U.eco = 0;
    U.CS = 1;
    U.feel = 50;
    U.Nano = 0;

    M.mon[0][0] = 100;
    M.mon[1][0] = 50;
    M.mon[2][0] = 2500;
    M.Nano[0] = 10000000;
    E.eco[0] = 1;
    E.tec[0] = 20;
    P.peo[1][0] = 10;
    P.peo[0][0] = 1;
    P.peo[2][0] = 1;
    F.feel[1][0] = 0.001;
    F.feel[0][0] = 0.001;
    S.sol[0] = 1;
    S.line = 0;
    E.Tec[0] = 1;

    M.tax[0] = 0.05;
    M.tax[1] = 0.08;
    M.tax[2] = 0.1;
    M.tax[3] = 0.12;
    M.tax[4] = 0.15;
    M.tax[5] = 0.2;
    M.tax[6] = 0.25;
    M.tax[7] = 0.3;
    M.tax[8] = 0.4;
    M.tax[9] = 0.5;
    M.tax[10] = 0.6;
    M.tax[11] = 0.8;

    N.Nsol[0] = 4;
    N.Nsol[1] = 12;
    N.Nsol[2] = 40;
    N.Nsol[3] = 135;
    N.Nsol[4] = 400;
    N.Nsol[5] = 1500;
    N.Nsol[6] = 3200;
    N.Nsol[7] = 12000;
    N.Nsol[8] = 70000;
    N.Nsol[9] = 125000;
    N.Nsol[10] = 500000;
    N.Nsol[11] = 1500000;

    strcpy_s(C[0].country, sizeof("제주"), "제주");
    strcpy_s(C[1].country, sizeof("부산"), "부산");
    strcpy_s(C[2].country, sizeof("광주"), "광주");
    strcpy_s(C[3].country, sizeof("울산"), "울산");
    strcpy_s(C[4].country, sizeof("대구"), "대구");
    strcpy_s(C[5].country, sizeof("대전"), "대전");
    strcpy_s(C[6].country, sizeof("서울"), "서울");
    strcpy_s(C[7].country, sizeof("원산"), "원산");
    strcpy_s(C[8].country, sizeof("함흥"), "함흥");
    strcpy_s(C[9].country, sizeof("청진"), "청진");
    strcpy_s(C[10].country, sizeof("신의주"), "신의주");
    strcpy_s(C[11].country, sizeof("개성"), "개성");
    strcpy_s(C[12].country, sizeof("평양"), "평양");

    for (i = 1; i < 9; i++) {
        if (i == 5)
            M.mon[2][i] = 5000000;
        else
            M.mon[2][i] = M.mon[2][i - 1] * 4;
    }
    for (i = 1; i < 9; i++) {
        if (i == 7)
            E.Tec[i] = 10000;
        else
            E.Tec[i] = E.Tec[i - 1] * 5;
    }
    for (i = 1; i < 9; i++) {
        if (i == 1)
            P.peo[2][i] = 2;
        else
            P.peo[2][i] = 0;
    }
    for (i = 1; i < 7; i++) {
        if (i < 5)
            E.tec[i] = E.tec[i - 1] * 5;
        else if (i == 6)
            E.tec[i] = 50000;
        else
            E.tec[i] = 100000;
    }
    for (i = 1; i < 3; i++)
        M.Nano[i] = M.Nano[i - 1] * 10;
    for (i = 1; i < 9; i++) {
        if (i == 1)
            P.peo[0][i] = 10;
        else if (i == 6)
            P.peo[0][i] = 100;
        else
            P.peo[0][i] = 0;
    }
    for (i = 1; i < 9; i++) {
        if (i < 5) {
            if (i % 2 == 1)
                F.feel[0][i] = F.feel[0][i - 1] * 5;
            else
                F.feel[0][i] = F.feel[0][i - 1] * 2;
        }
        else
            if (i < 7) {
                if (i % 2 == 1)
                    F.feel[0][i] = F.feel[0][i - 1] * 2;
                else
                    F.feel[0][i] = F.feel[0][i - 1] * 5;
            }
            else if (i == 7)
                F.feel[0][i] = 0.5;
            else
                F.feel[0][i] = 1;
    }
    for (i = 0; i < 12; i++)  //북한군의 방어도 설정
        N.def[i] = 100;
    for (i = 0; i < 12; i++)   //세금징수 시간간격 설정
        U.time[i] = 0;
    for (i = 1; i < 9; i++) {   //군사 생산의 가격 설정
        if (i != 7)
            M.mon[0][i] = M.mon[0][i - 1] * 10;
        else
            M.mon[0][i] = 500000000;
    }
    for (i = 1; i < 9; i++)
        M.mon[1][i] = M.mon[1][i - 1] * 10;
    for (i = 1; i < 9; i++) {
        if (i == 7)
            E.eco[i] = 10000;
        else
            E.eco[i] = E.eco[i - 1] * 5;
    }
    for (i = 1; i < 9; i++) {
        if (i == 3)
            P.peo[1][i] = P.peo[1][i - 1] * 3;
        else if (i == 4)
            P.peo[1][i] = 1000;
        else if (i == 5)
            P.peo[1][i] = P.peo[1][i - 2] * 5;
        else if (i == 7)
            P.peo[1][i] = 50000;
        else
            P.peo[1][i] = P.peo[1][i - 1] * 5;
    }
    for (i = 1; i < 9; i++) {
        if (i == 3)
            F.feel[1][i] = 0.01;
        else if (i == 7)
            F.feel[1][i] = 5;
        else if (i == 8)
            F.feel[1][i] = F.feel[1][i - 1] * 2;
        else
            F.feel[1][i] = F.feel[1][i - 1] * 5;
    }
    for (i = 1; i < 9; i++) {
        if (i == 2)
            S.sol[i] = S.sol[i - 1] * 20;
        else if (i == 4)
            S.sol[i] = S.sol[i - 1] * 10;
        else if (i == 7)
            S.sol[i] = 2000000;
        else
            S.sol[i] = S.sol[i - 1] * 5;
    }

}

void Start(void);
void Menu(void);
void War_go(void);
int War_ready(int place);
int War_start(int place);
void get_Tax(void);
void make_Soldier(void);
void dev_Tech(void);
void dev_Eco(void);
void Store(void);
void Story(void);
void The_End(void);


int main(void) {
    Set();
    Start();
}

void Start(void) {  //게임 시작 화면
    int cho;
    system("cls");
    printf(" ______   |7|     _______    _______    |7|  _______   || ||\n");
    printf("_________ | |    |______ |  |_____  |   | | |_____  |  || ||\n");
    printf("  /77A    | |__        | |       / /  __| |      / /   ||0||\n");
    printf(" (    )   | |__| ______|_|_     /  A |__  |     /  A   || ||\n");
    printf("  V__/    | |   |____  ____|   / /V A   | |    /_/V_A  || ||\n");
    printf("  ||      |_|     __|__|_     /_/ _V_A  |_|         /77A\n");
    printf("  ||________     |_____  |       | |______         (    )\n");
    printf("  V_________|          |_|        V_______|         V__/\n\n\n");

    printf("--1. 게임시작--\n\n");
    printf("--2. 게임설명--\n\n");
    printf("--3. 게임종료--\n\n");

    printf("당신의 닉네임을 입력해주세요(10자 이하): ");
    scanf("%s", U.name);

    printf("\n실행하고 싶은 번호를 고르세요: ");
    scanf("%d", &cho);
    while (cho > 3 || cho < 1) {
        printf("다시 입력해주세요: ");
        scanf("%d", &cho);
    }
    if (cho == 1)
        Menu();
    else if (cho == 2)
        Story();
    else if (cho == 3)
        exit(1);
}
void Menu(void) {  //게임 메뉴
    int cho;
    system("cls");
    if (U.CS == 13)
        The_End();
    printf("----------<한국전쟁 메뉴>----------\n\n");
    printf("1. 전쟁 출격\n\n");
    printf("2. 세금 징수\n\n");
    printf("3. 군사 생산\n\n");
    printf("4. 기술 개발\n\n");
    printf("5. 경제 개발\n\n");
    printf("6. 힉스입자 상점\n\n");
    printf("ESC. 종료하기\n\n\n");

    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.3lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n", U.Nano);

    printf("실행하고 싶은 번호를 고르세요");
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            if (cho >= 49 && cho <= 54) {
                switch (cho) {
                case 49: War_go();
                case 50: get_Tax();
                case 51: make_Soldier();
                case 52: dev_Tech();
                case 53: dev_Eco();
                default: Store();
                }
            }
            else if (cho == 27)
                exit(1);
            else if (cho == 97) {
                U.sol += 10000000;
                U.peo += 10000000;
                U.SP = U.sol / 10;
                U.tax += 10000000;
                U.tec += 10000000;
                U.eco += 10000000;
                U.CS += 1;
                U.feel += 50;
                U.Nano += 10;
                Menu();
            }
        }
    }
}
void War_go(void) {  //전쟁출격 화면
    int i;
    int cho;
    system("cls");
    printf("----------<전쟁 출격>----------\n\n");
    printf("-본 영토- 제주 <점령됨>\n\n");
    for (i = 1; i < 13; i++) {
        printf("%d. %s", i, C[i].country);
        if (U.CS > i)
            printf("  <점령됨>");
        printf("\n\n");
    }
    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.3lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n", U.Nano);

    printf("\n점령하고 싶은 지역을 선택하세요.\n");
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            if (cho >= 49 && cho <= 57 || cho == 97 || cho == 115 || cho == 100) {
                switch (cho) {
                case 97:
                    if (U.CS > 10) {
                        printf("\n%s지역은 이미 점령한 지역입니다.\n", C[10].country);
                        break;
                    }
                    else if (U.CS == 10) {
                        War_ready(10);
                    }
                    else {
                        printf("\n먼저 이전지역을 점령해 주세요!\n");
                        break;
                    }
                case 115:
                    if (U.CS > 11) {
                        printf("\n%s지역은 이미 점령한 지역입니다.\n", C[11].country);
                        break;
                    }
                    else if (U.CS == 11) {
                        War_ready(11);
                    }
                    else {
                        printf("\n먼저 이전지역을 점령해 주세요!\n");
                        break;
                    }
                case 100:
                    if (U.CS > 12) {
                        printf("\n%s지역은 이미 점령한 지역입니다.\n", C[12].country);
                        break;
                    }
                    else if (U.CS == 12) {
                        War_ready(12);
                    }
                    else {
                        printf("\n먼저 이전지역을 점령해 주세요!\n");
                        break;
                    }

                default:
                    if (U.CS > cho - 48) {
                        printf("\n%s지역은 이미 점령한 지역입니다.\n", C[cho - 48].country);
                        break;
                    }
                    else if (U.CS == cho - 48) {
                        War_ready(cho - 48);
                    }
                    else {
                        printf("\n먼저 이전지역을 점령해 주세요!\n");
                        break;
                    }
                }
            }
            else if (cho == 27)
                Menu();
        }
    }

}
int War_ready(int place) {  //전쟁을 출격하기 위한 준비 함수
    int cho;
    N.sol = N.Nsol[place - 1];
    system("cls");
    printf("----------<전쟁 출격>----------\n\n");
    printf("현재 %s지역의 방어도: %d\n\n", C[place].country, N.def[place - 1]);
    printf("적의 군사력: %ld\n\n", N.Nsol[place - 1]);
    printf("      vs\n\n");
    printf("나의 군사력: %ld\n\n\n", U.sol);

    printf("전쟁개시(Enter를 누르세요)\n\n");
    printf("후퇴(ESC를 누르세요)\n\n");

    while (1) {
        if (_kbhit()) {
            cho = _getch();
            if (cho == 13) {
                system("cls");
                War_start(place);
            }
            else if (cho == 27)
                War_go();
        }
    }
}
int War_start(int place) {  //전쟁을 하는 함수
    system("cls");
    U.SP = (double)U.sol / 10;
    N.NSP = (double)N.sol / 10;
    printf("한국\n");
    printf("군사력: %ld\n", U.sol);
    printf("전투력: %f\n\n", U.SP);
    printf("      vs\n\n");
    printf("북한\n");
    printf("군사력: %ld\n", N.sol);
    printf("전투력: %f\n\n", N.NSP);

    if (S.line == 0) {
        S.line = 1;
        printf("북한군이 공격합니다!!\n");
        Sleep(2000);
        U.sol -= N.NSP;
        if (U.sol < 0)
            U.sol = 0;
        printf("한국군의 남은 군사는 %ld입니다.\n\n", U.sol);
        if (U.sol == 0) {
            printf("한국군의 군사가 0입니다. 전투에서 패배하였습니다.\n");
            printf("인구 수 -500\n");
            printf("행복도 - 5\n\n");
            system("pause");
            Menu();
        }
        Sleep(2000);
        War_start(place);
    }
    else
        S.line = 0;
    printf("한국군이 공격합니다!!\n");
    Sleep(2000);
    N.sol -= U.SP;
    if (N.sol < 0)
        N.sol = 0;
    if (N.sol == 0) {
        printf("북한군의 군사가 0입니다. 전투에서 승리하였습니다.\n\n");
        N.def[place - 1] -= 20;
        if (N.def[place - 1] == 0) {
            printf("점령성공!!!\n");
            U.CS += 1;
            system("pause");
            Menu();
        }
        else
            printf("전투 승리!!!\n");
        printf("적의 방어도를 20%%감소 시켰습니다. 현재 방어도: %d%%\n", N.def[place - 1]);
        system("pause");
        Menu();
    }
    printf("북한군의 남은 군사는 %ld입니다.\n\n", N.sol);
    Sleep(2000);
    War_start(place);
}
void get_Tax(void) {   //세금을 징수하는 함수
    int cho;
    int i;
    system("cls");
    printf("----------<세금 징수>----------\n\n");
    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.3lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n\n", U.Nano);
    printf("점령한 지역에서 세금을 징수하세요\n\n");
    while (1) {
        while (1) {
            if (_kbhit())
                break;
            Sleep(1);
            for (i = 0; i < 12; i++) {
                U.time[i] -= 1;
                if (U.time[i] < 0)
                    U.time[i] = 0;
            }
        }
        if (_kbhit()) {
            cho = _getch();
            if (cho >= 49 && cho <= 57 || cho == 97 || cho == 115 || cho == 100) {
                switch (cho) {
                case 97:
                    if (U.CS < 9) {
                        printf("점령되지 않은 지역입니다!!\n");
                        break;
                    }
                    if (U.time[9] > 0) {
                        printf("시간이 되지 않았습니다!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[9];
                    U.time[9] = 100;
                    get_Tax();
                case 115:
                    if (U.CS < 10) {
                        printf("점령되지 않은 지역입니다!!\n");
                        break;
                    }
                    if (U.time[10] > 0) {
                        printf("시간이 되지 않았습니다!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[10];
                    U.time[10] = 100;
                    get_Tax();
                case 100:
                    if (U.CS < 11) {
                        printf("점령되지 않은 지역입니다!!\n");
                        break;
                    }
                    if (U.time[11] > 0) {
                        printf("시간이 되지 않았습니다!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[11];
                    U.time[11] = 100;
                    get_Tax();
                default:
                    if (U.CS <= cho - 49) {
                        printf("점령되지 않은 지역입니다!!\n");
                        break;
                    }
                    if (U.time[cho - 49] > 0) {
                        printf("시간이 되지 않았습니다!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[cho - 49];
                    U.time[cho - 49] = 100;
                    get_Tax();
                }
            }
            else if (cho == 27)
                Menu();
        }
    }

}
void make_Soldier(void) {   //군사력을 증진하는 함수
    system("cls");
    int i;
    int cho;
    long long pay;
    double feel;
    long peo;
    long Nano;
    printf("----------<군사 생산>----------\n\n");
    printf("1.군인 징병\n");
    printf("-> 비용: 100\n");
    printf("-> 인구 수 -1, 군사력 +1, 행복도 -0.001\n\n");
    printf("2.특수부대 육성\n");
    printf("-> 비용: 1,000\n");
    printf("-> 인구 수 -10, 군사력 +200, 행복도 -0.005\n\n");
    printf("3.탱크 생산\n\n");
    printf("-> 비용: 10,000\n");
    printf("-> 군사력 +1000, 행복도 -0.01\n");
    printf("-> <기술력 200이상>\n\n");
    printf("4.전투기 생산\n\n");
    printf("-> 비용: 100,000\n");
    printf("-> <기술력 1000이상>\n\n");
    printf("-> 군사력 +10000, 행복도 -0.05\n\n");
    printf("5.항공모함 생산\n\n");
    printf("-> 비용: 1,000,000\n");
    printf("-> <기술력 5000이상>\n\n");
    printf("-> 군사력 +50000, 행복도 -0.1\n\n");
    printf("6.무인 드론 전투기 생산\n\n");
    printf("-> 비용: 10,000,000\n");
    printf("-> <기술력 25000이상>\n\n");
    printf("-> 군사력 +250000, 행복도 -0.2\n\n");
    printf("7.핵무기 생산\n\n");
    printf("-> 비용: 100,000,000\n");
    printf("-> 인구 수 -100, 군사력 +1250000, 행복도 -1\n\n");
    printf("-> <기술력 50000이상>\n\n");
    printf("8.전투 로봇 생산\n\n");
    printf("-> 비용: 500,000,000\n");
    printf("-> 군사력 +2,000,000, 행복도 -0.5, <힉스입자 1개 필요>\n\n");
    printf("9.거대 모선 생산\n\n");
    printf("-> 비용: 5,000,000,000\n");
    printf("-> 군사력 +10,000,000, 행복도 -1, <힉스입자 2개 필요>\n\n\n");

    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.3lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n", U.Nano);
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            for (i = 49; i <= 55; i++) {
                if (cho == i) {
                    pay = U.tax - M.mon[0][i - 49];
                    feel = U.feel - F.feel[0][i - 49];
                    peo = U.peo - P.peo[0][i - 49];
                    if (pay < 0 || feel < 0)
                        break;
                    else {
                        U.tax -= M.mon[0][i - 49];
                        U.sol += S.sol[i - 49];
                        U.SP = (double)U.sol / 10;
                        U.feel -= F.feel[0][i - 49];
                        U.peo -= P.peo[0][i - 49];
                        make_Soldier();
                    }
                }
            }
            if (cho == 27)
                Menu();
            if (cho == 56) {
                pay = U.tax - M.mon[0][cho - 49];
                feel = U.feel - F.feel[0][i - 49];
                Nano = U.Nano - 1;
                if (pay < 0 || feel < 0 || Nano < 0)
                    break;
                else {
                    U.tax -= M.mon[0][i - 49];
                    U.sol += S.sol[i - 49];
                    U.SP = (double)U.sol / 10;
                    U.feel -= F.feel[0][i - 49];
                    U.Nano -= 1;
                    make_Soldier();
                }
            }
            else if (cho == 57) {
                pay = U.tax - M.mon[0][cho - 49];
                feel = U.feel - F.feel[0][i - 49];
                Nano = U.Nano - 2;
                if (pay < 0 || feel < 0 || Nano < 0)
                    break;
                else {
                    U.tax -= M.mon[0][i - 49];
                    U.sol += S.sol[i - 49];
                    U.SP = (double)U.sol / 10;
                    U.feel -= F.feel[0][i - 49];
                    U.Nano -= 2;
                    make_Soldier();
                }
            }

        }
    }
}
void dev_Tech(void) {
    system("cls");
    int i;
    int cho;
    long long pay;
    long Nano;
    printf("----------<기술력 개발>----------\n\n");
    printf("1. 연구원 모집\n");
    printf("-> 비용: 2,500\n");
    printf("-> 인구 수 -1, 기술력 +1, <경제력 20이상>\n\n");
    printf("2. 연구 센터 건설\n");
    printf("-> 비용: 10,000\n");
    printf("-> 인구 수 -2, 기술력 +5, <경제력 100이상>\n\n");
    printf("3. 기초과학 연구\n\n");
    printf("-> 비용: 40,000\n");
    printf("-> 기술력 +25, <경제력 500이상>\n\n");
    printf("4. 심화과학 연구\n\n");
    printf("-> 비용: 160,000\n");
    printf("-> 기술력 +75, <경제력 2500이상>\n\n");
    printf("5. 공학기술 연구\n\n");
    printf("-> 비용: 740,000\n");
    printf("-> 기술력 +225, <경제력 12500이상>\n\n");
    printf("6. 무기공학 개발\n\n");
    printf("-> 비용: 5,000,000\n");
    printf("-> 기술력 +1125, <기술력 50000이상>\n\n");
    printf("7. 첨단공학 연구\n\n");
    printf("-> 비용: 20,000,000\n");
    printf("-> 기술력 +5625 <기술력 100000이상>\n\n");
    printf("8. 미래공학 연구\n\n");
    printf("-> 비용: 100,000,000\n");
    printf("-> 기술력 +10000, <힉스입자 1개 필요>\n\n");
    printf("9. 시공간도약기술 개발\n\n");
    printf("-> 비용: 4,000,000,000\n");
    printf("-> 기술력 +50,000, <힉스입자 2개 필요>\n\n\n");

    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.3lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n", U.Nano);
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            for (i = 49; i <= 57; i++) {
                if (cho == i) {
                    pay = U.tax - M.mon[2][i - 49];
                    if (pay < 0)
                        break;
                    if (i - 49 < 5) {
                        if (U.eco >= E.tec[i - 49]) {
                            U.tax -= M.mon[2][i - 49];
                            U.tec += E.Tec[i - 49];
                            U.peo -= P.peo[2][i - 49];
                            dev_Tech();
                        }
                        else
                            break;
                    }
                    else if (i - 49 >= 5 && i - 49 < 7) {
                        if (U.tec >= E.tec[i - 49]) {
                            U.tax -= M.mon[2][i - 49];
                            U.tec += E.Tec[i - 49];
                            U.peo -= P.peo[2][i - 49];
                            dev_Tech();
                        }
                    }
                    else {
                        if (i - 49 == 7) {
                            Nano = U.Nano - 1;
                            if (pay < 0 || Nano < 0)
                                break;
                            else {
                                U.tax -= M.mon[2][i - 49];
                                U.tec += E.Tec[i - 49];
                                U.Nano -= 1;
                                dev_Tech();
                            }
                        }
                        else {
                            Nano = U.Nano - 2;
                            if (pay < 0 || Nano < 0)
                                break;
                            else {
                                U.tax -= M.mon[2][i - 49];
                                U.tec += E.Tec[i - 49];
                                U.Nano -= 2;
                                dev_Tech();
                            }
                        }
                    }
                }
            }
            if (cho == 27)
                Menu();
        }
    }
}
void dev_Eco(void) {
    system("cls");
    int i;
    int cho;
    long long pay;
    long Nano;
    printf("----------<경제 개발>----------\n\n");
    printf("1. 주택 건설\n");
    printf("-> 비용: 50\n");
    printf("-> 인구 수 +10, 경제력 +1, 행복도 +0.001\n\n");
    printf("2. 마을 건설\n");
    printf("-> 비용: 500\n");
    printf("-> 인구 수 +50, 경제력 +5, 행복도 +0.005\n\n");
    printf("3. 도시 건설\n\n");
    printf("-> 비용: 5,000\n");
    printf("-> 인구 수 +250, 경제력 +25, 행복도 +0.025\n\n");
    printf("4. 상업시설 건설\n\n");
    printf("-> 비용: 50,000\n");
    printf("-> 인구 수 +750, 경제력 +75, 행복도 +0.01\n\n");
    printf("5. 문화시설 건설\n\n");
    printf("-> 비용: 500,000\n");
    printf("-> 인구 수 +1,000, 경제력 +225, 행복도 +0.05\n\n");
    printf("6. 무역시설 건설\n\n");
    printf("-> 비용: 5,000,000\n");
    printf("-> 인구 수 +3750, 경제력 +1125, 행복도 +0.25\n\n");
    printf("7. 신도시 건설\n\n");
    printf("-> 비용: 50,000,000\n");
    printf("-> 인구 수 +18750, 경제력 +5625, 행복도 +1.25\n\n");
    printf("8. 복합신도시 건설\n\n");
    printf("-> 비용: 500,000,000\n");
    printf("-> 인구 수 +50,000, 경제력 +10000, 행복도 +5\n\n");
    printf("9. 미래도시 건설\n\n");
    printf("-> 비용: 5,000,000,000\n");
    printf("-> 인구 수 +250,000, 경제력 +50,000, 행복도 +10, <힉스입자 1개 필요>\n\n\n");

    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.3lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n", U.Nano);
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            for (i = 49; i <= 56; i++) {
                if (cho == i) {
                    pay = U.tax - M.mon[1][i - 49];
                    if (pay < 0)
                        break;
                    else {
                        U.tax -= M.mon[1][i - 49];
                        U.eco += E.eco[i - 49];
                        U.feel += F.feel[1][i - 49];
                        U.peo += P.peo[1][i - 49];
                        dev_Eco();
                    }
                }
            }
            if (cho == 27)
                Menu();
            if (cho == 57) {
                Nano = U.Nano - 1;
                if (pay >= 0 && Nano >= 0) {
                    U.tax -= M.mon[2][i - 49];
                    U.eco += E.eco[cho - 49];
                    U.feel += F.feel[1][i - 49];
                    U.peo += P.peo[1][i - 49];
                    U.Nano -= 1;
                    dev_Eco();
                }
            }
        }
    }
}
void Store(void) {
    int cho;
    system("cls");
    printf("----------<힉스입자 상점>----------\n\n");
    printf("*주의사항* 힉스입자를 사려면 <기술력 200000이상>, <경제력 100000이상> 이어야 합니다.\n\n");
    printf("1. 힉스입자 1개 사기\n");
    printf("-> 비용: 10,000,000\n\n");
    printf("2. 힉스입자 10개 사기(추가 +2)\n");
    printf("-> 비용: 100,000,000\n\n");
    printf("3. 힉스입자 100개 사기(추가 +20)\n");
    printf("-> 비용: 1,000,000,000\n\n\n");
    printf("국고 : %lld\t", U.tax);
    printf("군사력 : %ld\t", U.sol);
    printf("전투력 : %0.2f\t", U.SP);
    printf("나라면적 : %d\n\n", U.CS);
    printf("행복도 : %0.2lf\t", U.feel);
    printf("인구수 : %ld\t", U.peo);
    printf("경제력 : %lu\t", U.eco);
    printf("기술력 : %lu\t", U.tec);
    printf("힉스입자: %ld\n\n", U.Nano);
    printf("원하는 번호를 선택하세요\n");
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            if (cho >= 49 && cho <= 51) {
                if (U.eco >= 100000 && U.tec >= 200000) {
                    U.Nano += M.Nano[cho - 49] / 10000000;
                    U.tax -= M.Nano[cho - 49];
                    Store();
                }
                else
                    printf("아직 당신은 기술력이나 경제력이 부족합니다.\n\n");
            }
            else if (cho == 27)
                Menu();
        }
    }

}
void Story(void) {
    system("cls");
    printf("----------<프롤로그>----------\n\n");
    printf("2030년 4월 2일,\n오후 4시 반쯤을 기준으로\n\n10년전부터 서울에 잠복해있던\n북한의 특수요원에 의해\n\n3일만에 한국은 서울을 내주게 되었다.\n\n");
    system("pause");
    system("cls");
    printf("----------<프롤로그>----------\n\n");
    printf("2030년 4월 5일,\n해가 저물고 어둠이 깔리자마자\n북한은 30분마다 EMP폭탄발사를 하였고\n\n한국군은 서로 통신을\n할 수 없게 되었다.\n\n그 후 최신 NK-K1M1 미사일로 인하여\n대한민국 땅의 절반이 점령되었다.\n\n");
    system("pause");
    system("cls");
    printf("----------<프롤로그>----------\n\n");
    printf("2030년 4월 10일,\n그 날의 아침은 정말 참혹했다.\n\n단 8일만에 제주도를\n제외한 모든 지역은\n\n조선민주주의인민공화국으로\n선포되었다.\n\n");
    system("pause");
    system("cls");
    printf("----------<프롤로그>----------\n\n");
    printf("2030년 4월 12일,\n날이 지나는 자정을 기준으로\n\n제주도에서 시작되어\n빼앗긴 대한민국의 땅을\n되찾으려는 전쟁을 시작했다.\n\n우리는 우리의 조국을 되찾을 것이다.\n\n");
    system("pause");
    Menu();
}
void The_End(void) {
    system("cls");
    printf("----------<엔딩>----------\n\n");
    printf("승리...승리다!!!\n이제 통일이다!!\n\n");
    system("pause");
    system("cls");
    printf("----------<엔딩>----------\n\n");
    printf("우리는 다시 일상으로 돌아왔다.\n\n모두 참혹한 전쟁으로\n무너진 시설들을 재건하고 있었다.\n\n힘들었지만 통일이 된 상황을\n생각하며 이겨냈다.\n\n");
    system("pause");
    system("cls");
    printf("----------<엔딩>----------\n\n");
    printf("우리에게는 행복의 미래만\n있는 줄 알았었다.\n\n");
    system("pause");
    system("cls");
    printf("----------<엔딩>----------\n\n");
    printf("하지만 어찌된 일일까?...\n\n우리의 우방국인 미국이 전쟁중\n러시아와 중국의 마찰때문에\n전쟁 후에도 갖가지 도발이 일어났다.\n\n결국 전쟁이 끝나고 맺은\n미국과의 조약의 불만을 품은\n중국과 러시아가 선전포고를 했다.\n\n");
    system("pause");
    system("cls");
    printf("----------<엔딩>----------\n\n");
    printf("사람들은 이것을 세계전쟁이라\n부르기 시작했다.\n\n한국전쟁이\n세계전쟁의 단초가 된것이다.\n\n");
    system("pause");
    system("cls");
    printf("  00000000  00   00   000000       000000  00      00  0000 \n");
    printf("  00000000  00   00   00           00      000     00  00 00 \n");
    printf("     00     00   00   00           00      0000    00  00  00 \n");
    printf("     00     0000000   000000       000000  00 00   00  00   00 \n");
    printf("     00     00   00   000000       000000  00  00  00  00   00 \n");
    printf("     00     00   00   00           00      00   00 00  00  00 \n");
    printf("     00     00   00   00           00      00    0000  00 00 \n");
    printf("     00     00   00   000000       000000  00     00   0000  \n\n\n");
    system("pause");
    exit(1);
}

