#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 函數聲明
double dealCard();
double calculatePoints(double hand[]);
void printHand(double hand[]);
bool playerTurn(double playerHand[], double computerHand[]);
bool computerTurn(double playerHand[], double computerHand[]);
void determineWinner(double playerHand[], double computerHand[]);

int main() {
    srand(time(NULL)); // 初始化隨機種子

    double playerHand[5] = {0};    // 玩家的手牌
    double computerHand[5] = {0};  // 電腦的手牌

    int currentPlayer = 0; // 現在輪到誰（0：玩家，1：電腦）

    cout << "歡迎來到十點半遊戲！" << endl;

    // 初始化發牌
    for (int i = 0; i < 1; i++) {
        playerHand[i] = dealCard();
        computerHand[i] = dealCard();
    }

    // 遊戲迴圈
    while (true) {
        cout << "===================================" << endl;
        cout << "玩家的手牌: ";
        printHand(playerHand);
        cout << "電腦的底牌: " << computerHand[0] << endl;

        if (currentPlayer == 0) {
            if (!playerTurn(playerHand, computerHand)) {
                break;
            }
        } else {
            if (!computerTurn(playerHand, computerHand)) {
                break;
            }
        }

        currentPlayer = 1 - currentPlayer; // 切換玩家回合
    }

    // 確定勝者
    determineWinner(playerHand, computerHand);

    return 0;
}

// 發牌函數
double dealCard() {
    double cardValue = (rand() % 10 + 1); // 1 到 10 之間的隨機牌
    if (cardValue > 10) {
        cardValue = 0.5; // J、Q、K 設為 0.5
    }
    return cardValue;
}

// 計算手牌點數
double calculatePoints(double hand[]) {
    int numCards = 5;
    double total = 0;
    for (int i = 0; i < numCards; i++) {
        total += hand[i];
    }
    return total;
}

// 列印手牌
void printHand(double hand[]) {
    int numCards = 5;
    for (int i = 0; i < numCards; i++) {
        if (hand[i] != 0) {
            cout << hand[i] << " ";
        }
    }
    cout << "(點數: " << calculatePoints(hand) << ")" << endl;
}

// 玩家回合函數
bool playerTurn(double playerHand[], double computerHand[]) {
    char choice;
    if (playerHand[4] != 0 || calculatePoints(playerHand) >= 10.5) {
        cout << "你的回合，不需要要牌。" << endl;
        return false;
    }

    cout << "你的回合，要牌嗎？(Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        for (int i = 0; i < 5; i++) {
            if (playerHand[i] == 0) {
                playerHand[i] = dealCard();
                break;
            }
        }
        return true;
    } else {
        return false;
    }
}

// 電腦回合函數
bool computerTurn(double playerHand[], double computerHand[]) {
    double computerPoints = calculatePoints(computerHand);

    if (computerHand[4] != 0 || computerPoints >= 10.5) {
        cout << "電腦的回合，不需要要牌。" << endl;
        return false;
    }

    if (computerPoints < calculatePoints(playerHand)) {
        for (int i = 0; i < 5; i++) {
            if (computerHand[i] == 0) {
                computerHand[i] = dealCard();
                break;
            }
        }
        return true;
    } else {
        cout << "電腦的回合，不需要要牌。" << endl;
        return false;
    }
}

// 確定勝者函數
void determineWinner(double playerHand[], double computerHand[]) {
    double playerPoints = calculatePoints(playerHand);
    double computerPoints = calculatePoints(computerHand);

    cout << "===================================" << endl;
    cout << "玩家的手牌: ";
    printHand(playerHand);
    cout << "電腦的手牌: ";
    printHand(computerHand);

    if (playerPoints <= 10.5 && (computerPoints > 10.5 || playerPoints > computerPoints)) {
        cout << "玩家勝利: Player wins." << endl;
    } else if (computerPoints <= 10.5 && (playerPoints > 10.5 || computerPoints > playerPoints)) {
        cout << "電腦勝利: Banker wins." << endl;
    } else {
        cout << "平局: Tie." << endl;
    }
}