#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>
//MySQL 관련 헤더파일
#include <my_global.h>
#include <mysql.h>
using namespace std;


void menu(int &control)
{
	cout << "+------------------------------+\n";
	cout << "|  1. 플레이어 상태창 확인     |\n";
	cout << "|  2. 적팀 상태창 확인         |\n";
	cout << "|  3. 내 스킬 확인             |\n";
	cout << "|  4. 상대방 스킬 확인         |\n";
	cout << "|  5. 내 아이템 확인           |\n";
	cout << "|  6. 공격                     |\n";
	cout << "|  7. 상점에서 아이템 구매     |\n";
	cout << "|  8. 종료하기                 |\n";
	cout << "+------------------------------+\n";
	cout << "\n 플레이어님께서 취할 행동을 골라주세요 : ";
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */
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
		cout << "-----------상태창-----------" << endl;
		cout << " 챔피언 이름 : " << Row[1] << endl;
		cout << " 현재 체력   : " << Row[2] << endl;
		cout << " 현재 마나   : " << Row[3] << endl;
		cout << " 현재 공격력 : " << Row[4] << endl;
		cout << " 현재 방어력 : " << Row[5] << endl;
		cout << " 소지금      : " << Row[6] << endl;
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */
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
		cout << "-----------" << Row[1] << "의 상태창-----------" << endl;
		cout << " 챔피언 이름 : " << Row[1] << endl;
		cout << " 현재 체력   : " << Row[2] << endl;
		cout << " 현재 마나   : " << Row[3] << endl;
		cout << " 현재 공격력 : " << Row[4] << endl;
		cout << " 현재 방어력 : " << Row[5] << endl;
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */
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
		cout << "-----------" << Row[1] << "의 스킬창-----------" << endl;
		cout << " Q 스킬(" << Row[2] << ") - 피해량 " << Row[3] << endl;
		cout << " W 스킬(" << Row[4] << ") - 피해량 " << Row[5] << endl;
		cout << " E 스킬(" << Row[6] << ") - 피해량 " << Row[7] << endl;
		cout << " R 스킬(" << Row[8] << ") - 피해량 " << Row[9] << endl;
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */
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
		cout << "-----------" << Row[1] << "의 스킬창-----------" << endl;
		cout << " Q 스킬(" << Row[2] << ") - 피해량 " << Row[3] << endl;
		cout << " W 스킬(" << Row[4] << ") - 피해량 " << Row[5] << endl;
		cout << " E 스킬(" << Row[6] << ") - 피해량 " << Row[7] << endl;
		cout << " R 스킬(" << Row[8] << ") - 피해량 " << Row[9] << endl;
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */
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
		cout << "-----------아이템 현황-----------" << endl;
		cout << " 아이템 이름 : " << Row[1] << endl;
		cout << " 추가 체력   : " << Row[2] << endl;
		cout << " 추가 마나   : " << Row[3] << endl;
		cout << " 추가 공격력 : " << Row[4] << endl;
		cout << " 추가 방어력 : " << Row[5] << endl;
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */
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

	cout << "공격할 상대를 선택해주세요 : ";
	cin >> attack_enemy;

	// 공격할 상대를 특정하기 위한 쿼리
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
		cout << Row[1] << "님을 공격!" << endl;
		enemy_dp = atoi(Row[5]);
	}
	mysql_free_result(Result);

	// 피해량 계산을 위한 쿼리
	// 피해량 계산은 스킬 피해량 * ((플레이어 공격력 - 적 방어력) / 플레이어 공격력) 으로 계산함.

	cout << "사용할 스킬을 골라주세요! (Q, W, E, R) : ";
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
			cout << "Q 스킬 (" << Row[2] << ") 사용!" << endl;
			skill_damage = atoi(Row[3]);
			break;
		case 'W':
			cout << "W 스킬 (" << Row[4] << ") 사용!" << endl;
			skill_damage = atoi(Row[5]);
			break;
		case 'E':
			cout << "E 스킬 (" << Row[6] << ") 사용!" << endl;
			skill_damage = atoi(Row[7]);
			break;
		case 'R':
			cout << "R 스킬 (" << Row[8] << ") 사용!" << endl;
			skill_damage = atoi(Row[9]);
			break;
		default:
			cout << "오류입니다! " << endl;
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

	// 피해량 계산
	damage_result = (double)skill_damage * (((double)player_ap - (double)enemy_dp) / (double)player_ap);
	cout << "총 " << damage_result << "만큼의 데미지를 입혔습니다!" << endl << endl;

	// 피해량 적용하기
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

	/* 데이터베이스와 연결 */
	ConnPtr = mysql_real_connect(&Conn, "", "root", "rlaqudals1!", "player", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)
	{
		cout << stderr << "Mysql connection error : " << mysql_error(&Conn);
		return;
	}
	else cout << "[ 데이터베이스에 연결되었습니다. ]\n\n";

	/* SQL에 쿼리 보내기 */

	int player_cost;
	char* buyitem = new char[1];
	int item_cost;
	
	// 아이템 목록 불러오기 위한 쿼리
	const char* Query = "SELECT * FROM shop.shop";
	int Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	cout << "-------------상점 목록-------------" << endl;
	int i = 1;
	Result = mysql_store_result(ConnPtr);
	while ((Row = mysql_fetch_row(Result)) != NULL)
	{
		cout << i << ". " << Row[1] << endl;
		cout << "아이템 이름 : " << Row[1] << endl;
		cout << "체력 증가치 : " << Row[2] << endl;
		cout << "마나 증가치 : " << Row[3] << endl;
		cout << "공격력 증가치 : " << Row[4] << endl;
		cout << "방어력 증가치 : " << Row[5] << endl;
		cout << "가격 : " << Row[6] << endl;
		i++;
	}

	cout << "\n\n사실 아이템을 입력해주세요! (1 ~ 6) : ";
	cin >> buyitem;

	int item_HP;
	int item_MP;
	int item_AP;
	int item_DP;
	char temp_HP[3] = "";
	char temp_MP[3] = "";
	char temp_AP[3] = "";
	char temp_DP[3] = "";
	// 살 아이템 정보를 불러오기 위한 쿼리
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

	// 플레이어 소지금 값을 가지고 오기 위한 쿼리
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
		cout << "소지금이 부족합니다!" << endl;
		return;
	}
	else
	{
		cout << "아이템을 구매하였습니다!" << endl;
		player_cost -= item_cost;
	}

	// 플레이어 소지금 값 변경
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

	// 플레이어 아이템 추가
	char Query_insert[200] = "INSERT INTO player.item SELECT * FROM shop.shop WHERE Item_ID = 300";
	strcat(Query_insert, buyitem);
	Stat = mysql_query(ConnPtr, Query_insert);
	if (Stat != 0)
	{
		cout << stderr << "Mysql query error : " << mysql_error(&Conn) << endl;
		return;
	}

	// 플레이어 스테이터스 변경
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

	cout << endl << "플레이어 아이템 추가 및 스테이터스 변경 완료! 창을 확인해보세요." << endl << endl;

	mysql_close(ConnPtr);
	return;
}

int main()
{
	int control; // 선택하는 메뉴

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
			cout << "게임을 종료합니다. " << endl;
			break;
		}
		else cout << "명령이 잘못되었습니다. 다시 입력해주세요! \n";
	}
	return 0;
}