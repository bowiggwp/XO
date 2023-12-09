#include <iostream>
using namespace std;

char board[3][3] = { { '1', '2', '3' },
                     { '4', '5', '6' },
                     { '7', '8', '9' } };
bool player1Turn = true;
int choice;
char mark;

void displayBoard() {
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
    cout << " -----------" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
    cout << " -----------" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

bool placeMark(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Эта ячейка уже занята. Выберите другую." << endl;
        return false;
    }

    board[row][col] = mark;
    return true;
}

bool checkWin() {
    // Проверка строк, столбцов и диагоналей на победу
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int turns = 0;
    bool gameover = false;

    while (!gameover) {
        displayBoard();

        // Определение метки для текущего игрока
        if (player1Turn)
            mark = 'X';
        else
            mark = 'O';

        cout << "Игрок " << (player1Turn ? "1" : "2") << ", введите число для постановки " << mark << " : ";
        cin >> choice;

        // Проверка на допустимость выбора и постановка метки
        if (choice < 1 || choice > 9) {
            cout << "Недопустимый ход. Введите число от 1 до 9." << endl;
            continue;
        }

        if (placeMark(choice, mark)) {
            turns++;
            if (checkWin()) {
                displayBoard();
                cout << "Игрок " << (player1Turn ? "1" : "2") << " победил!" << endl;
                gameover = true;
            }
            else if (turns == 9) {
                displayBoard();
                cout << "Ничья!" << endl;
                gameover = true;
            }
            else {
                player1Turn = !player1Turn;
            }
        }
        else {
            cout << "Недопустимый ход. Попробуйте снова." << endl;
        }
    }

    return 0;
}
