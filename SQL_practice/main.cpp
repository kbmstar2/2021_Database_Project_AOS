#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
//MySQL ���� �������
#include <my_global.h>
#include <mysql.h>
using namespace std;


void menu(int &control)
{
	cout << "+------------------------------+\n";
	cout << "|  1. �÷��̾� ����â Ȯ��     |\n";
	cout << "|  2. ���� ����â Ȯ��         |\n";
	cout << "|  3. �� ��ų Ȯ��             |\n";
	cout << "|  4. ���� ��ų Ȯ��         |\n";
	cout << "|  5. �� ������ Ȯ��           |\n";
	cout << "|  6. ����                     |\n";
	cout << "|  7. �������� ������ ����     |\n";
	cout << "|  8. �����ϱ�                 |\n";
	cout << "+------------------------------+\n";
	cout << "\n �÷��̾�Բ��� ���� �ൿ�� ����ּ��� : ";
	cin >> control;
	
}

void player_status()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */
	int Stat;
	const char* Query = "SELECT * FROM player.playerstatus";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << "-----------����â-----------" << endl;
		cout << " è�Ǿ� �̸� : " << Row[1] << endl;
		cout << " ���� ü��   : " << Row[2] << endl;
		cout << " ���� ����   : " << Row[3] << endl;
		cout << " ���� ���ݷ� : " << Row[4] << endl;
		cout << " ���� ���� : " << Row[5] << endl;
		cout << " ������      : " << Row[6] << endl;
		cout << "----------------------------" << endl << endl;
	}
	mysql_free_result(Result);

	mysql_close(ConnPtr);
	return;
}

void enemy_status()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */
	int Stat;
	const char* Query = "SELECT * FROM enemy.enemystatus";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << "-----------" << Row[1] << "�� ����â-----------" << endl;
		cout << " è�Ǿ� �̸� : " << Row[1] << endl;
		cout << " ���� ü��   : " << Row[2] << endl;
		cout << " ���� ����   : " << Row[3] << endl;
		cout << " ���� ���ݷ� : " << Row[4] << endl;
		cout << " ���� ���� : " << Row[5] << endl;
		cout << "------------------------------------" << endl << endl;
	}
	mysql_free_result(Result);

	mysql_close(ConnPtr);
	return;
}

void player_skill()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */
	int Stat;
	const char* Query = "SELECT * FROM player.skill";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << "-----------" << Row[1] << "�� ��ųâ-----------" << endl;
		cout << " Q ��ų(" << Row[2] << ") - ���ط� " << Row[3] << endl;
		cout << " W ��ų(" << Row[4] << ") - ���ط� " << Row[5] << endl;
		cout << " E ��ų(" << Row[6] << ") - ���ط� " << Row[7] << endl;
		cout << " R ��ų(" << Row[8] << ") - ���ط� " << Row[9] << endl;
		cout << "------------------------------------" << endl;
	}
	mysql_free_result(Result);

	mysql_close(ConnPtr);
	return;
}

void enemy_skill()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */
	int Stat;
	const char* Query = "SELECT * FROM enemy.skill";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << "-----------" << Row[1] << "�� ��ųâ-----------" << endl;
		cout << " Q ��ų(" << Row[2] << ") - ���ط� " << Row[3] << endl;
		cout << " W ��ų(" << Row[4] << ") - ���ط� " << Row[5] << endl;
		cout << " E ��ų(" << Row[6] << ") - ���ط� " << Row[7] << endl;
		cout << " R ��ų(" << Row[8] << ") - ���ط� " << Row[9] << endl;
		cout << "------------------------------------" << endl << endl;
	}
	mysql_free_result(Result);

	mysql_close(ConnPtr);
	return;
}

void my_item()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */
	int Stat;
	const char* Query = "SELECT * FROM player.item";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << "-----------������ ��Ȳ-----------" << endl;
		cout << " ������ �̸� : " << Row[1] << endl;
		cout << " �߰� ü��   : " << Row[2] << endl;
		cout << " �߰� ����   : " << Row[3] << endl;
		cout << " �߰� ���ݷ� : " << Row[4] << endl;
		cout << " �߰� ���� : " << Row[5] << endl;
		cout << "---------------------------------" << endl << endl;
	}
	mysql_free_result(Result);

	mysql_close(ConnPtr);
	return;
}

