#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <vector>
#include <random>

using namespace std;

const int width = 30;
const int height = 20;

struct Snake {
    vector<pair<int, int>> body;
    char direction;
    Snake() {
        direction = 'r';
        body.push_back({ height / 2, width / 2 });
    }
};

struct Fruit {
    pair<int, int> pos;
    Fruit() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis_width(0, width - 1);
        uniform_int_distribution<int> dis_height(0, height - 1);
        pos = { dis_height(gen), dis_width(gen) };
    }
};

int main() {
    // initialize ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    // create snake and fruit
    Snake snake;
    Fruit fruit;

    // game loop
    while (true) {
        // get user input
        int ch = getch();
        if (ch == KEY_UP && snake.direction != 'd') snake.direction = 'u';
        else if (ch == KEY_DOWN && snake.direction != 'u') snake.direction = 'd';
        else if (ch == KEY_LEFT && snake.direction != 'r') snake.direction = 'l';
        else if (ch == KEY_RIGHT && snake.direction != 'l') snake.direction = 'r';

        // move snake
        auto head = snake.body[0];
        if (snake.direction == 'u') head.first--;
        else if (snake.direction == 'd') head.first++;
        else if (snake.direction == 'l') head.second--;
        else if (snake.direction == 'r') head.second++;
        snake.body.insert(snake.body.begin(), head);

        // check if snake has collided with a fruit
        if (head == fruit.pos) {
            snake.body.push_back(snake.body.back());
            fruit = Fruit();
        }
        else {
            snake.body.pop_back();
        }

        // draw snake and fruit
        clear();
        for (auto& part : snake.body) {
            mvprintw(part.first, part.second, "O");
        }
        mvprintw(fruit.pos.first, fruit.pos.second, "X");

        // refresh screen
        refresh();

        // wait for a while
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    // clean up ncurses
    endwin();

    return 0;
}
