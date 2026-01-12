#include <iostream>
#include <Windows.h>
using namespace std;

//class Lift {
//private:
//    int min_f;
//    int max_f;
//    bool is_turned;
//    bool in_move;
//    int active_f;
//public:
//    Lift()
//    {
//        this->min_f = 0;
//        this->max_f = 1;
//        this->is_turned = false;
//        this->in_move = false;
//        this->active_f = 0;
//    }
//    Lift(int _min_f, int _max_f)
//    {
//        if (_min_f >= 0 && _max_f > 0 && _max_f > min_f)
//        {
//            Lift();
//            this->min_f = _min_f;
//            this->max_f = _max_f;
//        }
//        else
//        {
//            Lift();
//        }
//    }
//
//    void Init(int _min_f, int _max_f)
//    {
//        if (_min_f >= 0 && _max_f > 0 && _max_f > min_f)
//        {
//            this->min_f = _min_f;
//            this->max_f = _max_f;
//        }
//    }
//    void Call_to(int _called_f)
//    {
//        if (_called_f >= min_f && _called_f < max_f && in_move == false && is_turned == true)
//        {
//            in_move = true;
//            cout << "Start moving from" << active_f << " floor to " << _called_f << " floor." << endl;
//            int start_f = active_f;
//            if (_called_f > active_f)
//            {
//                for (size_t i = 0; i <= (_called_f - start_f); i++)
//                {
//                    active_f++;
//                    Sleep(1000);
//                    cout << active_f << endl;
//                }
//            }
//            else {
//                for (size_t i = 0; i <= (start_f - _called_f); i++)
//                {
//                    active_f--;
//                    Sleep(1000);
//                    cout << active_f << endl;
//                }
//            }
//            in_move = false;
//            cout << "Now stopped at " << _called_f << " floor." << endl;
//        }
//        else
//        {
//            cout << "Error - lift is called or incorrect floor." << endl;
//        }
//    }
//    void Active_stady()
//    {
//        if (is_turned)
//        {
//            cout << "Now lift is turned on and ";
//            in_move ? cout << "moving" : cout << "staying";
//            cout << " at " << active_f << " floor." << endl;
//        }
//        else
//        {
//            cout << "Now lift is turned off" << endl;
//        }
//    }
//    void Turn_on(bool _is_turned)
//    {
//        is_turned = _is_turned;
//    }
//
//};
//
//int main() {
//    int minF, maxF;
//    cout << "Enter min floor: ";
//    cin >> minF;
//    cout << "Enter max floor: ";
//    cin >> maxF;
//
//    Lift lift(minF, maxF);
//
//    int command;
//    lift.Turn_on(true);
//
//    do {
//        cout << "\n--- Lift Menu ---\n";
//        cout << "1 - Call lift to floor\n";
//        cout << "2 - Show lift status\n";
//        cout << "0 - Exit\n";
//        cout << "Enter command: ";
//        cin >> command;
//
//        switch (command)
//        {
//        case 1:
//            int floor;
//            cout << "Enter floor to call: ";
//            cin >> floor;
//            lift.Call_to(floor);
//            break;
//        case 2:
//            lift.Active_stady();
//        default:
//            break;
//        }
//    } while (command != 0);
//
//    return 0;
//}

struct Size {
    double x;
    double y;
};

struct Room_size {
    double x;
    double y;
    double z;
};

class Paper_roll {
private:
    char* name = nullptr;
    Size size;
    double cost;
public:
    Paper_roll()
    {
        size.x = 0;
        size.y = 0;
        cost = 0;
    }
    Paper_roll(char* _name, Size _size, double _cost)
    {
        Init(_name, _size, _cost);
    }
    void Init(const char* _name, Size _size, double _cost)
    {
        if (_name != nullptr)
        {
            if (name != nullptr)
            {
                delete[] name;
                name = nullptr;
            }
            name = new char[strlen(_name) + 1];
            strcpy_s(name, strlen(_name) + 1, _name);
        }
        else cout << "Error: name can't be empty!" << endl;
        if (_size.x != 0 && _size.y != 0) size = _size;
        cost = _cost;
    }
    double GetCost()
    {
        return cost;
    }
    Size GetSize()
    {
        return size;
    }
    double GetS()
    {
        return(size.x * size.y);
    }
    ~Paper_roll()
    {
        delete[] name;
    }
};