void attack()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);
	char* attack_enemy = new char[1];

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */
	int Stat;
	const char* Query = "SELECT * FROM enemy.enemystatus";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	int i = 1;
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << i << ". "<< Row[1] << endl;
		i++;
	}
	mysql_free_result(Result);

	cout << "������ ��븦 �������ּ��� : ";
	cin >> attack_enemy;

	// ������ ��븦 Ư���ϱ� ���� ����
	char Query_attack[100] = "SELECT * FROM enemy.enemystatus WHERE Enemy_ID = ";
	strcat(Query_attack, attack_enemy);
	Stat = mysql_query(ConnPtr, Query_attack);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	int player_ap;
	int enemy_dp;
	int skill_damage;
	double damage_result;

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << Row[1] << "���� ����!" << endl;
		enemy_dp = atoi(Row[5]);
	}
	mysql_free_result(Result);

	// ���ط� ����� ���� ����
	// ���ط� ����� ��ų ���ط� * ((�÷��̾� ���ݷ� - �� ����) / �÷��̾� ���ݷ�) ���� �����.

	cout << "����� ��ų�� ����ּ���! (Q, W, E, R) : ";
	char useskill;
	cin >> useskill;
	Query = "SELECT * FROM player.skill";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		switch (useskill)
		{
		case 'Q':
			cout << "Q ��ų (" << Row[2] << ") ���!" << endl;
			skill_damage = atoi(Row[3]);
			break;
		case 'W':
			cout << "W ��ų (" << Row[4] << ") ���!" << endl;
			skill_damage = atoi(Row[5]);
			break;
		case 'E':
			cout << "E ��ų (" << Row[6] << ") ���!" << endl;
			skill_damage = atoi(Row[7]);
			break;
		case 'R':
			cout << "R ��ų (" << Row[8] << ") ���!" << endl;
			skill_damage = atoi(Row[9]);
			break;
		default:
			cout << "�����Դϴ�! " << endl;
			break;
		}
	}
	mysql_free_result(Result);

	Query = "SELECT * FROM player.playerstatus";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		player_ap = atoi(Row[4]);
	}

	mysql_free_result(Result);

	// ���ط� ���
	damage_result = (double)skill_damage * (((double)player_ap - (double)enemy_dp) / (double)player_ap);
	cout << "�� " << damage_result << "��ŭ�� �������� �������ϴ�!" << endl << endl;

	// ���ط� �����ϱ�
	char* hp_alter = new char[1];
	char* hp_where = new char[1];
	char Query_where[50] = " WHERE Enemy_ID = ";
	char Query_hp[100] = "UPDATE enemy.enemystatus SET Enemy_HP = Enemy_HP - ";
	_itoa((int)damage_result, hp_alter, 10);
	strcat(Query_hp, hp_alter);
	strcat(Query_where, attack_enemy);
	strcat(Query_hp, Query_where);
	Stat = mysql_query(ConnPtr, Query_hp);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}
	mysql_close(ConnPtr);
	return;
}

