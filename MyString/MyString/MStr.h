#pragma once
class MStr {
private:
    char* str;
    size_t length;
    static int count;
public:
    MStr();
    MStr(size_t size);
    MStr(const char* _str);
    MStr(const MStr& _str);
    MStr(MStr&& _str) noexcept;
    ~MStr();
    
    void Cpy(const MStr& st);
    bool StrStr(const char* st);
    void Print();
    size_t Len();
    void Inp(const char* st);
    int StrChr(char chr);
    void Cat(MStr& b);
    void DelChr(char chr);
    int StrCmp(MStr& b);

    static int Count();

    MStr operator+ (MStr& obj);
    MStr operator+ (const char* str);
    MStr operator+ (const char chr);
    MStr operator- (const char* str);
    bool operator== (MStr& obj);
    bool operator!= (MStr& obj);
    bool operator> (MStr& obj);
    bool operator< (MStr& obj);
    bool operator>= (MStr& obj);
    bool operator<= (MStr& obj);

    bool operator== (const char* str);
    bool operator!= (const char* str);
    bool operator> (const char* str);
    bool operator< (const char* str);
    bool operator>= (const char* str);
    bool operator<= (const char* str);

    bool operator== (const int len);
    bool operator!= (const int len);
    bool operator> (const int len);
    bool operator< (const int len);
    bool operator>= (const int len);
    bool operator<= (const int len);
    MStr& operator++ ();
    MStr operator++ (int);
    MStr& operator-- ();
    MStr operator-- (int);
};