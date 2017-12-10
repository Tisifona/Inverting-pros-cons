#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Field {
private:
    int field[2][2];
public:
    Field() {}

    virtual ~Field() {

    }

    void scan(string filepath) {
        ifstream inFile;

        char top[2], bot[2];
        string input;
        inFile.open(filepath);
        if (inFile.is_open()) {
            cout << "File has been opened" << endl;
        } else {
            cout << "NO FILE HAS BEEN OPENED" << endl;
            return;
        }

        {
            getline(inFile, input, '\n');
            top[0] = input[0];
            top[1] = input[2];
            getline(inFile, input, '\n');
            bot[0] = input[0];
            bot[1] = input[2];
        }
        inFile.close();
        for (int i = 0; i < 2; i++) {
            switch (top[i]) {
                case '+':
                    field[0][i] = 1;
                    break;
                case '-':
                    field[0][i] = -1;
                    break;
                default:
                    cout << "something goes wrong";
                    break;
            }
            switch (bot[i]) {
                case '+':
                    field[1][i] = 1;
                    break;
                case '-':
                    field[1][i] = -1;
                    break;
                default:
                    cout << "something goes wrong";
                    break;
            }
        }
    }

    void compare(Field a) {
        int mod1 = 1, mod2 = 1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mod1 *= this->field[i][j];
                mod2 *= a.field[i][j];
            }
        }
        if (mod1 == mod2) {
            printf("%d\t%d\t\t%d\t%d\n%d\t%d\t\t%d\t%d\n", this->field[0][0], this->field[0][1], a.field[0][0],
                   a.field[0][1], this->field[1][0], this->field[1][1], a.field[1][0], a.field[1][1]);
            cout << "При такiй замiнi всьо може бути" << endl;
        }
        if (mod1 != mod2) {
            printf("%d\t%d\t\t%d\t%d\n%d\t%d\t\t%d\t%d\n", this->field[0][0], this->field[0][1], a.field[0][0],
                   a.field[0][1], this->field[1][0], this->field[1][1], a.field[1][0], a.field[1][1]);
            cout << "При такiй замiнi такого не може бути" << endl;
        }
    }
};

int main() {
    Field a = Field();
    a.scan("G:\\Projects\\Adriana_Rozrakh\\worldcities.csv");
    Field b = Field();
    b.scan("G:\\Projects\\Adriana_Rozrakh\\worldcities1.csv");
    a.compare(b);
    return 0;
} 