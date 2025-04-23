#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

int con = 0;

typedef struct {            //����ϴ� ������ ���� ����ü �±�
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
typedef struct {       //���� ������ ���� ����ü �±�
    char country[10];
}Coun;
Coun C[13];
typedef struct {  //���ѿ� ���� ����ü �±�
    long Nsol[12];
    double NSP;
    int def[12];
    long sol;
}North;
North N;
typedef struct {     //���Ǵ� ���� ����
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
typedef struct {     //�ູ���� ����
    double feel[2][9]; /*
                        {
                            soldier
                            economy
                        }
                        */
}Feel;
Feel F;
typedef struct {    //�α� ���� ����
    unsigned long peo[2][9]; /*
                    {
                        solider
                        economy
                    }
                    */
}People;
People P;
typedef struct {   //������ �� ����¿� ����
    unsigned long eco[9];
    unsigned long tec[9];
    unsigned long Tec[9];
}EcoTec;
EcoTec E;
typedef struct {  //����¿� ����
    unsigned long sol[9];
    int line;
}Soilder;
Soilder S;
void Set(void) {  //���� ���ۿ� �ʿ��� ������
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

    strcpy_s(C[0].country, sizeof("����"), "����");
    strcpy_s(C[1].country, sizeof("�λ�"), "�λ�");
    strcpy_s(C[2].country, sizeof("����"), "����");
    strcpy_s(C[3].country, sizeof("���"), "���");
    strcpy_s(C[4].country, sizeof("�뱸"), "�뱸");
    strcpy_s(C[5].country, sizeof("����"), "����");
    strcpy_s(C[6].country, sizeof("����"), "����");
    strcpy_s(C[7].country, sizeof("����"), "����");
    strcpy_s(C[8].country, sizeof("����"), "����");
    strcpy_s(C[9].country, sizeof("û��"), "û��");
    strcpy_s(C[10].country, sizeof("������"), "������");
    strcpy_s(C[11].country, sizeof("����"), "����");
    strcpy_s(C[12].country, sizeof("���"), "���");

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
    for (i = 0; i < 12; i++)  //���ѱ��� �� ����
        N.def[i] = 100;
    for (i = 0; i < 12; i++)   //����¡�� �ð����� ����
        U.time[i] = 0;
    for (i = 1; i < 9; i++) {   //���� ������ ���� ����
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

void Start(void) {  //���� ���� ȭ��
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

    printf("--1. ���ӽ���--\n\n");
    printf("--2. ���Ӽ���--\n\n");
    printf("--3. ��������--\n\n");

    printf("����� �г����� �Է����ּ���(10�� ����): ");
    scanf("%s", U.name);

    printf("\n�����ϰ� ���� ��ȣ�� ������: ");
    scanf("%d", &cho);
    while (cho > 3 || cho < 1) {
        printf("�ٽ� �Է����ּ���: ");
        scanf("%d", &cho);
    }
    if (cho == 1)
        Menu();
    else if (cho == 2)
        Story();
    else if (cho == 3)
        exit(1);
}
void Menu(void) {  //���� �޴�
    int cho;
    system("cls");
    if (U.CS == 13)
        The_End();
    printf("----------<�ѱ����� �޴�>----------\n\n");
    printf("1. ���� ���\n\n");
    printf("2. ���� ¡��\n\n");
    printf("3. ���� ����\n\n");
    printf("4. ��� ����\n\n");
    printf("5. ���� ����\n\n");
    printf("6. �������� ����\n\n");
    printf("ESC. �����ϱ�\n\n\n");

    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.3lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n", U.Nano);

    printf("�����ϰ� ���� ��ȣ�� ������");
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
void War_go(void) {  //������� ȭ��
    int i;
    int cho;
    system("cls");
    printf("----------<���� ���>----------\n\n");
    printf("-�� ����- ���� <���ɵ�>\n\n");
    for (i = 1; i < 13; i++) {
        printf("%d. %s", i, C[i].country);
        if (U.CS > i)
            printf("  <���ɵ�>");
        printf("\n\n");
    }
    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.3lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n", U.Nano);

    printf("\n�����ϰ� ���� ������ �����ϼ���.\n");
    while (1) {
        if (_kbhit()) {
            cho = _getch();
            if (cho >= 49 && cho <= 57 || cho == 97 || cho == 115 || cho == 100) {
                switch (cho) {
                case 97:
                    if (U.CS > 10) {
                        printf("\n%s������ �̹� ������ �����Դϴ�.\n", C[10].country);
                        break;
                    }
                    else if (U.CS == 10) {
                        War_ready(10);
                    }
                    else {
                        printf("\n���� ���������� ������ �ּ���!\n");
                        break;
                    }
                case 115:
                    if (U.CS > 11) {
                        printf("\n%s������ �̹� ������ �����Դϴ�.\n", C[11].country);
                        break;
                    }
                    else if (U.CS == 11) {
                        War_ready(11);
                    }
                    else {
                        printf("\n���� ���������� ������ �ּ���!\n");
                        break;
                    }
                case 100:
                    if (U.CS > 12) {
                        printf("\n%s������ �̹� ������ �����Դϴ�.\n", C[12].country);
                        break;
                    }
                    else if (U.CS == 12) {
                        War_ready(12);
                    }
                    else {
                        printf("\n���� ���������� ������ �ּ���!\n");
                        break;
                    }

                default:
                    if (U.CS > cho - 48) {
                        printf("\n%s������ �̹� ������ �����Դϴ�.\n", C[cho - 48].country);
                        break;
                    }
                    else if (U.CS == cho - 48) {
                        War_ready(cho - 48);
                    }
                    else {
                        printf("\n���� ���������� ������ �ּ���!\n");
                        break;
                    }
                }
            }
            else if (cho == 27)
                Menu();
        }
    }

}
int War_ready(int place) {  //������ ����ϱ� ���� �غ� �Լ�
    int cho;
    N.sol = N.Nsol[place - 1];
    system("cls");
    printf("----------<���� ���>----------\n\n");
    printf("���� %s������ ��: %d\n\n", C[place].country, N.def[place - 1]);
    printf("���� �����: %ld\n\n", N.Nsol[place - 1]);
    printf("      vs\n\n");
    printf("���� �����: %ld\n\n\n", U.sol);

    printf("���ﰳ��(Enter�� ��������)\n\n");
    printf("����(ESC�� ��������)\n\n");

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
int War_start(int place) {  //������ �ϴ� �Լ�
    system("cls");
    U.SP = (double)U.sol / 10;
    N.NSP = (double)N.sol / 10;
    printf("�ѱ�\n");
    printf("�����: %ld\n", U.sol);
    printf("������: %f\n\n", U.SP);
    printf("      vs\n\n");
    printf("����\n");
    printf("�����: %ld\n", N.sol);
    printf("������: %f\n\n", N.NSP);

    if (S.line == 0) {
        S.line = 1;
        printf("���ѱ��� �����մϴ�!!\n");
        Sleep(2000);
        U.sol -= N.NSP;
        if (U.sol < 0)
            U.sol = 0;
        printf("�ѱ����� ���� ����� %ld�Դϴ�.\n\n", U.sol);
        if (U.sol == 0) {
            printf("�ѱ����� ���簡 0�Դϴ�. �������� �й��Ͽ����ϴ�.\n");
            printf("�α� �� -500\n");
            printf("�ູ�� - 5\n\n");
            system("pause");
            Menu();
        }
        Sleep(2000);
        War_start(place);
    }
    else
        S.line = 0;
    printf("�ѱ����� �����մϴ�!!\n");
    Sleep(2000);
    N.sol -= U.SP;
    if (N.sol < 0)
        N.sol = 0;
    if (N.sol == 0) {
        printf("���ѱ��� ���簡 0�Դϴ�. �������� �¸��Ͽ����ϴ�.\n\n");
        N.def[place - 1] -= 20;
        if (N.def[place - 1] == 0) {
            printf("���ɼ���!!!\n");
            U.CS += 1;
            system("pause");
            Menu();
        }
        else
            printf("���� �¸�!!!\n");
        printf("���� ���� 20%%���� ���׽��ϴ�. ���� ��: %d%%\n", N.def[place - 1]);
        system("pause");
        Menu();
    }
    printf("���ѱ��� ���� ����� %ld�Դϴ�.\n\n", N.sol);
    Sleep(2000);
    War_start(place);
}
void get_Tax(void) {   //������ ¡���ϴ� �Լ�
    int cho;
    int i;
    system("cls");
    printf("----------<���� ¡��>----------\n\n");
    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.3lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n\n", U.Nano);
    printf("������ �������� ������ ¡���ϼ���\n\n");
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
                        printf("���ɵ��� ���� �����Դϴ�!!\n");
                        break;
                    }
                    if (U.time[9] > 0) {
                        printf("�ð��� ���� �ʾҽ��ϴ�!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[9];
                    U.time[9] = 100;
                    get_Tax();
                case 115:
                    if (U.CS < 10) {
                        printf("���ɵ��� ���� �����Դϴ�!!\n");
                        break;
                    }
                    if (U.time[10] > 0) {
                        printf("�ð��� ���� �ʾҽ��ϴ�!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[10];
                    U.time[10] = 100;
                    get_Tax();
                case 100:
                    if (U.CS < 11) {
                        printf("���ɵ��� ���� �����Դϴ�!!\n");
                        break;
                    }
                    if (U.time[11] > 0) {
                        printf("�ð��� ���� �ʾҽ��ϴ�!!\n");
                        break;
                    }
                    U.tax += U.peo * M.tax[11];
                    U.time[11] = 100;
                    get_Tax();
                default:
                    if (U.CS <= cho - 49) {
                        printf("���ɵ��� ���� �����Դϴ�!!\n");
                        break;
                    }
                    if (U.time[cho - 49] > 0) {
                        printf("�ð��� ���� �ʾҽ��ϴ�!!\n");
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
void make_Soldier(void) {   //������� �����ϴ� �Լ�
    system("cls");
    int i;
    int cho;
    long long pay;
    double feel;
    long peo;
    long Nano;
    printf("----------<���� ����>----------\n\n");
    printf("1.���� ¡��\n");
    printf("-> ���: 100\n");
    printf("-> �α� �� -1, ����� +1, �ູ�� -0.001\n\n");
    printf("2.Ư���δ� ����\n");
    printf("-> ���: 1,000\n");
    printf("-> �α� �� -10, ����� +200, �ູ�� -0.005\n\n");
    printf("3.��ũ ����\n\n");
    printf("-> ���: 10,000\n");
    printf("-> ����� +1000, �ູ�� -0.01\n");
    printf("-> <����� 200�̻�>\n\n");
    printf("4.������ ����\n\n");
    printf("-> ���: 100,000\n");
    printf("-> <����� 1000�̻�>\n\n");
    printf("-> ����� +10000, �ູ�� -0.05\n\n");
    printf("5.�װ����� ����\n\n");
    printf("-> ���: 1,000,000\n");
    printf("-> <����� 5000�̻�>\n\n");
    printf("-> ����� +50000, �ູ�� -0.1\n\n");
    printf("6.���� ��� ������ ����\n\n");
    printf("-> ���: 10,000,000\n");
    printf("-> <����� 25000�̻�>\n\n");
    printf("-> ����� +250000, �ູ�� -0.2\n\n");
    printf("7.�ٹ��� ����\n\n");
    printf("-> ���: 100,000,000\n");
    printf("-> �α� �� -100, ����� +1250000, �ູ�� -1\n\n");
    printf("-> <����� 50000�̻�>\n\n");
    printf("8.���� �κ� ����\n\n");
    printf("-> ���: 500,000,000\n");
    printf("-> ����� +2,000,000, �ູ�� -0.5, <�������� 1�� �ʿ�>\n\n");
    printf("9.�Ŵ� �� ����\n\n");
    printf("-> ���: 5,000,000,000\n");
    printf("-> ����� +10,000,000, �ູ�� -1, <�������� 2�� �ʿ�>\n\n\n");

    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.3lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n", U.Nano);
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
    printf("----------<����� ����>----------\n\n");
    printf("1. ������ ����\n");
    printf("-> ���: 2,500\n");
    printf("-> �α� �� -1, ����� +1, <������ 20�̻�>\n\n");
    printf("2. ���� ���� �Ǽ�\n");
    printf("-> ���: 10,000\n");
    printf("-> �α� �� -2, ����� +5, <������ 100�̻�>\n\n");
    printf("3. ���ʰ��� ����\n\n");
    printf("-> ���: 40,000\n");
    printf("-> ����� +25, <������ 500�̻�>\n\n");
    printf("4. ��ȭ���� ����\n\n");
    printf("-> ���: 160,000\n");
    printf("-> ����� +75, <������ 2500�̻�>\n\n");
    printf("5. ���б�� ����\n\n");
    printf("-> ���: 740,000\n");
    printf("-> ����� +225, <������ 12500�̻�>\n\n");
    printf("6. ������� ����\n\n");
    printf("-> ���: 5,000,000\n");
    printf("-> ����� +1125, <����� 50000�̻�>\n\n");
    printf("7. ÷�ܰ��� ����\n\n");
    printf("-> ���: 20,000,000\n");
    printf("-> ����� +5625 <����� 100000�̻�>\n\n");
    printf("8. �̷����� ����\n\n");
    printf("-> ���: 100,000,000\n");
    printf("-> ����� +10000, <�������� 1�� �ʿ�>\n\n");
    printf("9. �ð��������� ����\n\n");
    printf("-> ���: 4,000,000,000\n");
    printf("-> ����� +50,000, <�������� 2�� �ʿ�>\n\n\n");

    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.3lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n", U.Nano);
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
    printf("----------<���� ����>----------\n\n");
    printf("1. ���� �Ǽ�\n");
    printf("-> ���: 50\n");
    printf("-> �α� �� +10, ������ +1, �ູ�� +0.001\n\n");
    printf("2. ���� �Ǽ�\n");
    printf("-> ���: 500\n");
    printf("-> �α� �� +50, ������ +5, �ູ�� +0.005\n\n");
    printf("3. ���� �Ǽ�\n\n");
    printf("-> ���: 5,000\n");
    printf("-> �α� �� +250, ������ +25, �ູ�� +0.025\n\n");
    printf("4. ����ü� �Ǽ�\n\n");
    printf("-> ���: 50,000\n");
    printf("-> �α� �� +750, ������ +75, �ູ�� +0.01\n\n");
    printf("5. ��ȭ�ü� �Ǽ�\n\n");
    printf("-> ���: 500,000\n");
    printf("-> �α� �� +1,000, ������ +225, �ູ�� +0.05\n\n");
    printf("6. �����ü� �Ǽ�\n\n");
    printf("-> ���: 5,000,000\n");
    printf("-> �α� �� +3750, ������ +1125, �ູ�� +0.25\n\n");
    printf("7. �ŵ��� �Ǽ�\n\n");
    printf("-> ���: 50,000,000\n");
    printf("-> �α� �� +18750, ������ +5625, �ູ�� +1.25\n\n");
    printf("8. ���սŵ��� �Ǽ�\n\n");
    printf("-> ���: 500,000,000\n");
    printf("-> �α� �� +50,000, ������ +10000, �ູ�� +5\n\n");
    printf("9. �̷����� �Ǽ�\n\n");
    printf("-> ���: 5,000,000,000\n");
    printf("-> �α� �� +250,000, ������ +50,000, �ູ�� +10, <�������� 1�� �ʿ�>\n\n\n");

    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.3lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n", U.Nano);
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
    printf("----------<�������� ����>----------\n\n");
    printf("*���ǻ���* �������ڸ� ����� <����� 200000�̻�>, <������ 100000�̻�> �̾�� �մϴ�.\n\n");
    printf("1. �������� 1�� ���\n");
    printf("-> ���: 10,000,000\n\n");
    printf("2. �������� 10�� ���(�߰� +2)\n");
    printf("-> ���: 100,000,000\n\n");
    printf("3. �������� 100�� ���(�߰� +20)\n");
    printf("-> ���: 1,000,000,000\n\n\n");
    printf("���� : %lld\t", U.tax);
    printf("����� : %ld\t", U.sol);
    printf("������ : %0.2f\t", U.SP);
    printf("������� : %d\n\n", U.CS);
    printf("�ູ�� : %0.2lf\t", U.feel);
    printf("�α��� : %ld\t", U.peo);
    printf("������ : %lu\t", U.eco);
    printf("����� : %lu\t", U.tec);
    printf("��������: %ld\n\n", U.Nano);
    printf("���ϴ� ��ȣ�� �����ϼ���\n");
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
                    printf("���� ����� ������̳� �������� �����մϴ�.\n\n");
            }
            else if (cho == 27)
                Menu();
        }
    }

}
void Story(void) {
    system("cls");
    printf("----------<���ѷα�>----------\n\n");
    printf("2030�� 4�� 2��,\n���� 4�� ������ ��������\n\n10�������� ���￡ �ẹ���ִ�\n������ Ư������� ����\n\n3�ϸ��� �ѱ��� ������ ���ְ� �Ǿ���.\n\n");
    system("pause");
    system("cls");
    printf("----------<���ѷα�>----------\n\n");
    printf("2030�� 4�� 5��,\n�ذ� ������ ����� ���ڸ���\n������ 30�и��� EMP��ź�߻縦 �Ͽ���\n\n�ѱ����� ���� �����\n�� �� ���� �Ǿ���.\n\n�� �� �ֽ� NK-K1M1 �̻��Ϸ� ���Ͽ�\n���ѹα� ���� ������ ���ɵǾ���.\n\n");
    system("pause");
    system("cls");
    printf("----------<���ѷα�>----------\n\n");
    printf("2030�� 4�� 10��,\n�� ���� ��ħ�� ���� ��Ȥ�ߴ�.\n\n�� 8�ϸ��� ���ֵ���\n������ ��� ������\n\n�������������ιΰ�ȭ������\n�����Ǿ���.\n\n");
    system("pause");
    system("cls");
    printf("----------<���ѷα�>----------\n\n");
    printf("2030�� 4�� 12��,\n���� ������ ������ ��������\n\n���ֵ����� ���۵Ǿ�\n���ѱ� ���ѹα��� ����\n��ã������ ������ �����ߴ�.\n\n�츮�� �츮�� ������ ��ã�� ���̴�.\n\n");
    system("pause");
    Menu();
}
void The_End(void) {
    system("cls");
    printf("----------<����>----------\n\n");
    printf("�¸�...�¸���!!!\n���� �����̴�!!\n\n");
    system("pause");
    system("cls");
    printf("----------<����>----------\n\n");
    printf("�츮�� �ٽ� �ϻ����� ���ƿԴ�.\n\n��� ��Ȥ�� ��������\n������ �ü����� ����ϰ� �־���.\n\n��������� ������ �� ��Ȳ��\n�����ϸ� �̰ܳ´�.\n\n");
    system("pause");
    system("cls");
    printf("----------<����>----------\n\n");
    printf("�츮���Դ� �ູ�� �̷���\n�ִ� �� �˾Ҿ���.\n\n");
    system("pause");
    system("cls");
    printf("----------<����>----------\n\n");
    printf("������ ����� ���ϱ�?...\n\n�츮�� ��汹�� �̱��� ������\n���þƿ� �߱��� ����������\n���� �Ŀ��� ������ ������ �Ͼ��.\n\n�ᱹ ������ ������ ����\n�̱����� ������ �Ҹ��� ǰ��\n�߱��� ���þư� �������� �ߴ�.\n\n");
    system("pause");
    system("cls");
    printf("----------<����>----------\n\n");
    printf("������� �̰��� ���������̶�\n�θ��� �����ߴ�.\n\n�ѱ�������\n���������� ���ʰ� �Ȱ��̴�.\n\n");
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

