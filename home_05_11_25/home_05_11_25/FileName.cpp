#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool ContainsWord(const string& filename, const string& target) {
    ifstream file(filename);
    if (!file) return false;

    string word;
    while (file >> word) {
        if (word == target) return true;
    }

    return false;
}

int main() {
    /*ofstream file("user_input.txt", ios::app);

    string input;
    cout << "������� ������ (������ ������ �������� ����):\n";
    int count = 0;
    char buff[1000];
    while (true) {

        cin.getline(buff, 1000);
        string str = buff;

        if (str.length() == 0)
        {
            count++;
            if (count == 2)
            {
                break;
            }
        }
        else
        {
            count = 0;
            file << str << "\n";
        }


    }

    file.close();*/


    // 5
    /* fstream text1("file1.txt", ios::trunc);
    fstream text2("file2.txt", ios::trunc);
    fstream buf("temp.txt", ios::trunc);
    buf << text1.rdbuf();
    text1 << text2.rdbuf();
    text2 << buf.rdbuf();

    text1.close();
    text2.close();
    buf.close();
    remove("temp.txt");
    return 0; */

    // 6
    /* ifstream main("main_6.txt", ios::in);
    const int size = 250;
    char buf[size];

    int chaise_count = 0;
    while (main)
    {
        main.read(buf, size);
        int bytesRead = main.gcount(); // GPT helped
        if (bytesRead == 0) break;
        string f_name = "chaise_" + to_string(chaise_count++) + ".txt";
        ofstream chaise(f_name, ios::out | ios::trunc);
        chaise.write(buf, bytesRead);
        chaise.close();
    }

    // can't understend ww chise's sm times writes like: ДЛЯ ВСЕХ ! ! Выполнить и показать код
    // аписать программу, которая сохраняет все введенные пользователем строки в файл.запись в файл закан�

    ofstream cpy_main("main_6_cpy.txt", ios::out | ios::trunc); // b't last cpy not destroyed

    for (size_t i = 0; i < chaise_count; i++)
    {
        string f_name = "chaise_" + to_string(i) + ".txt";
        ifstream chaise(f_name, ios::in);
        chaise.read(buf, size);
        int bytesRead = chaise.gcount();
        if (bytesRead == 0) break;
        cpy_main.write(buf, bytesRead);
    }

    cpy_main.close(); */

    // 7

    /*fstream file("index.html", ios::in | ios::app);
    fstream fileN("index_cpy.html", ios::out | ios::app);

    string line;
    while (getline(file, line)) {
        string src("src=\"../images/UI/halloween_jack.svg\"");
        bool is_nImg = line.find("<img") != string::npos && line.find(src) != string::npos;
        if (!is_nImg) fileN << line << "\n";
    }

    file.close();
    fileN.close();*/

    // 8
}
