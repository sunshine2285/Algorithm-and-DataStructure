#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	const int len = 6;

	queue<int> hengCards;
	queue<int> haCards;
	stack<int> cards;

	cout << "小哼的牌为：";
	for (int i = 0; i < len; i++)
	{
		int tCard = 0;
		cin >> tCard;
		hengCards.push(tCard);
	}

	cout << "小哈的牌为：";
	for (int i = 0; i < len; i++)
	{
		int tCard = 0;
		cin >> tCard;
		haCards.push(tCard);
	}

	bool exist[10] = { false };
	memset(exist, 0, sizeof(exist));
	int count = 1;

	queue<int>* playerCards = NULL;
	string playerName = "小哼";

	while (!hengCards.empty() && !haCards.empty())
	{
		//小哼先出牌

		if (count % 2 != 0) {
			cout << "************第" << count / 2 << "轮***********" << endl;
			playerCards = &hengCards;
			playerName = "小哼";
		}
		else
		{
			playerCards = &haCards;
			playerName = "小哈";
		}

		int playerCard = playerCards->front();
		playerCards->pop();
		cout << playerName << "出牌 " << playerCard << ";\t";

		if (exist[playerCard])
		{
			cout << "已经出的牌中有 " << playerCard << "; 收走牌 ";
			int tCard = 0;
			while (tCard != playerCard)
			{
				tCard = cards.top();
				exist[tCard] = false;
				cards.pop();
				playerCards->push(tCard);
				cout << tCard << ' ';
			}
		}
		else
		{
			exist[playerCard] = true;
			cards.push(playerCard);
			cout << "已经出的牌中无 " << playerCard;
		}
		cout << endl;
		++count;
	}

	if (hengCards.empty())
		cout << "小哈获胜！" << endl;
	else
		cout << "小哼获胜！" << endl;

	return 0;
}