class Room
{
private:
    char* name = nullptr;
    Paper_roll* rolls = nullptr;
    Room_size size;
    bool need_roof;
    int rolls_count;
public:
    Room()
    {
        size.x = 0;
        size.y = 0;
        size.z = 0;
        need_roof = false;
        rolls_count = 0;
    }
    Room(const char* _name, Paper_roll* _rolls, Room_size _size, bool _need_roof, int _rolls_count)
    {
        Init(_name, _rolls, _size, _need_roof, _rolls_count);
    }
    void Init(const char* _name, Paper_roll* _rolls, Room_size _size, bool _need_roof, int _rolls_count)
    {
        if (_name != nullptr)
        {
            if (name != nullptr)
            {
                delete[] name;
                name = nullptr;
            }
            name = new char[strlen(_name) + 1];
            strcpy_s(name, strlen(_name) + 1, _name);
        }
        else cout << "Error: name can't be empty!" << endl;
        if (_size.x != 0 && _size.y != 0 && _size.z) size = _size;
        if (_rolls != nullptr)
        {
            if (rolls != nullptr)
            {
                delete[] rolls;
                rolls = nullptr;
            }
            rolls = new Paper_roll[_rolls_count];
            for (size_t i = 0; i < _rolls_count; i++)
            {
                rolls[i] = _rolls[i];
            }
            rolls_count = _rolls_count;
        }
        need_roof = _need_roof;
    }
    void Print() const {
        cout << "Room: " << (name ? name : "Unnamed")
            << " (" << size.x << "x" << size.y << "x" << size.z << ")"
            << " Roof: " << (need_roof ? "Yes" : "No") << endl;
    }
    int GetCount()
    {
        return rolls_count;
    }
    double GetCost() {
        double room_s = (size.x * size.z * 2) + (size.y * size.z * 2);
        double part = room_s / rolls_count;
        double total = 0;
        for (int i = 0; i < rolls_count; i++) {
            total += (part / rolls[i].GetS()) * rolls[i].GetCost();
        }
        return total;
    }
    ~Room()
    {
        delete[] name;
        delete[] rolls;
    }
};

class Apart
{
private:
    Room* rooms = nullptr;
    int rooms_cnt;
public:
    Apart()
    {
        rooms = nullptr;
        rooms_cnt = 0;
    }
    Apart(Room* _rooms, int _rooms_cnt)
    {
        Init(_rooms, _rooms_cnt);
    }
    void AddRoom(Room _room)
    {
        Room* newRooms = new Room[rooms_cnt + 1];
        for (int i = 0; i < rooms_cnt; i++) newRooms[i] = rooms[i];
        newRooms[rooms_cnt] = _room;

        if (rooms != nullptr)
        {
            delete[] rooms;
            rooms = nullptr;
        }
        rooms = newRooms;
        rooms_cnt++;
    }
    void Init(Room* _rooms, int _rooms_cnt)
    {
        if (_rooms != nullptr)
        {
            if (rooms != nullptr)
            {
                delete[] rooms;
                rooms = nullptr;
            }
            rooms = new Room[_rooms_cnt];
            for (size_t i = 0; i < _rooms_cnt; i++)
            {
                rooms[i] = _rooms[i];
            }
            rooms_cnt = _rooms_cnt;
        }
    }
    void Print()
    {
        cout << "Apartment with " << GetCount() << " rooms:" << endl;
        for (int i = 0; i < GetCount(); i++) {
            rooms[i].Print();
        }
        cout << "Total cost is: " << GetF_Price() << "uah" << endl;
    }
    int GetCount()
    {
        return rooms_cnt;
    }
    double GetF_Price()
    {
        double cost = 0;
        for (size_t i = 0; i < GetCount(); i++)
        {
            cost += rooms[i].GetCost();
        }
        return cost;
    }
    ~Apart()
    {
        delete[] rooms;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Apart apart;

    int choice;
    do {
        cout << "1. Добавить комнату\n";
        cout << "2. Итоговая стоимость\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char buf[100];
            Room_size rs;
            int roof;
            int rolls_cnt;

            cout << "Введите название комнаты: ";
            cin >> buf;
            cout << "Введите размеры (x y z): ";
            cin >> rs.x >> rs.y >> rs.z;
            cout << "Введите кол-во типов рулонов: ";
            cin >> rolls_cnt;
            cout << "Нужен потолок? (1 - да, 0 - нет): ";
            cin >> roof;
            if (roof) rolls_cnt++;

            Paper_roll* rolls = new Paper_roll[rolls_cnt];
            for (int i = 0; i < rolls_cnt; i++) {
                char roll_name[50];
                Size s;
                double cost;
                cout << "Введите название обоев для стены " << i + 1 << ": ";
                cin >> roll_name;
                cout << "Введите размер рулона (x y): ";
                cin >> s.x >> s.y;
                cout << "Введите цену: ";
                cin >> cost;
                rolls[i].Init(roll_name, s, cost);
            }
            Room new_room(buf, rolls, rs, roof, rolls_cnt);
            apart.AddRoom(new_room);
            cout << "Комната добавлена!\n";
            break;
        }
        case 2: {
            apart.Print();
            break;
        }
        case 0:
            cout << "Выход\n";
            break;
        default:
            cout << "Неверный ввод!\n";
        }
    } while (choice != 0);

    return 0;
}