void buy_item()
{
	string str_query;
	MYSQL Conn;
	MYSQL* ConnPtr = NULL;
	MYSQL_RES* Result;
	MYSQL_ROW Row;
	mysql_init(&Conn);
	char* attack_enemy = new char[1];

	/* �����ͺ��̽��� ���� */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ �����ͺ��̽��� ����Ǿ����ϴ�. ]\n\n";

	/* SQL�� ���� ������ */

	int player_cost;
	char* buyitem = new char[1];
	int item_cost;
	
	// ������ ��� �ҷ����� ���� ����
	const char* Query = "SELECT * FROM shop.shop";
	int Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	cout << "-------------���� ���-------------" << endl;
	int i = 1;
	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << i << ". " << Row[1] << endl;
		cout << "������ �̸� : " << Row[1] << endl;
		cout << "ü�� ����ġ : " << Row[2] << endl;
		cout << "���� ����ġ : " << Row[3] << endl;
		cout << "���ݷ� ����ġ : " << Row[4] << endl;
		cout << "���� ����ġ : " << Row[5] << endl;
		cout << "���� : " << Row[6] << endl;
		i++;
	}

	cout << "\n\n��� �������� �Է����ּ���! (1 ~ 6) : ";
	cin >> buyitem;

	int item_HP;
	int item_MP;
	int item_AP;
	int item_DP;
	char temp_HP[3] = "";
	char temp_MP[3] = "";
	char temp_AP[3] = "";
	char temp_DP[3] = "";
	// �� ������ ������ �ҷ����� ���� ����
	char Query_buy[100] = "SELECT * FROM shop.shop WHERE Item_ID = 300";
	strcat(Query_buy, buyitem);
	Stat = mysql_query(ConnPtr, Query_buy);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		item_HP = atoi(Row[2]);
		item_MP = atoi(Row[3]);
		item_AP = atoi(Row[4]);
		item_DP = atoi(Row[5]);
		item_cost = atoi(Row[6]);
	}
	mysql_free_result(Result);

	// �÷��̾� ������ ���� ������ ���� ���� ����
	Query = "SELECT * FROM player.playerstatus";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		player_cost = atoi(Row[6]);
	}

	if (item_cost > player_cost)
	{
		cout << "�������� �����մϴ�!" << endl;
		return;
	}
	else
	{
		cout << "�������� �����Ͽ����ϴ�!" << endl;
		player_cost -= item_cost;
	}

	// �÷��̾� ������ �� ����
	char* cost_alter = new char[1];
	const char* Query_where = " WHERE Player_ID = 1";
	char Query_cost[100] = "UPDATE player.playerstatus SET Player_Cost = ";
	_itoa(player_cost, cost_alter, 10);
	strcat(Query_cost, cost_alter);
	strcat(Query_cost, Query_where);
	Stat = mysql_query(ConnPtr, Query_cost);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	mysql_free_result(Result);

	// �÷��̾� ������ �߰�
	char Query_insert[200] = "INSERT INTO player.item SELECT * FROM shop.shop WHERE Item_ID = 300";
	strcat(Query_insert, buyitem);
	Stat = mysql_query(ConnPtr, Query_insert);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	// �÷��̾� �������ͽ� ����
	char Query_status[500] = "UPDATE player.playerstatus SET ";
	char Query_HP[400] = "Player_HP = Player_HP + ";
	_itoa(item_HP, temp_HP, 10);
	strcat(Query_HP, temp_HP);
	char Query_MP[50] = ", Player_MP = Player_MP + ";
	_itoa(item_MP, temp_MP, 10);
	strcat(Query_MP, temp_MP);
	strcat(Query_HP, Query_MP);
	char Query_AP[50] = ", Player_AP = Player_AP + ";
	_itoa(item_AP, temp_AP, 10);
	strcat(Query_AP, temp_AP);
	strcat(Query_HP, Query_AP);
	char Query_DP[50] = ", Player_DP = Player_DP + ";
	_itoa(item_DP, temp_DP, 10);
	strcat(Query_DP, temp_DP);
	strcat(Query_HP, Query_DP);

	strcat(Query_status, Query_HP);
	strcat(Query_status, Query_where);

	Stat = mysql_query(ConnPtr, Query_status);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	cout << endl << "�÷��̾� ������ �߰� �� �������ͽ� ���� �Ϸ�! â�� Ȯ���غ�����." << endl << endl;

	mysql_close(ConnPtr);
	return;
}

int main()
{
	int control; // �����ϴ� �޴�

	for (;;)
	{
		menu(control);
		if (control == 1) player_status();
		else if (control == 2) enemy_status();
		else if (control == 3) player_skill();
		else if (control == 4) enemy_skill();
		else if (control == 5) my_item();
		else if (control == 6) attack();
		else if (control == 7) buy_item();
		else if (control == 8)
		{
			cout << "������ �����մϴ�. " << endl;
			break;
		}
		else cout << "����� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���! \n";
	}
	return 0;
}